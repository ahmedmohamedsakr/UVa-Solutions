#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,OO=0x3f3f3f3f;
int n,m;
vector<pair<int, int> >f;
void factorize1(int n)
{
    for(long long i = 2 ; i*i <= n ; ++i)
    {
        int power = 0;
        while(n%i==0)
        {
            n/=i;
            ++power;
        }
        if(power) f.push_back({i, power});
    }
    if(n > 1)f.push_back({n, 1});
}

int get_powers(int n, int p)
{
    int res = 0;
    int a=n;
    while(a)
    {
        res+=a/p;
        a/=p;
    }
    return res;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        f.clear();
        factorize1(m);
        bool y=(m!=0);
        for(auto it:f)
        {
            int ans=get_powers(n,it.first);
            if(ans<it.second)
            {
                y=0;
                break;
            }
        }
        if(y||m<=n)printf("%d divides %d!\n",m,n);
        else printf("%d does not divide %d!\n",m,n);
    }
    return 0;
}
