#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define M1(x)    var##x
#define M2(x)    printf("mcro test"#x"is %d\n", x)


#define WARN(fmtstr, ...)    mylog(1, fmtstr, __VA_ARGS__)
#define ERROR(fmtstr, args...)    mylog(2, fmtstr, ##args)

int mylog(int level, const char *format, ...);

int main(int argc, int argv)
{
    int M1(1) = 10;
    
    printf("var1 is %d\n", M1(1));
    M2(1000);

    WARN("This is %s", "test warn");
    ERROR("This is %s", "test error");


}

int mylog(int level, const char *format, ...)
{
    va_list pArg;
    char buf[256];

    va_start(pArg, format);
    memset(buf, '\0', sizeof(buf));
    vsnprintf(buf, sizeof(buf), format, pArg);

    char pBuf[10];
    memset(pBuf, '\0', sizeof(pBuf));
    switch(level)
    {
        case 1:
	    strcpy(pBuf, "warn: ");
	    break;
        case 2:
	    strcpy(pBuf, "error: ");
	    break;
	default:
	    break;
    }
    fputs(pBuf, stdout);
    printf("%s\n", buf);

    va_end(pArg);

    return 0;
}
