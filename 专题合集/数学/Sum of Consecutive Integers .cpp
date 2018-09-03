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

const int MAXN=1e7+5;

bool isnotprime[MAXN+1];
int prime[670010];
int k;
void getPrime() 
{
    memset(isnotprime,false,sizeof(isnotprime));
    isnotprime[0]=true,isnotprime[1]=true;
     k=0;
    for(int i=2;i<MAXN;i++)
    {
         if(!isnotprime[i])
          prime[k++]=i;
          for(int j=0;prime[j]*i<MAXN&&j<k;j++)
          {
               isnotprime[i*prime[j]]=true;
               if(!(i%prime[j])) break;
          }
    }
   // cout<<k<<endl;
}
ll ans;
void getFactors(long long x) {
    
    long long tmp=x;
    while(tmp%2==0)
    {
        tmp/=2;
    }
    for(int i=1;(ll)prime[i]*prime[i]<=tmp&&i<k;i++) {
        int cnt=0;
     
        if(tmp%prime[i]==0){
        
            while(tmp%prime[i]==0){
             cnt++;
            tmp/=prime[i]; 
        }
        ans*=(cnt+1);
        } 
        }
       if(tmp!=1) 
           ans*=2;
    }

int main(){

   int t;int cas=0;
   scanf("%d",&t);

   getPrime();

   while(t--)
   {

       ll n;
       scanf("%lld",&n);
   
       ans=1;
       getFactors(n);
       
     printf("Case %d: %lld\n",++cas,ans-1);
   
   }

 return 0;
  }

