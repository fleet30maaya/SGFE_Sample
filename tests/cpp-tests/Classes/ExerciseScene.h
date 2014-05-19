//
//  ExerciseScene.h
//  TestCpp
//
//  Created by maAya on 2014-5-20.
//
//

#ifndef __TestCpp__ExerciseScene__
#define __TestCpp__ExerciseScene__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "testBasic.h"

#define CREATE_EXERCISE(__ex__)									\
{															\
Scene* scene = Scene::create();					\
Exercise_##__ex__##_Layer* layer = new Exercise_##__ex__##_Layer();	\
layer->init();                                         \
scene->addChild(layer);                               \
Director::getInstance()->replaceScene(scene);     \
layer->autorelease();                                  \
}

#define CREATE_HOMEWORK(__ex__)									\
{															\
Scene* scene = Scene::create();					\
Homework_##__ex__##_Layer* layer = new Homework_##__ex__##_Layer();	\
layer->init();                                         \
scene->addChild(layer);                               \
Director::getInstance()->replaceScene(scene);     \
layer->autorelease();                                  \
}

struct LayerStruct {
	const char *test_name;
	std::function<void(Ref*)> callback;
};

class ExerciseMainLayer : public Layer
{
public:
    virtual void onEnter() override;
    
    void onTouchesBegan(const std::vector<Touch*>& touches, Event  *event);
    void onTouchesMoved(const std::vector<Touch*>&touches, Event  *event);
    
protected:
    Point _beginPos;
    Menu* _itmeMenu;
    
    std::unique_ptr<LayerStruct[]> g_exs;
    int g_maxitems;
};

class ExerciseBaseLayer : public Layer
{
public:
    virtual void onEnter() override;
    virtual void backCallback(Ref* sender) = 0;
};

class ExerciseScene : public TestScene
{
public:
    virtual void runThisTest() = 0;
};

#endif /* defined(__TestCpp__ExerciseScene__) */
