//
//  ExerciseScene_3.cpp
//  TestCpp
//
//  Created by maAya on 2014-5-20.
//
//

#include "ExerciseScene_3.h"
#include "Exercise_3_1.h"

USING_NS_CC;
USING_NS_CC_EXT;

////////////////////////////////////////////////////////
//
// Exercise_3MainLayer
//
////////////////////////////////////////////////////////
Exercise_3MainLayer::Exercise_3MainLayer()
{
    g_maxitems = 1;
    g_exs.reset(new LayerStruct[g_maxitems] {
        { "Exercise 3.1", [](Ref* sender){ CREATE_EXERCISE(3_1)} }
    });
}

Exercise_3MainLayer::~Exercise_3MainLayer()
{
    g_exs.release();
}

////////////////////////////////////////////////////////
//
// Exercise_3BaseLayer
//
////////////////////////////////////////////////////////
void Exercise_3BaseLayer::backCallback(Ref* sender)
{
    //    Director::getInstance()->enableRetinaDisplay(false);
    auto scene = new ExerciseScene_3();
    scene->runThisTest();
    scene->autorelease();
}

////////////////////////////////////////////////////////
//
// ExerciseScene_3
//
////////////////////////////////////////////////////////
void ExerciseScene_3::runThisTest()
{
    auto layer = new Exercise_3MainLayer();
    addChild(layer);
    layer->release();
    
    Director::getInstance()->replaceScene(this);
}
