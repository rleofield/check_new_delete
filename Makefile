#############################################################################
# Makefile for building: check_new_delete
# Generated by qmake (3.0) (Qt 5.1.0) on: Thu Jan 16 12:34:51 2014
# Project:  check_new_delete.pro
# Template: app
# Command: /home/richard/Qt5.1.0/5.1.0/gcc_64/bin/qmake -spec linux-g++ CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug -o Makefile check_new_delete.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_QML_DEBUG -DQT_DECLARATIVE_DEBUG
CFLAGS        = -pipe -g -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -gdwarf-3 -g -O0 -std=c++0x -Wparentheses -Wreturn-type -Wshadow -Wextra -Wno-unused -Weffc++ -Wall -W -fPIE $(DEFINES)
INCPATH       = -I../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/linux-g++ -I. -Isrc -Isrc/log
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/richard/Qt5.1.0/5.1.0/gcc_64
LIBS          = $(SUBLIBS) -lboost_thread -lboost_system -lboost_filesystem 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/richard/Qt5.1.0/5.1.0/gcc_64/bin/qmake
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
		src/log/tLog.cpp 
OBJECTS       = .tmp/main.o \
		.tmp/impl.o \
		.tmp/tLogImpl.o \
		.tmp/tLog.o
DIST          = ../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/linux.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/qconfig.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_bootstrap.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_clucene.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_designercomponents.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_platformsupport.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qmldevtools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_quickparticles.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_v8.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/unix/default_pre.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qml_debug.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/declarative_debug.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/wayland-scanner.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/lex.prf \
		check_new_delete.pro \
		check_new_delete.pro
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
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: check_new_delete.pro ../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/linux-g++/qmake.conf ../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/linux.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/qconfig.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_bootstrap.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_clucene.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_designercomponents.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_platformsupport.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qmldevtools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_quickparticles.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_v8.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/unix/default_pre.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qml_debug.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/declarative_debug.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/wayland-scanner.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/lex.prf \
		check_new_delete.pro
	$(QMAKE) -spec linux-g++ CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug -o Makefile check_new_delete.pro
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/spec_pre.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/shell-unix.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/unix.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/linux.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/gcc-base.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/gcc-base-unix.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/g++-base.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/common/g++-unix.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/qconfig.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_bootstrap.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_clucene.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_core.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_declarative.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_designer.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_designercomponents.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_gui.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_help.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_network.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_platformsupport.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qml.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qmldevtools.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_quick.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_quickparticles.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_script.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_sql.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_svg.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_v8.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_webkit.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_xml.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qt_functions.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qt_config.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/linux-g++/qmake.conf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/spec_post.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/exclusive_builds.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/default_pre.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/unix/default_pre.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/resolve_config.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/default_post.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/qml_debug.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/declarative_debug.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/unix/gdb_dwarf_index.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/warn_on.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/wayland-scanner.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/testcase_targets.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/exceptions.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/yacc.prf:
../../../Qt5.1.0/5.1.0/gcc_64/mkspecs/features/lex.prf:
check_new_delete.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug -o Makefile check_new_delete.pro

qmake_all: FORCE

dist: 
	@test -d .tmp/check_new_delete1.0.0 || mkdir -p .tmp/check_new_delete1.0.0
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/check_new_delete1.0.0/ && (cd `dirname .tmp/check_new_delete1.0.0` && $(TAR) check_new_delete1.0.0.tar check_new_delete1.0.0 && $(COMPRESS) check_new_delete1.0.0.tar) && $(MOVE) `dirname .tmp/check_new_delete1.0.0`/check_new_delete1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/check_new_delete1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_wayland-server-header_make_all:
compiler_wayland-server-header_clean:
compiler_wayland-client-header_make_all:
compiler_wayland-client-header_clean:
compiler_wayland-code_make_all:
compiler_wayland-code_clean:
compiler_qtwayland-client-header_make_all:
compiler_qtwayland-client-header_clean:
compiler_qtwayland-client-code_make_all:
compiler_qtwayland-client-code_clean:
compiler_qtwayland-server-header_make_all:
compiler_qtwayland-server-header_clean:
compiler_qtwayland-server-code_make_all:
compiler_qtwayland-server-code_clean:
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
		src/impl.h \
		src/log/tLfm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/main.o src/main.cpp

.tmp/impl.o: src/impl.cpp src/impl.h \
		src/log/tLfm.h \
		src/log/tLog.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/tLog_Category_default.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/impl.o src/impl.cpp

.tmp/tLogImpl.o: src/log/tLogImpl.cpp src/log/tLogImpl.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/tLogCategories.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/tLogImpl.o src/log/tLogImpl.cpp

.tmp/tLog.o: src/log/tLog.cpp src/log/tLog.h \
		src/log/tLfmCL.h \
		src/log/tLogEnum.h \
		src/log/tLogImpl.h \
		src/log/tLogCategories.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .tmp/tLog.o src/log/tLog.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
