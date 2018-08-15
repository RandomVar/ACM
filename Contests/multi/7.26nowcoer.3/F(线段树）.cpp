/*
SOD为不断求十六进制各位之和至其<16得到的数字
给1e5长度的十六进制数，有1e5次操作
每次操作改变其中一位数或者求[l,r]区间内\sum num[i]*1021^{i} mod 1e9+7,num[i]为区间内SOD为i的个数


发现SOD特点为SOD(ABCD)=SOD(A+B+C+D)=(A+B+C+D)%15
但当(A+B+C+D)=15时 SOD=15，需要特判
对线段树记录每一个点0-15每一种取值的个数
区间合并的时候就加一加，重载一个运算符方便一点

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
const int mod=1e9+7;
const int maxn=1e5+100;
ll base[20];
struct node{
    ll val[16];
    void init()
    {
        mem(val,0);
    }
    node operator+(const node &b)const{
        node ans;

        for(int i=0;i<16;i++) ans.val[i]=(b.val[i]+val[i])%mod;
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
            {
                int ni=(i+j)%15;
                if(i+j>0&&ni==0) ni=15;
             ans.val[ni]=(ans.val[ni]+b.val[i]*val[j]%mod)%mod;          
            }
        return ans;
    }
} tree[maxn<<2];
char s[maxn];
void pushup(int rt){
  tree[rt]=tree[rt*2]+tree[rt*2+1];
}

void build(int l,int r,int rt){
  tree[rt].init();
  if(l==r) { 
      if(s[l-1]>='0'&&s[l-1]<='9')
        tree[rt].val[s[l-1]-'0']++;
      else tree[rt].val[s[l-1]-'A'+10]++;
      return;
      }
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}

node query(int l,int r,int ll,int rr,int rt){
 if(l>=ll&&r<=rr) 
 {
//       for(int i=0;i<16;i++)
//    cout<<tree[rt].val[i]<<" ";
//    cout<<endl;
    return tree[rt];
 
 }
 
 int mid=(l+r)/2;
 if(rr<=mid){
    return query(l,mid,ll,rr,rt*2);
 }
 if(ll>mid){
    return query(mid+1,r,ll,rr,rt*2+1);
 }
 return query(l,mid,ll,rr,rt*2)+query(mid+1,r,ll,rr,rt*2+1);
 //for(int i=0;i<16;i++)
 //  cout<<ans.val[i]<<" ";
  // cout<<endl;

}

void update(int l,int r,int index,int add,int rt){
  if(l==r) {
       tree[rt].init();
       tree[rt].val[add]++;
    return;
  }
  int mid=(l+r)/2;
  if(index<=mid){
    update(l,mid,index,add,rt*2);
  }
  else update(mid+1,r,index,add,rt*2+1);
  pushup(rt);
}
ll solve(int l,int r,int n)
{
    ll daan=0;
    node ans=query(1,n,l,r,1);
    for(int i=0;i<16;i++)
      {
     //   cout<<ans.val[i]<<" ";
      daan=(daan+ans.val[i]*base[i]%mod)%mod;
      }
  return daan%mod;
}

int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    base[0]=1;
    for(int i=1;i<16;i++)
      base[i]=base[i-1]*1021%mod;
    while(scanf("%d%d",&n,&q)==2)
    {
        scanf("%s",s);
        build(1,n,1);
       for(int i=1;i<=q;i++)
       {
           int op;
           scanf("%d",&op);
           if(op==1)
           {
               int p;char c[5];
               int val;
               scanf("%d%s",&p,c);
               if(c[0]>='0'&&c[0]<='9')
                   val=c[0]-'0';
                else val=c[0]-'A'+10;
            update(1,n,p,val,1);
           }
           if(op==2)
           {
               int l,r;
               scanf("%d%d",&l,&r);
               printf("%lld\n",solve(l,r,n));
           }
       }
    }

 return 0;
  }

