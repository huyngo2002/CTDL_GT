#include<bits/stdc++.h>
using namespace std;
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
void heapify(string arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int langest = i;
    if (l < n && arr[l] > arr[langest])
        langest = l;
    if (r < n && arr[r] > arr[langest])
        langest = r;
    if (langest != i)
    {
        swap(arr[i], arr[langest]);
        heapify(arr, n, langest);
    }
}
void heapSort(string arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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
    string arr[] = {"John", "Cool", "Bee", "Try", "Thor", "Zil", "Adam"};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
