#include <stdlib.h>
#include <stdio.h>

int int_cmp(const void* a, const void* b) {
  return *(const int*) a - *(const int*) b;
}

#define BSEARCH_TEST_INT(key, arr, len, expect) \
  do { \
    void* res = bsearch((const void*) &key, (void*) arr, len, sizeof(int), int_cmp); \
    if (res != expect) { \
      printf("FAIL bsearch for %d in [", key); \
      for (size_t i = 0; i < len; ++i) printf("%d,", arr[i]); \
      printf("] expected %p but got %p\n", (void*) expect, res); \
      return 1; \
    } \
  } while (0);



int main(int argc, char* argv[]) {
  int x = 0;
  int y = 1024;
  int empty[] = {};
  BSEARCH_TEST_INT(x, empty, 0, NULL);

  int singleton[] = {42};
  printf("%p\n%p\n", singleton, &singleton[1]);
  BSEARCH_TEST_INT(x, singleton, 1, NULL);
  BSEARCH_TEST_INT(singleton[0], singleton, 1, &singleton[0]);
  BSEARCH_TEST_INT(y, singleton, 1, NULL);

  int two[] = {14, 42};
  BSEARCH_TEST_INT(x, two, 2, NULL);
  BSEARCH_TEST_INT(y, two, 2, NULL);
  BSEARCH_TEST_INT(two[0], two, 2, &two[0]);
  BSEARCH_TEST_INT(two[0], two, 1, &two[0]);
  BSEARCH_TEST_INT(two[1], two, 2, &two[1]);
  BSEARCH_TEST_INT(two[1], two, 1, NULL);

  int three[] = {-5, -1, 4};
  BSEARCH_TEST_INT(three[0], three, 3, &three[0]);
  BSEARCH_TEST_INT(three[1], three, 3, &three[1]);
  BSEARCH_TEST_INT(three[2], three, 3, &three[2]);

  int big[] = {-19, -13, -7, -3, 2, 5, 11};
  BSEARCH_TEST_INT(big[0], big, 7, big);
  BSEARCH_TEST_INT(big[6], big, 7, &big[6]);
  BSEARCH_TEST_INT(big[3], big, 7, &big[3]);
  BSEARCH_TEST_INT(x, big, 7, NULL);

  printf("PASS bsearch\n");
  return 0;
}
