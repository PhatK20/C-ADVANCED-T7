#include<stdio.h>
#define f(x) (x+1)
#define  m 5
int main()
{
    int a,b;
    
    scanf("%d %d",&a,&b);
    int x=2;
    a*=f(3);
    b*=f(9);
    printf("%d\n%d\n",a,b);
    printf("%d\n",a+b);
    printf("Hello world");

}