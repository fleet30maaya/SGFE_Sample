//
//  HomeworkScene_1.h
//  TestCpp
//
//  Created by maAya on 2014-4-25.
//
//

#ifndef __TestCpp__HomeworkScene_1__
#define __TestCpp__HomeworkScene_1__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "../testBasic.h"

class LogicTestLayer : public cocos2d::Layer, public cocos2d::extension::EditBoxDelegate
{
public:
    LogicTestLayer();
    virtual ~LogicTestLayer();
    void toExtensionsMainLayer(cocos2d::Ref *sender);
    
    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);
    void touchInsideAction_1(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_2(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_3(Ref *sender, cocos2d::extension::Control::EventType controlEvent);

private:
    int getEvenSumTo(int n);    // 返回到n之前的偶数之和
    int getFactorialTo(int n);  // 返回n的阶乘
    
    cocos2d::extension::EditBox* _edit_1;
    cocos2d::extension::EditBox* _edit_2;
    cocos2d::extension::EditBox* _edit_3;
    cocos2d::extension::ControlButton * _button_1;
    cocos2d::extension::ControlButton * _button_2;
    cocos2d::extension::ControlButton * _button_3;
    cocos2d::Label* _label_1;
    cocos2d::Label* _label_2;
    cocos2d::Label* _label_3;
};

class HomeworkScene_1 : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* defined(__TestCpp__HomeworkScene_1__) */
