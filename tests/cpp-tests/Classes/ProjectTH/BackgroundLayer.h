//
//  BackgroundLayer.h
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#ifndef __ProjectTH__BackgroundLayer__
#define __ProjectTH__BackgroundLayer__

#include "cocos2d.h"
#include "../testBasic.h"

USING_NS_CC;

class BackgroundLayer : public Layer
{
public:
    CREATE_FUNC(BackgroundLayer);
    virtual bool init() override;
    
protected:
    void createNewBackground();
};

#endif /* defined(__ProjectTH__BackgroundLayer__) */
