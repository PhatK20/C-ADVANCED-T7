#include <stdio.h>
#include <stdarg.h>

// hàm tính tổng có xác định số lượng số hạng 
double tinhTong(int num, ...)   // số lượng số hạng trong hàm = num
{
    double tong = 0;

    va_list danhSachSoHang; // khai báo kiểu dữ liệu va_list để lưu trữ danh sách các tham số biến đổi
    va_start(danhSachSoHang, num);

    for (int i = 0; i < num; i++)
    {
        double soHang = va_arg(danhSachSoHang, double);// va_arg() lấy giá trị của tham số thuộc kiểu double theo tuần tự
        printf("Tham so biến đổi thứ %d: %.2f\n",i,soHang);
        tong += soHang;
    }

    va_end(danhSachSoHang);//kết thúc việc sử dụng va_list và thực hiện các việc dọn dẹp cần thiết.

    return tong;
}

int main()
{
    double tong = tinhTong(3, 2, 3.7, 1.8);
    printf("Tong = %.2f\n", tong);

    tong = tinhTong(5, 1.0, 2.0, 3, 4.0, 5.0);
    printf("Tong = %.2f\n", tong);

    return 0;
}