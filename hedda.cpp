#include <cstdio>
#include "Vec3.h"
#include "ray.h"
#include "sphere.h"
#include "image.h"
#include "camera.h"
#include "hit.h"
#include "accel.h"
#include <memory>
#include <algorithm>
#include <random>

std::random_device dev_rnd;
std::mt19937 mt(dev_rnd());
std::uniform_real_distribution<> dist(0, 1);//0~1までの乱数
double rnd() {
    return dist(mt);//めっちゃランダムなやつ初項に使えば、あとめっちゃランダム
}

int main()
{
    Image img(512, 512);
    Camera cam(Vec3(0,0, -3), Vec3(0, 0, 1));//0だとカメラめり込むので
    Vec3 sunDir = normalize(Vec3(1,1,-1));

    Accel accel;
    accel.add(std::make_shared<Sphere>(Sphere(Vec3(0,0,0),1.0)));
    accel.add(std::make_shared<Sphere>(Sphere(Vec3(0,-10001,0),10000)));
    
    

    

    for(int k = 0;k < 100;k++){
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            double u =(2.0*i -img.width)/img.width;
            double v =(2.0*j -img.height)/img.height;
            Ray ray = cam.getRay(u, v);
            Hit hit;
            Vec3 color;
            if (accel.intersect(ray, hit))//当たってる場合のみshadowRay
            {
                Ray shadowRay = Ray(hit.hitPos + 0.001 * hit.hitNormal,sunDir);
                Hit hit_shadow;
                if(!accel.intersect(shadowRay,hit_shadow)){
                double I =std::max(dot(sunDir,hit.hitNormal),0.0);//光の強さ
                color = (hit.hitNormal + Vec3(1,1,1))/2.0;
                }else
                {
                     color = Vec3(0,0,0);
                }   

            }
            else{
                color = (0,0,0);
            }
            
                img.setPixel(i,j,img.getPixel(i,j) + 1 / 100.0 * color);
            }
        }
    }
    }
    img.ppm_output();

    return 0;
}