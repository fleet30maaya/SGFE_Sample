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

#define CREATE_HOMEWORK(__ex__)									\
{															\
Scene* scene = Scene::create();					\
Homework_##__ex__##_Layer* layer = new Homework_##__ex__##_Layer();	\
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
	{ "Homework 2.1", [](Ref* sender){ CREATE_HOMEWORK(2_1)} },
	{ "Homework 2.2", [](Ref* sender){ CREATE_HOMEWORK(2_2)} },
};

static const int g_maxitems = sizeof(g_exs) / sizeof(g_exs[0]);


////////////////////////////////////////////////////////
//
// Homework_2MainLayer
//
////////////////////////////////////////////////////////
void Homework_2MainLayer::onEnter()
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
    listener->onTouchesBegan = CC_CALLBACK_2(Homework_2MainLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(Homework_2MainLayer::onTouchesMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Homework_2MainLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    _beginPos = touches[0]->getLocation();
}

void Homework_2MainLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
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
// Homework_2BaseLayer
//
////////////////////////////////////////////////////////
void Homework_2BaseLayer::onEnter()
{
    Layer::onEnter();
    
    MenuItemFont::setFontName("Arial");
    MenuItemFont::setFontSize(24);
    auto pMainItem = MenuItemFont::create("Back", CC_CALLBACK_1(Homework_2BaseLayer::backCallback, this));
    pMainItem->setPosition(Point(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
    auto menu = Menu::create(pMainItem, NULL);
    menu->setPosition( Point::ZERO );
    addChild(menu);
}

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
