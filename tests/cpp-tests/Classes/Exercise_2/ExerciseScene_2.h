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
#include "../ExerciseScene.h"
#include "../testBasic.h"

class Exercise_2MainLayer : public ExerciseMainLayer
{
public:
    Exercise_2MainLayer();
    ~Exercise_2MainLayer();
};

class Exercise_2BaseLayer : public ExerciseBaseLayer
{
public:
    virtual void backCallback(Ref* sender) override;
};

class ExerciseScene_2 : public ExerciseScene
{
public:
    virtual void runThisTest() override;
};

#endif /* defined(__TestCpp__ExerciseScene_2__) */
