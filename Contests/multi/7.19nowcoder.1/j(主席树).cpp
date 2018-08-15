/*
求[1,l],[r,n]区间内不同数的个数

拼接上一段相同的区间后变成一道模板题
*/
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
const int maxn=2*1e5+100;
int n,m,cnt;
int root[maxn],a[maxn];
int x,y,k;
map<int,int>mp;
struct node{
  int l,r,sum;
}T[maxn*40];
void init()
{
    cnt=0;
    mp.clear();
    root[0]=0;
    T[0].l = T[0].r = T[0].sum = 0;
}

void update(int l,int r,int &x,int y,int pos,int val){
  T[++cnt]=T[y];
  T[cnt].sum+=val;
  x=cnt;
  if(l==r) return ;
  int mid=(l+r)/2;
  if(mid>=pos) update(l,mid,T[x].l,T[y].l,pos,val);
  else update(mid+1,r,T[x].r,T[y].r,pos,val);

}

int query(int l,int r,int pos,int y){
  if(l==r) return T[y].sum;
  int mid=(l+r)/2;
  if(pos <= mid)
        return query(l,mid,pos,T[y].l) + T[T[y].r].sum;
  else 
      return query(mid+1,r,pos, T[y].r);
}

int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q;
    while(scanf("%d%d",&n,&q)==2)
    {
        init();
        for(int i=1;i<=n;i++)
          scanf("%d",&a[i]),a[i+n]=a[i];
         int m=n;
         n*=2;
         int tmp;
         for(int i=1;i<=n;i++){
           if(mp[a[i]]==0){
             update(1,n,root[i],root[i-1],i,1);
            mp[a[i]]=i;
           }
           else{
               update(1,n,tmp,root[i-1],mp[a[i]],-1);
               update(1,n,root[i],tmp,i,1);
                mp[a[i]]=i; 
         }
         }

        for(int i=1;i<=q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l+=m;
            printf("%d\n",query(1,n,r,root[l]));
        }
    }

 return 0;
  }

