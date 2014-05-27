//
// Exercise 3.1
//

#include "Exercise_3_1.h"
#include "../CommonTools.h"

bool Exercise_3_1_Layer::init()
{
    if (Exercise_3BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // Add code here
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = CC_CALLBACK_2(Exercise_3_1_Layer::onTouchBegan, this);
        touchListener->onTouchMoved = CC_CALLBACK_2(Exercise_3_1_Layer::onTouchMoved, this);
        touchListener->onTouchEnded = CC_CALLBACK_2(Exercise_3_1_Layer::onTouchEnded, this);
        dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

        m_colorH = 0.0f;
        m_colorS = 1.0f;
        m_colorV = 1.0f;
        
        return true;
    }

    return false;
}

bool Exercise_3_1_Layer::onTouchBegan(Touch* touch, Event* event)
{
    auto location = touch->getLocation();
    
    auto ring = Sprite::create("exercises/ring.png");
    ring->setPosition(location);
    ring->setScale(0.1f);
    this->addChild(ring);
    
    m_colorH = 0.0f;
    m_colorS = 0.7f;
    m_colorV = 1.0f;
    ring->setColor(CommonTools::getRGBFromHSV(m_colorH, m_colorS, m_colorV));

    ring->runAction(Spawn::create(ScaleTo::create(1.5f, 1.5f),
                                  Sequence::create(DelayTime::create(0.7f),
                                                   FadeTo::create(0.8f, 0),
                                                   RemoveSelf::create(),
                                                   NULL),
                                  NULL));

    return true;
}

void Exercise_3_1_Layer::onTouchMoved(Touch* touch, Event* event)
{
    auto location = touch->getLocation();
    
    auto ring = Sprite::create("exercises/ring.png");
    ring->setPosition(location);
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

void Exercise_3_1_Layer::onTouchEnded(Touch* touch, Event* event)
{
}
