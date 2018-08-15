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


int dp[30][30*40];
int d[250];
int p[250];
int c[250];
vector<int>co;
/*
int checkpath(int p,int q,int k){
  if(dp[i-1][])
}*/
int main(){
  int n,m;int cas=0;
  while(cin>>n>>m&&m&&n){
    for(int i=1;i<=n;i++){
        cin>>p[i]>>d[i];
        c[i]=p[i]-d[i];
    }
    co.clear();
    memset(dp,-1,sizeof(dp));
    //for(int i=0;i<=20*m*2;i++)
    dp[0][20*m]=0;
    for(int i=1;i<=m;i++){
        for(int k=1;k<=n;k++)
         for(int j=c[k];j<=20*m*2;j++)
             if(dp[i-1][j-c[k]]!=-1)
               dp[i][j]=max(dp[i][j],dp[i-1][j-c[k]]+d[k]+p[k]);
    }
    int ans=40*m;
    int maxa=-1;
    for(int i=0;i<=20*m;i+=1)
    {

        if(dp[m][i+20*m]!=-1){
            ans=i+20*m;
            maxa=dp[m][i+20*m];
        }
        if(dp[m][20*m-i]>maxa){
            ans=20*m-i;
            maxa=dp[m][20*m-i];
        }
        if(maxa!=-1) break;
    }
    //cout<<ans<<endl;
    int sumd=0,sump=0;
    int key=ans;
    int sum=maxa;
    for(int i=m-1;i>=0;i--){
        for(int k=1;k<=n;k++)
             if(dp[i][key-c[k]]==sum-d[k]-p[k]){
                    co.push_back(k);
                    sum-=d[k]+p[k];
                    key-=c[k];
                    sumd+=d[k];
                    sump+=p[k];
             }
    }
    cout<<"Jury #"<<++cas<<endl;
    cout<<"Best jury has value "<<sump<<" for prosecution and value "<<sumd<<" for defence:"<<endl;
    sort(co.begin(),co.end());
    for(int i=0;i<co.size();i++)
        cout<<" "<<co[i];
    cout<<endl<<endl;
  }
}
