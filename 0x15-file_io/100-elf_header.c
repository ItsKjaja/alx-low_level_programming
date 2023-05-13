#include "main.h"


/**
 * main - main entry point
 * @ac: counter
 * @av: vector
 * Return: 0 in success
 */



int main(int ac, char *av[])
{
	register int fd, n, b;
	int elf *header;

	if (ac !=2)
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(98);
	header = malloc(sizeof(elf));
	if (!header)
	dprintf(STDERR_FILENO, "Malloc error\n"), exit(98);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
	exit(98);
}
n = read(fd, header, sizeof(elf));
if (n < 0)
		{
		free(header);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
		}


	validate_elf(header->e_ident);
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	printf(" ABI Version: ");
	printf("i\n" header->e_ident[EI_ABIVERSION]);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);
	free(header);
	b = close(fd);
{
	if (b)
	dprintf(STDERR_FILENO, "Error: Can't close fd\n"), exit(98);
	return (0);
	}
/**
 * validate_elf - help in checking if the input is a valid elf's file
 * @e_ident: pointer
 *
 */
void validate_elf(unsigned char *e_ident)
{
	if (e_ident[0] == 0x7f && e_ident[1] == 'E' &&
			e_ident[2] == 'L' && e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
		dprintf(STDERR_FILENO, "Error: Not a valid ELF\n"), exit(98);
}


/**
 * print_magic - print the magic number of ELF
 * @e_ident: pointer
 */


void print_magic(unsigned char *e_ident)
{
	register int m;
	printf(" Magic: ");
	for (m = 0; m < EI_NIDENT - 1; m++)
		printf("%02x ", e_ident[m]);
	printf("%02x\n", e_ident[m]);
}

/**print_class - print the class of elf
 * @e_ident: pointer to char array
 */
void print_class(unsigned char *e_ident)
{
	printf(" class   ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("This class is invalid\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n" , e_ident[EI_CLASS]);
/**
 * print_data - print ELF's data
 * @e_ident: pointer to char array
 */


void print_data(unsigned char *e_ident)
{
	printf(" Data:    ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("Unknown data format\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n" , e_ident[EI_DATA]);
	}
}

/**
 * print_version - print the version of elf
 * @e-ident: pointer to char array
 */

void print_version(unsigned char *e_ident)
{
	printf(" Version:      ");
	if (e-ident[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n" , EV_CURRENT);
	else
		printf("%i\n" , e_ident[EI_VERSION]);
}

/**
 * print_osabi - print the osabi of elf
 * @e_ident: pointer to char array
 */

void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI:      ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf ELFOSABI_HPUX:
				printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x\n" , e_ident[EI_OSABI]);
	}
}

/**
 * print_type - print the type of elf
 * @e_type: e_type address
 * @e_ident: pointer to char array
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type = e_type >> 8;
	printf(" Type:        ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
			default
			:
			printf("<unknown: %x>\n" , e_type);
	}
}

/**
 * print_entry - print the entry of elf
 * @e_entry: e_entry address
 * @e_ident: pointer to char arrat
 */


void print_entry(unsigned int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_entry = lit_to_big_endian(e_entry);

	printf(" Entry point address:       ")
			printf("%#x\n", (unsigned int) e_entry);
}

/**
 * lit_to_big_endian - converts little endian hexe to big endian hexe
 * @x: input unsigned int
 * Return: output unsigned int
 */


unsigned int lit_tobig_endian(unsigned int x)
{
	return (((x >> 24) & 0x000000ff) |
			((x >> 8 & 0x0000ff00) |
			 ((x << 8) & 0x00ff0000) |
			 ((x << 24) & 0xff000000));
			}

