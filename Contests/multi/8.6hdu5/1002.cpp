/*贪心 误*/
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int len;
char s[20];
char ans[20];
char ans2[20];
char s2[20];
void solve(ll k)
{
    if(k==0) return;
    char a='9';
    int  index=-1;
      for(int j=1;j<len;j++)
        {
           if(a>=s[j]&&s[j]!='0')
                a=s[j],index=j;
        }
    if(index!=-1&&a<s[0])
       {
         s[index]=s[0];
         s[0]=a;
         k--;
        if(k<=0) return;
       }
    for(int i=1;i<len;i++)
    {
        if(k<=0) return;
        int index=0;char a='9';
        for(int j=i+1;j<len;j++)
        {
           if(a>=s[j])
                a=s[j],index=j;
        }
         if(a>=s[i]) continue;
         s[index]=s[i];
         s[i]=a;
         k--;
    }
   for(int i=0;i<len;i++)
     if(s[i]!=ans[i]) {solve(k);return;}
       return;
}
void solve2(ll k)
{
    if(k==0) return;
    for(int i=0;i<len;i++)
    {
        if(k<=0) return;
        int index=-1;char a='0';
        for(int j=i+1;j<len;j++)
        {
           if(a<=s2[j])
                a=s2[j],index=j;
        }
         if(a<=s2[i]||index==-1) continue;
         s2[index]=s2[i];
         s2[i]=a;
         k--;
    }
   for(int i=0;i<len;i++)
     if(s2[i]!=ans2[i]) {solve2(k);return;}
       return;
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   scanf("%d",&t);
   while(t--)
   {
      // char s[20];
       ll k;
       scanf("%s%lld",s,&k);
       len=strlen(s);
       for(int i=0;i<len;i++)
        ans[i]=s[i],s2[i]=s[i];
        
        ans[len]='\0';s2[len]='\0';
        sort(ans,ans+len);
        for(int i=0;i<len;i++)
           ans2[i]=ans[len-1-i];
        ans[len]='\0';
        int x=0;
        for(x=0;x<len;x++)
           if(ans[x]!='0') break;
        swap(ans[x],ans[0]);

       solve(k);

       solve2(k);
       printf("%s %s\n",s,s2);
   }
 return 0;
  }

