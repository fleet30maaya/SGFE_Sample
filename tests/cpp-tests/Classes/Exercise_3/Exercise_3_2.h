#ifndef __Exercise_3_2_H__
#define __Exercise_3_2_H__

#include "ExerciseScene_3.h"

class Exercise_3_2_Layer : public Exercise_3BaseLayer
{
public:
    virtual bool init();
    virtual void update(float delta);
    
protected:
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    void onTouchCancelled(Touch* touch, Event* event);
    
    float m_colorH;
    float m_colorS;
    float m_colorV;
    bool  m_touching;
    Point m_touchingPos;
};

#endif // __Exercise_3_2_H__
