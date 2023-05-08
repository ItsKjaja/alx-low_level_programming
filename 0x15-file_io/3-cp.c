#include "main.h"


void error_file_from(char *, char *);
void error_file_to(char *, char *);
void error_close(int, char *);

/**
 * copy_file - copies a file from one to another
 * file_to: file to copy to
 * file_from: file to copy from
 * Return: Always 0.
 */

int copy_file(char *file_to, char *file_from)
{
	int f_to, f_from, wr, er, re;
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (0);
	f_from = open(file_from, O_RDONLY);
	if (f_from == -1)
		error_file_to(file_to, buf);
	re = read(f_from, buf, 1024);

	do {
		if (re == -1)
			error_file_from(file_from, buf);
		if (re == 0)
			break;
		wr = write(f_to, buf, re);
		if (wr == -1)
			error_file_to(file_to, buf);
		re = read(f_from, buf, 1024);
	} while (re > 0);

	er = close(f_to);
	if (er == -1)
		error_close(f_to, buf);
	er = close(f_from);
	if (er == -1)
		error_close(f_from, buf);
	free(buf);
	return (0);
}


/**
 * error_close - eroor procedure when issue with closing
 * @fd: int where file is opened
 * @buf: buffer to free
 * Return: void
 */

void error_close(int fd, char *buf)
{
	free(buf);
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * error_file_from - error to come when issue in file from
 * @file_from: file from name's
 * @buf: buffer to free
 * Return: void
 */

void error_file_from(char *file_from, char *buf)
{
	free(buf);
	dprntf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
	exit(98);
}
/**
 * error_file_to - error to come when issue with file to
 * @file_to: file to name's
 * @buf: buffer to free
 * Return: void
 */
void error_file_to(char *file_to, char *buf)
{
	free(buf);
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
	exit(99);
}

/**
 * main - program's main
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])

{
	if (argc != 3)
	{
		dprntf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	copy_file(argv[2], argv[1]);
	return (0);
}
