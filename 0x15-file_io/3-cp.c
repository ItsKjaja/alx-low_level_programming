#include "main.h"
/**
 * main - copy info from file_from to file_to.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int fi_from, fi_to;
	ssize_t  l_rd = 1024, l_wr, cl_file;
	char content[1024];

	if (argc != 3)
	{ dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }
	fi_from = open(argv[1], O_RDONLY);
	if (fi_from == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
		exit(98); }
	fi_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fi_to == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99); }
	while (l_rd == 1024)
	{
		l_rd = read(fi_from, content, 1024);
		if (l_rd == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98); }
		l_wr = write(fi_to, content, l_rd);
		if (l_wr == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99); }
	}
	cl_file = close(fi_from);
	if (cl_file == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", fi_from);
		exit(100); }
	cl_file = close(fi_to);
	if (cl_file == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", fi_to);
		exit(100); }
return (0);
}
