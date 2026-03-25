#include <iostream>

int findsum(int a[], int n);

int main(){
    int arr[] = {1, 1, 1, 1, 1, 1, 1};
    int n = 7;

    std::cout << "Array: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "The sum of the array is: " << findsum(arr, n) << "\n";

    return 0;
}

int findsum(int a[], int n){
    // Base case first index
    if (n == 1){
        return a[0];
    }
    // from n-1 index
    else {
        return a[n-1] + findsum(a, n-1);
    }
}