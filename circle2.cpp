#include<cstdio>

int main(){
  int W,H,x,y,r;
  std::scanf("%d%d%d%d%d",&W,&H,&x,&y,&r);
  if(x + r > W || x - r < 0 ){
    std::printf("No\n");
  }
  else if(y - r < 0 || y + r > H){
    std::printf("No\n");
  }
  else {
    std::printf("Yes\n");
  }
  return 0;
}