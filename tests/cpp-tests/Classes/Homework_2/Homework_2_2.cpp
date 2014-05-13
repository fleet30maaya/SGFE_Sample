//
// Homework 2.2
//

#include "Homework_2_2.h"

bool Homework_2_2_Layer::init()
{
    if (Homework_2BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // Add your code here
        
        return true;
    }

    return false;
}
