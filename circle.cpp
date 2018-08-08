#include<cstdio>

int main(){
  int seisu, i, max, min,n;
scanf("%d",&n);
  scanf("%d",&seisu);
  max = seisu;
  min = seisu;
  int s = seisu;


  for (i = 1; i < n; i++) {
    scanf("%d", &seisu);
    if(seisu > max){
      max = seisu;
    }else{
      if(seisu < min){
        min = seisu;
      }
    }
      s = s + seisu;
  }

  
  printf("%d %d %d\n", min, max, s);
  return 0;
}