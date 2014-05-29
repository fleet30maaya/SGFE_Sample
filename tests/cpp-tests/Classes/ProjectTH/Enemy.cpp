//
//  Enemy.cpp
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#include "Enemy.h"
#include "Bullet.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "../controller.h"
#include "../VisibleRect.h"
#include "BattleFieldLayer.h"

USING_NS_CC;

enum {
    TAG_FLIGHT_MASK,
};
bool Enemy::init()
{
    if(Node::init())
    {
        auto winSize = Director::getInstance()->getWinSize();

        auto flight = Sprite::create("projectTH/enemy.png");
        flight->setScale(0.5f);
        this->addChild(flight);

        auto flightMask = Sprite::create("projectTH/enemy.png");
        flightMask->setScale(0.5f);
        flightMask->setOpacity(0);
        flightMask->setBlendFunc(BlendFunc::ADDITIVE);
        this->addChild(flightMask, 1, TAG_FLIGHT_MASK);

        m_velocity = Point(0, -5);
        m_life = 200;
        m_hp = 20.0f;
        
        this->scheduleUpdate();
        
        return true;
    }
    return false;
}

void Enemy::update(float delta)
{
    if(!isAlive())
    {
        ((BattleFieldLayer*)this->getParent())->getEnemy().eraseObject(this);
        this->removeFromParent();

        return;
    }
    m_life--;
    
    this->setPosition(Point(this->getPosition().x + m_velocity.x,
                            this->getPosition().y + m_velocity.y));
}

void Enemy::damage(float damage)
{
    auto flightMask = this->getChildByTag(TAG_FLIGHT_MASK);
    flightMask->stopAllActions();
    flightMask->setOpacity(200);
    flightMask->runAction(FadeTo::create(0.05f, 0));
    
    m_hp -= damage;
    if(m_hp <= 0.0f)
    {
        m_life = 0;
        ((BattleFieldLayer*)this->getParent())->doBoom(Point(this->getPosition().x, this->getPosition().y - 50));
    }
}

bool Enemy::isAlive()
{
    return (m_life > 0);
}


