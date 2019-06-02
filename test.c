#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned long size = 127;
    void *ptr = malloc(size);
    printf("%lu\n", sizeof(ptr));
    free(ptr);
    return 0;
}