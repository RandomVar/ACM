/*
https://wenku.baidu.com/view/5b886b1ea76e58fafab00374.html

求不可重叠的最长重复子串
二分答案，
若长度为k的不可重叠的最长重复子串，则存在 min(height[i],height[i+1],……,height[j])>=k 且 abs(sa[i]-sa[j])>=k
按height分组，保证同一分组中所有height[i]>=k(每组后缀间的height都大于等于k)，则有希望满足条件的子串一定在同一分组内。
查询一分组内是否有i,j满足abs(sa[i],sa[j])>=k即可。

**/
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
const int maxn =2*1e4+100;
int s[maxn];
int a[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], ran[maxn], height[maxn];
/*
sa为后缀数组，保存sa[第i个名次]=是i开头后缀
rank为名次数组rank[i开头的后缀]=的名次
height为相邻两个后缀的最长公共前缀
*/
//n为字符串的长度,字符集的值为0~m-1

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

int check(int k,int n)
{
    int mas;int mis;
    mas=mis=sa[1];
    for(int j=2;j<=n;j++){
          if(height[j]>=k&&j<n) {
          mas=max(mas,sa[j]);
          mis=min(mis,sa[j]);
          continue;
          }
        if(mas-mis>=k) return 1;
        mas=mis=sa[j];
      }
    return 0;
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n&&n)
   {
       for(int i=0;i<n;i++)
         cin>>a[i];
          n--;
        for(int i=0;i<n;i++)
         s[i]=a[i+1]-a[i]+88;
        s[n]=0;
        build_sa(180,n);
       int ans=0;
       int l=0,r=n>>1;
         while(l<=r){
             int mid=(l+r)/2;
             if(check(mid,n)) l=mid+1,ans=mid;
             else r=mid-1;
         }
      //cout<<ans<<endl;
         if(ans >=4) printf("%d\n",ans+1);
         else printf("%d\n",0);
    
   
    }

 return 0;
  }

