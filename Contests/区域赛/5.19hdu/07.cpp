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
vector<int>c1;
vector<int>c2;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string a,b;
    while(cin>>a>>b){
        c1.clear();
        c2.clear();
            int flag=1;
            c1.push_back(-1);
            c2.push_back(-1);
         for(int i=0;i<a.size();i++)
            if(a[i]=='c')  c1.push_back(i);
         for(int i=0;i<b.size();i++)
            if(b[i]=='c') c2.push_back(i);
         if(c1.size()!=c2.size()) flag=0;
         else{
        // int num=c1.size();
         c1.push_back(a.size());
         c2.push_back(b.size());
         for(int i=0;i<c1.size()-1;i++){
              int num1a=0,num1b=0,num2a=0,num2b=0;
             for(int j=c1[i]+1;j<c1[i+1];j++){
                 if(a[j]=='a') num1a++;
                else num1b++;
             }
             for(int j=c2[i]+1;j<c2[i+1];j++){
                 if(b[j]=='a') num2a++;
                 else num2b++;

             }
           //  cout<<num1a<<" "<<num2a<<" "<<num1b<<" "<<num2b;
             if(abs(num2a-num1a)%2==1) {flag=0;break;}
             if(abs(num2b-num1b)%2==1) {flag=0;break;}
         }
         }
         if(flag) cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
    }

}
