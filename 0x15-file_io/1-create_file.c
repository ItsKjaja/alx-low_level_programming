#include "main.h"

/**
 * create_file - create a file with name filename
 * @filename: filename
 * @text_content:file information to write
 * Return: 1 on success, -1 on failure (file can not be created, file can not be written, write “fails”, etc…).
 */

int create_file(const char *filename, char *text_content)
{
	int inf;
	int numletters;
	int cr;

	if (!filename)
		return (-1);

	inf = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (inf == -1)
		return (-1);
	if (!text_content)
		text_content = "";

	for (numletters = 0; text_content[numletters]; numletters++)
		;
	cr = write(inf, text_content, numletters);

	if (cr == -1)
		return (-1);
	close(inf);
		return (1);
}
