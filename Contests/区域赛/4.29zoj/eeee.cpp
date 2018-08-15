#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int f[100010];
vector<int>vec[100010];
int a[100010];
int pre[100010];
int main(){
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  scanf("%d",&t);
  //cin>>t;
  while(t--){
    int n;int m=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        m=max(m,f[i]);
        }
        for(int i=1;i<=n;i++){
            int t;
         scanf("%d%d",&t,&a[i]);
        }
        mem(pre);
      for(int i=0;i<=m;i++)
        vec[i].clear();
      for(int i=1;i<=n;i++){
        vec[f[i]].pb(i);
        int len=vec[f[i]-1].size();
        if(len) pre[i]=vec[f[i]-1][len-1];
      }
      //int pre=INF;
      for(int i=m;i>=1;i--){
         int p=INF;
         int len=vec[i].size();
         for(int j=0;j<len;j++){
            int t=vec[i][j];
            //a[t]=min(a[t],pre-1);
            a[t]=min(a[t],p);
            p=a[t];
           if(pre[t]) a[pre[t]]=min(a[pre[t]],a[t]-1);
         }
         //pre=min(pre,p);
         //cout<<pre<<endl;
      }
  for(int i=1;i<n;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
  }
return 0;
}
