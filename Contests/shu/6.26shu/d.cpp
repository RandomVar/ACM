#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<sstream>
#include<stack>
#include<algorithm>
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a,x) memset(a,x,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);

const int maxn=200100;
vector<int>vec[30];

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string s;
  while(cin>>s){
        int len=s.size();
        for(int i=0;i<30;i++)
        vec[i].clear();
     for(int i=0;i<s.size();i++){
          vec[s[i]-'a'].pb(i);
     }
        int m;
       cin>>m;
  stack<int>st;
  st.push(-1);
    for(int i=0;i<m;i++){
        string op;
        cin>>op;

        if(op=="push"){
            char c;
            cin>>c;
            int t=c-'a';
           //- cout<<t<<endl;
            int p1=upper_bound(vec[t].begin(),vec[t].end(),st.top())-vec[t].begin();
            //cout<<p1<<endl;
            if(p1!=vec[t].size())
                {
                    st.push(vec[t][p1]);
                    cout<<"YES"<<endl;
                }
              else {
                    st.push(len);
                    cout<<"NO"<<endl;
              }

        }
        else if(op=="pop"){
            if(!st.empty()){
                st.pop();
              if(st.top()==len) cout<<"NO"<<endl;
             else  cout<<"YES"<<endl;

            }
              else cout<<"NO"<<endl;
        }

    }


  }
  return 0;
}
