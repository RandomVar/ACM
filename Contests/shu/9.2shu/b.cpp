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
const int maxn =1e6+100;
int fail[maxn];
int n;
int  getfail(char *x)
{
    int m=strlen(x);
    int i = 0, j = fail[0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) 
         {
             if(j<n&&x[i]<x[j]) return 0;
             j = fail[j];
         }
        fail[++i] = ++j;
    }
    return 1;
}
char s[maxn];
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


   while(scanf("%d",&n)==1)
   {
     scanf("%s",s);
    for(int i=0;i<n;i++)
      s[i+n]=s[i];
      s[2*n]='\0';
     if(getfail(s))
       printf("Yes\n");
    else printf("No\n");
   }
 return 0;
  }
