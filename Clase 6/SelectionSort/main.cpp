#include <iostream>

void selectionSort(int[], int);
void printArray(int[], int);

int main()
{
    int a[] = {10, 6, 20, 300, 1, 0, 16, 6};
    int n = sizeof(a)/sizeof(a[0]);

    selectionSort(a, n);
    printArray(a, n);
    return 0;
}

void selectionSort(int arr[], int largo){
    for(int i = 0; i < largo; i++){
        int min_idx = i;
        for(int j = i + 1; j < largo; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

void printArray(int arr[], int largo){
    for(int i = 0; i < largo; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}