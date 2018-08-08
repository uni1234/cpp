#include<cstdio>
#include <vector> //std::vectorを使うにはこれが必要

int main(){
  std::vector<int> v; //int型のstd::vector
  
  v.push_back(1); //末尾に1を追加
  v.push_back(2); //末尾に2を追加
  v.push_back(3); //末尾に3を追加
  v.push_back(10);//末尾に10を追加
  
  for(int i = 0; i < v.size(); i++) { //v.size()で長さを取得できる
    printf("%d ", v[i]); //通常の配列と同じようにアクセスできる
  }
  printf("\n");
  v[0] = -5;
  for(int i = 0; i < v.size(); i++) { //v.size()で長さを取得できる
    printf("%d ", v[i]); //通常の配列と同じようにアクセスできる
  }
  printf("\n");
  
  return 0;
}