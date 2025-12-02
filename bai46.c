#include <stdio.h>
#include <math.h>
// Bài 46. Số hoàn hảo là số nguyên dương bằng tổng các ước thực sự của nó và không kể 
// chính nó. Ví dụ: 6=1+2+3. Viết chương trình có sử dụng hàm kiểm tra n (nhập từ bàn 
// phím) có phải số hoàn hảo không ?
int main(){
    int n, sum = 0;
    printf("Nhap mot so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong.\n");
        return 1;
    }

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    if (sum == n) {
        printf("%d la so hoan hao.\n", n);
    } else {
        printf("%d khong phai la so hoan hao.\n", n);
    }

    return 0;
}