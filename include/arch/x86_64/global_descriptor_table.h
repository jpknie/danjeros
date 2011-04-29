#ifndef X86_64_GLOBAL_DESCRIPTOR_TABLE
#define X86_64_GLOBAL_DESCRIPTOR_TABLE

#include <stdint.h>
#include <stdbool.h>
#include <arch/x86_64/cpu.h>

typedef unsigned segment_type_t;

#define SEGMENT_TYPE_DATA ((segment_type_t)0)
#define SEGMENT_TYPE_DATA_WRITE ((segment_type_t)(1 << 1))
#define SEGMENT_TYPE_DATA_EXPAND_DOWN ((segment_type_t)(1 << 2))
#define SEGMENT_TYPE_CODE ((segment_type_t)(1 << 3))
#define SEGMENT_TYPE_CODE_CONFORMING ((segment_type_t)(1 << 2))
#define SEGMENT_TYPE_CODE_READ ((segment_type_t)(1 << 1))
#define SEGMENT_TYPE_ACCESSED ((segment_type_t)1)

typedef struct global_descriptor_t {
    uint16_t segment_limit_low;
    uint16_t base_addr_low;
    uint8_t base_addr_mid;
    segment_type_t segment_type : 4;
    bool descriptor_type : 1;
    cpu_privilege_t dpl : 2;
    bool segment_present : 1;
    unsigned segment_limit_high : 4;
    bool available : 1;
    bool code_segment64 : 1;
    bool operation_size : 1;
    bool granularity : 1;
    uint8_t base_addr_high;
}global_descriptor_t;

#endif
