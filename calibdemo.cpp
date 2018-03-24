#include "calibdemo.h"


CalibDemo::CalibDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

CalibDemo::~CalibDemo()
{

}

void CalibDemo::on_action_triggered()
{

	QString filename = QFileDialog::getOpenFileName(this, tr("选择图片文件"), ".", tr("图片格式(*.bmp *.png *.jpeg )"));
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

	painter.drawImage(QPoint(20, 40), CalibImage);
	this->update();
}