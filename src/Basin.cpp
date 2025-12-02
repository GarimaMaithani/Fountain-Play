#include "Basin.h"

//void Basin::initialize(const float height, const float borderWidth,
//    const float innerRadius, const float innerSizeZ,
//    std::unique_ptr<Texture> texture) {
//    // ...
//
//    // Generate vertices for a cylinder
//    const int segments = 36; // Number of segments to approximate a circle
//    const float angleIncrement = 2 * 3.14f / segments;
//
//    for (int i = 0; i <= segments; ++i) {
//        float angle = i * angleIncrement;
//        float x = innerRadius * cos(angle);
//        float z = innerRadius * sin(angle);
//
//        // Calculate texture coordinates based on angle for texture mapping
//        float texCoordX = static_cast<float>(i) / segments;
//        // You may need to adjust the texCoordY based on the cylinder's height
//        float texCoordY = 0.0f;
//
//        // Add vertex for the top surface
//        glVertex3f(x, height, z);
//        // Add corresponding texture coordinate for the top surface
//        glTexCoord2f(texCoordX, texCoordY);
//
//        // Add vertex for the bottom surface
//        glVertex3f(x, 0.0f, z);
//        // Add corresponding texture coordinate for the bottom surface
//        glTexCoord2f(texCoordX, 1.0f);
//    }
//
//    // Generate side surfaces of the cylinder using triangle strips
//    for (int i = 0; i < segments; ++i) {
//        glBegin(GL_TRIANGLE_STRIP);
//        for (int j = 0; j <= 1; ++j) {
//            float angle = (i + j) * angleIncrement;
//            float x = innerRadius * cos(angle);
//            float z = innerRadius * sin(angle);
//
//            // Add vertex and texture coordinate for the side surface
//            glVertex3f(x, height, z);
//            glTexCoord2f(static_cast<float>(i + j) / segments, 0.0f);
//
//            glVertex3f(x, 0.0f, z);
//            glTexCoord2f(static_cast<float>(i + j) / segments, 1.0f);
//        }
//        glEnd();
//    }
//
//    // ...
//}
//void Basin::render() {
//    glCallList(listIdx);
//}

//void Basin::initialize(const float height, const float borderWidth,
//    const float innerSizeX, const float innerSizeZ,
//    std::unique_ptr<Texture> texture) {
//    this->height = height;
//    this->borderWidth = borderWidth;
//    this->innerSizeX = innerSizeX;
//    this->innerSizeZ = innerSizeZ;
//    this->texBorder = borderWidth / (innerSizeX + 2 * borderWidth);
//
//    this->listIdx = glGenLists(1);
//    glNewList(listIdx, GL_COMPILE);
//    glPushMatrix();
//    texture->bind();
//    glBegin(GL_TRIANGLES); // Use triangles to create the hexagonal basin
//
//    // Calculate the vertices for a hexagonal shape
//    float halfX = innerSizeX / 2.0f;
//    float halfZ = innerSizeZ / 2.0f;
//    float h = height;
//
//    // Define the vertices of the hexagon manually
//    glTexCoord2f(0.5f, 0.5f);
//    glVertex3f(0.0f, h, 0.0f);
//    glVertex3f(halfX, 0.0f, halfZ * sqrt(3.0f));
//    glVertex3f(innerSizeX, h, 0.0f);
//
//    glVertex3f(innerSizeX, h, 0.0f);
//    glVertex3f(halfX, 0.0f, halfZ * sqrt(3.0f));
//    glVertex3f(innerSizeX, h, innerSizeZ);
//
//    glVertex3f(innerSizeX, h, innerSizeZ);
//    glVertex3f(halfX, 0.0f, halfZ * sqrt(3.0f));
//    glVertex3f(0.0f, h, innerSizeZ);
//
//    glVertex3f(0.0f, h, innerSizeZ);
//    glVertex3f(halfX, 0.0f, halfZ * sqrt(3.0f));
//    glVertex3f(-borderWidth, h, innerSizeZ / 2.0f);
//
//    glVertex3f(-borderWidth, h, innerSizeZ / 2.0f);
//    glVertex3f(halfX, 0.0f, halfZ * sqrt(3.0f));
//    glVertex3f(0.0f, h, 0.0f);
//
//    glVertex3f(0.0f, h, 0.0f);
//    glVertex3f(halfX, 0.0f, halfZ * sqrt(3.0f));
//    glVertex3f(-borderWidth, h, innerSizeZ / 2.0f);
//
//    glEnd();
//    glPopMatrix();
//    glEndList();
//}

//void Basin::initialize(const float height, const float borderWidth,
//    const float innerSizeX, const float innerSizeZ,
//    std::unique_ptr<Texture> texture) {
//
//    this->height = height;
//    this->borderWidth = borderWidth;
//    this->innerSizeX = innerSizeX;
//    this->innerSizeZ = innerSizeZ;
//    this->texBorder = borderWidth / (innerSizeX + 2 * borderWidth);
//
//    this->listIdx = glGenLists(1);
//    glNewList(listIdx, GL_COMPILE);
//    glPushMatrix();
//    texture->bind();
//    //glBegin(GL_QUADS);
//    glBegin(GL_TRIANGLES); // Use triangles to create the hexagonal basin
//
//    // Calculate the vertices for a hexagonal shape
//    float halfX = innerSizeX / 2.0f;
//    float halfZ = innerSizeZ / 2.0f;
//    float h = height;
//
//    // Loop to generate hexagonal basin geometry
//    for (int i = 0; i < 6; ++i) {
//        float angle1 = i * (3.14f / 3.0f);
//        float angle2 = (i + 1) * (3.14f / 3.0f);
//
//        // Center vertex
//        glTexCoord2f(0.5f, 0.5f);
//        glVertex3f(0.0f, h, 0.0f);
//
//        // First edge vertex
//        glTexCoord2f(0.0f, 0.0f);
//        glVertex3f(halfX * cos(angle1), 0.0f, halfZ * sin(angle1));
//
//        // Second edge vertex
//        glTexCoord2f(1.0f, 0.0f);
//        glVertex3f(halfX * cos(angle2), 0.0f, halfZ * sin(angle2));
//    }
//
//    glEnd();
//    glPopMatrix();
//    glEndList();
//}
//
//void Basin::render() {
//   glCallList(listIdx);
//}

//#include "Basin.h"
//
void Basin::initialize(const float height, const float borderWidth,
                       const float innerSizeX, const float innerSizeZ,
                       std::unique_ptr<Texture> texture) {
    this->height = height;
    this->borderWidth = borderWidth;
    this->innerSizeX = innerSizeX;
    this->innerSizeZ = innerSizeZ;
    this->texBorder = borderWidth / (innerSizeX + 2 * borderWidth);

    this->listIdx = glGenLists(1);
    glNewList(listIdx, GL_COMPILE);
    glPushMatrix();
    texture->bind();
    glBegin(GL_QUADS);

    /******************
     * top surface
     ******************/
    glNormal3f(0.0f, 1.0f, 0.0f);

    glTexCoord2f(texBorder, texBorder);
    glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(1.0f - texBorder, texBorder);
    glVertex3f(innerSizeX, height, 0.0f);
    glTexCoord2f(1.0f - texBorder, 0.0f);
    glVertex3f(innerSizeX, height, -borderWidth);
    glTexCoord2f(texBorder, 0.0f);
    glVertex3f(0.0f, height, -borderWidth);

    glTexCoord2f(texBorder, 0.0f);
    glVertex3f(0.0f, height, -borderWidth);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-borderWidth, height, -borderWidth);
    glTexCoord2f(0.0f, 1.0f - texBorder);
    glVertex3f(-borderWidth, height, innerSizeZ);
    glTexCoord2f(texBorder, 1.0f - texBorder);
    glVertex3f(0.0f, height, innerSizeZ);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(innerSizeX + borderWidth, height, -borderWidth);
    glTexCoord2f(1.0f - texBorder, 0.0f);
    glVertex3f(innerSizeX, height, -borderWidth);
    glTexCoord2f(1.0f - texBorder, 1.0f - texBorder);
    glVertex3f(innerSizeX, height, innerSizeZ);
    glTexCoord2f(1.0f, 1.0f - texBorder);
    glVertex3f(innerSizeX + borderWidth, height, innerSizeZ);

    glTexCoord2f(1.0f, 1.0f - texBorder);
    glVertex3f(innerSizeX + borderWidth, height, innerSizeZ);
    glTexCoord2f(0.0f, 1.0f - texBorder);
    glVertex3f(-borderWidth, height, innerSizeZ);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-borderWidth, height, innerSizeZ + borderWidth);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(innerSizeX + borderWidth, height, innerSizeZ + borderWidth);

    /******************
     * front sides
     ******************/
    glNormal3f(0.0f, 0.0f, 1.0f);

    glTexCoord2f(texBorder, texBorder);
    glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(1.0f - texBorder, texBorder);
    glVertex3f(innerSizeX, height, 0.0f);
    glTexCoord2f(1.0f - texBorder, 0.0f);
    glVertex3f(innerSizeX, 0.0f, 0.0f);
    glTexCoord2f(texBorder, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 1.0f - texBorder);
    glVertex3f(-borderWidth, height, innerSizeZ + borderWidth);
    glTexCoord2f(1.0f, 1.0f - texBorder);
    glVertex3f(innerSizeX + borderWidth, height, innerSizeZ + borderWidth);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(innerSizeX + borderWidth, 0.0f, innerSizeZ + borderWidth);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-borderWidth, 0.0f, innerSizeZ + borderWidth);

    /******************
    * back sides
    ******************/
    glNormal3f(0.0f, 0.0f, -1.0f);

    glTexCoord2f(texBorder, texBorder);
    glVertex3f(0.0f, height, innerSizeZ);
    glTexCoord2f(1.0f - texBorder, texBorder);
    glVertex3f(innerSizeX, height, innerSizeZ);
    glTexCoord2f(1.0f - texBorder, 0.0f);
    glVertex3f(innerSizeX, 0.0f, innerSizeZ);
    glTexCoord2f(texBorder, 0.0f);
    glVertex3f(0.0f, 0.0f, innerSizeZ);

    glTexCoord2f(0.0f, 1.0f - texBorder);
    glVertex3f(-borderWidth, height, -borderWidth);
    glTexCoord2f(1.0f, 1.0f - texBorder);
    glVertex3f(innerSizeX + borderWidth, height, -borderWidth);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(innerSizeX + borderWidth, 0.0f, -borderWidth);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-borderWidth, 0.0f, -borderWidth);

    /******************
    *  left sides
    ******************/
    glNormal3f(-1.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f - texBorder, texBorder);
    glVertex3f(innerSizeX, height, 0.0f);
    glTexCoord2f(1.0f, 1.0f - texBorder);
    glVertex3f(innerSizeX, height, innerSizeZ);
    glTexCoord2f(1.0f - texBorder, 1.0f - texBorder);
    glVertex3f(innerSizeX, 0.0f, innerSizeZ);
    glTexCoord2f(1.0f, texBorder);
    glVertex3f(innerSizeX, 0.0f, 0.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-borderWidth, height, -borderWidth);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-borderWidth, height, innerSizeZ + borderWidth);
    glTexCoord2f(1.0f, texBorder);
    glVertex3f(-borderWidth, 0.0f, innerSizeZ + borderWidth);
    glTexCoord2f(0.0f, texBorder);
    glVertex3f(-borderWidth, 0.0f, -borderWidth);

    /******************
    *  right sides
    ******************/
    glNormal3f(1.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f - texBorder, 0.0f);
    glVertex3f(0.0f, height, innerSizeZ);
    glTexCoord2f(texBorder, 0.0f);
    glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(texBorder, texBorder);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f - texBorder, texBorder);
    glVertex3f(0.0f, 0.0f, innerSizeZ);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(innerSizeX + borderWidth, height, innerSizeZ + borderWidth);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(innerSizeX + borderWidth, height, -borderWidth);
    glTexCoord2f(1.0f - texBorder, 0.0f);
    glVertex3f(innerSizeX + borderWidth, 0.0f, -borderWidth);
    glTexCoord2f(1.0f - texBorder, 1.0f);
    glVertex3f(innerSizeX + borderWidth, 0.0f, innerSizeZ + borderWidth);

    glEnd();
    glPopMatrix();
    glEndList();
}

void Basin::render() {
    glCallList(listIdx);
}
