//
//  BattleFieldLayer.cpp
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#include "BattleFieldLayer.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "../controller.h"
#include "../VisibleRect.h"
#include "Aircraft.h"
#include "Enemy.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

enum {
    TAG_FLIGHT,
    TAG_BOOM_BATCH,
};

bool BattleFieldLayer::init()
{
    if(Layer::init())
    {
        auto winSize = Director::getInstance()->getWinSize();

        auto flight = Aircraft::create();
        flight->setPosition(Point(250, 250));
        this->addChild(flight,0,TAG_FLIGHT);
        
        auto dispatcher = Director::getInstance()->getEventDispatcher();

        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = CC_CALLBACK_2(BattleFieldLayer::onTouchBegan, this);
        touchListener->onTouchMoved = CC_CALLBACK_2(BattleFieldLayer::onTouchMoved, this);
        touchListener->onTouchEnded = CC_CALLBACK_2(BattleFieldLayer::onTouchEnded, this);
        touchListener->onTouchCancelled = CC_CALLBACK_2(BattleFieldLayer::onTouchCancelled, this);
        dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

        auto cache = SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("projectTH/boom.plist");
        cache->addSpriteFramesWithFile("projectTH/boom.plist", "projectTH/boom.png");
        auto spritebatch = SpriteBatchNode::create("projectTH/boom.png");
        addChild(spritebatch, 0, TAG_BOOM_BATCH);

        this->scheduleUpdate();
        
        return true;
    }
    return false;
}

bool BattleFieldLayer::onTouchBegan(Touch* touch, Event* event)
{
    // ...
    Point touchPos = touch->getLocation();
    Aircraft* flight = (Aircraft*)this->getChildByTag(TAG_FLIGHT);
    m_offsetPos = Point(flight->getPosition().x - touchPos.x,
                        flight->getPosition().y - touchPos.y);
    flight->fireOn();

    return true;
}

void BattleFieldLayer::onTouchMoved(Touch* touch, Event* event)
{
    Point touchPos = touch->getLocation();
    Aircraft* flight = (Aircraft*)this->getChildByTag(TAG_FLIGHT);
    float x = m_offsetPos.x + touchPos.x;
    float y = m_offsetPos.y + touchPos.y;
    if(x < 0.0f) x = 0.0f;
    if(x > 500.0f) x = 500.0f;
    if(y < 0.0f) y = 0.0f;
    if(y > 768.0f) y = 768.0f;
    flight->setPosition(Point(x, y));
    
    m_offsetPos = Point(flight->getPosition().x - touchPos.x,
                        flight->getPosition().y - touchPos.y);
}

void BattleFieldLayer::onTouchEnded(Touch* touch, Event* event)
{
    Aircraft* flight = (Aircraft*)this->getChildByTag(TAG_FLIGHT);
    flight->fireOff();
}

void BattleFieldLayer::onTouchCancelled(Touch* touch, Event* event)
{
    
}

void BattleFieldLayer::update(float delta)
{
    if((float)rand() / (float)RAND_MAX > 0.95f)
    {
        auto enemy = Enemy::create();
        enemy->setPosition(Point(50 + (float)rand() / (float)RAND_MAX * 400, 800));
        addChild(enemy);
        
        m_enemies.pushBack(enemy);
    }
}

Vector<Enemy*>& BattleFieldLayer::getEnemy()
{
    return m_enemies;
}

void BattleFieldLayer::doBoom(Point pos)
{
    SimpleAudioEngine::getInstance()->playEffect("projectTH/boom.mp3");

    auto cache = SpriteFrameCache::getInstance();
    auto spritebatch = this->getChildByTag(TAG_BOOM_BATCH);
    
    auto _sprite1 = Sprite::createWithSpriteFrameName("b_skilleffect_5_00008.png");
    _sprite1->setPosition(pos);
    spritebatch->addChild(_sprite1);
    
    Vector<SpriteFrame*> animFrames(19);
    
    char str[100] = {0};
    for(int i = 8; i < 26; i++)
    {
        sprintf(str, "b_skilleffect_5_%05d.png", i);
        auto frame = cache->getSpriteFrameByName( str );
        animFrames.pushBack(frame);
    }
    
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.03f);
    _sprite1->runAction(Spawn::create(ScaleTo::create(0.6f, 1.2f),
                                      Sequence::create(Animate::create(animation),
                                                       RemoveSelf::create(),
                                                       NULL),
                                      NULL));
    _sprite1->setRotation(360 * (float)rand() / (float)RAND_MAX);
}


