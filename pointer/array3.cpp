#include<cstdio>

int main() {
    int array[5] =  {0,10,20,30,40};
    
    int *p = array;
    
    for(int i = 0;i < 5;i++) {
        printf("%d\n",p[i]);
    }
    return 0;
}