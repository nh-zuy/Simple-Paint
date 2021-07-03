#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPainter>
#include "abstracts/shape.h"

class Circle : public Shape
{
public:
    Circle() = default;
    ~Circle() = default;

    void draw(QPainter *painter) override;
};

#endif // CIRCLE_H
