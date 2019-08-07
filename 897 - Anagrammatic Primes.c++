#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e7+5,M=1e8+5,OO=0x3f3f3f3f;
ll n,l,r,f,g,m,numOfDidit,last,p,i;
vector<ll>v;
ll isComp[N];
void sieve()
{
    isComp[0]=isComp[1]=1;
    for(ll i=2; i*i<=N; ++i)
        if(!isComp[i])for(ll j=i*i; j<=N; j+=i)isComp[j]=1;

    for(ll i=2; i<=N; ++i)if(!isComp[i])v.push_back(i);

}

int main()
{
    sieve();
    while(scanf("%lld",&n)==1&&n)
    {
        numOfDidit=floor((double)log10(n))+1;
        p=(ll)(pow(10,numOfDidit-1)+.5),l=upper_bound(v.begin(),v.end(),n)-v.begin(),r=(ll)(pow(10,numOfDidit)+.5);
        for(i=l,g=1; v[i]<r&&i<v.size(); ++i)
        {
            m=f=g=0;
            while(m!=v[i])
            {
                if(!f)m=v[i],f=1;
                last=m%10;
                m/=10;
                m+=last*p;
                if(isComp[m])
                {
                    g=1;
                    break;
                }
            }
            if(!g)break;
        }
        if(g)puts("0");
        else printf("%lld\n",v[i]);

    }
    return 0;
}
