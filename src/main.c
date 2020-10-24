#include "stdio.h"
#include "math.h"

void test_float() {
    float x2,y2, deviation=0.0001f, x1 = 1, y1 = 1, f_meaning = 0.0f, s_meaning = 0.0f;
    int count =0;
    do {
        y2 = ((2.0001f + deviation) - 2) / 0.0001f;
        x2 = 2 - y2;
        f_meaning = x2 + 1.0001f * y2;
        if (f_meaning == s_meaning){
            break;
        }
        count++;
        s_meaning = f_meaning;
        deviation = deviation / 2;
    } while (sqrtf(powf((x1 - x2), 2) + powf((y1 - y2), 2)) > 0.000001f);
    printf("Колическво шагов %d\n",count);
    fprintf(stdout, "x2=%.17f y2=%.18f Растояние точек на координатной плоскости :%.20f \n", x2, y2,
            sqrtf(powf((x1 - x2), 2) + powf((y1 - y2), 2)));
    fprintf(stdout, "x1=%.1f y1=%.1f  \n", x1, y1);
}

void test_double() {
    double x2,y2, deviation=0.0001, x1 = 1, y1 = 1, f_meaning = 0.0, s_meaning = 0.0;
    int count =0;
    do {
        y2 = ((2.0001 + deviation) - 2) / 0.0001;
        x2 = 2 - y2;
        f_meaning = x2 + 1.0001 * y2;
        if (f_meaning == s_meaning){
            break;
        }
        count++;
        s_meaning = f_meaning;
        deviation = deviation / 2;
    } while (sqrtf(powf((x1 - x2), 2) + powf((y1 - y2), 2)) > 0.000001f);
    printf("Колическво шагов %d\n",count);
    fprintf(stdout, "x2=%.17f y2=%.18f Растояние точек на координатной плоскости:%.20f \n", x2, y2,
            sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
    fprintf(stdout, "x1=%.1f y1=%.1f  \n", x1, y1);
}



int main() {
    printf("Эксперимент с DOUBLE");
    test_double();
    printf("\n");
    printf("Эксперимент с FLOAT");
    test_float();
    return 0;
}