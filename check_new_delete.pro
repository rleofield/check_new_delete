TEMPLATE = app
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
QMAKE_CXXFLAGS_DEBUG += -Wno-unused
QMAKE_CXXFLAGS_DEBUG -= -Wwrite-strings
#QMAKE_CXXFLAGS_DEBUG -= -Wunused-variable
QMAKE_CXXFLAGS_DEBUG += -Weffc++

QMAKE_CXXFLAGS_RELEASE += -O2
QMAKE_CXXFLAGS_RELEASE += -std=c++0x
QMAKE_CXXFLAGS_RELEASE += -Wparentheses
QMAKE_CXXFLAGS_RELEASE += -Wreturn-type
QMAKE_CXXFLAGS_RELEASE += -Wshadow
QMAKE_CXXFLAGS_RELEASE += -Wextra
QMAKE_CXXFLAGS_RELEASE += -Wunused-parameter
QMAKE_CXXFLAGS_RELEASE -= -Wwrite-strings
#QMAKE_CXXFLAGS_RELEASE -= -Wunused-variable
#QMAKE_CXXFLAGS_RELEASE += -Weffc++

#QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/lib

message("qmake check_new_delete")


INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/log


SOURCES += \
    src/main.cpp \
    src/impl.cpp \
    src/log/tLogImpl.cpp \
    src/log/tLog.cpp

HEADERS += \
    src/impl.h \
    src/log/tLogImpl.h \
    src/log/tLogEnum.h \
    src/log/tLogCategories.h \
    src/log/tLog.h \
    src/log/tLog_Category_default.h \
    src/log/tLfm.h \
    src/log/tLfmCL.h


LIBS= -lboost_thread
LIBS += -lboost_system #-lboost_system-mt
LIBS += -lboost_filesystem #-lboost_filesystem-mt
