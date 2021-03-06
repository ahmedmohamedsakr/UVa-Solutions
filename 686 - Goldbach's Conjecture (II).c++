#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=(1<<15)+5,M=1e8+5,OO=0x3f3f3f3f;
ll n,l,r,sum,cnt;
vector<ll>v;
ll isComp[N];
void sieve()
{
    isComp[0]=isComp[1]=1;
    for(ll i=2; i*i<=N; ++i)
        if(!isComp[i])for(ll j=i*i; j<=N; j+=i)isComp[j]=1;

        for(ll i=2;i<=N;++i)if(!isComp[i])v.push_back(i);
}

int main()
{
    sieve();
    while(scanf("%lld",&n)==1&&n)
    {
        cnt=0,l=0,r=upper_bound(v.begin(),v.end(),n)-v.begin();
        while(l<=r)
        {
            sum=v[l]+v[r];
            if(sum>n)--r;
            else if(sum<n)++l;
            else cnt++,++l,--r;
        }
        printf("%lld\n",cnt);
    }

    return 0;
}
