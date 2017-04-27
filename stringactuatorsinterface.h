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

    virtual void applyLigth(const std::string & sourceId, units::Length wavelength, units::LuminousIntensity intensity);
    virtual void stopApplyLigth(const std::string & sourceId);

    virtual void applyTemperature(const std::string & sourceId, units::Temperature temperature);
    virtual void stopApplyTemperature(const std::string & sourceId);

    virtual void stir(const std::string & idSource, units::Frequency intensity);
    virtual void stopStir(const std::string & idSource);

    virtual units::Volume getVirtualVolume(const std::string & sourceId);
    virtual void loadContainer(const std::string & sourceId, units::Volume initialVolume);

    virtual void startMeasureOD(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency, units::Length wavelength);
    virtual double getMeasureOD(const std::string & sourceId);

    virtual void startMeasureTemperature(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency);
    virtual units::Temperature getMeasureTemperature(const std::string & sourceId);

    virtual void startMeasureLuminiscense(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency);
    virtual units::LuminousIntensity getMeasureLuminiscense(const std::string & sourceId);

    virtual void startMeasureVolume(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency);
    virtual units::Volume getMeasureVolume(const std::string & sourceId);

    virtual void startMeasureFluorescence(const std::string & sourceId, units::Time duration, units::Frequency measurementFrequency);
    virtual units::LuminousIntensity getMeasureFluorescence(const std::string & sourceId);

    virtual void mix(const std::string & idSource1,
                     const std::string & idSource2,
                     const std::string & idTarget,
                     units::Volume volume1,
                     units::Volume volume2);
    virtual void setContinuosFlow(const std::string & idSource, const std::string & idTarget, units::Volumetric_Flow rate);
    virtual void stopContinuosFlow(const std::string & idSource, const std::string & idTarget);
    virtual void transfer(const std::string & idSource, const std::string & idTarget, units::Volume volume);

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
