#ifndef __Exercise_3_1_H__
#define __Exercise_3_1_H__

#include "ExerciseScene_3.h"

class Exercise_3_1_Layer : public Exercise_3BaseLayer
{
public:
    virtual bool init();
    
protected:
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    
    float m_colorH;
    float m_colorS;
    float m_colorV;
};

#endif // __Exercise_3_1_H__
