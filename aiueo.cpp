#include<cstdio>

int main() {
    int A[3][3];
    
    printf("A[0][0] %d\n\n",A[0][0]);
    
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 3;j++) {
        printf("&A[%d][%d]  %d\n",i,j,&A[i][j]);
    }
    }
    return 0;
}