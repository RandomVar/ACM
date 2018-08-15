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
 3    freopen("data.out","w",stdout);
    #endif
*/
string s[1100];
//vector<int>edge[1100];
int vis[1100];
int pre[1100];
int n;
int nextx[1100];
int mapx[1100][1100];
int path[1100];
bool flag;

void hamidun()
{

        memset(nextx,-1,sizeof(nextx));
        int head=0;
        for(int j=1;j<n;j++)
        {
        
            if(mapx[j][head]==1)
            {
                nextx[j]=head;
                head=j;
            }//不断向后添加路径
            else
            {
                int pre=head,pos=nextx[head];
                while(pos!=-1&&mapx[pos][j]==1)
                {
                    pre=pos;
                    pos=nextx[pre];
                }//找到后，路径为pre→j→pos
                nextx[pre]=j;
                nextx[j]=pos;
            }
        }
        //head=0;
        int k=1;
        //cout<<head<<endl;
        for(int j=head;j!=-1;j=nextx[j])
           { 
               path[k++]=j;
               if(nextx[j]==-1||mapx[j][nextx[j]]!=1) break;
           }
       /* cout<<k<<endl;
        for(int i=1;i<k;i++)
           cout<<path[i]<<" ";
           cout<<endl;
           */
    if(k<=n) cout<<"impossible"<<endl;
    else {
        for(int i=1;i<k;i++)
           cout<<path[i]<<" ";
           cout<<endl;
    }
}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(cin>>n)
  {  
     
    mem(mapx,0);
      //flag=false;
      for(int i=0;i<n;i++)
        {
            cin>>s[i];
           for(int j=0;j<n;j++){
               if(s[i][j]=='0')
                 mapx[i][j]=1;
           }
        }
       hamidun();
    
 /* if(!flag) 
    cout<<"impossible"<<endl;
  else {
     for()
  }*/
  }
return 0;

  }

