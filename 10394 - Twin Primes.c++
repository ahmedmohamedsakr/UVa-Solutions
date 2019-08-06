#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e7+5,M=1e8+5,OO=0x3f3f3f3f;
int s;
vector<int>v;
vector<pair<int,int> >vii;
int isComp[N];
void sieve()
{
    isComp[0]=isComp[1]=1;
    for(int i=2; i*i<=N; ++i)
        if(!isComp[i])for(int j=i*i; j<=N; j+=i)isComp[j]=1;

    for(int i=2; i<=N; ++i)if(!isComp[i])v.push_back(i);
    for(int i=1;i<v.size();++i)if(v[i]==v[i-1]+2)vii.push_back({v[i-1],v[i]});
}

int main()
{
    sieve();
    while(scanf("%d",&s)==1)printf("(%d, %d)\n",vii[s-1].first,vii[s-1].second);
    return 0;
}
