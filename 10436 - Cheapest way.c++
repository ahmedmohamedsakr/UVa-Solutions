#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int N = 25,M=1e4+4, OO = 0x3f3f3f3f;
int n,n_s,n_p,c,tc,dis[N],par[N],cost,cnt;
float total;
char s1[M],s2[M];
map<string,ii>mp;
vector<ii>adj[N];
vector<string>v;
void printpath(int u)
{
    if(par[u]==u)
    {
        cout<<v[u-1];
        cost+=mp[v[u-1]].second;
        return;
    }
    printpath(par[u]);
    cost+=mp[v[u-1]].second;
    cout<<" "<<v[u-1];
}

void Dijkstra(int src)
{
    memset(dis,OO,sizeof dis);
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    pq.push({0,src});
    dis[src]=0;
    par[src]=src;
    while(!pq.empty())
    {
        int c=pq.top().first,u=pq.top().second;
        pq.pop();
        if(dis[u]<c)continue;
        for(auto it:adj[u])
        {
            if(c+it.first<dis[it.second])
            {
                dis[it.second]=c+it.first;
                par[it.second]=u;
                pq.push({dis[it.second],it.second});
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
    {
        cnt=0;
        v.clear();
        scanf("%d",&n_s);
        for(int i=1; i<=n_s; ++i)
        {
            scanf("%s%d",s1,&c);
            mp[s1]= {i,c};
            adj[i].clear();
            v.push_back(s1);
        }
        scanf("%d",&n_p);
        for(int i=0; i<n_p; ++i)
        {
            scanf("%s%s%d",s1,s2,&c);
            c<<=1;
            adj[mp[s1].first].push_back({c,mp[s2].first});
            adj[mp[s2].first].push_back({c,mp[s1].first});
        }
        scanf("%d",&tc);
        printf("Map #%d\n",k);
        while(tc--)
        {
            cost=0;
            scanf("%s%s%d",s1,s2,&c);
            printf("Query #%d\n",++cnt);
            Dijkstra(mp[s1].first);
            printpath(mp[s2].first);
            total=cost+dis[mp[s2].first];
            printf("\nEach passenger has to pay : %.2f taka\n",float((total+(.1*total)))/c);
        }
        if(k!=n)puts("");
    }
    return 0;
}
