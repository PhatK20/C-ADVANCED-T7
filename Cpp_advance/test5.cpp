#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

int main() {
    for (int i = 0; i <= 100; ++i) {
        std::cout << "Percent complete: " << i << "%" << std::flush;
        
        // Di chuyển con trỏ về đầu dòng
        std::cout << '\r';
        
        // Tạo độ trễ nhằm mô phỏng quá trình thay đổi
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    system("cls");

    // Xuất ra kết quả mới
    std::cout << "Ket qua moi o day!" << std::endl;
    std::cout << std::endl;
    return 0;
}
