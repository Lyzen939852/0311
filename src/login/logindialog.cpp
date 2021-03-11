#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text().trimmed() == tr("admin")&&
            ui->pwdLineEdit->text()==tr("admin"))
    {
        accept();
    }else{
        QMessageBox::warning(this,tr("Waring"),
                             tr("用户名或者密码错误！"),
                             QMessageBox::Yes);
    }

    // 清空内容并定位光标
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->usrLineEdit->setFocus();
}
