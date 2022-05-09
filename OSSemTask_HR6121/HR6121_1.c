
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;
    int fd2;


    char * myfifo = "/tmp/myfifo1";


    mkfifo(myfifo, 0666);

    int number;
    int i;
        

        fd1 = open(myfifo,O_RDONLY);
        
        read(fd1, &number, sizeof(int));

     
        
        printf("Number: %d\n", number);


        close(fd1);

        number = number * 2;

        fd1 = open(myfifo,O_WRONLY);

        write(fd1, &number, sizeof(int));
          
       

        close(fd1);

    return 0;
}
