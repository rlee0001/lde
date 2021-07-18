#include <X11/extensions/shape.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>  //This is used for the size hints structure
#include <X11/Xcursor/Xcursor.h>
#include <X11/extensions/shape.h>
#include <X11/Xatom.h>
#include <X11/extensions/Xrandr.h>

#include<iostream>

using namespace std;

int main() {
    Display* display = NULL;
    Window root;

    display = XOpenDisplay(NULL);

    root = DefaultRootWindow(display);

    XRRSelectInput(display, root, RRScreenChangeNotifyMask);

	cout << "Hi." << endl;

	return 0;
}