#include<string>
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
int cnt1[30];
int cnt2[30];
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    mem(cnt1);
    mem(cnt2);
    int len=s.size();
    int cnt=0;
    for(int i=0;i<len;i++){
       if(i%2==0) cnt1[s[i]-'a']++;
       else cnt2[s[i]-'a']++;
    }
    int i1;int i2;
    int a1=0;int a2=0;
    for(int i=0;i<26;i++){
        if(a1<cnt1[i]){a1=cnt1[i];i1=i;}
        if(a2<cnt2[i]){a2=cnt2[i];i2=i;}
    }
    cout<<len-a1-a2<<endl;
  }
  return 0;
  }



