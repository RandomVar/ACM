#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1e5+10;
int cnt[500];
int a[maxn];
int main(){
  int n,k;
  while(cin>>n>>k){
        for(int i=0;i<500;i++)
          cnt[i]=-1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        if(cnt[a[i]]==-1){
                int flag=0;
            for(int j=a[i]-1;j>=0&&j>=a[i]-k+1;j--)
              if(cnt[j]!=-1) {
                 if(a[i]-cnt[j]<k) {
                     for(int s=j+1;s<=a[i];s++)
                         cnt[s]=cnt[j];
                     }
                 else {
                     for(int s=j+1;s<=a[i];s++)
                        cnt[s]=j+1;
                 }
                    flag=1;
                 break;
            }
            if(flag==0) {
                    int t=max(0,a[i]-k+1);
                for(int j=t;j<=a[i];j++)
                    cnt[j]=t;
        }}
      if(i<n-1) cout<<cnt[a[i]]<<" ";
      else cout<<cnt[a[i]]<<endl;
     }
   /* for(int i=0;i<n;i++){
        if(cnt[a[i]]==-1) {
                int res=k;
                int j=-1;
              for(j=a[i];j>=0&&cnt[j]==-1&&res;j--,res--);
              //if(a[i]==3) cout<<j<<cnt[j]<<endl;
              for(int s=j+1;s<=j+k&&cnt[s]==-1;s++)
                 cnt[s]=j+1;
//                 cout<<cnt[2]<<cnt[0]<<endl;
        }
        if(i!=n-1)cout<<cnt[a[i]]<<" ";
        else cout<<cnt[a[i]]<<endl;
    }*/

  }
return 0;
}
