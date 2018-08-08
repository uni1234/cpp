#include<cstdio>

int main() {
    int a;
    int *p;//intのポインタ変数pを宣言 宣言のときのみ＊、変数名はp
    
    p = &a;//変数aのアドレスをintのポインタ変数pに代入
    
    printf("%p\n",&a);
    printf("%p\n",p);
    
    return 0;
}