#include<cstdio>

int main() {
    char *p;
    
    p = (char*)100;//(int*)や(char*)で無理やり100代入
    
    printf("%d\n",p);
    
    p = p + 2;
    
    printf("%d\n",p);
    
    return 0;
}