//
// Homework 2.1
//

#include "Homework_2_1.h"
#include "cocostudio/CocoStudio.h"

bool Homework_2_1_Layer::init()
{
    if (Homework_2BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // Add your code here
        
        return true;
    }

    return false;
}
