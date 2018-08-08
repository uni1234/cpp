#include<cstdio>

int main() {
    int a;
    int *p;//intのポインタ変数pを宣言
    
    p = &a;//変数aのアドレスをintのポインタ変数pに代入（これ以降aと*pの扱い一緒）
    
    a = 100;
    *p = *p + 2;//*pと書くことはaと書くことと一緒、つまりa = a + 2と同じ
    
    printf("%d\n",a);
    printf("%d\n",*p);//pのアドレスを参照する。
    
    return 0;
}