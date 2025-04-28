#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define BUCKETS 10
#define BALLS 100000

#define GRID_Y BUCKETS - 1
#define GRID_X BUCKETS * 2 - 1
#define BALL_X_START BUCKETS - 1
#define PROBABILITY_PEG 0.5f

int distribution[GRID_X] = {0};
bool grid[GRID_Y][GRID_X] = {0};
bool visited[GRID_Y][GRID_X] = {0};

#define TABLE_SCALE 1000
#define TABLE_Y (BALLS / TABLE_SCALE) / 2
#define TABLE_X BUCKETS
bool table[TABLE_Y][TABLE_X] = {};

unsigned long long fact(int v) {
    if (v == 0) {
        return 1;
    }
    return v * fact(v - 1);
}

unsigned long long binom(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

double _pow(double v, int p) {
    double r = v;
    if (p == 0) {
        return 1.0;
    }
    while (p-- > 1) {
        r *= v;
    }
    return r;
}

double calc_distribution(int n, int k) {
    unsigned long long b = binom(n, k);
    return b * _pow(PROBABILITY_PEG, k) *
           _pow(1.0f - PROBABILITY_PEG, n - k);
}

int main(void) {
    // Initialize pegs, for a more even distribution.
    for (int y = 0; y < GRID_Y; y++) {
        for (int x = 0; x < GRID_X; x += 2) {
            grid[y][x] = true;
        }
    }

    for (int b = 0; b < BALLS; b++) {
        int x = BALL_X_START;
        for (int y = 0; y < GRID_Y; y++) {
            grid[y][x] = !grid[y][x];
            if (grid[y][x] == true) {
                x--;
            } else {
                x++;
            }
        }
        distribution[x]++;
    }

    int max = 0;
    for (int x = 0; x < TABLE_X; x++) {
        int v = distribution[x * 2];
        for (int y = 0; y < v; y += TABLE_SCALE) {
            table[TABLE_Y - 1 - y / TABLE_SCALE][x] = true;
            if (v > max) {
                max = v;
            }
        }
    }

    for (int y = TABLE_Y - max / TABLE_SCALE - 2; y < TABLE_Y; y++) {
        for (int x = 0; x < TABLE_X; x++) {
            char c = (table[y][x]) ? 'X' : ' ';
            printf("%c", c);
        }
        printf("\n");
    }

    printf("\n");
    printf("Bucket probability: \n");
    printf("Index \t Simulation \t Binomial distribution \n");
    for (int i = 0; i < GRID_X; i += 2) {
        double v = calc_distribution(BUCKETS, i / 2 + 1);
        printf("%i: \t %Lf, \t %lf\n", i / 2 + 1,
               (long double)distribution[i] / (long double)BALLS, v);
    }

    return 0;
}