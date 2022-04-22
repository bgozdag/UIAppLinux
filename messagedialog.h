#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QFrame>
#include <qgridlayout.h>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QFrame
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = nullptr);
    ~MessageDialog();
    QGridLayout * getMessageDialogContainer();
    void hideGridLayoutWidget();
    void setDeleteOnClose(bool isActive);
    void hideCloseButton();
    virtual void show();
    void resize(int, int);
    const QRect& getSize() const;
    void move(int, int);

private:
    Ui::MessageDialog *ui;

signals:
    void dialogClosedSignal();

public slots:
    virtual void onCloseButtonClicked();
};

#endif // MESSAGEDIALOG_H
