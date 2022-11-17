#include <bits/stdc++.h>
using namespace std;

void counting_sort(int *arr, int n)
{
    int max = arr[0];
    int output[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int *count_array = new int[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count_array[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count_array[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count_array[i] += count_array[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count_array[arr[i]] - 1] = arr[i];
        count_array[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
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
    counting_sort(arr, n);
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}