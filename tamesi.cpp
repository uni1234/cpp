#include<stdio.h>
int main(){
    int n;
    int a[51];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);//一気に入力する必要はない　一つずつ結果を出していこう
    
        int x = 0;//初期化
        for(int j = 1;j < a[i];j++){
            if(a[i] % j == 0){
                x = x + j;
            }
        }
        if(a[i] == x){
            printf("perfect\n");
        }
        else if(a[i] - x == 1){
            printf("nearly\n");
        }
        else if(a[i] - x == -1){
            printf("nearly\n");
        }
        else{
            printf("neither\n");
        }
    }
}
//完全数とほぼ完全数　やはり一気に入力、一気に出力である必要はないみたい