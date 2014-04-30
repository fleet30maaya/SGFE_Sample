//
//  SingleLight.cpp
//  cocos2d_tests
//
//  Created by maAya on 14-4-28.
//
//

#include "SingleLight.h"

USING_NS_CC;
USING_NS_CC_EXT;

enum class SingleLightTag {
    SL_TAG_NONE,
    SL_TAG_RED,
    SL_TAG_GREEN,
    SL_TAG_YELLOW,
    SL_TAG_BLUE,
};

SingleLight* SingleLight::create()
{
    SingleLight *pSingleLight = new SingleLight();
    if (pSingleLight && pSingleLight->init())
    {
        pSingleLight->autorelease();
        return pSingleLight;
    }
    CC_SAFE_DELETE(pSingleLight);
    return nullptr;
}

bool SingleLight::init()
{
    if(Node::init())
    {
        auto sprite = Sprite::create("pad/light_off.png");
        addChild(sprite, 0, (int)SingleLightTag::SL_TAG_NONE);

        auto spriter = Sprite::create("pad/light_red.png");
        spriter->setOpacity(0);
        spriter->setVisible(false);
        addChild(spriter, 1, (int)SingleLightTag::SL_TAG_RED);
        
        auto spriteg = Sprite::create("pad/light_green.png");
        spriteg->setOpacity(0);
        spriteg->setVisible(false);
        addChild(spriteg, 2, (int)SingleLightTag::SL_TAG_GREEN);
        
        auto spritey = Sprite::create("pad/light_yellow.png");
        spritey->setOpacity(0);
        spritey->setVisible(false);
        addChild(spritey, 3, (int)SingleLightTag::SL_TAG_YELLOW);
        
        auto spriteb = Sprite::create("pad/light_blue.png");
        spriteb->setOpacity(0);
        spriteb->setVisible(false);
        addChild(spriteb, 4, (int)SingleLightTag::SL_TAG_BLUE);

        return true;
    }
    return false;
}

void SingleLight::turnOn(SingleLightColor color)
{
    if(color == SingleLightColor::OFF)
    {
        turnOff();
        return;
    }
    
    switch (color) {
        case SingleLightColor::OFF:
            turnOff();
            break;
        case SingleLightColor::RED:
            turnOnOneColor( (int)SingleLightTag::SL_TAG_RED);
            turnOffOneColor((int)SingleLightTag::SL_TAG_GREEN);
            turnOffOneColor((int)SingleLightTag::SL_TAG_YELLOW);
            turnOffOneColor((int)SingleLightTag::SL_TAG_BLUE);
            break;
        case SingleLightColor::GREEN:
            turnOffOneColor((int)SingleLightTag::SL_TAG_RED);
            turnOnOneColor( (int)SingleLightTag::SL_TAG_GREEN);
            turnOffOneColor((int)SingleLightTag::SL_TAG_YELLOW);
            turnOffOneColor((int)SingleLightTag::SL_TAG_BLUE);
            break;
        case SingleLightColor::YELLOW:
            turnOffOneColor((int)SingleLightTag::SL_TAG_RED);
            turnOffOneColor((int)SingleLightTag::SL_TAG_GREEN);
            turnOnOneColor( (int)SingleLightTag::SL_TAG_YELLOW);
            turnOffOneColor((int)SingleLightTag::SL_TAG_BLUE);
            break;
        case SingleLightColor::BLUE:
            turnOffOneColor((int)SingleLightTag::SL_TAG_RED);
            turnOffOneColor((int)SingleLightTag::SL_TAG_GREEN);
            turnOffOneColor((int)SingleLightTag::SL_TAG_YELLOW);
            turnOnOneColor( (int)SingleLightTag::SL_TAG_BLUE);
            break;
            
        default:
            break;
    }
}

void SingleLight::turnOff()
{
    turnOffOneColor((int)SingleLightTag::SL_TAG_RED);
    turnOffOneColor((int)SingleLightTag::SL_TAG_GREEN);
    turnOffOneColor((int)SingleLightTag::SL_TAG_YELLOW);
    turnOffOneColor((int)SingleLightTag::SL_TAG_BLUE);
}

void SingleLight::turnOnOneColor(int tag)
{
    if(tag == (int)SingleLightColor::OFF)
        return;
    
    Node* node = this->getChildByTag(tag);
    if(node == nullptr)
        return;
    
    node->stopAllActions();
    node->runAction(Sequence::create(Show::create(),
                                     FadeTo::create(0.1f*(1.0f - (float)node->getOpacity() / 255.0f),
                                                    255),
                                     nullptr));
}

void SingleLight::turnOffOneColor(int tag)
{
    if(tag == (int)SingleLightColor::OFF)
        return;
    
    Node* node = this->getChildByTag(tag);
    if(node == nullptr)
        return;
    
    node->stopAllActions();
    node->runAction(Sequence::create(FadeTo::create(0.1f*((float)node->getOpacity() / 255.0f),
                                                    0),
                                     Hide::create(),
                                     nullptr));
}

