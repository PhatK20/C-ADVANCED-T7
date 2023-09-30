#include <iostream>
#include <thread>

void function1() {
    // Code của luồng 1 ở đây
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 1: " << i << std::endl;
    }
}

void function2() {
    // Code của luồng 2 ở đây
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2: " << i << std::endl;
    }
}

int main() {
    // Tạo và khởi chạy hai luồng
    std::thread t1(function1);
    std::thread t2(function2);

    // Đợi cho tất cả các luồng hoàn thành
    t1.join();
    t2.join();

    std::cout << "Main thread: All threads have finished." << std::endl;

    return 0;
}
