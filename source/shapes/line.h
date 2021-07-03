#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include "abstracts/shape.h"

class Line: public Shape
{
public:
    Line() = default;
    ~Line() = default;

    void draw(QPainter *painter) override;
};

#endif // LINE_H
