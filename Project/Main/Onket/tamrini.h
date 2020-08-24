#ifndef TAMRINI_H
#define TAMRINI_H

#include <QWidget>

namespace Ui {
class Tamrini;
}

class Tamrini : public QWidget
{
    Q_OBJECT

public:
    explicit Tamrini(QWidget *parent = nullptr);
    ~Tamrini();

private:
    Ui::Tamrini *ui;
};

#endif // TAMRINI_H
