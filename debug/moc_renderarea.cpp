/****************************************************************************
** Meta object code from reading C++ file 'renderarea.h'
**
** Created: Tue May 16 23:24:09 2023
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../renderarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RenderArea[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x0a,
      38,   34,   11,   11, 0x0a,
      57,   51,   11,   11, 0x0a,
      86,   74,   11,   11, 0x0a,
     119,  107,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RenderArea[] = {
    "RenderArea\0\0shape\0setShape(Shape)\0pen\0"
    "setPen(QPen)\0brush\0setBrush(QBrush)\0"
    "antialiased\0setAntialiased(bool)\0"
    "transformed\0setTransformed(bool)\0"
};

const QMetaObject RenderArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RenderArea,
      qt_meta_data_RenderArea, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RenderArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RenderArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RenderArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RenderArea))
        return static_cast<void*>(const_cast< RenderArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int RenderArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setShape((*reinterpret_cast< Shape(*)>(_a[1]))); break;
        case 1: setPen((*reinterpret_cast< const QPen(*)>(_a[1]))); break;
        case 2: setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 3: setAntialiased((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: setTransformed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_CharArray[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CharArray[] = {
    "CharArray\0"
};

const QMetaObject CharArray::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CharArray,
      qt_meta_data_CharArray, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CharArray::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CharArray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CharArray::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CharArray))
        return static_cast<void*>(const_cast< CharArray*>(this));
    return QObject::qt_metacast(_clname);
}

int CharArray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ColorMatrix[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ColorMatrix[] = {
    "ColorMatrix\0"
};

const QMetaObject ColorMatrix::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ColorMatrix,
      qt_meta_data_ColorMatrix, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorMatrix::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorMatrix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorMatrix::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorMatrix))
        return static_cast<void*>(const_cast< ColorMatrix*>(this));
    return QObject::qt_metacast(_clname);
}

int ColorMatrix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
