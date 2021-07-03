#include "widthdialog.h"
#include "ui_widthdialog.h"

WidthDialog::WidthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WidthDialog)
{
    ui->setupUi(this);
}

WidthDialog::~WidthDialog()
{
    delete ui;
}

int WidthDialog::getValue() const
{
    return ui->spinBox->value();
}

void WidthDialog::setValue(int val)
{
    ui->horizontalSlider->setValue(val);
}

void WidthDialog::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}

void WidthDialog::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}
