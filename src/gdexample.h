#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/input_event_mouse.hpp>
#include <godot_cpp/classes/input_event_mouse_button.hpp>
#include <godot_cpp/classes/rectangle_shape2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/label.hpp>


#include <godot_cpp/classes/resource_loader.hpp>

#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/classes/input_event_mouse.hpp>

#include <godot_cpp/templates/vmap.hpp>

namespace godot {

class The_Game : public Node {
    GDCLASS(The_Game, Node)

    static void _bind_methods();
public:

    bool aPressed;

Node *printer;
    Sprite2D *player; // really a sprite2d.
    Vector2 mousePos;

    Ref<Resource> bulletScene;

    void _ready();
    void _process(double delta);
    void _input(const Ref<InputEvent> &event);

    };


} // end namespace.

#endif
