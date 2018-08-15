#include<bits/stdc++.h>
using namespace std;
int a[20];
int b[20];
vector<int>vec;
int main(){
   int n,m;
   while(cin>>n>>m){
        vec.clear();
        memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        b[t]=i;
    }
    for(int i=1;i<=n;i++){
        if(b[a[i]]){
            vec.push_back(a[i]);
        }
    }
   if(vec.size()==0) cout<<endl;
   else{
    for(int i=0;i<vec.size()-1;i++)
        cout<<vec[i]<<" ";
    cout<<vec[vec.size()-1]<<endl;
   }
   }


return 0;
}
