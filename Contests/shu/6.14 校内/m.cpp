#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mem(a,x) memset(a,x,sizeof(a))
#define TEST
using namespace std;
typedef long long LL;

const LL INV = -500000003;
const LL MOD = 1E9+7;
const int MAXN = 220000;
LL arr[MAXN];
LL inv[MAXN];
LL f[MAXN];

LL extendGcd(LL a, LL b, LL &x, LL &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL res = extendGcd(b, a%b, x, y);
    LL temp = x;
    x = y;
    y = temp - a/b*y;
    return res;
}

LL quickPowerMod(LL n, LL r) {
    LL res = 1;
    n = n%MOD;
    while(r) {
        if(r&1) {
            res = res*n%MOD;
        }
        n = n*n%MOD;
        r >>= 1;
    }
    return res;
}

LL inverse(LL a, LL mod) {
    /*
    LL x, y;
    extendGcd(a, mod, x, y);
    return x;
    */
    return quickPowerMod(a, mod - 2);
}

int main() {
/*#ifdef TEST
    LL dpz[20][20];
    mem(dpz, 0);
    dpz[0][0] = 1;
    printf("0    %7d\n",1);
    for(int i = 1; i < 20; i++) {
        printf("%d    ",i);
        for(int j = 0; j <= i; j++) {
            dpz[i][j] = dpz[i-1][(int)abs(j-1)] + dpz[i-1][j+1];
            printf("%7d", dpz[i][j]);
        }
        putchar('\n');
    }
#endif // TEST
#ifndef TEST*/
    arr[0] = 1;
    inv[0] = 1;
    f[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        arr[i] = (arr[i-1]*INV%MOD+MOD)%MOD;
        inv[i] = inv[i-1]*inverse(i, MOD)%MOD;
        f[i] = f[i-1]*i%MOD;
    }
    int t, n, m, temp;
    LL ans;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        n = abs(n);
        if((n%2 == m%2)&&(n <= m)) {
            temp = (m - n)/2;
            ans = arr[m];
            if(temp > 0)
                ans = ((ans*inv[temp]%MOD)*(f[m]-f[m-temp+1])%MOD+MOD)%MOD;
            cout<<ans<<endl;
        }
        else {
            cout<<0<<endl;
        }
    }
#endif // TEST
    return 0;
}
