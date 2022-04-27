import QtQuick 2.0

Item {
    id: root

    property int size: 150
    property int lineWidth: 5
    property real value: 0

    property color primaryColor: "#ffffff"
    property color secondaryColor: "#111111"

    property int animationDuration: 120000  // 2 minutes

    width: size
    height: size

    onValueChanged: {
        canvas.degree = value * 360;
    }


    Canvas {
        id: canvas

        property real degree: 0

        anchors.fill: parent
        antialiasing: true

        onDegreeChanged: {
            requestPaint();
        }

        Text {
            text: parseInt(root.value * 100) + "%"
            anchors.centerIn: parent
            font.pointSize: 75
            color: root.primaryColor
        }

        onPaint: {
            var ctx = getContext("2d");

            var x = root.width/2;
            var y = root.height/2;

            var radius = root.size/2 - root.lineWidth
            var startAngle = (Math.PI/180) * 270;
            var fullAngle = (Math.PI/180) * (270 + 360);
            var progressAngle = (Math.PI/180) * (270 + degree);

            ctx.reset()

            ctx.lineCap = 'round';
            ctx.lineWidth = root.lineWidth;

            ctx.beginPath();
            ctx.arc(x, y, radius, startAngle, fullAngle);
            ctx.strokeStyle = root.secondaryColor;
            ctx.stroke();

            ctx.beginPath();
            ctx.arc(x, y, radius, startAngle, progressAngle);
            ctx.strokeStyle = root.primaryColor;
            ctx.stroke();
        }

        NumberAnimation on degree {
            duration: root.animationDuration / 100
        }
    }

    NumberAnimation on value {
        from: 0
        to: 1
        duration: root.animationDuration
        running: true
    }
}