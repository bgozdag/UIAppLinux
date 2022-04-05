QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 debug

LIBS += -L$$PWD -ldl -lzmq -Wl,-rpath-link,$$PWD -lrt -g -rdynamic
OBJECTS += qrcode.o

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appstylesheets.cpp \
    chargingscreen.cpp \
    connectionscreen.cpp \
    disconnectionscreen.cpp \
    evc05chargeritem.cpp \
    evc05devicewidget.cpp \
    evc05homescreen.cpp \
    initializemessagedialog.cpp \
    languages/generated/appstrings.cpp \
    authorizewidget.cpp \
    authscreen.cpp \
    chargeritem.cpp \
    clickableqwidget.cpp \
    homescreen.cpp \
    homescreennotificationbar.cpp \
    innerscreen.cpp \
    languagemanager.cpp \
    languages/generated/translationstring.cpp \
    main.cpp \
    mainwindow.cpp \
    model/ac22charger.cpp \
    model/ac43charger.cpp \
    model/ccscharger.cpp \
    model/chademocharger.cpp \
    model/charger.cpp \
    model/schukocharger.cpp \
    persistentsettings.cpp \
    preparingforchargingscreen.cpp \
    progressbarwidget.cpp \
    screen.cpp \
    spinnermessagewidget.cpp \
    spinnerwidget.cpp \
    stepbasedprogressbar.cpp \
    stopchargingscreen.cpp \
    utils/stringutils.cpp \
    utils/uiutils.cpp \
    messagedialog.cpp \
    languagemessagedialog.cpp \
    warningmessagedialog.cpp \
    authorizemessagedialog.cpp \
    errormessagedialog.cpp \
    zmqhandler.cpp \
    errorwidget.cpp \
    languagewidget.cpp \
    languagebuttonwidget.cpp \
    appreciatescreen.cpp \
    firmwareupdatemessagedialog.cpp \
    topnotificationbar.cpp \
    emergencybuttondialog.cpp \
    emergencybuttondialogwidget.cpp

HEADERS += \
    appstylesheets.h \
    chargingscreen.h \
    connectionscreen.h \
    devicetype.h \
    disconnectionscreen.h \
    evc05chargeritem.h \
    evc05devicewidget.h \
    evc05homescreen.h \
    faultreason.h \
    firmwareupdatestate.h \
    initializemessagedialog.h \
    languages/generated/appstrings.h \
    authorizewidget.h \
    authscreen.h \
    chargeritem.h \
    chargeritemclicklistener.h \
    clickableqwidget.h \
    dimensions.h \
    homescreen.h \
    homescreennotificationbar.h \
    innerscreen.h \
    languagemanager.h \
    languages/generated/translationstring.h \
    mainwindow.h \
    model/headers/ac22charger.h \
    model/headers/ac43charger.h \
    model/headers/ccscharger.h \
    model/headers/chademocharger.h \
    model/headers/charger.h \
    model/headers/schukocharger.h \
    operationmode.h \
    persistentsettings.h \
    preparingforchargingscreen.h \
    progressbarwidget.h \
    screen.h \
    spinnermessagewidget.h \
    spinnerwidget.h \
    stepbasedprogressbar.h \
    stopchargingscreen.h \
    unavailablereason.h \
    utils/headers/stringutils.h \
    utils/headers/uiutils.h \
    messagedialog.h \
    languagemessagedialog.h \
    warningmessagedialog.h \
    authorizemessagedialog.h \
    errormessagedialog.h \
    zmqhandler.h \
    errorwidget.h \
    errorinfo.h \
    languagewidget.h \
    languagebuttonwidget.h \
    appreciatescreen.h \
    firmwareupdatemessagedialog.h \
    qrcode.hpp \
    topnotificationbar.h \
    emergencybuttondialog.h \
    emergencybuttondialogwidget.h

FORMS += \
    authorizewidget.ui \
    chargingscreen.ui \
    connectionscreen.ui \
    designer/authscreen.ui \
    designer/chargeritem.ui \
    designer/homescreennotificationbar.ui \
    designer/innerscreen.ui \
    designer/mainwindow.ui \
    disconnectionscreen.ui \
    evc05chargeritem.ui \
    evc05devicewidget.ui \
    preparingforchargingscreen.ui \
    messagedialog.ui \
    errorwidget.ui \
    languagewidget.ui \
    spinnermessagewidget.ui \
    stepbasedprogressbar.ui \
    topnotificationbar.ui \
    emergencybuttondialogwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    assets/fonts/muliblack.ttf \
    assets/fonts/mulibold.ttf \
    assets/fonts/muliregular.ttf \
    assets/fonts/mulisemibold.ttf
