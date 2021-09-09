/*
 * AB300 device support
 */

#include <epicsStdio.h>
#include <devCommonGpib.h>

/******************************************************************************
 *
 * The following define statements are used to declare the names to be used
 * for the dset tables.   
 *
 * A DSET_AI entry must be declared here and referenced in an application
 * database description file even if the device provides no AI records.
 *
 ******************************************************************************/
#define DSET_LI     devLiAB300

#include <devGpib.h> /* must be included after DSET defines */

#define TIMEOUT     1.0    /* I/O must complete within this time */
#define TIMEWINDOW  2.0    /* Wait this long after device timeout */

static int convertStatusReply(struct gpibDpvt *pdpvt, int P1, int P2, char **P3);
static struct gpibCmd gpibCmds[] = {
    /* Param 0 -- Read SCPI identification string */
    {&DSET_LI, GPIBREAD, IB_Q_LOW, "ch1?", NULL, 0, 10, convertStatusReply, 0 , 0, NULL, NULL, NULL},
};

/* The following is the number of elements in the command array above.  */
#define NUMPARAMS sizeof(gpibCmds)/sizeof(struct gpibCmd)

/******************************************************************************
 * Initialize device support parameters
 *
 *****************************************************************************/
static long init_ai(int parm)
{
    if(parm==0) {
        devSupParms.name = "devAB300";
        devSupParms.gpibCmds = gpibCmds;
        devSupParms.numparams = NUMPARAMS;
        devSupParms.timeout = TIMEOUT;
        devSupParms.timeWindow = TIMEWINDOW;
        devSupParms.respond2Writes = -1;
    }
    return(0);
}

static int convertStatusReply(struct gpibDpvt *pdpvt, int P1, int P2, char **P3)
{
        struct longinRecord *pli = ((struct longinRecord *)(pdpvt->precord));
        if (pdpvt->msgInputLen != 1) {
                epicsSnprintf(pdpvt->pasynUser->errorMessage, pdpvt->pasynUser->errorMessageSize, "Invalid reply");
                return -1; 
        }   
        pli->val = pdpvt->msg[0];
        return 0;
}


