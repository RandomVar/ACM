#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
#define mkr make_pair
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
const int maxn=205;
char s[maxn];
int st[maxn];
int cnt[maxn];
ll shu1[maxn];
ll shu2[maxn];
int isop(char c)
{
  if(c=='+'||c=='-') return 2;
  if(c=='*') return 3;
  if(c=='d') return 4;
  if(c=='(') return 5;
  if(c==')') return 1;
  if(c=='%') return -1;
   return 0;
}
bool cp(char s1,char s2)
{
  return isop(s1)>=isop(s2);
}
ll op(char c,ll x,ll y)
{
  if(c=='+') return x+y;
  if(c=='-') return x-y;
  if(c=='*') return x*y;
}
int main(){

/*  #ifndef ONLINE_JUDGE
     freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
     #endif
*/
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(scanf("%s",s)!=EOF)
    {
      int len=strlen(s);
      int top=-1;
      mem(cnt,0);
      s[len]='%';
      s[++len]='\0';
      for(int i=0;i<len;i++)
      {
         if(isop(s[i]))
         {
          while(top!=-1&&(cp(s[st[top]],s[i])>0&&s[st[top]]!='('))
           {
             if(s[st[top]]=='-')
                {
                  for(int j=st[top];j<i;j++)
                     if(s[j]=='d'||s[j]=='*') cnt[j]^=1;
                }
             top--;
           }
           if(s[i]==')') top--;
           else st[++top]=i;
          // cout<<s[i]<<top<<endl;
         }
      }
      top=-1;
      int t1=-1;
      int t2=-1;

      for(int i=0;i<len;i++)
     {
       if(isop(s[i]))
       {
        //  cout<<"&"<<top<<" "<<s[st[top]]<<" "<<s[i]<<endl;
          while(top!=-1&&(cp(s[st[top]],s[i])>0&&s[st[top]]!='('))
         {

           if(isop(s[st[top]])==2)
           {
             ll ans1=op(s[st[top]],shu1[t1-1],shu1[t1]);
             ll ans2=op(s[st[top]],shu2[t2-1],shu2[t2]);
            //  cout<<"?"<<shu1[t1-1]<<" "<<shu1[t1]<<" "<<t1<<endl;
             t1-=2;t2-=2;
             shu1[++t1]=ans1;
             shu2[++t2]=ans2;
            //  cout<<"+"<<ans1<<" "<<t1<<endl;
            }
            else if(s[st[top]]=='*')
            {
              ll ans1=-INF;
              ll ans2=INF;
              ll x=op(s[st[top]],shu1[t1],shu1[t1-1]);
              ans1=max(ans1,x);
              ans2=min(ans2,x);
              x=op(s[st[top]],shu2[t2],shu2[t2-1]);
              ans1=max(ans1,x);
              ans2=min(ans2,x);
             x=op(s[st[top]],shu1[t1],shu2[t2-1]);
              ans1=max(ans1,x);
              ans2=min(ans2,x);
              x=op(s[st[top]],shu2[t2],shu1[t1-1]);
              ans1=max(ans1,x);
              ans2=min(ans2,x);
              // cout<<"*"<<ans1<<" "<<ans2<<" "<<shu1[t1]<<" "<<shu1[t1-1]<<" "<<t1<<endl;
              t1-=2;t2-=2;
           if(cnt[st[top]]==0)
           {
              shu1[++t1]=ans1;
              shu2[++t2]=ans2;
            }
              else
              {
                shu1[++t1]=ans2;
                shu2[++t2]=ans1;
              }
              // cout<<"d"<<" "<<cnt[st[top]]<<" "<<ans1<<" "<<ans2<<endl;
          }
            else if(s[st[top]]=='d')
            {
            ll ans1,ans2;
            if(cnt[st[top]]==0)
            {
              ans1=shu1[t1]*shu1[t1-1];
              ans2=shu2[t2-1];
            }
            else
            {
              ans1=shu1[t1-1];
              ans2=shu2[t2-1]*shu2[t2];
            }
            t1-=2;t2-=2;
            shu1[++t1]=ans1;
            shu2[++t2]=ans2;
          }

          top--;
       }
        if(s[i]==')') top--;
         else st[++top]=i;
         //cout<<top<<endl;
      }
       else
       {
         ll x=0;
         while(s[i]>='0'&&s[i]<='9')
           x=x*10+s[i]-'0',i++;
           i--;
        shu1[++t1]=x;
        shu2[++t2]=x;
        // cout<<"!"<<x<<" "<<t1<<endl;
       }
     }
    //cout<<"*"<<t1<<" "<<t2<<endl;
   printf("%lld %lld\n",shu2[0],shu1[0]);
    }
 return 0;
  }