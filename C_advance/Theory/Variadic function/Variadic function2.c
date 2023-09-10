#include <stdio.h>
#include <stdarg.h>

// hàm tính tổng ko có xác định số lượng số hạng và số hạng kiểu int, double đều được
double tinhTong(...)
{
    double tong = 0.0;

    va_list danhSachSoHang;
    va_start(danhSachSoHang, NULL);

    double soHang = va_arg(danhSachSoHang, double);
    while (soHang != 0) {
        tong += soHang;
        soHang = va_arg(danhSachSoHang, double);
    }

    va_end(danhSachSoHang);

    return tong;
}

int main()
{
    double tong1 = tinhTong(1.5, 2.7, 3.8, 0);
    printf("Tong 1 = %.2f\n", tong1);

    double tong2 = tinhTong(4.5, 2.1, 3.3, 1.9, 0);
    printf("Tong 2 = %.2f\n", tong2);

    double tong3 = tinhTong(1.0, 2, 3, 4.5, 0);
    printf("Tong 3 = %.2f\n", tong3);

    return 0;
}
