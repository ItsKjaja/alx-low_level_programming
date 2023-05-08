#include "main.h"


/**
 * read_textfile - reads a text file and prints it to standard out
 * @filename: name of file
 * @letters: letters to read and print?
 * Return: 1 on success, -1 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	int nl;
	int wr;
	char *txt;

	if (!filename || letters == 0)
		return (0);
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	txt = malloc(sizeof(char) * letters);
	if (txt == NULL)
	{ close(file);
		return (0);
	}
	nl = read(file, txt, letters);
	close(file);
	if (nl < 0)
	{
		free(txt);
		return (0);
	}
	wr = write(STDOUT_FILENO, txt, nl);
	if (wr <= 0)
	{
		free(txt);
		return (wr);
	}
}
