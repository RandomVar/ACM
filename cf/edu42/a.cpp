#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
  int n;
  while(cin>>n){
        long long cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
       cnt+=a[i];
  }
  long long ans=0;int index=0;
     for(int i=0;i<n;i++){
        ans+=a[i];
        if(ans>=(cnt+1)/2)  {index=i;break;}
     }
  cout<<index+1<<endl;
}
}
