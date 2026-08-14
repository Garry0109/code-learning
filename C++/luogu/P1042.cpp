#include<bits/stdc++.h>
using namespace std;

char c;
void writein(vector<char> &a){
    while(cin>>c&&c!='E'){
    a.push_back(c);
    }
}

void num_(vector<char> &a,int total){
int num_W=0,num_L=0;
    for(int i=0;i<(int)(a.size());i++){
        if(a[i]=='W'){
            num_W++;
        }
        else{
            num_L++;
        }
    if((num_W>=total||num_L>=total)&&abs(num_W-num_L)>=2){
        cout<<num_W<<":"<<num_L<<"\n";
        num_W=0,num_L=0;
    }
    }
    cout<<num_W<<":"<<num_L<<"\n";
    
}
int main(){
    vector<char> a;
    writein(a);
//    for(char x:a)
//    cout<<x;
    num_(a,11);
    cout<<"\n";
    num_(a,21);
}