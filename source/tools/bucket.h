#ifndef BUCKET_H
#define BUCKET_H


#include <QPoint>
#include <QPainter>
#include <QVector>
#include "abstracts/itool.h"

class Bucket : public ITool
{
private:
    QVector<QPoint> _path;

public:
    Bucket();
    ~Bucket() = default;

    void startDraw(const QPoint& point) override;
    void endDraw(const QPoint& point) override;
    void draw(QPainter *painter) override;
};

#endif // BUCKET_H
