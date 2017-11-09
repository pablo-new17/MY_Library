#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T11:46:38
#
#-------------------------------------------------
QT       -= gui

TARGET = Byte_Array
TEMPLATE = lib
CONFIG += staticlib


MY_VERSION = 1.0.0

PROJECT = /home/pablo/workspace/projects
!include($$PROJECT/my_application/Build.pri) {
    error("Unable to load $$TOPDIR/build.pri")
}
!include(Byte_Array.pri) {
    error("Unable to load Byte_Array.pri")
}
