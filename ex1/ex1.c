// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("x is originally set to %d\n", x);
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Before changing X in child(PID: %d): x = %d\n", (int)getpid(), x);
        x = 500;
        printf("After changing X in child(PID: %d): x = %d\n", (int)getpid(), x);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("Before changing X in parent(PID: %d): x= %d\n", (int)getpid(), x);
        x = 3;
        printf("After changing X in parent(PID: %d): x = %d\n", (int)getpid(), x);
    }

    return 0;
}
