#include<iostream>
using namespace std;

int LinearSearch(int a[], int n, int key) {
  for (int i = 0; i < n; i++) { // Fixed condition
    if (a[i] == key) {
        return i;
    }
  }
  return -1;
}

int binarySearch(int a[], int n, int key) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2; // Fixed mid calculation

        if (a[mid] == key) {
            return mid;
        } else if (a[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Linear Search result: " << LinearSearch(arr, n, 4) << endl;
    cout << "Binary Search result: " << binarySearch(arr, n, 5) << endl;

    return 0;
}
