#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int size = 5;
    int array[size][size];

    cout << "Initial array:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = i + j;
            cout << setw(3) << array[i][j] << " ";
        }
        cout << endl;
    }

    int shifts;
    string direction;

    cout << "\nEnter the number of shifts: ";
    cin >> shifts;
    cout << "Enter the direction (left, right, up, down): ";
    cin >> direction;

    if (direction == "up") {
        for (int shift = 0; shift < shifts; shift++) {
            int temp[size];
            for (int j = 0; j < size; j++) {
                temp[j] = array[0][j];
            }
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size; j++) {
                    array[i][j] = array[i + 1][j];
                }
            }
            for (int j = 0; j < size; j++) {
                array[size - 1][j] = temp[j];
            }
        }
    } else if (direction == "down") {
        for (int shift = 0; shift < shifts; shift++) {
            int temp[size];
            for (int j = 0; j < size; j++) {
                temp[j] = array[size - 1][j];
            }
            for (int i = size - 1; i > 0; i--) {
                for (int j = 0; j < size; j++) {
                    array[i][j] = array[i - 1][j];
                }
            }
            for (int j = 0; j < size; j++) {
                array[0][j] = temp[j];
            }
        }
    } else if (direction == "left") {
        for (int shift = 0; shift < shifts; shift++) {
            int temp[size];
            for (int i = 0; i < size; i++) {
                temp[i] = array[i][0];
            }
            for (int j = 0; j < size - 1; j++) {
                for (int i = 0; i < size; i++) {
                    array[i][j] = array[i][j + 1];
                }
            }
            for (int i = 0; i < size; i++) {
                array[i][size - 1] = temp[i];
            }
        }
    } else if (direction == "right") {
        for (int shift = 0; shift < shifts; shift++) {
            int temp[size];
            for (int i = 0; i < size; i++) {
                temp[i] = array[i][size - 1];
            }

            for (int j = size - 1; j > 0; j--) {
                for (int i = 0; i < size; i++) {
                    array[i][j] = array[i][j - 1];
                }
            }
            for (int i = 0; i < size; i++) {
                array[i][0] = temp[i];
            }
        }
    } else {
        cout << "Incorrect direction!" << endl;
        return 1;
    }


    cout << "\nArray after shift:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
