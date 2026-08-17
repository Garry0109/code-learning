#include<bits/stdc++.h>
using namespace std;

int r;int ans=0;
int dp[1001][1001];
void reduct(){
    for(int i=2;i<=r;i++){
        for(int j=1;j<=i;j++) {
            if(j==1){
                dp[i][j]+=dp[i-1][j];
            }
            else if(j==i){
                dp[i][j]+=dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j]+dp[i-1][j-1],dp[i][j]+dp[i-1][j]);
            }
        }
    }
    for(int i=1;i<=r;i++){
        ans=max(ans,dp[r][i]);
    }
}

int main(){
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++) {
            cin>>dp[i][j];
        }
    }
    reduct();
    cout<<ans;
}