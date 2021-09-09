TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = AB300
# AB300.dbd will be created and installed
DBD += AB300.dbd

# AB300.dbd will be made up from these files:
AB300_DBD += base.dbd
AB300_DBD += devAB300.dbd
AB300_DBD += drvAsynSerialPort.dbd

# Include dbd files from all support applications:
#AB300_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#AB300_LIBS += xxx
AB300_LIBS += devAB300
AB300_LIBS += asyn

# AB300_registerRecordDeviceDriver.cpp derives from AB300.dbd
AB300_SRCS += AB300_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
AB300_SRCS_DEFAULT += AB300Main.cpp
AB300_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#AB300_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
AB300_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

