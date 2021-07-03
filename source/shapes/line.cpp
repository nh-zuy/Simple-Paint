#include "line.h"

void Line::draw(QPainter *painter) {
    QPen pen(this->color(), this->width(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);
    painter->drawLine(this->start(), this->end());
}
