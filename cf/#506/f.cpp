#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mpr make_pair
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
const int MAXN = 1e7+10;
bool has[MAXN+1];
int prime[MAXN/10+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    memset(has,false,sizeof(has));
    for(int i=2;i<=MAXN;i++)
    {
        if(!has[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            has[prime[j]*i]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}
ll fat[100][2];
int fcnt;
int getfats(ll x) 
{
    fcnt=0;
    ll tmp=x;
    for(int i=1;i<prime[0]&&prime[i]<=tmp/prime[i];i++) // if x is larger than 1e7,may need add condition i<prime[0]
    {
        fat[fcnt][1]=0;
        if(tmp%prime[i]==0)
        {
            fat[fcnt][0]=prime[i];
            while(tmp%prime[i]==0)
             {
            fat[fcnt][1]++;
            tmp/=prime[i]; 
             }
            fcnt++;
        } 
    }
       if(tmp!=1)  
       {
         fat[fcnt][0]=tmp;
         fat[fcnt++][1]=1; 
        }
   return fcnt;
}
map<ll,ll>mp;
int getfats2(ll x) 
{
    ll tmp=x;
    for(int i=1;i<prime[0]&&prime[i]<=tmp/prime[i];i++) // if x is larger than 1e7,may need add condition i<prime[0]
    {
       
        if(tmp%prime[i]==0)
        {
         
            while(tmp%prime[i]==0)
             {
                 mp[prime[i]]++;
            
            tmp/=prime[i]; 
             }
        
        } 
    }
       if(tmp!=1)  
       {
           mp[tmp]++; 
        }
 
}
int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   ll a,b;
   getPrime();
   while(cin>>a>>b)
   {
       getfats(a);
       
       getfats2(b);
       ll ans=1;
      // cout<<fcnt<<endl;
      /* for(int i=0;i<fcnt;i++)
       {
           //cout<<fat[i][0]<<endl;
           if(mp.count(fat[i][0]))
             ans*=min(fat[i][1],mp[fat[i][0]])+1;
       }*/
       
       if(a!=b) cout<<ans*2<<endl;
         else cout<<ans*4<<endl;
   } 
 return 0;
  }
