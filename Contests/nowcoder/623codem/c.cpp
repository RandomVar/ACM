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
    string n;
    while(cin>>n){
            int ans1=0;int ans2=0;
            int flag=0;
        for(int i=1;i<n.size();i++)
           if(n[i]=='1') ans1++;
       for(int i=1;i<n.size();i++){
          if(flag) ans2++;
          else if(n[i]=='1') {flag=1;}

       }
       ans1=max(ans1,ans2);
       int x=n.size();
       ans1+=x*(x-1)/2;
       if(x==1&&n[0]=='1') cout<<1<<endl;
       else cout<<ans1<<endl;
    }
    return 0;
}
