#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Nhap a (a != 0): ");
    scanf("%lf", &a);

    printf("Nhap b: ");
    scanf("%lf", &b);

    printf("Nhap c: ");
    scanf("%lf", &c);

    if (fabs(a) < 1e-12) {
        printf("a phai khac 0.\n");
        return 0;
    }

    double delta = b*b - 4*a*c;
    double t1, t2;
    int dem = 0;

    if (delta < 0) {
        printf("Phuong trinh vo nghiem.\n");
        return 0;
    }
    else if (fabs(delta) < 1e-12) {
        // t = -b/(2a)
        t1 = -b / (2*a);

        if (t1 > 0) {
            dem = 2; // x = ±sqrt(t1)
        } else if (fabs(t1) < 1e-12) {
            dem = 1; // x = 0
        } else {
            dem = 0;
        }
    }
    else {
        t1 = (-b + sqrt(delta)) / (2*a);
        t2 = (-b - sqrt(delta)) / (2*a);

        // Xét nghiệm t1
        if (t1 > 0) dem += 2;
        else if (fabs(t1) < 1e-12) dem += 1;

        // Xét nghiệm t2
        if (t2 > 0) dem += 2;
        else if (fabs(t2) < 1e-12) dem += 1;
    }

    printf("So nghiem thuc phan biet: %d\n", dem);
    return 0;
}
