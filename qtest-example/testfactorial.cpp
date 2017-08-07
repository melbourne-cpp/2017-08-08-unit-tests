#include <QTest>

#include "testfactorial.h"
#include "../factorial.h"

Q_DECLARE_METATYPE(long double)

void TestFactorial::iterative_data()
{
    QTest::addColumn<long>("n");
    QTest::addColumn<long>("expected");

    QTest::newRow("0") << 0L << 1L;
    QTest::newRow("1") << 1L << 1L;
    QTest::newRow("2") << 2L << 2L;
    QTest::newRow("3") << 3L << 6L;
    QTest::newRow("4") << 4L << 24L;
    QTest::newRow("5") << 5L << 120L;
    QTest::newRow("6") << 6L << 720L;
    QTest::newRow("7") << 7L << 5040L;
    QTest::newRow("8") << 8L << 40320L;
    QTest::newRow("9") << 9L << 362880L;
    QTest::newRow("10") << 10L << 3628800L;
    QTest::newRow("11") << 11L << 39916800L;
    QTest::newRow("12") << 12L << 479001600L;
    QTest::newRow("13") << 13L << 6227020800L;
    QTest::newRow("14") << 14L << 87178291200L;
    QTest::newRow("15") << 15L << 1307674368000L;
    QTest::newRow("16") << 16L << 20922789888000L;
    QTest::newRow("17") << 17L << 355687428096000L;
    QTest::newRow("18") << 18L << 6402373705728000L;
    QTest::newRow("19") << 19L << 121645100408832000L;
    QTest::newRow("20") << 20L << 2432902008176640000L;
}

#include <limits>
#include <iostream>
#include <iomanip>

void TestFactorial::iterative()
{
    QFETCH(long, n);
    QFETCH(long, expected);

    QCOMPARE(factorial_iterative(n), expected);

//    QBENCHMARK{
//        factorial_iterative(n);
//    }
}

void TestFactorial::recursive_data()
{
    iterative_data();
}

void TestFactorial::recursive()
{
    QFETCH(long, n);
    QFETCH(long, expected);

    QCOMPARE(factorial_recursive(n), expected);

//    QBENCHMARK{
//        factorial_recursive(n);
//    }
}

QTEST_MAIN(TestFactorial)
