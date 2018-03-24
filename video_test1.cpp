#include "video_test1.h"
#include<qdebug.h>
#include<QToolTip>
#include<QMouseEvent>
#include"Calib.h"

video_test1::video_test1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(&theTimer, &QTimer::timeout, this, &video_test1::updateImage);
	setMouseTracking(true);
	mousepress_x = 0;
	mousepress_y = 0;

	mousemove_x = 0;
	mousemove_y = 0;

	mouserelease_x = 0;
	mouserelease_y = 0;
	Rectw = 0;
	Recth = 0;
}
//���ļ������¼



void video_test1::paintEvent(QPaintEvent *e)
{
	//��ʾ����һ
	//QPainter painter(this);
	painter.begin(this);
	painter.translate(20,40);
	QImage image1 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
	painter.drawImage(QPoint(0,0), image1);
	//QPainter painter2(this);
	//painter2.drawRect(mousepress_x, mousepress_y, mousemove_x, mousemove_y);
	//

	painter.drawRect(mousepress_x, mousepress_y, Rectw, Recth);
	painter.drawRect(mousepress_x, mousepress_y, Rectw, Recth);
	
	this->update();
	painter.end();

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
		//imshow("��k֡", srcImage);
		ROI_show = srcImage(Range(250, 300), Range(260, 300));
		//imshow("ROI_show", ROI_show);

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
		//���Ĳ�    
		ui.ROI_show->setPixmap((QPixmap::fromImage(*this->qImage)).scaled(ui.ROI_show->size()));// ��仰��������Ҫ�� ��opencv���������ͼƬ�ŵ� qt ָ���ķ�������
		// ������������opencv����������ʾͼƬ�������Ա�


		if (srcImage.data)
		{
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR

			cvtColor(srcImage, grayImage, CV_BGR2GRAY);

			//imshow("grayImage:",grayImage);

			ROI = grayImage(Range(250, 300), Range(260, 300));
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
			//qDebug() << "countSeq=" << countSeq << endl;
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
	}

	
}
void video_test1::on_startCount_clicked()
{

	//QString filename = QFileDialog::getOpenFileName(this, tr("ѡ����Ƶ�ļ�"), ".", tr("��Ƶ��ʽ(*.avi *.mp4 *.flv *.mkv *.wmv)"));
	//QFile file(filename);
	//if (!file.open(QIODevice::ReadOnly))
	//{
	//	qDebug() << "Could not open file";
	//	exit(0);
	//}

	//QUrl::fromLocalFile(filename);
	//const string filename_ = filename.toLocal8Bit();
	//const string filename_ = "20180205-110629-683.mp4";

	//if (videoCap.open(filename_))
	//{
	//	srcImage = Mat::zeros(videoCap.get(CV_CAP_PROP_FRAME_HEIGHT), videoCap.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3);
	//	theTimer.start(33);
	//	videoCap >> srcImage;
	//	if (srcImage.data)
	//	{
	//		cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
	//		cvtColor(srcImage, grayImage, CV_BGR2GRAY);
	//		imageTemp = grayImage(Range(250, 300), Range(260, 300));
	//		GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
	//		//imshow("��һ֡", imageTemp);
	//		imageTemp.convertTo(imageTemp, CV_16SC1);
	//	}
	//}
	videoIsOpen = true;
	theTimer.start(33);
	videoCap >> srcImage;
	if (srcImage.data)
	{
		cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
		cvtColor(srcImage, grayImage, CV_BGR2GRAY);
		imageTemp = grayImage(Range(250, 300), Range(260, 300));
		GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
		//imshow("��һ֡", imageTemp);
		imageTemp.convertTo(imageTemp, CV_16SC1);
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

	QString filename = QFileDialog::getOpenFileName(this, tr("ѡ����Ƶ�ļ�"), ".", tr("��Ƶ��ʽ(*.avi *.mp4 *.flv *.mkv *.wmv)"));
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
		srcImage = Mat::zeros(videoCap.get(CV_CAP_PROP_FRAME_HEIGHT), videoCap.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3);
		//theTimer.start(33);
		//videoCap >> srcImage;
		videoCap.read(srcImage);
		if (srcImage.data)
		{
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);
			imageTemp = grayImage(Range(250, 300), Range(260, 300));
			GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
			//imshow("��һ֡", imageTemp);
			imageTemp.convertTo(imageTemp, CV_16SC1);
		}

	}

}


void video_test1:: mouseMoveEvent(QMouseEvent *event)
{
	 Rectw = abs(mousepress_x - mousemove_x);
	 Recth = abs(mousepress_y - mousemove_y);
	mousemove_x = event->pos().x() - 20;
	mousemove_y = event->pos().y() - 40;
	
	QString pos = QString("%1,%2").arg(event->pos().x()-20).arg(event->pos().y()-40);
	QToolTip::showText(event->globalPos(), pos, this);
}

void video_test1::mousePressEvent(QMouseEvent *event)
{
	mousepress_x = event->pos().x() - 20;
	mousepress_y = event->pos().y() - 40;
	QString pos = QString("%1,%2").arg(event->pos().x()-20).arg(event->pos().y()-40);
	QToolTip::showText(event->globalPos(), pos, this);
}
void video_test1::mouseReleaseEvent(QMouseEvent *event)
{
	Rectw = abs(mousepress_x - mousemove_x);
	Recth = abs(mousepress_y - mousemove_y);
	mouserelease_x = event->pos().x() - 20;
	mouserelease_y = event->pos().y() - 40;
}
void video_test1::on_openCalib_triggered()
{
	pMianWindow = new CalibDemo();

	pMianWindow->show();
}