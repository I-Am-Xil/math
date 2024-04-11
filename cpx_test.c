//* gcc cpx_test.c -o cpx_tesx.exe

#include<stdio.h>
#include "libraries\cpx.h"

int main() {
    //hello_world();

    complex c = {1.0, 1.0};
    complex c2 = {2.0, 3.0};

    print_complex(&c);
    c = add_complex(c, c2);
    print_complex(&c);
    c = mul_complex(c, c2);
    print_complex(&c);
    float modulus = mod_complex(c);
    printf("%f\n", modulus);
    c = complex_conjugate(c);
    print_complex(&c);
    polar cpolar = complex_to_polar(c);
    printf("%f, %ftheta\n", cpolar.r, cpolar.theta);

    return 0;
}