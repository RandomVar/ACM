#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll b[30];
int vis[30];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    memset(b,0,sizeof(b));
    memset(vis,0,sizeof(vis));
    int n,m;
    cin>>n>>m;
    ll ans=0;
    //getchar();
    int cnt=0;
    for(int i=1;i<=m;i++){
          ll a=0;

            string s1,s2,s3;
        string s;
        //getline(cin,s);
        //stringstream ss(s);
        //ss>>s1;
        cin>>s1>>s2>>s3;
          //getchar();
        //cout<<s1<<endl;
        //cout<<s2<<endl;
       //cout<<s3<<endl;
       a=s1[2]-'0';
       a*=10;
       a+=s1[3]-'0';
        //ss>>s2;
//cout<<a<<endl;
        //ss>>s3;
        if(s3=="AC"&&!vis[a]){
              //  cout<<1<<endl;
          b[a]+=((s2[0]-'0')*10+(s2[1]-'0'))*60;
           b[a]+=(s2[3]-'0')*10+s2[4]-'0';
            ans+=b[a];
            cnt++;
            vis[a]=1;
        }
        else if(s3!="AC"){
            b[a]+=20;
        }

    }
    cout<<cnt<<" "<<ans<<endl;
  }
return 0;
}
