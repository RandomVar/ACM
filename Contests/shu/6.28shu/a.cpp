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
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t,s,x;
    while(cin>>t>>s>>x){
        if(x==t) {cout<<"YES"<<endl;continue;}
        if(x<(s+t)) {cout<<"NO"<<endl;continue;}
        if((x-t)%s==0) cout<<"YES"<<endl;
        else if((x-t)%s==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }


}
