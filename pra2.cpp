#include<stdio.h>
#include<math.h>
void solve(double a,double b,double c){
    double D =b * b - 4 * a * c;
    if(a == 0){
        if(b == 0){
            printf("解なし\n");
        }
        else{
            printf("%f\n",-1 * (c / b));
        }
       
    }
    else if(D > 0){
       printf("%f ",(-1 * b + sqrt(D))/(2 * a));
       printf("%f\n",(-1 * b - sqrt(D))/(2 * a));
    }
    else if(D == 0){
        printf("%f\n",(-1 * b)/(2 * a));
    }
    else{
        printf("解なし\n");
    }
}

int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    solve(a,b,c);
    return 0;
}