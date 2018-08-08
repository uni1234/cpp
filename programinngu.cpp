#include<cstdio>

int main() {
  int A[3][3],B[3][3];

for(int i = 0;i < 3;i++)for(int j = 0;j < 3;j++)scanf("%d",&A[i][j]);//行列Aの入力
for(int i = 0;i < 3;i++)for(int j = 0;j < 3;j++)scanf("%d",&B[i][j]);//行列Bの入力


int C[3][3];

int *pa = &A[0][0];
int *pb = &B[0][0];
int *pc = &C[0][0];

for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
        *(pc + 3 * i + j) = (*pa + 3 * i + j)  + (*pb + 3 * i + j);
    }

}
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("C[%d][%d] = %d\n", i+1, j+1, *(pc + 3 * i + j));
    }
  
}
}