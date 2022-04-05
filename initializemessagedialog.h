#ifndef INITIALIZEMESSAGEDIALOG_H
#define INITIALIZEMESSAGEDIALOG_H

#include "spinnermessagewidget.h"
#include "messagedialog.h"
#include "stepbasedprogressbar.h"

#include <QWidget>

class InitializeMessageDialog : public MessageDialog
{
    Q_OBJECT

public:
    explicit InitializeMessageDialog(QWidget *parent = nullptr);
    ~InitializeMessageDialog();
    void updateInitializingProgressBarWithBootStepWidth(int completedBootStep, int totalBootStep);

private:
    static const int INITIATE_STEP_PROGRESS_BAR_WIDTH = 280;
    static const int BORDER_THICKNESS_OF_INITIATE_STEP_PROGRESS_BAR = 2;
    static const int MARGIN_BETWEEN_BOOT_STEPS_IN_INITIATE_STEP_PROGRESS_BAR = 1;
    SpinnerMessageWidget * warningWidget = nullptr;
    StepBasedProgressBar * initializeProgressBar = nullptr;
    QWidget * mainWindow;

public slots:
    void updateLanguageMessage();
};

#endif // INITIALIZEMESSAGEDIALOG_H
