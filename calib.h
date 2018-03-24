#ifndef CALIB_H
#define CALIB_H

#include <QWidget>
#include "ui_calib.h"
#include <QPainter>  
#include <QPixmap>  
#include <QLabel>  
#include <QImage>  

class Calib : public QWidget
{
	Q_OBJECT

public:
	Calib(QWidget *parent = 0);
	~Calib();

private:
	Ui::Calib ui;

protected:
	void paintEvent(QPaintEvent *e);
};

#endif // CALIB_H
