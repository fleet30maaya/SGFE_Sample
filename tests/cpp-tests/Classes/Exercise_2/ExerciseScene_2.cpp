//
//  ExerciseScene_2.cpp
//  TestCpp
//
//  Created by maAya on 2014-5-12.
//
//

#include "ExerciseScene_2.h"
#include "Exercise_2_1.h"
#include "Exercise_2_2.h"
#include "Exercise_2_3.h"
#include "Exercise_2_4.h"

USING_NS_CC;
USING_NS_CC_EXT;

////////////////////////////////////////////////////////
//
// Exercise_2MainLayer
//
////////////////////////////////////////////////////////
Exercise_2MainLayer::Exercise_2MainLayer()
{
    g_maxitems = 4;
    g_exs.reset(new LayerStruct[g_maxitems] {
        { "Exercise 2.1", [](Ref* sender){ CREATE_EXERCISE(2_1)} },
        { "Exercise 2.2", [](Ref* sender){ CREATE_EXERCISE(2_2)} },
        { "Exercise 2.3", [](Ref* sender){ CREATE_EXERCISE(2_3)} },
        { "Exercise 2.4", [](Ref* sender){ CREATE_EXERCISE(2_4)} }
    });
}

Exercise_2MainLayer::~Exercise_2MainLayer()
{
    g_exs.release();
}

////////////////////////////////////////////////////////
//
// Exercise_2BaseLayer
//
////////////////////////////////////////////////////////
void Exercise_2BaseLayer::backCallback(Ref* sender)
{
    //    Director::getInstance()->enableRetinaDisplay(false);
    auto scene = new ExerciseScene_2();
    scene->runThisTest();
    scene->autorelease();
}

////////////////////////////////////////////////////////
//
// ExerciseScene_2
//
////////////////////////////////////////////////////////
void ExerciseScene_2::runThisTest()
{
    auto layer = new Exercise_2MainLayer();
    addChild(layer);
    layer->release();
    
    Director::getInstance()->replaceScene(this);
}
