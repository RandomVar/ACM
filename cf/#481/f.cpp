#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2*1e5+100;
struct node{
  int id;int s;
  bool operator<(const node&b)const{
  return s<b.s;
  }
}a[maxn];
int q[maxn];
int ans[maxn];
int main(){
   int n,k;
   while(cin>>n>>k){
       memset(q,0,sizeof(q));
   for(int i=1;i<=n;i++){
    cin>>a[i].s;a[i].id=i;
   }
   for(int i=0;i<k;i++){
    int x,y;
    cin>>x>>y;
    if(a[x].s>a[y].s) q[x]++;
    if(a[y].s>a[x].s) q[y]++;
       }

    sort(a+1,a+1+n);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i>1&&a[i].s==a[i-1].s) cnt++;
        else cnt=0;
        ans[a[i].id]=i-1-cnt-q[a[i].id];

    }
    for(int i=1;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<ans[n]<<endl;
   }



}
