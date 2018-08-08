#include<cstdio>
int main(){
  int a,b;
  std::scanf("%d%d",&a,&b);
  
  if(a < b){
    std::printf("a < b\n");
  }
  else if(a > b){
    std::printf("a > b\n");
  }
  else {
    std::printf("a == b\n");
  }
  return 0;
}