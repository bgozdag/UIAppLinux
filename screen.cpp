#include "dimensions.h"
#include "screen.h"

Screen::Screen(QWidget * parent) : QWidget(parent)
{
    setGeometry(0, 0, Dimensions::WINDOW_WIDTH, Dimensions::WINDOW_HEIGHT);
}

Screen::~Screen()
{

}
