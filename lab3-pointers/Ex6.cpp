#include <iostream>

int main()
{
    int arr[] = {43, 12, 31, -31, 521, 34, 17};
    int sum = 0;
    long long mut = 1;

    int *p = arr;

    int arrayLength = sizeof(arr) / sizeof(*p);

    for (int i = 0; i < arrayLength; i++)
    {
        std::cout << *(p + i) << " ";
        sum += *(p + i);
        mut *= *(p + i);
    }
    std::cout << "\n";

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Mut: " << mut << "\n";

    return 0;
}
