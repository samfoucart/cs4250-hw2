#ifndef __DRONE_LAUNCHER_HPP__
#define __DRONE_LAUNCHER_HPP__

#include "Drawable.hpp"
#include "drone.h"

namespace cs4250 {
extern std::stack<mat4> mvStack;
extern mat4 modelView;

class DroneLauncher: public Drawable {
public:
    DroneLauncher();
    const mat4 defaultScale = Scale(.01 * 4, .01 * 4, .3 * 2);
    virtual void draw();
    void moveForward(GLfloat missleTime) { position = defaultPosition + vec3(0, 0, missleTime); }
    const vec3 defaultPosition = vec3(0, -1, 1);
private:
    vec3 position = defaultPosition;
}; // end class


inline DroneLauncher::DroneLauncher() {
    /**
     * Points used to draw a wireframe cube with GL_LINE_STRIP
     */ 
    points = std::vector<vec4>({
                        vec4(-1, -1, -1, 1),
                        vec4(1, -1, -1, 1),
                        vec4(1, 1, -1, 1),
                        vec4(-1, 1, -1, 1),
                        vec4(-1, -1, -1, 1),
                        vec4(1, 1, -1, 1),
                        vec4(1, 1, 1, 1),
                        vec4(-1, 1, -1, 1),
                        vec4(-1, 1, 1, 1),
                        vec4(1, 1, 1, 1),
                        vec4(1, -1, 1, 1),
                        vec4(-1, 1, 1, 1),
                        vec4(-1, -1, 1, 1),
                        vec4(1, -1, 1, 1),
                        vec4(1, 1, -1, 1),
                        vec4(1, -1, -1, 1),
                        vec4(1, -1, 1, 1),
                        vec4(-1, -1, -1, 1),
                        vec4(-1, -1, 1, 1),
                        vec4(-1, 1, 1, 1),
                        vec4(-1, -1, -1, 1),
                        vec4(-1, -1, -1, 1)
                        });

    transformation = defaultScale;
}



inline void DroneLauncher::draw() {
    mvStack.push(modelView);
    mat4 translationMatrix = Translate(position);
    translationMatrix = transpose(translationMatrix);
    transformation = defaultScale * translationMatrix;
    modelView = transformation * modelView;

    glUniformMatrix4fv(cs4250::view_loc, 1, GL_FALSE, modelView);
    glDrawArrays(GL_LINE_STRIP, 0, NumPoints); // draw the lines

    modelView = mvStack.top();
    mvStack.pop();
}

} // end namespace

#endif