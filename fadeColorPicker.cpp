#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    fadeFactor = fade;
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    HSLAPixel ret= p.c.color;
//    int px = (int) p.x;
//    int pcx = (int) p.c.x;
//    int py = (int)p.y;
//    int pcy = (int)p.c.y;
    distSq = sqrt(((p.x - p.c.x)* (p.x - p.c.x)) + ((p.y - p.c.y)* (p.y - p.c.y)));
    ret.l = p.c.color.l * pow(fadeFactor, distSq);
    return ret;
}
