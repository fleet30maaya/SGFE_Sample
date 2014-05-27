//
// Exercise 3.2
//

#include "Exercise_3_2.h"
#include "../CommonTools.h"

bool Exercise_3_2_Layer::init()
{
    if (Exercise_3BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // Add code here
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = CC_CALLBACK_2(Exercise_3_2_Layer::onTouchBegan, this);
        touchListener->onTouchMoved = CC_CALLBACK_2(Exercise_3_2_Layer::onTouchMoved, this);
        touchListener->onTouchEnded = CC_CALLBACK_2(Exercise_3_2_Layer::onTouchEnded, this);
        touchListener->onTouchCancelled = CC_CALLBACK_2(Exercise_3_2_Layer::onTouchCancelled, this);
        dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

        m_colorH = 0.0f;
        m_colorS = 1.0f;
        m_colorV = 1.0f;
        m_touching = false;
        
        this->scheduleUpdate();
        
        return true;
    }

    return false;
}

void Exercise_3_2_Layer::update(float delta)
{
    if(!m_touching)
        return;
    
    auto ring = Sprite::create("exercises/ring.png");
    ring->setPosition(m_touchingPos);
    ring->setScale(0.1f);
    this->addChild(ring);
    
    m_colorH += 5.0f;
    ring->setColor(CommonTools::getRGBFromHSV(m_colorH, m_colorS, m_colorV));
    ring->runAction(Spawn::create(ScaleTo::create(1.5f, 1.5f),
                                  Sequence::create(DelayTime::create(0.7f),
                                                   FadeTo::create(0.8f, 0),
                                                   RemoveSelf::create(),
                                                   NULL),
                                  NULL));

}

bool Exercise_3_2_Layer::onTouchBegan(Touch* touch, Event* event)
{
    auto location = touch->getLocation();
    m_touchingPos = Point(location);
    m_touching = true;

    m_colorH = 0.0f;
    m_colorS = 0.7f;
    m_colorV = 1.0f;

    return true;
}

void Exercise_3_2_Layer::onTouchMoved(Touch* touch, Event* event)
{
    auto location = touch->getLocation();
    m_touchingPos = Point(location);

}

void Exercise_3_2_Layer::onTouchEnded(Touch* touch, Event* event)
{
    m_touching = false;
}

void Exercise_3_2_Layer::onTouchCancelled(Touch* touch, Event* event)
{
    m_touching = false;
}


