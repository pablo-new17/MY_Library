
TOPDIR = $$PROJECT/my_library/DebugMessage

#PABLO_ONLY = 1
defined(PABLO_ONLY, var) {
    CURRENT_DIR = $$TOPDIR
}
!defined(PABLO_ONLY, var) {
    CURRENT_DIR = $$PWD
}

INCLUDEPATH += $$CURRENT_DIR/src

SOURCES += \
    $$CURRENT_DIR/src/Debug_Message.cpp

HEADERS += \
    $$CURRENT_DIR/src/Debug_Message.h


