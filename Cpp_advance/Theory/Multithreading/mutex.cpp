#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Khai báo mutex

void function1() {
    mtx.lock(); // Khóa mutex
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 1: " << i << std::endl;
    }
    mtx.unlock(); // Mở khóa mutex
}

void function2() {
    mtx.lock(); // Khóa mutex
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2: " << i << std::endl;
    }
    mtx.unlock(); // Mở khóa mutex
}

int main() {
    std::thread t1(function1);
    std::thread t2(function2);

    t1.join();
    t2.join();

    std::cout << "Main thread: All threads have finished." << std::endl;

    return 0;
}
