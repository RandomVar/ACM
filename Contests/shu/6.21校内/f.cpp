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
double a[20];
double b[20];
int main(){
  double  n,m;
  while(cin>>n>>m){
        int x=0,y=0;
    for(int i=0;i<20;i++){
    char c;
     cin>>c;
    if(c=='a'||c=='A')  cin>>a[x++];
    else cin>>b[y++];
  }
  double ans1=0;double ans2=0;
  for(int i=0;i<10;i++){
      ans1+=a[i];
  }
  ans1=n/ans1;
  for(int i=0;i<10;i++)
    ans2+=b[i];
  ans2=m/ans2;
  double ans3=0;
  for(int i=0;i<10;i++){
      ans3+=n/a[i];
  }
  double ans4=0;
  for(int i=0;i<10;i++)
     ans4+=m/b[i];
     printf("Method 1\n");
     printf("African: %.2lf furlongs per hour\n",ans1*10);
     printf("European: %.2lf furlongs per hour\n",ans2*10);
     printf("Method 2\n");
     printf("African: %.2lf furlongs per hour\n",ans3/10.0);
     printf("European: %.2lf furlongs per hour\n",ans4/10.0);
  }
}
