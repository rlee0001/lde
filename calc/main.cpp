#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Xaw/Label.h>

int main(int argc, char* argv[])
{
    XtAppContext app_context;
    Widget toplevel, hello;

    toplevel = XtVaAppInitialize(
        &app_context,
        "XHello",
        NULL, 0,
        &argc, argv,
        NULL,
        NULL);

    hello = XtVaCreateManagedWidget("hello", labelWidgetClass, toplevel, NULL);

    XtAddCallback(hello, XmNactivateCallback, onClick, NULL);

    XtRealizeWidget(toplevel);
    XtAppMainLoop(app_context);
}

void onClick(Widget widget, XtPointer client_data, XtPointer call_data)
{
   printf("Hello Yourself!");
}