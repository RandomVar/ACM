#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;
struct node{
 int w,id;
bool operator<(const node &b)const {
  return w<b.w;
}
bool operator>(const node &b)const {
  return w>b.w;
}
}a[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int n;
   while(cin>>n){
    priority_queue<node,vector<node>,greater<node> >q1;
      priority_queue<node>q2;
      for(int i=1;i<=n;i++)
        {
            cin>>a[i].w;
            a[i].id=i;
            q1.push(a[i]);
            }

    string s;
    cin>>s;
      for(int i=0;i<2*n;i++){
         if(s[i]=='0'){
            node e=q1.top();
            cout<<e.id<<" ";
            q1.pop();
            q2.push(e);
         }
         else{
            node e=q2.top();
            cout<<e.id<<" ";
            q2.pop();
         }
      }
      cout<<endl;
   }

}
