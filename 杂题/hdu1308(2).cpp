#include<string>
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb(x) push_back(x)
#define fir first
#define sec second
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
//freopen("data.in","r",stdin);
//freopen("data.out","w",stdout);
//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int moday[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
string mo[]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
string d[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int month,day,year;
int judgerun(int y){
  if(y>1582){
           if(y%400==0) return 1;
            else if(y%100==0) return 0;
            else if(y%4==0) return 1;
          return 0;
  }
  if(y%4==0) return 1;
  return 0;
}
int hefa(){
  if(year<=0||month<=0||month>12||day<=0) return 0;
  if(day>moday[month]) return 0;
  if(!judgerun(year)&&day>28) return 0;
  if(year==1752&&month==9&&day>2&&day<14)
    return 0;
  return 1;
}
int main(){

  while(cin>>month>>day>>year){
         if(!month&&!day&&!year) break;
          int days=0;int flag=1;
         days=day-1;
         if(year<1752||(year==1752&&month<9)||(year==1752&&month==9&&day<=2))
              days=(days+11)%7;

    if(year>=2000){
      for(int i=2000;i<year;i++){
          if(judgerun(i)) days=(days+366)%7;
          else days=(days+365)%7;
      }
       for(int i=1;i<month;i++){
            if(i!=2) days=(days+moday[i])%7;
           else{
             if(judgerun(year)) days=(days+29)%7;
             else days=(days+28)%7;
           }
       }
    }
   else{
      for(int i=1999;i>=year;i--){
         if(judgerun(i)) days=(days-366%7+7)%7;
          else days=(days-365%7+7)%7;
      }
       for(int i=1;i<month;i++){
         if(i!=2) days=(days+moday[i])%7;
           else{
             if(judgerun(year)) days=(days+29)%7;
             else days=(days+28)%7;
           }
        }
       }

    if(!hefa()) printf("%d/%d/%d is an invalid date.\n",month,day,year);
    printf("%s %d, %d is a %s\n",yue[mon],day,year,xingqi[tot_d % 7]);
        else
        cout<<day<<"/"<<month<<"/"<<year<<" is an invalid date."<<endl;
    else{
        cout<<mo[month]<<" "<<day<<", "<<year<<" is a "<<d[(days+5)%7]<<endl;
    }
  }
}
