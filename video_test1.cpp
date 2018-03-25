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
//���ļ������¼
video_test1::~video_test1()
{
	pMianWindow->close();
}


void video_test1::paintEvent(QPaintEvent *e)
{
	//��ʾ����һ
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
	
	//this->update();//��Ҫ��paintEvent()�����е���update()����repaint()
	//painter.end();

	//QPainter painter2(this);
	//QImage image2 = QImage((uchar*)(ROI_show.data), ROI_show.cols, ROI_show.rows, QImage::Format_RGB888);
	//painter2.drawImage(QPoint(680,40), image2);

	//��ʾ������
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
			//imshow("��k֡", srcImage);
			//ROI_show = srcImage(Range(250, 300), Range(260, 300));
			showImage = srcImage;
			this->qTempShowImage = new QImage(QSize(showImage.width, showImage.height), QImage::Format_RGB888);
			this->tempShowIamge = cvCreateImageHeader(cvSize(showImage.width, showImage.height), 8, 3);
			this->tempShowIamge->imageData = (char*)(this->qTempShowImage->bits());
			cvCopy(&showImage, this->tempShowIamge, 0);
			cvCvtColor(this->tempShowIamge, this->tempShowIamge, CV_BGR2RGB);
			//imageShowLabel->setPixmap((QPixmap::fromImage(*this->qTempShowImage)).scaled(imageShowLabel->size()));// ��仰��������Ҫ�� ��opencv���������ͼƬ�ŵ� qt ָ���ķ�������


			ROI_show = srcImage(Range(y1, y2), Range(x1, x2));
			//��һ���������Ǽ���һ��ͼƬ���ǽ���opencv���������ص�ͼƬ
			image = ROI_show;// ��opencv��������һ��ͼƬ
			// �ڶ�����ʵ����һ���յ�QImage ��һ��  IplImage
			this->qImage = new QImage(QSize(image.width, image.height), QImage::Format_RGB888);
			// ����������ص���ͼƬ������һ����ͬ��ʽ(ָ���ǳ��͸�)��opencv���ͼƬ����
			this->tempImage = cvCreateImageHeader(cvSize(image.width, image.height), 8, 3);

			// ������
			this->tempImage->imageData = (char*)(this->qImage->bits());// tempImage->imageDataָ��Ĵ��ͼ��ʵ�������ָ��, qlmage->bits() ��QT�� ͼ��ʵ������ָ�룬������tempImage->imageData Ҳָ�� qlmage->bits() ָ�������
			cvCopy(&image, this->tempImage, 0);// ��ͼ�����ݴ�this->image ������ this->tempImageָ������򣬶�this->tempImage��ʱָ��������this->qImage->bits()��ָ����ͬһ������
			cvCvtColor(this->tempImage, this->tempImage, CV_BGR2RGB); //�������ɫ�ռ�ת��
			//���Ĳ�  ��ROI_show������ʾROI����  
			ui.ROI_show->setPixmap((QPixmap::fromImage(*this->qImage)).scaled(ui.ROI_show->size()));// ��仰��������Ҫ�� ��opencv���������ͼƬ�ŵ� qt ָ���ķ�������
			


			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);

			//ROI = grayImage(Range(250, 300), Range(260, 300));
			ROI = grayImage(Range(y1, y2), Range(x1, x2));

			GaussianBlur(ROI, ROI, Size(3, 3), 1, 1, BORDER_DEFAULT);
			//imshow("ROI",ROI);//ROI��ȷ
			ROI.convertTo(ROI, CV_16SC1);

			subtract(ROI, imageTemp, subROI, Mat(), CV_16SC1);//ͬ�����������������ֵ�����144-240Ҳ������ - 96������uchar�ܱ�ʾ����Сֵ0��

			subROI = abs(subROI);//ȡ����ֵ

			//Mat constMat = Mat::ones(int(subROI.rows), int(subROI.cols),CV_16SC1) * 10;
			//subtract(subROI, constMat, subROI, Mat(), CV_16SC1);
			subROI.convertTo(subROI, CV_8UC1);
			//imshow("SubROI", subROI);//subROI��������꣬subROIΪȫ��:ucharʱ�������

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

			this->update();	//����ˢ����Ϣ
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
		theTimer.start(33);//33�������һ��ͼ��/֡Ƶ��ԼΪ33Hz  1000/33��
		
		videoCap >> srcImage;
	
		if (srcImage.data)
		{
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);
			//imageTemp = grayImage(Range(250, 300), Range(260, 300));
			imageTemp = grayImage(Range(y1, y2), Range(x1, x2));


			GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
			//imshow("��һ֡", imageTemp);
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
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);
			//imageTemp = grayImage(Range(250, 300), Range(260, 300));
			imageTemp = grayImage(Range(y1,y2), Range(x1,x2));
			GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
			//imshow("��һ֡", imageTemp);
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