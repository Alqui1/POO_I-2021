/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../POO_Tangram/main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PushButton_Menu_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PushButton_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PushButton_Menu_t qt_meta_stringdata_PushButton_Menu = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PushButton_Menu"
QT_MOC_LITERAL(1, 16, 9), // "file_name"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "PushButton_Menu\0file_name\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PushButton_Menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void PushButton_Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PushButton_Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->file_name((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PushButton_Menu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PushButton_Menu::file_name)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PushButton_Menu::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_PushButton_Menu.data,
    qt_meta_data_PushButton_Menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PushButton_Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PushButton_Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PushButton_Menu.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int PushButton_Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void PushButton_Menu::file_name(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Main_Window_t {
    QByteArrayData data[13];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_Window_t qt_meta_stringdata_Main_Window = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Main_Window"
QT_MOC_LITERAL(1, 12, 13), // "Show_MainPage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "Show_Levels"
QT_MOC_LITERAL(4, 39, 11), // "level_index"
QT_MOC_LITERAL(5, 51, 19), // "Show_Selection_Menu"
QT_MOC_LITERAL(6, 71, 19), // "Show_SandboxDefault"
QT_MOC_LITERAL(7, 91, 14), // "Show_UserLevel"
QT_MOC_LITERAL(8, 106, 7), // "saveFig"
QT_MOC_LITERAL(9, 114, 9), // "openLevel"
QT_MOC_LITERAL(10, 124, 12), // "get_NameFile"
QT_MOC_LITERAL(11, 137, 6), // "string"
QT_MOC_LITERAL(12, 144, 29) // "getFigures_FromDefaultSandbox"

    },
    "Main_Window\0Show_MainPage\0\0Show_Levels\0"
    "level_index\0Show_Selection_Menu\0"
    "Show_SandboxDefault\0Show_UserLevel\0"
    "saveFig\0openLevel\0get_NameFile\0string\0"
    "getFigures_FromDefaultSandbox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    1,   68,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 11, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void Main_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Main_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Show_MainPage(); break;
        case 1: _t->Show_Levels((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Show_Selection_Menu(); break;
        case 3: _t->Show_SandboxDefault(); break;
        case 4: _t->Show_UserLevel(); break;
        case 5: _t->saveFig(); break;
        case 6: _t->openLevel(); break;
        case 7: { string _r = _t->get_NameFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->getFigures_FromDefaultSandbox(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Main_Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Main_Window.data,
    qt_meta_data_Main_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Main_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Main_Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Main_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
