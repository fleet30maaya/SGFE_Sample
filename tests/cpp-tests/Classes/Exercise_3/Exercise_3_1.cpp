//
// Exercise 3.1
//

#include "Exercise_3_1.h"
#include "cocostudio/CocoStudio.h"

bool Exercise_3_1_Layer::init()
{
    if (Exercise_3BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // Add code here
        
        return true;
    }

    return false;
}
