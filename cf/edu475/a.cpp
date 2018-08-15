#include<bits/stdc++.h>
using namespace std;
int cnt[1000000];
int main(){
    int n;
    while(cin>>n){
        cout<<n/2+1<<endl;
    }
  /*for(int i=1;i<=100;i++){
    int ans=0;
    memset(cnt,0,sizeof(cnt));
    for(int j=1;j<=i;j++){
        if(cnt[i/j]==0) {cnt[i/j]=1;ans++;}
    }
    cout<<i<<":"<<ans<<endl;
  }
*/
}
/*int init(){
    memset(cnt,0,sizeof(cnt));int i;
    cnt[1]=1;cnt[2]=2;cnt[3]=4;cnt[4]=6;
    cnt[5]=8;cnt[6]=12;
    for(i=7;cnt[i-1]<1e9+5;i++){
        cnt[i]=cnt[i-1]+(i+1)/2;
    }
    return i;
}
int main(){
    int x=init();
    //for (int i=1;i<=30;i++)
      //  cout<<cnt[i]<<" ";
    //cout<<x<<endl;
    int n;
    while(cin>>n){
        int t=upper_bound(cnt,cnt+x,n)-cnt;
        cout<<t-1<<endl;
    }


  }*/


