#include <stdio.h>
int main() {
    int x = 5;
    int y = 2;
    int *z =&x;
    int *v =&y;
    z = v;
    printf("%d", z);
    return 0;
}
