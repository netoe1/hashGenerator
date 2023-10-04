#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

char *ptr = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%&*()-"};

int generateHash(int length);
int main(int argc, char **argv)
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	if (argc >= 2)
	{
		if (argv[1] != NULL)
		{
			if ((strcmp("--generate", argv[1]) == 0 || strcmp("-g", argv[1]) == 0) && argv[2] != NULL)
			{
				int integer = atoi(argv[2]);
				generateHash(integer);
			}
			else if (strcmp("--help", argv[1]) == 0 || strcmp("-h", argv[1]) == 0)
			{
				puts("Valid Usage: <program_name> <function> <flag>");
				puts("--help || -h\t# Outputs valid commands to use.");
				puts("--generate || -g <length> \t# Generates a hash acording to length.");
			}
			else
			{
				puts("Something went wrong, use --help to manage use.");
			}
			return 0;
		}
	}

	puts("Invalid usage, use --help or -h to see valid commands.");
	return -1;
}

int generateHash(int length)
{
	if (&length != NULL)
	{
		for (int i = 0; i < length; i++)
		{
			printf("%c", ptr[rand() % strlen(ptr)]);
		}
		return 0;
	}

	perror("You must provide a valid length to create an valid hash.");

	return -1;
}
