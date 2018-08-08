#include<cstdio>

int main() {
    int S;
    scanf("%d",&S);
    int h = S / 3600;//時間
    S %= 3600;// S = S % 3600表示したいものではなく使う文字を置く
    int m = S / 60;//分
    int s = S % 60;//秒

    printf("%d:%d:%d\n",h,m,s);
    return 0;
}