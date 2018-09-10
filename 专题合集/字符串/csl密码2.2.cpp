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
const int maxn=1e6+100;
char s[maxn];
int zhi1[maxn],zhi2[maxn];
ll bit[10][maxn];
int fail[maxn];
int len;
void getfail(char *x)
{
    int i = 1, j = fail[1] = -1;
    while (i <= len)
    {
        while (j != -1 && x[i] != x[j]) j = fail[j];
        fail[++i] = ++j;
    }
}
int lowbit(int x){
return x&(-x);
}
ll sum(int x,int id,int c){
  ll ret=0;
  while(x>0){
    ret+=bit[c*5+id][x];
    x-=lowbit(x);
  }
return ret;
}

void add(int x,int id,int c){
    if(x<0) return;
   while(x<=len){
    bit[c*5+id][x]++;
    x+=lowbit(x);
   }
}

int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        for(int i=len-1;i>=0;i--)
          s[i+1]=s[i];
          s[len]='\0';
        // cout<<len<<endl;
        int flag=0;
        zhi1[0]=zhi2[0]=0;
        for(int i=1;i<=len;i++)
        {
            zhi1[i]=(s[i]-'0')*(flag+1);//2^0
            zhi2[i]=(s[i]-'0')*((flag^1)+1);//2^1
            flag^=1;
           zhi1[i]=(zhi1[i]+zhi1[i-1])%3;
           zhi2[i]=(zhi2[i]+zhi2[i-1])%3;
        }
        ll ans=0;
         getfail(s);
         mem(bit,0);
        for(int i=1;i<=len;i++)
        {
            if(i%2==1)
            {
                if(fail[i+1]==0||fail[i+1]==-1)
                 ans+=sum(i,zhi1[i],0);
                else ans+=sum(fail[i+1]-1,zhi1[i],0);            
            }
            else 
              ans+=sum(max(fail[i+1]-1,1),zhi2[i],1);
            if(s[i]!='0')
            {
                add(i,zhi1[i-1],0);
                add(i,zhi2[i-1],1);
            }
        }
        printf("%lld\n",ans);            
 
    }
 return 0;
  }
