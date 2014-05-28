//
//  Enemy.h
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#ifndef __ProjectTH__Enemy__
#define __ProjectTH__Enemy__

#include "cocos2d.h"
#include "../testBasic.h"

USING_NS_CC;

class Enemy : public Node
{
public:
    CREATE_FUNC(Enemy);
    virtual bool init() override;
    virtual void update(float delta) override;
    void damage(float damage);
    bool isAlive();
    
protected:
    Point m_velocity;
    int   m_life;
    float m_hp;
};

#endif /* defined(__ProjectTH__Enemy__) */
