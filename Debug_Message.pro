#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T23:19:00
#
#-------------------------------------------------

QT -= gui

TARGET = Debug_Message
TEMPLATE = lib
CONFIG += staticlib

MY_VERSION = 1.0.0
PROJECT = /home/pablo/workspace/projects
!include($$PROJECT/my_application/Build.pri) {
    error("Unable to load $$TOPDIR/build.pri")
}
!include(Debug_Message.pri) {
    error("Unable to load Debug_Message.pri")
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}
