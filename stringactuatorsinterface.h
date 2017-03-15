#ifndef STRINGACTUATORSINTERFACE_H
#define STRINGACTUATORSINTERFACE_H

#include <sstream>
#include <vector>

#include <utils/AutoEnumerate.h>
#include <protocolGraph/execution_interface/actuatorsexecutioninterface.h>

class StringActuatorsInterface : public ActuatorsExecutionInterface
{
public:
    StringActuatorsInterface(const std::vector<double> & measureValues);
    virtual ~StringActuatorsInterface();

    virtual void applyLigth(int sourceId, units::Length wavelength, units::LuminousIntensity intensity);
    virtual void applyTemperature(int sourceId, units::Temperature temperature);
    virtual void stir(int idSource, units::Frequency intensity);

    virtual units::Volume getVirtualVolume(int sourceId);
    virtual void loadContainer(int sourceId, units::Volume initialVolume);

    virtual double measureOD(int sourceId, units::Time duration, units::Frequency measurementFrequency, units::Length wavelength);
    virtual units::Temperature measureTemperature(int sourceId, units::Time duration, units::Frequency measurementFrequency);
    virtual units::LuminousIntensity measureLuminiscense(int sourceId, units::Time duration, units::Frequency measurementFrequency);
    virtual units::Volume measureVolume(int sourceId, units::Time duration, units::Frequency measurementFrequency);
    virtual units::LuminousIntensity measureFluorescence(int sourceId, units::Time duration, units::Frequency measurementFrequency);

    virtual void mix(int idSource1, int idSource2, int idTarget, units::Volume volume1, units::Volume volume2);
    virtual void setContinuosFlow(int idSource, int idTarget, units::Volumetric_Flow rate);
    virtual void transfer(int idSource, int idTarget, units::Volume volume);

    virtual void setTimeStep(units::Time time);
    virtual units::Time timeStep();

    const std::stringstream & getStream() const {
        return stream;
    }

protected:
    double timeSlice;
    std::stringstream stream;

    AutoEnumerate actualValueSerie;
    std::vector<double> measureValues;

    double getNextReadValue();
};

#endif // STRINGACTUATORSINTERFACE_H
