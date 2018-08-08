#include <iostream>//sugoiyatu
#include <fstream>
#include <cmath>


class Complex {
    public:
        double real;
        double imag;

        Complex(double real, double imag) : real(real), imag(imag) {};

        double abs() const {
            return std::sqrt(real*real + imag*imag);
        };
};
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(c1.real*c2.real - c1.imag*c2.imag, c1.real*c2.imag + c1.imag*c2.real);
}


int main() {
  //ファイルを開く
  std::ofstream file("output.ppm");
  
  //このようにしてファイルに文字列を出力できる
  file << "P3" << std::endl;
  //横幅と縦幅は512
  file << "512 512" << std::endl;
  //階調数は255
  file << "255" << std::endl;
  
  //画像データ出力
  //全てのピクセルを(255, 255, 255)=白色にする
  for(int j = 0; j < 512; j++) {
    for(int i = 0; i < 512; i++) {
        double x = i/512.0 * 2.0 - 1.5;
        double y = j/512.0 * 2.0 - 1.0;
        Complex c(x, y);
        Complex z(0, 0);
        int diverge_count = 100;
        for(int k = 0; k < 100; k++) {
            z = z*z + c;
            if(z.abs() > 2.0) {
                diverge_count = k;
            }
        }
        int v = diverge_count/100.0 * 255;
        file << v << " " << v << " " << v << std::endl;
    }
  }
  
  //使い終わったらファイルを閉じる
  file.close();
  return 0;
}