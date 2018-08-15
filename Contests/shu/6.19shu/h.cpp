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
string s[55];
int main(){
  int t;
  cin>>t;
  while(t--){
     int n,m;
     scanf("%d%d",&n,&m);
    // cin>>n>>m;
     for(int i=0;i<n;i++)
        cin>>s[i];
        int cnt=0;int ans=0;
    for(int i=1;i<n-1;i++){
        if(s[i][0]=='0') cnt++;
        if(s[i][m-1]=='0') cnt++;
    }
    for(int j=1;j<m-1;j++){
         if(s[0][j]=='0') cnt++;
         if(s[n-1][j]=='0') cnt++;
    }
    if(s[0][0]=='0') cnt++;
    if(s[0][m-1]=='0') cnt++;
    if(s[n-1][0]=='0') cnt++;
    if(s[n-1][m-1]=='0') cnt++;
     for(int i=1;i<n-1;i++)
       for(int j=1;j<m-1;j++){
          if(s[i][j]=='1'){
              ans++;
          }
       }
       //cout<<cnt<<" "<<ans<<endl;
        if(ans<cnt) printf("-1\n");
        else printf("%d\n",cnt);

     }

  }

