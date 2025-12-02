#include <stdio.h>
#include <math.h>
//Bài 15. Cho tam giác ABC với 3 đỉnh A,B,C có tọa độ là:(x1,y1),(x2,y2),(x3,y3)
//a. Diện tích của tam giác 
//b. Chu vi của tam giác 
//Viết chương trình sử dụng hàm để giải bài toán này. 
int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Nhap toa do diem A (x1 y1): ");
    scanf("%d %d", &x1, &y1);   
    printf("Nhap toa do diem B (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Nhap toa do diem C (x3 y3): ");
    scanf("%d %d", &x3, &y3);
    float a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    float b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    float c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    float p = (a + b + c) / 2;
    float dien_tich = sqrt(p * (p - a) * (p - b) * (p - c));
    float chu_vi = a + b + c;
    printf("Dien tich: %.2f\n", dien_tich);
    printf("Chu vi: %.2f\n", chu_vi);
    return 0;
}