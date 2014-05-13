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

#define CREATE_EXERCISE(__ex__)									\
{															\
Scene* scene = Scene::create();					\
Exercise_##__ex__##_Layer* layer = new Exercise_##__ex__##_Layer();	\
layer->init();                                         \
scene->addChild(layer);                               \
Director::getInstance()->replaceScene(scene);     \
layer->autorelease();                                  \
}

enum
{
    LINE_SPACE = 40,
    kItemTagBasic = 5432,
};

static Point s_tCurPos = Point::ZERO;

struct {
	const char *test_name;
	std::function<void(Ref*)> callback;
} g_exs[] = {
	{ "Exercise 2.1", [](Ref* sender){ CREATE_EXERCISE(2_1)} },
	{ "Exercise 2.2", [](Ref* sender){ CREATE_EXERCISE(2_2)} },
	{ "Exercise 2.3", [](Ref* sender){ CREATE_EXERCISE(2_3)} },
	{ "Exercise 2.4", [](Ref* sender){ CREATE_EXERCISE(2_4)} },
};

static const int g_maxitems = sizeof(g_exs) / sizeof(g_exs[0]);


////////////////////////////////////////////////////////
//
// Exercise_2MainLayer
//
////////////////////////////////////////////////////////
void Exercise_2MainLayer::onEnter()
{
    Layer::onEnter();
    
    auto s = Director::getInstance()->getWinSize();
    _itmeMenu = Menu::create();
    MenuItemFont::setFontName("Arial");
    MenuItemFont::setFontSize(24);
    for (int i = 0; i < g_maxitems; ++i)
    {
        auto pItem = MenuItemFont::create(g_exs[i].test_name, g_exs[i].callback);
        pItem->setPosition(Point(s.width / 2, s.height - (i + 2) * LINE_SPACE));
        _itmeMenu->addChild(pItem, kItemTagBasic + i);
    }
    
    _itmeMenu->setPosition(s_tCurPos);
    addChild(_itmeMenu);
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(Exercise_2MainLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(Exercise_2MainLayer::onTouchesMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Exercise_2MainLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    _beginPos = touches[0]->getLocation();
}

void Exercise_2MainLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
    auto touchLocation = touches[0]->getLocation();
    float nMoveY = touchLocation.y - _beginPos.y;
    
    auto curPos  = _itmeMenu->getPosition();
    auto nextPos = Point(curPos.x, curPos.y + nMoveY);
    auto winSize = Director::getInstance()->getWinSize();
    if (nextPos.y < 0.0f)
    {
        _itmeMenu->setPosition(Point::ZERO);
        return;
    }
    
    if (nextPos.y > ((g_maxitems + 1)* LINE_SPACE - winSize.height))
    {
        _itmeMenu->setPosition(Point(0, ((g_maxitems + 1)* LINE_SPACE - winSize.height)));
        return;
    }
    
    _itmeMenu->setPosition(nextPos);
    _beginPos = touchLocation;
    s_tCurPos   = nextPos;
}

////////////////////////////////////////////////////////
//
// Exercise_2BaseLayer
//
////////////////////////////////////////////////////////
void Exercise_2BaseLayer::onEnter()
{
    Layer::onEnter();
    
    MenuItemFont::setFontName("Arial");
    MenuItemFont::setFontSize(24);
    auto pMainItem = MenuItemFont::create("Back", CC_CALLBACK_1(Exercise_2BaseLayer::backCallback, this));
    pMainItem->setPosition(Point(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
    auto menu = Menu::create(pMainItem, NULL);
    menu->setPosition( Point::ZERO );
    addChild(menu);
}

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
