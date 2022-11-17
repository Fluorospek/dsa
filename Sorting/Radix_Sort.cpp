#include <bits/stdc++.h>
using namespace std;

void count_sort_for_radix(int *arr, int size, int place)
{
    int output[size];
    int max = (arr[0] / place) % 10;
    for (int i = 0; i < size; i++)
    {
        if (max < (arr[i] / place) % 10)
            max = (arr[i] / place) % 10;
    }
    int *count = new int[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[(arr[i] / place) % 10]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radix_sort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    for (int place = 1; (max / place) > 0; place *= 10)
    {
        count_sort_for_radix(arr, n, place);
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
    radix_sort(arr, n);
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}