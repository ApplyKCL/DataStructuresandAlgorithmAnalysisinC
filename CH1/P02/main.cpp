#define DATAFILE "data"
#define DIRFILE "dir"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define POSITIVE_X 0
#define POSITIVE_X_Y 1
#define POSITIVE_Y 2
#define NEGATIVE_X_Y 3
#define NEGATIVE_X 4
#define NEGATIVE_X_NEGATIVE_Y 5
#define NEGATIVE_Y 6
#define POSITIVE_X_NEGATIVE_Y 7

using namespace std;

typedef struct {
    unsigned int row;
    unsigned int col;
    unsigned int maxRow;
    unsigned int maxCol;
    int dir;
} Position;

int wordSearch(vector<string> data, vector<string> words);
int findWord(vector<string> data, vector<string> words, Position p);
int findWordRcu(vector<string> data, string word, Position p);

const int dirX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dirY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int findWord(vector<string> data, vector<string> words, Position p)
{
    for (int i = 0; i < p.maxCol*p.maxRow; i++)
    {
        p.col = i%p.maxCol;
        p.row = i/p.maxCol;
        for (auto & word : words)
        {
            if (data[p.row][p.col] == word[0])
            {
                p.dir = POSITIVE_X;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
                p.dir = NEGATIVE_X;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
                p.dir = POSITIVE_Y;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
                p.dir = NEGATIVE_Y;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
                p.dir = POSITIVE_X_Y;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
                p.dir = NEGATIVE_X_Y;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
                p.dir = POSITIVE_X_NEGATIVE_Y;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
                p.dir = NEGATIVE_X_NEGATIVE_Y;
                findWordRcu(data, word, p) == 0 ? cout << "Word found: " << word << endl : cout << "";
            }
        }
    }

    return -1;
}

int findWordRcu(vector<string> data, string word, Position p)
{
    if (word[0] == '\0')
    {
        return 0;
    }
    if (p.row >= p.maxRow || p.col >= p.maxCol)
    {
        return -1;
    }
    if (data[p.row][p.col] == word[0])
    {
        //cout << data[p.row][p.col]<< " Context: ("<<p.row<<","<<p.col<<") "<<"DIR: "<<p.dir<<endl;
        p.col = p.col + dirX[p.dir];
        p.row = p.row + dirY[p.dir];
        return findWordRcu(data, word.substr(1), p);
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
    }
    dirFile.close();
    Position p;
    p.row = 0;
    p.col = 0;
    p.maxRow = row;
    p.maxCol = data[0].size();
    p.dir = 0;

    findWord(data, dir, p);

    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.