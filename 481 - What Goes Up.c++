#include <iostream>
#include <vector>
using namespace std;


void LIS(vector<int>&v){
    vector<int>seq(v.size(),0);
    vector<int>parent(v.size(),0);
    int len=0;

    for(int i=0;i<v.size();++i){
        int lo = 1, mid, hi = len;
        while(lo<=hi){               //implementing lower_bound() using binary search.
            mid = (lo+hi)>>1;
            if(v[seq[mid]]>=v[i])  hi = mid-1;
            else  lo = mid+1;
        }
        parent[i]=seq[lo-1];       
        seq[lo]=i;
        if(lo>len)len=lo;
    }

     printf("%d\n-\n",len);
     int idx=seq[len];
     vector<int>lis(len);
     for(int i=len-1;i>=0;--i){
         lis[i]=v[idx];
         idx=parent[idx];
     }
     for(int i=0;i<len;++i)cout<<lis[i]<<endl;
}

int main() {
    int n;
    vector<int>a;
    while(scanf("%d",&n)!=EOF){
        a.push_back(n);
    }
    LIS(a);
    return 0;
}
