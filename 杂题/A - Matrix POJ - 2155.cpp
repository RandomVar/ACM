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
int tree[1010][1010];
int n;
int lowbit(int x){
return x&(-x);
}

void add(int x,int y){
   for(int i=x;i<=n;i+=lowbit(i))
    for(int j=y;j<=n;j+=lowbit(j))
       tree[i][j]++;
}

int sum(int x,int y){
   int ret=0;
   for(int i=x;i>0;i-=lowbit(i))
     for(int j=y;j>0;j-=lowbit(j))
       ret+=tree[i][j];
   return ret;
}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int x;
  cin>>x;
  while(x--){
     int t;
     cin>>n>>t;
     mem(tree,0);
     for(int i=0;i<t;i++){
        char a[5];
       cin>>a;
        //cout<<a<<endl;
        if(a[0]=='C'){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            //cout<<x1<<endl;
            add(x1,y1);
            add(x2+1,y2+1);
            add(x1,y2+1);
            add(x2+1,y1);

        }
        else if(a[0]=='Q'){
            int xx,y;
            cin>>xx>>y;
          //  cout<<xx<<endl;
           if(sum(xx,y)%2) cout<<1<<endl;
           else cout<<0<<endl;

        }
     }
     if(x) cout<<endl;
  }

  return 0;
}
