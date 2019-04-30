#include <stdio.h>
int pw(int x, int y, int p) 
{
  if (!y) {return 1;}
  int res = 
if (y & 1) {
  res = res * x % p;
  }
  return res;
}
int main() {
  int x, y, p;scanf("%d%d%d", &x, &y, &p);printf("%d\n", pw(x, y, p));
  scanf("%d",&x);
  
  return 0;}
