#include "move.h"

void control_movement::move_forward(glm::mat4& model, float speed)
{
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, speed));
}