/****************************************************************************
** Meta object code from reading C++ file 'signup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "signup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_signup_t {
    QByteArrayData data[14];
    char stringdata0[412];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_signup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_signup_t qt_meta_stringdata_signup = {
    {
QT_MOC_LITERAL(0, 0, 6), // "signup"
QT_MOC_LITERAL(1, 7, 44), // "on_repeat_password_line_edit_..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 37), // "on_username_line_edit_editing..."
QT_MOC_LITERAL(4, 91, 37), // "on_password_line_edit_editing..."
QT_MOC_LITERAL(5, 129, 29), // "on_show_password_stateChanged"
QT_MOC_LITERAL(6, 159, 15), // "on_back_clicked"
QT_MOC_LITERAL(7, 175, 24), // "on_signup_button_clicked"
QT_MOC_LITERAL(8, 200, 38), // "on_firstname_line_edit_editin..."
QT_MOC_LITERAL(9, 239, 37), // "on_lastname_line_edit_editing..."
QT_MOC_LITERAL(10, 277, 41), // "on_phone_number_line_edit_edi..."
QT_MOC_LITERAL(11, 319, 36), // "on_address_line_edit_editingF..."
QT_MOC_LITERAL(12, 356, 29), // "on_add_address_button_clicked"
QT_MOC_LITERAL(13, 386, 25) // "on_create_account_clicked"

    },
    "signup\0on_repeat_password_line_edit_editingFinished\0"
    "\0on_username_line_edit_editingFinished\0"
    "on_password_line_edit_editingFinished\0"
    "on_show_password_stateChanged\0"
    "on_back_clicked\0on_signup_button_clicked\0"
    "on_firstname_line_edit_editingFinished\0"
    "on_lastname_line_edit_editingFinished\0"
    "on_phone_number_line_edit_editingFinished\0"
    "on_address_line_edit_editingFinished\0"
    "on_add_address_button_clicked\0"
    "on_create_account_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_signup[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void signup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<signup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_repeat_password_line_edit_editingFinished(); break;
        case 1: _t->on_username_line_edit_editingFinished(); break;
        case 2: _t->on_password_line_edit_editingFinished(); break;
        case 3: _t->on_show_password_stateChanged(); break;
        case 4: _t->on_back_clicked(); break;
        case 5: _t->on_signup_button_clicked(); break;
        case 6: _t->on_firstname_line_edit_editingFinished(); break;
        case 7: _t->on_lastname_line_edit_editingFinished(); break;
        case 8: _t->on_phone_number_line_edit_editingFinished(); break;
        case 9: _t->on_address_line_edit_editingFinished(); break;
        case 10: _t->on_add_address_button_clicked(); break;
        case 11: _t->on_create_account_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject signup::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_signup.data,
    qt_meta_data_signup,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *signup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *signup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_signup.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int signup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
