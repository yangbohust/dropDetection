#include "video_test1.h"
#include<qdebug.h>
#include<QToolTip>
#include<QMouseEvent>
#include"Calib.h"

video_test1::video_test1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//connect(&theTimer, &QTimer::timeout, this, &video_test1::updateImage);
	imageShowLabel = new QLabel(this);
	imageShowLabel->setGeometry(20, 40, 640, 480);
	imageShowWidget = new QWidget(this);
	imageShowWidget->setGeometry(20, 40, 640, 480);



	connect(&theTimer, SIGNAL(timeout()), this, SLOT(updateImage()));
	setMouseTracking(true);
	mousepress_x = 0;
	mousepress_y = 0;

	mousemove_x = 0;
	mousemove_y = 0;

	mouserelease_x = 0;
	mouserelease_y = 0;
	Rectw = 0;
	Recth = 0;

	 x1=260;
	 y1=250;
	 x2=300;
	 y2=300;
	pMianWindow = new CalibDemo();
	connect(pMianWindow, SIGNAL(sendCalib(double)), this, SLOT(receiveCalib(double)));
	isFileOpen = false;

	setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
	setFixedSize(this->width(), this->height());


	
	//srcImage = Mat::zeros(640, 480, CV_8UC3);

}
//打开文件保存记录
video_test1::~video_test1()
{
	pMianWindow->close();
}


void video_test1::paintEvent(QPaintEvent *e)
{
	//显示方法一
	QPainter painter(this);
	//painter.begin(this);
	//QPainter painter(this->imageShowLabel);

	
	//QPainter painter(imageShowLabel);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.translate(20,40);

	QImage image1 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
	painter.drawImage(QPoint(0,0), image1);
	//QPainter painter2(this);
	//painter2.drawRect(mousepress_x, mousepress_y, mousemove_x, mousemove_y);
	//

	painter.drawRect(mousepress_x, mousepress_y, Rectw, Recth);
	//painter.drawRect(mousepress_x, mousepress_y, Rectw, Recth);
	
	//this->update();//不要在paintEvent()函数中调用update()或者repaint()
	//painter.end();

	//QPainter painter2(this);
	//QImage image2 = QImage((uchar*)(ROI_show.data), ROI_show.cols, ROI_show.rows, QImage::Format_RGB888);
	//painter2.drawImage(QPoint(680,40), image2);

	//显示方法二
//	QImage image2 = QImage((uchar*)(ROI.data), ROI.cols, ROI.rows, QImage::Format_RGB888);
	//QImage image2 = QImage((uchar*)(ROI_show.data), ROI_show.cols, ROI_show.rows, QImage::Format_RGB888);
	//ROILabel->setPixmap(QPixmap::fromImage(image2));
	//ROILabel->resize(image2.size());
	//ROILabel->show();
}


void video_test1::on_clearPainter_clicked()
{
	//painter.drawRect(mousepress_x, mousepress_y, Rectw, Recth);
	painter.drawRect(mousepress_x, mousepress_y, Rectw, Recth);

}

void video_test1::updateImage()
{
	if (videoIsOpen == true)
	{
		//qDebug() << "updataImage" << endl;
		videoCap >> srcImage;
		
		if (srcImage.data)
		{
			//imshow("第k帧", srcImage);
			//ROI_show = srcImage(Range(250, 300), Range(260, 300));
			showImage = srcImage;
			this->qTempShowImage = new QImage(QSize(showImage.width, showImage.height), QImage::Format_RGB888);
			this->tempShowIamge = cvCreateImageHeader(cvSize(showImage.width, showImage.height), 8, 3);
			this->tempShowIamge->imageData = (char*)(this->qTempShowImage->bits());
			cvCopy(&showImage, this->tempShowIamge, 0);
			cvCvtColor(this->tempShowIamge, this->tempShowIamge, CV_BGR2RGB);
			//imageShowLabel->setPixmap((QPixmap::fromImage(*this->qTempShowImage)).scaled(imageShowLabel->size()));// 这句话就是你想要的 把opencv处理出来的图片放到 qt 指定的方框里了


			ROI_show = srcImage(Range(y1, y2), Range(x1, x2));
			//第一步：下面是加载一张图片，是借助opencv函数来加载的图片
			image = ROI_show;// 用opencv函数加载一张图片
			// 第二步：实例化一个空的QImage 和一个  IplImage
			this->qImage = new QImage(QSize(image.width, image.height), QImage::Format_RGB888);
			// 根据上面加载到的图片，建立一个相同格式(指的是长和高)的opencv里的图片对象
			this->tempImage = cvCreateImageHeader(cvSize(image.width, image.height), 8, 3);

			// 第三步
			this->tempImage->imageData = (char*)(this->qImage->bits());// tempImage->imageData指向的存放图像实体区域的指针, qlmage->bits() 是QT中 图像实体区域指针，现在让tempImage->imageData 也指向 qlmage->bits() 指向的区域
			cvCopy(&image, this->tempImage, 0);// 把图像数据从this->image 拷贝到 this->tempImage指向的区域，而this->tempImage此时指向的区域和this->qImage->bits()所指的是同一个区域
			cvCvtColor(this->tempImage, this->tempImage, CV_BGR2RGB); //这个是颜色空间转换
			//第四步  在ROI_show部件显示ROI区域  
			ui.ROI_show->setPixmap((QPixmap::fromImage(*this->qImage)).scaled(ui.ROI_show->size()));// 这句话就是你想要的 把opencv处理出来的图片放到 qt 指定的方框里了
			


			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);

			//ROI = grayImage(Range(250, 300), Range(260, 300));
			ROI = grayImage(Range(y1, y2), Range(x1, x2));

			GaussianBlur(ROI, ROI, Size(3, 3), 1, 1, BORDER_DEFAULT);
			//imshow("ROI",ROI);//ROI正确
			ROI.convertTo(ROI, CV_16SC1);

			subtract(ROI, imageTemp, subROI, Mat(), CV_16SC1);//同理如果用这两个像素值相减，144-240也不会是 - 96，而是uchar能表示的最小值0。

			subROI = abs(subROI);//取绝对值

			//Mat constMat = Mat::ones(int(subROI.rows), int(subROI.cols),CV_16SC1) * 10;
			//subtract(subROI, constMat, subROI, Mat(), CV_16SC1);
			subROI.convertTo(subROI, CV_8UC1);
			//imshow("SubROI", subROI);//subROI出错，相减完，subROI为全零:uchar时的情况；

			//countSeq = countNonZero(subROI);
			countSeq = 0;
			MatIterator_<uchar> it, end;
			for (it = subROI.begin<uchar>(), end = subROI.end<uchar>(); it != end; it++)
			{
				if (*it > 10)
					countSeq++;
			}
			deltaCount = abs(countSeq - countTemp);
			qDebug() << "deltaCount=" << deltaCount << endl;
			if (deltaCount > 100 && countSeq<100)
			{
				totalCount++;
				qDebug() << "totalCount=" << totalCount << endl;
				QString num = QString::number(totalCount, 10);
				ui.count->setText(num);
				srand((unsigned)time(NULL));
				cur_volume = 0.05 + rand() % 10 * 0.0001;
				QString cur_vol = QString::number(cur_volume, 10, 4);
				ui.cur_volume->setText(cur_vol);

				sum_volume += cur_volume;
				QString sum_vol = QString::number(sum_volume, 10, 4);
				ui.sum_volume->setText(sum_vol);
			}
			//QString num = QString::number(deltaCount, 10);
			//ui.count->setText(num);
			imageTemp = ROI;
			countTemp = countSeq;

			this->update();	//发送刷新消息
		}
		else
		{
			videoCap.release();
			videoIsOpen = false;
		}
	}
	else
	{
		videoIsOpen =false;
	}

	
}
void video_test1::on_startCount_clicked()
{
	if (isFileOpen == true)
	{
		videoIsOpen = true;
		theTimer.start(33);//33毫秒更新一次图像/帧频率约为33Hz  1000/33；
		
		videoCap >> srcImage;
	
		if (srcImage.data)
		{
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);
			//imageTemp = grayImage(Range(250, 300), Range(260, 300));
			imageTemp = grayImage(Range(y1, y2), Range(x1, x2));


			GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
			//imshow("第一帧", imageTemp);
			imageTemp.convertTo(imageTemp, CV_16SC1);
		}
	}
	

}
void video_test1::on_stopCount_clicked()
{
	if (videoCap.isOpened() == 1)
	{
		videoIsOpen = false;
	}
}


void video_test1::on_action_triggered()
{
	totalCount = 0;
	cur_volume = 0;
	sum_volume = 0;
	QString filename = QFileDialog::getOpenFileName(this, tr("chioce an video"), ".", tr("format(*.avi *.mp4 *.flv *.mkv *.wmv)"));
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "Could not open file";
		exit(0);
	}

	QUrl::fromLocalFile(filename);
	filename_ = filename.toStdString();

	if (videoCap.open(filename_))
	{
		isFileOpen = true;
		srcImage = Mat::zeros(videoCap.get(CV_CAP_PROP_FRAME_HEIGHT), videoCap.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3);
		//theTimer.start(33);
		//videoCap >> srcImage;
		videoCap.read(srcImage);
		if (srcImage.data)
		{
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);
			//imageTemp = grayImage(Range(250, 300), Range(260, 300));
			imageTemp = grayImage(Range(y1,y2), Range(x1,x2));
			GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
			//imshow("第一帧", imageTemp);
			imageTemp.convertTo(imageTemp, CV_16SC1);
		}

	}

}


void video_test1:: mouseMoveEvent(QMouseEvent *event)
{
	if (event->pos().x() >= 0 && event->pos().x() <= 640 && pos().y() >= 0 && pos().y() <= 480)
	{
		Rectw = abs(mousepress_x - mousemove_x);
		Recth = abs(mousepress_y - mousemove_y);
		mousemove_x = event->pos().x() - 20;
		mousemove_y = event->pos().y() - 40;

		QString pos = QString("%1,%2").arg(event->pos().x() - 20).arg(event->pos().y() - 40);
		QToolTip::showText(event->globalPos(), pos, this);
		this->update();
	}
	
}

void video_test1::mousePressEvent(QMouseEvent *event)
{
	if (event->pos().x() >= 0 && event->pos().x() <= 640 && pos().y() >= 0 && pos().y() <= 480)
	{
		if (event->button() == Qt::LeftButton)
		{
			mousepress_x = event->pos().x() - 20;
			mousepress_y = event->pos().y() - 40;
			QString pos = QString("%1,%2").arg(event->pos().x() - 20).arg(event->pos().y() - 40);
			QToolTip::showText(event->globalPos(), pos, this);
		}
	}

	
	
}
void video_test1::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->pos().x() >= 0 && event->pos().x() <= 640 && pos().y() >= 0 && pos().y() <= 480)
	{
		if (event->button() == Qt::LeftButton)
		{
			Rectw = abs(mousepress_x - mousemove_x);
			Recth = abs(mousepress_y - mousemove_y);
			mouserelease_x = event->pos().x() - 20;
			mouserelease_y = event->pos().y() - 40;
			QString pos = QString("%1,%2").arg(event->pos().x() - 20).arg(event->pos().y() - 40);
			QToolTip::showText(event->globalPos(), pos, this);

		//	QString ROI_info = QString("x2=%1,y2=%2").arg(mouserelease_x).arg(mouserelease_y);
			//ui.label_ROI->setText(ROI_info);
		}
	}
	

}
void video_test1::on_openCalib_triggered()
{
	

	pMianWindow->show();
}

void video_test1::getCalib(double &calib)
{
	this->Calib = calib;
}


void video_test1::receiveCalib(double data)
{
	Calib = data;
	QString calib = QString::number(data, 10, 2);
	ui.lineEdit->setText(calib);
}



void video_test1::on_cleanPainter_clicked()
{
	mousepress_x = 0;
	mousepress_y = 0;
	Rectw = 0;
	Recth = 0;
	
	this->update();

}
void video_test1::on_chooseROI_clicked()
{
	x1 = mousepress_x;
	y1 = mousepress_y;
	x2 = mouserelease_x;
	y2 = mouserelease_y;

	QString ROI_infox1 = QString::number(x1, 10);
	QString ROI_infoy1 = QString::number(y1, 10);
	QString ROI_infox2 = QString::number(x2, 10);
	QString ROI_infoy2 = QString::number(y2, 10);

	QString ROI_info = QString("ROI:upLeft(%1,%2),lowRigth(%3,%4)").arg(ROI_infox1).arg(ROI_infoy1).arg(ROI_infox2).arg(ROI_infoy2);
	ui.label_ROI->setText(ROI_info);

}