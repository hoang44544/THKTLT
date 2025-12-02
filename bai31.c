#include <stdio.h>
#include <math.h>
// Bài 31.Viết chương trình giải phương trình bậc bốn trùng phương 
// (ax4+bx2+c=0,a!=0). Có đếm số nghiệm khác nhau của phương trình.
int main() {
    float a, b, c;
    printf("Nhap he so a (a != 0): ");
    scanf("%f", &a);
    printf("Nhap he so b: ");
    scanf("%f", &b);
    printf("Nhap he so c: ");
    scanf("%f", &c);

    if (a == 0) {
        printf("He so a phai khac 0.\n");
        return 1;
    }

    float delta = b * b - 4 * a * c;
    int so_nghiem = 0;

    if (delta < 0) {
        so_nghiem = 0;
    } else if (delta == 0) {
        float y = -b / (2 * a);
        if (y > 0) {
            so_nghiem = 2; // Hai nghiem phan biet
        } else if (y == 0) {
            so_nghiem = 1; // Mot nghiem kep
        } else {
            so_nghiem = 0; // Khong co nghiem thuc
        }
    } else {
        float y1 = (-b + sqrt(delta)) / (2 * a);
        float y2 = (-b - sqrt(delta)) / (2 * a);
        if (y1 > 0) so_nghiem += 2; // Hai nghiem phan biet tu y1
        else if (y1 == 0) so_nghiem += 1; // Mot nghiem kep tu y1
        if (y2 > 0) so_nghiem += 2; // Hai nghiem phan biet tu y2
        else if (y2 == 0) so_nghiem += 1; // Mot nghiem kep tu y2
    }

    printf("So nghiem thuc khac nhau cua phuong trinh: %d\n", so_nghiem);
    return 0;
}