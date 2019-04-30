#include<bits/stdc++.h>
using namespace std;
 int mp[4][4]={1,4,2,5,2,1,2,1,3,1,3,2,2,5,3,4};
 int can[4][4];
 int result;
 void dfs(int st,int ans)
 {
  //  cout<<st<<" "<<ans<<endl;
  //  int flag=0;
  //  for(int i=0;i<4;i++)
  //   for(int j=0;j<4;j++)
  //     if(can[i][j]!=2) flag=1;
  //   if(flag==0)
  //   {
  //     // cout<<ans<<endl;
  //       result=max(result,ans);
  //       return;
  //   }
    if(st==8)
    {
      result=max(result,ans);
      return;
    }
   for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
     {
       for(int p=0;p<4;p++)
         for(int q=0;q<4;q++)
         {
           if(p==i&&q==j) continue;
           if(mp[i][j]==mp[p][q]&&can[i][j]==1&&can[p][q]==1)
              {
                int ji[8]={0};
                if(i-1>=0&&!can[i-1][j]) can[i-1][j]=1,ji[0]=1;
                if(i+1<4&&!can[i+1][j]) can[i+1][j]=1,ji[1]=1;
                if(j-1>=0&&!can[i][j-1]) can[i][j-1]=1,ji[2]=1;
                if(j+1<4&&!can[i][j+1]) can[i][j+1]=1,ji[3]=1;
                
                if(p-1>=0&&!can[p-1][q]) can[p-1][q]=1,ji[4]=1;
                if(p+1<4&&!can[p+1][q]) can[p+1][q]=1,ji[5]=1;
                if(q-1>=0&&!can[p][q-1]) can[p][q-1]=1,ji[6]=1;
                if(q+1<4&&!can[p][q+1]) can[p][q+1]=1,ji[7]=1;
                can[i][j]=2;
                can[p][q]=2;
              dfs(st+1,ans+mp[i][j]*st);
            if(ji[0]) can[i-1][j]=0;
            if(ji[1]) can[i+1][j]=0;
            if(ji[2]) can[i][j-1]=0;
            if(ji[3]) can[i][j+1]=0;
            if(ji[4]) can[p-1][q]=0;
            if(ji[5]) can[p+1][q]=0;
            if(ji[6]) can[p][q-1]=0; 
            if(ji[7]) can[p][q+1]=0;
                can[i][j]=1;
                can[p][q]=1;
              }
           }
     }
 }
int main()
{
  freopen("b.out","w",stdout);
  result=0;
  for(int i=0;i<4;i++)
   for(int j=0;j<4;j++)
     if(i==0||i==3||j==0||j==3) can[i][j]=1;
   dfs(1,0);
   cout<<result<<endl;
}