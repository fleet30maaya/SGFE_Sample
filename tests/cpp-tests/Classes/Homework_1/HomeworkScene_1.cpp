//
//  HomeworkScene_1.cpp
//  TestCpp
//
//  Created by maAya on 2014-4-25.
//
//

#include "HomeworkScene_1.h"

USING_NS_CC;
USING_NS_CC_EXT;


LogicTestLayer::LogicTestLayer()
{
    auto glview = Director::getInstance()->getOpenGLView();
    auto visibleOrigin = glview->getVisibleOrigin();
    auto visibleSize = glview->getVisibleSize();
    
    auto editBoxSize = Size(visibleSize.width - 500, 60);

    // top
    _edit_1 = EditBox::create(editBoxSize, Scale9Sprite::create("extensions/green_edit.png"));
    _edit_1->setPosition(Point(visibleOrigin.x+visibleSize.width/2, visibleOrigin.y+visibleSize.height - 200.0f));
    _edit_1->setFont("Paint Boy", 25);
    _edit_1->setPlaceholderFont("Paint Boy", 25);
    _edit_1->setFontColor(Color3B::WHITE);
    _edit_1->setPlaceHolder("Even Sum");
    _edit_1->setInputMode(EditBox::InputMode::NUMERIC);
    _edit_1->setReturnType(EditBox::KeyboardReturnType::DONE);
    _edit_1->setDelegate(this);
    addChild(_edit_1);
    
    _button_1 = ControlButton::create(Label::createWithSystemFont("Result", "Paint Boy", 25),
                                      Scale9Sprite::create("extensions/green_edit.png"));
    _button_1->setPosition(Point(visibleOrigin.x+visibleSize.width/2 - 250 + _button_1->getContentSize().width/2,
                                 visibleOrigin.y+visibleSize.height - 260.0f));
    _button_1->addTargetWithActionForControlEvents(this, cccontrol_selector(LogicTestLayer::touchInsideAction_1),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_1);
    
    _label_1 = Label::createWithSystemFont("0", "Paint Boy", 25, Size::ZERO, TextHAlignment::LEFT);
    _label_1->setColor(Color3B::WHITE);
    _label_1->setAnchorPoint(Point(1.0f, 0.5f));
    _label_1->setPosition(Point(visibleOrigin.x+visibleSize.width/2 + 250,
                                visibleOrigin.y+visibleSize.height - 260.0f));
    addChild(_label_1);

    // middle
    _edit_2 = EditBox::create(editBoxSize, Scale9Sprite::create("extensions/orange_edit.png"));
    _edit_2->setPosition(Point(visibleOrigin.x+visibleSize.width/2, visibleOrigin.y+visibleSize.height - 350.0f));
    _edit_2->setFont("American Typewriter", 25);
    _edit_2->setPlaceholderFont("American Typewriter", 25);
    _edit_2->setFontColor(Color3B::GREEN);
    _edit_2->setPlaceHolder("Factorial");
    _edit_2->setInputMode(EditBox::InputMode::NUMERIC);
    _edit_2->setDelegate(this);
    addChild(_edit_2);
    
    _button_2 = ControlButton::create(Label::createWithSystemFont("Result", "American Typewriter", 25),
                                      Scale9Sprite::create("extensions/orange_edit.png"));
    _button_2->setPosition(Point(visibleOrigin.x+visibleSize.width/2 - 250 + _button_2->getContentSize().width/2,
                                 visibleOrigin.y+visibleSize.height - 410.0f));
    _button_2->addTargetWithActionForControlEvents(this, cccontrol_selector(LogicTestLayer::touchInsideAction_2),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_2);

    _label_2 = Label::createWithSystemFont("0", "American Typewriter", 25, Size::ZERO, TextHAlignment::LEFT);
    _label_2->setColor(Color3B::WHITE);
    _label_2->setAnchorPoint(Point(1.0f, 0.5f));
    _label_2->setPosition(Point(visibleOrigin.x+visibleSize.width/2 + 250,
                                visibleOrigin.y+visibleSize.height - 410.0f));
    addChild(_label_2);

    // bottom
    _edit_3 = EditBox::create(Size(editBoxSize.width, editBoxSize.height), Scale9Sprite::create("extensions/yellow_edit.png"));
    _edit_3->setPosition(Point(visibleOrigin.x+visibleSize.width/2, visibleOrigin.y+visibleSize.height - 500.0f));
    _edit_3->setPlaceHolder("Invisible Button");
    _edit_3->setInputMode(EditBox::InputMode::NUMERIC);
    _edit_3->setDelegate(this);
    addChild(_edit_3);
    
    _button_3 = ControlButton::create(Label::createWithSystemFont("Result", "American Typewriter", 25),
                                      Scale9Sprite::create("extensions/yellow_edit.png"));
    _button_3->setPosition(Point(visibleOrigin.x+visibleSize.width/2 - 250 + _button_2->getContentSize().width/2,
                                 visibleOrigin.y+visibleSize.height -560.0f));
    _button_3->addTargetWithActionForControlEvents(this, cccontrol_selector(LogicTestLayer::touchInsideAction_3),
                                                   Control::EventType::TOUCH_DOWN);
    addChild(_button_3);

    this->setPosition(Point(10, 20));
}

LogicTestLayer::~LogicTestLayer()
{
    
}

void LogicTestLayer::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidBegin !", editBox);
}

void LogicTestLayer::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox)
{
    log("editBox %p DidEnd !", editBox);
}

void LogicTestLayer::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
    log("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

void LogicTestLayer::editBoxReturn(EditBox* editBox)
{
    log("editBox %p was returned !",editBox);
}

void LogicTestLayer::touchInsideAction_1(Ref *sender, Control::EventType controlEvent)
{
    log("button 1 clicked !");
    
    std::string numStr = std::string(_edit_1->getText());
    if(numStr.find_first_not_of("1234567890") != std::string::npos)
    {
        log("Invalid input");
        _label_1->setString("Invalid");
    }
    else
    {
        int result = getEvenSumTo(atoi(_edit_1->getText()));
        std::stringstream ss;
        ss << result;
        _label_1->setString(std::string(ss.str()));
    }
}

void LogicTestLayer::touchInsideAction_2(Ref *sender, Control::EventType controlEvent)
{
    log("button 2 clicked !");
    
    std::string numStr = std::string(_edit_2->getText());
    if(numStr.find_first_not_of("-1234567890") != std::string::npos)
    {
        log("Invalid input");
        _label_2->setString("Invalid");
    }
    else
    {
        int result = getFactorialTo(atoi(_edit_2->getText()));
        std::stringstream ss;
        ss << result;
        _label_2->setString(std::string(ss.str()));
    }
}

void LogicTestLayer::touchInsideAction_3(Ref *sender, Control::EventType controlEvent)
{
    log("button 3 clicked !");
}

int LogicTestLayer::getEvenSumTo(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            sum = sum + i;
        }
    }

    return sum;
}

int LogicTestLayer::getFactorialTo(int n)
{
    int a = 1;
    for(int i = 1; i <= n; i++)
    {
        a = a * i;
    }
    
    return a;
}

////////////////////////////////////////////////////////
//
// HomeworkScene_1
//
////////////////////////////////////////////////////////

void HomeworkScene_1::runThisTest()
{
    auto layer = new LogicTestLayer();
    addChild(layer);
    layer->release();
    
    Director::getInstance()->replaceScene(this);
}


