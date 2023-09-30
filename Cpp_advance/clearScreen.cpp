#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main() {
    for (int i = 1; i <= 3; i++) {
        cout << "line " << i << endl;
    }
    Sleep(5000); // Đợi 5 giây
	cout << "\x1B[2J\x1B[H"; // Xóa màn hình và đưa con trỏ về đầu
    // system("cls"); // Xóa màn hình

    for (int i = 1; i <= 3; i++) {
        cout << "new line " << i << endl;
    }

    return 0;
}
