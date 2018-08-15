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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
int a[101000];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   int n;
   while(cin>>n){
     for(int i=1;i<=n;i++)
        cin>>a[i];
    int x1=-1;int x2=-1;
    int c1=0;int c2=0;
   int cnt=0;int ans=0;
     x1=a[1];c1=1;
     for(int i=2;i<=n;i++){
         if(a[i]==x1) c1++;
         else if(c2==0&&(a[i]==x1+1||a[i]==x1-1))
              {
                  x2=a[i];

                  c2=1;
              }
               else if(c1==0&&(a[i]==x2+1||a[i]==x2-1))
              {
                  x1=a[i];c1=1;
              }
        else if(a[i]==x2) c2++;
        else{
            if(a[i-c1-c2]==x1) c1--;
            else c2--;
            if(c1==0) x1=-1;
            if(c2==0) x2=-1;
            i--;
        }
        ans=max(ans,c1+c2);
      //  cout<<ans<<endl;
    }
        cout<<ans<<endl;


   }

}
