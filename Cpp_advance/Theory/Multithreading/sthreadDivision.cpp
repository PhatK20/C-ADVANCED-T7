#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>   // Để sử dụng _kbhit và _getch
#include <windows.h> // Để sử dụng hàm clear screen
#include <mutex>     // Để sử dụng mutex

using namespace std;

// Biến cờ để kiểm tra điều kiện dừng
bool shouldExit = false;

// Biến để lưu giá trị "Count:" và "Ban vua nhan phim:"
string displayString = "";

// Mutex để đồng bộ hóa truy cập và cập nhật chuỗi hiển thị
std::mutex displayMutex;

// Biến và mutex để đếm số
int countValue = 0;
std::mutex countMutex;

// Hàm để nhập từ bàn phím trong một luồng riêng
void getInput()
{
    while (!shouldExit)
    {
        if (_kbhit())
        {
            char ch = _getch();
            cout << "\x1B[2J\x1B[H"; // Xóa màn hình

            // Kiểm tra nếu người dùng nhấn phím "q", đặt biến cờ để dừng chương trình
            if (ch == 'q')
            {
                shouldExit = true;
            }
            else
            {
                displayMutex.lock();
                displayString = "Ban vua nhan phim: " + string(1, ch) + "\n";
                displayMutex.unlock();
            }
        }
    }
}

// Hàm để hiển thị "Count:" và "Ban vua nhan phim:" trong một luồng riêng
void displayData()
{
    while (!shouldExit)
    {
        displayMutex.lock();     // Khóa mutex trước khi truy cập chuỗi hiển thị
        cout << "\x1B[2J\x1B[H"; // Xóa màn hình
        cout << "Count: " << countValue << "\n";
        cout << displayString;                      // Hiển thị chuỗi hiển thị
        displayMutex.unlock();                      // Mở khóa mutex sau khi hoàn thành
        this_thread::sleep_for(chrono::seconds(1)); // Dừng chương trình trong 1 giây
    }
}

// Hàm để đếm số trong một luồng riêng
void countNumbers()
{
    while (!shouldExit)
    {
        countMutex.lock(); // Khóa mutex trước khi cập nhật biến countValue
        countValue++;
        countMutex.unlock();                        // Mở khóa mutex sau khi hoàn thành
        this_thread::sleep_for(chrono::seconds(1)); // Đếm số sau mỗi 1 giây
    }
}

int main()
{
    // Tạo luồng cho phần nhập từ bàn phím
    std::thread inputThread(getInput);

    // Tạo luồng cho phần hiển thị "Count:" và "Ban vua nhan phim:"
    std::thread displayThread(displayData);

    // Tạo luồng cho phần đếm số
    std::thread countThread(countNumbers);

    // Chờ cho cả ba luồng kết thúc
    inputThread.join();
    displayThread.join();
    countThread.join();

    return 0;
}
