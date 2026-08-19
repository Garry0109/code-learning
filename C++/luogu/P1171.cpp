#include <bits/stdc++.h>
using namespace std;
const int N=21;const int M=1e8;
int n ;int dp[1<<N][N];int ans=M;int dist[N][N];

int solve(){
    for(int i=0;i<=(1<<(n))-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if((!(i&(1<<k)))&&(i&(1<<j))){
                    dp[i|1<<k][k]=min(dp[i|1<<k][k],dp[i][j]+dist[j][k]);
                }
            }
        }
    }
    for(int j=1;j<n;j++){
    ans=min(dp[(1<<(n))-1][j]+dist[j][0],ans);
    }
    return ans;
}



int main(){
    cin>>n;
    fill(&dp[0][0], &dp[0][0]+(1<<N)*N, M);
    dp[1][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin>>dist[i][j];
    }
    cout<<solve();
}