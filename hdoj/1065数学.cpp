#include<cstdio>
#include<iostream>
using namespace std;
const double PI=3.1415926;
int main(){
	int n;cin>>n;int k=0;
	while(k<n){
		k++;
        double x,y;
        cin>>x>>y;
        double r=x*x+y*y;
        int d=PI*r/100+1;
        printf("Property %d: This property will begin eroding in year %d.\n",k,d);
	}
	printf("END OF OUTPUT.\n");
}
