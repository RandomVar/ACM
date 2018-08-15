#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
ll m;
struct node{
 int op;ll len;ll c;ll l;
 bool operator<(const node &b)const{

 return len<b.len;
 }
}nodes[maxn];
ll ans(node &t){
  int p=lower_bound(nodes,nodes+m+1,t)-nodes;
  if(nodes[p].op==1) return nodes[p].c;
  ll tmp=nodes[p].len;
  //cout<<tmp<<endl;
  tmp-=nodes[p].c*nodes[p].l;
  t.len-=tmp;
  //cout<<t.len<<endl;
  t.len%=nodes[p].l;
 // cout<<t.len<<endl;
  if(t.len==0) t.len=nodes[p].l;
  return ans(t);

}

int main(){
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     while(cin>>m){
            ll num=0;
       for(int i=0;i<m;i++){

        cin>>nodes[i].op;
        if(nodes[i].op==1){

             cin>>nodes[i].c;
             nodes[i].len=++num;

        }
        if(nodes[i].op==2){
            cin>>nodes[i].l>>nodes[i].c;
            num+=nodes[i].l*nodes[i].c;
             nodes[i].len=num;

        }
       }
       nodes[m].len=num;
     int x;
     cin>>x;
     ll pre=0;
     for(int i=0;i<x;i++){
         node t;
         cin>>t.len;
         cout<<ans(t)<<" ";

        }
           cout<<endl;
     }

return 0;
}
