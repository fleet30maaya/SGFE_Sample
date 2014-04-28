//
//  LightBoard.h
//  cocos2d_tests
//
//  Created by maAya on 14-4-28.
//
//

#ifndef __cocos2d_tests__LightBoard__
#define __cocos2d_tests__LightBoard__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "SingleLight.h"

class LightBoard : public cocos2d::Node
{
public:
    static LightBoard* create(int width, int height);
    
    void turnOn(int x, int y, SingleLightColor color);
    void turnOff(int x, int y);
    void turnOffAll();

protected:
    virtual bool initWithSize(int width, int height);
    std::vector<std::vector<SingleLight*>> m_lightBoard;
};

#endif /* defined(__cocos2d_tests__LightBoard__) */
