#include <iostream>

int findMin(int a[], int n);

int main(){
    int arr[] = {45, 23, 67, 12, 89, 34, 56};
    int n = 7;

    std::cout << "Array: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "The minimum element in the array is: " << findMin(arr, n) << "\n";

    return 0;
}

int findMin(int a[], int n){
    // Base case
    if (n == 1){
        return a[0];
    }
    // if last smaller?
    else {
        int minRest = findMin(a, n - 1);
        return (a[n - 1] < minRest) ? a[n - 1] : minRest;
    }
}
