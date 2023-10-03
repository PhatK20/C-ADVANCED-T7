#include <stdio.h>


//static

void test(){
    static int i=0; 
    // biến static tồn tại cho đến khi kết thúc chương trình.
    // dùng để khởi tạo giá trị đầu tiên cho biến
    // nó chỉ khởi tạo giá trị ở lần gọi đầu tiên khi gọi lại nó sẽ ko khởi tạo nữa
    printf("i = %d\n", i++);
}

int main(){
    test();// khởi tạo biến static và chạy các lệnh còn lại

    test();// bỏ qua khởi tạo biến static và chạy các lệnh còn lại
    test();
    return 0;
}