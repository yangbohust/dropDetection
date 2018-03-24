#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_video_test1.h"
#include<qtimer.h>
#include <QPainter>  
#include <QPixmap>  
#include <QLabel>  
#include <QImage>  
#include<QFileDialog>
#include <cv.h>
#include <highgui.h>
#include <opencv.hpp>  
#include<opencv2\opencv.hpp>
#include<cmath>
#include"calib.h"
#include"calibdemo.h"
using namespace cv;

class video_test1 : public QMainWindow
{
	Q_OBJECT

public:
	video_test1(QWidget *parent = Q_NULLPTR);
public slots:
	void updateImage();
	void on_startCount_clicked();
	void on_stopCount_clicked();
	void on_action_triggered();
	void on_clearPainter_clicked();
	void on_openCalib_triggered();

private:
	Ui::video_test1Class ui;

	QTimer theTimer;
	Mat srcImage;
	
	Mat ROI;
	Mat subROI;

	Mat imageTemp;
	Mat ROI_show;
	Mat grayImage;
	
	VideoCapture videoCap;
	bool videoIsOpen;
	QLabel *imageLabel;
	long countTemp = 0;
	long countSeq=0;
	long deltaCount=0;
	long totalCount=0;
	QLabel *ROILabel;
	double cur_volume;
	double sum_volume=0;
	QImage ROI_show_;

	QImage * qImage; // qt 中的图片类型指针
	IplImage image;  // opencv里的图片类型指针
	IplImage * tempImage;

	string filename_;

	QPainter painter;
	int mousepress_x;
	int mousepress_y;

	int mousemove_x;
	int mousemove_y;

	int mouserelease_x;
	int mouserelease_y;
	int Rectw;
	int Recth;

	Calib* pWidget;
	CalibDemo *pMianWindow;

protected:
	void paintEvent(QPaintEvent *e);
	
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};
