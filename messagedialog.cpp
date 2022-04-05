#include "appstylesheets.h"
#include "messagedialog.h"
#include "ui_messagedialog.h"
#include <utils/headers/stringutils.h>
#include "authorizewidget.h"

#include <utils/headers/uiutils.h>

MessageDialog::MessageDialog(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->close_button_container, &ClickableQWidget::clickedSignal, this, &MessageDialog::onCloseButtonClicked);
}

MessageDialog::~MessageDialog()
{
    delete ui;
}

void MessageDialog::onCloseButtonClicked()
{
    close();
}

QGridLayout * MessageDialog::getMessageDialogContainer(){
    return ui->messageDialogContainer;
}

void MessageDialog::resize(int width, int height)
{
    ui->messageDialogWidget->resize(width,height);
    ui->messageDialogWidget->setMinimumSize(QSize(width, height));

    ui->gridLayoutWidget->resize(width,height);
}

const QRect& MessageDialog::getSize() const
{
    return ui->messageDialogWidget->geometry();
}

void MessageDialog::move(int x, int y)
{
    ui->messageDialogWidget->move(x, y);
}

void MessageDialog::setDeleteOnClose(bool isActive)
{
    setAttribute(Qt::WA_DeleteOnClose, isActive);
}

void MessageDialog::hideCloseButton()
{
    ui->close_button_container->hide();
}

void MessageDialog::show()
{
    QFrame::show();
}
