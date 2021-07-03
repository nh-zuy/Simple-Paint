#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <abstracts/shape.h>

class Rectangle: public Shape
{
public:
    Rectangle() = default;
    ~Rectangle() = default;

    void draw(QPainter* painter) override;
};

#endif // RECTANGLE_H
