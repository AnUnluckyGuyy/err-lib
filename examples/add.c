#include <stdio.h>
#include <limits.h>
#include "../err.h"

Result add(int x, int y, int *result) {
    if (!result) { return ERR_NULL_POINTER; }
    *result = 0;
    if (x > 0 && y > 0 && x > INT_MAX - y) { return ERR_OVERFLOW; }
    if (x < 0 && y < 0 && x < INT_MIN - y) { return ERR_UNDERFLOW; }
    *result = x + y;
    return OK;
}


int main(void) {
    int x=-1;
    int y=-1;
    int result;
    Result r = add(x, y, &result);
    if (IS_ERR(r)) {
        fprintf(stderr, "%s\n", string_err(r));
        return 1;
    }
    printf("result: %d\n", result);
    return 0;
}