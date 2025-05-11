#include<iostream>
using namespace std;

int main(){
    int numbers[6] = {1, 2, 3, 4, 5}; // Make room for insertion
    int num = 10, k = 2, len = 5, j = len - 1;

    // Insert at position k
    while(j >= k){
        numbers[j + 1] = numbers[j];
        j--;
    }
    numbers[k] = num;
    len++; // Array has one more element now

    cout << "After Insertion:" << endl;
    for(int i = 0; i < len; i++){
        cout << numbers[i] << endl;
    }

    // Delete at position k
    for(int i = k; i < len - 1; i++){
        numbers[i] = numbers[i + 1];
    }
    len--; // Array now has one less element

    cout << "After Deletion:" << endl;
    for(int i = 0; i < len; i++){
        cout << numbers[i] << endl;
    }

    return 0;
}
