#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, hash[10] = { 0 };
    for (i = 0; i < n; i++)
        hash[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        hash[i] += hash[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[hash[(arr[i] / exp) % 10] - 1] = arr[i];
        hash[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 

int main()
{
    int arr[] = { 0,500,0,234 };
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}