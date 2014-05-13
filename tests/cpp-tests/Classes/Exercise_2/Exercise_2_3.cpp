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
        
        
        //
        auto group2 = Node::create();
        group2->setPosition(Point(500, size.height - 450));
        addChild(group2);
        //
        auto airplane = Sprite::create("exercises/airplane.png");
        airplane->setScale(0.2f);
        group2->addChild(airplane);
        auto group2_1 = Node::create();
        group2->addChild(group2_1);
        auto wheel_2 = Sprite::create("exercises/wheel_inner.png");
        wheel_2->setPosition(Point(150, 0));
        group2_1->addChild(wheel_2);
        auto wheel_3 = Sprite::create("exercises/wheel_inner.png");
        wheel_3->setPosition(Point(-150, 0));
        group2_1->addChild(wheel_3);
        group2_1->runAction(RepeatForever::create(RotateBy::create(5.0f, 720)));

        return true;
    }

    return false;
}
