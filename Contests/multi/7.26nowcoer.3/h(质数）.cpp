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
const int MAXN = 1e7+100;
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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    getPrime();
    while(cin>>n)
    {
        ll ans=0;
        prime[0]=0;
       int i;
       for(i=1;prime[i]<=n;i++)
       {
           
           ans+=(n/prime[i])*(i-1);
           //cout<<prime[i]<<" "<<i<<" "<<ans<<endl;
       }
       cout<<ans*2<<endl;
    }

 return 0;
  }

