#ifndef ITOOL_H
#define ITOOL_H

#include <QColor>
#include <QPainter>
#include <QPoint>

/**
 * @brief The ITool class
 *
 * Interface ITool
 * Contain functionals must be implemeting in child
 */
class ITool
{
protected:
    QColor _color;
    int _width;
public:
    ITool();
    virtual ~ITool() = default;

    /* Getter/Setter for _color */
    QColor color() const;
    void setColor(const QColor &color);

    /* Getter/Setter for _width */
    int width() const;
    void setWidth(int width);

    /* Pure abstract */
    virtual void startDraw(const QPoint& point) = 0;
    virtual void endDraw(const QPoint& point) = 0;
    virtual void draw(QPainter* painter) = 0;
};

#endif // ITOOL_H
