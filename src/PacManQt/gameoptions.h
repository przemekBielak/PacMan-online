#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include <QWidget>

namespace Ui {
class gameOptions;
}

class gameOptions : public QWidget
{
    Q_OBJECT

public:
    explicit gameOptions(QWidget *parent = 0);
    ~gameOptions();

private:
    Ui::gameOptions *ui;
};

#endif // GAMEOPTIONS_H
