#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
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
char mp[110][110];
int main(){
 int n,k;
 while(cin>>n>>k){

    cout<<"YES"<<endl;
    if(k%2==0){
          for(int j=0;j<n;j++){
            mp[0][j]=mp[3][j]='.';
            if(k==0||j==0||j==n-1) mp[1][j]=mp[2][j]='.';
            else {mp[1][j]=mp[2][j]='#';k-=2;}
        }
    }
    else if(k<=n-2){
        for(int j=0;j<n;j++)
          mp[2][j]=mp[0][j]=mp[3][j]='.';
        int t=(n-k)/2;
        for(int j=0;j<t;j++)
             mp[1][j]='.';
        for(int j=t;j<n-(n-k)/2;j++)
            mp[1][j]='#';
         for(int j=n-(n-k)/2;j<n;j++)
             mp[1][j]='.';
    }
    else{
        for(int j=0;j<n;j++){
          mp[0][j]=mp[3][j]='.';
          if(j==0||j==n-1) mp[1][j]='.';
          else mp[1][j]='#';
        }
        k=k-(n-2);
        for(int j=0;j<=n/2;j++){
            if(j==0||j==n/2) mp[2][j]=mp[2][n-j-1]='.';
            else if(k>0) {mp[2][j]=mp[2][n-j-1]='#';k-=2;}
            else mp[2][j]=mp[2][n-j-1]='.';
        }

    }
     for(int i=0;i<4;i++){
        for(int j=0;j<n;j++)
          cout<<mp[i][j];
       cout<<endl;
     }
   /* for(int i=0;i<4;i++){
       for(int j=0;j<n;j++){
         if(i==0||i==3) cout<<'.';
        else{
            if(k==0||j==0||j==n-1) cout<<'.';
            else {cout<<'#';k--;}
        }
       }
      cout<<endl;*/
       }
 }

