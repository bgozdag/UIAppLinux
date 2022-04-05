#include "appstylesheets.h"
#include "initializemessagedialog.h"
#include "spinnerwidget.h"
#include <utils/headers/uiutils.h>

#include <languages/generated/appstrings.h>

InitializeMessageDialog::InitializeMessageDialog(QWidget *parent) :
    MessageDialog(parent),
    mainWindow(parent)
{
    warningWidget = new SpinnerMessageWidget();
    warningWidget->setMessage(AppStrings::device_initializing);
    getMessageDialogContainer()->addWidget(warningWidget);

    initializeProgressBar = new StepBasedProgressBar(this, INITIATE_STEP_PROGRESS_BAR_WIDTH, BORDER_THICKNESS_OF_INITIATE_STEP_PROGRESS_BAR, MARGIN_BETWEEN_BOOT_STEPS_IN_INITIATE_STEP_PROGRESS_BAR);
    getMessageDialogContainer()->addWidget(initializeProgressBar->getProgressBarWidget());

    hideCloseButton();
    initializeProgressBar->hideProgressBar();
    connect(mainWindow, SIGNAL(languageChangedSignal()), this, SLOT(updateLanguageMessage()));
}

InitializeMessageDialog::~InitializeMessageDialog()
{
}

void InitializeMessageDialog::updateInitializingProgressBarWithBootStepWidth(int completedBootStep, int totalBootStep)
{
    initializeProgressBar->calculateBootStepWidthAndSetProgressBar(completedBootStep, totalBootStep);
}

void InitializeMessageDialog::updateLanguageMessage()
{
    warningWidget->setMessage(AppStrings::device_initializing);
}
