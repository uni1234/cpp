#include <cstdio>

class Vec2 {
  public:
    double x; //x座標
    double y; //y座標
    
    //コンストラクタ
    Vec2(double _x, double _y) {
      x = _x;
      y = _y;
    };
    
    //出力
    void print() const {
      printf("(%f, %f)\n", x, y);
    };
};


//演算子+をオーバーロード int型はすでに定義されている
Vec2 operator+(const Vec2& left, const Vec2& right) {
  return Vec2(left.x + right.x, left.y + right.y);
}
Vec2 operator-(const Vec2& left, const Vec2& right) {
    return Vec2(left.x - right.x, left.y -right.y);
}
Vec2 operator*(double left,const Vec2& right) {
    return Vec2(left * right.x, left*right.y);
}
Vec2 operator*(const Vec2& left, double right){
    return Vec2(left.x*right, left.y*right);
}//両方定義必要

int main() {
  Vec2 v1(1, 1);
  Vec2 v2(2, 2);
  
  Vec2 v3 = 0.5*(2*v1 + 10*v2);//複雑な計算ができるよになった！
  v3.print();
  
  return 0;
}