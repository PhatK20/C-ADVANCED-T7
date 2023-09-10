#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* ptr = (int*)malloc(sizeof(int)); // Cấp phát bộ nhớ cho con trỏ
	*ptr = 42; // Đặt giá trị vào địa chỉ mà con trỏ trỏ tới

	printf("Value pointed to by ptr: %d\n", *ptr);
	printf("Value pointed to by ptr: %p\n", ptr);
	free(ptr); // Giải phóng bộ nhớ
	//ptr = NULL;
	// Bây giờ ptr không nên được sử dụng nữa, vì bộ nhớ đã được giải phóng

	// Lưu ý: Dưới đây là các ví dụ không chính thức để minh họa
	// tình huống đã giải phóng bộ nhớ, và sử dụng con trỏ sau khi giải phóng là không an toàn.

	printf("Value pointed to by ptr: %d\n", *ptr); // Có thể gây lỗi không xác định
	printf("Value pointed to by ptr: %p\n", ptr);
	return 0;
}

