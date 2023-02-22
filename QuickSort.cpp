#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

void QuickSort(int arr[], int a, int b)
{
    int peg = arr[(a + b) / 2]; // cọc
    int i = a, j = b;
    while (i < j)
    {
        while (arr[j] > peg)
        {
            j--;
        }
        while (arr[i] < peg)
        {
            i++;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (i < b)
    {
        QuickSort(arr, i, b);
    }

    if (a < j)
    {
        QuickSort(arr, a, j);
    }
}

int main()
{
    int size = 1000;
    ifstream ifs("data.txt");
    int arr[size], i = 0;
    while (!ifs.eof())
    {
        if (ifs)
        {
            ifs >> arr[i];
        }
        i++;
    }
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    QuickSort(arr, 0, size);
    auto stop = high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

    time_taken *= 1e-9;

    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}