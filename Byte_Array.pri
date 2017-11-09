
TOPDIR = $$PROJECT/my_library/Byte_Array

#PABLO_ONLY = 1
defined(PABLO_ONLY, var) {
    CURRENT_DIR = $$TOPDIR
}
!defined(PABLO_ONLY, var) {
    CURRENT_DIR = $$PWD
}

INCLUDEPATH += $$CURRENT_DIR/src

SOURCES += \
    $$CURRENT_DIR/src/Byte_Array_Read.cpp \
    $$CURRENT_DIR/src/Byte_Array_Write.cpp

HEADERS += \
    $$CURRENT_DIR/src/Byte_Array_Read.h \
    $$CURRENT_DIR/src/Byte_Array_Write.h

