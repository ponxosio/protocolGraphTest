#include "stringactuatorsinterface.h"

StringActuatorsInterface::StringActuatorsInterface(const std::vector<double> & measureValues) :
    measureValues(measureValues)
{

}

StringActuatorsInterface::~StringActuatorsInterface()
{

}

void StringActuatorsInterface::applyLigth(const std::string & sourceId, units::Length wavelength, units::LuminousIntensity intensity) {
    stream << "applyLight(" << sourceId << "," << wavelength.to(units::nm) << "nm," << intensity.to(units::cd) << "cd);";
}

void StringActuatorsInterface::stopApplyLigth(const std::string & sourceId) {
    stream << "stopApplyLight(" << sourceId << ");";
}

void StringActuatorsInterface::applyTemperature(const std::string & sourceId, units::Temperature temperature) {
    stream << "applyTemperature(" << sourceId << "," << temperature.to(units::C) << "Cº);";
}

void StringActuatorsInterface::stopApplyTemperature(const std::string & sourceId) {
    stream << "stopApplyTemperature(" << sourceId << ");" ;
}

void StringActuatorsInterface::stir(const std::string & idSource, units::Frequency intensity) {
    stream << "stir(" << idSource << "," << intensity.to(units::Hz) << "Hz);";
}

void StringActuatorsInterface::stopStir(const std::string & idSource) {
    stream << "stopStir(" << idSource << ");";
}

units::Volume StringActuatorsInterface::getVirtualVolume(const std::string & sourceId) {
    stream << "getVirtualVolume(" << sourceId << ");";
    return -1*units::l;
}

void StringActuatorsInterface::loadContainer(const std::string & sourceId, units::Volume initialVolume) {
    stream << "loadContainer(" << sourceId << "," << initialVolume.to(units::ml) << "ml);";
}

void StringActuatorsInterface::startMeasureOD(
        const std::string & sourceId,
        units::Time duration, units::Frequency measurementFrequency,
        units::Length wavelength)
{
    stream << "measureOD(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz,"
           << wavelength.to(units::nm) << "nm);";
}

double StringActuatorsInterface::getMeasureOD(const std::string & sourceId) {
    stream << "getMeasureOD(" << sourceId << ");";
    return getNextReadValue();
}

void StringActuatorsInterface::startMeasureTemperature(
        const std::string & sourceId,
        units::Time duration,
        units::Frequency measurementFrequency)
{
    stream << "measureTemperature(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
}

units::Temperature StringActuatorsInterface::getMeasureTemperature(const std::string & sourceId) {
    stream << "getMeasureTemperature(" << sourceId << ");";
    return getNextReadValue()*units::C;
}

void StringActuatorsInterface::startMeasureLuminiscense(
        const std::string & sourceId,
        units::Time duration,
        units::Frequency measurementFrequency)
{
    stream << "measureLuminiscense(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
}

units::LuminousIntensity StringActuatorsInterface::getMeasureLuminiscense(const std::string & sourceId) {
    stream << "getMeasureLuminiscense(" << sourceId << ");";
    return getNextReadValue()*units::cd;
}

void StringActuatorsInterface::startMeasureVolume(
        const std::string & sourceId,
        units::Time duration,
        units::Frequency measurementFrequency)
{
    stream << "measureVolume(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
}

units::Volume StringActuatorsInterface::getMeasureVolume(const std::string & sourceId) {
    stream << "getMeasureVolume(" << sourceId << ");";
    return getNextReadValue()*units::ml;
}

void StringActuatorsInterface::startMeasureFluorescence(
        const std::string & sourceId,
        units::Time duration,
        units::Frequency measurementFrequency)
{
    stream << "measureFluorescence(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
}

units::LuminousIntensity StringActuatorsInterface::getMeasureFluorescence(const std::string & sourceId) {
    stream << "getMeasureFluorescence(" << sourceId << ");";
    return getNextReadValue()*units::cd;
}

void StringActuatorsInterface::mix(
        const std::string & idSource1,
        const std::string & idSource2,
        const std::string & idTarget,
        units::Volume volume1,
        units::Volume volume2)
{
    stream << "mix(" << idSource1 << "," << idSource2 << "," << idTarget << "," << volume1.to(units::ml) << "ml," << volume2.to(units::ml) << ");";
}

void StringActuatorsInterface::setContinuosFlow(
        const std::string & idSource,
        const std::string & idTarget,
        units::Volumetric_Flow rate)
{
    stream << "setContinuosFlow(" << idSource << "," << idTarget << "," << rate.to(units::ml/units::hr) << "ml/h" << ");";
}

void StringActuatorsInterface::stopContinuosFlow(const std::string & idSource, const std::string & idTarget)
{
    stream << "stopContinuosFlow(" << idSource << "," << idTarget << ");";
}

void StringActuatorsInterface::transfer(
        const std::string & idSource,
        const std::string & idTarget,
        units::Volume volume)
{
    stream << "transfer(" << idSource << "," << idTarget << "," << volume.to(units::ml) << "ml" << ");";
}

void StringActuatorsInterface::setTimeStep(units::Time time) {
    stream << "setTimeStep(" << time.to(units::ms) << "ms" << ");";
    timeSlice = time.to(units::ms);
}

units::Time StringActuatorsInterface::timeStep() {
    stream << "timeStep();";
    return timeSlice * units::s;
}

double StringActuatorsInterface::getNextReadValue() {
    if (actualValueSerie.getValue() >= measureValues.size()) {
        actualValueSerie.reset();
    }
    int nextValue = actualValueSerie.getNextValue();
    return measureValues[nextValue];
}
