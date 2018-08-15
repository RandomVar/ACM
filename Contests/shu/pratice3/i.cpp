#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
 int n;
 cin>>n;
 while(n--){
    for(int i=1;i<=5;i++)
      cin>>a[i];
    if(a[2]-a[1]==a[3]-a[2]){
        a[6]=a[5]+a[2]-a[1];
    }
    else{
        a[6]=a[5]*(a[2]/a[1]);
    }
    for(int i=1;i<6;i++)
        cout<<a[i]<<" ";
    cout<<a[6]<<endl;
 }
return 0;
}
