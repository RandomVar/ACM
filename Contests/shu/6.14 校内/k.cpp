#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
  int t;cin>>t;
  while(t--){
    string a;string b;
    cin>>a;
    cin>>b;
    int flag=1;int f1=-1;int f2=-1;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){ f1=i;break;}

    }
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[i]) {f2=i;break;}

    }
    if(f1==-1&&f2==-1) cout<<"YES"<<endl;
    else{
    for(int i=0;i<=f2-f1;i++){
        if(a[f1+i]!=b[f2-i]) {flag=0;break;}

    }
    if(flag==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }}

}
