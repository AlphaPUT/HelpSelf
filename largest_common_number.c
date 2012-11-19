#include <stdio.h>
int gcd(int a,int b) {
    if(b <= 0) return a;
    else gcd(b,a % b);
}
int main()
{
    int result = gcd(4,2);
    printf("%i\n",result);
    return 0;
}
