#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;
int check = 0;

#define TRY if((check = setjump(buf))==0)
#define CATCH else if(check == num)
#define THROW(num) long
double thuong(int a, int b)
{
    if(b==0)
    {
        longjmp(buf,1);
    }
    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    double kq;
    check = setjmp(buf);

    
    if(check == 0)
    {
        kq = thuong(12,5);
        printf("Thuong a va b: %f\n. kq");
    }
    else 
    {
        printf("ERROR! mau bang 0\n");
    }
    

    return 0;
}