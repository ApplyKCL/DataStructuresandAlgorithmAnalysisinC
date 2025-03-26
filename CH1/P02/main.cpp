#define DATAFILE "data"
#define DIRFILE "dir"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    ifstream dataFile;
    dataFile.open(DATAFILE);
    if (!dataFile.is_open())
    {
        cout << "File could not be opened" << endl;
    }

    ifstream dirFile;
    dirFile.open(DIRFILE);
    if (!dirFile.is_open())
    {
        cout << "File could not be opened" << endl;
    }
    unsigned int row = 0;
    unsigned int col = 0;
    string line = "";
    vector <string> data;
    while (getline(dataFile, line))
    {
        line.erase(ranges::remove(line, ' ').begin(), line.end());
        data.push_back(line);
        row++;
    }
    dataFile.close();

    vector <string> dir;
    while (getline(dirFile, line))
    {
        line.erase(ranges::remove(line, ' ').begin(), line.end());
        dir.push_back(line);
        col++;
    }
    dirFile.close();



    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.