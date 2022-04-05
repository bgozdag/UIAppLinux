#ifndef STEPBASEDPROGRESSBAR_H
#define STEPBASEDPROGRESSBAR_H

#include <QWidget>

namespace Ui {
class StepBasedProgressBar;
}

class StepBasedProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit StepBasedProgressBar(QWidget *parent, int progressBarWidth, int borderThicknessOfProgressBar, int marginBetweenBootSteps);
    ~StepBasedProgressBar();
    void hideProgressBar();
    QWidget *getProgressBarWidget();
    void calculateBootStepWidthAndSetProgressBar(int completedBootStep, int totalBootStep);

private:
    Ui::StepBasedProgressBar *ui;
    int progressBarWidth;
    int borderThicknessOfProgressBar;
    int marginBetweenBootSteps;
};

#endif // STEPBASEDPROGRESSBAR_H
