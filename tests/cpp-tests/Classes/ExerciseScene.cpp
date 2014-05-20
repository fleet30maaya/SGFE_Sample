//
//  ExerciseScene.cpp
//  TestCpp
//
//  Created by maAya on 2014-5-20.
//
//

#include "ExerciseScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

enum
{
    LINE_SPACE = 40,
    kItemTagBasic = 5432,
};

static Point s_tCurPos = Point::ZERO;

////////////////////////////////////////////////////////
//
// ExerciseMainLayer
//
////////////////////////////////////////////////////////
void ExerciseMainLayer::onEnter()
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
    listener->onTouchesBegan = CC_CALLBACK_2(ExerciseMainLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(ExerciseMainLayer::onTouchesMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void ExerciseMainLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    _beginPos = touches[0]->getLocation();
}

void ExerciseMainLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
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
// ExerciseBaseLayer
//
////////////////////////////////////////////////////////
void ExerciseBaseLayer::onEnter()
{
    Layer::onEnter();
    
    MenuItemFont::setFontName("Arial");
    MenuItemFont::setFontSize(24);
    auto pMainItem = MenuItemFont::create("Back", CC_CALLBACK_1(ExerciseBaseLayer::backCallback, this));
    pMainItem->setPosition(Point(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
    auto menu = Menu::create(pMainItem, NULL);
    menu->setPosition( Point::ZERO );
    addChild(menu);
}

////////////////////////////////////////////////////////
//
// ExerciseScene
//
////////////////////////////////////////////////////////
