#include<cstdio>
int main(){
int a,b,d,r;
std::scanf("%d %d",&a, &b);
d = a / b;
r = a % b;
double f = (double)a / b;
std::printf("%d %d %.6f\n", d, r, f);
return 0;
}
