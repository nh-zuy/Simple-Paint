#include "shape.h"

/**
 * @brief Shape::Shape
 */
Shape::Shape(): ITool(), _start(QPoint()), _end(QPoint()) {}

/**
 * @brief Shape::start
 * @return
 * Getter/Setter
 */
QPoint Shape::start() const
{
    return _start;
}
void Shape::setStart(const QPoint &start)
{
    this->_start = start;
}

/**
 * @brief Shape::end
 * @return
 * Getter/Setter
 */
QPoint Shape::end() const
{
    return _end;
}
void Shape::setEnd(const QPoint &end)
{
    this->_end = end;
}

/**
 * @brief Shape::startDraw
 * @param point
 * @Override
 */
void Shape::startDraw(const QPoint &point)
{
    this->setStart(point);
    this->setEnd(point);
}
/**
 * @brief Shape::endDraw
 * @param point
 * @Override
 */
void Shape::endDraw(const QPoint &point)
{
    this->setEnd(point);
}
