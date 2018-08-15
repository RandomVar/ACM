#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5;
char s[maxn+10];
int main(){
   int n,a,b;
   while(cin>>n>>a>>b){
      cin>>s;int sa=a;int sb=b;
      int cnt=0;
      for(int i=0;i<n;i++){
        if(s[i]=='*'){
          if(cnt){
            if(cnt%2==0) {
                sa-=cnt/2;
                sb-=cnt/2;
            }
            else{
                sa-=cnt/2;
                sb-=cnt/2;
                if(sa>sb) sa-=1;
                else sb-=1;
            }
          }
          cnt=0;
        }
        else cnt++;
      }
      if(cnt){
        if(cnt%2==0) {
                sa-=cnt/2;
                sb-=cnt/2;
            }
            else{
                sa-=cnt/2;
                sb-=cnt/2;
                if(sa>sb) sa-=1;
                else sb-=1;
            }
      }
      if(sa<0) sa=0;
      if(sb<0) sb=0;
     // cout<<sa<<sb;
      cout<<a+b-sa-sb<<endl;
   }

}
