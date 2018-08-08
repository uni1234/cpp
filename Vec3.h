#ifndef VEC3_H//if not defined   = 0 =>  = 1
#define VEC3_H //                    define

#include <cstdio>
#include <cmath>
class Vec3 {
    public:
        double x;
        double y;
        double z;

        Vec3() {
            x = y = z = 0;
        };
        Vec3(double _x, double _y, double _z) {
            x = _x;
            y = _y;
            z = _z;
        };

        double length() const {
            return std::sqrt(x*x + y*y + z*z);
        };
        void print() const{
            printf("(%f,%f,%f)\n",x,y,z);
        }
};

Vec3 operator+(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vec3 operator-(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator*(double k, const Vec3& v) {
    return Vec3(k * v.x, k * v.y, k * v.z);
}
Vec3 operator*(const Vec3& v, double k) {
    return k*v;
}
Vec3 operator*(const Vec3& v1,const Vec3& v2){
    return Vec3(v1.x * v2.x,v1.y * v2.y,v1.z * v2.z);
}

Vec3 operator/(double k, const Vec3& v) {
    return Vec3(k / v.x, k / v.y, k / v.z);
}
Vec3 operator/(const Vec3& v, double k) {
    return Vec3(v.x / k, v.y / k, v.z / k);
}

double dot(const Vec3& v1, const Vec3& v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}
Vec3 cross(const Vec3& v1,const Vec3& v2){
    return Vec3(v1.y*v2.z - v1.z*v2.y,v1.z*v2.x-v1.x*v2.z, v1.x*v2.y-v1.y*v2.x);
}
Vec3 normalize(const Vec3& v){
    return v/v.length();//単位ベクトル化
}
Vec3 reflect(const Vec3& d,const Vec3& n){
    return d - 2 * dot(d,n) * n;
}
void orthonormalBasis(const Vec3& n,Vec3& x, Vec3& z){
    if(n.x > 0.9) x = Vec3(0,1,0);
    else x = Vec3(1,0,0);
    x = x - dot(x,n)*n;
    x = normalize(x);
    z = normalize(cross(n,x));
}



#endif