#include <bits/stdc++.h>
using namespace std;
vector<int> dp_LDS,dp_LIS,num;int ans_LIS,ans_LDS;int l;

void solve(){
    for(int i=0;i<l;i++){
        for(int j=0;j<i;j++){
            if(num[j]<num[i]){
                dp_LIS[i]=max(dp_LIS[i],dp_LIS[j]+1);
            }
            else{
                dp_LDS[i]=max(dp_LDS[i],dp_LDS[j]+1);
            }
        }
    }
    ans_LIS=*max_element(dp_LIS.begin(),dp_LIS.end());
    ans_LDS=*max_element(dp_LDS.begin(),dp_LDS.end());
}

int main(){
    int x;
    while(cin>>x){
        num.push_back(x);
        dp_LIS.push_back(1);
        dp_LDS.push_back(1);
    }
    l=dp_LIS.size();
    solve();
    cout<<ans_LDS<<"\n"<<ans_LIS;
}