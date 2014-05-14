//
// Exercise 2.1
//

#include "Exercise_2_1.h"

bool Exercise_2_1_Layer::init()
{
    if (Exercise_2BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // Add a sprite
        auto helloworldSprite = Sprite::create("exercises/hello_world.png");
        helloworldSprite->setPosition(Point(200, size.height - 100));
        addChild(helloworldSprite);
        
        // Add a label (with text "Hello world!")
        // set position to (200, size.height - 250)
        
        // Add a armature
        // set position to (200, size.height - 500)
        
        return true;
    }

    return false;
}
