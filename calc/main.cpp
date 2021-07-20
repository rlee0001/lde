#include<X11/Xlib.h>
#include<X11/X.h>
#include<X11/Xutil.h>

#include<cairo/cairo.h>
#include<cairo/cairo-xlib.h>

#include<iostream>

using namespace std;

void draw(cairo_t *cr)
{
    cairo_set_source_rgba(cr, 1.0, 0.0, 0.0, 0.5);
    cairo_rectangle(cr, 0, 0, 200, 200);
    cairo_fill(cr);
}

int main(int argc, char* argv[])
{
    Display *d = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(d);
    int default_screen = XDefaultScreen(d);

    XVisualInfo vinfo;
    if (!XMatchVisualInfo(d, default_screen, 32, TrueColor, &vinfo))
    {
        cout << "No visual found supporting 32-bit color." << endl;
        return 1;
    }

    XSetWindowAttributes attrs;
    attrs.override_redirect = true;
    attrs.colormap = XCreateColormap(d, root, vinfo.visual, AllocNone);
    attrs.background_pixel = 0;
    attrs.border_pixel = 0;
    attrs.event_mask = KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask;

    Window overlay = XCreateWindow(
        d, root, 0, 0, 200, 200, 0, vinfo.depth, InputOutput, vinfo.visual,
        CWOverrideRedirect | CWColormap | CWBackPixel | CWBorderPixel, &attrs
    );

    XMapWindow(d, overlay);

    cairo_surface_t *surf = cairo_xlib_surface_create(d, overlay, vinfo.visual, 200, 200);
    cairo_t *cr = cairo_create(surf);

    draw(cr);
    XFlush(d);

    bool run = true;
    XEvent xEvent;

    while (run)
    {
        XNextEvent(d, &xEvent);

        cout << "Event: " << xEvent.type << endl;

        switch (xEvent.type)
        {
        case ButtonRelease:
            run = false;
        }
    }

    cairo_destroy(cr);
    cairo_surface_destroy(surf);

    XUnmapWindow(d, overlay);
    XCloseDisplay(d);
    return 0;
}