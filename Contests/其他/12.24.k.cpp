#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c[10010];
int cmp(int a,int b){
return a>b;
}
int main(){
  int x,v;
  while(cin>>x>>v){
    int s=0;
    for(int i=0;i<x;i++){
      cin>>c[i];
      }
      sort(c,c+x,cmp);
      int k;
      for(k=0;k<x;k++){
        s+=c[k];
        if(s>=v) break;
      }
      if(k<x) cout<<k+1<<endl;
      else if(s>=v) cout<<x<<endl;
      else cout<<-1<<endl;
  }
}
