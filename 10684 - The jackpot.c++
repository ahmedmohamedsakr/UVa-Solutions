#include <bits/stdc++.h>

using namespace std;
const int N = 1e4+5, M = 1e4, OO = 0x3f3f3f3f;
int n,sum,ans,val;

int main()
{
    while(~scanf("%d",&n)&&n){

        sum=ans=0;
        for(int i=0;i<n;++i){
            scanf("%d",&val);
            sum+=val;
            ans=max(ans,sum);
            if(sum<0)sum=0;
        }

        if(ans)printf("The maximum winning streak is %d.\n",ans);
        else puts("Losing streak.");
    }


    return 0;
}
