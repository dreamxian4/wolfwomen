#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QWidget>
#include <QMenu>
#include <QPoint>
#include"uiapi/customwidget.h"

namespace Ui {
class ChatDialog;
}

class ChatDialog : public CustomMoveDialog
{
    Q_OBJECT

signals:

    void SIG_SendChatMsg(int id,QString content);
    void SIG_quitChat(int);

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();
    //设置窗口信息
    void setInfo(QString name,int id);
    //在控件上显示收到的消息内容
    void slot_setChatMsg(QString content);
    //处理聊天对象不在线
    void slot_UserOffline();
    //处理详细信息菜单
    void slot_dealMenu(QAction *action);
    //获取聊天内容
    void slot_getMsg(int id/*我的id*/);

private slots:
    void on_pb_send_clicked();
    void on_pb_show_clicked();


    void on_pb_min_2_clicked();

    void on_pb_close_2_clicked();

private:
    Ui::ChatDialog *ui;
    QString m_name;
    int m_id;//好友id
    QMenu* m_menu;
};

#endif // CHATDIALOG_H
