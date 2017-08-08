#include <QTest>

#include "testfactorial.h"
#include "../factorial.h"

void TestFactorial::iterative_data()
{
    QTest::addColumn<uint64_t>("n");
    QTest::addColumn<uint64_t>("expected");

    QTest::newRow("0") << 0UL << 1UL;
    QTest::newRow("1") << 1UL << 1UL;
    QTest::newRow("2") << 2UL << 2UL;
    QTest::newRow("3") << 3UL << 6UL;
    QTest::newRow("4") << 4UL << 24UL;
    QTest::newRow("5") << 5UL << 120UL;
    QTest::newRow("6") << 6UL << 720UL;
    QTest::newRow("7") << 7UL << 5040UL;
    QTest::newRow("8") << 8UL << 40320UL;
    QTest::newRow("9") << 9UL << 362880UL;
    QTest::newRow("10") << 10UL << 3628800UL;
    QTest::newRow("11") << 11UL << 39916800UL;
    QTest::newRow("12") << 12UL << 479001600UL;
    QTest::newRow("13") << 13UL << 6227020800UL;
    QTest::newRow("14") << 14UL << 87178291200UL;
    QTest::newRow("15") << 15UL << 1307674368000UL;
    QTest::newRow("16") << 16UL << 20922789888000UL;
    QTest::newRow("17") << 17UL << 355687428096000UL;
    QTest::newRow("18") << 18UL << 6402373705728000UL;
    QTest::newRow("19") << 19UL << 121645100408832000UL;
    QTest::newRow("20") << 20UL << 2432902008176640000UL;
}

void TestFactorial::iterative()
{
    QFETCH(uint64_t, n);
    QFETCH(uint64_t, expected);

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
    QFETCH(uint64_t, n);
    QFETCH(uint64_t, expected);

    QCOMPARE(factorial_recursive(n), expected);

//    QBENCHMARK{
//        factorial_recursive(n);
//    }
}

QTEST_MAIN(TestFactorial)
