#include<cstdio>
int main(){
char a[1001];//intとかlongだと小さい数のみしか判定できない、1000桁とか無理
int i,sum;
while(1){
    sum = 0;
scanf("%s",a);
if(a[0] == '0'){
    break;
}
for(i = 0;a[i] != '\0';i++){
    sum = sum + a[i] - '0';//配列はASCIIコード!!なので、a[i] - '0'で数値に直している
}
printf("%d\n",sum);
}
return 0;
}