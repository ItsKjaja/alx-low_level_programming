#include "main.h"

/**
 * _checkelf - check if file is type of elf
 * @he: header
 * Return: No return
 */

void _checkelf(char *he)
{
	if (he[0] != 0x7f || he[1] != 'E' || he[2] != 'L' || he[3] != 'F')
		dprintf(STDERR_FILENO, "Eroor: a wrong file type\n"), exit(98);
}

/**
 * _magic - print elf magic
 *
 * @he: header
 * Return: No return
 */

void _magic(char *he)
{
	int n;
	printf("Header's Elf:\n Magic: ");

	for (n = 0; n <15; n++)
		printf("%02x", (unsigned int)he[n]);
	printf("\n";
			}
			/**
			 * _class - print elf's class
			 * @he: header
			 * @0x64: 1 if x64, 0 if x32
			 *
			 * Return: No Reeturn
			 */
		       void _class(char *he, int x64)
		       {

	if (he[4] != 1 && he[4] != 2)
	{
printf("<unknown: %02hex>\n", he[4]);
return;
}
printf(" %-35s", "Class:");
if (x64 == 0)
printf("elf64\n");
}
/**
 * _data - print elf's data
 * @he: header
 * Return: No return
 */

void _data(char *he)
{

	printf(" %-35s", "data:");
	printf("2's complement, ");
	if (he[5] == 1)
		printf("little endian\n");
	else if (he[5] == 2)
		printf("big endian\n");
	else
		printf("<unknown: %02hex>\n", he[5]);
}
/**
 * _version - print elf's version
 *
 * @he: header
 *
 * Return: No return
 */


void _version(char *he)
{
	printf(" %-35s", "Version:");
	if (he[6] == EV_CURRENT)
	{
		printf("%d (current)\n", he[6]);
	}
	else if (he[6] != EV_CURRENT)
			{
			printf("%d\n", h[6]);
			}
			}
/**
 * _os - print elf's os/ABI
 * @he: header
 *
 * Return: No return
 */

void _os(char *he)
{
	printf(" %-35s", "OS/ABI:");
	if (he[7] == 0)
		printf("UNIX -System V\n");
	else if (he[7] == 1)
		printf("UNIX -HP-UX\n");
	else if (he[7] == 2)
		printf("UNIX -NetBSD\n");
	else if (he[7] == 3)
		printf"UNIX -Linux\n");

