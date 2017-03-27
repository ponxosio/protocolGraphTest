#include "stringactuatorsinterface.h"

StringActuatorsInterface::StringActuatorsInterface(const std::vector<double> & measureValues) :
    measureValues(measureValues)
{

}

StringActuatorsInterface::~StringActuatorsInterface()
{

}

void StringActuatorsInterface::applyLigth(int sourceId, units::Length wavelength, units::LuminousIntensity intensity) {
    stream << "applyLight(" << sourceId << "," << wavelength.to(units::nm) << "nm," << intensity.to(units::cd) << "cd);";
}

void StringActuatorsInterface::applyTemperature(int sourceId, units::Temperature temperature) {
    stream << "applyTemperature(" << sourceId << "," << temperature.to(units::C) << "Cº);";
}

void StringActuatorsInterface::stir(int idSource, units::Frequency intensity) {
    stream << "stir(" << idSource << "," << intensity.to(units::Hz) << "Hz);";
}

units::Volume StringActuatorsInterface::getVirtualVolume(int sourceId) {
    stream << "getVirtualVolume(" << sourceId << ");";
    return -1*units::l;
}

void StringActuatorsInterface::loadContainer(int sourceId, units::Volume initialVolume) {
    stream << "loadContainer(" << sourceId << "," << initialVolume.to(units::ml) << "ml);";
}

double StringActuatorsInterface::measureOD(int sourceId, units::Time duration, units::Frequency measurementFrequency, units::Length wavelength) {
    stream << "measureOD(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz,"
           << wavelength.to(units::nm) << "nm);";
    return getNextReadValue();
}

units::Temperature StringActuatorsInterface::measureTemperature(int sourceId, units::Time duration, units::Frequency measurementFrequency) {
    stream << "measureTemperature(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
    return getNextReadValue()*units::C;
}

units::LuminousIntensity StringActuatorsInterface::measureLuminiscense(int sourceId, units::Time duration, units::Frequency measurementFrequency) {
    stream << "measureLuminiscense(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
    return getNextReadValue()*units::cd;
}

units::Volume StringActuatorsInterface::measureVolume(int sourceId, units::Time duration, units::Frequency measurementFrequency) {
    stream << "measureVolume(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
    return getNextReadValue()*units::ml;
}

units::LuminousIntensity StringActuatorsInterface::measureFluorescence(int sourceId, units::Time duration, units::Frequency measurementFrequency) {
    stream << "measureFluorescence(" << sourceId << "," << duration.to(units::s) << "s," << measurementFrequency.to(units::Hz) << "Hz);";
    return getNextReadValue()*units::cd;
}

void StringActuatorsInterface::mix(int idSource1, int idSource2, int idTarget, units::Volume volume1, units::Volume volume2) {
    stream << "mix(" << idSource1 << "," << idSource2 << "," << idTarget << "," << volume1.to(units::ml) << "ml," << volume2.to(units::ml) << ");";
}

void StringActuatorsInterface::setContinuosFlow(int idSource, int idTarget, units::Volumetric_Flow rate) {
    stream << "setContinuosFlow(" << idSource << "," << idTarget << "," << rate.to(units::ml/units::hr) << "ml/h" << ");";
}

void StringActuatorsInterface::transfer(int idSource, int idTarget, units::Volume volume) {
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
