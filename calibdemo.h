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
#include<qtooltip.h>
#include<QMouseEvent>
#include<qstring.h>


class CalibDemo : public QMainWindow
{
	Q_OBJECT

public:
	CalibDemo(QWidget *parent = 0);
	~CalibDemo();
	double returnCalib();

private:
	Ui::CalibDemo ui;

	QImage CalibImage;
	//const QString filename_;


	QPainter painter;

	int mousepress_x;
	int mousepress_y;

	int mousemove_x;
	int mousemove_y;

	int mouserelease_x;
	int mouserelease_y;
	int Rectw;
	int Recth;
	double Length;
	QString lennum;
	double Calib;


private slots:
	void on_action_triggered();
	void on_pushButton_clicked();

signals:
	void sendCalib(double calib);

protected:
	void paintEvent(QPaintEvent *e);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};

#endif // CALIBDEMO_H
