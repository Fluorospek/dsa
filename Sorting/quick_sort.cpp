#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int a, int b)
{
    int pivot = arr[b];
    int i = a - 1;
    int j = a;
    while (j < b)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[b];
    arr[b] = temp;
    return i + 1;
}

void quick_sort(int *arr, int a, int b)
{
    if (a < b)
    {
        int pi = partition(arr, a, b);
        quick_sort(arr, a, pi - 1);
        quick_sort(arr, pi + 1, b);
    }
}

int main()
{
    int n, *arr;
    cout << "Enter number of values to be entered: " << endl;
    cin >> n;
    arr = new int[n];
    cout << "Enter values" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}
