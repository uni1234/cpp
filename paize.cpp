#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x = 0;
    int y = 0;
    
    for(int i = 1;i <= n;i++){
char s[100];
scanf("%s",s);
if(s[0] == 'b'){
    x = x + 1;
    if(x < 4){
        printf("ball!\n");
    }
    else if(x == 4){
        printf("fourball!\n");
    }
}

else if(s[0] =='s'){
    y = y + 1;
    if(y < 3){
        printf("strike!\n");
    }
    else if(y == 3){
        printf("out!\n");
    }
}
    }
}