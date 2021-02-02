#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 4;
int mem[N][N];
int n, m, c, f;
vector<int> t1, t2;

int LCS(int i = 0, int j = 0)
{
    if (i == n || j == m)
        return 0;
    int &ret = mem[i][j];
    if (~ret)
        return ret;
    if (t1[i] == t2[j])
        return ret = LCS(i + 1, j + 1) + 1;
    return ret = max(LCS(i + 1, j), LCS(i, j + 1));
}
void init()
{
    memset(mem, -1, sizeof mem);
    t1.clear();
    t2.clear();
}
int main()
{
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;
        f = 1;
        int x;
        init();
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            t1.push_back({x});
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> x;
            t2.push_back({x});
        }
        cout << "Twin Towers #" << ++c << endl;
        cout << "Number of Tiles : " << LCS() << "\n\n";
    }
}
