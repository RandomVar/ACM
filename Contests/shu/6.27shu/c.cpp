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
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
int id[30];
int de[30];
int edge[30][30];
string s[110];
int tot;
int top(){
    queue<int>que;
  for(int j=0;j<26;j++)
      if(!de[j]){
         que.push(j);

       }
   while(!que.empty()){
      int t=que.front();
      que.pop();
      id[++tot]=t;
      for(int j=0;j<26;j++){
        if(edge[t][j]){
           de[j]--;
             if(de[j]==0)
                  que.push(j);
        }}

   }
   for(int i=0;i<26;i++)
    if(de[i]) return 0;
return 1;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
        mem(edge,0);
        mem(de,0);
        mem(id,0);
    for(int i=0;i<n;i++)
        cin>>s[i];
        int tot=1;
        int flag=1;
    for(int i=0;i<n-1;i++){
           int j=i+1;
           int k=0;
           while(k<min(s[i].size(),s[j].size())){
               if(s[i][k]!=s[j][k]){
                  edge[s[i][k]-'a'][s[j][k]-'a']=1;
                 break;
               }
               else k++;
           }
          if(k<s[i].size()&&k==s[j].size()) {flag=0;break;}

  }
  for(int i=0;i<26;i++)
   for(int j=0;j<26;j++)
      if(edge[i][j]){
         de[j]++;
   }
    tot=0;
      if(!flag||!top()) cout<<"Impossible"<<endl;
      else {
        for(int i=1;i<=26;i++)
            cout<<char(id[i]+'a');
        cout<<endl;
      }

}
}
