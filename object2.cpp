#include<stdio.h>
#include<cmath>

class Vec2{
    public:
    double x;
    double y;

    Vec2(double _x,double _y){
        x = _x;
        y = _y;
    };
};


class Figure {
  public:
    virtual double area() const = 0;//固定　これしてないとしたのconstで引っかかる
};



class Rectangle : public Figure 
{
  public:
  Vec2 left;//左下の点
  Vec2 right;//右上の点
  Rectangle(const Vec2& _left,const Vec2& _right) : left(_left), right(_right){};

  double area() const {
      return  (right.x -left.x)*(right.y - left.y);
  };
  
};
class Circle : public Figure{
    public:
    double radius;
    Vec2 center;

    Circle(const Vec2& _center,double _radius) : center(_center),radius(_radius){};
    double area(){
        return M_PI * radius * radius;
    };
    
};

void printArea(const Rectangle& rect) {
  printf("%f\n", rect.area());
}

    
   
int main(){
  Rectangle rect = Rectangle(Vec2(1,1),Vec2(3,3));
  printArea(rect);
}
//const は間違い予防、間違いになるうるものでもerror 後高速化！！！