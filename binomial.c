/*
Suppose that out of any given message that you receive from your
colleague there is an 80% chance that it has serious content, there is
a 10% chance that it is an unfunny meme and a 10% chance that it is a
funny meme. When you receive a funny meme, you always
acknowledge it. If you get exactly 20 messages in a day from your
colleague. What is the probability that 3 or more of those messages
contain an unfunny meme.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int sum = 0;
#define ITERS 1000000
#define N 20
#define A 3
#define P 1  // 1/10
#define S 10

    for (int d = 0; d < ITERS; d++) {
        int unfunny_memes = 0;
        for (int i = 0; i < N; i++) {
            int option = rand() % S;
            if (option == P) {
                unfunny_memes += 1;
            }
            if (unfunny_memes >= A) {
                sum += 1;
                break;
            }
        }
    }

    printf("%f\n", (double)sum / (double)ITERS);

    return 0;
}