#include <bits/stdc++.h>
using namespace std;
int N;int dp[201][201],dp_Max[201][201],dp_Min[201][201];int sum[201];
const int M=1e8;
int ans_Max=0;int ans_Min=M;

void solve(){
    for(int i=1;i<=2*N;i++){
        sum[i]=sum[i-1]+dp[i][i];
    }
}
int solve_Max(){
    int len;
    for(len=2;len<=N;len++){
        for(int i=1;i+len-1<=2*N;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                dp_Max[i][j]=max(dp_Max[i][j],dp_Max[i][k]+dp_Max[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    for(int i=1;i<=N;i++){
    ans_Max=max(ans_Max,dp_Max[i][i+N-1]);
    }
    return ans_Max;
}


int solve_Min(){
    int len;
    for(len=2;len<=N;len++){
        for(int i=1;i+len-1<=2*N;i++){
            int j=i+len-1;
            dp_Min[i][j]=M;
            for(int k=i;k<j;k++){
                dp_Min[i][j]=min(dp_Min[i][j],dp_Min[i][k]+dp_Min[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    for(int i=1;i<=N;i++){
    ans_Min=min(ans_Min,dp_Min[i][i+N-1]);
    }
    return ans_Min;
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>dp[i][i];
    }
    for(int i=N+1;i<=2*N;i++){
        dp[i][i]=dp[i-N][i-N];
    }
    solve();
    cout<<solve_Min()<<"\n"<<solve_Max();
    return 0;
}
