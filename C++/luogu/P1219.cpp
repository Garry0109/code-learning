#include <bits/stdc++.h>
using namespace std;

int n;
bool col[40];
bool dg[40];
bool udg[40];
int ans[20];

int cnt=0;



void judge(int row){
    if(row==n+1){
    cnt++;
        if(cnt<=3){
        for(int j=1;j<=n;j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
        return;
    }
    for(int i=1;i<=n;i++){

        if(col[i]==true)
        continue;
        if(udg[i+row]==true)
        continue;
        if(dg[i-row+n]==true)
        continue;

        ans[row]=i;
        col[i]=true;
        dg[i-row+n]=true;
        udg[i+row]=true;

        judge(row+1);

        col[i]=false;
        dg[i-row+n]=false;
        udg[i+row]=false;

    }

}

int main(){
    cin>>n;
    judge(1);
    cout<<cnt;
}