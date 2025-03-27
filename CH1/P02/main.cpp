#define DATAFILE "data"
#define DIRFILE "dir"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define HORIZONTAL 0
#define VERTICAL 1
#define OPPOSITEANG 2

using namespace std;

typedef struct {
    int row;
    int col;
    int maxRow;
    int maxCol;
    int dir;
} Position;

int wordSearch(vector<string> data, vector<string> words);
int findWord(vector<string> data, vector<string> words, Position p);
int findWordH(vector<string> data, string word, Position p);
int findWordV(vector<string> data, string word, Position p);
int findWordA(vector<string> data, string word, Position p);

int findWord(vector<string> data, vector<string> words, Position p)
{

    for (int i = 0; i < words.size(); i++)
    {
        if (data[p.row][p.col] == words[i][0])
        {
            if (findWordH(data, words[i], p) == 0)
            {
                return 0;
            }
            if (findWordV(data, words[i], p) == 0)
            {
                return 0;
            }
            if (findWordA(data, words[i], p) == 0)
            {
                return 0;
            }
        }else
        {
            p.col = p.col + 1;
            if (p.col == p.maxCol)
            {
                p.col = 0;
                p.row = p.row + 1;
            }
            if (p.row == p.maxRow)
            {
                return -1;
            }
        }
        findWord(data, words, p);
    }


}

int findWordH(vector<string> data, string word, Position p)
{
    if (word[0] == '\0')
    {
        return 0;
    }
    if (data[p.row][p.col] == word[0])
    {
        printf("%c", data[p.row][p.col]);
        p.col = p.col + 1;
        findWordH(data, &word[1], p);
    }
    return -1;
}

int findWordV(vector<string> data, string word, Position p)
{
    if (word[0] == '\0')
    {
        return 0;
    }
    if (data[p.row][p.col] == word[0])
    {
        printf("%c", data[p.row][p.col]);
        p.row = p.row + 1;
        findWordH(data, &word[1], p);
    }
    return -1;
}

int findWordA(vector<string> data, string word, Position p)
{
    if (word[0] == '\0')
    {
        return 0;
    }
    if (data[p.row][p.col] == word[0])
    {
        printf("%c", data[p.row][p.col]);
        p.row = p.row + 1;
        p.col = p.col + 1;
        findWordH(data, &word[1], p);
    }
    return -1;

}


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