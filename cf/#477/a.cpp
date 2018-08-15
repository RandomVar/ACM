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
int main(){
  int n,s;
  while(cin>>n>>s){
        int xh,xs;
        cin>>xh>>xs;
         int flag=0;
         if(xh*60+xs-1>=s) {flag=1;cout<<"0 0"<<endl;}
    for(int i=1;i<n;i++){
        int h,ss;
        cin>>h>>ss;
        if(!flag&&((h-xh)*60+(ss-xs)-2)>=(2*s)){

            flag=1;
            int aa=xh*60+xs+s+1;
            cout<<(aa/60)<<" "<<(aa%60)<<endl;
        }
        xh=h;xs=ss;
    }
    if(!flag) {
        int aa=xh*60+xs+s+1;
            cout<<aa/60<<" "<<aa%60<<endl;
    }
    //cout<<flag<<endl;
  }

return 0;
}
