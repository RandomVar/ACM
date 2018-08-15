#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
int main(){
 int t;
 cin>>t;
 while(t--){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int flag=0;
      int cnt=0;
    if(a>b) flag=1;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        int x;
        cin>>x;
        if(x<a||x>b) cnt++;
    }
    if(flag) cout<<"No Solution"<<endl;
    else cout<<cnt<<endl;

 }
 return 0;
}
