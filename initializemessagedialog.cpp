#include "appstylesheets.h"
#include "initializemessagedialog.h"
#include "spinnerwidget.h"
#include <utils/headers/uiutils.h>
#include "dimensions.h"

#include <languages/generated/appstrings.h>

InitializeMessageDialog::InitializeMessageDialog(QWidget *parent) :
    MessageDialog(parent),
    mainWindow(parent)
{
//    warningWidget = new SpinnerMessageWidget();
//    warningWidget->setMessage(AppStrings::device_initializing);
//    getMessageDialogContainer()->addWidget(warningWidget);

//    initializeProgressBar = new StepBasedProgressBar(this, INITIATE_STEP_PROGRESS_BAR_WIDTH, BORDER_THICKNESS_OF_INITIATE_STEP_PROGRESS_BAR, MARGIN_BETWEEN_BOOT_STEPS_IN_INITIATE_STEP_PROGRESS_BAR);
//    getMessageDialogContainer()->addWidget(initializeProgressBar->getProgressBarWidget());

    hideCloseButton();
//    initializeProgressBar->hideProgressBar();
    connect(mainWindow, SIGNAL(languageChangedSignal()), this, SLOT(updateLanguageMessage()));
    this->resize(Dimensions::WINDOW_WIDTH, Dimensions::WINDOW_HEIGHT);
    this->move(0,0);
    this->hideGridLayoutWidget();

    QQuickWidget *progressBar = new QQuickWidget(this);
    progressBar->setAttribute(Qt::WA_TranslucentBackground);
    progressBar->setClearColor(Qt::transparent);
    progressBar->setAttribute(Qt::WA_AlwaysStackOnTop);
    progressBar->setSource(QUrl("qrc:/assets/qml/CircularProgressBar.qml"));
    progressBar->setGeometry(int((Dimensions::WINDOW_WIDTH-150)/2),int((Dimensions::WINDOW_HEIGHT-150)/2) + 230,150,150);
    progressBar->show();
    progressBar->raise();

    QString projectType = UIUtils::getProjectType();
    qDebug() << "Project type:" << projectType << endl;
    if (projectType == "EVC05")
    {
        this->setStyleSheet("background-image: url(:/assets/images/evc05_init_background.png); background-position: center; background-origin: content;");
        progressBar->setGeometry(int((Dimensions::WINDOW_WIDTH-150)/2),int((Dimensions::WINDOW_HEIGHT-150)/2) + 270,150,150);
    }
    else
    {
        this->setStyleSheet("background-image: url(:/assets/images/evc03_init_background.png); background-position: center; background-origin: content;");
        if (projectType == "EVC10")
        {
            progressBar->setGeometry(int((Dimensions::WINDOW_WIDTH-150)/2),int((Dimensions::WINDOW_HEIGHT-150)/2) + 210,150,150);
        }
    }

}

InitializeMessageDialog::~InitializeMessageDialog()
{
}

void InitializeMessageDialog::updateInitializingProgressBarWithBootStepWidth(int completedBootStep, int totalBootStep)
{
//    initializeProgressBar->calculateBootStepWidthAndSetProgressBar(completedBootStep, totalBootStep);
}

void InitializeMessageDialog::updateLanguageMessage()
{
//    warningWidget->setMessage(AppStrings::device_initializing);
}
