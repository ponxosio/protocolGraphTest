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
    std::shared_ptr<ProtocolGraph> createsGraph();

private Q_SLOTS:
    void iterateOverProtocol();
};

ProtocolGraphTest::ProtocolGraphTest()
{
}

void ProtocolGraphTest::iterateOverProtocol()
{
    try {
        std::shared_ptr<ProtocolGraph> protocol = createsGraph();
        qDebug() << protocol->toString().c_str();

        std::vector<double> measureValue = {0,100,200,300,400,500,600,700,650,600,550,600,625,600,575,600,575,600,600};
        StringActuatorsInterface* actuatorInterfaz = new StringActuatorsInterface(measureValue);

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
        std::string generatedOutput = actuatorInterfaz->getStream().str();
        std::string expectedOutput = "setTimeStep(1100ms);loadContainer(1,1);loadContainer(2,0);loadContainer(3,0);measureOD(2,2,2,650);setContinuosFlow(1,2,4ml/h);setContinuosFlow(2,3,4ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,7.33333ml/h);setContinuosFlow(2,3,7.33333ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,12.2222ml/h);setContinuosFlow(2,3,12.2222ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,18.3333ml/h);setContinuosFlow(2,3,18.3333ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,24.4444ml/h);setContinuosFlow(2,3,24.4444ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,28.5185ml/h);setContinuosFlow(2,3,28.5185ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,28.5185ml/h);setContinuosFlow(2,3,28.5185ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,23.7654ml/h);setContinuosFlow(2,3,23.7654ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,21.785ml/h);setContinuosFlow(2,3,21.785ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,21.785ml/h);setContinuosFlow(2,3,21.785ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,23.6004ml/h);setContinuosFlow(2,3,23.6004ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,23.6004ml/h);setContinuosFlow(2,3,23.6004ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,22.617ml/h);setContinuosFlow(2,3,22.617ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,22.617ml/h);setContinuosFlow(2,3,22.617ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,23.5594ml/h);setContinuosFlow(2,3,23.5594ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,23.5594ml/h);setContinuosFlow(2,3,23.5594ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,24.5411ml/h);setContinuosFlow(2,3,24.5411ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,24.5411ml/h);setContinuosFlow(2,3,24.5411ml/h);timeStep();measureOD(2,2,2,650);setContinuosFlow(1,2,24.5411ml/h);setContinuosFlow(2,3,24.5411ml/h);timeStep();";
        qDebug() << "generated: " << generatedOutput.c_str();
        qDebug() << "expectd:" << expectedOutput.c_str();

        QVERIFY2(expectedOutput.compare(generatedOutput) == 0, "expected and generated outputs are not the same, check debug printed values for more info");
        delete actuatorInterfaz;

    } catch (std::exception & e) {
        QFAIL(std::string("Exception occired, message:" + std::string(e.what())).c_str());
    }
}

std::shared_ptr<ProtocolGraph> ProtocolGraphTest::createsGraph() {
    std::shared_ptr<ProtocolGraph> graphPtr = std::make_shared<ProtocolGraph>("turbidostat");

    std::shared_ptr<ComparisonOperable> tautology = BF::tautology();
    std::shared_ptr<MathematicOperable> mtime = graphPtr->getTimeVariable();

    int setTimeS = graphPtr->emplaceSetTimeStep(MF::getNum(1100), units::ms);
    graphPtr->setStartNode(setTimeS);

    int op1 = graphPtr->emplaceAssignation("epsilon", MF::getNum(0.1));//epsilon = 0.1
    int op2 = graphPtr->emplaceAssignation("threshold", MF::getNum(600)); //threshold = 600
    int op3 = graphPtr->emplaceAssignation("rate", MF::getNum(2)); //rate = 2

    graphPtr->connectOperation(setTimeS, op1, tautology);
    graphPtr->connectOperation(op1, op2, tautology);
    graphPtr->connectOperation(op2, op3, tautology);

    int op4 = graphPtr->emplaceLoadContainer(1, MF::getNum(1000), units::ml); //loadContainer(1, 1000ml)
    int op5 = graphPtr->emplaceLoadContainer(2, MF::getNum(0), units::ml); //loadContainer(2, 0ml)
    int op6 = graphPtr->emplaceLoadContainer(3, MF::getNum(0), units::ml); //loadContainer(3, 0ml)

    graphPtr->connectOperation(op3, op4, tautology);
    graphPtr->connectOperation(op4, op5, tautology);
    graphPtr->connectOperation(op5, op6, tautology);

    std::shared_ptr<ComparisonOperable> comp1 = BF::less(mtime, MF::getNum(20000));
    int loop1 = graphPtr->emplaceLoop(comp1); //while (t < 20s)
    graphPtr->connectOperation(op6, loop1, tautology);

    int op7 = graphPtr->emplaceMeasureOD(2, "od", MF::getNum(2), units::s, MF::getNum(2), units::Hz, MF::getNum(650), units::nm); //od = measureOd(2)
    graphPtr->connectOperation(loop1, op7, comp1);

    std::shared_ptr<MathematicOperable> normOD = graphPtr->getVariable("normOD");
    std::shared_ptr<MathematicOperable> od = graphPtr->getVariable("od");
    std::shared_ptr<MathematicOperable> threshold = graphPtr->getVariable("threshold");

    int op8 =  graphPtr->emplaceAssignation("normOD", MF::divide(MF::minus(od, threshold), threshold)); // normOD = (od - threshold) /threshold
    graphPtr->connectOperation(op7, op8, tautology);

    std::shared_ptr<MathematicOperable> rate = graphPtr->getVariable("rate");   
    int op12 = graphPtr->emplaceAssignation("rate", MF::minus(rate,MF::multiply(normOD, rate))); // rate = rate - normOD * rate
    graphPtr->connectOperation(op8, op12, tautology);

    int op13 = graphPtr->emplaceSetContinuousFlow(1, 2, rate, units::ml/units::hr); // setcontinousFlow(1,2,rate)
    graphPtr->connectOperation(op12, op13, tautology);

    int op14 = graphPtr->emplaceSetContinuousFlow(2, 3, rate, units::ml/units::hr); // setcontinousFlow(2,3,rate)
    graphPtr->connectOperation(op13, op14, tautology);

    int timeStep = graphPtr->emplaceTimeStep();
    graphPtr->connectOperation(op14, timeStep, tautology);
    graphPtr->connectOperation(timeStep, loop1, tautology);

    return graphPtr;
}

QTEST_APPLESS_MAIN(ProtocolGraphTest)

#include "tst_protocolgraphtest.moc"
