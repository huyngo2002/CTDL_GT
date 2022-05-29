#include<bits/stdc++.h>
using namespace std;
void merge(string arr[], int low, int high, int mid)
{
    int i = low, j = mid + 1, k=0;
    string temp[high - low + 1];
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    for(i = low; i <= high; i++)
        arr[i] = temp[i - low];
    return;
}
void mergeSort(string arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
    return;
}
void printArray(string arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    string arr[] = {"John", "Cool", "Bee", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
