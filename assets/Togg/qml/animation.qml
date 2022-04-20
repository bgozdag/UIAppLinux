import QtQuick 2.0
import QtQuick.Window 2.2
import QtMultimedia 5.0


Rectangle
{
    width: 300
    height: 300
    color: "transparent"
    Image {
        id: image
        x: 0
        y: 0
        property int currentImage: 0
        source: "animation_src/Render" + pad(currentImage) + ".png"
        SequentialAnimation on currentImage{
            id: animation
            NumberAnimation{
                target: image
                property: "currentImage"
                from: 0
                to: 249
                duration: 10000
            }
            NumberAnimation{
                target: image
                property: "currentImage"
                from: 248
                to: 1
                duration: 10000
            }
            loops: Animation.Infinite
        }
    }
    function pad(n) {
        if (n < 10)
            return "00" + n;
        else if (n < 100)
            return "0" + n;
        else
            return n;
    }

    signal progressSignal(int progress)
    onProgressSignal:{
    }

    signal setIndeterminateSignal(bool indeterminate)
    onSetIndeterminateSignal: {
        if (indeterminate) {
            animation.restart()
        } else {
            animation.stop()
        }
    }

    signal setSizeSignal(int height, int width)
    onSetSizeSignal:{
    }

    property var maxProgressBarHeight;
    property var maxProgressBarWidth;
}




//Image {
//    id: image
//    property int currentImage: 1
//    x: 0
//    y: 0
//    source: "src/ToGG_" + currentImage + ".jpg"
//    NumberAnimation on currentImage {
//    from: 1
//    to: 500
//    duration: 20000
//    loops: Animation.Infinite
//    }
//}


//Video {
//    id: video
//    width: 1024
//    height: 768
//    source: "qrc:/src/ToGG.mp4"
//    loops: Animation.Infinite
//    autoPlay: true
//}
