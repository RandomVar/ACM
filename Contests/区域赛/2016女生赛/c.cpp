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
int a[110];
int main(){
   int t;
   cin>>t;
   while(t--){
        int n;
     cin>>n;
     int sum=0;
     for(int i=0;i<n-1;i++){
         cin>>a[i];
         sum+=a[i];
     }
     int x=(sum*2)/(3*n-2);
     cout<<x<<" ";
     int cnt=1;
     for(int i=0;i<n-1;i++){
        if(a[i]==x) cnt++;
     }

     printf("%.2lf\n",double(1.0/cnt));
     //cout<<(double)(1.0/cnt)<<endl;
   }
   return 0;
}


