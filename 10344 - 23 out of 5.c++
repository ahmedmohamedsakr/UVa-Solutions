#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20,M=15,OO=0x3f3f3f3f;
int a[5],c,f;

bool solve(int ans=a[0],int idx=1)
{
    if(idx==5)return ans==23;
    return solve(a[idx]+ans,idx+1)||
           solve(a[idx]*ans,idx+1)||
           solve(ans-a[idx],idx+1);
}
int main()
{
    while(true)
    {
        c=f=0;
        for(int i=0; i<5; ++i)
        {
            scanf("%d",a+i);
            if(!a[i])c++;
        }
        if(c==5)break;
        sort(a,a+5);
        do
        {
            f = solve();
            if(f)break;
        }
        while (next_permutation(a,a+5));

        if (f)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}
