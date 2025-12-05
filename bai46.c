#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_valid_int(const char *s, int *value) {
    char *end;
    long num = strtol(s, &end, 10);
    if (*end != '\0') return 0;
    if (num < -2147483648LL || num > 2147483647LL) return 0;
    *value = (int)num;
    return 1;
}

int la_hoan_hao(int n) {
    if (n <= 0) return 0;
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) sum += i;
    }
    return (sum == n);
}

int main() {
    char input[100];
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%s", input);
    // kiểm tra số nguyên
    if (!is_valid_int(input, &n) || n <= 0) {
        printf("Input khong hop le. Yeu cau nhap so nguyen duong.\n");
        return 1;
    }
    if (la_hoan_hao(n))
        printf("%d la so hoan hao.\n", n);
    else
        printf("%d khong phai so hoan hao.\n", n);
    return 0;
}
