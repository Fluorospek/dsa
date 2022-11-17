#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *, int);
void selection_sort(int *, int);
void mergesort(int *, int, int);
void merge(int *, int, int, int);
void quick_sort(int *, int, int);
int partition(int *, int, int);
void counting_sort(int *, int);
void radix_sort(int *, int);
void count_sort_for_radix(int *, int, int);

int main()
{
    int n, *arr;
    cout << "Enter number of values to be entered: " << endl;
    cin >> n;
    arr = new int[n];
    cout << "Enter values" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // insertion_sort(arr, n);
    // selection_sort(arr, n);
    // mergesort(arr, 0, n - 1);
    // quick_sort(arr, 0, n - 1);
    // counting_sort(arr, n);
    radix_sort(arr, n);
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

void insertion_sort(int *arr, int n)
{
    int key, j;
    for (int step = 1; step < n; step++)
    {
        int key = arr[step];
        int j = step - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return;
}

void selection_sort(int *arr, int n)
{
    for (int step = 0; step < n; step++)
    {
        int min = step;
        for (int i = step; i < n; i++)
        {
            if (arr[min] > arr[i])
                min = i;
        }
        if (min != step)
        {
            int temp = arr[min];
            arr[min] = arr[step];
            arr[step] = temp;
        }
    }
}

void mergesort(int *arr, int a, int c)
{
    if (a < c)
    {
        int b = a + ((c - a) / 2);
        mergesort(arr, a, b);
        mergesort(arr, b + 1, c);
        merge(arr, a, b, c);
    }
}

void merge(int *arr, int a, int b, int c)
{
    int n1 = b - a + 1;
    int n2 = c - b;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[a + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = arr[b + 1 + i];

    int i = 0, j = 0, k = a;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
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