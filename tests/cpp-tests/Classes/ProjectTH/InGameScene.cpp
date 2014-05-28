//
//  InGameScene.cpp
//  ProjectTH
//
//  Created by maAya on 2014-5-28.
//
//

#include "InGameScene.h"
#include "BackgroundLayer.h"
#include "BattleFieldLayer.h"
#include "HUDLayer.h"
#include "../controller.h"
#include "../VisibleRect.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

bool InGameScene::init()
{
    if(Scene::init())
    {
        return true;
    }
    return false;
}

void testScene_callback1(Ref *sender )
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();

    auto scene = Scene::create();
    
    auto layer = new TestController();
    scene->addChild(layer);
    layer->release();
    
    Director::getInstance()->replaceScene(scene);
}

void InGameScene::onEnter()
{
    Scene::onEnter();
    
    //add the menu item for back to main menu
    TTFConfig ttfConfig("fonts/arial.ttf", 20);
    auto label = Label::createWithTTF(ttfConfig,"MainMenu");
    
    auto menuItem = MenuItemLabel::create(label, testScene_callback1 );
    auto menu = Menu::create(menuItem, NULL);
    
    menu->setPosition( Point::ZERO );
    menuItem->setPosition( Point( VisibleRect::right().x - 50, VisibleRect::bottom().y + 25) );
    
    addChild(menu, 1);
    
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("projectTH/Pilot.mp3");
}

void InGameScene::runThisTest()
{
    Director::getInstance()->replaceScene(this);
    
    auto winSize = Director::getInstance()->getWinSize();

    auto backgroundLayer = BackgroundLayer::create();
    this->addChild(backgroundLayer);
//    backgroundLayer->setScale(0.8f);
    
    auto battlefieldLayer = BattleFieldLayer::create();
    battlefieldLayer->setPosition(Point(winSize.width / 2 - 250, 0));
    this->addChild(battlefieldLayer);
    
    auto hudLayer = HUDLayer::create();
    this->addChild(hudLayer);
    
    SimpleAudioEngine::getInstance()->playBackgroundMusic("projectTH/Pilot.mp3");
}



