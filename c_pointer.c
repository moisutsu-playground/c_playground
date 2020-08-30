#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *p = (char *)malloc(sizeof(char) * 10);
    strcpy(p, "Hello");
    p[0] = p[3];
    printf("%c\n", p[0]);
    return 0;
}
