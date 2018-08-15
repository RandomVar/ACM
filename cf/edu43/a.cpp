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
    int n;
    while(cin>>n){
        string s;
        cin>>s;
        int cnt=0;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') cnt++;
            if(s[i]=='1') flag=1;
        }
        if(flag) {cout<<1;
          for(int i=0;i<cnt;i++)
            cout<<0;}
          else cout<<0;
          cout<<endl;
    }

return 0;
}
