#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int N =1e4+1,M=1e9,OO = 0x3f3f3f3f;
ll b,p,m,res;

ll power()
{
    res=1;
    while(p)
    {
        if(p&1)res=((res%m)*(b%m))%m;
        b=((b%m)*(b%m))%m;
        p>>=1;
    }
    return res;
}

int main()
{
    while(scanf("%lld%lld%lld",&b,&p,&m)==3)
        printf("%lld\n",power());

    return 0;
}
