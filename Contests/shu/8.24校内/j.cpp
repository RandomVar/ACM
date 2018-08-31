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
/*后缀数组 DA倍增算法 o(n*log(n))*/
const int maxn = 1e5+100;
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], ran[maxn], height[maxn];
/*
sa为后缀数组，保存sa[第i个名次]=是i开头后缀
rank为名次数组rank[i开头的后缀]=的名次
height为相邻两个后缀的最长公共前缀
*/
//n为字符串的长度,字符集的值为0~m-1
/*
build(128,s.size())
height[ 2-s.size() ] 有效
height[i]为以sa[i-1]和sa[i]开头的后缀 的最长公共前缀
*/
int n;
vector<int>vec;
vector<int>v;
int len[110];
char  buf[maxn];
int cnt[110];
int id(int x)
{
    return lower_bound(len+1,len+n+1,x)-len;
}
void build_sa(int m, int n)
{
    n++;
    int *x = t, *y = t2;
    //基数排序
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; ~i; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        //直接利用sa数组排序第二关键字
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++)
            if (sa[i] >= k) y[p++] = sa[i] - k;
        //基数排序第一关键字
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 0; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; ~i; i--) sa[--c[x[y[i]]]] = y[i];
        //根据sa和y数组计算新的x数组
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break; //以后即使继续倍增，sa也不会改变，推出
        m = p;             //下次基数排序的最大值
    }
    n--;
    int k = 0;
    for (int i = 0; i <= n; i++) ran[sa[i]] = i;
    for (int i = 0; i < n; i++)
    {
        if (k) k--;
        int j = sa[ran[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        height[ran[i]] = k;
    }
}

int check(int mid)
{
    mem(cnt,0);
    vec.clear();
    int ans=0;
    for(int i=2;i<=len[n];i++)
    {
        if(height[i]>=mid)
        {
            int x=id(sa[i-1]);
            cnt[x]++;
           // cout<<sa[i-1]<<" "<<x<<endl;
           if(cnt[x]==1) ans++;
        }
        else
        {
            int x=id(sa[i-1]);
            cnt[x]++;
            if(cnt[x]==1) ans++;
            if(ans>n/2)
              {
                 // cout<<sa[i-1]<<endl;
                  vec.pb(sa[i-1]);
              }
            mem(cnt,0);
            ans=0;
        }
    }
    if(height[n]>=mid)
    {
     int x=id(sa[n]);
      cnt[x]++;
     if(cnt[x]==1) ans++;
      if(ans>n/2)
     vec.pb(sa[n]);
    }
   if(vec.size()==0) return 0;
   else
   {
       v.clear();
       for(int i=0;i<vec.size();i++)
         v.pb(vec[i]);
   return 1;
   }
   
    //return vec.size();
}
void print(int ans)
{
    if(ans==0) {printf("?\n\n");return;}
    for(int i =0;i<v.size();i++)
    {
      //  cout<<v[i]<<endl;
        for(int j=v[i];j<v[i]+ans;j++)
         printf("%c",s[j]);
         //cout<<s[i][j];
         printf("\n");
         //cout<<endl;
    }
    printf("\n");
}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    while(scanf("%d",&n)==1&&n)
    {
        v.clear();
        char tmp[2];
        s[0]='\0';
        for(int i=1;i<=n;i++)
        {
           scanf("%s",buf);
            strcat(s,buf);
            len[i]=strlen(s);
            tmp[0]=i;
        if(i!=n)   strcat(s,tmp);
        }
        //cout<<s<<endl;
        build_sa(128,len[n]);
        int l=0;int r=len[n];
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
              l=mid+1,ans=mid;
            else r=mid-1;
        }
        //cout<<ans<<endl;
        print(ans);
    }
 return 0;
  }
