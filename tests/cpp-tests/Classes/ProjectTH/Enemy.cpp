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

bool Enemy::init()
{
    if(Node::init())
    {
        auto winSize = Director::getInstance()->getWinSize();

        auto flight = Sprite::create("projectTH/enemy.png");
        flight->setScale(0.5f);
        this->addChild(flight);

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
    m_hp -= damage;
    if(m_hp <= 0.0f)
        m_life = 0;
}

bool Enemy::isAlive()
{
    return (m_life > 0);
}


