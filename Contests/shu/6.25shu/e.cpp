#include<cstdio>
#include<iostream>
#include<queue>
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
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int Max=1e5+100;
int fat[Max],ran[Max];
void Init(int n)//初始化重要
{
    for(int i=0; i<=n; i++)
    {
        fat[i]=i;//初始化都是指向（看做）自己
        ran[i]=0;//0同类 1吃父节点 2被父节点吃
    }
    return;
}
int Find(int x)//找寻父节点+路径压缩
{
    if(x==fat[x])
        return fat[x];
    int y=Find(fat[x]);
        ran[x]=(ran[x]+ran[fat[x]])%2;//递归后从祖先节点向后到每个孩子来计算
    return fat[x]=y;//路径压缩
}
int Union(int typ,int x,int y)//区间并与查询
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)//共父节点才能判断出关系
    {
        if((ran[x]-ran[y]+2)%2==typ-1)
            return 0;
        return 1;
    }
    fat[x1]=y1;//连接两父节点
    ran[x1]=(-ran[x]+typ-1+ran[y]+2)%2;//使用类似向量方法来计算权值,虽然题目只有两个，但是会出现被吃这种情况，所以要变成3种情况，注意一定要处理负数的情况
    return 0;
}
int main(){
  int n,m,q;

  while(cin>>n>>m>>q){
          Init(n);
          map<string,int>mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=i;
    }
    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        string a,b;
        cin>>a>>b;
      int t1=mp[a];int t2=mp[b];
        if(Union(op,t1,t2)==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
   for(int i=0;i<q;i++){
      string a,b;
      cin>>a>>b;
       int t1=mp[a];
       int t2=mp[b];
       int x=Find(t1);
       int y=Find(t2);
       if(x==y)//共父节点才能判断出关系
    {
        if((ran[t1]-ran[t2]+2)%2==0)
            cout<<1<<endl;
        else cout<<2<<endl;
    }
    else cout<<3<<endl;

   }

  }
}
