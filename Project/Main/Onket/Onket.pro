QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Admin.cpp \
    Customer.cpp \
    Guest.cpp \
    Order.cpp \
    User.cpp \
    actiointype.cpp \
    actionaddgood.cpp \
    actionaddtype.cpp \
    commentlistwidget.cpp \
    commentlistwidgetitem.cpp \
    commentwidget.cpp \
    commentwidgetfield.cpp \
    commentitemstatus.cpp \
    commentitemstatusfield.cpp \
    dashboard.cpp \
    discussionitem.cpp \
    discussionlistwidget.cpp \
    filefunctions.cpp \
    good.cpp \
    goodgenralinfowidget.cpp \
    goodmainviewwidget.cpp \
    goodpreviewscrollarea.cpp \
    goodpreviewwidget.cpp \
    goodpropertywidget.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    comment.cpp \
    Commodity.cpp \
    menutype.cpp \
    question.cpp \
    questioninputwidget.cpp \
    questionviewitem.cpp \
    reply.cpp \
    loginpage.cpp \
    replyinputwidget.cpp \
    replyviewitem.cpp \
    signup.cpp \
    storage.cpp \
    type.cpp

HEADERS += \
    Admin.h \
    Commodity.h \
    Customer.h \
    Guest.h \
    Order.h \
    User.h \
    actiointype.h \
    actionaddgood.h \
    actionaddtype.h \
    commentlistwidget.h \
    commentitemstatus.h \
    commentitemstatusfield.h \
    commentlistwidgetitem.h \
    commentwidget.h \
    commentwidgetfield.h \
    dashboard.h \
    discussionitem.h \
    discussionlistwidget.h \
    filefunctions.h \
    good.h \
    goodgenralinfowidget.h \
    goodmainviewwidget.h \
    goodpreviewscrollarea.h \
    goodpreviewwidget.h \
    goodpropertywidget.h \
    item.h \
    mainwindow.h \
    comment.h \
    Commity.h \
    menutype.h \
    question.h \
    questioninputwidget.h \
    questionviewitem.h \
    reply.h \
    loginpage.h \
    replyinputwidget.h \
    replyviewitem.h \
    signup.h \
    storage.h \
    type.h

FORMS += \
    commentlistwidget.ui \
    commentlistwidgetitem.ui \
    commentwidget.ui \
    commentwidgetfield.ui \
    dashboard.ui \
    discussionlistwidget.ui \
    goodgenralinfowidget.ui \
    goodmainviewwidget.ui \
    goodpreviewscrollarea.ui \
    goodpreviewwidget.ui \
    goodpropertywidget.ui \
    mainwindow.ui \
    loginpage.ui \
    questioninputwidget.ui \
    questionviewitem.ui \
    replyinputwidget.ui \
    replyviewitem.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
