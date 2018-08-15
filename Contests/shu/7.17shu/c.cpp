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
const int maxn=1e5+100;
int n,cnt;
int root[maxn],a[maxn];
int x,y,k;
struct node{
  int l,r,sum;
}T[maxn*40];


void update(int l,int r,int &x,int y,int pos){
  T[++cnt]=T[y];
  T[cnt].sum++;
  x=cnt;
  if(l==r) return ;
  int mid=(l+r)/2;
  if(mid>=pos) update(l,mid,T[x].l,T[y].l,pos);
  else update(mid+1,r,T[x].r,T[y].r,pos);

}

int query(int l,int r,int x,int y,int k){
  if(l==r) return l;
  int mid=(l+r)/2;
  int sum=T[T[y].l].sum-T[T[x].l].sum;
  if(sum>=k) return query(l,mid,T[x].l,T[y].l,k);
  else return query(mid+1,r,T[x].r,T[y].r,k-sum);

}

int solve(int l,int r)
{
  int daan=0;
  int low=0;int high=r-l+1;
  while(low<=high)
  {
    int mid=(low+high)/2;
    int ans=query(1,n,root[l-1],root[r],r-l+1-mid+1);
    //cout<<ans<<" "<<mid<<endl;
    if(ans>=mid)
    {
      daan=mid;
        low=mid+1;
    }
    else high=mid-1;
  }
  return daan;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int q;
   while(cin>>n>>q)
   {
      cnt=0;
       for(int i=1;i<=n;i++)
       
         cin>>a[i];
       
        for(int i=1;i<=n;i++)
         update(1,n,root[i],root[i-1],a[i]);
         for(int i=1;i<=q;i++)
         {
             int l,r;
             cin>>l>>r;
            cout<<solve(l,r)<<endl;
         }
   }

 return 0;
  }

