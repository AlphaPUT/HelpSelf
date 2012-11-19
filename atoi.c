#include <stdio.h>
#include <assert.h>
#define true 1
#define false 0
int myatoi(char *c)
{
    char *p;
    p = c;
    int re;//result
    int flag = false;
    assert(c);
    if((*p) == '-' || (*p) == '+') {
        p++;
        if((*p) == '-') {
            flag = true;
        }
    }
    while(*p != '\0') {
        if(isdigit(*p)) {
            re = re * 10 + (*p) - '0';
            p++;
        } else {
            return  flag ? -re : re;
        }
    }
    return flag ? -re : re;
}
int main()
{
    char *t = "+12345.45";
    int re = myatoi(t);
    if(re != -1)
        printf("%i\n",re);
    return 0;
}
