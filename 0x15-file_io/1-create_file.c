#include "main.h"


/**
 * create_file - file creating
 * @filename: file's name
 * @text_contant: NULL terminated string to write to the file
 * Return:1 on success, -1 on failure
 */


int create_file(const char *filename, char *text_content)

{
	int fi, check, n = 0;

	if (filename == 0)
		return (-1);

	fi = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);

	if (fi == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[1] != 0)
			n++;
		check = write(fi, text_content, n);

		if (check == -1)
			return (-1);
	}

	close(fi);
	return (1);
}

