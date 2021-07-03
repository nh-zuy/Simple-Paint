#include "itool.h"

ITool::ITool():_color(QColor())
{
    this->_width = 0;
}

QColor ITool::color() const
{
    return _color;
}

void ITool::setColor(const QColor &color)
{
    _color = color;
}

int ITool::width() const
{
    return _width;
}

void ITool::setWidth(int width)
{
    _width = width;
}


