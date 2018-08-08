#include<stdio.h>

int memo[101][101][101];
int Tarai(int x,int y,int z){
    if(x <= y){
        return y;
    }
    else {
        if(memo[x][y][z] != 0){
            return memo[x][y][z];
        }
        else{
            memo[x][y][z] = Tarai(Tarai(x - 1,y,z),Tarai(y - 1,z,x),Tarai(z - 1,x,y));
            return memo[x][y][z];
        }
    }
}
    

int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    printf("%d\n",Tarai(x,y,z));
    return 0;

}