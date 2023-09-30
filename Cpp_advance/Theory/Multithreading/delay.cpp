#include <iostream>
#include <thread>
#include <chrono>

void threadFunction1() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Thread 1: Count " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Đợi 1 giây
    }
}

void threadFunction2() {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Thread 2: Count " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Đợi 500 mili giây
    }
}

int main() {
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);

    t1.join();
    t2.join();

    std::cout << "Main thread: All threads have finished." << std::endl;

    return 0;
}
