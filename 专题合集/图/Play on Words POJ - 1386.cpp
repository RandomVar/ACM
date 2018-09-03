#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
struct node{
  int in,out;
}nodes[30];
int p[30];
void init(){
  for(int i=0;i<26;i++)
    p[i]=-1;/*根节点初始化为自己*/
}
int find(int x){
 return x==p[x]?x:find(p[x]);
}
void unin(int x,int y){
  x=find(x);y=find(y);
  if(x!=y) p[x]=y;
}
bool connect(){
  int base=-1;
  for(int i=0;i<26;i++){
    if(p[i]==-1) continue;
    else if(base==-1) {base=find(i);continue;}
    else if(base!=find(i)){return false;}
}
return true;
}
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    string s;
    init();
    for(int i=0;i<26;i++){
        nodes[i].in=nodes[i].out=0;
    }
   // memset(nodes.out,0,sizeof(nodes.out));
    for(int i=0;i<n;i++){
    getchar();
    cin>>s;
    int len=s.size();
    p[s[0]-'a']=s[0]-'a';
    p[s[len-1]-'a']=s[len-1]-'a';
    unin(s[0]-'a',s[len-1]-'a');
    nodes[s[0]-'a'].out++;
    nodes[s[len-1]-'a'].in++;
    }
   // cout<<connect()<<endl;
   if(!connect()) cout<<"The door cannot be open"<<endl;

   else{
    int s=-1,e=-1;int flag=0;
    for(int i=0;i<26;i++){
        if(nodes[i].in==nodes[i].out) continue;
        if(nodes[i].out-nodes[i].in==1) {
            if(s==-1) s=i;
            else {flag=1;break;}   }
        else if(nodes[i].in-nodes[i].out==1) {
            if(e==-1) e=i;
            else {flag=1;break;}
            }
        else {flag=1;break;}
    }
    //cout<<flag<<endl;
   // cout<<s<<e<<endl;
   //cout<<nodes['o'-'a'].in<<nodes['o'-'a'].out<<endl;
    if(flag) {
        cout<<"The door cannot be open"<<endl;
    }
    else {
        if(s==-1&&e==-1) cout<<"Ordering is possible"<<endl;
        else if(s==-1||e==-1) cout<<"The door cannot be open"<<endl;
        else  cout<<"Ordering is possible"<<endl;
    }}
  }
}
