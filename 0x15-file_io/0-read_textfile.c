#include "main.h"

/**
 * read_textfile - and prints it to the POSIX standard output.
 * @filename: readable file name's
 * @letters: number of letters must be readable and printable
 *
 * Return:the actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t numletters;
	int Fl;
	char *txt;

	if (!filename)
		return (0);
	txt = malloc(sizeof(char) * letters + 1);
	if (txt == NULL)
		return (0);
	Fl = open(filename, O_RDONLY);
	if (Fl == -1)
	{

		free(txt);
		return (0);
	}
	numletters = read(Fl, txt, sizeof(char) * letters);
	if (numletters == -1)
	{
		free(txt);
		close(Fl);
		return(0);
	}
	numletters = write(STDOUT_FILENO, txt, numletters);
	if (numletters == 1)
	{
		free(txt);
		close(Fl);
		return (0);
	}
	free(txt);
	close(Fl);
	return (numletters);
}
