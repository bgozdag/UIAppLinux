import QtQuick 2.0
import QtQuick.Controls 2.4
import QtGraphicalEffects 1.0

Rectangle {
    id: progressBar
    radius: 15
    clip: true

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#b6f826" }
        GradientStop { position: 1.0; color: "#219203" }
    }

    PropertyAnimation {
        id: progressAnimator
        target: progressBar
        properties: "width"
        from: 0
        to: progressBar.width
        running:true
        duration: 5000
        loops: Animation.Infinite
   }

    signal progressSignal(int progress)
    onProgressSignal:{
        if (!progressAnimator.running) {
            progressBar.width = (progress*maxProgressBarWidth)/100
        }
    }

    signal setIndeterminateSignal(bool indeterminate)
    onSetIndeterminateSignal: {
        if (indeterminate) {
            progressAnimator.restart()
        } else {
            progressAnimator.stop()
        }
    }

    signal setSizeSignal(int height, int width)
    onSetSizeSignal:{
        progressBar.height = height
        progressBar.width = width
        maxProgressBarHeight = height
        maxProgressBarWidth = width
    }

    property var maxProgressBarHeight;
    property var maxProgressBarWidth;
}

