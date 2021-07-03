#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include "itool.h"

class Shape: public ITool
{
private:
    QPoint _start;
    QPoint _end;
public:
    Shape();
    virtual ~Shape() = default;

    /* Getter/Setter start point */
    QPoint start() const;
    virtual void setStart(const QPoint &start);

    /* Getter/Setter end point */
    QPoint end() const;
    virtual void setEnd(const QPoint &end);

    /* @Override */
    virtual void startDraw(const QPoint& point) override;
    virtual void endDraw(const QPoint& point) override;
};

#endif // SHAPE_H
