#include <QPen>
#include "pen.h"

Pen::Pen():_path() {}

/**
 * @brief Pen::startDraw
 * @param point
 */
void Pen::startDraw(const QPoint &point) {
    this->_path.push_back(point);
}

/**
 * @brief Pen::endDraw
 * @param point
 */
void Pen::endDraw(const QPoint &point) {
    this->_path.push_back(point);
}

/**
 * @brief Pen::draw
 * @param painter
 */
void Pen::draw(QPainter *painter) {
    QPen pen(this->color(), this->width(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter->setPen(pen);

    if (this->_path.size() > 1) {
        for (register int i = 0; i < this->_path.size() - 1; ++i) {
            painter->drawLine(this->_path[i], this->_path[i + 1]);
        };
    } else {
        painter->drawPoint(this->_path[0]);
    }
}
