//
//  BackgroundLayer.cpp
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#include "BackgroundLayer.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "../controller.h"
#include "../VisibleRect.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
    if(Layer::init())
    {
        auto winSize = Director::getInstance()->getWinSize();

        auto sp = Sprite::create("projectTH/background.png");
        sp->setPosition(winSize.width/2, 300);
        sp->setScaleY(1.01f);
        sp->runAction(Sequence::create(MoveBy::create(10.0f, Point(0, -750)),
                                       CallFunc::create(CC_CALLBACK_0(BackgroundLayer::createNewBackground, this)),
                                       RemoveSelf::create(),
                                       NULL));
        this->addChild(sp);
        
        auto sp2 = Sprite::create("projectTH/background.png");
        sp2->setPosition(winSize.width/2, 300+750);
        sp2->setScaleY(1.01f);
        sp2->runAction(Sequence::create(MoveBy::create(20.0f, Point(0, -750*2)),
                                        CallFunc::create(CC_CALLBACK_0(BackgroundLayer::createNewBackground, this)),
                                        RemoveSelf::create(),
                                        NULL));
        this->addChild(sp2);
        
        auto sp3 = Sprite::create("projectTH/background.png");
        sp3->setPosition(winSize.width/2, 300+750*2);
        sp3->setScaleY(1.01f);
        sp3->runAction(Sequence::create(MoveBy::create(30.0f, Point(0, -750*3)),
                                        CallFunc::create(CC_CALLBACK_0(BackgroundLayer::createNewBackground, this)),
                                        RemoveSelf::create(),
                                        NULL));
        this->addChild(sp3);
        
        return true;
    }
    return false;
}

void BackgroundLayer::createNewBackground()
{
    auto winSize = Director::getInstance()->getWinSize();

    auto sp = Sprite::create("projectTH/background.png");
    sp->setPosition(winSize.width/2, 300+750*2);
    sp->setScaleY(1.01f);
    sp->runAction(Sequence::create(MoveBy::create(30.0f, Point(0, -750*3)),
                                   CallFunc::create(CC_CALLBACK_0(BackgroundLayer::createNewBackground, this)),
                                   RemoveSelf::create(),
                                   NULL));
    this->addChild(sp);
}

