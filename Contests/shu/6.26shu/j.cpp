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
struct node{

    ll num;int b;
    int id;
   bool operator<(const node &c)const{
   // if(num==c.num) return b>c.b;
   return num>c.num;
   }
    }cnt[50];
string s[1100];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
		  res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin>>n){
        for(int i=0;i<50;i++){
         cnt[i].num=cnt[i].b=0;
         cnt[i].id=i;
        }


        for(int i=0;i<n;i++)
           cin>>s[i];
    for(int i=0;i<n;i++){
            int len=s[i].size();
      for(int j=0;j<len;j++){

          int t=s[i][j]-'a';
          if(j==0) cnt[t].b=1;

          cnt[t].num+=quick(10,len-j-1);
    }
  }
  ll ans=0;
     sort(cnt,cnt+11);
     priority_queue<int,vector<int>,greater<int> >que;
     for(int i=0;i<10;i++){
        que.push(i);
     }
     for(int i=0;i<10;i++){
            if(cnt[i].num!=0){
                int t=que.top();
                 if(t==0&&cnt[i].b==1) {
                    que.pop();
                    int x=que.top();
                    ans+=cnt[i].num*(ll)x;
                    que.pop();
                    que.push(0);
               //     cout<<cnt[i].id<<" "<<x<<endl;
                 }
                 else {
                        ans+=cnt[i].num*(ll)t;
                       que.pop();
                   //       cout<<cnt[i].id<<" "<<t<<endl;
                 }
     }
     }
   cout<<ans<<endl;
}
}
