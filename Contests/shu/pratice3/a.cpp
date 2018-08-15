#include<bits/stdc++.h>
using namespace std;
int main(){

  int n;
  while(scanf("%d",&n)==1){
    for(int i=0;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        double ans=0.01*x*y+(1-0.01*x)*z;
        printf("%.1lf\n",ans);
    }

  }
}
