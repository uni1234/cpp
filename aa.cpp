#include <cstdio>
#include <random>


std::random_device dev_rnd;
std::mt19937 mt(dev_rnd());
std::uniform_real_distribution<> dist(0, 1);//0~1までの乱数
double rnd() {
    return dist(mt);//めっちゃランダムなやつ初項に使えば、あとめっちゃランダム
}


int main() {
    for(int i = 0; i < 100; i++) {
        printf("%f\n", rnd());
    }
    return 0;
}