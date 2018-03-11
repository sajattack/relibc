int execl(const char* path, ...) {
    const char** args;
    va_list ap;
    va_start(ap, path);
    args = va_arg(ap, const char *);
    va_end(ap);
    return _execl(path, args);
}

int execle(const char* path, ...) {
    const char** args;
    va_list ap;
    va_start(ap, path);
    args = va_arg(ap, const char *);
    va_end(ap);
    return _execle(path, args);
}

int execlp(const char* path, ...) {
    const char** args;
    va_list ap;
    va_start(ap, path);
    args = va_arg(ap, const char *);
    va_end(ap);
    return _execlp(path, args);
}
