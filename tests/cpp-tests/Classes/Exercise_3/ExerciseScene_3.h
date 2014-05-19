//
//  ExerciseScene_3.h
//  TestCpp
//
//  Created by maAya on 2014-5-20.
//
//

#ifndef __TestCpp__ExerciseScene_3__
#define __TestCpp__ExerciseScene_3__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "../ExerciseScene.h"
#include "../testBasic.h"

class Exercise_3MainLayer : public ExerciseMainLayer
{
public:
    Exercise_3MainLayer();
    ~Exercise_3MainLayer();
};

class Exercise_3BaseLayer : public ExerciseBaseLayer
{
public:
    virtual void backCallback(Ref* sender) override;
};

class ExerciseScene_3 : public ExerciseScene
{
public:
    virtual void runThisTest() override;
};

#endif /* defined(__TestCpp__ExerciseScene_3__) */
