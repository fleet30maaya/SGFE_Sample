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
#include "../ExerciseScene.h"
#include "../testBasic.h"

class Homework_2MainLayer : public ExerciseMainLayer
{
public:
    Homework_2MainLayer();
    ~Homework_2MainLayer();
};

class Homework_2BaseLayer : public ExerciseBaseLayer
{
public:
    virtual void backCallback(Ref* sender) override;
};

class HomeworkScene_2 : public ExerciseScene
{
public:
    virtual void runThisTest() override;
};

#endif /* defined(__TestCpp__HomeworkScene_2__) */
