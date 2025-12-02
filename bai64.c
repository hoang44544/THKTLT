#include <stdio.h>
// Bài 64. Viết chương trình nhập mảng 1 chiều A có N phần tử  có sử dụng hàm(với N 
// nhập từ bàn phím). :   
// a. Xuất các phần tử đã nhập ra màn hình. 
// b. Xuất ra màn hình số nguyên tố cuối cùng của mảng (nếu có),còn không xuất 
// ra dòng “Không có số nguyên tố trong mảng”  ? 
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

    int A[N];
    printf("Nhap %d phan tu cho mang:\n", N);
    for (int i = 0; i < N; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    int lastPrime = -1;
    for (int i = 0; i < N; i++) {
        if (isPrime(A[i])) {
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