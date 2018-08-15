/*
求不相似字符串的个数（字符串仅含a,b,c)

将字符串复制6份，中间加其他不同的字符，后缀数组求不同字符串个数
得出的个数是答案的6倍
单一字符串得出的个数是答案的3倍
答案为 （不同字符串个数+3*单一字符串个数）/6

xbb:求不同字符串 要注意n个字符串都相等，最后答案算1个。不理解这个很难想通。

*/

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
const int maxn =31*1e4;
char s[maxn];
int sa[maxn], t[maxn], t2[maxn], c[maxn], ran[maxn], height[maxn];
int a[5];
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
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    while(cin>>n)
    {
        cin>>s;
        for(int i=0;i<3;i++)
        {
            a[i]=i;
        }
        int k=0;
        next_permutation(a,a+3);
        int tot=n;
        do{
            s[tot++]=char('d'+k);
            k++;
            for(int i=0;i<n;i++)
                s[tot++]=(char)('a'+a[s[i]-'a']);
        }while(next_permutation(a,a+3));
        s[tot]='\0';
        //cout<<s<<endl;
        build_sa(128,tot);

        ll ans=0;

       for(int i=1;i<=tot;i++)
        {
            ll cur =n- (sa[i] % (n + 1));
            ans += cur - height[i];
          //ans+=max(n-sa[i]%(n+1)-height[i],0);
        }
         ll res=0;
        ll cnt=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
                cnt++;
           else cnt=1;
            res=max(cnt,res);
        }
        //cout<<res<<endl;
        ans+=3*res;
        cout<<ans/6<<endl;
    }

 return 0;
  }

