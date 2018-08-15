#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
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
 string s;
 int cnt1=0;int cnt2=0;
 cin>>s;
 for(int i=0;i<s.size();i++){
    if(s[i]=='-') cnt1++;
    else cnt2++;
 }
  if(cnt2==0) cout<<"YES"<<endl;
  else if(cnt1%cnt2==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
