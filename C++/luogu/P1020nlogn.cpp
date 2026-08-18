#include<bits/stdc++.h>
using namespace std;
vector<int> num;int l;

int LIS(){
    vector<int> dp;
    for(int i=0;i<l;i++){
        auto it=lower_bound(dp.begin(),dp.end(),num[i]);
        if(it==dp.end())
            dp.push_back(num[i]);
        else
            *it=num[i];
    }
    return dp.size();
}
int LDS(){
    vector<int> dp;
    for(int i=0;i<l;i++){
        int x=-num[i];
    auto it=upper_bound(dp.begin(),dp.end(),x);
        if(it==dp.end())
            dp.push_back(x);
        else
            *it=x;
    }
    return dp.size();
}

int main(){
    int x;
    while(cin>>x){
        num.push_back(x);
    }
    l=num.size();
    cout<<LDS()<<"\n"<<LIS();
}