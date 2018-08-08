#include <iostream>
#include <memory>
#include <algorithm>
#include <random>
#include "vec3.h"
#include "ray.h"
#include "hit.h"
#include "sphere.h"
#include "image.h"
#include "camera.h"
#include "accel.h"
#include <omp.h>



std::random_device dev_rnd;
std::mt19937 mt(dev_rnd());
std::uniform_real_distribution<> dist(0, 1);
double rnd() {
    return dist(mt);
}
Vec3 randomDir() {
    double theta = M_PI*rnd();
    double phi = 2*M_PI*rnd();
    
    double x = std::cos(phi)*std::sin(theta);
    double y = std::cos(theta);
    double z = std::sin(phi)*std::sin(theta);
    return Vec3(x, y, z);
}
Vec3 randomemisohere(const Vec3& n){
    double u = rnd();
    double v = rnd();

    double y = u;
    double x = std::sqrt(1 - u * u) * std::cos(2 * M_PI * v);
    double z = std::sqrt(1 - u * u) * std::sin(2 * M_PI * v);
    Vec3 xv,zv;
    orthonormalBasis(n,xv,zv);

    return x * xv + y * n + z * zv;
    
}

Vec3 randomCosineHemisphere(float &pdf,const Vec3 &n) {//つけるだけつけといたほうがいい　早くなるしミス少なくなる　書き換える時だけ書かんければ良い
  double u = rnd();
  double v = rnd();

  double theta = 0.5 * std::acos(1 - 2 * u);
  double phi = 2 * M_PI * v;
  pdf = 1 / M_PI *  std::cos(theta);//pdf 引数に用いてるからerror出ない
  
  double y = std::cos(theta);
  double x = std::cos(phi) * std::sin(theta);
  double z = std::sin(phi) * std::sin(theta);
  
  Vec3 xv, zv;
  orthonormalBasis(n, xv, zv);
  
  return x*xv + y*n + z*zv;
}
Accel accel;
Vec3 lightDir = normalize(Vec3(1,1,-1));


Vec3 getColor(const Ray& ray,double roulette = 1.0,int depth = 0) {
    if(rnd() > roulette) return Vec3(0,0,0);
    roulette *= 0.96;
    Hit hit;
    Vec3 color;
    if(accel.intersect(ray,hit)){
        
    if(hit.hitSphere->material == 0){
        float pdf;//確率密度関数
        Vec3 nextDir = randomCosineHemisphere(pdf,hit.hitNormal);
        Ray nextRay = Ray(hit.hitPos + hit.hitNormal*0.001,nextDir);
        double cos_term = std::max(dot(nextDir,hit.hitNormal),0.0);
        return 1 / roulette * 1 /pdf * hit.hitSphere->color/M_PI * cos_term * getColor(nextRay,roulette,depth + 1);//hit.hitSphere->color/M_PI BRDF /roulette <= 平均取る

                }
                else if(hit.hitSphere->material == 1){
                    Ray nextRay(hit.hitPos + 0.001 * hit.hitNormal,reflect(ray.direction,hit.hitNormal));
                    return getColor(nextRay,depth + 1);


    }else{
        return Vec3(0,0,0);//new
    }
    }
    else{
    return  Vec3(1, 1, 1);
    }
}




int main(){
    Image img(512, 512);
    Camera cam(Vec3(0, 0, -3), Vec3(0, 0, 1));
    
    accel.add(std::make_shared<Sphere>(Sphere(Vec3(0, 0, 0), 1.0,Vec3(0,1,0),0)));
    accel.add(std::make_shared<Sphere>(Sphere(Vec3(0, -10001, 0), 10000,Vec3(0.8,0.8,0.8),0)));

#pragma omp parallel for
    for(int k = 0; k < 100; k++) {
        for(int i = 0; i < img.width; i++) {
            for(int j = 0; j < img.height; j++) {
                //ピクセル内の位置をランダムにずらす
                double u = (2.0*(i + rnd()) - img.width)/img.width;
                double v = (2.0*(j + rnd()) - img.height)/img.height;
                Ray ray = cam.getRay(u, v);
                img.setPixel(i, j, img.getPixel(i, j) + 1/100.0*getColor(ray)); //平均をとる  
            }
        }
    }
    img.gamma_correction();
    img.ppm_output();
}
//return はおかしい
