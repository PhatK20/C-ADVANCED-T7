/* #include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    // Sử dụng std::rand() để tạo số ngẫu nhiên và chia cho phạm vi mong muốn, sau đó cộng với giá trị tối thiểu
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main() {
    // Khởi tạo bộ sinh số ngẫu nhiên với thời gian hiện tại làm hạt giống
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Lấy số ngẫu nhiên trong khoảng từ 30 đến 70 và in ra màn hình
    int randomValue = getRandomNumber(30, 70);
    std::cout << "Số ngẫu nhiên: " << randomValue << std::endl;

    return 0;
}
 */

#include <iostream>
#include <random>

int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

int main() {
    // Lấy số ngẫu nhiên trong khoảng từ 30 đến 70 và in ra màn hình
    int randomValue = getRandomNumber(30, 70);
    std::cout << "Số ngẫu nhiên: " << randomValue << std::endl;

    return 0;
}
