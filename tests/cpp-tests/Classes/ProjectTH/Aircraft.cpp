//
//  Aircraft.cpp
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#include "Aircraft.h"
#include "Bullet.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "../controller.h"
#include "../VisibleRect.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

bool Aircraft::init()
{
    if(Node::init())
    {
        auto winSize = Director::getInstance()->getWinSize();

        auto flight = Sprite::create("projectTH/flight.png");
        flight->setScale(0.3f);
        this->addChild(flight);

        auto particle = ParticleSystemQuad::create("projectTH/core_par.plist");
        particle->setPosition(Point(0,-7));
        particle->setPositionType(tPositionType::GROUPED);
        //        particle->setScale(0.3f);
        this->addChild(particle);
        
        m_fireOn = false;
        
        this->scheduleUpdate();
        
        return true;
    }
    return false;
}

void Aircraft::update(float delta)
{
    if(m_fireOn)
    {
        if(m_fireCD == 0)
        {
            if(m_fireSoundCD == 0)
            {
                SimpleAudioEngine::getInstance()->playEffect("projectTH/bullet.mp3");
            }
            m_fireSoundCD = (m_fireSoundCD + 1) % 3;
            for(int i = 0; i < 5; i++)
            {
                auto bullet = Bullet::create();
                float x = (i - 2) * 10 + this->getPosition().x;
                float y = 0 - fabs(i-2) * 10 + this->getPosition().y;
                bullet->setPosition(Point(x,y));
                bullet->setOpacity(180);
                this->getParent()->addChild(bullet);
            }
        }
        
        m_fireCD = (m_fireCD + 1) % 3;
    }
}

void Aircraft::fireOn()
{
    m_fireOn = true;
    m_fireCD = 0;
    m_fireSoundCD = 0;
}

void Aircraft::fireOff()
{
    m_fireOn = false;
    m_fireCD = 0;
    m_fireSoundCD = 0;
}

