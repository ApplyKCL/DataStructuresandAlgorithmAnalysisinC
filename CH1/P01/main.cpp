#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <random>
#include "sort.h"
using namespace std;

int main()
{
    string outfile = "data";
    ofstream fout;
    fout.open(outfile.c_str());
    if (!fout)
    {
        cout << "Error opening " << outfile << endl;
        return -1;
    }
    int N = 1000;
    fout << N << endl;
    for (int i = 0; i < N; i++)
    {
        fout << rand() % 1000 << " ";
    }
    fout.close();
    string infile = "data";
    ifstream fin;
    fin.open(infile.c_str());
    if (!fin)
    {
        cout << "Error opening " << infile << endl;
        return -1;
    }
    fin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        fin >> arr[i];
    }
    fin.close();
    Sort s(N, arr);
    s.initArray();
    time_t startTime = time(NULL);
    s.sortArray(N);
    time_t endTime = time(NULL);
    cout << "Time to sort " << N << " elements: " << endTime - startTime << " seconds" << endl;
    //s.printArray();
    s.initKArray();
    time_t startTime2 = time(NULL);
    s.sortKArray(N/2);


    //s.printKArray();
    s.popKArray();
    time_t endTime2 = time(NULL);
    cout << "Time to sort " << N/2 << " elements: " << endTime2 - startTime2 << " seconds" << endl;
    //s.printKArray();

    delete[] arr;
}
