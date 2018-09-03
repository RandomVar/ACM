#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-6;
typedef pair<int,int>line;
line lines[1010];
int cnt[1010];
int vis[1010];
int n,m,xa,ya,xb,yb;
bool check(int x,int y,line l){
  if(x<min(l.first,l.second)) return 0;
  double xline=(double)(l.first-l.second)/(ya-yb)*(y-ya)+l.first;
  //cout<<xline<<endl;
  if(xline<=x) return 1;
  else return 0;
}
int cmp(line a,line b){
return a.first<b.first;
}
int main(){
   while(cin>>n){
    if(n==0) break;
   else cin>>m>>xa>>ya>>xb>>yb;
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
      lines[0]=line(xa,xa);
      for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        lines[i]=line(a,b);
      }
      lines[n+1]=line(xb,xb);
      sort(lines,lines+n+2,cmp);
      for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int left=0;int right=n+1;
        while(left<=right){
            int mid=(left+right)/2;
            if(check(x,y,lines[mid])){
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        cnt[left-1]++;
       // cout<<left<<endl;
      }
     // for(int i=1;i<=n;i++)
       // cout<<i<<": "<<cnt[i]<<endl;
      cout<<"Box"<<endl;
      for(int i=0;i<=n;i++){
         if(cnt[i]) vis[cnt[i]]++;
      }
     for(int i=1;i<=m;i++){
         if(vis[i]) cout<<i<<": "<<vis[i]<<endl;
      }
   }
}
