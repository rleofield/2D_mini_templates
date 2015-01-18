#-------------------------------------------------
#
# Project created by QtCreator 2013-10-01T22:28:55
#
#-------------------------------------------------

QTEMPLATE = app
CONFIG += console
CONFIG -= qt

#DESTDIR += bin
CONFIG  += x86_64


OBJECTS_DIR = .tmp
MOC_DIR = .tmp
UI_DIR = .tmp
RCC_DIR = .tmp


QMAKE_CXXFLAGS += -gdwarf-3


QMAKE_CXXFLAGS_DEBUG += -O0
QMAKE_CXXFLAGS_DEBUG += -std=c++0x
QMAKE_CXXFLAGS_DEBUG += -Wparentheses
QMAKE_CXXFLAGS_DEBUG += -Wreturn-type
QMAKE_CXXFLAGS_DEBUG += -Wshadow
QMAKE_CXXFLAGS_DEBUG += -Wextra
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-parameter
QMAKE_CXXFLAGS_DEBUG += -Wwrite-strings
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-variable
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-function
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-variable
#QMAKE_CXXFLAGS_DEBUG += -Weffc++
QMAKE_CXXFLAGS_DEBUG += -Wparentheses
QMAKE_CXXFLAGS_DEBUG += -Wreturn-type
QMAKE_CXXFLAGS_DEBUG += -Wshadow
QMAKE_CXXFLAGS_DEBUG += -Wextra
QMAKE_CXXFLAGS_DEBUG += -Wunused-parameter

QMAKE_CXXFLAGS_DEBUG += -Wwrite-strings
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-variable
QMAKE_CXXFLAGS_DEBUG += -Wpedantic
QMAKE_CXXFLAGS_DEBUG += -Wno-unused-but-set-variable
QMAKE_CXXFLAGS_DEBUG += -Werror
QMAKE_CXXFLAGS_DEBUG += -Wall
QMAKE_CXXFLAGS_DEBUG += -Wcast-align
QMAKE_CXXFLAGS_DEBUG += -Wcast-qual
QMAKE_CXXFLAGS_DEBUG += -Woverloaded-virtual
QMAKE_CXXFLAGS_DEBUG += -Wzero-as-null-pointer-constant
QMAKE_CXXFLAGS_DEBUG += -Wwrite-strings
QMAKE_CXXFLAGS_DEBUG += -Wconversion
QMAKE_CXXFLAGS_DEBUG += -Wold-style-cast


QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE += -std=c++0x
QMAKE_CXXFLAGS_RELEASE += -Wparentheses
QMAKE_CXXFLAGS_RELEASE += -Wreturn-type
QMAKE_CXXFLAGS_RELEASE += -Wshadow
QMAKE_CXXFLAGS_RELEASE += -Wextra
QMAKE_CXXFLAGS_RELEASE += -Wunused-parameter
#QMAKE_CXXFLAGS_RELEASE -= -Wwrite-strings
QMAKE_CXXFLAGS_RELEASE += -Wunused-variable
QMAKE_CXXFLAGS_RELEASE += -Wno-unused-variable
#QMAKE_CXXFLAGS_RELEASE += -Weffc++

message("qmake 2D_mini_templates")


SOURCES += src/test.cpp \
    src/main.cpp \
    src/hstring/t_2D_string.cpp \
    src/hstring/stringhelper.cpp \
    src/hstring/gettokens.cpp

HEADERS += \
    src/minit/tObjPositionSize.h \
    src/minit/tLine.h \
    src/minit/tIndexID.h \
    src/minit/tArea.h \
    src/minit/t_3D_xyz.h \
    src/minit/t_2D_xy.h \
    src/minit/t_2D_Matrix.h \
    src/hstring/t_2D_string.h \
    src/hstring/stringhelper.h \
    src/hstring/gettokens.h \
    src/boost/boost_cstdint.h

INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/minit
INCLUDEPATH += $$PWD/src/hstring
INCLUDEPATH += $$PWD/src/boost

LIBS += -lboost_system
LIBS += -lboost_filesystem




#LIBS= -lboost_thread-mt -lboost_system -lboost_filesystem
LIBS= -lboost_system -lboost_filesystem

OTHER_FILES += \
    lgpl-3.0.txt \
    README.md
