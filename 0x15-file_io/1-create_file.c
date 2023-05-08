#include "main.h"


/**
 * create_file - file creating
 * @filename: file's name
 * @text_content: NULL terminated string to write to the file
 * Return:1 on success, -1 on failure
 */


int create_file(const char *filename, char *text_content)

{
	int fi, check, n = 0;

	if (!filename)
		return (-1);

	fi = open(filename, O_RDWR | O_CREAT | O_TRUNC, 00600);

	if (fi == -1)
		return (-1);

	if (text_content)
	{
		for (check = 0; *(text_content + check);)
			check++;
		n = write(fi, text_content, check);

		if (n != check)
		{
		close(fi);
		return (-1);
	}
	}
	close(fi);
	return (1);
}

