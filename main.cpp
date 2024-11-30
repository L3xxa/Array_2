#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 mersenne(rd());
    uniform_int_distribution<int> uid(0, 10);

    const int size = 5;
    int array[size][size];
    int sum = 0;

    for (int i = 0; i < size; i++) {
        int sum_row = 0;
        for (int j = 0; j < size; j++) {
            array[i][j] = uid(mersenne);
            sum_row += array[i][j];
            sum += array[i][j];
            cout << setw(3) << array[i][j] << " ";
        }
        cout << "   |" << setw(4) << sum_row << endl;
    }

    cout << "---------------------------" << endl;

    for (int j = 0; j < size; j++) {
        int sum_col = 0;
        for (int i = 0; i < size; i++) {
            sum_col += array[i][j];
        }
        cout << setw(3) << sum_col << " ";
    }
    cout << "   |" << setw(4) << sum << endl;

    return 0;
}