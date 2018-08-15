#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
char a[50][50];
char b[50][50];
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    getchar();
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
    getchar();}
    //getchar();
    string str;
    getline(cin,str);
   /* for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        cout<<a[i][j];
    }*/
    int nl=0;int nr=0;
    //for(int i=0;i<str.size();i++)
      //  cout<<str[i];
    for(int i=0;i<str.size();i++)
        if(str[i]=='L') nr++;
        else nl++;
    if(nr>nl) {nr-=nl;
    while(nr--){
      for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        if(a[i][j]=='|') a[i][j]='-';
        else if(a[i][j]=='-') a[i][j]='|';
        b[m-1-j][i]=a[i][j];

      }
      swap(n,m);
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        a[i][j]=b[i][j];
    }
    }
    else if(nr<nl){
        nl-=nr;
        while(nl--){
            for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
              if(a[i][j]=='|') a[i][j]='-';
              else if(a[i][j]=='-') a[i][j]='|';
                 b[j][n-1-i]=a[i][j];

      }
      swap(n,m);
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        a[i][j]=b[i][j];
        }
    }
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    cout<<endl;
  }
}
