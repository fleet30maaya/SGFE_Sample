//
//  Experiment_1.cpp
//  TestCpp
//
//  Created by maAya on 2014-4-28.
//
//

#include "Experiment_1.h"
#include "../View/LightBoard.h"

USING_NS_CC;
USING_NS_CC_EXT;


PadExerciseLayer::PadExerciseLayer()
{
    auto glview = Director::getInstance()->getOpenGLView();
    auto visibleOrigin = glview->getVisibleOrigin();
    auto visibleSize = glview->getVisibleSize();
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            m_board = LightBoard::create(16, 12);
            m_board->setPosition(Point(visibleOrigin.x + 200,
                                       visibleOrigin.y + visibleSize.height - 50));
            addChild(m_board);
        }
    }
    
    auto _button_Off = ControlButton::create(Label::createWithSystemFont("Turn Off", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_Off->setPosition(Point(visibleOrigin.x + 200.0f + 100.0f,
                                 visibleOrigin.y + 80.0f));
    _button_Off->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_Off),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_Off);

    auto _button_1 = ControlButton::create(Label::createWithSystemFont("1", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_1->setPosition(Point(visibleOrigin.x + 200.0f + 200.0f,
                                 visibleOrigin.y + 80.0f));
    _button_1->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_1),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_1);

    auto _button_2 = ControlButton::create(Label::createWithSystemFont("2", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_2->setPosition(Point(visibleOrigin.x + 200.0f + 250.0f,
                                 visibleOrigin.y + 80.0f));
    _button_2->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_2),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_2);

    auto _button_3 = ControlButton::create(Label::createWithSystemFont("3", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_3->setPosition(Point(visibleOrigin.x + 200.0f + 300.0f,
                                 visibleOrigin.y + 80.0f));
    _button_3->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_3),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_3);

    auto _button_4 = ControlButton::create(Label::createWithSystemFont("4", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_4->setPosition(Point(visibleOrigin.x + 200.0f + 350.0f,
                                 visibleOrigin.y + 80.0f));
    _button_4->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_4),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_4);
    
    auto _button_5 = ControlButton::create(Label::createWithSystemFont("5", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_5->setPosition(Point(visibleOrigin.x + 200.0f + 400.0f,
                                 visibleOrigin.y + 80.0f));
    _button_5->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_5),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_5);
    
    auto _button_6 = ControlButton::create(Label::createWithSystemFont("6", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_6->setPosition(Point(visibleOrigin.x + 200.0f + 200.0f,
                                 visibleOrigin.y + 30.0f));
    _button_6->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_6),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_6);
    
    auto _button_7 = ControlButton::create(Label::createWithSystemFont("7", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_7->setPosition(Point(visibleOrigin.x + 200.0f + 250.0f,
                                 visibleOrigin.y + 30.0f));
    _button_7->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_7),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_7);
    
    auto _button_8 = ControlButton::create(Label::createWithSystemFont("8", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_8->setPosition(Point(visibleOrigin.x + 200.0f + 300.0f,
                                 visibleOrigin.y + 30.0f));
    _button_8->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_8),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_8);
    
    auto _button_9 = ControlButton::create(Label::createWithSystemFont("9", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_9->setPosition(Point(visibleOrigin.x + 200.0f + 350.0f,
                                 visibleOrigin.y + 30.0f));
    _button_9->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_9),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_9);
    
    auto _button_X = ControlButton::create(Label::createWithSystemFont("X", "American Typewriter", 25),
                                           Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_X->setPosition(Point(visibleOrigin.x + 200.0f + 400.0f,
                                 visibleOrigin.y + 30.0f));
    _button_X->addTargetWithActionForControlEvents(this, cccontrol_selector(PadExerciseLayer::touchInsideAction_X),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_X);
}

PadExerciseLayer::~PadExerciseLayer()
{
    
}

void PadExerciseLayer::touchInsideAction_Off(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button Turn Off");
    m_board->turnOffAll();
}

void PadExerciseLayer::touchInsideAction_1(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 1");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_2(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 2");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_3(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 3");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_4(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 4");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_5(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 5");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_6(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 6");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_7(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 7");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_8(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 8");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_9(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button 9");
    // Add code here
}

void PadExerciseLayer::touchInsideAction_X(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
    log("Button X");
    // Add code here
}

////////////////////////////////////////////////////////
//
// Experiment_1
//
////////////////////////////////////////////////////////

void Experiment_1::runThisTest()
{
    auto layer = new PadExerciseLayer();
    addChild(layer);
    layer->release();
    
    Director::getInstance()->replaceScene(this);
}


