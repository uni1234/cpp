#include<cstdio>
int main(){
int a,b,c,s,i;
int m = 0;
std::scanf("%d%d%d",&a,&b,&c);
for(i = a;i <= b;i++){
    if(c % i == 0){
        m++;
        }
} 
        std::printf("%d\n",m);
}