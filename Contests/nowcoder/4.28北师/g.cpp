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
char ans[200];
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int len=s.size();
    int flag=0;
    int cnt=0;
    //char ans[1000];
    int k=0;
    for(int i=0;i<len;i++)
    {
        if(i==0) {
                if(s[i]>='A'&&s[i]<='Z') ans[k++]=s[i]-'A'+'a';
                else ans[k++]=s[i];
        continue;}
        if(i==1&&s[i]>='A'&&s[i]<='Z') {flag=1;break;}
        if(i!=0&&s[i]>='A'&&s[i]<='Z') {
            cnt++;
            ans[k++]='_';
            ans[k++]=s[i]-'A'+'a';
           if(i>=len-1||(s[i+1]>='A'&&s[i+1]<='Z')) {flag=1;break;}
        }
        else ans[k++]=s[i];
    }
    ans[k]='\0';
    if(flag==0&&cnt) cout<<ans<<endl;
    else cout<<s<<endl;
  }
}
