#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
struct node{
   ll p,c,ans;int id;
}a[maxn];
bool cmp1(node &x,node &y){

 return x.p<y.p;
}
bool cmp2(node &x,node &y){

return x.id<y.id;
}
//priority_queue<ll>que;
//
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,k;
  while(cin>>n>>k){
      for(int i=1;i<=n;i++){
        cin>>a[i].p;
        a[i].id=i;
      }
      for(int i=1;i<=n;i++)
        cin>>a[i].c;
      sort(a+1,a+1+n,cmp1);
      ll ans=0;
    priority_queue<ll,vector<ll>,greater<ll> >que;
      for(int i=1;i<=k+1;i++){
        ans+=a[i].c;
        a[i].ans=ans;
        que.push(a[i].c);
      }
      for(int i=k+2;i<=n;i++){
           ans+=a[i].c;

           ans-=que.top();
           a[i].ans=ans;
           que.pop();
           que.push(a[i].c);
      }
      sort(a+1,a+1+n,cmp2);
      for(int i=1;i<n;i++)
        cout<<a[i].ans<<" ";
      cout<<a[n].ans<<endl;
  }

}
