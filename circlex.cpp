#include<cstdio>
#include<cmath>
int main(){
    double r,s,l;
std::scanf("%lf",&r);
    s = M_PI * r * r;
    l = M_PI * r * 2;
    std::printf("%.6f %.6f\n", s, l);
    return 0;
}
