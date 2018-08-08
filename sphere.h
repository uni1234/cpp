#ifndef SPHERE_H
#define SPHERE_H
#include "hit.h"
#include "ray.h"
#include "Vec3.h"



class Sphere {
    public:
        Vec3 center;
        double radius;
        Vec3 color;
        int material;

        Sphere(const Vec3& center, double radius,const Vec3& color,int material) : center(center), radius(radius),color(color),material(material) {};

        bool intersect(const Ray& ray ,Hit& hit) const {
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
            hit.t = t;
            hit.hitPos = ray.origin + t * ray.direction;
            hit.hitNormal = normalize(hit.hitPos -center);
            hit.hitSphere = this;

            return true;
        };
};
#endif