//
// Created by chorm on 2020-01-02.
//

#ifndef SNES_DEV_QC_INT_H
#define SNES_DEV_QC_INT_H

#include <qc_base.h>

/// Provides declarations for all qc operations on integer types

#define __qc_int_ops(type)\
    __qc_def_bop(type,add,+);\
    __qc_def_bop(type,sub,-);\
    __qc_def_bop(type,mul,*);\
    __qc_def_bop(type,div,/);\
    __qc_def_bop(type,band,&);\
    __qc_def_bop(type,bor,|);\
    __qc_def_bop(type,bxor,^);\
    __qc_def_uop(type,neg,-);\
    __qc_def_uop(type,bnot,~);\
    __qc_def_div_ops(type)

#define __qc_def_div_ops(type)\
    typedef struct{ type __quotient; type __remainder;} __div_##type;\
    __qc_extern __div_##type __qc_div_##type(type __divd,type __divs);

#define __qc_def_int_type(type, bits)\
    typedef signed type _Int##bits __qc_sized_int(bits);\
    typedef unsigned type _UInt##bits __qc_sized_int(bits);\
    __qc_int_ops(_Int##bits);\
    __qc_int_ops(_UInt##bits)

#define __qc_def_ext_int_t(type,salias,ualias,bits)\
    typedef signed type salias __qc_sized_int(bits);\
    typedef unsigned type ualias __qc_sized_int(bits);\
    __qc_int_ops(salias);\
    __qc_int_ops(ualias)

#include "qc_int.inc"

// Define Macros for each of the qc operators
// Standard methods of macro function supression are allowed
#define __qc_op_add_Int8(a,b) ((_Int8)((_Int8)a+(_Int8)b)))
#define __qc_op_add_UInt8(a,b) ((_UInt8)((_UInt8)a+(_UInt8)b)))
#define __qc_op_add_Int16(a,b) ((_Int16)((_Int16)a+(_Int16)b)))
#define __qc_op_add_UInt16(a,b) ((_UInt16)((_UInt16)a+(_UInt16)b)))
#define __qc_op_add_Int32(a,b) ((_Int32)((_Int32)a+(_Int32)b)))
#define __qc_op_add_UInt32(a,b) ((_UInt32)((_UInt32)a+(_UInt32)b)))
#define __qc_op_add_Int64(a,b) ((_Int64)((_Int64)a+(_Int64)b)))
#define __qc_op_add_UInt64(a,b) ((_UInt64)((_UInt64)a+(_UInt64)b)))

#endif //SNES_DEV_QC_INT_H
