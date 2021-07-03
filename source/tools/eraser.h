#ifndef ERASER_H
#define ERASER_H

#include <QPoint>
#include <QPainter>
#include <QVector>
#include "abstracts/itool.h"

class Eraser : public ITool
{
private:
    QVector<QPoint> _path;

public:
    Eraser();
    ~Eraser() = default;

    void startDraw(const QPoint& point) override;
    void endDraw(const QPoint& point) override;
    void draw(QPainter *painter) override;
};


#endif // ERASER_H
