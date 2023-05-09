#include "main.h"

/**
 * main - copy info from file_from to file_to.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	int from, to;
	ssize_t l_rd = 1024, l_wr, close_file;
	char content[1024];

	if (argc != 3)
	{ dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }
	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
		exit(98); }
	to = pen(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99); }
	while (l_rd == 1024)
	{
		l_rd = read(from, content, 1024);
		if (l_rd == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1];
				exit(98); }
				l_wr = write(to, content, l_rd);
				if (l_wr == -1)
				{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				exit(99); }

				close_file = close(from);
				if (close_file == -1)
				{ dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
				exit(100); }
				close_file = close(to);
				if (close_file == -1)
				{ dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to);
				exit(100); }
				return (0);
				}
