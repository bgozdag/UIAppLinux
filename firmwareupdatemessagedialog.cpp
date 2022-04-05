#include "appstylesheets.h"
#include "firmwareupdatemessagedialog.h"
#include "spinnerwidget.h"
#include "firmwareupdatestate.h"
#include "devicetype.h"
#include "utils/headers/stringutils.h"

#include <sstream>
#include <languages/generated/appstrings.h>

FirmwareUpdateMessageDialog::FirmwareUpdateMessageDialog(QWidget *parent) :
    MessageDialog(parent)
{
    warningWidget = new SpinnerMessageWidget();
    warningWidget->setMessage(AppStrings::text_firmware_update);
    getMessageDialogContainer()->addWidget(warningWidget);

    progressBar = new QProgressBar();
    progressBar->setStyleSheet("height:30px; width:300px; font-size:20px");
    progressBar->setValue(0);
    progressBar->setVisible(false);

    warningWidget->addWidgetToSpinnerMessageContainer(progressBar, 0, Qt::AlignHCenter|Qt::AlignTop);

    hideCloseButton();
}

FirmwareUpdateMessageDialog::~FirmwareUpdateMessageDialog()
{

}

void FirmwareUpdateMessageDialog::onFirmwareUpdateProgress(int deviceType, int progress, int firmwareUpdateState)
{
    bool showProgressBar = false;
    if (firmwareUpdateState >= 0 && firmwareUpdateState < FirmwareUpdateState::COUNT) {
        std::stringstream strStream;

        strStream << AppStrings::firmware_update_text.getForLocale().c_str() << "\n";

        switch(firmwareUpdateState) {
            case FirmwareUpdateState::REBOOTING:
                strStream << AppStrings::rebooting_for_update.getForLocale().c_str();
                break;
            case FirmwareUpdateState::TRANSFERRING:
                strStream << AppStrings::transferring_update.getForLocale().c_str();
                showProgressBar = true;
                break;
            default:
                strStream << AppStrings::installing_update.getForLocale().c_str();
                break;
        }

        std::string boardName = "";

        switch(deviceType) {
            case DeviceType::CTB:
            case DeviceType::ACCT:
                boardName = AppStrings::main_board.getForLocale();
                break;
            case DeviceType::HMI:
                boardName = "HMI";
                break;
            case DeviceType::CCS_BOARD:
                boardName = "PLC";
                break;
        }

        warningWidget->setMessage(StringUtils::replaceAll(strStream.str(), "<board_name>", boardName).c_str());
    }

    progressBar->setValue(progress);
    progressBar->setVisible(showProgressBar);
}
