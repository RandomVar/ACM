/*https://www.nowcoder.com/acm/contest/view-submission?submissionId=30004720*/
/*
神tm忘记这题吧 不想补了
有空可以看看其他的解法
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
#define int long long
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int maxn=1e6+1100;
struct node{
    int x1,y1;int x2,y2;
    int k;
}b[maxn];
int a[maxn];
int num1[maxn];
int num0[maxn];
int si[maxn];
int n,m;
int sum1[maxn];
int sum0[maxn];
void addarea(node &x,int k)
{
    if(k==0)
    {
    if(x.x2<n-1&&x.y2<m-1)
        num0[(x.x2+1)*m+x.y2+1]+=1;
    if(x.x2<n-1)
        num0[(x.x2+1)*m+x.y1]-=1;
    if(x.y2<m-1)
        num0[(x.x1)*m+x.y2+1]-=1;
    num0[(x.x1)*m+x.y1]+=1;
    }
    if(k==1)
    {
       if(x.x2<n-1&&x.y2<m-1)
        num1[(x.x2+1)*m+x.y2+1]+=1;
      if(x.x2<n-1)
        num1[(x.x2+1)*m+x.y1]-=1;
      if(x.y2<m-1)
        num1[(x.x1)*m+x.y2+1]-=1;
    num1[(x.x1)*m+x.y1]+=1;
    }
}

signed main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   while(scanf("%lld%lld%lld",&n,&m,&t)==3)
   {
       mem(si,0);
       int ans=0;
       
       for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           scanf("%lld",&a[i*m+j]);
        
      
        for(int i=1;i<=t;i++)
        {
            
            scanf("%lld%lld%lld%lld%lld",&b[i].x1,&b[i].y1,&b[i].x2,&b[i].y2,&b[i].k);
           b[i].x1--;b[i].y1--;b[i].x2--;b[i].y2--;
        }

       for(int i=0;i<21;i++)
       {
         //  cout<<i<<": "<<endl;
            mem(num0,0);
            mem(num1,0);
            mem(sum0,0);
            mem(sum1,0);
            for(int j=1;j<=t;j++)
            {
              addarea(b[j],(b[j].k&(1LL<<i)));
           
            }
         
            for(int j=0;j<n*m;j++)
            {
             int x=j/m;int y=j%m;
            //cout<<j<<" "<<x<<" "<<y<<endl;
              if(j%m!=0)
                 sum0[j]+=sum0[j-1], sum1[j]+=sum1[j-1];
              if(j>=m)
                 sum0[j]+=sum0[j-m],sum1[j]+=sum1[j-m];
              if(j%m!=0&&j>=m)
                  sum0[j]-=sum0[j-m-1], sum1[j]-=sum1[j-m-1];
           /* if(x>0) sum0[j]+=sum0[(x-1)*m+y],sum1[j]+=sum1[(x-1)*m+y];
            if(y>0) sum0[j]+=sum0[x*m+(y-1)],sum1[j]+=sum1[x*m+(y-1)];
            if(x>0&&y>0) sum0[j]-=sum0[(x-1)*m+(y-1)],sum1[j]-=sum1[(x-1)*m+(y-1)];
            */
            sum0[j]+=num0[j];
            sum1[j]+=num1[j];
            // sum0[j]=sum0[(x-1)*m+y]+sum0[x*m+(y-1)]-sum0[(x-1)*m+y-1]+num0[j];//num0[(x+1)*m+y+1];
             //sum1[j]=sum1[(x-1)*m+y]+sum1[x*m+(y-1)]-sum1[(x-1)*m+y-1]+num1[j];//num1[(x+1)*m+y+1];
            // cout<<sum0[j]<<" "<<sum1[j]<<endl;
                if(a[j]&(1LL<<i)) 
                  if(sum0[j]>0) ans+=(si[j]^1),si[j]=1;
                if((a[j]&(1LL<<i))==0)
                   if(sum1[j]>0)  ans+=(si[j]^1),si[j]=1;
    
            }           
       }
     ans=0;
      for(int i=0;i<n*m;i++)
        if(si[i]) ans++;
      
       printf("%lld\n",ans);
         //cout<<ans<<endl;
   
   }

 return 0;
  }


/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1100;
struct node{
    int x1,y1;int x2,y2;
    int k;
}b[maxn];
int n,m;
int s0[maxn],s1[maxn];
int si[maxn];
int a[maxn];
int id(int x,int y) {return (x-1)*m+y-1;}
void addarea(int i,int k)
{
 if(k==0)
 {
    s0[id(b[i].x1,b[i].y1)]++;
    if(b[i].x2<n)
    s0[id(b[i].x2+1,b[i].y1)]--;
    if(b[i].y2<m)
    s0[id(b[i].x1,b[i].y2+1)]--;
    if(b[i].x2<n&&b[i].y2<m)
    s0[id(b[i].x2+1,b[i].y2+1)]++;
}
if(k==1)
 {
    s1[id(b[i].x1,b[i].y1)]++;
    if(b[i].x2<n)
    s1[id(b[i].x2+1,b[i].y1)]--;
    if(b[i].y2<m)
    s1[id(b[i].x1,b[i].y2+1)]--;
    if(b[i].x2<n&&b[i].y2<m)
    s1[id(b[i].x2+1,b[i].y2+1)]++;
}
}


int main(){
 
   int t;
   while(scanf("%d%d%d",&n,&m,&t)!=EOF)
   {
       memset(si,0,sizeof(si));
       int ans=0;
       
       for(int i=0;i<n*m;i++)
           scanf("%d",&a[i]);
       
         for(int i=1;i<=t;i++)
        {
            scanf("%d%d%d%d%d",&b[i].x1,&b[i].y1,&b[i].x2,&b[i].y2,&b[i].k);
        }

         for(int i=0;i<20;i++)
       {
        
            memset(s0,0,sizeof(s0));
            memset(s1,0,sizeof(s1));
            for(int j=1;j<=t;j++)
            {
              addarea(j, b[j].k >> i & 1);
            }

             for(int j=0;j<n*m;j++)
            {
                    if(j%m!=0)
                    s1[j]+=s1[j-1];
                    if(j>=m)
                    s1[j]+=s1[j-m];
                    if(j%m!=0&&j>=m)
                    s1[j]-=s1[j-m-1];
                 
                 if(j%m!=0)
                    s0[j]+=s0[j-1];
                    if(j>=m)
                    s0[j]+=s0[j-m];
                    if(j%m!=0&&j>=m)
                    s0[j]-=s0[j-m-1];
            }
         for(int j=0;j<n*m;j++)
         {
             if((a[j] >> i & 1) == 0 &&s0[j]>0) 
                  si[j]=1;
            if((a[j] >> i & 1) == 1 &&s1[j]>0)
                 si[j]=1;
         }
       }
         for(int i=0;i<n*m;i++)
          if(si[i]) ans++;
      
       printf("%d\n",ans);

   }
 return 0;
  }



*/