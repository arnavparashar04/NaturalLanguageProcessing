#include <stdio.h>
int main()
{
    printf("Enter text to cleap up\n");
    char a[1024];
    fgets(a, 1023, stdin);
}