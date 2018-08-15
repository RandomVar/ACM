/*
数列A初始为0，B为1-n的排列，有1e5次操作：
给数组A区间加1
查询区间内 ai/bi向下取整的值
n<=1e5


q/1+q/2+……+q/n 约等于 q*log(n)
因此每次add操作后更新一次线段树是可行的，因为最多更新q*log(n)次
再用树状数组保存答案的前缀和

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
//typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;

/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e5+100;
int tree[maxn<<2];
int seg[maxn<<2];
int mi[maxn<<2];
int b[maxn];
int s[maxn<<2];
int n;
void pushup(int rt){
 if(tree[rt*2]<=tree[rt*2+1])
   tree[rt]=tree[rt*2],mi[rt]=mi[rt*2];
else
  tree[rt]=tree[rt*2+1],mi[rt]=mi[rt*2+1];
}

void pushdown(int rt){
  if(seg[rt]){
    seg[rt*2]+=seg[rt];
    seg[rt*2+1]+=seg[rt];
    tree[rt*2]+=seg[rt];
    tree[rt*2+1]+=seg[rt];
    seg[rt]=0;
  }
}

void build(int l,int r,int rt){
  seg[rt]=0;
  if(l==r) {
    tree[rt]=b[l];
    mi[rt]=l;
    return;
    }
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}

void update(int l,int r,int ll,int rr,int add,int rt){
  if(l>=ll&&r<=rr) {
    seg[rt]+=add;tree[rt]+=add;
    return;
  }
  pushdown(rt);
  int mid=(l+r)/2;
  if(ll<=mid) {
    update(l,mid,ll,rr,add,rt*2);
  }
  if(rr>mid){
    update(mid+1,r,ll,rr,add,rt*2+1);
  }
  pushup(rt);
}

int query(int l,int r,int ll,int rr,int rt){
  if(l>=ll&&r<=rr){
     return tree[rt];
  }
  int ans=inf;
  pushdown(rt);
  int mid=(l+r)/2;
  if(ll<=mid) 
        ans=min(ans,query(l,mid,ll,rr,rt*2));

  if(rr>mid) ans=min(ans,query(mid+1,r,ll,rr,rt*2+1));
  return ans;
}

int lowbit(int x){
  return x&(-x);
}

int sum(int x){
  int ret=0;
  while(x>0){
    ret+=s[x];
    x-=lowbit(x);
  }
return ret;
}

void add(int x,int d){
    if(x<0) return;
   while(x<=n){
    s[x]+=d;
    x+=lowbit(x);
   }
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int q;
   while(scanf("%d%d",&n,&q)==2)
   {
       for(int i=1;i<=n;i++)
         scanf("%d",&b[i]);
        build(1,n,1);
        mem(s,0);
        for(int i=1;i<=q;i++)
        {
            int l,r;
            char s[15];
            scanf("%s%d%d",s,&l,&r);
            if(s[0]=='a')
            {
                update(1,n,l,r,-1,1);
                 while(query(1,n,1,n,1)==0)
                  {
                     // cout<<mi[1]<<endl;
                     
                      add(mi[1],1);
                       update(1,n,mi[1],mi[1],b[mi[1]],1);
                  }
            }
            else{
                //cout<<sum(r)<<" "<<sum(l-1)<<endl;
               /*for(int i=0;i<=n;i++)
                 cout<<sum(i)<<" ";
                 cout<<endl;*/
               printf("%d\n",sum(r)-sum(l-1));
            }
        }
   }

 return 0;
  }

