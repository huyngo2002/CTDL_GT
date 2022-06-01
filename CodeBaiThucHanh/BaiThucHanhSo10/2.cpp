#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = n - 1; j > i; j--)
            if(arr[j - 1] < arr[j]){
                int temp = arr[j - 1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {18, 73, 17, 56, 10, 86};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
