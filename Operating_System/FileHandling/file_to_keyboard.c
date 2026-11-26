#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
    int pipe_file_descriptor[2], pipe_file_descriptor_, file_descriptor;
    char *c, *d;

    pipe_file_descriptor_ = pipe(pipe_file_descriptor);
    if (pipe_file_descriptor_ == -1)
    {
        printf("Errir");
        exit(1);
    }

    c=d=(char*)malloc(sizeof(char));

    file_descriptor = open("C:\\Users\\Dell\\C++\\Operating_System\\FileHandling\\output.txt", O_WRONLY | O_CREAT, 00777);

    scanf("%c",c);
    while (*c != '#')
    {
        write(pipe_file_descriptor[0],c, sizeof(c));
        read(pipe_file_descriptor[1],d,1);
        write(file_descriptor,d,1);
        scanf("%c",c);
    }
    
    close(pipe_file_descriptor_);
    close(file_descriptor);
    return 0;
}