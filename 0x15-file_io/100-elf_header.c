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
		printf("UNIX -Linux\n");
	else if (he[7] == 4)
		printf("UNIX - GNU Hurd\n");
	else if (he[7] == 5)
                printf("UNIX - Solaris\n");
	else if (he[7] == 6)
                printf("UNIX - AIX\n");
	else if (he[7] == 7)
                printf("UNIX - IRIX\n");
	else if (he[7] == 8)
                printf("UNIX - FreeBSD\n");
	else if (he[7] == 9)
                printf("UNIX - True64\n");
	else if (he[7] == 10)
                printf("UNIX - Novell Modesto\n");
	else if (he[7] == 11)
                printf("UNIX - OpenBSD\n");
	else if (he[7] == 12)
                printf("UNIX - Open VMS\n");
	else if (he[7] == 13)
                printf("UNIX - NonStop Kernel\n");
	else if (he[7] == 14)
                printf("UNIX - AROS\n");
	else if (he[7] == 15)
                printf("UNIX - Fenix OS\n");
	else if (he[7] == 16)
                printf("UNIX - CloudABI\n");
	else 
		printf("<unknown: %02hex>\n", he[7]);
}

/**
 * _abiv - checks abi's version
 *
 * @he: header
 * Return: No return
 */
*void _abiv(char *he)
{
	printf(" %-35s", "ABI Version:");
	printf("%d\n", he[8]);
}

/**
 * _type - print elf's type
 *
 * @he: header
 * @x64: variable to check if x64 (1) or x32 (0)
 *
 * Return: No return
 */
void _type(char *he, int x64)
{
	int xtype = 17;
	(void) x64;
	if (he[5] == 1)
		xtype = 16;
	printf(" %-35s", "Type:");


switch (he[xtype])
{
	case 0:
		printf("NONE\n");
		break;
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<inknown>: %02x\n", he[stype]);
}

/**
 * _entry - print the entry point access by directly accessing of elf
 * the elf's header struct
 * @he: header
 * @0x64: check 1 for x64 and 0x32
 *
 * Return: No return
 */

void _entry(char *he, int x64)
{

	int count = 27 , n;
	 printf(" %-35s0x", "Eentry point address:");

	 if (x64 == 1)
		 count = 31;
	 if (he[5] == 1)
	 {
		 /*Little endian */
		 n = count;
		 while (he[n] == 0 && n > 24
				 n--;
				 printf("%x", he[n]);
				 n--;

				 while (n >= 24)
				 {

				 printf("%02x", (unsigned char) he[n]);
				 n--;
				 }
				 }
				 else
				 {
				 /*Big endian*/
				 n = 24;
				 while (he[n]== 0)
				 n++;
				 printf("%x", he[n]);
				 n++;
				 while (n <= count)
				 {
					 printf("%02x", (unsigned char) he[n]);
					 n++;
				 }
				 }
		 printf("\n");
}

