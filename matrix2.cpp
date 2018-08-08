#include <cstdio>

long memo[100];
int count = 0;
long f(long n) {
    count++;
  
  if(n == 0) {//終了条件をきちんと書かないと無限ループなので、segment faultになる、for文をこれでかけるにはかける
    return 0;
  }
  else if(n == 1){
      return 1;
  }
  else {
      if(memo[n] == 0){      //memo化
          memo[n] = f(n - 2)+ f(n - 1);
          return memo[n];
      }
      else{   
   return memo[n];
  }
}
}


int main() {
  printf("%ld\n", f(50));
  printf("%d\n",count);
  return 0;
}