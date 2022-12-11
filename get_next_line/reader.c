//create a program that uses the read() function to read a file and print it to the standard output.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int ret;
    char buf[4096 + 1];

    if (argc != 2)
        return (1);
    while ((ret = read(open(argv[1], O_RDONLY), buf, 4096))) 
    {
        buf[ret] = '\n';
        printf("%s", buf);
        break;
    }
    return (0);
}
