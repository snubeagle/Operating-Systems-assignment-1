#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *num = "5";
    int exit_stat;
	int result;
	int cpid;

    int arrrrrrr = fork();
    
    if (arrrrrrr < 0){
		perror("Fork");
		void exit(int);
	}
	else if (arrrrrrr == 0) {
		assert (result = execl("./counter", "counter", num, (char *)NULL) > 0);	
		if (result < 0) {
			assert (printf("Error executing counter file") != 0);
			exit;
		}
	}
    else
		assert (waitpid(arrrrrrr, &exit_stat, 0) > -1);
		if (WIFEXITED(0)) {
			assert (printf("Process %d exited with status %d\n", arrrrrrr, atoi(num)) !=0);
		}
		else {
			assert (printf("Child exited with invalid status\n") != 0);
		}
    return 0;
}

