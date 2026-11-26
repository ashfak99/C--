#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void file_error()
{
    printf("File can't be open.");
    exit(0);
}

int main(int argc, char const *argv[])
{
    int file_descriptor_1, file_descriptor_2, bytes_read;
    char buffer[1024];
    file_descriptor_1 = open("C:\\Users\\Dell\\C++\\Operating_System\\RR.c++", O_RDONLY);

    if(file_descriptor_1==-1)
        file_error();
    
    file_descriptor_2 = open("C:\\Users\\Dell\\C++\\Operating_System\\FileHandling\\output.txt",O_WRONLY | O_CREAT , 00057);

    if(file_descriptor_2==-1)
        file_error();

    bytes_read = read(file_descriptor_1, buffer, sizeof(buffer));

    while (bytes_read!=0)
    {
        write(file_descriptor_2, buffer, bytes_read);
        bytes_read=read(file_descriptor_1, buffer, sizeof(buffer));
    }

    close(file_descriptor_1);
    close(file_descriptor_2);
    printf("File Write Successfully");
    return 0;
}