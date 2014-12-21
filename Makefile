#############################################################################
# Makefile for building: check_new_delete
# Generated by qmake (3.0) (Qt 5.3.0)
# Project:  check_new_delete.pro
# Template: app
# Command: /home/richard/Qt5.3.0/5.3/gcc_64/bin/qmake -spec linux-g++ CONFIG+=debug -o Makefile check_new_delete.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -g -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -gdwarf-3 -g -O0 -std=c++0x -Wparentheses -Wreturn-type -Wshadow -Wextra -Wno-unused -Wno-unused-variable -Weffc++ -Wall -W -fPIE $(DEFINES)
INCPATH       = -I../../../Qt5.3.0/5.3/gcc_64/mkspecs/linux-g++ -I. -Isrc -Isrc/log -Isrc/hstring
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/richard/Qt5.3.0/5.3/gcc_64
LIBS          = $(SUBLIBS) -lboost_thread -lboost_system -lboost_filesystem 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/richard/Qt5.3.0/5.3/gcc_64/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = .tmp/

####### Files

SOURCES       = src/main.cpp \
		src/impl.cpp \
		src/log/tLogImpl.cpp \
		src/log/tLog.cpp \
		src/log/alloccheck.cpp \
		src/hstring/stringhelper.cpp \
		src/hstring/gettokens.cpp 
OBJECTS       = .tmp/main.o \
		.tmp/impl.o \
		.tmp/tLogImpl.o \
		.tmp/tLog.o \
		.tmp/alloccheck.o \
		.tmp/stringhelper.o \
		.tmp/gettokens.o
DIST          = ../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/linux.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/qconfig.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/lex.prf \
		check_new_delete.pro src/main.cpp \
		src/impl.cpp \
		src/log/tLogImpl.cpp \
		src/log/tLog.cpp \
		src/log/alloccheck.cpp \
		src/hstring/stringhelper.cpp \
		src/hstring/gettokens.cpp
QMAKE_TARGET  = check_new_delete
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = check_new_delete


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: check_new_delete.pro ../../../Qt5.3.0/5.3/gcc_64/mkspecs/linux-g++/qmake.conf ../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/linux.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/qconfig.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/lex.prf \
		check_new_delete.pro
	$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile check_new_delete.pro
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/spec_pre.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/shell-unix.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/unix.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/linux.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/gcc-base.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/gcc-base-unix.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/g++-base.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/common/g++-unix.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/qconfig.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_core.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_declarative.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designer.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_enginio.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_gui.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_help.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_network.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qml.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quick.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_script.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sql.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_svg.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkit.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xml.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/qt_functions.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/qt_config.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/linux-g++/qmake.conf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/spec_post.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/exclusive_builds.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/default_pre.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/resolve_config.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/default_post.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/warn_on.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/testcase_targets.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/exceptions.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/yacc.prf:
../../../Qt5.3.0/5.3/gcc_64/mkspecs/features/lex.prf:
check_new_delete.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile check_new_delete.pro

qmake_all: FORCE

dist: 
	@test -d .tmp/check_new_delete1.0.0 || mkdir -p .tmp/check_new_delete1.0.0
	$(COPY_FILE) --parents $(DIST) .tmp/check_new_delete1.0.0/ && (cd `dirname .tmp/check_new_delete1.0.0` && $(TAR) check_new_delete1.0.0.tar check_new_delete1.0.0 && $(COMPRESS) check_new_delete1.0.0.tar) && $(MOVE) `dirname .tmp/check_new_delete1.0.0`/check_new_delete1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/check_new_delete1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

.tmp/main.o: src/main.cpp src/log/tLog.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/tLog_Category_default.h \
		src/log/tLog_Category_A.h \
		src/log/tLogCategories.h \
		src/log/tLfm.h \
		src/log/alloccheck.h \
		src/impl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/main.o src/main.cpp

.tmp/impl.o: src/impl.cpp src/log/alloccheck.h \
		src/log/tLfm.h \
		src/impl.h \
		src/log/tLog.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/tLog_Category_default.h \
		src/log/win32.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/impl.o src/impl.cpp

.tmp/tLogImpl.o: src/log/tLogImpl.cpp src/log/tLogImpl.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/tLogCategories.h \
		src/log/win32.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/tLogImpl.o src/log/tLogImpl.cpp

.tmp/tLog.o: src/log/tLog.cpp src/log/tLfm.h \
		src/log/tLog.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/tLogImpl.h \
		src/log/tLogCategories.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/tLog.o src/log/tLog.cpp

.tmp/alloccheck.o: src/log/alloccheck.cpp src/hstring/stringhelper.h \
		src/log/tLog.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/alloccheck.h \
		src/log/tLfm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/alloccheck.o src/log/alloccheck.cpp

.tmp/stringhelper.o: src/hstring/stringhelper.cpp src/hstring/stringhelper.h \
		src/hstring/gettokens.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/stringhelper.o src/hstring/stringhelper.cpp

.tmp/gettokens.o: src/hstring/gettokens.cpp src/hstring/gettokens.h \
		src/hstring/stringhelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/gettokens.o src/hstring/gettokens.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

