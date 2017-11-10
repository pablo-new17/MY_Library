
TOPDIR = $$PROJECT/my_library/Singleton

#PABLO_ONLY = 1
defined(PABLO_ONLY, var) {
    CURRENT_DIR = $$TOPDIR
}
!defined(PABLO_ONLY, var) {
    CURRENT_DIR = $$PWD
}

INCLUDEPATH += $$CURRENT_DIR/src

SOURCES += \
        $$CURRENT_DIR/src/Singleton.cpp

HEADERS += \
        $$CURRENT_DIR/src/call_once.h \
        $$CURRENT_DIR/src/Singleton.h

