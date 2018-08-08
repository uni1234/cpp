#include <cstdio>


int main() {
    int x = 1;
    int& y = x;//xにyという別名をつける

    printf("%d\n", y);

    y = 2;
    printf("%d\n", x);

    return 0;
}
/*構造型プログラミング　関数を使ってソフトウェアを作る
オブジェクト指向　データと関数をまとめる(クラス)項目ごとに分けれる
int double　組み込み型
クラスを使うと、Vec3 Complex　みたいなのを自分で定義できる！
ベクトル　複素数