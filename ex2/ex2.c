// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{
    // Your code here
    FILE *fp = fopen("text.txt", "w");

    int rc = fork();

    if (rc < 0)
    {
        printf("Fork failed \n");
        exit(1);
    }
    else if (rc == 0)
    {
        fprintf(fp, "Child writing to file. \n");
    }
    else
    {
        fprintf(fp, "Parent writing to file. \n");
    }

    fclose(fp);
    return 0;
}
