#include<cstdio>
#include<cmath>
class Vec3{
    public:
    double x;
    double y;
    double z;
    Vec3(){
        x = 0;
        y = 0;
        z = 0;
    };
    Vec3(double _x,double _y,double _z){
        x = _x;
        y = _y;
        z = _z;
    };
    void print(){
        printf("%f\n",sqrt(x * x + y * y + z * z));
    };
};


class Sphere{
    public:
    double radius;
    Vec3 center;
    Sphere(){

    };
    Sphere(const Vec3& _center,double _radius) : center(_center), radius(_radius){};
    double area(){
        radius = 3;
        return 4 / 3 * M_PI * radius * radius * radius;
    };
    
};

int main(){
    Vec3 v3;
    Sphere Sp;
    
    printf("%f\n",Sp.area());

}