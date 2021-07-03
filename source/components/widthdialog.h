#ifndef WIDTHDIALOG_H
#define WIDTHDIALOG_H

#include <QDialog>

namespace Ui {
class WidthDialog;
}

/**
 * Dialog to handle size of tool
 *
 * @brief The WidthDialog class
 */
class WidthDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::WidthDialog *ui;

public:
    explicit WidthDialog(QWidget *parent = nullptr);
    ~WidthDialog();

    int getValue() const;
    void setValue(int val);

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);
};

#endif // WIDTHDIALOG_H
