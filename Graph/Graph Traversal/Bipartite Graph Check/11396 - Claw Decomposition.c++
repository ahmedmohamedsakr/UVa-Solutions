#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N=3e2+5,M=1e6+5,OO=0x3f3f3f3f;
int a,b,v;
vi adj[N];

bool checkBiPartite(int src=1)
{
    queue<int>q;
    vi color(N,OO);
    color[src]=0;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it:adj[u])
        {
            if(color[it]==OO)
            {
                color[it]=1-color[u];
                q.push(it);
            }
            else if(color[it]==color[u])return 0;
        }
    }
    return 1;
}

int main ()
{
    while(~scanf("%d",&v))
    {
        if(!v)break;
        for(auto &it:adj)it.clear();
        while(~scanf("%d%d",&a,&b))
        {
            if(!a&&!b)break;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        puts(checkBiPartite()?"YES":"NO");
    }
    return 0;
}
