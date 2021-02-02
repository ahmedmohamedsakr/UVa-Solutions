#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 4;
int mem[N][N], f;
string s;
vector<string> s1, s2;

int LCS(int i, int j)
{
    if (i == s1.size() || j == s2.size())
        return 0;
    int &ret = mem[i][j];
    if (~ret)
        return ret;
    if (s1[i] == s2[j])
        return ret = LCS(i + 1, j + 1) + 1;
    return ret = max(LCS(i + 1, j), LCS(i, j + 1));
}
void print(int i = 0, int j = 0)
{
    if (i == s1.size() || j == s2.size())
        return;
    int ret = LCS(i, j);
    if (ret == LCS(i + 1, j))
        print(i + 1, j);
    else if (ret == LCS(i, j + 1))
        print(i, j + 1);
    else
    {
        if (f)
            cout << " ";
        f = 1;
        cout << s1[i];
        print(i + 1, j + 1);
    }
}
void init()
{
    memset(mem, -1, sizeof mem);
    f = 0;
    s1.clear();
    s2.clear();
}
int main()
{

    while (cin >> s)
    {
        init();
        do
        {
            stringstream str(s);
            string word;
            while (str >> word)
            {
                s1.push_back(word);
            }
        } while (cin >> s && s != "#");

        while (cin >> s && s != "#")
        {
            string word;
            stringstream str(s);
            while (str >> word)
            {
                s2.push_back(word);
            }
        }
        print();
        puts("");
    }
}
