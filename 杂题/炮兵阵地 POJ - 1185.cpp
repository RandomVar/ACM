#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=70;
const int maxm=110;
int dp[maxm][70][70];
string s[maxm];
int vst[70],num[70];
int sta[maxm];
int vnum,m;
int getnum(int i){
  int res=0;
 while(i){
    if(i%2) res++;
    i/=2;

 }
return res;
}


void init(){
  vnum=0;
  for(int i=0;i<(1<<m);i++){
     if(!(i&(i<<1))&&!(i&(i<<2)))
     {
         vst[vnum]=i;//这里其实是一个hash的操作
         num[vnum++]=getnum(i);//左右不相邻条件
     }
  }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n>>m){
    mem(sta,0);
     for(int i=0;i<n;i++)
        cin>>s[i];
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(s[i][j]=='H')
            sta[i]|=(1<<j);//平地条件
        }
       }
        mem(dp,-1);
        init();
        for(int i=0;i<vnum;i++){
            if(!(vst[i]&sta[0]))//同时符合两个条件
              dp[0][i][0]=num[i];

        }
       for(int i=1;i<n;i++)
         for(int j=0;j<vnum;j++){
           if(vst[j]&sta[i])
             continue;
            for(int k=0;k<vnum;k++){
                if(vst[k]&sta[i-1])
                      continue;
                if(vst[j]&vst[k])
                      continue;
                for(int t=0;t<vnum;t++)
                {

                    if(vst[t]&vst[j])
                         continue;
                    if(dp[i-1][k][t]==-1)
                         continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][t]+num[j]);
            }

            }
       }
       int ans=0;
       for(int j=0;j<vnum;j++)
         for(int k=0;k<vnum;k++)
             ans=max(ans,dp[n-1][j][k]);
           cout<<ans<<endl;
     }
  }

