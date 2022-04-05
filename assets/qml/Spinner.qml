import QtQuick 2.0
import QtQuick.Controls 2.4
import QtGraphicalEffects 1.0

Image {
    id : spinner
    source: "qrc:/assets/images/black_spinner"

    RotationAnimation {
        target: spinner;
        from: 0;
        to: 360;
        duration: 1500
        running: true
        loops: Animation.Infinite
    }
    signal setSourceSignal(string src)
    onSetSourceSignal:{
        spinner.source = src
    }

}




