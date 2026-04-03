#include <iostream>

void findMaxMin(int* arr, int *max, int *min);

int main(){
    int p[] = {43,12,31,-31,521,34,17};
    int max, min;

    findMaxMin(p, &max, &min);

    std::cout << "max: " << max << "\n";
    std::cout << "min: " << min << "\n";

    return 0;
}

void findMaxMin(int* arr, int *max, int *min){
    *max = *(arr+0);
    *min = *(arr+0);
    
    // array passsed into function decays into a pointer of first index
    // int arrayLength = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < 7; i++){
        if(*(arr+i) > *max) *max = *(arr + i);
        if(*(arr+i) < *min) *min = *(arr + i);
    }
}