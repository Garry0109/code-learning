#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;const int NN=1e7+5;
int t[N];int v[N];long long dp[NN];
int T;int M;

void solve(){
    for(int i=1;i<=M;i++){
        for(int j=t[i];j<=T;j++){
            dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
        }
    }
}

int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++){
        cin>>t[i]>>v[i];
    }
    solve();
    cout<<dp[T];
}