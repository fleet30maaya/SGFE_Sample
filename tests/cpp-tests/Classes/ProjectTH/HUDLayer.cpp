//
//  HUDLayer.cpp
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#include "HUDLayer.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "../controller.h"
#include "../VisibleRect.h"

USING_NS_CC;

bool HUDLayer::init()
{
    if(Layer::init())
    {
        auto winSize = Director::getInstance()->getWinSize();

        auto back_l = Sprite::create("projectTH/hud_background.png");
        back_l->setAnchorPoint(Point(1.0f, 0.5f));
        back_l->setPosition(Point(winSize.width/2 - 250, winSize.height/2));
        addChild(back_l);
        
        auto back_r = Sprite::create("projectTH/hud_background.png");
        back_r->setAnchorPoint(Point(0.0f, 0.5f));
        back_r->setPosition(Point(winSize.width/2 + 250, winSize.height/2));
        addChild(back_r);

        return true;
    }
    return false;
}


