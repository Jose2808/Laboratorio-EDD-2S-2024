#include <iostream>

void quickSort(int[], int, int);
void printArray(int[], int);

int main()
{
    int a[] = {10, 6, 20, 300, 1, 0, 16, 6};
    int n = sizeof(a)/sizeof(a[0]);

    quickSort(a, 0, n);
    printArray(a, n);
    return 0;
}

void quickSort(int arr[], int primero, int ultimo){
    int x = arr[(primero + ultimo)/2];
    int i = primero;
    int j = ultimo;

    while(true){
        while(arr[i] < x){i++;}
        while(x < arr[j]){j--;}

        if(i >= j) break;
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    if(primero < i - 1){quickSort(arr, primero, i-1);}
    if(j + 1 < ultimo){quickSort(arr, j + 1, ultimo);}
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}