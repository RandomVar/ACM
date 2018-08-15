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
int a[15];
int main(){
   //freopen("data.in","r",stdin);
   //freopen("data.out","w",stdout);
  int n;
  while(cin>>n){
        int flag=0;
    for(int i=1;i<=9;i++){
        cin>>a[i];
        if(n>=a[i]) flag=1;
    }
    /*int maxa=0;int index=0;
    for(int i=1;i<=9;i++){
        if(maxa<=n/a[i]){
            maxa=n/a[i];
            index=i;
        }
    }*/
    if(flag==0) cout<<-1<<endl;
  else{
    int maxa=0;int index=0;
    for(int i=1;i<=9;i++){
        if(maxa<=n/a[i]){
            maxa=n/a[i];
            index=i;
        }
    }
    int cnt=n-n/a[index]*a[index];

    if(cnt){
        int res=n-(n/a[index]-cnt)*a[index];
        int resdig=cnt;
        while(res&&resdig&&res>resdig*a[index]){
              int ind2=0;
            for(int i=9;i>=1;i--){
             if(resdig+a[index]>=a[i]){
               ind2=i;
               break;
            }
           }
           if(ind2==0) break;
            int x=0;
            //cout<<resdig<<endl;
            if(ind2!=index) x=cnt/(a[ind2]-a[index]);
            else break;
           for(int i=1;i<=x;i++)
             cout<<ind2;
          resdig-=x;
          res-=x*a[ind2];
        }
        //cout<<resdig<<endl;
         for(int i=0;i<n/a[index]-cnt+resdig;i++)
          cout<<index;


    }

    else{
        for(int i=0;i<n/a[index];i++)
        cout<<index;
    }
    cout<<endl;

  }
 }
  return 0;
}
