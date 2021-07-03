#ifndef BRUSH_H
#define BRUSH_H

#include <QPoint>
#include <QPainter>
#include "abstracts/itool.h"

class Brush : public ITool
{
private:
    QVector<QPoint> _path;

public:
    Brush();
    ~Brush() = default;

    void startDraw(const QPoint& point) override;
    void endDraw(const QPoint& point) override;
    void draw(QPainter *painter) override;
};

#endif // BRUSH_H
