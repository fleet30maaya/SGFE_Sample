//
//  HomeworkScene_2.cpp
//  TestCpp
//
//  Created by maAya on 2014-5-13.
//
//

#include "HomeworkScene_2.h"
#include "Homework_2_1.h"
#include "Homework_2_2.h"

USING_NS_CC;
USING_NS_CC_EXT;


////////////////////////////////////////////////////////
//
// Homework_2MainLayer
//
////////////////////////////////////////////////////////
LayerStruct item_h2[] = {
    { "Homework 2.1", [](Ref* sender){ CREATE_HOMEWORK(2_1)} },
    { "Homework 2.2", [](Ref* sender){ CREATE_HOMEWORK(2_2)} },
};
Homework_2MainLayer::Homework_2MainLayer()
{
    g_exs.reset(item_h2);
	g_maxitems = sizeof(item_h2) / sizeof(LayerStruct);
}

Homework_2MainLayer::~Homework_2MainLayer()
{
    g_exs.release();
}

////////////////////////////////////////////////////////
//
// Homework_2BaseLayer
//
////////////////////////////////////////////////////////
void Homework_2BaseLayer::backCallback(Ref* sender)
{
    //    Director::getInstance()->enableRetinaDisplay(false);
    auto scene = new HomeworkScene_2();
    scene->runThisTest();
    scene->autorelease();
}

////////////////////////////////////////////////////////
//
// HomeworkScene_2
//
////////////////////////////////////////////////////////
void HomeworkScene_2::runThisTest()
{
    auto layer = new Homework_2MainLayer();
    addChild(layer);
    layer->release();
    
    Director::getInstance()->replaceScene(this);
}
