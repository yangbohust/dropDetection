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
//打开文件保存记录



void video_test1::paintEvent(QPaintEvent *e)
{
	//显示方法一
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
		//imshow("第k帧", srcImage);
		ROI_show = srcImage(Range(250, 300), Range(260, 300));
		//imshow("ROI_show", ROI_show);

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
		//第四步    
		ui.ROI_show->setPixmap((QPixmap::fromImage(*this->qImage)).scaled(ui.ROI_show->size()));// 这句话就是你想要的 把opencv处理出来的图片放到 qt 指定的方框里了
		// 下面这两句是opencv独立窗口显示图片，用来对比


		if (srcImage.data)
		{
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR

			cvtColor(srcImage, grayImage, CV_BGR2GRAY);

			//imshow("grayImage:",grayImage);

			ROI = grayImage(Range(250, 300), Range(260, 300));
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

			this->update();	//发送刷新消息
		}
	}

	
}
void video_test1::on_startCount_clicked()
{

	//QString filename = QFileDialog::getOpenFileName(this, tr("选择视频文件"), ".", tr("视频格式(*.avi *.mp4 *.flv *.mkv *.wmv)"));
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
	//		cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
	//		cvtColor(srcImage, grayImage, CV_BGR2GRAY);
	//		imageTemp = grayImage(Range(250, 300), Range(260, 300));
	//		GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
	//		//imshow("第一帧", imageTemp);
	//		imageTemp.convertTo(imageTemp, CV_16SC1);
	//	}
	//}
	videoIsOpen = true;
	theTimer.start(33);
	videoCap >> srcImage;
	if (srcImage.data)
	{
		cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
		cvtColor(srcImage, grayImage, CV_BGR2GRAY);
		imageTemp = grayImage(Range(250, 300), Range(260, 300));
		GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
		//imshow("第一帧", imageTemp);
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

	QString filename = QFileDialog::getOpenFileName(this, tr("选择视频文件"), ".", tr("视频格式(*.avi *.mp4 *.flv *.mkv *.wmv)"));
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
			cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
			cvtColor(srcImage, grayImage, CV_BGR2GRAY);
			imageTemp = grayImage(Range(250, 300), Range(260, 300));
			GaussianBlur(imageTemp, imageTemp, Size(3, 3), 1, 1);
			//imshow("第一帧", imageTemp);
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