/*************************************************************************
Copyright (c) 2012-2015 Miroslav Andel
All rights reserved.

For conditions of distribution and use, see copyright notice in sgct.h 
*************************************************************************/

#ifndef _SGCT_TRACKING_MANAGER_H_
#define _SGCT_TRACKING_MANAGER_H_

#include <vector>
#include <set>
#include "SGCTTracker.h"
#include "SGCTUser.h"
#ifndef SGCT_DONT_USE_EXTERNAL
    #include "external/tinythread.h"
#else
    #include <tinythread.h>
#endif

namespace sgct
{

/*!
Class that manages tracking systems
*/
class SGCTTrackingManager
{
public:
    SGCTTrackingManager();
    ~SGCTTrackingManager();
    
    void startSampling();
    void updateTrackingDevices();
    void addTracker(std::string name);
    void addDeviceToCurrentTracker(std::string name);
    void addSensorToCurrentDevice(const char * address, int id);
    void addButtonsToCurrentDevice(const char * address, size_t numOfButtons);
    void addAnalogsToCurrentDevice(const char * address, size_t numOfAxes);
    
    inline size_t getNumberOfTrackers() { return mTrackers.size(); }
    inline size_t getNumberOfDevices() { return mNumberOfDevices; }
    inline SGCTTrackingDevice * getHeadDevicePtr() { return mHead; }

    SGCTTracker * getLastTrackerPtr();
    SGCTTracker * getTrackerPtr(size_t index);
    SGCTTracker * getTrackerPtr(const char * name);

    void setEnabled(bool state);
    void setSamplingTime(double t);
    double getSamplingTime();

    bool isRunning();

private:
    void setHeadTracker(const char * trackerName, const char * deviceName);

private:
    tthread::thread * mSamplingThread;
    std::vector<SGCTTracker *> mTrackers;
    std::set< std::string > mAddresses;
    double mSamplingTime;
    bool mRunning;

    sgct_core::SGCTUser * mHeadUser;
    SGCTTrackingDevice * mHead;
    size_t mNumberOfDevices;
};

}

#endif
