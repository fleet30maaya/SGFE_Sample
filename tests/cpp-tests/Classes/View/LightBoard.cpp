//
//  LightBoard.cpp
//  cocos2d_tests
//
//  Created by maAya on 14-4-28.
//
//

#include "LightBoard.h"

USING_NS_CC;
USING_NS_CC_EXT;

LightBoard* LightBoard::create(int width, int height)
{
    LightBoard *pLightBoard = new LightBoard();
    if (pLightBoard && pLightBoard->initWithSize(width, height))
    {
        pLightBoard->autorelease();
        return pLightBoard;
    }
    CC_SAFE_DELETE(pLightBoard);
    return nullptr;
}

bool LightBoard::initWithSize(int width, int height)
{
    if(Node::init())
    {
        int w = (width >= 1) ? width : 1;
        int h = (height >= 1) ? height : 1;
        // TODO: 用一堆SingleLight对象很没有效率
        // 以后改成batch
        for(int i = 0; i < h; i++)
        {
            std::vector<SingleLight*> m_line;
            for(int j = 0; j < w; j++)
            {
                auto sprite = SingleLight::create();
                sprite->setPosition(Point(0 + j * 40,
                                          0 - i * 40));
                this->addChild(sprite);
                m_line.push_back(sprite);
            }
            m_lightBoard.push_back(m_line);
        }
        return true;
    }
    return false;
}

void LightBoard::turnOn(int x, int y, SingleLightColor color)
{
    if(y < 0 || y >= m_lightBoard.size())
        return;
    std::vector<SingleLight*> m_line = m_lightBoard[y];
    if(x < 0 || x >= m_line.size())
        return;
    
    SingleLight* light = m_line[x];
    light->turnOn(color);
}

void LightBoard::turnOff(int x, int y)
{
    if(y < 0 || y >= m_lightBoard.size())
        return;
    std::vector<SingleLight*> m_line = m_lightBoard[y];
    if(x < 0 || x >= m_line.size())
        return;
    
    SingleLight* light = m_line[x];
    light->turnOff();
}

void LightBoard::turnOffAll()
{
    for(std::vector<SingleLight*> m_line : m_lightBoard)
    {
        for(SingleLight* light : m_line)
        {
            light->turnOff();
        }
    }
}

