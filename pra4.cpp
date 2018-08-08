#include <cstdio>

int gcd(int a, int b){
    if(a >= b){
    for (int i = 0; a % b != 0; i++){
        
            int r = a % b;
            a = b;
            b = r;
            
        }
        return b;
    }


        else{
            for(int j = 0;b % a != 0;j++){
            int r = b % a;
            b = a;
            a = r;
            }
            return a;
        }
    }


    int main(){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
        return 0;
    }