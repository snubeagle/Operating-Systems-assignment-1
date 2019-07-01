#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *end;
	int cpid, ppid;
	int terminal_val = strtol(argv[1], &end, 10);
	
	if ((argc > 2) | (terminal_val > 100)) {
		assert (printf("Invalid input provided") != 0);
	}
	else {
		cpid = getpid();
		ppid = getppid();
    
		assert (printf("Parent PID: %d\n", ppid) != 0);
		assert (printf("Child PID: %d\n", cpid) !=0);
    
		for(int i = 1; i <= terminal_val; i++) {
			assert (printf("Process: %d %d\n", cpid, i) !=0);
		}
		return terminal_val;
	}
	return 0;
}
