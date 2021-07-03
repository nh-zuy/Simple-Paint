#ifndef PEN_H
#define PEN_H

#include <QPoint>
#include <QPainter>
#include <QVector>
#include "abstracts/itool.h"

class Pen : public ITool
{
private:
    QVector<QPoint> _path;

public:
    Pen();
    ~Pen() = default;

    void startDraw(const QPoint& point) override;
    void endDraw(const QPoint& point) override;
    void draw(QPainter *painter) override;
};

#endif // PEN_H
