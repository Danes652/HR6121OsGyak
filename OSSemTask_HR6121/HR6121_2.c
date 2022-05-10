//6. feladat
//Beleir egy random szamot a csovezetekbe, majd varja a duplajat a szamnak. Ezutan kitorli a csovezeteket.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int fd;

    char * myfifo = "/tmp/myfifo1";

    //letrehozza a csovezeteket
    mkfifo(myfifo, 0666);

    //general egy random szamot
    int number;
    srand(time(0));
    number = rand()%100 + 1;
    

	//megnyitja a csovezeteket irasra, beleirja a random generalt szamot, majd bezarja 
        fd = open(myfifo, O_WRONLY);
                
        write(fd, &number, sizeof(int));
        
        close(fd);

        
        //megnyitja a csovezeteket olvasasra, var hogy tegyenek bele egy szamot, majd kiirja, becsukja a csovezeteket
        fd = open(myfifo, O_RDONLY);

        read(fd, &number, sizeof(int));

        printf("Number doubled: %d\n", number);
        close(fd);

	//kitorli a csovezeteket
        remove("/tmp/myfifo1");

    return 0;
}
