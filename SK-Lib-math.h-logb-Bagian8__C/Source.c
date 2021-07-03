#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>
#include <conio.h>

int main(void) {
    double a = 203.58;
    printf("Given the number %.2f or %a in hex,\n", a, a);

    double b;
    double c = modf(a, &b);
    printf("modf() makes %.0f + %.2f\n", b, c);

    int i;
    c = frexp(a, &i);
    printf("frexp() makes %f * 2^%d\n", c, i);

    i = logb(a);
    printf("logb()/logb() make %f * %d^%d\n", a / scalbn(1.0, i), FLT_RADIX, i);

    // error handling
    feclearexcept(FE_ALL_EXCEPT);
    printf("logb(0) = %f\n", logb(0));
    
    if (fetestexcept(FE_DIVBYZERO)) {
        puts("    FE_DIVBYZERO raised");
    }

    _getch();
    return 0;
}