#include<bits/stdc++.h>
#define ll long long
using namespace std;
int com(vector<char>a,vector<char>b){
 if(a.size()!=b.size()) return 0;
 for(int i=0;i<a.size();i++)
    if(a[i]!=b[i]) return 0;
 return 1;
}
int main(){
 string s;int cnt=0;
 while(cin>>s){
        cnt++;
       vector<char>x[1010];
     int k=0;int flag=0;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
           x[k].push_back(s[i]); flag=1;}
        else {
            if(flag) {k++;flag=0;}
        }
        if(i==s.size()-1&&((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))
            k++;
    }
    for(int i=0;i<k;i++)
    for(int j=i+1;j<k;j++){
        if(com(x[i],x[j])) x[j].clear();
    }
    int fi=0;
    cout<<"Case "<<cnt<<':'<<endl;
    for(int i=0;i<k;i++){
        if(!x[i].empty()){
                fi=1;
            for(int j=0;j<x[i].size();j++)
                cout<<x[i][j];
            cout<<endl;
        }
    }
    if(!fi) cout<<"NO"<<endl;
 }
}
