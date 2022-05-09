
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
    int fd2;

    char * myfifo = "/tmp/myfifo1";

    mkfifo(myfifo, 0666);

    int number;
    srand(time(0));
    number = rand()%100 + 1;
    

        fd = open(myfifo, O_WRONLY);

        
        
        write(fd, &number, sizeof(int));
        
        close(fd);

        
        
        fd = open(myfifo, O_RDONLY);

        
        read(fd, &number, sizeof(int));

        printf("Number doubled: %d\n", number);
        close(fd);
        remove("/tmp/myfifo1");

    return 0;
}
