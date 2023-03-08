#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int size)
{
    int key, i, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, size);
    auto stop = high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}