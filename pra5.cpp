#include<stdio.h>
int comb(int n,int r){
    int x = 1;
    for(int i = n;i >= n- r + 1;i--){
        x = x * i;
    }
    for(int j = 1;j <= r;j++){
        x = x / j;
    }
    return x;
}

int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%d\n",comb(n,r));
    return 0;
}