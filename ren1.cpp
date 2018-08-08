#include<cstdio>
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
    void print() const{
        printf("(%f,%f,%f)\n",x,y,z);
    };
};

Vec3 operator+(const Vec3& left,const Vec3& right){
    return Vec3(left.x + right.x,left.y + right.y,left.z + right.z);
}//ok
Vec3 operator-(const Vec3& left,const Vec3& right){
    return Vec3(left.x - right.x,left.y - right.y,left.z - right.z);
}//ok
Vec3 operator*(double left,const Vec3& right){
    return Vec3(left * right.x,left * right.y,left * right.z);
}//ok
Vec3 operator*(const Vec3& left,double right){
    return Vec3(left.x * right,left.y * right,left.z * right);
}//ok

Vec3 operator/(const Vec3& left,double right){
    return Vec3(left.x / right,left.y /right,left.z /right);
}
Vec3 operator/(double left,const Vec3& right){
    return Vec3(left / right.x,left /right.y,left /right.z);
}


int main(){
    Vec3 v1(1,1,1);
    Vec3 v2(2,2,2);
    Vec3 v3;
    v3 = v1 / 4;
    v3.print();
    return 0;
}

