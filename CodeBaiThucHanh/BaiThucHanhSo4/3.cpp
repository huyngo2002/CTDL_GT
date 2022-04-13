#include<bits/stdc++.h>
using namespace std;
/* Hàm sắp xếp sử dụng thuật toán sắp xếp chèn */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Di chuyển các phần tử có giá trị lớn hơn giá trị
        key về sau một vị trí so với vị trí ban đầu
        của nó */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
