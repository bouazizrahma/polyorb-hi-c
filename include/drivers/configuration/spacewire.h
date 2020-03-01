#ifndef GENERATED_ASN1SCC_spacewire_H
#define GENERATED_ASN1SCC_spacewire_H
/*
Code automatically generated by asn1scc tool
*/
#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif


typedef asn1SccUint __po_hi_c_Core_Frequence_T;


void __po_hi_c_Core_Frequence_T_Initialize(__po_hi_c_Core_Frequence_T* pVal);

#define ERR_CORE_FREQUENCE_T		1  /**/
flag __po_hi_c_Core_Frequence_T_IsConstraintValid(const __po_hi_c_Core_Frequence_T* pVal, int* pErrCode);
typedef asn1SccUint __po_hi_c_Node_Addr_T;


void __po_hi_c_Node_Addr_T_Initialize(__po_hi_c_Node_Addr_T* pVal);

#define ERR_NODE_ADDR_T		8  /**/
flag __po_hi_c_Node_Addr_T_IsConstraintValid(const __po_hi_c_Node_Addr_T* pVal, int* pErrCode);
typedef asn1SccUint __po_hi_c_Clock_Division_T;


void __po_hi_c_Clock_Division_T_Initialize(__po_hi_c_Clock_Division_T* pVal);

#define ERR_CLOCK_DIVISION_T		15  /**/
flag __po_hi_c_Clock_Division_T_IsConstraintValid(const __po_hi_c_Clock_Division_T* pVal, int* pErrCode);
/*-- __po_hi_c_spacewire_conf_t --------------------------------------------*/
typedef char __po_hi_c_spacewire_conf_t_devname[21];
typedef struct {
    __po_hi_c_spacewire_conf_t_devname devname;
    __po_hi_c_Node_Addr_T nodeaddr;
    __po_hi_c_Core_Frequence_T corefreq;
    __po_hi_c_Clock_Division_T clockdiv;
    flag use_router;
    flag remove_prot_id;
    flag rxblock;
    flag txblock;

    struct {
        unsigned int corefreq:1;
        unsigned int clockdiv:1;
        unsigned int use_router:1;
        unsigned int remove_prot_id:1;
        unsigned int rxblock:1;
        unsigned int txblock:1;
    } exist;

} __po_hi_c_spacewire_conf_t;

void __po_hi_c_spacewire_conf_t_devname_Initialize(__po_hi_c_spacewire_conf_t_devname val);
void __po_hi_c_spacewire_conf_t_Initialize(__po_hi_c_spacewire_conf_t* pVal);

#define ERR_SPACEWIRE_CONF_T		90  /**/
#define ERR_SPACEWIRE_CONF_T_DEVNAME		22  /**/
#define ERR_SPACEWIRE_CONF_T_NODEADDR		29  /**/
#define ERR_SPACEWIRE_CONF_T_COREFREQ		40  /**/
#define ERR_SPACEWIRE_CONF_T_CLOCKDIV		51  /**/
#define ERR_SPACEWIRE_CONF_T_USE_ROUTER		62  /**/
#define ERR_SPACEWIRE_CONF_T_REMOVE_PROT_ID		69  /**/
#define ERR_SPACEWIRE_CONF_T_RXBLOCK		76  /**/
#define ERR_SPACEWIRE_CONF_T_TXBLOCK		83  /**/
flag __po_hi_c_spacewire_conf_t_IsConstraintValid(const __po_hi_c_spacewire_conf_t* pVal, int* pErrCode);

extern const __po_hi_c_spacewire_conf_t leon_rasta_spw_sender;
extern const __po_hi_c_spacewire_conf_t leon_rasta_spw_receiver; 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
