//
//  Bullet.cpp
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#include "Bullet.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "../controller.h"
#include "../VisibleRect.h"
#include "BattleFieldLayer.h"
#include "Enemy.h"

USING_NS_CC;

bool Bullet::init()
{
    if(Node::init())
    {
        auto bullet = Sprite::create("projectTH/bullet.png");
        addChild(bullet);
    
        m_velocity = Point(0, 40);
        m_life = 20;
        
        this->scheduleUpdate();
        
        return true;
    }
    return false;
}

void Bullet::update(float delta)
{
    if(m_life == 0)
    {
        this->removeFromParent();
        return;
    }
    m_life--;
    
    this->setPosition(Point(this->getPosition().x + m_velocity.x,
                            this->getPosition().y + m_velocity.y));
    
    Vector<Enemy*> enemies = ((BattleFieldLayer*)this->getParent())->getEnemy();
    std::vector<Enemy*>::iterator it = enemies.begin();
    while (it != enemies.end()) {
        Enemy* enemy = *it;
        Point ePos = enemy->getPosition();
        Point bPos = this->getPosition();
        if((ePos.x-bPos.x)*(ePos.x-bPos.x)+(ePos.y-bPos.y)*(ePos.y-bPos.y)< 50*50)
        {
            enemy->damage(1.0f);
            m_life = 0;
        }
        it++;
    }
}

