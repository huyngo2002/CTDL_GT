#include<bits/stdc++.h>
using namespace std;
void selectionSort(string arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int m = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[m] > arr[j])
                m = j;
        }
        string temp = arr[m];
        arr[m] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
