#include "appstylesheets.h"
#include "stepbasedprogressbar.h"
#include "ui_stepbasedprogressbar.h"
#include <utils/headers/uiutils.h>

StepBasedProgressBar::StepBasedProgressBar(QWidget *parent, int progressBarWidth, int borderThicknessOfProgressBar, int marginBetweenBootSteps) :
    QWidget(parent),
    ui(new Ui::StepBasedProgressBar)
{
    ui->setupUi(this);
    this->progressBarWidth = progressBarWidth;
    this->borderThicknessOfProgressBar = borderThicknessOfProgressBar;
    this->marginBetweenBootSteps = marginBetweenBootSteps;
}

StepBasedProgressBar::~StepBasedProgressBar()
{
    delete ui;
}

void StepBasedProgressBar::hideProgressBar()
{
    ui->initializingProgressBar->hide();
}

QWidget * StepBasedProgressBar::getProgressBarWidget()
{
    return  ui->initializingProgressBarWidget;
}

void StepBasedProgressBar::calculateBootStepWidthAndSetProgressBar(int completedBootStep, int totalBootStep)
{
    int bootStepWidth;
    int updatedProgressBarWidth;

    bootStepWidth = (progressBarWidth - (borderThicknessOfProgressBar * 2) - ((totalBootStep * 2)* marginBetweenBootSteps)) / totalBootStep;
    updatedProgressBarWidth = (totalBootStep * bootStepWidth) + ((totalBootStep * 2)* marginBetweenBootSteps) + (borderThicknessOfProgressBar * 2);

    ui->initializingProgressBar->setMaximumWidth(updatedProgressBarWidth);
    ui->initializingProgressBar->show();
    UIUtils::setStyleSheetAndUpdate(ui->initializingProgressBar,
                                    UIUtils::getStyleSheetForBootStepWidthOfInitializingProgressBar(QString::number(bootStepWidth).toStdString(),
                                                                                                    QString::number(borderThicknessOfProgressBar).toStdString(),
                                                                                                    QString::number(marginBetweenBootSteps).toStdString(),
                                                                                                    AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::INITIALIZING_PROGRESS_BAR_ITEM)));
    ui->initializingProgressBar->setValue(100 * completedBootStep / totalBootStep);
}
