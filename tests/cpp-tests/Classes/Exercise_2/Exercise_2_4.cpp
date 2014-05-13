//
// Exercise 2.4
//

#include "Exercise_2_4.h"

bool Exercise_2_4_Layer::init()
{
    if (Exercise_2BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        Point pos = Point(size.width / 2, size.height / 2);
        
        auto wheel_0 = Sprite::create("exercises/wheel_outter.png");
        wheel_0->setPosition(pos);
        addChild(wheel_0);
        
//        auto wheel_1 = Sprite::create("exercises/wheel_inner.png");
//        wheel_1->setPosition(pos);
//        wheel_1->runAction(RepeatForever::create(RotateBy::create(5.0f, 1080)));
//        addChild(wheel_1);
//
//        auto wheel_2 = Sprite::create("exercises/wheel_inner.png");
//        wheel_2->setPosition(pos);
//        wheel_2->setAnchorPoint(Point(0.0f, 0.0f));
//        wheel_2->runAction(RepeatForever::create(RotateBy::create(5.0f, 1080)));
//        addChild(wheel_2);
//
//        auto wheel_3 = Sprite::create("exercises/wheel_inner.png");
//        wheel_3->setPosition(pos);
//        wheel_3->setAnchorPoint(Point(-1.0f, 0.5f));
//        wheel_3->runAction(RepeatForever::create(RotateBy::create(5.0f, 1080)));
//        addChild(wheel_3);
//
//        auto wheel_4 = Sprite::create("exercises/wheel_inner.png");
//        wheel_4->setPosition(pos);
//        wheel_4->setAnchorPoint(Point(-5.0f, 0.5f));
//        wheel_4->runAction(RepeatForever::create(RotateBy::create(5.0f, 1080)));
//        addChild(wheel_4);

        return true;
    }

    return false;
}
