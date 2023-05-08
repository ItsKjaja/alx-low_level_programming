#include "main.h"

/**
 * main - copy info from file_from to file_to.
 * @ac: number of arguments
 * @av: array of arguments
 * Return: Always 0.
 */


int main(int argc, char **argv)
{
	int f_f, f_t;
	ssize_t l_rd = 1024, l_wr, close_file;
	char content[1024];


	if (argc != 3)
	{dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");  exit(97);


	}

	f_f = open(argv[1], O_RDONLY);

	if (f_f == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	f_t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (f_t == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99); }

	while (l_rd == 1024)
	{
		l_rd = read(f_f, content, 1024);
		if (l_rd == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);exit(98); }
	       l_wr = write(f_t, content, l_rd);
       if (l_wr == -1)
       { dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);}
	}
 close_file = close(f_f);
if (close_file == -1)
{ dprintf(STDERR_FILENO, "Error: Can't close fi %d\n", file_from);
exit(100); }
close_file == close (f_t);
if (close_file == -1)
{ dprintf(STERR_FILENO, "Error: Can't close fi %d\n", file_to);
	exit(100); }

	return (0);
	}

