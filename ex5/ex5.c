// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main()
{
    char inbuf[MSGSIZE];
    int p[2];

    if (pipe(p) < 0)
    {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    int RC = fork();

    if (RC < 0)
    {
        fprintf(stderr, "fork failed!\n");
        exit(2);
    }

    else if (RC == 0)
    {
        printf("child writing to pipe\n");

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        wait(NULL);
        close(p[1]);

        printf("parent reading from pipe\n");
        for (int i = 0; i < 3; i++)
        {
            // read 16 bytes of data from the read file descriptor
            read(p[0], inbuf, MSGSIZE);
            printf("parent: %s\n", inbuf);
        }
        printf("parent done reading\n");
    }

    return 0;

    return 0;
}
