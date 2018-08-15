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
string mo[]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
string d[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main(){
  int month,day,year;
  while(cin>>month>>day>>year){
         if(!month&&!day&&!year) break;
          int days=0;int flag=1;
         if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
         {
             if(day>31) flag=0;
         }
         else if(month==2){
          if(year>1582){
            if(year%400==0) if(day>29) flag=0;
            else if(year%100==0) if(day>28) flag=0;
            else if(year%4==0) if(day>29) flag=0;
            else if(day>28) flag=0;
           }
           else {
             if(year%4==0) if(day>29) flag=0;
              else if(day>28) flag=0;
           }
         }
         else {
            if(day>30) flag=0;
         }
         days=day-1;
         if(year<1752||(year==1752&&month<9)||(year==1752&&month==9&&day<=2))
              days=(days+11)%7;
         if(year==1752&&month==9&&day>2&&day<14) flag=0;
         if(year<=0||month<=0||month>12||day<=0) flag=0;
    if(year>=2000){
      for(int i=2000;i<year;i++){
         if(i%400==0) days=(days+366)%7;
         else if(i%100==0) days=(days+365)%7;
         else if(i%4==0) days=(days+366)%7;
         else days=(days+365)%7;
      }
       for(int i=1;i<month;i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) days=(days+31)%7;
        else if(i==2) {
            if(year%400==0) days=(days+29)%7;
            else if(year%100==0) days=(days+28)%7;
            else if(year%4==0) days=(days+29)%7;
            else days=(days+28)%7;
        }
        else days=(days+30)%7;
       }
    }
    else if(year<=1582){
        for(int i=1999;i>=year;i--){
         if(i%4==0) days=(days-366%7+7)%7;
         else days=(days-365%7+7)%7;
      }
       for(int i=1;i<month;i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) days=(days+31)%7;
        else if(i==2) {
          if(year%4==0) days=(days+29)%7;
            else days=(days+28)%7;
        }
        else days=(days+30)%7;
       }
    }
   else{
      for(int i=1999;i>=year;i--){
         if(i%400==0) days=(days-366%7+7)%7;
         else if(i%100==0) days=(days-(365)%7+7)%7;
         else if(i%4==0) days=(days-366%7+7)%7;
         else days=(days-365%7+7)%7;
      }
       for(int i=1;i<month;i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) days=(days+31)%7;
        else if(i==2) {
            if(year%400==0) days=(days+29)%7;
            else if(year%100==0) days=(days+28)%7;
            else if(year%4==0) days=(days+29)%7;
            else days=(days+28)%7;
        }
        else days=(days+30)%7;
       }

   }
    if(flag==0) cout<<month<<"/"<<day<<"/"<<year<<" is an invalid date."<<endl;
    else{
        cout<<mo[month]<<" "<<day<<", "<<year<<" is a "<<d[(days+5)%7]<<endl;
    }
  }
}
