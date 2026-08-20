#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int V[N];int dp[N];int n;

void solve(){
    sort(V+1,V+n+1);
    for(int i=1;i<=n;i++){
        if(i>=V[i]){
            dp[i]=max(dp[i-1],dp[i-V[i]]+1);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>V[i];
    }
    solve();
    cout<<dp[n];

}