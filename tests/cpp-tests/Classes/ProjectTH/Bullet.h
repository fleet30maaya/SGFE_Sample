//
//  Bullet.h
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#ifndef __ProjectTH__Bullet__
#define __ProjectTH__Bullet__

#include "cocos2d.h"
#include "../testBasic.h"

USING_NS_CC;

class Bullet : public Node
{
public:
    CREATE_FUNC(Bullet);
    virtual bool init() override;
    virtual void update(float delta) override;
    
protected:
    Point m_velocity;
    int   m_life;
};

#endif /* defined(__ProjectTH__Bullet__) */
