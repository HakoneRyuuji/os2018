#include<unistd.h>
#include<stdio.h>
int main(){
	printf("Main before fork()\n");
	int pid = fork();
	if (pid == 0){
		printf("I'm child after fork()\n");
		char *args[] = {"/bin/ps", "-ef",NULL};		
		execvp("/bin/ps", args);
	}
	int pid = fork();
	if (pid == 0){
		printf("I'm child after second fork()\n");
		char *args[] = {"free", "-h", NULL};
		execvp("free", args);
	}
return 0;
}
