#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: appended file.
 * @text_content: infos that will append into the file.
 * Return: 1 on success -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int  numletters;
	int inf;
	int rc;

	if (!filename)
		return (-1);

	inf = open(filename, O_WRONLY | O_APPEND);

	if (inf  == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		for (numletters = 0; text_content[numletters]; numletters++)
			;
		rc = write(inf, text_content, numletters);
		if (rc == -1)
			return (-1);
	}
	close(inf);
	return (1);
}
