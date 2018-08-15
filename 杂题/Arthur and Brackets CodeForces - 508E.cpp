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
struct node{
int x,pos;

};
int a[1500];
int l[700],r[700];
stack<node>st;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    mem(a,0);

    int flag=1;int w=0;
    for(int i=1;i<=n;i++){
        w++;
      if(l[i]==1)
      {
        a[w]=1;a[w+1]=2;
        w++;
      if(!st.empty()){
        node t=st.top();
      while(!st.empty()&&w>=t.pos+l[t.x]){

        if(w<=t.pos+r[t.x]){
            st.pop();
            a[t.pos]=1;a[w+1]=2;
            w++;
        }
        else if(w>t.pos+r[t.x]){
             flag=0;break;

        }
      if(!st.empty())  t=st.top();
      else break;
       }}
      }
      else{
        st.push(node{i,w});
      }
      if(!flag) break;
    }


    if(!flag) {cout<<"IMPOSSIBLE"<<endl;continue;}
    for(int i=1;i<=2*n;i++)
        if(a[i]==1) cout<<"(";
        else if(a[i]==2) cout<<")";
    cout<<endl;
  }


}
