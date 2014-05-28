//
//  BattleFieldLayer.h
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#ifndef __ProjectTH__BattleFieldLayer__
#define __ProjectTH__BattleFieldLayer__

#include "cocos2d.h"
#include "../testBasic.h"
#include "Enemy.h"

USING_NS_CC;

class BattleFieldLayer : public Layer
{
public:
    CREATE_FUNC(BattleFieldLayer);
    virtual bool init() override;
    virtual void update(float delta) override;

    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    void onTouchCancelled(Touch* touch, Event* event);

    Vector<Enemy*>& getEnemy();
    
protected:
    Point m_offsetPos;
    Vector<Enemy*> m_enemies;
};

#endif /* defined(__ProjectTH__BattleFieldLayer__) */
