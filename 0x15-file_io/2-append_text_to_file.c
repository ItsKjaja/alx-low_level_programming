#include "main.h"


int append_text_to_file(const char *filename, char *text_content)

{
	int fi, wr, l;

	if (!filename)
		return (-1);

	fi = open(filename, O_WRONLY | O_APPEND);
	if (fi == -1)
		return (-1);
	if (text_content)
	{
		for (l= 0; *(text_content + l);)
			l++;
		wr = write(fi, text_content, l);

		if (wr == -1)
		{
			close(fi);
			return (-1);
		}

	}
	close(fi);
	return (1);

}
