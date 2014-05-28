//
//  Aircraft.h
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#ifndef __ProjectTH__Aircraft__
#define __ProjectTH__Aircraft__

#include "cocos2d.h"
#include "../testBasic.h"

USING_NS_CC;

class Aircraft : public Node
{
public:
    CREATE_FUNC(Aircraft);
    virtual bool init() override;
    virtual void update(float delta) override;
    
    void fireOn();
    void fireOff();
    
protected:
    bool m_fireOn;
    int  m_fireCD;
};

#endif /* defined(__ProjectTH__Aircraft__) */
