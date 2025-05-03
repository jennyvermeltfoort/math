

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int sum = 0;
#define ITERS 1000000

    for (int i = 0; i < ITERS; i++) {
        sum += (rand() % 6) + 1;
    }

    printf("%f\n", (double)sum / (double)ITERS);

    return 0;
}