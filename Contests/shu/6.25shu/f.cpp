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
string T,S;
int nex[400100];
void getNext()
{
    int j, k;
    j = 0; k = -1;
    nex[0] = -1;
    while(j < T.size())
        if(k == -1 || T[j] == T[k])
            nex[++j] = ++k;
        else
            k = nex[k];

}
int main(){

  while(cin>>T){
    getNext();
    int len=T.size();
  int i=len;
  priority_queue<int,vector<int>,greater<int> >que;
  que.push(len);
  while(nex[i]>0){
     que.push(nex[i]);
     i=nex[i];
   // cout<<i<<endl;
  }
  while(!que.empty()){
     int e=que.top();
     que.pop();
     cout<<e<<" ";

  }
  cout<<endl;
    }

  }

