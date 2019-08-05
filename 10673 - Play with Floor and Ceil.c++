#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+5,M=10,OO=0x3f3f3f3f;
ll t,x,k,p,q,d;


void extendedEuclid(ll a,ll b)
{
    if(b==0)
    {
        p=1,q=0,d=a;
        return;
    }
    extendedEuclid(b,a%b);
    ll temp=p;
    p=q;
    q=temp-a/b*q;
}
bool solve_LDE(ll a,ll b)
{
    extendedEuclid(a,b);
    ll m=x/d;
    p*=m;
    q*=m;
    return !(x%d);
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&x,&k);
        ll a=floor((double)x/k);
        ll b=ceil((double)x/k);
        solve_LDE(a,b);
        printf("%lld %lld\n",p,q);
    }


    return 0;
}
