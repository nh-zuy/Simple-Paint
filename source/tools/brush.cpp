#include "brush.h"

Brush::Brush():_path() {}

/**
 * @brief Brush::startDraw
 * @param point
 */
void Brush::startDraw(const QPoint &point) {
    this->_path.push_back(point);
}

/**
 * @brief Brush::endDraw
 * @param point
 */
void Brush::endDraw(const QPoint &point) {
    this->_path.push_back(point);
}

/**
 * @brief Brush::draw
 * @param painter
 */
void Brush::draw(QPainter *painter) {
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
