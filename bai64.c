#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N;
    printf("Nhap so luong phan tu N: ");
    scanf("%d", &N);
    char input[100];
    int A[N];
    printf("Nhap %d phan tu cho mang:\n", N);
    for (int i = 0; i < N; i++) {
        printf("A[%d] = ", i);
        scanf("%s", input);
        if (strchr(input, '.') != NULL) {
            A[i] = -1; //đánh dấu kh hợp lệ
            continue;
        }
        A[i] = atoi(input);
    }
    int lastPrime = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] != -1 && isPrime(A[i])) {
            lastPrime = A[i];
        }
    }
    if (lastPrime != -1) {
        printf("So nguyen to cuoi cung trong mang la: %d\n", lastPrime);
    } else {
        printf("Khong co so nguyen to trong mang.\n");
    }
    return 0;
}
