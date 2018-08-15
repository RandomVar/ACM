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
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
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
    int ind2=0;
    if(cnt){
    for(int i=9;i>=1;i--){
        if(cnt+a[index]>=a[i]){
            ind2=i;
            break;
        }
    }
        int x=1;
     for(x=1;x*(a[ind2]-a[index])<=cnt;x++)
          cout<<ind2;
    for(int i=x;i<n/a[index];i++)
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
