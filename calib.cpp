#include "calib.h"



Calib::Calib(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Calib::~Calib()
{

}

void Calib::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QImage image;
	image.load("Calib.bmp");
	painter.drawImage(QPoint(20, 40),image);
}