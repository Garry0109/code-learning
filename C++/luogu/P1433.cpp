#include <bits/stdc++.h>
using namespace std;

double ans=1e9;
int n;
bool judge[15];
struct point
{
    public:
    double x,y;
    double operator-(const point &rhs)const{
    return sqrt((x-rhs.x)*(x-rhs.x)+(y-rhs.y)*(y-rhs.y));
}
};

point a[15];
void solve(int now,int cnt,double length){
    if(cnt==n){
        ans=min(ans,length);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!judge[i]){
            judge[i]=true;
            solve(i,cnt+1,length+(a[i]-a[now]));
            judge[i]=false;
        }
    }
}



int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    a[0].x=0;a[0].y=0;
    solve(0,0,0);
    printf("%.2f",ans);
}
