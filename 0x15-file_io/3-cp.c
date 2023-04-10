#include "main.h"

/**
 * main - entry point c file to another file
 * @argc:arguments number
 * @argv:arguments file to and file from
 * Return: 0 in succes
 */

int main(int argc, char *argv[])
{
	char *f_name, *t_name, buff[1024];
	int Fl_d, Fl_src, rd_r, wr_r;

	if (argc != 3)
		dprintf(STDERR_FILENO, "USAGE: cp file_from file_to\n"),
			exit(97);
	f_name = argv[1], t_name = argv[2];
	Fl_src = open(f_name, O_RDONLY);
	if (Fl_src == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", f_name),
			exit(98);
	Fl_d = open(t_name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (Fl_d == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", f_name),
			exit(98);
	while (rd_r > 0)
	{
	wr_r = write(Fl_d, buff, rd_r);

if (wr_r == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", t_name),
	        	exit(99);
		rd_r = read(Fl_src, buff, 1024);
	}
	if (close(Fl_src) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %\n", Fl_src),
			exit(100);
			if (close(Fl_d) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %\n", Fl_d),
			exit(100);
			return (0);
	}
