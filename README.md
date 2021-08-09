# Any2c GUI

![any2cgui](https://i.ibb.co/48hfRLY/Any2c-GUI-v1-1-Linux.png)

Any2c (formerly Raw2c, hence the filenames) is a GUI utility to convert files into byte data that can be used inside a C or C++ application. It supports multiple files and can export .c or .cpp sources along with a header file.

By default, Any2c will use string literals for the produced sources to reduce their size as much as possible. If the option for the string literals is disabled, it will produce arrays of [unsigned char] values, either in decimal or hexadecimal.

Developed using wxWidgets 3.0 and Code::Blocks (+ wxSmith plugin).
