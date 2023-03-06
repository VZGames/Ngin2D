#ifndef CAMERA_H
#define CAMERA_H

namespace ngin2D {

struct ViewPort
{
    int x, y;
    int w, h;
};
class Camera
{
public:
    Camera();
    ~Camera();


    const ViewPort &getViewport() const;
    void setViewport(const ViewPort &newViewport);

private:
    ViewPort viewport;


};
}

#endif // CAMERA_H
