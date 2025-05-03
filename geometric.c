/*
Suppose that out of any given message that you receive from your
colleague there is an 80% chance that it has serious content, there is
a 10% chance that it is an unfunny meme and a 10% chance that it is a
funny meme. When you receive a funny meme, you always
acknowledge it. What is the probability that your colleague stops
sending memes before his 10th message of the day?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int sum = 0;
#define ITERS 1000000
#define N 10
#define S 10
#define P 1

    for (int d = 0; d < ITERS; d++) {
        for (int i = 0; i < N - 1; i++) {
            int option = rand() % S;
            if (option == P) {
                sum += 1;
                break;
            }
        }
    }

    printf("%f\n", (double)sum / (double)ITERS);

    return 0;
}