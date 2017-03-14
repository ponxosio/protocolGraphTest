#include <QString>
#include <QtTest>

class ProtocolGraphTest : public QObject
{
    Q_OBJECT

public:
    ProtocolGraphTest();

private Q_SLOTS:
    void iterateOverProtocol();
};

ProtocolGraphTest::ProtocolGraphTest()
{
}

void ProtocolGraphTest::iterateOverProtocol()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ProtocolGraphTest)

#include "tst_protocolgraphtest.moc"
