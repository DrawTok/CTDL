#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

using namespace std;

int main()

{
    ofstream ofs("data.txt");
    srand((int)time(0));
    int r;
    for (int i = 0; i < 1000; ++i)
    {
        r = random(1, 1000);
        ofs << r << " ";
    }
    ofs.close();

    ifstream ifs("data.txt");
    int arr[1000], i = 0;
    while (!ifs.eof())
    {
        if (ifs)
        {
            ifs >> arr[i];
        }
        i++;
    }

    for (int i = 0; i < 1000; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}