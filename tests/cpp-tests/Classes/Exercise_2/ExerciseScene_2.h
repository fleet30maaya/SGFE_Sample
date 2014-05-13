//
//  ExerciseScene_2.h
//  TestCpp
//
//  Created by maAya on 2014-5-12.
//
//

#ifndef __TestCpp__ExerciseScene_2__
#define __TestCpp__ExerciseScene_2__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "../testBasic.h"

class Exercise_2MainLayer : public Layer
{
public:
    virtual void onEnter() override;
    
    void onTouchesBegan(const std::vector<Touch*>& touches, Event  *event);
    void onTouchesMoved(const std::vector<Touch*>&touches, Event  *event);
    
protected:
    Point _beginPos;
    Menu* _itmeMenu;
};

class Exercise_2BaseLayer : public Layer
{
public:
    virtual void onEnter() override;
    void backCallback(Ref* sender);
};

class ExerciseScene_2 : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* defined(__TestCpp__ExerciseScene_2__) */
