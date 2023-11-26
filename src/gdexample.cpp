#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void The_Game::_bind_methods()
{}

void The_Game::_ready() // begin
{
    // templates.
    printer = get_node<Node>("printer");
    player = this->get_node<Sprite2D>("player");
    String string = "res://bullet_scene.tscn";
    bulletScene = ResourceLoader::get_singleton()->load(string);
}

void The_Game::_process(double delta) // loop
{
    // move the player if they press a

    float speed = 10.f; // 1px/s

    if (this->aPressed)
    {
        // TODO: figure out why the player was moving in an odd way ...
        // where they were going really slowly after A was released.
        Vector2 movDir = Vector2(0.f, 1.f);
        player->set_position( player->get_position() + movDir * delta * speed );

        printer->call( "my_print", "PLAYER MOVED" );
    }

}

// getting all the input events as they come, presumably.
void The_Game::_input(const Ref<InputEvent> &event)
{
    const InputEventKey *key_event = Object::cast_to<const InputEventKey>(*event);	
    const InputEventMouseButton *mouseBttnEvent = Object::cast_to<const InputEventMouseButton>(*event);
    const InputEventMouse  *mouseBttnMotion = Object::cast_to<const InputEventMouse>(*event);

    if (key_event) {
        if ( event->is_action_pressed("go left") )
        {
            // ??
            this->aPressed = true;
        }else   if (event->is_action_released("go left")) this->aPressed = false;
        
    } 


    if (mouseBttnEvent){ 
    // which mouse button.

        if ( MouseButton::MOUSE_BUTTON_LEFT ==  mouseBttnEvent->get_button_index() &&  event->is_pressed())
        {
            // spawn the bullet prefab.
            printer->call( "my_print", "left mouse button printed" );

            // bullet dir.
            float width = 1152;
            float height = 648;
            Vector2 mouseInPlayerSpace = this->mousePos - Vector2( width/2.f, height/2.f);

            Vector2 dir = mouseInPlayerSpace - player->get_position();
            dir = dir / dir.length();

            // instantiate the scene.
            Variant instance = bulletScene->call("instantiate");
            Node *instanceNode = dynamic_cast<Node *>((Object*)(instance));
            instanceNode->set( "movDir", Variant( dir ) );
            this->call("add_child", instance);
            
        }

    }

    if (mouseBttnMotion)
    {
        Vector2 pos = mouseBttnMotion->get_position();
        char buffer[256];
        sprintf( buffer, "Mouse Motion at: (%f, %f)", pos.x, pos.y );
        printer->call("my_print", buffer); 

        this->mousePos = pos;

        //get_viewport().get_visible_rect().size
    }

}

