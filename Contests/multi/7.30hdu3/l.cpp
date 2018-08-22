#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
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
const int inf=0x3f3f3f3f;
const ll INF= 0x3f3f3f3f3f3f3f3f;
/*
 #ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
     freopen("data.out","w",stdout);
    #endif
*/
char mp[100][100];
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
      
       int a,b,c;
       cin>>a>>b>>c;
        int numx=2*c+1+2*b;
        int numy=2*a+1+2*b;
       for(int i=0;i<2*b;i++)
       {
           for(int j=0;j<2*b-i;j++)
             mp[i][j]='.';
       }
       for(int i=numx-1;i>numx-1-2*b;i--){
          int k=0;
         for(int j=numy-k-1;k<2*b&&j>=0;j--,k++)
             mp[i][j]='.';
       }

       for(int i=0;i<2*b;i++)
       {
           int s=2*b-i;
           if(i%2==0)
           {
           
           for(int j=0;j<2*a+1;j++)
             {
                 if(j%2) mp[i][s+j]='-';
                 else mp[i][s+j]='+';
             }
           }
           else{
               for(int j=0;j<2*a+1;j++)
             {
                 if(j%2) mp[i][s+j]='.';
                 else mp[i][s+j]='/';
             }
           }
       }
       for(int i=0;i<2*c+1;i++)
       {
           int s=2*b;
           if(i%2==0)
           {
               for(int j=0;j<2*a+1;j++)
               {
                   if(j%2==0) mp[i+s][j]='+';
                   else mp[i+s][j]='-'; 
               }
           }
           else{
               for(int j=0;j<2*a+1;j++)
               {
                   if(j%2==0) mp[i+s][j]='|';
                   else mp[i+s][j]='.';
               }
           }
       }
     
       for(int j=0;j<2*b;j++)
       {
           int s=2*a+1;
           if(j%2==0)
           {
               int k=0;
           for(int i=2*b-j;i<numx-j-1;i++)
           {
               if(k%2==0)
                  mp[i][j+s]='.';
                else mp[i][j+s]='/';
              k++;
           }
           }
           else if(j%2)
           {
               int k=0;
               for(int i=2*b-j;i<numx-j-1;i++)
               {
                   if(k%2==0)
                     mp[i][j+s]='|';
                    else mp[i][j+s]='+';
                    k++;
               }
           }

       }


     for(int i=0;i<numx;i++){
       for(int j=0;j<2*a+1+2*b;j++)
         cout<<mp[i][j];
       cout<<endl;
     }
        

   }

 return 0;
  }

