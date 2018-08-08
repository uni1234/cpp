#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include "Vec3.h"

class Image{
    public:
    int width;
    int height;
    Vec3* data;

    Image(int _width,int _height){
        width = _width;
        height = _height;
        data = new Vec3[width * height];
    };

    ~Image(){
        delete[] data;
    };
    Vec3 getPixel(int i,int j) const{
        return data[width * i + j];

    };
    void setPixel(int i,int j,const Vec3& color){
        data[width * i + j] =color;
    };
    void ppm_output() const{
        std::ofstream file("output.ppm");

        file << "P3" << std::endl;
        file << width << " " << height << std::endl;
        file << "255" << std::endl;
        for(int i = 0;i <height;i++){
            for(int j = 0;j < width;j++){
                Vec3 color = 255*this->getPixel(j,i);
                int r = std::min((int)color.x,255);
                int g = std::min((int)color.y,255);
                int b = std::min((int)color.z,255);
                file << r << " " << g << " " << b << std::endl;
            }
        }
    };
    void gamma_correction(){
    for(int i = 0;i < width;i++){
        for(int j = 0;j < height;j++){
            Vec3 col = this->getPixel(i,j);
            col.x = std::pow(col.x,1.0/2.2);
            col.y = std::pow(col.y,1.0/2.2);
            col.z = std::pow(col.z,1.0/2.2);
            this->setPixel(i,j,col);
        }
    }
};
};



#endif