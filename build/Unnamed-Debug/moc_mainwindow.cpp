/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClickableVlcWidgetVideo_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClickableVlcWidgetVideo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClickableVlcWidgetVideo_t qt_meta_stringdata_ClickableVlcWidgetVideo = {
    {
QT_MOC_LITERAL(0, 0, 23), // "ClickableVlcWidgetVideo"
QT_MOC_LITERAL(1, 24, 7), // "clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "index"
QT_MOC_LITERAL(4, 39, 13), // "doubleClicked"
QT_MOC_LITERAL(5, 53, 12), // "rightClicked"
QT_MOC_LITERAL(6, 66, 3) // "pos"

    },
    "ClickableVlcWidgetVideo\0clicked\0\0index\0"
    "doubleClicked\0rightClicked\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClickableVlcWidgetVideo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       5,    2,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    6,

       0        // eod
};

void ClickableVlcWidgetVideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClickableVlcWidgetVideo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->doubleClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->rightClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClickableVlcWidgetVideo::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClickableVlcWidgetVideo::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClickableVlcWidgetVideo::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClickableVlcWidgetVideo::doubleClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClickableVlcWidgetVideo::*)(int , const QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClickableVlcWidgetVideo::rightClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClickableVlcWidgetVideo::staticMetaObject = { {
    &VlcWidgetVideo::staticMetaObject,
    qt_meta_stringdata_ClickableVlcWidgetVideo.data,
    qt_meta_data_ClickableVlcWidgetVideo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClickableVlcWidgetVideo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClickableVlcWidgetVideo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClickableVlcWidgetVideo.stringdata0))
        return static_cast<void*>(this);
    return VlcWidgetVideo::qt_metacast(_clname);
}

int ClickableVlcWidgetVideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VlcWidgetVideo::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ClickableVlcWidgetVideo::clicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClickableVlcWidgetVideo::doubleClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClickableVlcWidgetVideo::rightClicked(int _t1, const QPoint & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "signal_load_vlc"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "showMainWindow"
QT_MOC_LITERAL(4, 43, 16), // "handleViewChange"
QT_MOC_LITERAL(5, 60, 17), // "calculateCellSize"
QT_MOC_LITERAL(6, 78, 10), // "viewOption"
QT_MOC_LITERAL(7, 89, 4), // "int&"
QT_MOC_LITERAL(8, 94, 9), // "cellWidth"
QT_MOC_LITERAL(9, 104, 10), // "cellHeight"
QT_MOC_LITERAL(10, 115, 17), // "handleDoubleClick"
QT_MOC_LITERAL(11, 133, 5), // "index"
QT_MOC_LITERAL(12, 139, 15), // "showContextMenu"
QT_MOC_LITERAL(13, 155, 3), // "pos"
QT_MOC_LITERAL(14, 159, 15), // "handleCloseView"
QT_MOC_LITERAL(15, 175, 19), // "closeFullscreenView"
QT_MOC_LITERAL(16, 195, 22), // "resetErrorMessageLabel"
QT_MOC_LITERAL(17, 218, 30), // "updateGridLayoutForCurrentView"
QT_MOC_LITERAL(18, 249, 22), // "getCurrentViewRowsCols"
QT_MOC_LITERAL(19, 272, 4), // "rows"
QT_MOC_LITERAL(20, 277, 4), // "cols"
QT_MOC_LITERAL(21, 282, 12), // "takeSnapshot"
QT_MOC_LITERAL(22, 295, 13), // "createSidebar"
QT_MOC_LITERAL(23, 309, 16) // "slot_loading_vlc"

    },
    "MainWindow\0signal_load_vlc\0\0showMainWindow\0"
    "handleViewChange\0calculateCellSize\0"
    "viewOption\0int&\0cellWidth\0cellHeight\0"
    "handleDoubleClick\0index\0showContextMenu\0"
    "pos\0handleCloseView\0closeFullscreenView\0"
    "resetErrorMessageLabel\0"
    "updateGridLayoutForCurrentView\0"
    "getCurrentViewRowsCols\0rows\0cols\0"
    "takeSnapshot\0createSidebar\0slot_loading_vlc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    3,   87,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      12,    2,   97,    2, 0x08 /* Private */,
      14,    1,  102,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    1,  106,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    2,  110,    2, 0x08 /* Private */,
      21,    0,  115,    2, 0x08 /* Private */,
      22,    0,  116,    2, 0x0a /* Public */,
      23,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,   11,   13,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_load_vlc(); break;
        case 1: _t->showMainWindow(); break;
        case 2: _t->handleViewChange(); break;
        case 3: _t->calculateCellSize((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->handleDoubleClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->showContextMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 6: _t->handleCloseView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->closeFullscreenView(); break;
        case 8: _t->resetErrorMessageLabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateGridLayoutForCurrentView(); break;
        case 10: _t->getCurrentViewRowsCols((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->takeSnapshot(); break;
        case 12: _t->createSidebar(); break;
        case 13: _t->slot_loading_vlc(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signal_load_vlc)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signal_load_vlc()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
