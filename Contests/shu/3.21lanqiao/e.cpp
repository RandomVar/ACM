#include <stdio.h>
int main() {int n, ans = 0;scanf("%d", &n);
while (n) {ans +=(n/=5);}
printf("%d\n", ans);
scanf("%d",&n);

return 0;}
