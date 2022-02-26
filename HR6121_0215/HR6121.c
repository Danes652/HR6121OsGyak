#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;

    fptr=fopen("honti.txt","w");

    if(fptr == NULL){
        printf("Error!");
    }

    fprintf(fptr,"Honti Daniel, Programtervezo Informatikus, HR6121");

    fflush(fptr);
    fclose(fptr);

    return 0;
}
