#include <QObject>

class TestFactorial : public QObject {
    Q_OBJECT

private slots:
    void iterative_data();
    void iterative();

    void recursive_data();
    void recursive();

};
