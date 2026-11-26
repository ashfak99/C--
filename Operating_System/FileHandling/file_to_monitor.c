#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

void file_error()
{
    printf("File can't be open.");
    exit(0);
}

int main(int argc, char const *argv[])
{
    int file_descriptor, byte_reads;
    char buffer[1024];

    file_descriptor=open("C:\\Users\\Dell\\C++\\Operating_System\\FCFS.c++", O_RDONLY);

    if(file_descriptor == -1)
        file_error();
    
    byte_reads=read(file_descriptor, buffer, sizeof(buffer));

    while (byte_reads != 0)
    {
        write(1, buffer, byte_reads);
        byte_reads=read(file_descriptor,buffer, sizeof(buffer));
    }
    
    close(file_descriptor);

    return 0;
}
