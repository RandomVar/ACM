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
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int flag=1;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s!="PERFECT") flag=0;
    }
    if(flag) cout<<"MILLION Master"<<endl;
    else cout<<"NAIVE Noob"<<endl;
  }

}
