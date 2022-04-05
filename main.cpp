#include "dimensions.h"
#include "mainwindow.h"
#include <QApplication>

#include <execinfo.h>
#include <signal.h>
#include <QDir>
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <utils/headers/stringutils.h>

std::shared_ptr<std::FILE> openFileToWrite(const char * fileName, const char * flags)
{
    return std::shared_ptr<std::FILE>(std::fopen(fileName, flags), std::fclose);
}

const QString CRASH_LOG_FOLDER_PATH = "/home/root/crashLogs/evc03ui/";
const string EVC03_UI_CRASH_LOG_FILE = "evc03uicrash.log"; // timestamp is added to this name. (ex: 21-08-25_11.25.24_evc03uicrash.log)

void handler(int sig) {
    int crashLogarraySize = 100;
    void *crashLogarray[crashLogarraySize];
    int size;
    size = backtrace(crashLogarray, crashLogarraySize);

    static std::time_t currentTime = std::time(nullptr);
    std::stringstream evc03UiCrashLogFileNameWithTimeStamp;
    evc03UiCrashLogFileNameWithTimeStamp << std::put_time(std::localtime(&currentTime), "%y-%m-%d_%OH.%OM.%OS_") << EVC03_UI_CRASH_LOG_FILE;

    QString evc03UiCrashPath(CRASH_LOG_FOLDER_PATH);
    QDir dir;

    if (!dir.exists(evc03UiCrashPath))
    {
        dir.mkpath(evc03UiCrashPath);
    }

    auto evc03UiCrashLogFile = openFileToWrite((evc03UiCrashPath.toStdString() + evc03UiCrashLogFileNameWithTimeStamp.str()).c_str(), "wb");
    int backtraceSymbolsFd = fileno(evc03UiCrashLogFile.get());

    backtrace_symbols_fd(crashLogarray, size, backtraceSymbolsFd);
    exit(1);
}

int main(int argc, char **argv) {
    signal(SIGSEGV, handler);

    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    w.setGeometry(0, 0, Dimensions::WINDOW_WIDTH, Dimensions::WINDOW_HEIGHT);
    w.setFixedSize(w.size());
    w.show();
    return a.exec();
}
