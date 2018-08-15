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
vector<int>cnt[30];
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int cmp(string x,string y){
return x>y;
}
int main(){
    string s;
   while(cin>>s){
        for(int i=0;i<30;i++)
          cnt[i].clear();
        int len=s.size();
        for(int i=0;i<len;i++){
           cnt[s[i]-'a'].push_back(i);
        }
        int pre=-1;
        for(int i=25;i>=0;i--){
            for(int j=0;j<cnt[i].size();j++){
                if(pre<cnt[i][j]) {cout<<char('a'+i);
                pre=cnt[i][j];}
            }
        }
   cout<<endl;
  }
  return 0;
  }
       // cout<<s;
    /*for(int i=0;i<30;i++)
        cnt[i]=-1;
    for(int i=0;i<strlen(s);i++){
       int t=s[i]-'a';
        if(cnt[t]==-1) {cnt[t]=i;}
    }
    for(int i=25;i>=0;i--){
        if(cnt[i]!=-1){
                cout<<cnt[i]<<endl;
            for(int j=cnt[i];j<strlen(s);j++)
                cout<<s[j];
            break;
        }}
        cout<<endl;
   }*/


