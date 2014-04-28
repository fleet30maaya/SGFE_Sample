//
//  SingleLight.h
//  cocos2d_tests
//
//  Created by maAya on 14-4-28.
//
//

#ifndef __cocos2d_tests__SingleLight__
#define __cocos2d_tests__SingleLight__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

enum class SingleLightColor {
    SL_OFF,
    SL_RED,
    SL_GREEN,
    SL_YELLOW,
    SL_BLUE,
};

class SingleLight : public cocos2d::Node
{
public:
    static SingleLight* create();
    
    void turnOn(SingleLightColor color);
    void turnOff();

protected:
    virtual bool init();
    void turnOnOneColor(int tag);
    void turnOffOneColor(int tag);

};

#endif /* defined(__cocos2d_tests__SingleLight__) */
