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
struct node{
  int x,y;

}a[20],b[20];
int v1[20][20],v2[20][20];
int c1[20],c2[20];
int main(){
 int n,m;
 while(cin>>n>>m){
        memset(v1,0,sizeof(v1));
       memset(v2,0,sizeof(v2));
       memset(c1,0,sizeof(c1));
       memset(c2,0,sizeof(c2));
     for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i].x=x;
        a[i].y=y;
        c1[x]++;
        c1[y]++;
        v1[x][y]++;
        v1[y][x]++;
     }
     for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        b[i].x=x;
        b[i].y=y;
        c2[x]++;
        c2[y]++;
        v2[x][y]++;
        v2[y][x]++;
     }
     int flag=1;int f=1;
     int ans=-1;
     for(int i=0;i<n;i++){

        int x=a[i].x;int y=a[i].y;
       // if(c2[x]-v2[x][y]>1)
        //f=-1;
        //else if(c2[y]-v2[x][y]>1)
        //  f=-1;
        if((c2[x]-v2[x][y])&&(c2[y]-v2[x][y]))
            f=-1;
        else if((c2[x]-v2[x][y])||(c2[y]-v2[x][y]))
            {
             flag--;
             if(c2[x]-v2[x][y]) ans=x;
             else ans=y;
            }
          if(f==-1) break;
     }
     if(f!=-1){
            int flag2=1;
        for(int i=0;i<m;i++){

        int x=b[i].x;int y=b[i].y;
        //if(c1[x]-v1[x][y]>1)
       // f=-1;
        //else if(c1[y]-v1[x][y]>1)
          //f=-1;
        if((c1[x]-v1[x][y])&&(c1[y]-v1[x][y]))
            f=-1;
        else if((c1[x]-v1[x][y])||(c1[y]-v1[x][y])){
            flag2--;
             if(c1[x]-v1[x][y]) ans=x;
             else ans=y;
        }
          if(f==-1) break;
     }
     flag=min(flag,flag2);
     }
     if(f==-1)
          cout<<f<<endl;
    else if(flag<0) cout<<0<<endl;
    else cout<<ans<<endl;

 }
return 0;
}
