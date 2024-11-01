#include <iostream>
#include <iomanip>
#include <cstring>

void PT(int **arr, int num) {
    arr[0][0] = 1;
    if (num == 1) return;
   
    arr[1][0] = 1;
    arr[1][1] = 1;
    if (num == 2) return;
   
    for (int i = 2; i < num; i++) {
        arr[i][0] = 1;  
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
        arr[i][i] = 1;  
    }
}

int main() {
    int number;
    std::cout << "enter a number";  
    std::cin >> number;              
    int **array = new int*[number];
    for (int j = 0; j < number; j++) {
        array[j] = new int[j+1];
        std::memset(array[j], 0, sizeof(int) * (j+1));
    }
    PT(array, number);

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < (number-i); j++) {
            std::cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

}