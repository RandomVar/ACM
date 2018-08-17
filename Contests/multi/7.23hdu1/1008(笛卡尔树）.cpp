/*
定义两个RMQ相似为区间相同且下标最小的最大值位置相同
给定数组A，在0，1间随机B的值，若A,B相似，则B的weight的数学期望为B数组元素之和，反之则为0
求B的weight的数学期望

建A的笛卡尔树，若A,B笛卡尔树同构则相似
符合条件的构造数量为 总的种数 / 所有子树大小的连乘（即树的拓扑序的数量）
一种构造的期望为 n/2
weight的期望为 符合条件的个数 / 总的种数（即为符合条件的概率） * n/2

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
const int mod=1e9+7;
const int maxn=1e6+100;
typedef pair<int,int> P;
P a[maxn];
int vis[maxn];
int r[maxn],l[maxn];
int stk[maxn];
ll res;
int n;
ll inv[maxn];
int dfs(int x)
{
    int ans=1;
   if(l[x]) ans+=dfs(l[x]);
   if(r[x]) ans+=dfs(r[x]);
   res=(res*inv[ans])%mod;
   return ans;
}
/**笛卡尔树
 * 中序遍历得到的序列为原数组序列
 * 节点的key值要大于其左右子节点的key值
 * 利用单调栈建树
 **/
void build() {
	int top=0;
	for(int i=1;i<=n;i++)
      l[i]=0,r[i]=0,vis[i]=0;
	for(int i=1;i<=n;i++)
     {
		int k=top;
		while (k>0&&a[stk[k-1]]<a[i]) --k;
		if (k) r[stk[k-1]]=i;//找出i左边第一个比它大的数，把i连到它的右子树
		if (k<top) l[i]=stk[k];//将该数字原来的右子树连到i的左子树
		stk[k++]=i;
		top=k;
	}
    for(int i=1;i<=n;i++)
	   vis[l[i]]=vis[r[i]]=1;
	int rt=0;
    for(int i=1;i<=n;i++)
       if (vis[i]==0)  rt=i;
	dfs(rt);
}
/*线性递推求逆元*/
void init()
{
    inv[1]=1;
   for(int i=2;i<=1e6;i++)
   inv[i]=inv[mod%i]*(mod-mod/i)%mod;

}
int main(){
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   init();
   scanf("%d",&t);
   while(t--)
   {
      // int n;
       scanf("%d",&n);
       for(int i=1;i<=n;i++){
         int t;
         scanf("%d",&t);
         a[i]=make_pair(t,-i);
       }
       res=inv[2]*n%mod;
       build();
     printf("%lld\n",res);
   }

 return 0;
  }

