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
const int maxn=1e5+100;
int fail[5][maxn];
char s[5][maxn];
int ans[maxn];
char st[maxn];
int now[maxn];
int prea;
void getfail(char *x,int id)
{
    int m=strlen(x);
    int i = 0, j = fail[id][0] = -1;
    while (i < m)
    {
        while (j != -1 && x[i] != x[j]) j = fail[id][j];
        fail[id][++i] = ++j;
    }
}
void kmp(char *y,int cnt)
{
 
   int n=strlen(y);
  prea=inf;
  for(int id=0;id<cnt;id++)
  {
         int i, j;
         i = j = 0;
      int top=-1;
      int m=strlen(s[id]);
       prea=min(prea,m);
       while(i<n)
       {
         if(y[i]=='-')
         {
           if(top>=0) 
               top--;
           if(top>=0)   ans[i]=min(ans[i],ans[st[top]]);
           else ans[i]=min(ans[i],m);
           i++;
           continue;
         }
         else {
             if(top==-1) j=0;
             else j=now[st[top]];
             st[++top]=i;
           }
         while(j!=-1&&y[st[top]]!=s[id][j])
           {
                j=fail[id][j];
           }
       
        ans[i]=min(ans[i],m-j-1);
        //cout<<id<<"*"<<ans[i]<<" "<<i<<" "<<j<<endl;
         i++,j++;
         now[st[top]]=j;
        if(j>=m) now[st[top]]=fail[id][j];
     }
   }
}
char buf[maxn];
int main(){
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(scanf("%d",&n)==1)
    {
        mem(ans,0x3f);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            getfail(s[i],i);
        }
        scanf("%s",buf);
        kmp(buf,n);
        int len=strlen(buf);
        printf("%d\n",prea);
        for(int i=0;i<len;i++)
          printf("%d\n",ans[i]);
    }
 return 0;
  }
