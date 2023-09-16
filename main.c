#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

char *validArgs = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%¨&*()_-+="} ;

int main(int argc,char **argv)
{
    setlocale(LC_ALL,"");
    srand(time(0));

    if(argc == 3)
    {
        if(strcmp(argv[1],"create_hash") == 0 && &argv[2] != NULL){
            int i;
            puts("The hash has been generated.");
            for(i = 0;i < atoi(argv[2]);i++){
                printf("%c",validArgs[rand() % strlen(validArgs)]);
            }
            printf("\n");
            return 0;
        }
    }

    printf("Correct usage: <program> <create_hash> <length>");

    return -1;
}
