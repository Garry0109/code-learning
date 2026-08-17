#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int t[101];int v[101];int dp[N];
int T;int M;

void solve(){
    for(int i=1;i<=M;i++){
        for(int j=T;j>=t[i];j--){
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