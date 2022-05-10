//6. feladat
//Beolvas egy random szamot, megduplazza, visszaküldi 
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

   
    char * myfifo = "/tmp/myfifo1";

    //letrehozza a csovezeteket
    mkfifo(myfifo, 0666);

    int number;
    int i;
        
	//Megnyitja a csovezeteket olvasasra, var hogy irjanak bele, kiolvassa belole majd kiirja a szamot, majd bezarja a csovezeteket
        fd1 = open(myfifo,O_RDONLY);
        
        read(fd1, &number, sizeof(int));

        printf("Number: %d\n", number);

        close(fd1);


	//megduplazza a szamot
        number = number * 2;

	//Megnyitja a csovezeteket irasra, beleirja a megduplazott szamot, bezarja a csovezeteket
        fd1 = open(myfifo,O_WRONLY);

        write(fd1, &number, sizeof(int));
          
        close(fd1);

    return 0;
}
