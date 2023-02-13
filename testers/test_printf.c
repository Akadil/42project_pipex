#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    printf(argv[1], argv[2]);
    return (0);
}