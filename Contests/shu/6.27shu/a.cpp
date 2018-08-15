#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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

int main(){
  //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  while(cin>>n>>m){
        int flag=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++)
                cout<<'#';
        }
        else{
            if(flag==0){
                for(int j=0;j<m-1;j++)
                    cout<<'.';
                cout<<'#';
                flag=1;
            }
            else{
            cout<<'#';
            for(int j=0;j<m-1;j++)
                cout<<'.';
              flag=0;
            }

        }
        cout<<endl;
    }



  }
}
