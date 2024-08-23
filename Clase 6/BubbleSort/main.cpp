#include <iostream>

void bubbleSort(int[], int);
void printArray(int[], int);

int main()
{
    int a[] = {10, 6, 20, 300, 1, 0, 16, 6};
    int n = sizeof(a)/sizeof(a[0]);

    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}

void bubbleSort(int arr[], int largo){
    for(int i = 0; i < largo - 1; i++)
        for(int j = 0; j < largo - i - 1; j++)
            if(arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

void printArray(int arr[], int largo){
    for(int i = 0; i < largo; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
