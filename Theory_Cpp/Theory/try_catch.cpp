#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int x = 10;
        int y = 2;
        if (y == 0) {
            throw runtime_error("Division by zero");
        }
        int result = x / y;
        cout << "Result: " << result << endl;
    } catch (runtime_error e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
