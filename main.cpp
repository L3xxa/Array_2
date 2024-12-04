#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 mersenne(rd());
    uniform_int_distribution<int> uid(0, 50);

    const int size_1 = 5;
    const int size_2 = 10;
    int array[size_1][size_2];
    int array_2[size_1][size_2 - 1];

    cout << "<------------------Array: 1------------------>" << endl;
    cout << endl;

    for (int i = 0; i < size_1; i++) {
        for (int j = 0; j < size_2; j++) {
            array[i][j] = uid(mersenne);
            cout << setw(4) << array[i][j];
        }
        cout << endl;
    }
    cout << endl;

    cout << "<------------------Array: 2------------------>" << endl;
    cout << endl;

    for (int i = 0; i < size_1; i++) {
        for (int j = 0; j < size_2; j += 2) {
            if (j + 1 < size_2) {
                array_2[i][j / 2] = array[i][j] + array[i][j + 1];
                cout << setw(4) << array_2[i][j / 2];
            }
        }
        cout << endl;
    }

    return 0;
}
