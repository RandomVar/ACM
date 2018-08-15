#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
string pla[]={"cinema","cocktail bar","disco","stay at the Hacienda"};
int cnt[4];
void cal(int i){
        if(i&1) cnt[0]++;
        if((i&1)&&(i&(1<<2))) cnt[0]++;
        if((i&(1<<1))&&((i&1)==0||(i&(1<<4))||(i&(1<<3)))){
            if((i&(1<<6))==0) cnt[1]++;
        }
        else if((i&(1<<1))&&(i&(1<<6))) cnt[2]++;
        if((i&(1<<6))){
          if(i&(1<<2)) cnt[2]++;
          else if(i&(1)) cnt[0]++;
          else cnt[1]++;
        }
        if(i&(1<<4)){
            if((i&1)&&(i&(1<<2))==0) cnt[1]++;
            else cnt[0]++;
        }
        if(i&(1<<5)){
            if((i&(1<<1))==0&&(i&1)==0) cnt[0]++;
            if(i&1) cnt[2]++;
        }
 }
  int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
            string s;
            int st=0;
        while(cin>>s){
            char ch=getchar();
            if(s[0]<='F'){ st|=(1<<(s[0]-'A'));}
            else st|=(1<<6);
             if(ch=='\n') break;
        }
        memset(cnt,0,sizeof(cnt));
        cal(st);
        //for(int j=0;j<3;j++)
        //    cout<<cnt[j]<<endl;
         cout<<"Scenario #"<<i+1<<":"<<endl;
        if(cnt[0]>cnt[1]&&cnt[0]>cnt[2]) cout<<pla[0]<<endl;
        else if(cnt[1]>cnt[0]&&cnt[1]>cnt[2]) cout<<pla[1]<<endl;
        else if(cnt[2]>cnt[0]&&cnt[2]>cnt[1]) cout<<pla[2]<<endl;
        else cout<<pla[3]<<endl;
        cout<<endl;
        }
    }
