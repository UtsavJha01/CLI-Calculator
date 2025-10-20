#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void basicOperations();
void advancedOperations();
void areaVolume();

int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("     CLI CALCULATOR MENU\n");
        printf("==============================\n");
        printf("1. Basic Operations (+, -, *, /, %%)\n");
        printf("2. Advanced Operations (Power, Roots, Trig)\n");
        printf("3. Area & Volume Calculations\n");
        printf("4. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: basicOperations(); break;
            case 2: advancedOperations(); break;
            case 3: areaVolume(); break;
            case 4: printf("Exiting Calculator. Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Try again!\n");
        }
    }

    return 0;
}


void basicOperations() {
    double a, b, result;
    int op;

    printf("\n---- BASIC OPERATIONS ----\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n");
    printf("Choose operation: ");
    scanf("%d", &op);

    if (op == 5) {
        int x, y;
        printf("Enter two integers: ");
        scanf("%d%d", &x, &y);
        printf("Result = %d\n", x % y);
        return;
    }

    printf("Enter two numbers: ");
    scanf("%lf%lf", &a, &b);

    switch (op) {
        case 1: result = a + b; break;
        case 2: result = a - b; break;
        case 3: result = a * b; break;
        case 4: result = (b != 0) ? a / b : NAN; break;
        default: printf("Invalid Operation!\n"); return;
    }

    if (isnan(result)) printf("Error: Division by zero!\n");
    else printf("Result = %.4lf\n", result);
}


void advancedOperations() {
    double n, m, result;
    int op;

    printf("\n---- ADVANCED OPERATIONS ----\n");
    printf("1. Power\n2. Square Root\n3. Cube Root\n4. Logarithm\n5. Sine\n6. Cosine\n7. Tangent\n8. Factorial\n");
    printf("Choose operation: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Enter base and exponent: ");
            scanf("%lf%lf", &n, &m);
            printf("Result = %.4lf\n", pow(n, m));
            break;
        case 2:
            printf("Enter number: ");
            scanf("%lf", &n);
            printf("Square Root = %.4lf\n", sqrt(n));
            break;
        case 3:
            printf("Enter number: ");
            scanf("%lf", &n);
            printf("Cube Root = %.4lf\n", cbrt(n));
            break;
        case 4:
            printf("Enter number: ");
            scanf("%lf", &n);
            printf("Log (base e) = %.4lf\n", log(n));
            break;
        case 5:
            printf("Enter angle in degrees: ");
            scanf("%lf", &n);
            printf("sin(%.2lf°) = %.4lf\n", n, sin(n * M_PI / 180));
            break;
        case 6:
            printf("Enter angle in degrees: ");
            scanf("%lf", &n);
            printf("cos(%.2lf°) = %.4lf\n", n, cos(n * M_PI / 180));
            break;
        case 7:
            printf("Enter angle in degrees: ");
            scanf("%lf", &n);
            printf("tan(%.2lf°) = %.4lf\n", n, tan(n * M_PI / 180));
            break;
        case 8: {
            int num;
            unsigned long long fact = 1;
            printf("Enter integer: ");
            scanf("%d", &num);
            for (int i = 1; i <= num; i++) fact *= i;
            printf("Factorial(%d) = %llu\n", num, fact);
            break;
        }
        default: printf("Invalid choice!\n");
    }
}


void areaVolume() {
    int choice;
    double r, l, b, h, area, volume;

    printf("\n---- AREA & VOLUME CALCULATIONS ----\n");
    printf("1. Area of Circle\n2. Area of Rectangle\n3. Area of Triangle\n");
    printf("4. Volume of Sphere\n5. Volume of Cylinder\n6. Volume of Cuboid\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter radius: ");
            scanf("%lf", &r);
            area = M_PI * r * r;
            printf("Area of Circle = %.4lf\n", area);
            break;
        case 2:
            printf("Enter length and breadth: ");
            scanf("%lf%lf", &l, &b);
            area = l * b;
            printf("Area of Rectangle = %.4lf\n", area);
            break;
        case 3:
            printf("Enter base and height: ");
            scanf("%lf%lf", &b, &h);
            area = 0.5 * b * h;
            printf("Area of Triangle = %.4lf\n", area);
            break;
        case 4:
            printf("Enter radius: ");
            scanf("%lf", &r);
            volume = (4.0 / 3.0) * M_PI * pow(r, 3);
            printf("Volume of Sphere = %.4lf\n", volume);
            break;
        case 5:
            printf("Enter radius and height: ");
            scanf("%lf%lf", &r, &h);
            volume = M_PI * r * r * h;
            printf("Volume of Cylinder = %.4lf\n", volume);
            break;
        case 6:
            printf("Enter length, breadth, and height: ");
            scanf("%lf%lf%lf", &l, &b, &h);
            volume = l * b * h;
            printf("Volume of Cuboid = %.4lf\n", volume);
            break;
        default:
            printf("Invalid choice!\n");
    }
}