#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e8+5,OO=0x3f3f3f3f;
int m,n;
vector<int>v;
int isComp[N];
void sieve()
{
    isComp[0]=isComp[1]=1;
    for(int i=2; i*i<=N; ++i)
        if(!isComp[i])for(int j=i*i; j<=N; j+=i)isComp[j]=1;

    for(int i=2; i<=N; ++i)if(!isComp[i])v.push_back(i);
}

int main()
{
    sieve();
    scanf("%d",&m);
    while(m--){
       scanf("%d",&n);
       printf("%d\n",*lower_bound(v.begin(),v.end(),n/2+1));
    }
    return 0;
}
