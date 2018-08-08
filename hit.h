#ifndef HIT_H
#define HIT_H
#include "Vec3.h"

class Sphere;
class Hit {
    public:
        double t; //衝突点までの距離
        Vec3 hitPos; //衝突位置
        Vec3 hitNormal; //衝突位置の法線
        const Sphere* hitSphere;

        Hit() {};
        Hit(double t, const Vec3& hitPos, const Vec3& hitNormal) : t(t), hitPos(hitPos), hitNormal(hitNormal) {};
};
#endif