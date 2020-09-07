#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    this->borderSize = borderSize;
    this->fillColor = fillColor;
    this->img = img;
    this->tolerance = tolerance;
}

HSLAPixel borderColorPicker::operator()(point p)
{

    unsigned int bsSqr = pow(borderSize, 2);

    unsigned int bsSqrm = pow(borderSize, 2);
    // int euDist = sqrt(((p.x - img.width())* (p.x - p.c.x)) + ((p.y - p.c.y)* (p.y - p.c.y)));
    if ( (pow(img.width() - 1- p.x,2) < bsSqr) || (pow(p.x,2) < bsSqr) || (pow(img.height() - 1 - p.y,2) < bsSqr) || (pow(p.y,2) <bsSqr)){
        return fillColor;
    }
    else{
        for (unsigned int i = -borderSize; i<=borderSize; i++ ){
            for (unsigned int j = -borderSize; j<=borderSize; j++){
                if (img.getPixel(p.x + i, p.y + j)->dist(p.c.color) >= tolerance){
                    return fillColor;
                }
            }
        }
        return *img.getPixel(p.x, p.y);

    }

}
