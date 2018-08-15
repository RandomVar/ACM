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
void Init(int n)//��ʼ����Ҫ
{
    for(int i=0; i<=n; i++)
    {
        fat[i]=i;//��ʼ������ָ�򣨿������Լ�
        ran[i]=0;//0ͬ�� 1�Ը��ڵ� 2�����ڵ��
    }
    return;
}
int Find(int x)//��Ѱ���ڵ�+·��ѹ��
{
    if(x==fat[x])
        return fat[x];
    int y=Find(fat[x]);
        ran[x]=(ran[x]+ran[fat[x]])%2;//�ݹ������Ƚڵ����ÿ������������
    return fat[x]=y;//·��ѹ��
}
int Union(int typ,int x,int y)//���䲢���ѯ
{
    int x1=Find(x);
    int y1=Find(y);
    if(x1==y1)//�����ڵ�����жϳ���ϵ
    {
        if((ran[x]-ran[y]+2)%2==typ-1)
            return 0;
        return 1;
    }
    fat[x1]=y1;//���������ڵ�
    ran[x1]=(-ran[x]+typ-1+ran[y]+2)%2;//ʹ��������������������Ȩֵ,��Ȼ��Ŀֻ�����������ǻ���ֱ����������������Ҫ���3�������ע��һ��Ҫ�����������
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
       if(x==y)//�����ڵ�����жϳ���ϵ
    {
        if((ran[t1]-ran[t2]+2)%2==0)
            cout<<1<<endl;
        else cout<<2<<endl;
    }
    else cout<<3<<endl;

   }

  }
}
