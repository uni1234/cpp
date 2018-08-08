#ifndef CAMERA_H
#define CAMERA_H
class Camera {
    public:
        Vec3 camPos;
        Vec3 camForward;
        Vec3 camRight;
        Vec3 camUp;

        Camera(const Vec3& camPos, const Vec3& camForward) : camPos(camPos), camForward(camForward) {
            camRight = -1 * normalize(cross(camForward, Vec3(0, 1, 0))); //カメラの横方向//-1?
            camUp = normalize(cross(camForward, camRight)); //カメラの上方向
        };

        Ray getRay(double u, double v) const {
            Vec3 pinhole = camPos + camForward; //ピンホールの位置
            Vec3 sensorPos = camPos + u*camRight + v*camUp; //(i, j)の位置
            return Ray(sensorPos, normalize(pinhole - sensorPos));
        };
};
#endif