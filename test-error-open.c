/*
 * Example that shows a couple of errors of the open function and how
 * to understand them via errno.
 *
 * Try to run:
 * 
 *   ./a.out
 *     which should fail because it expects a 1st parameter as input file
 *
 *   ./a.out <filename>
 *     if <filename> is in the same directory, then it works
 *
 *   chmod -rwx <filename>
 *   ./a.out <filename>
 *     the file is there but the program has no access permission
 */

#include <stdio.h>    /* fprintf, printf */
#include <string.h>   /* strerror */
#include <errno.h>    /* errno */
#include <fcntl.h>    /* open */

#define CASE_ERR(e)						\
	case e:							\
	fprintf(stderr, "errno=%d=%s, strerror(%s)=\"%s\"\n",	\
		e, #e, #e, strerror(e));			\
	break;

int main (int argc, char * argv[]) {

	int fd, flags;

	flags = O_RDONLY;
	printf("Trying to open file \"%s\" with flags %X\n", argv[1], flags);
	fd = open(argv[1], flags);
	printf("Returned value: %d\n", fd);
	printf("errno value: %d\n", errno);

	/* Checking the error */
	switch (errno) {
		CASE_ERR(EFAULT);
		CASE_ERR(EACCES);
		CASE_ERR(EINVAL);
		CASE_ERR(ENOENT);
		CASE_ERR(EPERM);
	default:
		fprintf(stderr, "errno=%d, strerror(%d)=\"%s\"\n",
			errno, errno, strerror(errno));		
		break;
	}


}
