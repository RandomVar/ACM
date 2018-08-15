#include<bits/stdc++.h>
using namespace std;
string x[]={"purple","green","blue","orange","red","yellow"};
string y[]={"Power","Time","Space","Soul","Reality","Mind"};
int cnt[10];
int main(){
   int n;
   while(cin>>n){
        memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<6;j++)
            if(x[j]==s)
               cnt[j]++;
    }
   cout<<6-n<<endl;;
    for(int i=0;i<6;i++)
        if(!cnt[i])
           cout<<y[i]<<endl;
   }


return 0;
}
