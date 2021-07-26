QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Figure_Clases/rect_t.cpp \
    Figure_Clases/shape.cpp \
    Figure_Clases/trapezoid.cpp \
    Figure_Clases/triangle.cpp \
    levels/level_class.cpp \
    main.cpp \
    main_window.cpp

HEADERS += \
    Figure_Clases/rect_t.h \
    Figure_Clases/shape.h \
    Figure_Clases/trapezoid.h \
    Figure_Clases/triangle.h \
    levels/level_class.h \
    main_window.h

TRANSLATIONS += \
    POO_Tangram_es_419.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources_file.qrc

DISTFILES += \
    corona.png
