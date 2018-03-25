#include "calibdemo.h"


CalibDemo::CalibDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	 mousepress_x=0;
	 mousepress_y=0;

	 mousemove_x=0;
	 mousemove_y=0;

	 mouserelease_x=0;
	 mouserelease_y=0;
	 Rectw=0;
	 Recth=0;
	 setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
	 setFixedSize(this->width(), this->height());
	 
}

CalibDemo::~CalibDemo()
{

}

void CalibDemo::on_action_triggered()
{

	QString filename = QFileDialog::getOpenFileName(this, tr("Chioce a picture!"), ".", tr("format(*.bmp *.png *.jpeg *.jpg *.tif *.tiff )"));
	//QFile file(filename);
	//if (!file.open(QIODevice::ReadOnly))
	//{
	//	qDebug() << "Could not open file";
	//	exit(0);
	//}
	//QUrl::fromLocalFile(filename);
	//filename_ = filename.toStdString();

	CalibImage.load(filename);
}


void CalibDemo::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawImage(QPoint(10,60), CalibImage);

	QPoint x1(mousepress_x, mousepress_y);
	QPoint x2(mousemove_x, mousemove_y);
	QPoint x3(mouserelease_x, mouserelease_y);

	painter.drawLine(x1, x2);
	//painter.drawLine(x1, x3);

	//this->update();//不要在paintEvent()函数中调用update()或者repaint()
}


void CalibDemo::mouseMoveEvent(QMouseEvent *event)
{
	Rectw = (mousepress_x - mousemove_x)*(mousepress_x - mousemove_x);
	Recth = (mousepress_y - mousemove_y)*(mousepress_y - mousemove_y);
	Length = sqrt(Rectw + Recth);
	mousemove_x = event->pos().x() ;
	mousemove_y = event->pos().y() ;
	
	QString pos = QString("Length=%1pixels").arg(Length);
	//QString pos = QString("%1,%2").arg(event->pos().x() - 20).arg(event->pos().y() - 40);
	QToolTip::showText(event->globalPos(), pos, this);
	this->update();
}

void CalibDemo::mousePressEvent(QMouseEvent *event)
{
	mousepress_x = event->pos().x() ;
	mousepress_y = event->pos().y() ;
	//QString pos = QString("%1,%2").arg(event->pos().x() - 20).arg(event->pos().y() - 40);
	//QToolTip::showText(event->globalPos(), pos, this);
}
void CalibDemo::mouseReleaseEvent(QMouseEvent *event)
{
	//Rectw = abs(mousepress_x - mousemove_x);
	//Recth = abs(mousepress_y - mousemove_y);
	//mouserelease_x = event->pos().x() ;
	//mouserelease_y = event->pos().y() ;
	Calib =10/Length;//1cm=10mm,每个像素宽度为Length/10;
	lennum = QString::number(Calib, 10,2);
	ui.lineEdit->setText(lennum);
}

double CalibDemo::returnCalib()
{
	return Calib;
}

void CalibDemo::on_pushButton_clicked()
{
	emit sendCalib(returnCalib());

}