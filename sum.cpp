#include<cstdio>
int main(){
int sum,n,x;
for(;;){
    sum = 0;
scanf("%d",&n);
if (n == 0){
    break;
}
for(;n == 0;){
   
    x = n % 10;
    sum = sum + x;
    n = n /10;
}
printf("%d\n",x);
}
}
//桁の関係でAOJで使うことは無理