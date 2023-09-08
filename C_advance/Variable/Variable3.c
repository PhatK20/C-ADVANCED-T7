#include <stdio.h>
#include <stdbool.h>

#include <time.h>

// register



int main(int argc, char const *argv[])
{
    clock_t start, end;
    // register int i;  
    // register trong mỗi máy có giới hạn, đọc xem datasheet sẽ thấy
    // register giúp máy chạy nhanh hơn
    int i;

    start = clock();      // 1s

    for ( i; i < 0xFFFFFFFF; i++);

    end = clock();       //6 s


    printf("time: %f\n", (double)((end- start)/CLOCKS_PER_SEC));
    
    
    
    return 0;
}