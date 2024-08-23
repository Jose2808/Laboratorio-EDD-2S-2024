#include <iostream>

void insertionSort(int[], int);
void printArray(int[], int);

int main()
{
    int a[] = {10, 6, 20, 300, 1, 0, 16, 6};
    int n = sizeof(a)/sizeof(a[0]);

    insertionSort(a, n);
    printArray(a, n);
    return 0;
}

void insertionSort(int arr[], int largo){
    for(int i = 1; i < largo; i++){
        int llave = arr[i];
        int j = i - 1;

        while((j >= 0) && (arr[j] > llave)){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = llave;
    }
}

void printArray(int arr[], int largo){
    for(int i = 0; i < largo; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}