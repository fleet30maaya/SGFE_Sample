//
//  CommonTools.cpp
//  SGFG
//
//  Created by maAya on 14-5-26.
//
//

#include "CommonTools.h"

Color3B CommonTools::getRGBFromHSV(float h, float s, float v)
{
    float r = 0, g = 0, b = 0;
    int i = ((int)(h / 60) % 6);
    float f = (h / 60) - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);
    switch (i) {
        case 0:
            r = v;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = v;
            b = p;
            break;
        case 2:
            r = p;
            g = v;
            b = t;
            break;
        case 3:
            r = p;
            g = q;
            b = v;
            break;
        case 4:
            r = t;
            g = p;
            b = v;
            break;
        case 5:
            r = v;
            g = p;
            b = q;
            break;
        default:
            break;
    }
    return Color3B((GLubyte) (r * 255.0), (GLubyte) (g * 255.0), (GLubyte) (b * 255.0));
}
