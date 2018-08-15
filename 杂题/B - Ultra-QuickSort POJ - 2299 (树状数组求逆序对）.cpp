/*
�������������

�������ǵ�iС �����iλ��1��ͳ����ǰ���м���1���м�������С��,i-sum(i)��Ϊ����Ը���
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
vector<int>v;
int tree[500100];
int a[500100];
int n;
int getid(int x){
 return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int lowbit(int x){
return x&(-x);
}
int sum(int x){//���
  int ret=0;
  while(x>0){
    ret+=tree[x];
    x-=lowbit(x);
  }
return ret;
}

void update(int x,int d){//���½ڵ���Ϣ
    if(x<0) return;
   while(x<=n){
    tree[x]+=d;
    x+=lowbit(x);
   }
}
int main(){
   //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   //int n;
   while(cin>>n&&n){
        v.clear();
     for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),v.push_back(a[i]);

      sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
    mem(tree,0);
    ll ans=0;
    for(int i=1;i<=n;i++){
        int t=getid(a[i]);
        update(t,1);
        ans+=i-sum(t);

    }
    printf("%lld\n",ans);
   // cout<<ans<<endl;

   }


}
