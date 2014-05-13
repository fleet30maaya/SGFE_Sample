//
//  HomeworkScene_2.h
//  TestCpp
//
//  Created by maAya on 2014-5-13.
//
//

#ifndef __TestCpp__HomeworkScene_2__
#define __TestCpp__HomeworkScene_2__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "../testBasic.h"

class Homework_2MainLayer : public Layer
{
public:
    virtual void onEnter() override;
    
    void onTouchesBegan(const std::vector<Touch*>& touches, Event  *event);
    void onTouchesMoved(const std::vector<Touch*>&touches, Event  *event);
    
protected:
    Point _beginPos;
    Menu* _itmeMenu;
};

class Homework_2BaseLayer : public Layer
{
public:
    virtual void onEnter() override;
    void backCallback(Ref* sender);
};

class HomeworkScene_2 : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* defined(__TestCpp__HomeworkScene_2__) */
