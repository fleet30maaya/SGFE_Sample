//
// Exercise 2.2
//

#include "Exercise_2_2.h"

bool Exercise_2_2_Layer::init()
{
    if (Exercise_2BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // rotate animation
        auto wheel_1 = Sprite::create("exercises/wheel_inner.png");
        wheel_1->setPosition(Point(200, size.height - 100));
        addChild(wheel_1);
        wheel_1->runAction(RotateBy::create(5.0f, 720));
        
        // looped rotate animation
        auto wheel_2 = Sprite::create("exercises/wheel_inner.png");
        wheel_2->setPosition(Point(300, size.height - 100));
        addChild(wheel_2);
        wheel_2->runAction(RepeatForever::create(RotateBy::create(5.0f, 720)));
        
        // move animation
        auto wheel_3 = Sprite::create("exercises/wheel_inner.png");
        wheel_3->setPosition(Point(200, size.height - 250));
        addChild(wheel_3);
        wheel_3->runAction(MoveBy::create(5.0f, Point(600, 0)));

        // move & rotate
        auto wheel_4 = Sprite::create("exercises/wheel_inner.png");
        wheel_4->setPosition(Point(200, size.height - 400));
        addChild(wheel_4);
        wheel_4->runAction(Spawn::create(MoveBy::create(5.0f, Point(600, 0)),
                                         RotateBy::create(5.0f, 1080),
                                         NULL));

        // looped move & rotate
        auto wheel_5 = Sprite::create("exercises/wheel_inner.png");
        wheel_5->setPosition(Point(200, size.height - 550));
        addChild(wheel_5);
        wheel_5->runAction(RepeatForever::create(Sequence::create(Spawn::create(MoveBy::create(5.0f, Point(600, 0)),
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
