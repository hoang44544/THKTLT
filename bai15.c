#include <stdio.h>
#include <math.h>

double khoang_cach(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
double dien_tich(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
int la_tam_giac(double a, double b, double c) {
    return (a + b > c && a + c > b && b + c > a);
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("Nhap toa do diem A (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Nhap toa do diem B (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Nhap toa do diem C (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);
    double a = khoang_cach(x1, y1, x2, y2);
    double b = khoang_cach(x2, y2, x3, y3);
    double c = khoang_cach(x3, y3, x1, y1);
    if (!la_tam_giac(a, b, c)) {
        printf("Ba diem khong tao thanh tam giac.\n");
        return 0;
    }
    double S = dien_tich(a, b, c);
    double P = a + b + c;
    printf("Dien tich tam giac: %.2lf\n", S);
    printf("Chu vi tam giac: %.2lf\n", P);
    return 0;
}
