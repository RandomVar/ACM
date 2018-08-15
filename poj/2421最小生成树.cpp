#include<iostream>
#include<algorithm>
using namespace std;
#define maxm 105*105//最多边数
#define maxn 105//最多顶点数
struct edge{
  int u,v,w;
}edges[maxm];
int p[maxn];int n,q,k;
void init(){
 for(int i=0;i<n;i++)
    p[i]=-1;
}
int find(int x){
  int s;
  for(s=x;p[s]>=0;s=p[s]);
  while(s!=x){/*压缩路径*/
    int temp=p[x];
    p[x]=s;
    x=temp;
  }
  return s;
}
int cmp(edge a,edge b){
 return a.w<b.w;
}
void unin(int x,int y){
  int x1=find(x);int y1=find(y);
  int temp=p[x1]+p[y1];/*p[根节点]的值为的其所有子节点的个数*/
  if(p[x1]>p[y1]){
    p[x1]=y1;
    p[y1]=temp;
    }
  else{
    p[y1]=x1;
    p[x1]=temp;
  }
}
int kruskal(){
  int sumweight=0;//生成树的总权值
  int num=0;//已选用的边的数目

  sort(edges,edges+k,cmp);
  for(int i=0;i<k;i++){
        int u=edges[i].u;int v=edges[i].v;int w=edges[i].w;
    if(find(u)!=find(v))
    {unin(u,v);num++;sumweight+=w;
    // cout<<u<<" "<<v<<endl;
  }
  if(num==n-1) break;
}
return sumweight;
}
int main(){

 while(cin>>n){
        k=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
            int x;
        cin>>x;
        edges[k].u=i;edges[k].v=j;edges[k].w=x;
        k++;
    }}
    init();
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;cin>>x>>y;
        unin(--x,--y);
    }

 cout<<kruskal()<<endl;
}
 return 0;
}
