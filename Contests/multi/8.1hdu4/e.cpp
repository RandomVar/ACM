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
int A[]={1,10,100};
int M[50][50];
int main(){
    int cursor=0;
    int L=3;
    int cnt=0;
 //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  for (int i = 0; i<20; ++i) {
    for (int j = 0; j <= i; ++j) { 
        M[j][i - j] = (++cnt)%8;
        //A[cursor];
       // cursor = (cursor + 1) % L;
    }
}  
  for(int i=0;i<20;i++)
  {
     for(int j=0;j<20;j++)
     printf("%5d",M[i][j]);
         //  cout<<M[i][j]<<" ";
           cout<<endl;
  }
  int t;
  cin>>t;

 return 0;
  }

