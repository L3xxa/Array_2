#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    int x;
    cout << "Enter a number: ";
    cin >> x;

    const int size_x = 5;
    const int size_y = 5;
    int arr[size_x][size_y];

    int current_value = x;

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            arr[i][j] = current_value;
            current_value += 1;
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}