#include "BasinCylindrical.h"

void BasinCylindrical::initialize(const float height, const float borderWidth,
    const float innerRadius, const float innerSizeZ,
    std::unique_ptr<Texture> texture) {
    // ...

    // Generate vertices for a cylinder
    const int segments = 36; // Number of segments to approximate a circle
    const float angleIncrement = 2 * PI / segments;

    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleIncrement;
        float x = innerRadius * cos(angle);
        float z = innerRadius * sin(angle);

        // Calculate texture coordinates based on angle for texture mapping
        float texCoordX = static_cast<float>(i) / segments;
        // You may need to adjust the texCoordY based on the cylinder's height
        float texCoordY = 0.0f;

        // Add vertex for the top surface
        glVertex3f(x, height, z);
        // Add corresponding texture coordinate for the top surface
        glTexCoord2f(texCoordX, texCoordY);

        // Add vertex for the bottom surface
        glVertex3f(x, 0.0f, z);
        // Add corresponding texture coordinate for the bottom surface
        glTexCoord2f(texCoordX, 1.0f);
    }

    // Generate side surfaces of the cylinder using triangle strips
    for (int i = 0; i < segments; ++i) {
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= 1; ++j) {
            float angle = (i + j) * angleIncrement;
            float x = innerRadius * cos(angle);
            float z = innerRadius * sin(angle);

            // Add vertex and texture coordinate for the side surface
            glVertex3f(x, height, z);
            glTexCoord2f(static_cast<float>(i + j) / segments, 0.0f);

            glVertex3f(x, 0.0f, z);
            glTexCoord2f(static_cast<float>(i + j) / segments, 1.0f);
        }
        glEnd();
    }

    // ...
}
void BasinCylindrical::render() {
    glCallList(listIdx);
}
