#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int bit[maxn];
int st[maxn];
int a[maxn];
int n;
int mi[maxn<<2];
int ma[maxn<<2];
typedef pair<int,int> P;
void pushup(int rt){
  mi[rt]=min(mi[rt*2],mi[rt*2+1]);
  ma[rt]=max(ma[rt*2],ma[rt*2+1]);
}

void build(int l,int r,int rt){
  if(l==r) {
      mi[rt]=l;
      ma[rt]=l;
      return;
      }
  int mid=(l+r)/2;
  build(l,mid,rt*2);
  build(mid+1,r,rt*2+1);
  pushup(rt);
}

P query(int l,int r,int L,int R,int rt){
    P ans;
 if(l>=L&&r<=R)
 {
     ans.first=mi[rt];
     ans.second=ma[rt];
     return ans;
 }
 ans.first=1e8;
  ans.second=0;
 int mid=(l+r)/2;
 if(L<=mid){
    P x=query(l,mid,L,R,rt*2);
   ans.first=min(ans.first,x.first);
   ans.second=max(ans.second,x.second);
 }
 if(R>mid){
  P x=query(mid+1,r,L,R,rt*2+1);
  ans.first=min(ans.first,x.first);
   ans.second=max(ans.second,x.second);
 }
 return ans;
}

void update1(int l,int r,int index,int add,int rt){
  if(l==r) {
      mi[rt]=min(mi[rt],add);
    return;
  }
  int mid=(l+r)/2;
  if(index<=mid)
    update1(l,mid,index,add,rt*2);

  else update1(mid+1,r,index,add,rt*2+1);
  pushup(rt);
}
void update2(int l,int r,int index,int add,int rt){
  if(l==r) {
      ma[rt]=max(ma[rt],add);
    return;
  }
  int mid=(l+r)/2;
  if(index<=mid)
    update2(l,mid,index,add,rt*2);

  else update2(mid+1,r,index,add,rt*2+1);
  pushup(rt);
}

int lowbit(int x){
return x&(-x);
}
int sum(int x){
  int ret=0;
  while(x>0){
    ret+=bit[x];
    x-=lowbit(x);
  }
return ret;
}

void add(int x,int d){
    if(x<0) return;
   while(x<=n){
    bit[x]+=d;
    x+=lowbit(x);
   }
}

int main()
{
    int m,q;
    while(scanf("%d%d%d",&n,&m,&q)==3)
    {
        memset(bit,0,sizeof(bit));
       build(1,n,1);
        for(int i=1;i<=n;i++)
         scanf("%d",&a[i]);
         int top=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==0)
             st[++top]=i;
            else
              {
                  if(top==-1)
                    add(i,1);
                    // b[i]=-1;
                  else if(a[st[top]]/2!=a[i]/2)
                    {
                        add(i,1);
                        while(top!=-1)
                          add(st[top--],1);
                    }
                    else 
                    {
                        update1(1,n,i,st[top],1);
                        update2(1,n,st[top],i,1);
                        // P ans=query(1,n,i,st[top],1);
                        // cout<<"!"<<ans.first<<" "<<ans.second<<endl;
                        // cout<<"*"<<st[top]<<" "<<i<<endl;
                        top--;
    
                    }
              }
        }
        while(top!=-1)
          add(st[top--],1);

        for(int i=1;i<=q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int x=sum(r)-sum(l-1);
            P ans=query(1,n,l,r,1);
            // cout<<ans.first<<" "<<ans.second<<endl;
            int flag=1;
            if(ans.first<l||ans.second>r)
             flag=0;
            // cout<<sum2(r)<<" "<<sum2(l-1)<<endl;
           if(x!=0||flag==0)
            printf("No\n");
        else
           printf("Yes\n");
        }
        
    }
}