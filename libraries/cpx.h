#include <math.h>

const float PI = 3.1415;

//TODO: a Struct with float types for real and imaginary components

typedef struct
{
    float r;
    float i;
} complex;


typedef struct
{
    float r;
    float theta;
} polar;


void print_complex(complex *c){
    printf("(%f, %fi)\n", c->r, c->i);
}


complex add_complex(complex c1, complex c2){
    return (complex){c1.r + c2.r, c1.i + c2.i};
}


complex mul_complex(complex c1, complex c2){
    return (complex){c1.r*c2.r - c1.i*c2.i, c1.r*c2.i + c2.r*c1.i};
}


float mod_complex(complex c){
    return sqrtf(powf(c.r, 2) + powf(c.i, 2));
}


complex complex_conjugate(complex c){
    return (complex){c.r, -c.i};
}


polar complex_to_polar(complex c){
    float r = mod_complex(c);
    return (polar){r, atan2f(c.i, c.r)};
}