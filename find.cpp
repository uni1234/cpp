#include<cstdio>
int main(){
int n;
scanf("%d",&n);

bool card[4][13];
for(int i = 0;i < 4;i++){
  for(int j = 0;j < 13;j++){
   card[i][j] = false;
}
}

for(int i = 0;i < n;i++){
  char c;
  scanf("\n%c",&c);
int x;
scanf("%d",&x);
if(c == 'S'){
  card[0][x - 1] = true;
}
else if(c == 'H'){
  card[1][x - 1] = true;
  }
  else if(c == 'C'){
   card[2][x - 1] = true;
  }
  else if(c == 'D'){
    card[3][x - 1] = true;
  }
  }
  for(int i = 0;i < 4;i++){
    for(int j = 0; j < 13;j++){
      if(!card[i][j]){
       if(i ==0){
         printf("S %d\n", j + 1);
       }
       else if(i == 1){
         printf("H %d\n", j + 1);
       }
       else if(i == 2){
         printf("C %d\n", j + 1);
       }
      else if(i == 3){
        printf("D %d\n", j+ 1);
      }
      }
    }
    }
  return 0;
  }
