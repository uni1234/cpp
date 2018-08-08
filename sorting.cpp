#include<cstdio>
int main(){
  int a,b,c;
  std::scanf("%d%d%d",&a,&b,&c);

  if(a < b && b < c){
    std::printf("%d %d %d\n", a, b, c);
  }
  else if(b > c && b < a){
    std::printf("%d %d %d\n", c, b, a);
  }
  else if(c < a && a < b){
    std::printf("%d %d %d\n", c, a, b);
  }
  else if(b < a && a < c){
    std::printf("%d %d %d\n", b, a, c);
  }
  else if(a < c && c < b){
    std::printf("%d %d %d\n", a, c, b);
  }
  else {
    std::printf("%d %d %d\n", b, c, a);
  }
  return 0;
}