#include<stdio.h>
int main(){
    int n,m,l;
    scanf("%d %d %d",&n,&m,&l);
    int A[101][101];
    int B[101][101];
    int ans;
   
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < l;j++){
        scanf("%d",&B[i][j]);
    }
    }
    for(int i = 0;i < n;i++){
       
        for(int j = 0;j < l;j++){
            ans = 0;
            for(int k = 0; k < m;k++){
                ans += A[i][k] * B[k][j];
            }
            if(j == l - 1){
       printf("%d",ans);
       }
else{
printf("%d ",ans);
}
          
        }
        printf("\n");
        
    }
    return 0;
}

