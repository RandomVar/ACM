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
   int a,b,c,n;
   while(cin>>a>>b>>c>>n){
      if(c>min(a,b)) cout<<-1<<endl;
      else if(max(a,b)>n-1) cout<<-1<<endl;
      else if(a+b-c<n){
        cout<<n-(a+b-c)<<endl;
      }
        else if(a+b-c>=n){
            cout<<-1<<endl;
        }

   }
}
