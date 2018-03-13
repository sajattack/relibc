#include <string.h>

int execl(const char *path, const char* argv0, ...)
{
	int argc;
	va_list ap;
	va_start(ap, argv0);
	for (argc=1; va_arg(ap, const char*); argc++);
	va_end(ap);
	{
		int i;
		char *argv[argc+1];
		va_start(ap, argv0);
		argv[0] = (char *)argv0;
		for (i=1; i<argc; i++)
			argv[i] = va_arg(ap, char *);
		argv[i] = NULL;
		va_end(ap);
		return _execl(path, argv);
	}
}

int execle(const char *path, const char* argv0, ...)
{
	int argc;
	va_list ap;
	va_start(ap, argv0);
	for (argc=1; va_arg(ap, const char *); argc++);
	va_end(ap);
	{
		int i;
		char *argv[argc+1];
		char **envp;
		va_start(ap, argv0);
		argv[0] = (char *)argv0;
		for (i=1; i<=argc; i++)
			argv[i] = va_arg(ap, char *);
		envp = va_arg(ap, char **);
		va_end(ap);
		return _execle(path, argv, envp);
	}
}

int execlp(const char* file, const char* argv0, ...) {
    int argc;
	va_list ap;
	va_start(ap, argv0);
	for (argc=3; va_arg(ap, const char*); argc++);
	va_end(ap);
	{
		int i;
		char* argv[argc+4];
		va_start(ap, argv0);
		const char* path = "/bin/sh";
		argv[0] = "-c";
		argv[1] = file;
		argv[2] = (char *)argv0;
		for (i=3; i<argc; i++)
			argv[i] = va_arg(ap, char *);
		argv[i] = NULL;
		va_end(ap);
		return execv(path, argv);
	}
}

int execvp(const char* file, char *const _argv[]) {
    int argc = sizeof(_argv)/sizeof(_argv[0]);
    va_list ap;
    char* argv[argc+3];
    const char* path = "/bin/sh";
    argv[0] = "-c";
    argv[1] = file;
    memccpy(argv, _argv, 0, sizeof(_argv));
    return execv(path, argv);
}
