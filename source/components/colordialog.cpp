#include "colordialog.h"

ColorDialog::ColorDialog(QWidget *parent):QColorDialog(parent) {}

QColor ColorDialog::selectedColor() const
{
    return _selectedColor;
}

void ColorDialog::setSelectedColor(const QColor &selectedColor)
{
    _selectedColor = selectedColor;
}

void ColorDialog::setColor(const QColor &color)
{
    this->setSelectedColor(color);
}

QColor ColorDialog::chooseColor() {
    QColor color = this->getColor(this->selectedColor(),
                                         this, tr("Color Panel"),
                                         QColorDialog::DontUseNativeDialog);

    return color;
}


