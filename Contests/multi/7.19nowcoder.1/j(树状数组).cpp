#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+100;
int data[maxn];
int a[maxn];
int ans[maxn];
map<int,int>mp;
void init()
{
    for(int i=0;i<maxn;i++)
      data[i]=0;
    mp.clear();
}
struct node{
    int l,r,id;
    bool operator<(const node &t)const{
        return l<t.l;
    }
}q[maxn];
int sum(int i){
    int ans=0;
    while(i>0){
        ans+=data[i];
        i-=i&-i;
    }
    return ans;
}
void add(int i,int x){
    while(i<maxn){
        data[i]+=x;
        i+=i&-i;
    }
}

int main()
{
   // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n,Q;
   while(scanf("%d%d",&n,&Q)==2)
   {
       init();
       for(int i=1;i<=n;i++)
         scanf("%d",&a[i]),a[i+n]=a[i];
    
      for(int i=1;i<=Q;i++)
      {
          scanf("%d%d",&q[i].l,&q[i].r);
        q[i].l=q[i].l+n;
        q[i].id=i;
      }

      sort(q+1,q+1+Q);
      int pre=1;
     for(int i=1;i<=Q;i++)
     {
         for(int j=pre;j<=q[i].l;j++)
         {
             if(mp[a[j]])
             {
                 add(mp[a[j]],-1);
             }
             add(j,1);
             mp[a[j]]=j;
         }
         pre=q[i].l+1;
         
        ans[q[i].id]=sum(q[i].l)-sum(q[i].r-1);
     }
     
     for(int i=1;i<=Q;i++)
       printf("%d\n",ans[i]);
       //cout<<ans[i]<<endl;
   }


}
/*
3 2
1 2 1
1 2
1 3

5 5
1 2 1 2 4 5
1 4
1 3
3 4
3 5
3 4
*/