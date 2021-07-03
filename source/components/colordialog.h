#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QWidget>
#include <QColorDialog>
#include <QColor>

/**
 * A dialog to select and manipulate color
 *
 * @brief The ColorDialog class
 */
class ColorDialog : public QColorDialog
{
    Q_OBJECT
private:
    QColor _selectedColor;
public:
    explicit ColorDialog(QWidget *parent = 0);
    ~ColorDialog() = default;

    QColor chooseColor();
    void setColor(const QColor& color);

    QColor selectedColor() const;
    void setSelectedColor(const QColor &selectedColor);
};

#endif // COLORDIALOG_H
