#include<bits/stdc++.h>
using namespace std;
void insertionSort(string arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        string temp = arr[i];
        int j = i - 1;
        while(j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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
    string arr[] = {"John", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
