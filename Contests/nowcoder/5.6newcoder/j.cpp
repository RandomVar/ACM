
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9+5;
const int MAXN = 100;
const int MOD = 1e9+7;
const double eps = 1e-7;
const double PI = acos(-1);
using namespace std;

int Scan_Int()///输入外挂
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
void Out(LL a)///输出外挂
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}
int n;
int equ, var;///equ个方程 var个变量
int a[MAXN][MAXN];///增广矩阵
int x[MAXN];///解集
int x_i[MAXN];
bool free_x[MAXN];///判断是不是自由变元
int free_num;///自由变元的个数
int Gauss()
{
    int Max_r;///当前列绝对值最大的存在的行
    ///col：处理当前的列
    int row,col = 0;
    int free_x_num;
    int free_index;
    free_num = 0;
    for(int i=0; i<=var; i++)
    {
        x[i] = 0;
        free_x[i] = 1;
    }
    for(row=0; row<equ&&col<var; row++,col++)
    {
        Max_r = row;
        for(int i=row+1; i<equ; i++)
            if(abs(a[i][col]) > abs(a[Max_r][col]))
                Max_r = i;
        if(a[Max_r][col] == 0)
        {
            free_x[col] = 1;
            x_i[free_num++] = col;
            row--;
            continue;
        }
        if(Max_r != row)
            for(int i=col; i<var+1; i++)
                swap(a[row][i], a[Max_r][i]);
        ///消元
        for(int i=row+1; i<equ; i++)
            if(a[i][col])
                for(int j=col; j<var+1; j++)
                    a[i][j] ^= a[row][j];
    }
    for(int i=row; i<equ; i++)
        if(a[i][col])
            return -1;///无解
    ///保证对角线主元非 0
    for(int i=0;  i<equ; i++)
    {
        if(!a[i][i])
        {
            int j;
            for(j=i+1; j<var; j++)
                if(a[i][j])
                    break;
            if(j == var)
                break;
            for(int k=0; k<equ; k++)
                swap(a[k][i], a[k][j]);
        }
    }
    if(row < var)
        return var - row;///自由变元的个数
    ///回代，得到解集
    for(int i=var-1; i>=0; i--)
    {
        x[i] = a[i][var];
        for(int j=i+1; j<var; j++)
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;///唯一解
}
void Debug()
{
    puts("");
    cout<<"+++++++++++++++++++++++++++分界线++++++++++++++++++++++++++++++"<<endl;
    for(int i=0; i<equ; i++)
    {
        for(int j=0; j<var+1; j++)
        {
            cout<<a[i][j]<<", ";
        }
        cout<<endl;
    }
    cout<<"+++++++++++++++++++++++++++分界线++++++++++++++++++++++++++++++"<<endl;
    puts("");
}
void Init()
{
    memset(a, 0, sizeof(a));
    memset(x, 0, sizeof(x));
    for(int i=0; i<equ; i++)
    {
        int ta = i % n, tb  = i / n;
        a[i][i] = 1;
        if(ta > 0)
            a[i-1][i] = 1;
        if(tb > 0)
            a[i-n][i] = 1;
        if(ta < (n-1))
            a[i+1][i] = 1;
        if(tb < (n-1))
            a[i+n][i] = 1;
    }
    for(int i=0; i<equ; i++)
        a[i][i+equ] = 1;
}
int a2[4][2]=
{
    3,2,
    3,1,
    2,3,
    1,3
};

int a3[9][3]=
{
    5,1,6,
    0,2,7,
    5,4,3,
    1,3,1,
    2,7,2,
    4,6,4,
    6,1,5,
    7,2,0,
    3,4,5
};

int a6[36][6]=
{
    43,8,55,10,44,40,
    3,20,53,17,14,4,
    44,42,7,32,55,34,
    13,21,56,1,59,17,
    48,10,43,34,28,8,
    53,4,59,20,13,5,
    8,28,2,27,34,44,
    20,54,5,59,21,14,
    42,43,10,48,2,55,
    21,53,20,3,16,59,
    10,27,40,55,42,28,
    4,14,16,54,17,13,
    55,2,48,42,27,10,
    53,5,56,1,59,17,
    7,10,28,40,48,32,
    56,20,14,5,3,1,
    43,40,7,32,55,34,
    59,16,3,21,54,20,
    10,27,42,48,2,55,
    17,59,1,56,5,53,
    32,48,40,28,10,7,
    1,3,5,14,20,56,
    34,55,32,7,40,43,
    20,54,21,3,16,59,
    44,34,27,2,28,8,
    14,21,59,5,54,20,
    55,2,48,10,43,42,
    59,16,3,20,53,21,
    28,42,55,40,27,10,
    13,17,54,16,14,4,
    40,44,10,55,8,43,
    4,14,17,53,20,3,
    34,55,32,7,42,44,
    17,59,1,56,21,13,
    8,28,34,43,10,48,
    5,13,20,59,4,53
};

int a7[49][7]=
{
    109,65,14,84,88,16,96,
    108,34,27,2,28,40,112,
    3,20,53,81,110,84,56,
    107,0,107,8,119,42,28,
    96,20,86,69,59,21,14,
    27,34,108,32,28,10,7,
    91,65,56,21,13,4,3,
    65,99,21,86,68,56,16,
    34,119,32,7,42,108,40,
    20,54,69,91,5,86,84,
    0,0,8,28,34,107,42,
    20,54,81,109,80,53,21,
    34,119,2,112,42,27,10,
    65,99,84,53,17,14,4,
    14,21,59,5,54,68,88,
    27,32,107,8,119,42,28,
    53,69,88,17,99,5,110,
    107,8,119,34,0,34,119,
    86,81,13,68,99,80,59,
    108,2,107,8,119,42,28,
    56,84,110,80,54,17,13,
    84,86,5,91,5,86,84,
    2,7,8,27,8,7,2,
    81,91,17,96,17,91,81,
    8,28,34,107,34,28,8,
    69,109,68,3,68,109,69,
    32,112,8,108,8,112,32,
    21,53,80,109,80,53,21,
    88,68,54,5,59,21,14,
    28,42,119,8,107,32,27,
    110,5,99,17,88,69,53,
    119,34,0,34,119,8,107,
    59,80,99,68,13,81,86,
    28,42,119,8,107,2,108,
    13,17,54,80,110,84,56,
    16,56,68,86,21,99,65,
    40,108,42,7,32,119,34,
    84,86,5,91,69,54,20,
    42,107,34,28,8,0,0,
    21,53,80,109,81,54,20,
    10,27,42,112,2,119,34,
    4,14,17,53,84,99,65,
    96,16,88,84,14,65,109,
    112,40,28,2,27,34,108,
    56,84,110,81,53,20,3,
    28,42,119,8,107,0,107,
    14,21,59,69,86,20,96,
    7,10,28,32,108,34,27,
    3,4,13,21,56,65,91
};

int a8[64][8]=
{
    220,138,7,128,199,170,108,40,
    214,81,13,64,237,1,238,68,
    27,0,27,32,107,168,199,130,
    237,81,54,16,14,5,3,1,
    183,138,108,8,112,160,192,128,
    216,0,216,4,214,21,227,65,
    107,138,176,2,183,128,119,34,
    59,81,224,1,227,85,54,20,
    138,219,10,192,42,171,130,108,
    81,219,17,224,65,3,69,238,
    0,0,32,112,136,172,42,199,
    81,219,65,56,21,13,4,3,
    138,219,130,28,168,176,32,192,
    0,0,4,14,17,53,84,227,
    138,219,136,7,130,192,162,119,
    81,219,80,3,84,213,65,54,
    7,10,28,160,172,2,171,170,
    13,17,54,16,14,5,3,1,
    27,32,107,136,183,10,172,168,
    54,65,213,68,59,20,13,5,
    108,130,171,34,220,40,176,160,
    216,4,214,17,237,80,53,21,
    176,136,108,8,112,160,192,128,
    224,80,56,5,53,64,213,85,
    128,192,160,112,136,172,42,199,
    64,224,16,216,84,14,65,237,
    32,112,136,172,10,183,136,107,
    16,56,68,214,69,59,21,14,
    8,28,34,107,162,220,168,112,
    4,14,17,53,80,237,17,214,
    2,7,8,27,42,112,130,183,
    1,3,5,14,17,53,84,227,
    199,42,172,136,112,160,192,128,
    237,65,14,84,216,16,224,64,
    107,136,183,10,172,136,112,32,
    14,21,59,69,214,68,56,16,
    112,168,220,162,107,34,28,8,
    214,17,237,80,53,17,14,4,
    183,130,112,42,27,8,7,2,
    227,84,53,17,14,5,3,1,
    170,171,2,172,160,28,10,7,
    1,3,5,14,16,54,17,13,
    168,172,10,183,136,107,32,27,
    5,13,20,59,68,213,65,54,
    160,176,40,220,34,171,130,108,
    21,53,80,237,17,214,4,216,
    128,192,160,112,8,108,136,176,
    85,213,64,53,5,56,80,224,
    108,130,171,42,192,10,219,138,
    238,69,3,65,224,17,219,81,
    199,42,172,136,112,32,0,0,
    3,4,13,21,56,65,219,81,
    192,32,176,168,28,130,219,138,
    227,84,53,17,14,4,0,0,
    119,162,192,130,7,136,219,138,
    54,65,213,84,3,80,219,81,
    40,108,170,199,128,7,138,220,
    68,238,1,237,64,13,81,214,
    130,199,168,107,32,27,0,27,
    1,3,5,14,16,54,81,237,
    128,192,160,112,8,108,138,183,
    65,227,21,214,4,216,0,216,
    34,119,128,183,2,176,138,107,
    20,54,85,227,1,224,81,59
};
int b[MAXN];
int main()
{
    int T;
    T = Scan_Int();
    while(T--)
    {
        memset(b, 0, sizeof(b));
        memset(x, 0, sizeof(x));
        n = Scan_Int();
        equ = var = n*n;
        if(n == 1)
        {
            int xx;
            xx = Scan_Int();
            Out(xx);
            puts("");
            continue;
        }
        if(n == 2)
        {
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                int xx;
                b[i] = Scan_Int();
            }
            for(int i=0; i<equ; i++)
                for(int j=0; j<n; j++)
                    x[i] ^= (a2[i][j]&b[j]);
            for(int i=0; i<var; i++)
            {
                int tmp = 0;
                while(x[i])
                {
                    tmp ^= (x[i] & 1);
                    x[i]>>=1;
                }
                sum += tmp;
            }
            Out(sum);
            puts("");
            continue;
        }
        if(n == 3)
        {
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                int xx;
                b[i] = Scan_Int();
            }
            for(int i=0; i<equ; i++)
                for(int j=0; j<n; j++)
                    x[i] ^= (a3[i][j]&b[j]);
            for(int i=0; i<var; i++)
            {
                int tmp = 0;
                while(x[i])
                {
                    tmp ^= (x[i] & 1);
                    x[i]>>=1;
                }
                sum += tmp;
            }
            Out(sum);
            puts("");
            continue;
        }
        if(n == 6)
        {
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                int xx;
                b[i] = Scan_Int();
            }
            for(int i=0; i<equ; i++)
                for(int j=0; j<n; j++)
                    x[i] ^= (a6[i][j]&b[j]);
            for(int i=0; i<var; i++)
            {
                int tmp = 0;
                while(x[i])
                {
                    tmp ^= (x[i] & 1);
                    x[i]>>=1;
                }
                sum += tmp;
            }
            Out(sum);
            puts("");
            continue;
        }
        if(n == 7)
        {
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                int xx;
                b[i] = Scan_Int();
            }
            for(int i=0; i<equ; i++)
                for(int j=0; j<n; j++)
                    x[i] ^= (a7[i][j]&b[j]);
            for(int i=0; i<var; i++)
            {
                int tmp = 0;
                while(x[i])
                {
                    tmp ^= (x[i] & 1);
                    x[i]>>=1;
                }
                sum += tmp;
            }
            Out(sum);
            puts("");
            continue;
        }
        if(n == 8)
        {
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                int xx;
                b[i] = Scan_Int();
            }
            for(int i=0; i<equ; i++)
                for(int j=0; j<n; j++)
                    x[i] ^= (a8[i][j]&b[j]);
            for(int i=0; i<var; i++)
            {
                int tmp = 0;
                while(x[i])
                {
                    tmp ^= (x[i] & 1);
                    x[i]>>=1;
                }
                sum += tmp;
            }
            Out(sum);
            puts("");
            continue;
        }
        Init();
        for(int i=0; i<n; i++)
        {
            int xx;
            xx = Scan_Int();
            for(int j=n-1; j>=0; j--)
            {
                a[i*n+j][var] = (xx&1);
                xx>>=1;
            }
        }
        ///Debug();
        int tmp = Gauss();
        if(tmp == -1)
            puts("-1");
        else if(tmp == 0)
        {
            int ans = 0;
            for(int i=0; i<var; i++)
                ans += x[i];
            Out(ans);
            puts("");
        }
        else
        {
            int all = (1<<tmp), ans = INF;
            for(int i=0; i<all; i++)
            {
                int sum = 0;
                for(int j=0; j<tmp; j++)
                {
                    if(i & (1<<j))
                        x[x_i[j]] = 1;
                    else
                        x[x_i[j]] = 0;
                }
                for(int ii=var-tmp-1; ii>=0; ii--)
                {
                    x[ii] = a[ii][var];
                    for(int j=ii+1; j<var; j++)
                        x[ii] ^= (a[ii][j] && x[j]);
                }
                for(int ii=0; ii<var; ii++)
                    sum += x[ii];
                ans = min(sum, ans);
            }
            Out(ans);
            puts("");
        }
    }
    return 0;
}
