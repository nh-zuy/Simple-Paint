#include "bucket.h"

Bucket::Bucket():_path() {}

/**
 * @brief Brush::startDraw
 * @param point
 */
void Bucket::startDraw(const QPoint &point) {
    this->_path.push_back(point);
}

/**
 * @brief Brush::endDraw
 * @param point
 */
void Bucket::endDraw(const QPoint &point) {
    this->_path.push_back(point);
}

/**
 * @brief Brush::draw
 * @param painter
 */
void Bucket::draw(QPainter *painter) {
    QPen pen(this->color());
    pen.setWidth(1);
    painter->setPen(pen);

    for (QPoint& point: this->_path) {
        painter->drawPoint(point);
    };
}


