#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int status, status1;

	//letezo:
	status=system("dir");
	if(status < 0) perror("system() error");
	if(WIFEXITED(status)) printf("Normalis befejezodes, visszaadott ertek: %d\n", WEXITSTATUS(status));
	else printf("Nem normalis befejezodes\n");
	
	//nem letezo
	status=system("aaaaa");
	if(status < 0) perror("system() error");
	if(WIFEXITED(status)) printf("Normalis befejezodes, visszaadott ertek: %d\n ", WEXITSTATUS(status));
	else printf("Nem normalis befejezodes\n");
	exit(0);

}
