#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
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
int cnt[1010];
string s[1010];
int main(){
  int n;
  while(cin>>n){
        set<int>st;
    for(int i=0;i<n;i++)
        cin>>s[i];
    mem(cnt);
    for(int i=0;i<n;i++)
       for(int j=0;j<s[i].size();j++){
          cnt[i]|=(1<<(s[i][j]-'a'));
    }
    int ans=0;
    for(int i=0;i<n;i++){
        st.insert(cnt[i]);
    }
    cout<<st.size()<<endl;
  }

return 0;
}
