//
// Exercise 2.1
//

#include "Exercise_2_1.h"
#include "cocostudio/CocoStudio.h"

bool Exercise_2_1_Layer::init()
{
    if (Exercise_2BaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        
        // Add a sprite
        auto helloworldSprite = Sprite::create("exercises/hello_world.png");
        helloworldSprite->setPosition(Point(200, size.height - 100));
        addChild(helloworldSprite);
        
        // Add a label (with text "Hello world!")
        // set position to (200, size.height - 400)
        auto helloworldLabel = Label::createWithSystemFont("Hello world!", "", 40);
        helloworldLabel->setPosition(Point(200, size.height - 250));
        addChild(helloworldLabel);
        
        // Add a armature
        // remove sigle resource
        cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo("exercises/helloworld_armature.ExportJson");
        // load resource directly
        cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo("exercises/helloworld_armature.ExportJson");
        
        auto armature = cocostudio::Armature::create("helloworld_armature");
        armature->getAnimation()->playWithIndex(0);
        armature->setPosition(Point(600, size.height - 500));
        addChild(armature);
        
        return true;
    }

    return false;
}
