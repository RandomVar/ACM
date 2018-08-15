#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int maxn=1010;
int tree[maxn<<2][maxn<<2];
int n;
int low_bit(int x){
return x&(-x);
}

void add(int x,int y){
   for(int i=x;i<=n;i+=low_bit(i))
    for(int j=y;j<=n;j+=low_bit(j))
       tree[i][j]++;
}

int sum(int x,int y){
   int ret=0;
   for(int i=x;i>0;i-=low_bit(i))
     for(int j=y;j>0;j-=low_bit(j))
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
   // cout<<n<<t<<endl;
    memset(tree,0,sizeof(tree));
    int cnt=0;
    for(int i=0;i<t;i++){
        //getchar();
        char ch;
        cin>>ch;
        if(ch=='C'){
               // cout<<ch<<endl;
                int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            add(x1,y1);
            add(x2+1,y2+1);
            add(x1,y2+1);
            add(x2+1,y1);
        }
        else if(ch=='Q'){
            int xx,y;
            cin>>xx>>y;
             if(sum(xx,y)%2==0) cout<<0<<endl;
             else cout<<1<<endl;
        }
    }
    if(x) cout<<endl;
  }
return 0;
}
