#include <cstdio>//プログラムは関数定義の集まり

int sum(int array[],int n){
  int ret = 0;
  
  for(int i = 0;i < n;i++){
    ret += array[i];
  }
 
  return ret;
}
double avr(int array[],int n){
  return (double)sum(array,n)/n;//sumはintで定義されるのでdouble型にcast
}

//hello world と返す関数（何も返さない関数）を作る。返す値がないので、returnいらない
void h(){
  printf("Hello World\n");
}

double vari(int array[],int n){//中に書いてある関数は先に書いておく。もしくは定義されてる関数先に列挙していく。

  double mu = avr(array,n);
  int a[n];
  for(int i = 0;i < n;i++){
     a[i] = (array[i] - mu)*(array[i] - mu);
  }
  
  return (double)sum(array,n)/n;
}
int main(){//関数ていぎ
int a[3] = {1,2,3};
 printf("%f\n",vari(a,3));
 printf("%d\n",a[2]);
  return 0;//0 ->正常終了　1->以上終了とosに返す

}
//再利用できる。見やすい。
//配列は参照渡し　　配列の先頭要素のアドレスを渡している