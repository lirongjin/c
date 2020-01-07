#include <stdio.h>
#include <stdarg.h>

void func(int i, ...);

int main()
{

    func(1, 2, 3, 4, 5, -1);
    func(1000, 1, 2, 3, 4, -1);

}



void func(int i, ...)
{
    va_list ap;
    int val;

    va_start(ap, i);
    val = va_arg(ap, int);
    while(val != -1)
    {
	printf("%d ", val);
        val = va_arg(ap, int);
    }

    printf("\n");

    va_end(ap);
}
