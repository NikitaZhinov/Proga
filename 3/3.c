#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    char *isPrime = (char *)malloc((n + 1) * sizeof(char));
    for (int i = 2; i <= n; ++i)
        isPrime[i] = 1;

    for (int i = 2; i * i <= n; ++i)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;

    for (int i = 2; i <= n; ++i)
        if (isPrime[i])
            printf("%d ", i);
    printf("\n");

    free(isPrime);
    return 0;
}