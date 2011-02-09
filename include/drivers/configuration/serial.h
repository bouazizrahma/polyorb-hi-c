#ifndef _INC_SERIAL_H
#define _INC_SERIAL_H
/*
Code automatically generated by asn1scc tool
Date was: 2/9/2011
Time was: 17:39:11
*/

#include "asn1crt.h"

#ifdef  __cplusplus
extern "C" {
#endif



typedef enum {
    __po_hi_c_b9600 = 0,
    __po_hi_c_b19200 = 1,
    __po_hi_c_b38400 = 2,
    __po_hi_c_b57600 = 3,
    __po_hi_c_b115200 = 4,
    __po_hi_c_b230400 = 5
} __po_hi_c_Baudrate_T;

#define __po_hi_c_Baudrate_T_REQUIRED_BYTES_FOR_ENCODING        1
#define __po_hi_c_Baudrate_T_REQUIRED_BITS_FOR_ENCODING        3
#define __po_hi_c_Baudrate_T_REQUIRED_BYTES_FOR_ACN_ENCODING       1
#define __po_hi_c_Baudrate_T_REQUIRED_BITS_FOR_ACN_ENCODING        3

#ifndef ERR___po_hi_c_Baudrate_T_unknown_enumeration_value 
#define ERR___po_hi_c_Baudrate_T_unknown_enumeration_value		1000 /* invalid enumeration value */
#endif

void __po_hi_c_Baudrate_T_Initialize(__po_hi_c_Baudrate_T* pVal);
flag __po_hi_c_Baudrate_T_IsConstraintValid(const __po_hi_c_Baudrate_T* val, int* pErrCode);
flag __po_hi_c_Baudrate_T_Equal(const __po_hi_c_Baudrate_T* val1, const __po_hi_c_Baudrate_T* val2);



typedef enum {
    __po_hi_c_even = 0,
    __po_hi_c_odd = 1
} __po_hi_c_Parity_T;

#define __po_hi_c_Parity_T_REQUIRED_BYTES_FOR_ENCODING        1
#define __po_hi_c_Parity_T_REQUIRED_BITS_FOR_ENCODING        1
#define __po_hi_c_Parity_T_REQUIRED_BYTES_FOR_ACN_ENCODING       1
#define __po_hi_c_Parity_T_REQUIRED_BITS_FOR_ACN_ENCODING        1

#ifndef ERR___po_hi_c_Parity_T_unknown_enumeration_value 
#define ERR___po_hi_c_Parity_T_unknown_enumeration_value		1001 /* invalid enumeration value */
#endif

void __po_hi_c_Parity_T_Initialize(__po_hi_c_Parity_T* pVal);
flag __po_hi_c_Parity_T_IsConstraintValid(const __po_hi_c_Parity_T* val, int* pErrCode);
flag __po_hi_c_Parity_T_Equal(const __po_hi_c_Parity_T* val1, const __po_hi_c_Parity_T* val2);



typedef struct {
    char devname[21];
    __po_hi_c_Baudrate_T speed;
    __po_hi_c_Parity_T parity;
    asn1SccSint bits;
    flag use_paritybit;
    struct {
        unsigned int speed:1;
        unsigned int parity:1;
        unsigned int bits:1;
        unsigned int use_paritybit:1;
    } exist;
} __po_hi_c_serial_conf_t;

#define __po_hi_c_serial_conf_t_REQUIRED_BYTES_FOR_ENCODING        20
#define __po_hi_c_serial_conf_t_REQUIRED_BITS_FOR_ENCODING        155
#define __po_hi_c_serial_conf_t_REQUIRED_BYTES_FOR_ACN_ENCODING       22
#define __po_hi_c_serial_conf_t_REQUIRED_BITS_FOR_ACN_ENCODING        175

#ifndef ERR___po_hi_c_serial_conf_t_devname 
#define ERR___po_hi_c_serial_conf_t_devname		1002 /* (SIZE (1..20)) */
#endif
#ifndef ERR___po_hi_c_serial_conf_t_bits 
#define ERR___po_hi_c_serial_conf_t_bits		1003 /* (7..8) */
#endif

void __po_hi_c_serial_conf_t_Initialize(__po_hi_c_serial_conf_t* pVal);
flag __po_hi_c_serial_conf_t_IsConstraintValid(const __po_hi_c_serial_conf_t* val, int* pErrCode);
flag __po_hi_c_serial_conf_t_Equal(const __po_hi_c_serial_conf_t* val1, const __po_hi_c_serial_conf_t* val2);




#ifdef  __cplusplus
}
#define ENUM___po_hi_c_b9600	__po_hi_c_b9600
#define ENUM___po_hi_c_b19200	__po_hi_c_b19200
#define ENUM___po_hi_c_b38400	__po_hi_c_b38400
#define ENUM___po_hi_c_b57600	__po_hi_c_b57600
#define ENUM___po_hi_c_b115200	__po_hi_c_b115200
#define ENUM___po_hi_c_b230400	__po_hi_c_b230400
#define ENUM___po_hi_c_even	__po_hi_c_even
#define ENUM___po_hi_c_odd	__po_hi_c_odd
#endif

#endif
