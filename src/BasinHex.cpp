#include "Basin.h"

void BasinHex::initialize(const float height, const float borderWidth,
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
    //glBegin(GL_QUADS);
    glBegin(GL_TRIANGLES); // Use triangles to create the hexagonal basin


    // Calculate the vertices for a hexagonal shape
    float halfX = innerSizeX / 2.0f;
    float halfZ = innerSizeZ / 2.0f;
    float h = height;

    // Loop to generate hexagonal basin geometry
    for (int i = 0; i < 6; ++i) {
        float angle1 = i * (M_PI / 3.0f);
        float angle2 = (i + 1) * (M_PI / 3.0f);

        // Center vertex
        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(0.0f, h, 0.0f);

        // First edge vertex
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(halfX * cos(angle1), 0.0f, halfZ * sin(angle1));

        // Second edge vertex
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(halfX * cos(angle2), 0.0f, halfZ * sin(angle2));
    }

    glEnd();
    glPopMatrix();
    glEndList();

void BasinHex::render() {
    glCallList(listIdx);
}
