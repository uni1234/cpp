Vec3 getColor(const Ray& ray,int depth = 0){
  Hit hit;
  if(accel.intersect(ray,hit)){
   if(hit.hitSphere->material == 0){
     Ray shadowray(hit.hitPos + hit.hitNormal * 0.001,lightDir);
     Hit shadow_hit;
     if(!accel.intersect(shadowray,shadow_hit)){
       double I = std::max(dot(lightDir,hit.hitNormal),0.0);
       return I * hit.hitSphere->color;
     }
     else{
       return = Vec3(0,0,0);
     }
   }
   else if(hit.hitSphere->material == 1){
     Ray nextRay(hit.hitPos + hit.hitNormal * 0.001,reflect(ray.direction,hit.hitNormal));
     return getColor(nextRay,depth + 1);
   }
  }
  else{
    return Vec3(0,0,0);
  }
}