#ifndef CALIBDEMO_H
#define CALIBDEMO_H

#include <QMainWindow>
#include "ui_calibdemo.h"
#include <QPainter>  
#include <QPixmap>  
#include <QLabel>  
#include <QImage>  
#include<QFileDialog>
#include<qdebug.h>
#include<string>


class CalibDemo : public QMainWindow
{
	Q_OBJECT

public:
	CalibDemo(QWidget *parent = 0);
	~CalibDemo();

private:
	Ui::CalibDemo ui;

	QImage CalibImage;
	//const QString filename_;
private slots:
	void on_action_triggered();

protected:
	void paintEvent(QPaintEvent *e);

};

#endif // CALIBDEMO_H
