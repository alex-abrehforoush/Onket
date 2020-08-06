#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_lineEdit_3_editingFinished();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_checkBox_stateChanged();

    void on_commandLinkButton_clicked();

private:
    Ui::signup *ui;
    QSize sizeHint() const;
};

#endif // SIGNUP_H
