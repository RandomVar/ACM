#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    while(cin>>x)
    {
    unsigned seed=chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    cout<<generator()<<endl;
    }
}