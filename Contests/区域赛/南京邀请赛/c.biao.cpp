#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;
typedef long long ll;
const int maxn = 10000;
ll a[maxn];
int curI[maxn];
int binC[maxn];
int main() {
    ofstream fout;
    fout.open("1.txt");
    ll sum, temp, ans, len;
    sum = 0;
    ans = 0;
    memset(binC,0,sizeof(binC));
    for(int i = 1; i < maxn; i++) {
        temp = i;
        memset(curI,0,sizeof(curI));
        for(int j = 26; j >= 0; j--){
            fout<<binC[j];
        }
        fout<<endl;
        for(int j = 0; temp; j++){
            binC[j] += temp&1;
            curI[j] = (temp&1);
            temp >>= 1;
        }
        for(int j = 26; j >= 0; j--){
            fout<<curI[j];
        }
        fout<<endl;
        temp = sum;
        sum += i;
        len = 0;
        while(temp) {
            len++;
            temp >>= 1;
        }
        for(int j = 0; j <= len; j++){
            if(binC[j] >= 2){
                binC[j + 1] += binC[j]/2;
                binC[j] %= 2;
                ans++;
            }
        }
        for(int j = 26; j >= 0; j--){
            fout<<binC[j];
        }
        fout<<endl;
        fout<<ans<<endl;
    }
    return 0;
}
