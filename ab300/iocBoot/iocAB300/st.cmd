#!../../bin/linux-x86_64/AB300

## You may have to change AB300 to something else
## everywhere it appears in this file

#< envPaths

## Register all support components
dbLoadDatabase("../../dbd/AB300.dbd",0,0)
AB300_registerRecordDeviceDriver(pdbbase) 

## Load record instances
dbLoadRecords("../../db/AB300.db","user=linux")

drvAsynSerialPortConfigure("L0","/dev/ttyS0",0,0,0)
asynSetOption("L0", -1, "baud", "9600")
asynSetOption("L0", -1, "bits", "8")
asynSetOption("L0", -1, "parity", "none")
asynSetOption("L0", -1, "stop", "1")
asynSetOption("L0", -1, "clocal", "Y")
asynSetOption("L0", -1, "crtscts", "N")

iocInit()

## Start any sequence programs
#seq sncAB300,"user=linux"
