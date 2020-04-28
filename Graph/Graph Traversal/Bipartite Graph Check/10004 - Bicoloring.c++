#include <bits/stdc++.h>
using namespace std;
const int N=2e2+5,M=1e6+5,OO=0x3f3f3f3f;
int col[N],n,l,u,v;
vector<int>adj[N];

bool CheckBiPartite(int src=0)
{
    queue<int>q;
    q.push(src);
    col[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it:adj[u])
        {
            if(col[it]==OO)
            {
                col[it]=!col[u];
                q.push(it);
            }
            else if(col[it]==col[u])return 0;
        }
    }
    return 1;
}
void init()
{
    memset(col,OO,sizeof col);
    for(auto &it:adj)it.clear();
}
int main ()
{
    while(~scanf("%d",&n)&&n)
    {
        init();
        scanf("%d",&l);
        for(int i=0; i<l; ++i)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
        }
        puts(CheckBiPartite()?"BICOLORABLE.":"NOT BICOLORABLE.");
    }
    return 0;
}
