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
int main(){
  int n;
  while(cin>>n){
    int t=n;
    int flag=1;
    do{
        if(t%2!=0) {flag=0;break;}
        t=t/2;
    }while(t>1);
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

return 0;
}
