#include <QPen>
#include <QRect>
#include "rectangle.h"

void Rectangle::draw(QPainter *painter) {
    QPen pen(this->color(), this->width(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);

    QRect shape(this->start(), this->end());
    painter->drawRect(shape);
}
