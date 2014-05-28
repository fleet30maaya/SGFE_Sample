//
//  InGameScene.h
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#ifndef __ProjectTH__InGameScene__
#define __ProjectTH__InGameScene__

#include "cocos2d.h"
#include "../testBasic.h"

USING_NS_CC;

class InGameScene : public TestScene
{
public:
    virtual bool init() override;
    virtual void onEnter() override;
    virtual void runThisTest() override;
};

#endif /* defined(__ProjectTH__InGameScene__) */
