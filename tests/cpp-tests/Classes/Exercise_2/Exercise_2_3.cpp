//
// Exercise 2.3
//

#include "Exercise_2_3.h"

bool Exercise_2_3_Layer::init()
{
    if (Exercise_2BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        auto group = Node::create();
        group->setPosition(Point(200, size.height - 150));
        addChild(group);
        // rotate animation
        auto wheel_0 = Sprite::create("exercises/wheel_outter.png");
        group->addChild(wheel_0);
        auto wheel_1 = Sprite::create("exercises/wheel_inner.png");
        group->addChild(wheel_1);
        
        group->runAction(RepeatForever::create(Sequence::create(Spawn::create(MoveBy::create(5.0f, Point(600, 0)),
                                                                              RotateBy::create(5.0f, 1080),
                                                                              NULL),
                                                                Spawn::create(MoveBy::create(5.0f, Point(-600, 0)),
                                                                              RotateBy::create(5.0f, -1080),
                                                                              NULL),
                                                                NULL)));
        
        
        return true;
    }

    return false;
}
