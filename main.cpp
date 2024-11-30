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

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = uid(mersenne);
            cout << setw(3) <<  array[i][j] << " ";
        }
        cout << endl;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += array[i][j];
        }
    }

    int median = sum / size;

    int max = 0;
    for (int i = 0; i < size; i++ ) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }

    int min = array[0][0];
    for (int i = 0; i < size; i++ ) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }

    cout << "Sum of all elements is " << sum << endl;
    cout << "Median of all elements is " << median << endl;
    cout << "Max of all elements is " << max << endl;
    cout << "Min of all elements is " << min << endl;

    return 0;
}