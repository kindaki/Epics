TOP=..
include $(TOP)/configure/CONFIG
#=======================================

# Build devAB300 as a library for an IOC:
LIBRARY_IOC += devAB300

# Library Source files
devAB300_SRCS += devAB300.c

# Link with the asyn and base libraries
devAB300_LIBS += asyn
devAB300_LIBS += $(EPICS_BASE_IOC_LIBS)

# Install .dbd and .db files
DBD += devAB300.dbd
DB_INSTALLS += devAB300.db

#=======================================
include $(TOP)/configure/RULES
