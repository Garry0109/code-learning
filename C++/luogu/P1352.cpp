#include <bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;vector<int> son[N];int fat[N];int dp[N][2];int v[N];

void dfs(int i){
    dp[i][0]=0;
    dp[i][1]=v[i];
    for(int child:son[i]){
        dfs(child);
        dp[i][0]+=max(dp[child][0],dp[child][1]);
        dp[i][1]+=dp[child][0];
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        son[y].push_back(x);
        fat[x]=y;
    }

    int root;
    for(int i=1;i<=n;i++){
        if(fat[i]==0)
        root=i;
    }
    dfs(root);
    int ans=max(dp[root][0],dp[root][1]);
    cout<<ans;
}