#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
int son[1010][1010];
int main(){
  int n;
  while(cin>>n){
        memset(son,0,sizeof(son));
    for(int i=2;i<=n;i++){
        int t;cin>>t;
        son[t][i]=1;
        for(int j=1;j<i;j++)
          if(son[j][t]) son[j][t]=-1;
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        int cnt=0;int biao=0;
        for(int j=i+1;j<=n;j++)
          if(son[i][j]==1) cnt++;
          else if(son[i][j]==-1) biao=1;
        if(cnt==0&&biao==0) continue;
        else if(cnt==0&&biao==1) {flag=1;break;}
        else if(cnt<3) {flag=1;break;}
    }
    //cout<<son[1][1]
    if(flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
}
