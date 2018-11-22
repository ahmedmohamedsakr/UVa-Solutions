#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4,M=10,OO=0x3f3f3f3f;
int t,n,h;
void solve(string s="",int c=0,int idx=0){
        if(idx==n){
            if(c==h)cout<<s<<endl;
            return;
        }
        solve(s+'0',c,idx+1);
        solve(s+'1',c+1,idx+1);
}

int main()
{
   scanf("%d",&t);
   while(t--){
       scanf("%d%d",&n,&h);
       solve();
       if(t)puts("");
   }
    return 0;
}
