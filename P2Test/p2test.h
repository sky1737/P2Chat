#ifndef P2TEST_H
#define P2TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_p2test.h"

class P2Test : public QMainWindow
{
	Q_OBJECT

public:
	P2Test(QWidget *parent = 0);
	~P2Test();

private:
	Ui::P2TestClass ui;
};

#endif // P2TEST_H