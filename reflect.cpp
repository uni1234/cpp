#include "Vec3.h"
#include "image.h"
#include "sphere.h"
#include "camera.h"
#include "ray.h"


Vec3 reflect(const Vec3& d, const Vec3& n) {
    return d - 2*dot(d, n)*n;
}


int main() {
    Image img(512, 512);
    Camera cam(Vec3(0, 0, -3), Vec3(0, 0, 1));

    Sphere sphere(Vec3(0, 0, 0), 1.0);

    Vec3 sunDir = normalize(Vec3(1, 1, -1));

    double kd = 0.5;
    double ks = 0.5;
    double alpha = 128.0;

    for(int i = 0; i < img.width; i++) {
        for(int j = 0; j < img.height; j++) {
            double u = (2.0*i - img.width)/img.width;
            double v = (2.0*j - img.height)/img.height;
            Ray ray = cam.getRay(u, v);

            Hit hit;
            if(sphere.intersect(ray, hit)) {
                Vec3 color = Vec3(1, 1, 1);
                Vec3 r = reflect(-1*sunDir, hit.hitNormal);
                double I = kd*std::max(dot(hit.hitNormal, sunDir), 0.0) + ks*std::pow(std::max(dot(-1*ray.direction, r), 0.0), alpha);
                img.setPixel(i, j, I*color);
            }
            else {
                img.setPixel(i, j, Vec3(0, 0, 0));
            }
        }
    }

    img.ppm_output();
}