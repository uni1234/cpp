#include<stdio.h>
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
    
};

    class Ray {
    public:
        Vec3 origin; //始点
        Vec3 direction; //方向

        Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction) {};
};

class Sphere{
    public:
        Vec3 center;
        double radius;

        Sphere(const Vec3& center, double radius) : center(center), radius(radius) {};

        bool intersect(const Ray& ray) const {
            double d_norm = ray.direction.length();
            double oc_norm = (ray.origin - center).length();

            double a = d_norm*d_norm;
            double b = 2*dot(ray.direction, ray.origin - center);
            double c = oc_norm*oc_norm - radius*radius;
            double D = b*b - 4*a*c;
            if(D < 0) return false;

            //解の候補
            double t1 = (-b - std::sqrt(D))/(2*a);
            double t2 = (-b + std::sqrt(D))/(2*a);

            //衝突距離
            double t = t1;
            if(t < 0) {
                t = t2;
                if(t < 0) return false;
            }

            return true;
        }
};
int main(){
    
}