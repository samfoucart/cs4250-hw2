#include <vector>
#include "Angel.h"

namespace cs4250 {
class Drawable {
public:
    std::vector<vec4> points;
    mat4 transformation;
    virtual void draw() = 0;
    
};
}