#define DATAFILE "data"
#define DIRFILE "dir"

#include <iostream>
#include <fstream>


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

    while (dataFile>>line)
    {
        col = line.length();
        row++;
    }
    dataFile.close();
    printf("Rows: %u\n", row);
    printf("Cols: %u\n", col);


    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.