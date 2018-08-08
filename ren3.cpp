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
    double length(){
        return sqrt(x * x + y * y + z * z);
    };
};
Vec3 operator-(const Vec3& left,const Vec3& right){
    return Vec3(left.x - right.x,left.y -right.y,left.z -right.z);
}
int main(){
    Vec3 v1(1,1,1);
    Vec3 v2(3,5,5);
    Vec3 v3;
    v3 = v1 - v2;
    printf("%f\n",v3.length());
    return 0;
}



