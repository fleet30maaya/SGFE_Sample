//
//  Experiment_1.h
//  TestCpp
//
//  Created by maAya on 2014-4-28.
//
//

#ifndef __TestCpp__Experiment_1__
#define __TestCpp__Experiment_1__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "../testBasic.h"

class LightBoard;

class PadExerciseLayer : public cocos2d::Layer
{
public:
    PadExerciseLayer();
    virtual ~PadExerciseLayer();
    void toExtensionsMainLayer(cocos2d::Ref *sender);

    void touchInsideAction_Off(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_1(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_2(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_3(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_4(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_5(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_6(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_7(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_8(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_9(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    void touchInsideAction_X(Ref *sender, cocos2d::extension::Control::EventType controlEvent);
    
protected:
    LightBoard* m_board;

};

class Experiment_1 : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* defined(__TestCpp__Experiment_1__) */
