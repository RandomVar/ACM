#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;

LL f(LL n) {
    while(n >= 20180001) {
        n = f(n - 2018);
    }
    return n + 2017;
}

int main() {
    LL t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<f(n)<<endl;
    }
    return 0;
}
