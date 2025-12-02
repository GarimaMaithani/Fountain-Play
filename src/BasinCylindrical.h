#ifndef BASIN_H
#define BASIN_H

#include <memory>
#include <GL/glut.h>

#include "Texture.h"

class BasinCylindrical {
public:
    BasinCylindrical() {};
    void initialize(const float height, const float borderWidth,
                    const float innerRadius, const float innerSizeZ,
                    std::unique_ptr<Texture> texture);
    void render();
private:
    float height;
    float borderWidth;
    float innerRadius;
    float innerSizeZ;
    float texBorder;
    int listIdx;
};

#endif