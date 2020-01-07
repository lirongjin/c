#include <stdio.h>

#define show(a)   __builtin_choose_expr(__builtin_types_compatible_p(typeof(a), char), showc(a),    \
                      __builtin_choose_expr(__builtin_types_compatible_p(typeof(a), float), showf(a), 1) )

void showc(char a)
{
    printf("%c\n", a);
}

void showf(float f)
{
    printf("%f\n", f);
}

int main()
{
    char c = 'c';
    float f = 3.14;
    show(f);
}
