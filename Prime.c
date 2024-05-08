#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool primeCheck(int x) {
    if (x < 2) {
        return false;
    }

    if (x == 2) {
        return true;
    }

    if (x % 2 == 0) {
        return false;
    }

    int limit = sqrt(x);
    for (int i = 3; i <= limit; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int x;
    scanf("%d", &x);

    bool prime = primeCheck(x);

    if (prime) {
        printf("The number %d is prime\n", x);
    } else {
        printf("The number %d is not prime\n", x);
    }

    return EXIT_SUCCESS;
}
