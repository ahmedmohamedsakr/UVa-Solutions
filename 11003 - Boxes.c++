#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5, M = 3e3 + 5, OO = 0x3f3f3f3f;
int t, n, ans, p[N], w[N];
int mem[N][M];
int solve(int i, int rem)
{
    if (rem<0)return -OO;
    if (i == n)return 0;
    int & ret = mem[i][rem];
    if (~ret)return ret;
    ret = solve(i + 1, rem);
    ret = max(ret, solve(i + 1, min(p[i],rem - w[i])) + 1);
    return ret;
}
void init()
{
    memset(mem, -1, sizeof mem);
    memset(w, 0, sizeof w);
    memset(p, 0, sizeof p);
    ans = 0;
}
int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (!n)break;
        init();
        for (int i = 0; i<n; ++i)scanf("%d%d", w + i, p + i);
        for (int i = 1; i<=n; ++i)
        {

            ans = max(ans, solve(i, p[i - 1]));
        }
        printf("%d\n", ++ans);
    }
    return 0;
}
