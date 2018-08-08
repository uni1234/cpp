#include<cstdio>

int main() {
    int array[10];
    
    printf("array %d\n\n",array);
    
    for(int i = 0;i < 10;i++) {
        printf("&array[%d]  %d\n",i,&array[i]);
    }
    return 0;
}
//・　array と &array[0]が等しい
//・　&array[i + 1] と　&array[i] + 1　が等しい(ポインタ演算で)


//ポインタの解説
//(A)&array[0] 配列の先頭要素へのアドレス
//(B)配列arrayの5番目の要素
//(c)先頭アドレス　+ 4 （ポインタ演算）    *
//(D)*array + 4 -> (*array)+ 4-> array[0] + 4(ポインタ演算ではない)        +
//(e)&(array + 4) &は変数のアドレスを取ってくる、これはポインタ演算のアドレス取ってこい（意味不明）なのでエラー
//(f)&array[1]+ 3(ポインタ演算)->先頭から四つずらす->array + 4     *
//(h)array[0]先頭要素アドレスではない
//(I)array[0] + 4          +