#ifndef TEST_H
#define TEST_H
#include <QQmlContext>
#include <QObject>
#include <QQuickView>
class Base: public QObject{
    Q_OBJECT
public:
    Base(QQuickView* view , QObject * parent = nullptr): QObject(parent){
        m_context = view->rootContext();
        m_context->setContextProperty("view", this);
    }
private:
    QQmlContext* m_context;

};

class Derived: public Base{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setvalue NOTIFY valueChanged)
public:
    Derived(QQuickView * view): Base(view){}

    int value() const;
public slots:
    void setvalue(int newValue){
        if (m_value == newValue)
            return;
        m_value = newValue;
        emit valueChanged();
    }
signals:
    void valueChanged();
private:
    int m_value = 12;
};

inline int Derived::value() const
{
    return m_value;
}


#endif // TEST_H
