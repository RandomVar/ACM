#include<bits/stdc++.h>

/*#include<cstdio>
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
*/
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
const int maxn =50100*4;
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn];
int ran[maxn], height[maxn];
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


int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(scanf("%d",&n)==1)
   { 
       scanf("%s",s);
       for(int i=n;i<2*n;i++)
       {
           s[i]=s[i-n];
       }
       s[2*n]='&';
       int k=2*n-1;
       for(int i=2*n+1;i<=4*n;i++)
         s[i]=s[k--];
         //s[i]=s[2*n-(i-2*n)+1];
        s[4*n+1]='\0';
       // cout<<s<<endl;
       build_sa(128,4*n+1);
       height[4*n+2]=0;
       ll ans=0;
       for(int i=1;i<=4*n+1;i++)
       {
           if(sa[i]==2*n) continue;
          else if(sa[i]>2*n)
            ans+=min(n,4*n+1-sa[i])-min(n,height[i]);
          else if(sa[i]<2*n)
            ans+=min(n,2*n-sa[i])-min(n,height[i]);
             //cout<<sa[i]<<" "<<height[i]<<endl;
         //if(height[i]<n) 
           //   ans-=height[i];
       }
       cout<<ans<<endl;
   }

 return 0;
  }

