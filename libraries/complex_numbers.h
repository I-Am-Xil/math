#include <math.h>
#include <stdio.h>
#include <assert.h>

#define LEN(x) sizeof((string))/sizeof((string)[0])


typedef struct{
    float r;
    float i;
} complex;


typedef struct{
    float r;
    float theta;
} polar;


#ifndef MATH_SYMBOLS
#define MATH_SYMBOLS


#define SYM_THETA "\xCE\xB8"

#define SUPER_ZERO "\xE2\x81\xB1"
#define SUPER_ONE "\xC2\xB9"
#define SUPER_TWO "\xC2\xB2"
#define SUPER_THREE "\xC2\xB3"
#define SUPER_FOUR "\xE2\x81\xB4"
#define SUPER_FIVE "\xE2\x81\xB5"
#define SUPER_SIX "\xE2\x81\xB6"
#define SUPER_SEVEN "\xE2\x81\xB7"
#define SUPER_EIGHT "\xE2\x81\xB8"
#define SUPER_NINE "\xE2\x81\xB9"

#endif


#ifndef CPX_INTERFACE
#define CPX_INTERFACE
void print_complex(complex c);
complex add_complex(complex c1, complex c2);
complex mul_complex(complex c1, complex c2);
complex div_complex(complex c1, complex c2);
complex pow_complex(complex c, int power);
float mod_complex(complex c);
complex complex_conjugate(complex c);

polar complex_to_polar(complex c);
complex polar_to_complex(polar p);
void print_polar(polar p);
polar add_polar(polar p1, polar p2);
polar mul_polar(polar p1, polar p2);
polar div_polar(polar p1, polar p2);
#endif


#ifndef CPX_IMPLEMENTATION
#define CPX_IMPLEMENTATION

//Complex form

void print_complex(complex c){
    printf("(%f, %fi)\n", c.r, c.i);
}


complex add_complex(complex c1, complex c2){
    return (complex){c1.r + c2.r, c1.i + c2.i};
}


complex mul_complex(complex c1, complex c2){
    return (complex){c1.r*c2.r - c1.i*c2.i, c1.r*c2.i + c2.r*c1.i};
}


complex div_complex(complex c1, complex c2){
    assert(c2.r != 0.0 | c2.i != 0.0);
    float denominator = mul_complex(c2, complex_conjugate(c2)).r;
    return (complex){(c1.r*c2.r + c1.i+c2.i)/denominator, c2.r*c1.i - c1.r*c2.i/denominator};
}


complex pow_complex(complex c, int power){
    polar p = complex_to_polar(c);
    p = (polar){powf(p.r, power), p.theta*power};
    return polar_to_complex(p);
}


void roots_complex(complex c, complex *roots, size_t root){
    polar p = complex_to_polar(c);
    for(int i = 0; i < root; i++){
        polar p_temp = (polar){powf(p.r, 1/(float)root), p.theta + (2*(float)M_PI*i)/(float)root};
        roots[i] = polar_to_complex(p_temp);
    }
    return;
}


float mod_complex(complex c){
    return sqrtf(powf(c.r, 2) + powf(c.i, 2));
}


complex complex_conjugate(complex c){
    return (complex){c.r, -c.i};
}



// Polar representation

polar complex_to_polar(complex c){
    float r = mod_complex(c);
    return (polar){r, atan2f(c.i, c.r)};
}


complex polar_to_complex(polar p){
    return (complex){p.r*cos(p.theta), p.r*sin(p.theta)};
}


void print_polar(polar p){
    printf("(%f, %f%s)\n", p.r, p.theta, SYM_THETA);
}


polar add_polar(polar p1, polar p2){
    complex c = add_complex(polar_to_complex(p1), polar_to_complex(p2));
    return complex_to_polar(c);
}


polar mul_polar(polar p1, polar p2){
    return (polar){p1.r*p2.r, p1.theta+p2.theta};
}


polar div_polar(polar p1, polar p2){
    assert(p2.r != 0.0);
    return (polar){p1.r/p2.r, p1.theta-p2.theta};
}

#endif
