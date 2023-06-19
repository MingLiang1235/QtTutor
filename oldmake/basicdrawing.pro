HEADERS       = renderarea.h \
                window.h
SOURCES       = main.cpp \
                renderarea.cpp \
                window.cpp
RESOURCES     = basicdrawing.qrc

# install
target.path = d:/s_c/Project/Decode_graphic
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS basicdrawing.pro images
sources.path = d:/s_c/Project/Decode_graphic
INSTALLS += target sources

symbian {
    TARGET.UID3 = 0xA000A649
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
}
