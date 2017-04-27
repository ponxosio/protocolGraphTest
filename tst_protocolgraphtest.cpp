#include <QString>
#include <QtTest>

#include <memory>

#include <protocolGraph/ProtocolGraph.h>
#include <protocolGraph/operables/mathematics/ConstantNumber.h>
#include <protocolGraph/operables/mathematics/UnaryOperation.h>
#include <protocolGraph/operables/mathematics/ArithmeticOperation.h>

#include <protocolGraph/operables/comparison/Tautology.h>
#include <protocolGraph/operables/comparison/ComparisonOperable.h>
#include <protocolGraph/operables/comparison/SimpleComparison.h>

#include <protocolGraph/operables/comparison/protocolboolf.h>
#include <protocolGraph/operables/mathematics/protocolmathf.h>

#include <utils/units.h>

#include "stringactuatorsinterface.h"

class ProtocolGraphTest : public QObject
{
    Q_OBJECT

    typedef ProtocolBoolF BF;
    typedef ProtocolMathF MF;

public:
    ProtocolGraphTest();

private:
    std::shared_ptr<ProtocolGraph> createsTurbidostatProtocol();
    std::shared_ptr<ProtocolGraph> createsIfThenElseProtocol(int switchValue);
    std::shared_ptr<ProtocolGraph> createsWhileIfProtocol();
    std::shared_ptr<ProtocolGraph> createsNestedIfsProtocol(int & endBlockId);
    std::shared_ptr<ProtocolGraph> createsSequentialIfsProtocol(int & eb1, int & eb2);
    std::shared_ptr<ProtocolGraph> createsIfsWhilesProtocol(int & eb);
    std::shared_ptr<ProtocolGraph> createIsPhysicalProtocol();
    std::shared_ptr<ProtocolGraph> createOperationsProtocol();
    std::shared_ptr<ProtocolGraph> createFinishProtocol();

    void executeProtocol(std::shared_ptr<ProtocolGraph> protocol,ActuatorsExecutionInterface* actuatorInterfaz);

private Q_SLOTS:
    void iterateOverProtocol();
    void ifThenElseProcotol_branch1();
    void ifThenElseProcotol_branch2();
    void ifThenElseProcotol_branch3();
    void whileIfProtocol();
    void nestedIfsProtocol();
    void sequentialIfsProtocol();
    void IfsWhilesProtocol();
    void isPhysical();
    void checkRandom();
    void opertationsProtocol();
    void finishProtocol();
};

ProtocolGraphTest::ProtocolGraphTest()
{
}

void ProtocolGraphTest::iterateOverProtocol()
{
    try {
        std::shared_ptr<ProtocolGraph> protocol = createsTurbidostatProtocol();
        qDebug() << protocol->toString().c_str();

        std::vector<double> measureValue = {0,100,200,300,400,500,600,700,650,600,550,600,625,600,575,600,575,600,600};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);
        executeProtocol(protocol,actuatorInterfaz);

        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput = "setTimeStep(1100ms);loadContainer(1,1000ml);loadContainer(2,0ml);loadContainer(3,0ml);measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,4ml/h);setContinuosFlow(2,3,4ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,7.33333ml/h);setContinuosFlow(2,3,7.33333ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,12.2222ml/h);setContinuosFlow(2,3,12.2222ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,18.3333ml/h);setContinuosFlow(2,3,18.3333ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,24.4444ml/h);setContinuosFlow(2,3,24.4444ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,28.5185ml/h);setContinuosFlow(2,3,28.5185ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,28.5185ml/h);setContinuosFlow(2,3,28.5185ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,23.7654ml/h);setContinuosFlow(2,3,23.7654ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,21.785ml/h);setContinuosFlow(2,3,21.785ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,21.785ml/h);setContinuosFlow(2,3,21.785ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,23.6004ml/h);setContinuosFlow(2,3,23.6004ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,23.6004ml/h);setContinuosFlow(2,3,23.6004ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,22.617ml/h);setContinuosFlow(2,3,22.617ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,22.617ml/h);setContinuosFlow(2,3,22.617ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,23.5594ml/h);setContinuosFlow(2,3,23.5594ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,23.5594ml/h);setContinuosFlow(2,3,23.5594ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,24.5411ml/h);setContinuosFlow(2,3,24.5411ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,24.5411ml/h);setContinuosFlow(2,3,24.5411ml/h);timeStep();measureOD(2,2s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,24.5411ml/h);setContinuosFlow(2,3,24.5411ml/h);timeStep();stopContinuosFlow(1,2);stopContinuosFlow(2,3);timeStep();";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::ifThenElseProcotol_branch1() {
    try {
        std::shared_ptr<ProtocolGraph> protocol = createsIfThenElseProtocol(1);
        qDebug() << protocol->toString().c_str();

        for(int ctrId : protocol->getControlOperations()) {
            std::shared_ptr<ControlNode> ctrPtr = protocol->getControlNode(ctrId);
            QVERIFY2(ctrPtr->getEndBlockId().back() == 11,
                     std::string(std::to_string(ctrId) + " end block is not 11 is" + std::to_string(ctrPtr->getEndBlockId().back())).c_str());
        }

        std::vector<double> measureValue = {};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);
        executeProtocol(protocol,actuatorInterfaz);

        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput = "setTimeStep(1100ms);setContinuosFlow(1,2,300ml/h);setContinuosFlow(2,3,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::ifThenElseProcotol_branch2() {
    try {
        std::shared_ptr<ProtocolGraph> protocol = createsIfThenElseProtocol(2);
        qDebug() << protocol->toString().c_str();

        std::vector<double> measureValue = {};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);
        executeProtocol(protocol,actuatorInterfaz);

        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput = "setTimeStep(1100ms);setContinuosFlow(2,3,300ml/h);setContinuosFlow(3,4,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::ifThenElseProcotol_branch3() {
    try {
        std::shared_ptr<ProtocolGraph> protocol = createsIfThenElseProtocol(3);
        qDebug() << protocol->toString().c_str();

        std::vector<double> measureValue = {};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);
        executeProtocol(protocol,actuatorInterfaz);

        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput = "setTimeStep(1100ms);setContinuosFlow(3,4,300ml/h);setContinuosFlow(4,5,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::whileIfProtocol() {
    try {
        std::shared_ptr<ProtocolGraph> protocol = createsWhileIfProtocol();
        qDebug() << protocol->toString().c_str();

        for(int ctrId : protocol->getControlOperations()) {
            std::shared_ptr<ControlNode> ctrPtr = protocol->getControlNode(ctrId);
            QVERIFY2((ctrPtr->getEndBlockId().back() == 9) || (ctrPtr->getEndBlockId().back() == 11),
                     std::string(std::to_string(ctrId) + " end block is not 11 or 9 is" + std::to_string(ctrPtr->getEndBlockId().back())).c_str());
        }

        std::vector<double> measureValue = {};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);
        executeProtocol(protocol,actuatorInterfaz);

        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput = "setTimeStep(1100ms);setContinuosFlow(1,2,300ml/h);timeStep();setContinuosFlow(2,3,300ml/h);timeStep();setContinuosFlow(3,4,300ml/h);timeStep();timeStep();";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::nestedIfsProtocol() {
    try {
        int endBlockId;
        std::shared_ptr<ProtocolGraph> protocol = createsNestedIfsProtocol(endBlockId);
        qDebug() << protocol->toString().c_str();

        for(int ctrId : protocol->getControlOperations()) {
            std::shared_ptr<ControlNode> ctrPtr = protocol->getControlNode(ctrId);
            QVERIFY2(ctrPtr->getEndBlockId().back() == endBlockId,
                     std::string(std::to_string(ctrId) + " end block is not " + std::to_string(endBlockId) + "is" +
                                 std::to_string(ctrPtr->getEndBlockId().back())).c_str());
        }

        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{4});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 4";
        std::string generatedOutput4 = actuatorInterfaz->getStream().str();
        std::string expectedOutput4 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,0ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput4.c_str();
        qDebug() << "expectd:" << expectedOutput4.c_str();

        QVERIFY2(expectedOutput4.compare(generatedOutput4) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;

        actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{3});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 3";
        std::string generatedOutput3 = actuatorInterfaz->getStream().str();
        std::string expectedOutput3 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput3.c_str();
        qDebug() << "expectd:" << expectedOutput3.c_str();

        QVERIFY2(expectedOutput3.compare(generatedOutput3) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;

        actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{2});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 2";
        std::string generatedOutput2 = actuatorInterfaz->getStream().str();
        std::string expectedOutput2 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(2,3,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput2.c_str();
        qDebug() << "expectd:" << expectedOutput2.c_str();

        QVERIFY2(expectedOutput2.compare(generatedOutput2) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;

        actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{-1});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = -1";
        std::string generatedOutput1 = actuatorInterfaz->getStream().str();
        std::string expectedOutput1 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(2,3,0ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput1.c_str();
        qDebug() << "expectd:" << expectedOutput1.c_str();

        QVERIFY2(expectedOutput1.compare(generatedOutput1) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::sequentialIfsProtocol() {
    try {
        int eb1,eb2;
        std::shared_ptr<ProtocolGraph> protocol = createsSequentialIfsProtocol(eb1, eb2);
        qDebug() << protocol->toString().c_str();

        for(int ctrId : protocol->getControlOperations()) {
            std::shared_ptr<ControlNode> ctrPtr = protocol->getControlNode(ctrId);
            QVERIFY2((ctrPtr->getEndBlockId().back() == eb1) || (ctrPtr->getEndBlockId().back() == eb2),
                     std::string(std::to_string(ctrId) + " end block is not 14 or 8 is" + std::to_string(ctrPtr->getEndBlockId().back())).c_str());
        }

        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{4});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 4";
        std::string generatedOutput4 = actuatorInterfaz->getStream().str();
        std::string expectedOutput4 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,300ml/h);setContinuosFlow(2,3,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput4.c_str();
        qDebug() << "expectd:" << expectedOutput4.c_str();

        QVERIFY2(expectedOutput4.compare(generatedOutput4) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;

        actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{1});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 1";
        std::string generatedOutput1 = actuatorInterfaz->getStream().str();
        std::string expectedOutput1 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,300ml/h);setContinuosFlow(2,3,400ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput1.c_str();
        qDebug() << "expectd:" << expectedOutput1.c_str();

        QVERIFY2(expectedOutput1.compare(generatedOutput1) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;

        actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{7});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 7";
        std::string generatedOutput7 = actuatorInterfaz->getStream().str();
        std::string expectedOutput7 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(1,2,400ml/h);setContinuosFlow(2,3,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput7.c_str();
        qDebug() << "expectd:" << expectedOutput7.c_str();

        QVERIFY2(expectedOutput7.compare(generatedOutput7) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::IfsWhilesProtocol() {
    try {
        int eb;
        std::shared_ptr<ProtocolGraph> protocol = createsIfsWhilesProtocol(eb);
        qDebug() << protocol->toString().c_str();

        for(int ctrId : protocol->getControlOperations()) {
            std::shared_ptr<ControlNode> ctrPtr = protocol->getControlNode(ctrId);
            QVERIFY2(ctrPtr->getEndBlockId().back() == eb,
                     std::string(std::to_string(ctrId) + " end block is not 11 is" + std::to_string(ctrPtr->getEndBlockId().back())).c_str());
        }

        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{1});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 1";
        std::string generatedOutput4 = actuatorInterfaz->getStream().str();
        std::string expectedOutput4 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(4,5,300ml/h);setContinuosFlow(4,5,300ml/h);setContinuosFlow(4,5,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput4.c_str();
        qDebug() << "expectd:" << expectedOutput4.c_str();

        QVERIFY2(expectedOutput4.compare(generatedOutput4) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;

        actuatorInterfaz = new StringActuatorsInterface(std::vector<double>{2});
        executeProtocol(protocol,actuatorInterfaz);

        qDebug() << "var = 2";
        std::string generatedOutput2 = actuatorInterfaz->getStream().str();
        std::string expectedOutput2 = "setTimeStep(1100ms);measureOD(2,4s,2Hz,650nm);getMeasureOD(2);setContinuosFlow(4,5,300ml/h);setContinuosFlow(4,5,300ml/h);setContinuosFlow(4,5,300ml/h);setContinuosFlow(4,5,300ml/h);setContinuosFlow(4,5,300ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput2.c_str();
        qDebug() << "expectd:" << expectedOutput2.c_str();

        QVERIFY2(expectedOutput2.compare(generatedOutput2) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::isPhysical() {
    try {
        std::shared_ptr<ProtocolGraph> protocol = createIsPhysicalProtocol();
        qDebug() << protocol->toString().c_str();

        QVERIFY2(protocol->getVariable("cont")->isPhysical(), "Variable cont is not physical");
        QVERIFY2(protocol->getVariable("var")->isPhysical(), "Variable var is not physical");
        QVERIFY2(!protocol->getVariable("rate")->isPhysical(), "Variable var is not physical");
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::checkRandom() {
    try {
        std::shared_ptr<MathematicOperable> random = MF::random();
        std::shared_ptr<MathematicOperable> randomInt = MF::random(0,10);

        for(int i = 0; i < 5; i++) {
            double randomValue = random->getValue();
            double randomIntValue = randomInt->getValue();

            qDebug() << randomValue;
            qDebug() << randomIntValue;

            QVERIFY2(randomValue >= 0.0 && randomValue <= 1.0,
                     std::string("random value: " + std::to_string(randomValue) + " is not between [0,1]").c_str());
            QVERIFY2(Utils::isWhole(randomIntValue),
                     std::string("random int value: " + std::to_string(randomIntValue) + " is not an integer").c_str());
            QVERIFY2(randomIntValue >= 0 && randomIntValue <= 10,
                     std::string("random int value: " + std::to_string(randomIntValue) + " is not between [0,10]").c_str());
        }
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::opertationsProtocol() {
    try {
        std::shared_ptr<ProtocolGraph> protocol = createOperationsProtocol();
        qDebug() << protocol->toString().c_str();

        std::vector<double> measureValue = {};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);
        executeProtocol(protocol,actuatorInterfaz);

        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput = "setTimeStep(1100ms);loadContainer(0,1ml);loadContainer(0,0ml);loadContainer(0,1ml);loadContainer(0,0ml);loadContainer(0,1ml);";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0,
                 "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

void ProtocolGraphTest::finishProtocol() {
    try {
        std::shared_ptr<ProtocolGraph> protocol = createFinishProtocol();
        qDebug() << protocol->toString().c_str();

        std::vector<double> measureValue = {300};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);
        executeProtocol(protocol,actuatorInterfaz);

        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput =  "setTimeStep(1100ms);measureOD(cell,3s,2Hz,650nm);timeStep();timeStep();timeStep();getMeasureOD(cell);timeStep();";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0,
                 "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;
    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

/*
 * setTimeStep(1100ms);
 * epsilon = 0.1;
 * threshold = 600;
 * rate = 2;
 *
 * loadContainer(1,100ml);
 * loadContainer(2,0ml);
 * loadContainer(3,0ml);
 *
 * while(t < 20s){
 *  od = measureOd(2);
 *  normOD = (od - threshold) / threshold;
 *  rate = rate - normOD * rate;
 *  SCF(1,2,rate ml/hr);
 *  SCF(2,3,rate ml/hr);
 *  timeStep();
 * }
 * SCF(1,2);
 * SCF(2,3);
 * timeStep();
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createsTurbidostatProtocol() {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("turbidostat");

    std::shared_ptr<MathematicOperable> mtime = graphPtr->getTimeVariable();
    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op1 = graphPtr->emplaceAssignation("epsilon", MF::getNum(0.1));//epsilon = 0.1
    int op2 = graphPtr->emplaceAssignation("threshold", MF::getNum(600)); //threshold = 600
    int op3 = graphPtr->emplaceAssignation("rate", MF::getNum(2)); //rate = 2

    graphPtr->appendOperations(op1);
    graphPtr->appendOperations(op2);
    graphPtr->appendOperations(op3);

    int op4 = graphPtr->emplaceLoadContainer("1", MF::getNum(1000), units::ml); //loadContainer(1, 1000ml)
    int op5 = graphPtr->emplaceLoadContainer("2", MF::getNum(0), units::ml); //loadContainer(2, 0ml)
    int op6 = graphPtr->emplaceLoadContainer("3", MF::getNum(0), units::ml); //loadContainer(3, 0ml)

    graphPtr->appendOperations(op4);
    graphPtr->appendOperations(op5);
    graphPtr->appendOperations(op6);

    std::shared_ptr<ComparisonOperable> comp1 = BF::less(mtime, MF::getNum(20000));
    graphPtr->startLoopBlock(comp1); //while(t < 20000)

    int op7 = graphPtr->emplaceMeasureOD("2", "od", MF::getNum(2), units::s, MF::getNum(2), units::Hz, MF::getNum(650), units::nm); //od = measureOd(2)
    graphPtr->appendOperations(op7);

    int finishOD = graphPtr->emplaceFinishOperation(op7);
    graphPtr->appendOperations(finishOD);

    std::shared_ptr<MathematicOperable> normOD = graphPtr->getVariable("normOD");
    std::shared_ptr<MathematicOperable> od = graphPtr->getVariable("od");
    std::shared_ptr<MathematicOperable> threshold = graphPtr->getVariable("threshold");

    int op8 =  graphPtr->emplaceAssignation("normOD", MF::divide(MF::minus(od, threshold), threshold)); // normOD = (od - threshold) /threshold
    graphPtr->appendOperations(op8);

    std::shared_ptr<MathematicOperable> rate = graphPtr->getVariable("rate");   
    int op12 = graphPtr->emplaceAssignation("rate", MF::minus(rate,MF::multiply(normOD, rate))); // rate = rate - normOD * rate
    graphPtr->appendOperations(op12);

    int op13 = graphPtr->emplaceSetContinuousFlow("1", "2", rate, units::ml/units::hr); // setcontinousFlow(1,2,rate)
    graphPtr->appendOperations(op13);

    int op14 = graphPtr->emplaceSetContinuousFlow("2", "3", rate, units::ml/units::hr); // setcontinousFlow(2,3,rate)
    graphPtr->appendOperations(op14);

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);
    graphPtr->endLoopBlock();

    int scf1 = graphPtr->emplaceStopContinuousFlow("1","2");
    graphPtr->appendOperations(scf1);

    int scf2 = graphPtr->emplaceStopContinuousFlow("2","3");
    graphPtr->appendOperations(scf2);

    int timeStep2 = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep2);

    return graphPtr;
}

/*
 * setTimeStep(1100ms);
 * sw = <switchValue>;
 *
 * if(sw == 1) {
 *  SCF(1,2,300 ml/hr);
 *  SCF(2,3,300 ml/hr);
 * } else if (sw == 2) {
 *  SCF(2,3,300 ml/hr);
 *  SCF(3,4,300 ml/hr);
 * } else {
 *  SCF(3,4,300 ml/hr);
 *  SCF(4,5,300 ml/hr);
 * }
 * timeStep();
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createsIfThenElseProtocol(int switchValue) {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("if_then_else");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op1 = graphPtr->emplaceAssignation("switch", MF::getNum(switchValue));//switch = switchValue
    graphPtr->appendOperations(op1);

    std::shared_ptr<ComparisonOperable> comp1 = BF::equal(graphPtr->getVariable("switch"), MF::getNum(1));
    graphPtr->startIfBlock(comp1);

    int op2 = graphPtr->emplaceSetContinuousFlow("1","2",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op2);

    int op5 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op5);

    std::shared_ptr<ComparisonOperable> comp2 = BF::equal(graphPtr->getVariable("switch"), MF::getNum(2));
    graphPtr->startElIfBlock(comp2);

    int op3 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op3);

    int op6 = graphPtr->emplaceSetContinuousFlow("3","4",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op6);

    graphPtr->startElseBlock();

    int op4 = graphPtr->emplaceSetContinuousFlow("3","4",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op4);

    int op7 = graphPtr->emplaceSetContinuousFlow("4","5",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op7);

    graphPtr->endIfBlock();

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);

    return graphPtr;
}

/*
 *
 * SetTimeStep(1100ms);
 * sw = 1;
 *
 * while(sw < 4) {
 *  if(sw == 1) {
 *      SCF(1,2,300ml/hr);
 *  } elif (sw == 2) {
 *      SCF(2,3,300ml/hr);
 *  } else {
 *      SCF(3,4,300ml/hr);
 *   }
 *  sw ++;
 *  timeStep();
 * }
 * timeStep();
 *
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createsWhileIfProtocol() {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("while_if");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op1 = graphPtr->emplaceAssignation("switch", MF::getNum(1));//switch = 1
    graphPtr->appendOperations(op1);

    std::shared_ptr<ComparisonOperable> compLoop = BF::less(graphPtr->getVariable("switch"), MF::getNum(4));
    graphPtr->startLoopBlock(compLoop);

    std::shared_ptr<ComparisonOperable> comp1 = BF::equal(graphPtr->getVariable("switch"), MF::getNum(1));
    graphPtr->startIfBlock(comp1);

    int op2 = graphPtr->emplaceSetContinuousFlow("1","2",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op2);

    std::shared_ptr<ComparisonOperable> comp2 = BF::equal(graphPtr->getVariable("switch"), MF::getNum(2));
    graphPtr->startElIfBlock(comp2);

    int op3 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op3);

    graphPtr->startElseBlock();

    int op4 = graphPtr->emplaceSetContinuousFlow("3","4",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op4);

    graphPtr->endIfBlock();

    int op5 = graphPtr->emplaceAssignation("switch", MF::add(graphPtr->getVariable("switch"),MF::getNum(1)));
    graphPtr->appendOperations(op5);

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);

    graphPtr->endLoopBlock();

    int timeStep2 = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep2);

    return graphPtr;
}

/*
 * SetTimeStep(1100);
 * var = measureOD(2);
 *
 * if(var > 2) {
 *  if(var < 4) {
 *      SCF(1,2,300ml/hr);
 *  } else {
 *      SCF(1,2,0ml/hr);
 *  }
 * } else {
 *  if(var > 0) {
 *      SCF(2,3,300ml/hr);
 *  } else {
 *      SCF(2,3,0ml/hr);
 *  }
 * }
 * timeStep();
 *
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createsNestedIfsProtocol(int & endBlockId) {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("nested_ifs");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op1 = graphPtr->emplaceMeasureOD("2","var", MF::getNum(4000), units::ms, MF::getNum(2), units::Hz, MF::getNum(650), units::nm);//var = MeasureOd()
    graphPtr->appendOperations(op1);

    int finisOp1 = graphPtr->emplaceFinishOperation(op1);
    graphPtr->appendOperations(finisOp1);

    std::shared_ptr<ComparisonOperable> comp1 = BF::big(graphPtr->getVariable("var"), MF::getNum(2)); //if(var > 2)
    graphPtr->startIfBlock(comp1);

    std::shared_ptr<ComparisonOperable> comp2 = BF::less(graphPtr->getVariable("var"), MF::getNum(4)); //if(var < 4)
    graphPtr->startIfBlock(comp2);

    int op3 = graphPtr->emplaceSetContinuousFlow("1","2",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op3);

    graphPtr->startElseBlock();

    int op4 = graphPtr->emplaceSetContinuousFlow("1","2",MF::getNum(0), units::ml / units::hr);
    graphPtr->appendOperations(op4);

    graphPtr->endIfBlock();

    graphPtr->startElseBlock();

    std::shared_ptr<ComparisonOperable> comp3 = BF::big(graphPtr->getVariable("var"), MF::getNum(0)); //if(var > 0)
    graphPtr->startIfBlock(comp3);

    int op5 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op5);

    graphPtr->startElseBlock();

    int op6 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(0), units::ml / units::hr);
    graphPtr->appendOperations(op6);

    graphPtr->endIfBlock();
    graphPtr->endIfBlock();

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);

    endBlockId = timeStep;

    return graphPtr;
}

/*
 *
 * setTimeStep(1100);
 * var = measureOD(2);
 *
 * if(var < 5) {
 *  SCF(1,2,300ml/hr);
 * } elif (var > 8) {
 *  SCF(1,2,0ml/hr);
 * } else {
 *  SCF(1,2,400ml/hr);
 * }
 *
 * if( var > 2) {
 *  SCF(2,3,300ml/hr);
 * } elif (var < 0) {
 *  SCF(2,3,0ml/hr);
 * } else {
 *  SCF(2,3,400ml/hr);
 * }
 * timeStep()
 *
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createsSequentialIfsProtocol(int & eb1, int & eb2) {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("sequential_ifs");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op1 = graphPtr->emplaceMeasureOD("2","var", MF::getNum(4000), units::ms, MF::getNum(2), units::Hz, MF::getNum(650), units::nm);//var = MeasureOd()
    graphPtr->appendOperations(op1);

    int finishOp1 = graphPtr->emplaceFinishOperation(op1);
    graphPtr->appendOperations(finishOp1);

    std::shared_ptr<ComparisonOperable> comp1 = BF::less(graphPtr->getVariable("var"), MF::getNum(5)); //if(var < 5)
    graphPtr->startIfBlock(comp1);

    int op3 = graphPtr->emplaceSetContinuousFlow("1","2",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op3);

    std::shared_ptr<ComparisonOperable> comp2 = BF::big(graphPtr->getVariable("var"), MF::getNum(8)); //if(var > 8)
    graphPtr->startElIfBlock(comp2);

    int op4 = graphPtr->emplaceSetContinuousFlow("1","2",MF::getNum(0), units::ml / units::hr);
    graphPtr->appendOperations(op4);

    graphPtr->startElseBlock();

    int op7 = graphPtr->emplaceSetContinuousFlow("1","2",MF::getNum(400), units::ml / units::hr);
    graphPtr->appendOperations(op7);

    graphPtr->endIfBlock();

    std::unordered_set<int> ctrNodesB(graphPtr->getControlOperations());

    std::shared_ptr<ComparisonOperable> comp3 = BF::big(graphPtr->getVariable("var"), MF::getNum(2)); //if(var > 2)
    graphPtr->startIfBlock(comp3);

    std::unordered_set<int> ctrNodesA(graphPtr->getControlOperations());

    for(int a : ctrNodesA) {
        if (ctrNodesB.find(a) == ctrNodesB.end()) {
            eb1 = a;
        }
    }

    int op5 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(op5);

    std::shared_ptr<ComparisonOperable> comp4 = BF::less(graphPtr->getVariable("var"), MF::getNum(0)); //if(var < 0)
    graphPtr->startElIfBlock(comp4);

    int op6 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(0), units::ml / units::hr);
    graphPtr->appendOperations(op6);

    graphPtr->startElseBlock();

    int op8 = graphPtr->emplaceSetContinuousFlow("2","3",MF::getNum(400), units::ml / units::hr);
    graphPtr->appendOperations(op8);

    graphPtr->endIfBlock();

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);

    eb2 = timeStep;

    return graphPtr;
}

/*
 * setTimeStep(1100ms);
 * var = measureOD(2);
 * cont = 0;
 *
 * if(var == 1) {
 *  while(cont < 3) {
 *      SCF(4,5,300ml/hr);
 *      cont++;
 *  }
 * } else {
 *  while(cont < 5) {
 *      SCF(4,5,300ml/hr);
 *      cont++;
 *  }
 * }
 * timeStep();
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createsIfsWhilesProtocol(int & eb) {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("ifs_whiles");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op1 = graphPtr->emplaceMeasureOD("2","var", MF::getNum(4000), units::ms, MF::getNum(2), units::Hz, MF::getNum(650), units::nm);//var = MeasureOd()
    graphPtr->appendOperations(op1);

    int finishOp1 = graphPtr->emplaceFinishOperation(op1);
    graphPtr->appendOperations(finishOp1);

    int op2 = graphPtr->emplaceAssignation("cont", MF::getNum(0));
    graphPtr->appendOperations(op2);

    std::shared_ptr<ComparisonOperable> comp1 = BF::equal(graphPtr->getVariable("var"), MF::getNum(1)); //if(var = 1)
    graphPtr->startIfBlock(comp1);

    std::shared_ptr<ComparisonOperable> compLoop = BF::less(graphPtr->getVariable("cont"), MF::getNum(3)); //while(cont < 3)
    graphPtr->startLoopBlock(compLoop);

    int opCont = graphPtr->emplaceAssignation("cont", MF::add(graphPtr->getVariable("cont"), MF::getNum(1)));//cont = cont + 1
    graphPtr->appendOperations(opCont);

    int opCont2 = graphPtr->emplaceSetContinuousFlow("4","5", MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(opCont2);

    graphPtr->endLoopBlock();

    graphPtr->startElseBlock();

    std::shared_ptr<ComparisonOperable> compLoop2 = BF::less(graphPtr->getVariable("cont"), MF::getNum(5)); //while(cont < 5)
    graphPtr->startLoopBlock(compLoop2);

    int opCont22 = graphPtr->emplaceAssignation("cont", MF::add(graphPtr->getVariable("cont"), MF::getNum(1)));//cont = cont + 1
    graphPtr->appendOperations(opCont22);

    int opCont21 = graphPtr->emplaceSetContinuousFlow("4","5", MF::getNum(300), units::ml / units::hr);
    graphPtr->appendOperations(opCont21);

    graphPtr->endLoopBlock();

    graphPtr->endIfBlock();

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);

    eb = timeStep;

    return graphPtr;
}

/*
 * SetTimeStep(1100ms);
 * cont = 0;
 * rate = 300;
 *
 * loop(cont == 0) {
 *  var = measureOD(2,4Hz,650nm);
 *  if(var < 50) {
 *      cont = 1;
 *  }
 *  SCF(1,2, rate, ml/hr);
 *  timeStep();
 * }
 *
 *
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createIsPhysicalProtocol() {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("isPhysical");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op2 = graphPtr->emplaceAssignation("cont", MF::getNum(0));
    graphPtr->appendOperations(op2);

    int op3 = graphPtr->emplaceAssignation("rate", MF::getNum(300));
    graphPtr->appendOperations(op3);

    std::shared_ptr<ComparisonOperable> compLoop = BF::equal(graphPtr->getVariable("cont"), MF::getNum(0)); //while(cont == 0)
    graphPtr->startLoopBlock(compLoop);

    int op1 = graphPtr->emplaceMeasureOD("2","var", MF::getNum(4000), units::ms, MF::getNum(2), units::Hz, MF::getNum(650), units::nm);//var = MeasureOd()
    graphPtr->appendOperations(op1);

    std::shared_ptr<ComparisonOperable> comp1 = BF::less(graphPtr->getVariable("var"), MF::getNum(50)); //if(var < 50)
    graphPtr->startIfBlock(comp1);

    int opCont = graphPtr->emplaceAssignation("cont", MF::getNum(1));//cont = 1
    graphPtr->appendOperations(opCont);

    graphPtr->endIfBlock();

    int opCont2 = graphPtr->emplaceSetContinuousFlow("1","2", graphPtr->getVariable("rate"), units::ml / units::hr);
    graphPtr->appendOperations(opCont2);

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);

    graphPtr->endLoopBlock();

    return graphPtr;
}


/*
 * even = isEven(2) ? 1 : 0;
 * whole = isWhole(2.1) ? 1 : 0;
 * prime2 = isPrime(2) ? 1 : 0;
 * prime770 = isPrime(770) ? 1 : 0;
 * prime503 = isPrime(503) ? 1 : 0;
 *
 * LC(0,even ml);
 * LC(0,whole ml);
 * LC(0,prime2 ml);
 * LC(0,prime770 ml);
 * LC(0,prime503 ml);
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createOperationsProtocol() {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("operations");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int evenOp = graphPtr->emplaceAssignation("even", MF::test(BF::isEven(MF::getNum(2.0)), MF::getNum(1.0), MF::getNum(0.0)));
    graphPtr->appendOperations(evenOp);

    int wholeOP = graphPtr->emplaceAssignation("whole", MF::test(BF::isWhole(MF::getNum(2.1)), MF::getNum(1.0), MF::getNum(0.0)));
    graphPtr->appendOperations(wholeOP);

    int primeOP2 = graphPtr->emplaceAssignation("prime2", MF::test(BF::isPrime(MF::getNum(2.0)), MF::getNum(1.0), MF::getNum(0.0)));
    graphPtr->appendOperations(primeOP2);

    int primeOP770 = graphPtr->emplaceAssignation("prime770", MF::test(BF::isPrime(MF::getNum(770.0)), MF::getNum(1.0), MF::getNum(0.0)));
    graphPtr->appendOperations(primeOP770);

    int primeOP503 = graphPtr->emplaceAssignation("prime503", MF::test(BF::isPrime(MF::getNum(503.0)), MF::getNum(1.0), MF::getNum(0.0)));
    graphPtr->appendOperations(primeOP503);

    int LC1 = graphPtr->emplaceLoadContainer("0", graphPtr->getVariable("even"), units::ml);
    graphPtr->appendOperations(LC1);

    int LC2 = graphPtr->emplaceLoadContainer("0", graphPtr->getVariable("whole"), units::ml);
    graphPtr->appendOperations(LC2);

    int LC3 = graphPtr->emplaceLoadContainer("0", graphPtr->getVariable("prime2"), units::ml);
    graphPtr->appendOperations(LC3);

    int LC4 = graphPtr->emplaceLoadContainer("0", graphPtr->getVariable("prime770"), units::ml);
    graphPtr->appendOperations(LC4);

    int LC5 = graphPtr->emplaceLoadContainer("0", graphPtr->getVariable("prime503"), units::ml);
    graphPtr->appendOperations(LC5);

    return graphPtr;
}

/*
 * setTimeStep(1100ms);
 * executing = 0;
 *
 * while(t <= 4s) {
 *  if (t >= 0s && t <= 3s) {
 *      if (!executing) {
 *          startMeasureOd(cell,od,3s,2Hz,650nm);
 *          executing = 1;
 *      }
 *  } else if (executing) {
 *      od = getMeasureOd(cell);
 *      executing = 0;
 *  }
 *  timeStep();
 * }
 *
 */
std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createFinishProtocol() {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("operations");

    std::shared_ptr<VariableEntry> vTime = graphPtr->getTimeVariable();
    std::shared_ptr<VariableEntry> executingFlag = graphPtr->getVariable("executing");

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int initFlag = graphPtr->emplaceAssignation("executing", MF::getNum(0));
    graphPtr->appendOperations(initFlag);

    graphPtr->startLoopBlock(BF::lessEq(vTime, MF::getNum(4000)));

    std::shared_ptr<ComparisonOperable> ifCmp = BF::makeAnd(BF::bigEq(vTime,MF::getNum(0)), BF::lessEq(vTime, MF::getNum(3000)));
    graphPtr->startIfBlock(ifCmp);

    graphPtr->startIfBlock(BF::equal(executingFlag, MF::getNum(0)));

    int measureOd = graphPtr->emplaceMeasureOD("cell", "od", MF::getNum(3), units::s, MF::getNum(2), units::Hz, MF::getNum(650), units::nm);
    graphPtr->appendOperations(measureOd);

    int setFlag = graphPtr->emplaceAssignation("executing", MF::getNum(1));
    graphPtr->appendOperations(setFlag);

    graphPtr->endIfBlock();

    graphPtr->startElIfBlock(BF::equal(executingFlag, MF::getNum(1)));

    int finishOp = graphPtr->emplaceFinishOperation(measureOd);
    graphPtr->appendOperations(finishOp);

    int unsetFlag = graphPtr->emplaceAssignation("executing", MF::getNum(0));
    graphPtr->appendOperations(unsetFlag);

    graphPtr->endIfBlock();

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->appendOperations(timeStep);

    graphPtr->endLoopBlock();

    return graphPtr;
}

void ProtocolGraphTest::executeProtocol(std::shared_ptr<ProtocolGraph> protocol,ActuatorsExecutionInterface* actuatorInterfaz) {
    std::vector<int> nodes2process = {protocol->getStart()->getContainerId()};
    while(!nodes2process.empty()) {
        int nextId = nodes2process.back();
        nodes2process.pop_back();

        if (protocol->isCpuOperation(nextId)) {
            protocol->getCpuOperation(nextId)->execute();
        } else if (protocol->isActuatorOperation(nextId)) {
            protocol->getActuatorOperation(nextId)->execute(actuatorInterfaz);
        }

        ProtocolGraph::ProtocolEdgeVectorPtr leaving = protocol->getProjectingEdges(nextId);
        for(const ProtocolGraph::ProtocolEdgePtr & edge: *leaving.get()) {
            if (edge->conditionMet()) {
                nodes2process.push_back(edge->getIdTarget());
            }
        }
    }
}


QTEST_APPLESS_MAIN(ProtocolGraphTest)

#include "tst_protocolgraphtest.moc"
