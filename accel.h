#ifndef ACCEL_H
#define ACCEL_H
#include <vector>
#include <memory>
#include "ray.h"
#include "hit.h"
#include "sphere.h"
class Accel {
    public:
        std::vector<std::shared_ptr<Sphere>> spheres;

        Accel() {};

        void add(std::shared_ptr<Sphere> p) {
          spheres.push_back(p);//std::vector
        };

        bool intersect(const Ray& ray, Hit& hit) const {
          bool isHit = false;

          hit.t = 10000;
          Hit hit_each;
          
          for(auto p:spheres){
              if(p -> intersect(ray,hit_each)){
                  isHit = true;
                  if(hit_each.t < hit.t){
                      hit = hit_each;
                  }
              }
          }
          return isHit;
        };
};
#endif