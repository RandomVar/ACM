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
int a[110];
int main(){
  int n;
  while(cin>>n){
     double sum=0;
     for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
     }
     if(sum>=4.5*n) {cout<<0<<endl;continue;}
     sort(a,a+n);
     int cnt=0;
     for(int i=0;i<n;i++)
    {
        sum+=5-a[i];
        cnt++;
        if(sum>=4.5*n) {cout<<cnt<<endl;break;}

    }
  }

}
