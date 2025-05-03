/*
Suppose that out of any given message that you receive from your
colleague there is an 80% chance that it has serious content, there is
a 10% chance that it is an unfunny meme and a 10% chance that it is a
funny meme. When you receive a funny meme, you always
acknowledge it. For a given day, what is the probability that you
receive an unfunny meme before you receive a funny meme?
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int sum = 0;
#define ITERS 1000000
#define N 10
#define S 10
#define PF 1
#define PU 2

    for (int d = 0; d < ITERS; d++) {
        bool seen_unfunny = false;
        for (;;) {
            int option = rand() % S;
            if (option == PU) {
                seen_unfunny = true;
            }
            if (option == PF) {
                sum += seen_unfunny;
                break;
            }
        }
    }

    printf("%f\n", (double)sum / (double)ITERS);

    return 0;
}