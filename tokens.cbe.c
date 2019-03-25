/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#ifndef __cplusplus
typedef unsigned char bool;
#endif

/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#if defined(__GNUC__)
#define  __ATTRIBUTELIST__(x) __attribute__(x)
#else
#define  __ATTRIBUTELIST__(x)  
#endif

#ifdef _MSC_VER
#define __UNALIGNED_LOAD__(type, align, op) *((type __unaligned*)op)
#else
#define __UNALIGNED_LOAD__(type, align, op) ((struct { type data __attribute__((packed, aligned(align))); }*)op)->data
#endif

#ifdef _MSC_VER
#define __MSALIGN__(X) __declspec(align(X))
#else
#define __MSALIGN__(X)
#endif

#ifdef _MSC_VER
#define __builtin_unreachable() __assume(0)
#define __noreturn __declspec(noreturn)
#else
#define __noreturn __attribute__((noreturn))
#define __forceinline __attribute__((always_inline)) inline
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#else
#define LLVM_NAN(NanStr)   ((double)NAN)           /* Double */
#define LLVM_NANF(NanStr)  ((float)NAN))           /* Float */
#define LLVM_INF           ((double)INFINITY)      /* Double */
#define LLVM_INFF          ((float)INFINITY)       /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__ "__attribute__((constructor)) not supported on this compiler"
#define __ATTRIBUTE_DTOR__ "__attribute__((destructor)) not supported on this compiler"
#endif

#if !defined(__GNUC__) || __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if defined(__GNUC__) && defined(__LP64__) /* 128-bit integer types */
typedef int __attribute__((mode(TI))) int128_t;
typedef unsigned __attribute__((mode(TI))) uint128_t;
#define UINT128_C(hi, lo) (((uint128_t)(hi) << 64) | (uint128_t)(lo))
static __forceinline uint128_t llvm_ctor_u128(uint64_t hi, uint64_t lo) { return UINT128_C(hi, lo); }
static __forceinline bool llvm_icmp_eq_u128(uint128_t l, uint128_t r) { return l == r; }
static __forceinline bool llvm_icmp_ne_u128(uint128_t l, uint128_t r) { return l != r; }
static __forceinline bool llvm_icmp_ule_u128(uint128_t l, uint128_t r) { return l <= r; }
static __forceinline bool llvm_icmp_sle_i128(int128_t l, int128_t r) { return l <= r; }
static __forceinline bool llvm_icmp_uge_u128(uint128_t l, uint128_t r) { return l >= r; }
static __forceinline bool llvm_icmp_sge_i128(int128_t l, int128_t r) { return l >= r; }
static __forceinline bool llvm_icmp_ult_u128(uint128_t l, uint128_t r) { return l < r; }
static __forceinline bool llvm_icmp_slt_i128(int128_t l, int128_t r) { return l < r; }
static __forceinline bool llvm_icmp_ugt_u128(uint128_t l, uint128_t r) { return l > r; }
static __forceinline bool llvm_icmp_sgt_i128(int128_t l, int128_t r) { return l > r; }
#else /* manual 128-bit types */
typedef struct { uint64_t lo; uint64_t hi; } uint128_t;
typedef uint128_t int128_t;
#define UINT128_C(hi, lo) {(lo), (hi)}
static __forceinline uint128_t llvm_ctor_u128(uint64_t hi, uint64_t lo) { uint128_t r; r.lo = lo; r.hi = hi; return r; }
static __forceinline bool llvm_icmp_eq_u128(uint128_t l, uint128_t r) { return l.hi == r.hi && l.lo == r.lo; }
static __forceinline bool llvm_icmp_ne_u128(uint128_t l, uint128_t r) { return l.hi != r.hi || l.lo != r.lo; }
static __forceinline bool llvm_icmp_ule_u128(uint128_t l, uint128_t r) { return l.hi < r.hi ? 1 : (l.hi == r.hi ? l.lo <= l.lo : 0); }
static __forceinline bool llvm_icmp_sle_i128(int128_t l, int128_t r) { return (int64_t)l.hi < (int64_t)r.hi ? 1 : (l.hi == r.hi ? (int64_t)l.lo <= (int64_t)l.lo : 0); }
static __forceinline bool llvm_icmp_uge_u128(uint128_t l, uint128_t r) { return l.hi > r.hi ? 1 : (l.hi == r.hi ? l.lo >= l.hi : 0); }
static __forceinline bool llvm_icmp_sge_i128(int128_t l, int128_t r) { return (int64_t)l.hi > (int64_t)r.hi ? 1 : (l.hi == r.hi ? (int64_t)l.lo >= (int64_t)l.lo : 0); }
static __forceinline bool llvm_icmp_ult_u128(uint128_t l, uint128_t r) { return l.hi < r.hi ? 1 : (l.hi == r.hi ? l.lo < l.hi : 0); }
static __forceinline bool llvm_icmp_slt_i128(int128_t l, int128_t r) { return (int64_t)l.hi < (int64_t)r.hi ? 1 : (l.hi == r.hi ? (int64_t)l.lo < (int64_t)l.lo : 0); }
static __forceinline bool llvm_icmp_ugt_u128(uint128_t l, uint128_t r) { return l.hi > r.hi ? 1 : (l.hi == r.hi ? l.lo > l.hi : 0); }
static __forceinline bool llvm_icmp_sgt_i128(int128_t l, int128_t r) { return (int64_t)l.hi > (int64_t)r.hi ? 1 : (l.hi == r.hi ? (int64_t)l.lo > (int64_t)l.lo : 0); }
#define __emulate_i128
#endif

#ifdef _MSC_VER  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#ifdef _MSC_VER
#define __atomic_thread_fence(x) __faststorefence
#endif



/* Support for floating point constants */
typedef uint64_t ConstantDoubleTy;
typedef uint32_t ConstantFloatTy;
typedef struct { uint64_t f1; uint16_t f2; uint16_t pad[3]; } ConstantFP80Ty;
typedef struct { uint64_t f1; uint64_t f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  uint32_t Int32;
  uint64_t Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* Types Declarations */
struct l_struct_struct_OC__IO_FILE;
struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init;
struct l_struct_struct_OC_yy_buffer_state;
struct l_struct_class_OC_Node;
struct l_struct_union_OC_YYSTYPE;
struct l_struct_class_OC_std_KD__KD_allocator;
struct l_struct_struct_OC_std_KD__KD___cxx11_KD__KD_basic_string_MD_char_MC__AC_std_KD__KD_char_traits_MD_char_OD__MC__AC_std_KD__KD_allocator_MD_char_OD__AC__OD__KD__KD__Alloc_hider;
struct l_struct_union_OC_anon;
struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string;
typedef uint32_t l_fptr_2(int, ...);

/* Types Definitions */
struct l_array_1_uint8_t {
  uint8_t array[1];
};
struct l_array_20_uint8_t {
  uint8_t array[20];
};
struct l_struct_struct_OC__IO_FILE {
  uint32_t field0;
  uint8_t* field1;
  uint8_t* field2;
  uint8_t* field3;
  uint8_t* field4;
  uint8_t* field5;
  uint8_t* field6;
  uint8_t* field7;
  uint8_t* field8;
  uint8_t* field9;
  uint8_t* field10;
  uint8_t* field11;
  void* field12;
  struct l_struct_struct_OC__IO_FILE* field13;
  uint32_t field14;
  uint32_t field15;
  uint64_t field16;
  uint16_t field17;
  uint8_t field18;
  struct l_array_1_uint8_t field19;
  uint8_t* field20;
  uint64_t field21;
  void* field22;
  void* field23;
  struct l_struct_struct_OC__IO_FILE* field24;
  uint8_t* field25;
  uint64_t field26;
  uint32_t field27;
  struct l_array_20_uint8_t field28;
};
struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init {
  uint8_t field0;
};
struct l_struct_struct_OC_yy_buffer_state {
  struct l_struct_struct_OC__IO_FILE* field0;
  uint8_t* field1;
  uint8_t* field2;
  uint32_t field3;
  uint32_t field4;
  uint32_t field5;
  uint32_t field6;
  uint32_t field7;
  uint32_t field8;
  uint32_t field9;
  uint32_t field10;
  uint32_t field11;
};
struct l_struct_class_OC_Node {
  l_fptr_2** field0;
};
struct l_struct_union_OC_YYSTYPE {
  struct l_struct_class_OC_Node* field0;
};
struct l_struct_class_OC_std_KD__KD_allocator {
  uint8_t field0;
};
struct l_struct_struct_OC_std_KD__KD___cxx11_KD__KD_basic_string_MD_char_MC__AC_std_KD__KD_char_traits_MD_char_OD__MC__AC_std_KD__KD_allocator_MD_char_OD__AC__OD__KD__KD__Alloc_hider {
  uint8_t* field0;
};
struct l_array_8_uint8_t {
  uint8_t array[8];
};
struct l_struct_union_OC_anon {
  uint64_t field0;
  struct l_array_8_uint8_t field1;
};
struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string {
  struct l_struct_struct_OC_std_KD__KD___cxx11_KD__KD_basic_string_MD_char_MC__AC_std_KD__KD_char_traits_MD_char_OD__MC__AC_std_KD__KD_allocator_MD_char_OD__AC__OD__KD__KD__Alloc_hider field0;
  uint64_t field1;
  struct l_struct_union_OC_anon field2;
};
struct l_array_256_uint8_t {
  uint8_t array[256];
};
struct l_array_33_uint16_t {
  uint16_t array[33];
};
struct l_array_55_uint16_t {
  uint16_t array[55];
};
struct l_array_34_uint16_t {
  uint16_t array[34];
};
struct l_array_36_uint8_t {
  uint8_t array[36];
};
struct l_array_32_uint8_t {
  uint8_t array[32];
};
struct l_array_31_uint8_t {
  uint8_t array[31];
};
struct l_array_29_uint8_t {
  uint8_t array[29];
};
struct l_array_30_uint8_t {
  uint8_t array[30];
};
struct l_array_16_uint8_t {
  uint8_t array[16];
};
struct l_array_51_uint8_t {
  uint8_t array[51];
};
struct l_array_44_uint8_t {
  uint8_t array[44];
};
struct l_array_42_uint8_t {
  uint8_t array[42];
};
struct l_array_41_uint8_t {
  uint8_t array[41];
};
struct l_array_56_uint8_t {
  uint8_t array[56];
};
struct l_array_46_uint8_t {
  uint8_t array[46];
};
struct l_array_49_uint8_t {
  uint8_t array[49];
};
struct l_array_4_uint8_t {
  uint8_t array[4];
};

/* Function definitions */

typedef void l_fptr_1(uint8_t*);


/* External Global Variable Declarations */
extern uint8_t __dso_handle;
extern struct l_struct_struct_OC__IO_FILE* stdin;
extern struct l_struct_struct_OC__IO_FILE* stdout;
extern struct l_struct_union_OC_YYSTYPE yylval;
extern struct l_struct_struct_OC__IO_FILE* stderr;

/* Function Declarations */
static void __cxx_global_var_init(void) __ATTRIBUTELIST__((noinline));
void _ZNSt8ios_base4InitC1Ev(struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init*);
void _ZNSt8ios_base4InitD1Ev(struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init*) __ATTRIBUTELIST__((nothrow));
uint32_t __cxa_atexit(l_fptr_1*, uint8_t*, uint8_t*) __ATTRIBUTELIST__((nothrow));
uint32_t yywrap(void) __ATTRIBUTELIST__((noinline, nothrow));
uint32_t _Z5yylexv(void) __ATTRIBUTELIST__((noinline));
static void _ZL21yyensure_buffer_stackv(void) __ATTRIBUTELIST__((noinline));
struct l_struct_struct_OC_yy_buffer_state* _Z16yy_create_bufferP8_IO_FILEi(struct l_struct_struct_OC__IO_FILE*, uint32_t) __ATTRIBUTELIST__((noinline));
static void _ZL20yy_load_buffer_statev(void) __ATTRIBUTELIST__((noinline, nothrow));
uint32_t printf(uint8_t*, ...);
uint8_t* _Znwm(uint64_t);
void _ZNSaIcEC1Ev(struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((nothrow));
void _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*, uint8_t*, uint64_t, struct l_struct_class_OC_std_KD__KD_allocator*);
uint32_t __gxx_personality_v0(int, ...);
void _ZNSaIcED1Ev(struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((nothrow));
void _ZdlPv(uint8_t*) __ATTRIBUTELIST__((nothrow));
uint64_t fwrite(uint8_t*, uint64_t, uint64_t, struct l_struct_struct_OC__IO_FILE*);
static uint32_t _ZL21yy_get_previous_statev(void) __ATTRIBUTELIST__((noinline, nothrow));
static uint32_t _ZL16yy_try_NUL_transi(uint32_t) __ATTRIBUTELIST__((noinline, nothrow));
static uint32_t _ZL18yy_get_next_bufferv(void) __ATTRIBUTELIST__((noinline));
void _Z9yyrestartP8_IO_FILE(struct l_struct_struct_OC__IO_FILE*) __ATTRIBUTELIST__((noinline));
static __noreturn void _ZL14yy_fatal_errorPKc(uint8_t*) __ATTRIBUTELIST__((noinline));
static void _ZL14yy_init_bufferP15yy_buffer_stateP8_IO_FILE(struct l_struct_struct_OC_yy_buffer_state*, struct l_struct_struct_OC__IO_FILE*) __ATTRIBUTELIST__((noinline));
void _Z19yy_switch_to_bufferP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state*) __ATTRIBUTELIST__((noinline));
uint8_t* _Z7yyallocm(uint64_t) __ATTRIBUTELIST__((noinline, nothrow));
void _Z16yy_delete_bufferP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state*) __ATTRIBUTELIST__((noinline));
void _Z6yyfreePv(uint8_t*) __ATTRIBUTELIST__((noinline, nothrow));
void _Z15yy_flush_bufferP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state*) __ATTRIBUTELIST__((noinline));
void _Z19yypush_buffer_stateP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state*) __ATTRIBUTELIST__((noinline));
void _Z18yypop_buffer_statev(void) __ATTRIBUTELIST__((noinline));
struct l_struct_struct_OC_yy_buffer_state* _Z14yy_scan_bufferPcm(uint8_t*, uint64_t) __ATTRIBUTELIST__((noinline));
struct l_struct_struct_OC_yy_buffer_state* _Z14yy_scan_stringPKc(uint8_t*) __ATTRIBUTELIST__((noinline));
struct l_struct_struct_OC_yy_buffer_state* _Z13yy_scan_bytesPKci(uint8_t*, uint32_t) __ATTRIBUTELIST__((noinline));
uint64_t strlen(uint8_t*) __ATTRIBUTELIST__((nothrow, pure));
uint32_t _Z12yyget_linenov(void) __ATTRIBUTELIST__((noinline, nothrow));
struct l_struct_struct_OC__IO_FILE* _Z8yyget_inv(void) __ATTRIBUTELIST__((noinline, nothrow));
struct l_struct_struct_OC__IO_FILE* _Z9yyget_outv(void) __ATTRIBUTELIST__((noinline, nothrow));
uint32_t _Z10yyget_lengv(void) __ATTRIBUTELIST__((noinline, nothrow));
uint8_t* _Z10yyget_textv(void) __ATTRIBUTELIST__((noinline, nothrow));
void _Z12yyset_linenoi(uint32_t) __ATTRIBUTELIST__((noinline, nothrow));
void _Z8yyset_inP8_IO_FILE(struct l_struct_struct_OC__IO_FILE*) __ATTRIBUTELIST__((noinline, nothrow));
void _Z9yyset_outP8_IO_FILE(struct l_struct_struct_OC__IO_FILE*) __ATTRIBUTELIST__((noinline, nothrow));
uint32_t _Z11yyget_debugv(void) __ATTRIBUTELIST__((noinline, nothrow));
void _Z11yyset_debugi(uint32_t) __ATTRIBUTELIST__((noinline, nothrow));
uint32_t _Z13yylex_destroyv(void) __ATTRIBUTELIST__((noinline));
static uint32_t _ZL15yy_init_globalsv(void) __ATTRIBUTELIST__((noinline, nothrow));
uint8_t* malloc(uint64_t) __ATTRIBUTELIST__((nothrow));
uint8_t* _Z9yyreallocPvm(uint8_t*, uint64_t) __ATTRIBUTELIST__((noinline, nothrow));
uint8_t* realloc(uint8_t*, uint64_t) __ATTRIBUTELIST__((nothrow));
void free(uint8_t*) __ATTRIBUTELIST__((nothrow));
uint32_t getc(struct l_struct_struct_OC__IO_FILE*);
uint32_t ferror(struct l_struct_struct_OC__IO_FILE*) __ATTRIBUTELIST__((nothrow));
uint32_t* __errno_location(void) __ATTRIBUTELIST__((nothrow, const));
uint64_t fread(uint8_t*, uint64_t, uint64_t, struct l_struct_struct_OC__IO_FILE*);
void clearerr(struct l_struct_struct_OC__IO_FILE*) __ATTRIBUTELIST__((nothrow));
uint32_t isatty(uint32_t) __ATTRIBUTELIST__((nothrow));
uint32_t fileno(struct l_struct_struct_OC__IO_FILE*) __ATTRIBUTELIST__((nothrow));
uint32_t fprintf(struct l_struct_struct_OC__IO_FILE*, uint8_t*, ...);
__noreturn void exit(uint32_t) __ATTRIBUTELIST__((nothrow));
static void _GLOBAL__sub_I_tokens_OC_cpp(void) __ATTRIBUTELIST__((noinline));
uint8_t* memset(uint8_t*, uint32_t, uint64_t);


/* Global Variable Definitions and Initialization */
uint32_t yyleng;
struct l_struct_struct_OC__IO_FILE* yyin;
struct l_struct_struct_OC__IO_FILE* yyout;
uint32_t yylineno = 1;
uint32_t yy_flex_debug;
uint8_t* yytext;
static struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init _ZStL8__ioinit;
static uint32_t _ZL7yy_init;
static uint32_t _ZL8yy_start;
static struct l_struct_struct_OC_yy_buffer_state** _ZL15yy_buffer_stack;
static uint64_t _ZL19yy_buffer_stack_top;
static uint8_t* _ZL10yy_c_buf_p;
static uint8_t _ZL12yy_hold_char;
static __MSALIGN__(16) struct l_array_256_uint8_t _ZL5yy_ec __attribute__((aligned(16))) = { { 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 1, 1, 1, 1, 1, 1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 1, 1, 14, 15, 16, 1, 1, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 1, 1, 1, 1, 17, 1, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 1, 19, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
static __MSALIGN__(16) struct l_array_33_uint16_t _ZL9yy_accept __attribute__((aligned(16))) = { { 0, 0, 0, 24, 22, 1, 1, 22, 12, 13, 20, 18, 17, 19, 16, 21, 4, 8, 5, 10, 2, 14, 15, 7, 3, 3, 9, 6, 11, 2, 3, 3, 0 } };
static uint32_t _ZL23yy_last_accepting_state;
static uint8_t* _ZL22yy_last_accepting_cpos;
static __MSALIGN__(16) struct l_array_55_uint16_t _ZL6yy_chk __attribute__((aligned(16))) = { { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 20, 29, 33, 31, 20, 29, 30, 25, 24, 19, 18, 17, 16, 7, 3, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 } };
static __MSALIGN__(16) struct l_array_34_uint16_t _ZL7yy_base __attribute__((aligned(16))) = { { 0, 0, 0, 34, 35, 35, 35, 18, 35, 35, 35, 35, 35, 35, 35, 35, 19, 16, 15, 14, 7, 35, 35, 35, 15, 14, 35, 35, 35, 8, 13, 10, 35, 21 } };
static __MSALIGN__(16) struct l_array_34_uint16_t _ZL6yy_def __attribute__((aligned(16))) = { { 0, 32, 1, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 33, 32, 32, 32, 32, 32, 32, 32, 32, 33, 32, 32, 32, 32, 32, 33, 0, 32 } };
static __MSALIGN__(16) struct l_array_20_uint8_t _ZL7yy_meta __attribute__((aligned(16))) = { { 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
static __MSALIGN__(16) struct l_array_55_uint16_t _ZL6yy_nxt __attribute__((aligned(16))) = { { 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 29, 29, 24, 31, 29, 29, 30, 31, 30, 28, 27, 26, 25, 23, 32, 3, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 } };
static struct l_array_36_uint8_t _OC_str = { "%s\t -- TIDENTIFIER\t TOKEN_ID is %d\n" };
static struct l_array_32_uint8_t _OC_str_OC_1 = { "%s\t -- TDOUBLE\t TOKEN_ID is %d\n" };
static struct l_array_31_uint8_t _OC_str_OC_2 = { "%s\t -- TEQUAL\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_3 = { "%s\t -- TCEQ\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_4 = { "%s\t -- TCNE\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_5 = { "%s\t -- TCLT\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_6 = { "%s\t -- TCLE\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_7 = { "%s\t -- TCGT\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_8 = { "%s\t -- TCGE\t TOKEN_ID is %d\n" };
static struct l_array_32_uint8_t _OC_str_OC_9 = { "%s\t -- TLPAREN\t TOKEN_ID is %d\n" };
static struct l_array_32_uint8_t _OC_str_OC_10 = { "%s\t -- TRPAREN\t TOKEN_ID is %d\n" };
static struct l_array_32_uint8_t _OC_str_OC_11 = { "%s\t -- TLBRACE\t TOKEN_ID is %d\n" };
static struct l_array_32_uint8_t _OC_str_OC_12 = { "%s\t -- TRBRACE\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_13 = { "%s\t -- TDOT\t TOKEN_ID is %d\n" };
static struct l_array_31_uint8_t _OC_str_OC_14 = { "%s\t -- TCOMMA\t TOKEN_ID is %d\n" };
static struct l_array_30_uint8_t _OC_str_OC_15 = { "%s\t -- TPLUS\t TOKEN_ID is %d\n" };
static struct l_array_31_uint8_t _OC_str_OC_16 = { "%s\t -- TMINUS\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_17 = { "%s\t -- TMUL\t TOKEN_ID is %d\n" };
static struct l_array_29_uint8_t _OC_str_OC_18 = { "%s\t -- TDIV\t TOKEN_ID is %d\n" };
static struct l_array_16_uint8_t _OC_str_OC_19 = { "Unknown token!\n" };
static uint32_t _ZL10yy_n_chars;
static uint32_t _ZL27yy_did_buffer_switch_on_eof;
static struct l_array_51_uint8_t _OC_str_OC_20 = { "fatal flex scanner internal error--no action found" };
static struct l_array_44_uint8_t _OC_str_OC_21 = { "out of dynamic memory in yy_create_buffer()" };
static struct l_array_42_uint8_t _OC_str_OC_22 = { "out of dynamic memory in yy_scan_buffer()" };
static struct l_array_41_uint8_t _OC_str_OC_23 = { "out of dynamic memory in yy_scan_bytes()" };
static struct l_array_30_uint8_t _OC_str_OC_24 = { "bad buffer in yy_scan_bytes()" };
static struct l_array_56_uint8_t _OC_str_OC_25 = { "fatal flex scanner internal error--end of buffer missed" };
static struct l_array_44_uint8_t _OC_str_OC_26 = { "fatal error - scanner input buffer overflow" };
static struct l_array_29_uint8_t _OC_str_OC_27 = { "input in flex scanner failed" };
static struct l_array_46_uint8_t _OC_str_OC_28 = { "out of dynamic memory in yy_get_next_buffer()" };
static struct l_array_49_uint8_t _OC_str_OC_29 = { "out of dynamic memory in yyensure_buffer_stack()" };
static uint64_t _ZL19yy_buffer_stack_max;
static struct l_array_4_uint8_t _OC_str_OC_30 = { "%s\n" };


/* LLVM Intrinsic Builtin Function Bodies */
static __forceinline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static __forceinline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static __forceinline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static __forceinline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static __forceinline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static __forceinline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static __forceinline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static __forceinline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static __forceinline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static __forceinline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static __forceinline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static __forceinline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static __forceinline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static __forceinline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }
static __forceinline int llvm_fcmp_0(double X, double Y) { return 0; }
static __forceinline int llvm_fcmp_1(double X, double Y) { return 1; }
static __forceinline uint32_t llvm_add_u32(uint32_t a, uint32_t b) {
  uint32_t r = a + b;
  return r;
}
static __forceinline uint64_t llvm_add_u64(uint64_t a, uint64_t b) {
  uint64_t r = a + b;
  return r;
}
static __forceinline uint32_t llvm_sub_u32(uint32_t a, uint32_t b) {
  uint32_t r = a - b;
  return r;
}
static __forceinline uint64_t llvm_sub_u64(uint64_t a, uint64_t b) {
  uint64_t r = a - b;
  return r;
}
static __forceinline uint32_t llvm_mul_u32(uint32_t a, uint32_t b) {
  uint32_t r = a * b;
  return r;
}
static __forceinline uint64_t llvm_mul_u64(uint64_t a, uint64_t b) {
  uint64_t r = a * b;
  return r;
}
static __forceinline uint32_t llvm_sdiv_u32(int32_t a, int32_t b) {
  uint32_t r = a / b;
  return r;
}
static __forceinline uint32_t llvm_ashr_u32(int32_t a, int32_t b) {
  uint32_t r = a >> b;
  return r;
}


/* Function Bodies */

static void __cxx_global_var_init(void) {
  uint32_t llvm_cbe_tmp__1;

  _ZNSt8ios_base4InitC1Ev((&_ZStL8__ioinit));
  llvm_cbe_tmp__1 = __cxa_atexit(((l_fptr_1*)_ZNSt8ios_base4InitD1Ev), ((&_ZStL8__ioinit.field0)), (&__dso_handle));
}


uint32_t yywrap(void) {
  uint32_t llvm_cbe_tmp__2;    /* Address-exposed local */

  llvm_OC_trap();
  __builtin_unreachable();

}


uint32_t _Z5yylexv(void) {
  uint32_t llvm_cbe_tmp__3;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__4;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__5;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__6;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__7;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__8;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__9;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__10;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__11;    /* Address-exposed local */
  bool llvm_cbe_tmp__12;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__13;    /* Address-exposed local */
  bool llvm_cbe_tmp__14;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__15;    /* Address-exposed local */
  bool llvm_cbe_tmp__16;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__17;    /* Address-exposed local */
  bool llvm_cbe_tmp__18;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__19;    /* Address-exposed local */
  bool llvm_cbe_tmp__20;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__21;    /* Address-exposed local */
  bool llvm_cbe_tmp__22;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__23;    /* Address-exposed local */
  bool llvm_cbe_tmp__24;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__25;    /* Address-exposed local */
  bool llvm_cbe_tmp__26;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__27;    /* Address-exposed local */
  bool llvm_cbe_tmp__28;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__29;    /* Address-exposed local */
  bool llvm_cbe_tmp__30;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__31;    /* Address-exposed local */
  bool llvm_cbe_tmp__32;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__33;    /* Address-exposed local */
  bool llvm_cbe_tmp__34;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__35;    /* Address-exposed local */
  bool llvm_cbe_tmp__36;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__37;    /* Address-exposed local */
  bool llvm_cbe_tmp__38;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__39;    /* Address-exposed local */
  bool llvm_cbe_tmp__40;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__41;    /* Address-exposed local */
  bool llvm_cbe_tmp__42;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__43;    /* Address-exposed local */
  bool llvm_cbe_tmp__44;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__45;    /* Address-exposed local */
  bool llvm_cbe_tmp__46;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__47;    /* Address-exposed local */
  bool llvm_cbe_tmp__48;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator llvm_cbe_tmp__49;    /* Address-exposed local */
  bool llvm_cbe_tmp__50;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__51;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__52;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__53;
  uint32_t llvm_cbe_tmp__54;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__55;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__56;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__57;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__58;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__59;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__60;
  uint64_t llvm_cbe_tmp__61;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__62;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__63;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__63__PHI_TEMPORARY;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__64;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__65;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__66;
  uint64_t llvm_cbe_tmp__67;
  uint8_t* llvm_cbe_tmp__68;
  uint8_t llvm_cbe_tmp__69;
  uint8_t* llvm_cbe_tmp__70;
  uint8_t* llvm_cbe_tmp__71;
  uint32_t llvm_cbe_tmp__72;
  uint8_t* llvm_cbe_tmp__73;
  uint8_t llvm_cbe_tmp__74;
  uint8_t llvm_cbe_tmp__75;
  uint32_t llvm_cbe_tmp__76;
  uint16_t llvm_cbe_tmp__77;
  uint32_t llvm_cbe_tmp__78;
  uint8_t* llvm_cbe_tmp__79;
  uint32_t llvm_cbe_tmp__80;
  uint16_t llvm_cbe_tmp__81;
  uint8_t llvm_cbe_tmp__82;
  uint16_t llvm_cbe_tmp__83;
  uint32_t llvm_cbe_tmp__84;
  uint32_t llvm_cbe_tmp__85;
  uint16_t llvm_cbe_tmp__86;
  uint32_t llvm_cbe_tmp__87;
  uint8_t llvm_cbe_tmp__88;
  uint8_t llvm_cbe_tmp__89;
  uint32_t llvm_cbe_tmp__90;
  uint16_t llvm_cbe_tmp__91;
  uint8_t llvm_cbe_tmp__92;
  uint16_t llvm_cbe_tmp__93;
  uint8_t* llvm_cbe_tmp__94;
  uint32_t llvm_cbe_tmp__95;
  uint16_t llvm_cbe_tmp__96;
  uint32_t llvm_cbe_tmp__97;
  uint16_t llvm_cbe_tmp__98;
  uint32_t llvm_cbe_tmp__99;
  uint8_t* llvm_cbe_tmp__100;
  uint32_t llvm_cbe_tmp__101;
  uint32_t llvm_cbe_tmp__102;
  uint16_t llvm_cbe_tmp__103;
  uint8_t* llvm_cbe_tmp__104;
  uint8_t* llvm_cbe_tmp__105;
  uint8_t* llvm_cbe_tmp__106;
  uint8_t* llvm_cbe_tmp__107;
  uint8_t llvm_cbe_tmp__108;
  uint8_t* llvm_cbe_tmp__109;
  uint8_t* llvm_cbe_tmp__110;
  uint32_t llvm_cbe_tmp__111;
  uint8_t llvm_cbe_tmp__112;
  uint8_t* llvm_cbe_tmp__113;
  uint8_t* llvm_cbe_tmp__114;
  uint32_t llvm_cbe_tmp__115;
  uint8_t* llvm_cbe_tmp__116;
  uint32_t llvm_cbe_tmp__117;
  uint8_t* llvm_cbe_tmp__118;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__119;
  uint8_t* llvm_cbe_tmp__120;
  uint32_t llvm_cbe_tmp__121;
  uint8_t* llvm_cbe_tmp__122;
  uint32_t llvm_cbe_tmp__123;
  uint8_t* llvm_cbe_tmp__124;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__125;
  uint8_t* llvm_cbe_tmp__126;
  uint32_t llvm_cbe_tmp__127;
  uint8_t* llvm_cbe_tmp__128;
  uint32_t llvm_cbe_tmp__129;
  uint8_t* llvm_cbe_tmp__130;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__131;
  uint8_t* llvm_cbe_tmp__132;
  uint32_t llvm_cbe_tmp__133;
  uint8_t* llvm_cbe_tmp__134;
  uint32_t llvm_cbe_tmp__135;
  uint8_t* llvm_cbe_tmp__136;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__137;
  uint8_t* llvm_cbe_tmp__138;
  uint32_t llvm_cbe_tmp__139;
  uint8_t* llvm_cbe_tmp__140;
  uint32_t llvm_cbe_tmp__141;
  uint8_t* llvm_cbe_tmp__142;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__143;
  uint8_t* llvm_cbe_tmp__144;
  uint32_t llvm_cbe_tmp__145;
  uint8_t* llvm_cbe_tmp__146;
  uint32_t llvm_cbe_tmp__147;
  uint8_t* llvm_cbe_tmp__148;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__149;
  uint8_t* llvm_cbe_tmp__150;
  uint32_t llvm_cbe_tmp__151;
  uint8_t* llvm_cbe_tmp__152;
  uint32_t llvm_cbe_tmp__153;
  uint8_t* llvm_cbe_tmp__154;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__155;
  uint8_t* llvm_cbe_tmp__156;
  uint32_t llvm_cbe_tmp__157;
  uint8_t* llvm_cbe_tmp__158;
  uint32_t llvm_cbe_tmp__159;
  uint8_t* llvm_cbe_tmp__160;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__161;
  uint8_t* llvm_cbe_tmp__162;
  uint32_t llvm_cbe_tmp__163;
  uint8_t* llvm_cbe_tmp__164;
  uint32_t llvm_cbe_tmp__165;
  uint8_t* llvm_cbe_tmp__166;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__167;
  uint8_t* llvm_cbe_tmp__168;
  uint32_t llvm_cbe_tmp__169;
  uint8_t* llvm_cbe_tmp__170;
  uint32_t llvm_cbe_tmp__171;
  uint8_t* llvm_cbe_tmp__172;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__173;
  uint8_t* llvm_cbe_tmp__174;
  uint32_t llvm_cbe_tmp__175;
  uint8_t* llvm_cbe_tmp__176;
  uint32_t llvm_cbe_tmp__177;
  uint8_t* llvm_cbe_tmp__178;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__179;
  uint8_t* llvm_cbe_tmp__180;
  uint32_t llvm_cbe_tmp__181;
  uint8_t* llvm_cbe_tmp__182;
  uint32_t llvm_cbe_tmp__183;
  uint8_t* llvm_cbe_tmp__184;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__185;
  uint8_t* llvm_cbe_tmp__186;
  uint32_t llvm_cbe_tmp__187;
  uint8_t* llvm_cbe_tmp__188;
  uint32_t llvm_cbe_tmp__189;
  uint8_t* llvm_cbe_tmp__190;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__191;
  uint8_t* llvm_cbe_tmp__192;
  uint32_t llvm_cbe_tmp__193;
  uint8_t* llvm_cbe_tmp__194;
  uint32_t llvm_cbe_tmp__195;
  uint8_t* llvm_cbe_tmp__196;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__197;
  uint8_t* llvm_cbe_tmp__198;
  uint32_t llvm_cbe_tmp__199;
  uint8_t* llvm_cbe_tmp__200;
  uint32_t llvm_cbe_tmp__201;
  uint8_t* llvm_cbe_tmp__202;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__203;
  uint8_t* llvm_cbe_tmp__204;
  uint32_t llvm_cbe_tmp__205;
  uint8_t* llvm_cbe_tmp__206;
  uint32_t llvm_cbe_tmp__207;
  uint8_t* llvm_cbe_tmp__208;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__209;
  uint8_t* llvm_cbe_tmp__210;
  uint32_t llvm_cbe_tmp__211;
  uint8_t* llvm_cbe_tmp__212;
  uint32_t llvm_cbe_tmp__213;
  uint8_t* llvm_cbe_tmp__214;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__215;
  uint8_t* llvm_cbe_tmp__216;
  uint32_t llvm_cbe_tmp__217;
  uint8_t* llvm_cbe_tmp__218;
  uint32_t llvm_cbe_tmp__219;
  uint8_t* llvm_cbe_tmp__220;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__221;
  uint8_t* llvm_cbe_tmp__222;
  uint32_t llvm_cbe_tmp__223;
  uint8_t* llvm_cbe_tmp__224;
  uint32_t llvm_cbe_tmp__225;
  uint8_t* llvm_cbe_tmp__226;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__227;
  uint8_t* llvm_cbe_tmp__228;
  uint32_t llvm_cbe_tmp__229;
  uint8_t* llvm_cbe_tmp__230;
  uint32_t llvm_cbe_tmp__231;
  uint8_t* llvm_cbe_tmp__232;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__233;
  uint8_t* llvm_cbe_tmp__234;
  uint32_t llvm_cbe_tmp__235;
  uint32_t llvm_cbe_tmp__236;
  uint8_t* llvm_cbe_tmp__237;
  uint32_t llvm_cbe_tmp__238;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__239;
  uint64_t llvm_cbe_tmp__240;
  uint8_t* llvm_cbe_tmp__241;
  uint8_t* llvm_cbe_tmp__242;
  uint8_t llvm_cbe_tmp__243;
  uint8_t* llvm_cbe_tmp__244;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__245;
  uint64_t llvm_cbe_tmp__246;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__247;
  uint32_t llvm_cbe_tmp__248;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__249;
  uint64_t llvm_cbe_tmp__250;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__251;
  uint32_t llvm_cbe_tmp__252;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__253;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__254;
  uint64_t llvm_cbe_tmp__255;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__256;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__257;
  uint64_t llvm_cbe_tmp__258;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__259;
  uint8_t* llvm_cbe_tmp__260;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__261;
  uint64_t llvm_cbe_tmp__262;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__263;
  uint8_t* llvm_cbe_tmp__264;
  uint32_t llvm_cbe_tmp__265;
  uint8_t* llvm_cbe_tmp__266;
  uint32_t llvm_cbe_tmp__267;
  uint32_t llvm_cbe_tmp__268;
  uint32_t llvm_cbe_tmp__269;
  uint32_t llvm_cbe_tmp__270;
  uint8_t* llvm_cbe_tmp__271;
  uint32_t llvm_cbe_tmp__272;
  uint8_t* llvm_cbe_tmp__273;
  uint8_t* llvm_cbe_tmp__274;
  uint32_t llvm_cbe_tmp__275;
  uint8_t* llvm_cbe_tmp__276;
  uint32_t llvm_cbe_tmp__277;
  uint32_t llvm_cbe_tmp__278;
  uint8_t* llvm_cbe_tmp__279;
  uint32_t llvm_cbe_tmp__280;
  uint32_t llvm_cbe_tmp__281;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__282;
  uint8_t* llvm_cbe_tmp__283;
  uint32_t llvm_cbe_tmp__284;
  uint32_t llvm_cbe_tmp__285;
  uint8_t* llvm_cbe_tmp__286;
  uint8_t* llvm_cbe_tmp__287;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__288;
  uint64_t llvm_cbe_tmp__289;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__290;
  uint8_t* llvm_cbe_tmp__291;
  uint32_t llvm_cbe_tmp__292;
  uint32_t llvm_cbe_tmp__293;
  uint8_t* llvm_cbe_tmp__294;
  uint8_t* llvm_cbe_tmp__295;
  uint32_t llvm_cbe_tmp__296;

  llvm_cbe_tmp__53 = _ZL7yy_init;
  if ((((llvm_cbe_tmp__53 != 0u)&1))) {
    goto llvm_cbe_tmp__297;
  } else {
    goto llvm_cbe_tmp__298;
  }

llvm_cbe_tmp__298:
  _ZL7yy_init = 1;
  llvm_cbe_tmp__54 = _ZL8yy_start;
  if ((((llvm_cbe_tmp__54 != 0u)&1))) {
    goto llvm_cbe_tmp__299;
  } else {
    goto llvm_cbe_tmp__300;
  }

llvm_cbe_tmp__300:
  _ZL8yy_start = 1;
  goto llvm_cbe_tmp__299;

llvm_cbe_tmp__299:
  llvm_cbe_tmp__55 = yyin;
  if ((((llvm_cbe_tmp__55 != ((struct l_struct_struct_OC__IO_FILE*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__301;
  } else {
    goto llvm_cbe_tmp__302;
  }

llvm_cbe_tmp__302:
  llvm_cbe_tmp__56 = stdin;
  yyin = llvm_cbe_tmp__56;
  goto llvm_cbe_tmp__301;

llvm_cbe_tmp__301:
  llvm_cbe_tmp__57 = yyout;
  if ((((llvm_cbe_tmp__57 != ((struct l_struct_struct_OC__IO_FILE*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__303;
  } else {
    goto llvm_cbe_tmp__304;
  }

llvm_cbe_tmp__304:
  llvm_cbe_tmp__58 = stdout;
  yyout = llvm_cbe_tmp__58;
  goto llvm_cbe_tmp__303;

llvm_cbe_tmp__303:
  llvm_cbe_tmp__59 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__59 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__305;
  } else {
    goto llvm_cbe_tmp__306;
  }

llvm_cbe_tmp__305:
  llvm_cbe_tmp__60 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__61 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__62 = *((&llvm_cbe_tmp__60[((int64_t)llvm_cbe_tmp__61)]));
  llvm_cbe_tmp__63__PHI_TEMPORARY = llvm_cbe_tmp__62;   /* for PHI node */
  goto llvm_cbe_tmp__307;

llvm_cbe_tmp__306:
  llvm_cbe_tmp__63__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__307;

llvm_cbe_tmp__307:
  llvm_cbe_tmp__63 = llvm_cbe_tmp__63__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__63 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__308;
  } else {
    goto llvm_cbe_tmp__309;
  }

llvm_cbe_tmp__309:
  _ZL21yyensure_buffer_stackv();
  llvm_cbe_tmp__64 = yyin;
  llvm_cbe_tmp__65 = _Z16yy_create_bufferP8_IO_FILEi(llvm_cbe_tmp__64, 16384);
  llvm_cbe_tmp__66 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__67 = _ZL19yy_buffer_stack_top;
  *((&llvm_cbe_tmp__66[((int64_t)llvm_cbe_tmp__67)])) = llvm_cbe_tmp__65;
  goto llvm_cbe_tmp__308;

llvm_cbe_tmp__308:
  _ZL20yy_load_buffer_statev();
  goto llvm_cbe_tmp__297;

llvm_cbe_tmp__297:
  goto llvm_cbe_tmp__310;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__310:
  llvm_cbe_tmp__68 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__5 = llvm_cbe_tmp__68;
  llvm_cbe_tmp__69 = _ZL12yy_hold_char;
  llvm_cbe_tmp__70 = llvm_cbe_tmp__5;
  *llvm_cbe_tmp__70 = llvm_cbe_tmp__69;
  llvm_cbe_tmp__71 = llvm_cbe_tmp__5;
  llvm_cbe_tmp__6 = llvm_cbe_tmp__71;
  llvm_cbe_tmp__72 = _ZL8yy_start;
  llvm_cbe_tmp__4 = llvm_cbe_tmp__72;
  goto llvm_cbe_tmp__311;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__311:
  goto llvm_cbe_tmp__312;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__312:
  llvm_cbe_tmp__73 = llvm_cbe_tmp__5;
  llvm_cbe_tmp__74 = *llvm_cbe_tmp__73;
  llvm_cbe_tmp__75 = *((&_ZL5yy_ec.array[((int64_t)(((uint64_t)(uint8_t)llvm_cbe_tmp__74)))]));
  llvm_cbe_tmp__8 = llvm_cbe_tmp__75;
  llvm_cbe_tmp__76 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__77 = *((&_ZL9yy_accept.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__76)))]));
  if ((((llvm_cbe_tmp__77 != ((uint16_t)0))&1))) {
    goto llvm_cbe_tmp__313;
  } else {
    goto llvm_cbe_tmp__314;
  }

llvm_cbe_tmp__313:
  llvm_cbe_tmp__78 = llvm_cbe_tmp__4;
  _ZL23yy_last_accepting_state = llvm_cbe_tmp__78;
  llvm_cbe_tmp__79 = llvm_cbe_tmp__5;
  _ZL22yy_last_accepting_cpos = llvm_cbe_tmp__79;
  goto llvm_cbe_tmp__314;

llvm_cbe_tmp__314:
  goto llvm_cbe_tmp__315;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__315:
  llvm_cbe_tmp__80 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__81 = *((&_ZL7yy_base.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__80)))]));
  llvm_cbe_tmp__82 = llvm_cbe_tmp__8;
  llvm_cbe_tmp__83 = *((&_ZL6yy_chk.array[((int64_t)(((int64_t)(int32_t)(llvm_add_u32((((int32_t)(int16_t)llvm_cbe_tmp__81)), (((uint32_t)(uint8_t)llvm_cbe_tmp__82)))))))]));
  llvm_cbe_tmp__84 = llvm_cbe_tmp__4;
  if (((((((int32_t)(int16_t)llvm_cbe_tmp__83)) != llvm_cbe_tmp__84)&1))) {
    goto llvm_cbe_tmp__316;
  } else {
    goto llvm_cbe_tmp__317;
  }

llvm_cbe_tmp__316:
  llvm_cbe_tmp__85 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__86 = *((&_ZL6yy_def.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__85)))]));
  llvm_cbe_tmp__4 = (((int32_t)(int16_t)llvm_cbe_tmp__86));
  llvm_cbe_tmp__87 = llvm_cbe_tmp__4;
  if ((((((int32_t)llvm_cbe_tmp__87) >= ((int32_t)33u))&1))) {
    goto llvm_cbe_tmp__318;
  } else {
    goto llvm_cbe_tmp__319;
  }

llvm_cbe_tmp__318:
  llvm_cbe_tmp__88 = llvm_cbe_tmp__8;
  llvm_cbe_tmp__89 = *((&_ZL7yy_meta.array[((int64_t)(((uint64_t)(uint8_t)llvm_cbe_tmp__88)))]));
  llvm_cbe_tmp__8 = llvm_cbe_tmp__89;
  goto llvm_cbe_tmp__319;

llvm_cbe_tmp__319:
  goto llvm_cbe_tmp__315;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__317:
  llvm_cbe_tmp__90 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__91 = *((&_ZL7yy_base.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__90)))]));
  llvm_cbe_tmp__92 = llvm_cbe_tmp__8;
  llvm_cbe_tmp__93 = *((&_ZL6yy_nxt.array[((int64_t)(((int64_t)(int32_t)(llvm_add_u32((((int32_t)(int16_t)llvm_cbe_tmp__91)), (((uint32_t)(uint8_t)llvm_cbe_tmp__92)))))))]));
  llvm_cbe_tmp__4 = (((int32_t)(int16_t)llvm_cbe_tmp__93));
  llvm_cbe_tmp__94 = llvm_cbe_tmp__5;
  llvm_cbe_tmp__5 = ((&llvm_cbe_tmp__94[((int32_t)1)]));
  goto llvm_cbe_tmp__320;

llvm_cbe_tmp__320:
  llvm_cbe_tmp__95 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__96 = *((&_ZL7yy_base.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__95)))]));
  if (((((((int32_t)(int16_t)llvm_cbe_tmp__96)) != 35u)&1))) {
    goto llvm_cbe_tmp__312;
  } else {
    goto llvm_cbe_tmp__321;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__321:
  goto llvm_cbe_tmp__322;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__322:
  llvm_cbe_tmp__97 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__98 = *((&_ZL9yy_accept.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__97)))]));
  llvm_cbe_tmp__7 = (((int32_t)(int16_t)llvm_cbe_tmp__98));
  llvm_cbe_tmp__99 = llvm_cbe_tmp__7;
  if ((((llvm_cbe_tmp__99 == 0u)&1))) {
    goto llvm_cbe_tmp__323;
  } else {
    goto llvm_cbe_tmp__324;
  }

llvm_cbe_tmp__323:
  llvm_cbe_tmp__100 = _ZL22yy_last_accepting_cpos;
  llvm_cbe_tmp__5 = llvm_cbe_tmp__100;
  llvm_cbe_tmp__101 = _ZL23yy_last_accepting_state;
  llvm_cbe_tmp__4 = llvm_cbe_tmp__101;
  llvm_cbe_tmp__102 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__103 = *((&_ZL9yy_accept.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__102)))]));
  llvm_cbe_tmp__7 = (((int32_t)(int16_t)llvm_cbe_tmp__103));
  goto llvm_cbe_tmp__324;

llvm_cbe_tmp__324:
  llvm_cbe_tmp__104 = llvm_cbe_tmp__6;
  yytext = llvm_cbe_tmp__104;
  llvm_cbe_tmp__105 = llvm_cbe_tmp__5;
  llvm_cbe_tmp__106 = llvm_cbe_tmp__6;
  yyleng = (((uint32_t)(llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__105)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__106))))));
  llvm_cbe_tmp__107 = llvm_cbe_tmp__5;
  llvm_cbe_tmp__108 = *llvm_cbe_tmp__107;
  _ZL12yy_hold_char = llvm_cbe_tmp__108;
  llvm_cbe_tmp__109 = llvm_cbe_tmp__5;
  *llvm_cbe_tmp__109 = 0;
  llvm_cbe_tmp__110 = llvm_cbe_tmp__5;
  _ZL10yy_c_buf_p = llvm_cbe_tmp__110;
  goto llvm_cbe_tmp__325;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__325:
  llvm_cbe_tmp__111 = llvm_cbe_tmp__7;
  switch (llvm_cbe_tmp__111) {
  default:
    goto llvm_cbe_tmp__326;
  case 0u:
    goto llvm_cbe_tmp__327;
  case 1u:
    goto llvm_cbe_tmp__328;
  case 2u:
    goto llvm_cbe_tmp__329;
  case 3u:
    goto llvm_cbe_tmp__330;
  case 4u:
    goto llvm_cbe_tmp__331;
  case 5u:
    goto llvm_cbe_tmp__332;
  case 6u:
    goto llvm_cbe_tmp__333;
  case 7u:
    goto llvm_cbe_tmp__334;
  case 8u:
    goto llvm_cbe_tmp__335;
  case 9u:
    goto llvm_cbe_tmp__336;
  case 10u:
    goto llvm_cbe_tmp__337;
  case 11u:
    goto llvm_cbe_tmp__338;
  case 12u:
    goto llvm_cbe_tmp__339;
  case 13u:
    goto llvm_cbe_tmp__340;
  case 14u:
    goto llvm_cbe_tmp__341;
  case 15u:
    goto llvm_cbe_tmp__342;
  case 16u:
    goto llvm_cbe_tmp__343;
  case 17u:
    goto llvm_cbe_tmp__344;
  case 18u:
    goto llvm_cbe_tmp__345;
  case 19u:
    goto llvm_cbe_tmp__346;
  case 20u:
    goto llvm_cbe_tmp__347;
  case 21u:
    goto llvm_cbe_tmp__348;
  case 22u:
    goto llvm_cbe_tmp__349;
  case 23u:
    goto llvm_cbe_tmp__350;
  case 25u:
    goto llvm_cbe_tmp__351;
  case 24u:
    goto llvm_cbe_tmp__352;
  }

llvm_cbe_tmp__352:
  llvm_cbe_tmp__241 = llvm_cbe_tmp__5;
  llvm_cbe_tmp__242 = yytext;
  llvm_cbe_tmp__51 = (llvm_sub_u32((((uint32_t)(llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__241)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__242)))))), 1));
  llvm_cbe_tmp__243 = _ZL12yy_hold_char;
  llvm_cbe_tmp__244 = llvm_cbe_tmp__5;
  *llvm_cbe_tmp__244 = llvm_cbe_tmp__243;
  llvm_cbe_tmp__245 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__246 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__247 = *((&llvm_cbe_tmp__245[((int64_t)llvm_cbe_tmp__246)]));
  llvm_cbe_tmp__248 = *((&llvm_cbe_tmp__247->field11));
  if ((((llvm_cbe_tmp__248 == 0u)&1))) {
    goto llvm_cbe_tmp__353;
  } else {
    goto llvm_cbe_tmp__354;
  }

llvm_cbe_tmp__353:
  llvm_cbe_tmp__249 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__250 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__251 = *((&llvm_cbe_tmp__249[((int64_t)llvm_cbe_tmp__250)]));
  llvm_cbe_tmp__252 = *((&llvm_cbe_tmp__251->field4));
  _ZL10yy_n_chars = llvm_cbe_tmp__252;
  llvm_cbe_tmp__253 = yyin;
  llvm_cbe_tmp__254 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__255 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__256 = *((&llvm_cbe_tmp__254[((int64_t)llvm_cbe_tmp__255)]));
  *((&llvm_cbe_tmp__256->field0)) = llvm_cbe_tmp__253;
  llvm_cbe_tmp__257 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__258 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__259 = *((&llvm_cbe_tmp__257[((int64_t)llvm_cbe_tmp__258)]));
  *((&llvm_cbe_tmp__259->field11)) = 1;
  goto llvm_cbe_tmp__354;

llvm_cbe_tmp__354:
  llvm_cbe_tmp__260 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__261 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__262 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__263 = *((&llvm_cbe_tmp__261[((int64_t)llvm_cbe_tmp__262)]));
  llvm_cbe_tmp__264 = *((&llvm_cbe_tmp__263->field1));
  llvm_cbe_tmp__265 = _ZL10yy_n_chars;
  if ((((((uint64_t)llvm_cbe_tmp__260) <= ((uint64_t)((&llvm_cbe_tmp__264[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__265)))]))))&1))) {
    goto llvm_cbe_tmp__355;
  } else {
    goto llvm_cbe_tmp__356;
  }

llvm_cbe_tmp__356:
  llvm_cbe_tmp__277 = _ZL18yy_get_next_bufferv();
  switch (llvm_cbe_tmp__277) {
  default:
    goto llvm_cbe_tmp__357;
  case 1u:
    goto llvm_cbe_tmp__358;
  case 0u:
    goto llvm_cbe_tmp__359;
  case 2u:
    goto llvm_cbe_tmp__360;
  }

llvm_cbe_tmp__358:
  _ZL27yy_did_buffer_switch_on_eof = 0;
  llvm_cbe_tmp__278 = yywrap();
  if ((((llvm_cbe_tmp__278 != 0u)&1))) {
    goto llvm_cbe_tmp__361;
  } else {
    goto llvm_cbe_tmp__362;
  }

llvm_cbe_tmp__361:
  llvm_cbe_tmp__279 = yytext;
  _ZL10yy_c_buf_p = ((&(*llvm_cbe_tmp__279)));
  llvm_cbe_tmp__280 = _ZL8yy_start;
  llvm_cbe_tmp__7 = (llvm_add_u32((llvm_add_u32(24, (llvm_sdiv_u32((llvm_sub_u32(llvm_cbe_tmp__280, 1)), 2)))), 1));
  goto llvm_cbe_tmp__325;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__360:
  llvm_cbe_tmp__288 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__289 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__290 = *((&llvm_cbe_tmp__288[((int64_t)llvm_cbe_tmp__289)]));
  llvm_cbe_tmp__291 = *((&llvm_cbe_tmp__290->field1));
  llvm_cbe_tmp__292 = _ZL10yy_n_chars;
  _ZL10yy_c_buf_p = ((&llvm_cbe_tmp__291[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__292)))]));
  llvm_cbe_tmp__293 = _ZL21yy_get_previous_statev();
  llvm_cbe_tmp__4 = llvm_cbe_tmp__293;
  llvm_cbe_tmp__294 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__5 = llvm_cbe_tmp__294;
  llvm_cbe_tmp__295 = yytext;
  llvm_cbe_tmp__6 = ((&(*llvm_cbe_tmp__295)));
  goto llvm_cbe_tmp__322;

llvm_cbe_tmp__355:
  llvm_cbe_tmp__266 = yytext;
  llvm_cbe_tmp__267 = llvm_cbe_tmp__51;
  _ZL10yy_c_buf_p = ((&llvm_cbe_tmp__266[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__267)))]));
  llvm_cbe_tmp__268 = _ZL21yy_get_previous_statev();
  llvm_cbe_tmp__4 = llvm_cbe_tmp__268;
  llvm_cbe_tmp__269 = llvm_cbe_tmp__4;
  llvm_cbe_tmp__270 = _ZL16yy_try_NUL_transi(llvm_cbe_tmp__269);
  llvm_cbe_tmp__52 = llvm_cbe_tmp__270;
  llvm_cbe_tmp__271 = yytext;
  llvm_cbe_tmp__6 = ((&(*llvm_cbe_tmp__271)));
  llvm_cbe_tmp__272 = llvm_cbe_tmp__52;
  if ((((llvm_cbe_tmp__272 != 0u)&1))) {
    goto llvm_cbe_tmp__363;
  } else {
    goto llvm_cbe_tmp__364;
  }

llvm_cbe_tmp__364:
  llvm_cbe_tmp__276 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__5 = llvm_cbe_tmp__276;
  goto llvm_cbe_tmp__322;

llvm_cbe_tmp__327:
  llvm_cbe_tmp__112 = _ZL12yy_hold_char;
  llvm_cbe_tmp__113 = llvm_cbe_tmp__5;
  *llvm_cbe_tmp__113 = llvm_cbe_tmp__112;
  llvm_cbe_tmp__114 = _ZL22yy_last_accepting_cpos;
  llvm_cbe_tmp__5 = llvm_cbe_tmp__114;
  llvm_cbe_tmp__115 = _ZL23yy_last_accepting_state;
  llvm_cbe_tmp__4 = llvm_cbe_tmp__115;
  goto llvm_cbe_tmp__322;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__359:
  llvm_cbe_tmp__283 = yytext;
  llvm_cbe_tmp__284 = llvm_cbe_tmp__51;
  _ZL10yy_c_buf_p = ((&llvm_cbe_tmp__283[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__284)))]));
  llvm_cbe_tmp__285 = _ZL21yy_get_previous_statev();
  llvm_cbe_tmp__4 = llvm_cbe_tmp__285;
  llvm_cbe_tmp__286 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__5 = llvm_cbe_tmp__286;
  llvm_cbe_tmp__287 = yytext;
  llvm_cbe_tmp__6 = ((&(*llvm_cbe_tmp__287)));
  goto llvm_cbe_tmp__311;

llvm_cbe_tmp__363:
  llvm_cbe_tmp__273 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__274 = (&llvm_cbe_tmp__273[((int32_t)1)]);
  _ZL10yy_c_buf_p = llvm_cbe_tmp__274;
  llvm_cbe_tmp__5 = llvm_cbe_tmp__274;
  llvm_cbe_tmp__275 = llvm_cbe_tmp__52;
  llvm_cbe_tmp__4 = llvm_cbe_tmp__275;
  goto llvm_cbe_tmp__311;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__362:
  llvm_cbe_tmp__281 = _ZL27yy_did_buffer_switch_on_eof;
  if ((((llvm_cbe_tmp__281 != 0u)&1))) {
    goto llvm_cbe_tmp__365;
  } else {
    goto llvm_cbe_tmp__366;
  }

llvm_cbe_tmp__366:
  llvm_cbe_tmp__282 = yyin;
  _Z9yyrestartP8_IO_FILE(llvm_cbe_tmp__282);
  goto llvm_cbe_tmp__365;

llvm_cbe_tmp__365:
  goto llvm_cbe_tmp__367;

llvm_cbe_tmp__367:
  goto llvm_cbe_tmp__357;

llvm_cbe_tmp__357:
  goto llvm_cbe_tmp__368;

llvm_cbe_tmp__368:
  goto llvm_cbe_tmp__369;

llvm_cbe_tmp__350:
  goto llvm_cbe_tmp__370;

llvm_cbe_tmp__370:
  llvm_cbe_tmp__237 = yytext;
  llvm_cbe_tmp__238 = yyleng;
  llvm_cbe_tmp__239 = yyout;
  llvm_cbe_tmp__240 = fwrite(llvm_cbe_tmp__237, (((int64_t)(int32_t)llvm_cbe_tmp__238)), UINT64_C(1), llvm_cbe_tmp__239);
  if ((((llvm_cbe_tmp__240 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__371;
  } else {
    goto llvm_cbe_tmp__372;
  }

llvm_cbe_tmp__371:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__372:
  goto llvm_cbe_tmp__373;

llvm_cbe_tmp__373:
  goto llvm_cbe_tmp__369;

llvm_cbe_tmp__328:
  goto llvm_cbe_tmp__369;

llvm_cbe_tmp__369:
  goto llvm_cbe_tmp__310;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__329:
  llvm_cbe_tmp__116 = yytext;
  llvm_cbe_tmp__117 = printf(((&_OC_str.array[((int32_t)0)])), llvm_cbe_tmp__116, 258);
  llvm_cbe_tmp__118 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__12 = ((1) & 1);
  llvm_cbe_tmp__119 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__118);
  llvm_cbe_tmp__120 = yytext;
  llvm_cbe_tmp__121 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__9));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__119, llvm_cbe_tmp__120, (((int64_t)(int32_t)llvm_cbe_tmp__121)), (&llvm_cbe_tmp__9));
  goto llvm_cbe_tmp__374;

llvm_cbe_tmp__374:
  llvm_cbe_tmp__12 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__119;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__9));
  llvm_cbe_tmp__3 = 258;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__330:
  llvm_cbe_tmp__122 = yytext;
  llvm_cbe_tmp__123 = printf(((&_OC_str_OC_1.array[((int32_t)0)])), llvm_cbe_tmp__122, 260);
  llvm_cbe_tmp__124 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__14 = ((1) & 1);
  llvm_cbe_tmp__125 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__124);
  llvm_cbe_tmp__126 = yytext;
  llvm_cbe_tmp__127 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__13));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__125, llvm_cbe_tmp__126, (((int64_t)(int32_t)llvm_cbe_tmp__127)), (&llvm_cbe_tmp__13));
  goto llvm_cbe_tmp__376;

llvm_cbe_tmp__376:
  llvm_cbe_tmp__14 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__125;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__13));
  llvm_cbe_tmp__3 = 260;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__331:
  llvm_cbe_tmp__128 = yytext;
  llvm_cbe_tmp__129 = printf(((&_OC_str_OC_1.array[((int32_t)0)])), llvm_cbe_tmp__128, 259);
  llvm_cbe_tmp__130 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__16 = ((1) & 1);
  llvm_cbe_tmp__131 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__130);
  llvm_cbe_tmp__132 = yytext;
  llvm_cbe_tmp__133 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__15));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__131, llvm_cbe_tmp__132, (((int64_t)(int32_t)llvm_cbe_tmp__133)), (&llvm_cbe_tmp__15));
  goto llvm_cbe_tmp__377;

llvm_cbe_tmp__377:
  llvm_cbe_tmp__16 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__131;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__15));
  llvm_cbe_tmp__3 = 259;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__332:
  llvm_cbe_tmp__134 = yytext;
  *((uint32_t*)(&yylval)) = 267;
  llvm_cbe_tmp__135 = printf(((&_OC_str_OC_2.array[((int32_t)0)])), llvm_cbe_tmp__134, 267);
  llvm_cbe_tmp__136 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__18 = ((1) & 1);
  llvm_cbe_tmp__137 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__136);
  llvm_cbe_tmp__138 = yytext;
  llvm_cbe_tmp__139 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__17));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__137, llvm_cbe_tmp__138, (((int64_t)(int32_t)llvm_cbe_tmp__139)), (&llvm_cbe_tmp__17));
  goto llvm_cbe_tmp__378;

llvm_cbe_tmp__378:
  llvm_cbe_tmp__18 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__137;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__17));
  *((uint32_t*)(&yylval)) = 267;
  llvm_cbe_tmp__3 = 267;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__333:
  llvm_cbe_tmp__140 = yytext;
  *((uint32_t*)(&yylval)) = 261;
  llvm_cbe_tmp__141 = printf(((&_OC_str_OC_3.array[((int32_t)0)])), llvm_cbe_tmp__140, 261);
  llvm_cbe_tmp__142 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__20 = ((1) & 1);
  llvm_cbe_tmp__143 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__142);
  llvm_cbe_tmp__144 = yytext;
  llvm_cbe_tmp__145 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__19));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__143, llvm_cbe_tmp__144, (((int64_t)(int32_t)llvm_cbe_tmp__145)), (&llvm_cbe_tmp__19));
  goto llvm_cbe_tmp__379;

llvm_cbe_tmp__379:
  llvm_cbe_tmp__20 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__143;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__19));
  *((uint32_t*)(&yylval)) = 261;
  llvm_cbe_tmp__3 = 261;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__334:
  llvm_cbe_tmp__146 = yytext;
  *((uint32_t*)(&yylval)) = 262;
  llvm_cbe_tmp__147 = printf(((&_OC_str_OC_4.array[((int32_t)0)])), llvm_cbe_tmp__146, 262);
  llvm_cbe_tmp__148 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__22 = ((1) & 1);
  llvm_cbe_tmp__149 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__148);
  llvm_cbe_tmp__150 = yytext;
  llvm_cbe_tmp__151 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__21));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__149, llvm_cbe_tmp__150, (((int64_t)(int32_t)llvm_cbe_tmp__151)), (&llvm_cbe_tmp__21));
  goto llvm_cbe_tmp__380;

llvm_cbe_tmp__380:
  llvm_cbe_tmp__22 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__149;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__21));
  *((uint32_t*)(&yylval)) = 262;
  llvm_cbe_tmp__3 = 262;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__335:
  llvm_cbe_tmp__152 = yytext;
  *((uint32_t*)(&yylval)) = 263;
  llvm_cbe_tmp__153 = printf(((&_OC_str_OC_5.array[((int32_t)0)])), llvm_cbe_tmp__152, 263);
  llvm_cbe_tmp__154 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__24 = ((1) & 1);
  llvm_cbe_tmp__155 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__154);
  llvm_cbe_tmp__156 = yytext;
  llvm_cbe_tmp__157 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__23));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__155, llvm_cbe_tmp__156, (((int64_t)(int32_t)llvm_cbe_tmp__157)), (&llvm_cbe_tmp__23));
  goto llvm_cbe_tmp__381;

llvm_cbe_tmp__381:
  llvm_cbe_tmp__24 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__155;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__23));
  *((uint32_t*)(&yylval)) = 263;
  llvm_cbe_tmp__3 = 263;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__336:
  llvm_cbe_tmp__158 = yytext;
  *((uint32_t*)(&yylval)) = 264;
  llvm_cbe_tmp__159 = printf(((&_OC_str_OC_6.array[((int32_t)0)])), llvm_cbe_tmp__158, 264);
  llvm_cbe_tmp__160 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__26 = ((1) & 1);
  llvm_cbe_tmp__161 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__160);
  llvm_cbe_tmp__162 = yytext;
  llvm_cbe_tmp__163 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__25));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__161, llvm_cbe_tmp__162, (((int64_t)(int32_t)llvm_cbe_tmp__163)), (&llvm_cbe_tmp__25));
  goto llvm_cbe_tmp__382;

llvm_cbe_tmp__382:
  llvm_cbe_tmp__26 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__161;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__25));
  *((uint32_t*)(&yylval)) = 264;
  llvm_cbe_tmp__3 = 264;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__337:
  llvm_cbe_tmp__164 = yytext;
  *((uint32_t*)(&yylval)) = 265;
  llvm_cbe_tmp__165 = printf(((&_OC_str_OC_7.array[((int32_t)0)])), llvm_cbe_tmp__164, 265);
  llvm_cbe_tmp__166 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__28 = ((1) & 1);
  llvm_cbe_tmp__167 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__166);
  llvm_cbe_tmp__168 = yytext;
  llvm_cbe_tmp__169 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__27));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__167, llvm_cbe_tmp__168, (((int64_t)(int32_t)llvm_cbe_tmp__169)), (&llvm_cbe_tmp__27));
  goto llvm_cbe_tmp__383;

llvm_cbe_tmp__383:
  llvm_cbe_tmp__28 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__167;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__27));
  *((uint32_t*)(&yylval)) = 265;
  llvm_cbe_tmp__3 = 265;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__338:
  llvm_cbe_tmp__170 = yytext;
  *((uint32_t*)(&yylval)) = 266;
  llvm_cbe_tmp__171 = printf(((&_OC_str_OC_8.array[((int32_t)0)])), llvm_cbe_tmp__170, 266);
  llvm_cbe_tmp__172 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__30 = ((1) & 1);
  llvm_cbe_tmp__173 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__172);
  llvm_cbe_tmp__174 = yytext;
  llvm_cbe_tmp__175 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__29));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__173, llvm_cbe_tmp__174, (((int64_t)(int32_t)llvm_cbe_tmp__175)), (&llvm_cbe_tmp__29));
  goto llvm_cbe_tmp__384;

llvm_cbe_tmp__384:
  llvm_cbe_tmp__30 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__173;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__29));
  *((uint32_t*)(&yylval)) = 266;
  llvm_cbe_tmp__3 = 266;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__339:
  llvm_cbe_tmp__176 = yytext;
  *((uint32_t*)(&yylval)) = 268;
  llvm_cbe_tmp__177 = printf(((&_OC_str_OC_9.array[((int32_t)0)])), llvm_cbe_tmp__176, 268);
  llvm_cbe_tmp__178 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__32 = ((1) & 1);
  llvm_cbe_tmp__179 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__178);
  llvm_cbe_tmp__180 = yytext;
  llvm_cbe_tmp__181 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__31));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__179, llvm_cbe_tmp__180, (((int64_t)(int32_t)llvm_cbe_tmp__181)), (&llvm_cbe_tmp__31));
  goto llvm_cbe_tmp__385;

llvm_cbe_tmp__385:
  llvm_cbe_tmp__32 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__179;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__31));
  *((uint32_t*)(&yylval)) = 268;
  llvm_cbe_tmp__3 = 268;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__340:
  llvm_cbe_tmp__182 = yytext;
  *((uint32_t*)(&yylval)) = 269;
  llvm_cbe_tmp__183 = printf(((&_OC_str_OC_10.array[((int32_t)0)])), llvm_cbe_tmp__182, 269);
  llvm_cbe_tmp__184 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__34 = ((1) & 1);
  llvm_cbe_tmp__185 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__184);
  llvm_cbe_tmp__186 = yytext;
  llvm_cbe_tmp__187 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__33));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__185, llvm_cbe_tmp__186, (((int64_t)(int32_t)llvm_cbe_tmp__187)), (&llvm_cbe_tmp__33));
  goto llvm_cbe_tmp__386;

llvm_cbe_tmp__386:
  llvm_cbe_tmp__34 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__185;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__33));
  *((uint32_t*)(&yylval)) = 269;
  llvm_cbe_tmp__3 = 269;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__341:
  llvm_cbe_tmp__188 = yytext;
  *((uint32_t*)(&yylval)) = 270;
  llvm_cbe_tmp__189 = printf(((&_OC_str_OC_11.array[((int32_t)0)])), llvm_cbe_tmp__188, 270);
  llvm_cbe_tmp__190 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__36 = ((1) & 1);
  llvm_cbe_tmp__191 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__190);
  llvm_cbe_tmp__192 = yytext;
  llvm_cbe_tmp__193 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__35));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__191, llvm_cbe_tmp__192, (((int64_t)(int32_t)llvm_cbe_tmp__193)), (&llvm_cbe_tmp__35));
  goto llvm_cbe_tmp__387;

llvm_cbe_tmp__387:
  llvm_cbe_tmp__36 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__191;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__35));
  *((uint32_t*)(&yylval)) = 270;
  llvm_cbe_tmp__3 = 270;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__342:
  llvm_cbe_tmp__194 = yytext;
  *((uint32_t*)(&yylval)) = 271;
  llvm_cbe_tmp__195 = printf(((&_OC_str_OC_12.array[((int32_t)0)])), llvm_cbe_tmp__194, 271);
  llvm_cbe_tmp__196 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__38 = ((1) & 1);
  llvm_cbe_tmp__197 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__196);
  llvm_cbe_tmp__198 = yytext;
  llvm_cbe_tmp__199 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__37));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__197, llvm_cbe_tmp__198, (((int64_t)(int32_t)llvm_cbe_tmp__199)), (&llvm_cbe_tmp__37));
  goto llvm_cbe_tmp__388;

llvm_cbe_tmp__388:
  llvm_cbe_tmp__38 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__197;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__37));
  *((uint32_t*)(&yylval)) = 271;
  llvm_cbe_tmp__3 = 271;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__343:
  llvm_cbe_tmp__200 = yytext;
  *((uint32_t*)(&yylval)) = 273;
  llvm_cbe_tmp__201 = printf(((&_OC_str_OC_13.array[((int32_t)0)])), llvm_cbe_tmp__200, 273);
  llvm_cbe_tmp__202 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__40 = ((1) & 1);
  llvm_cbe_tmp__203 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__202);
  llvm_cbe_tmp__204 = yytext;
  llvm_cbe_tmp__205 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__39));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__203, llvm_cbe_tmp__204, (((int64_t)(int32_t)llvm_cbe_tmp__205)), (&llvm_cbe_tmp__39));
  goto llvm_cbe_tmp__389;

llvm_cbe_tmp__389:
  llvm_cbe_tmp__40 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__203;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__39));
  *((uint32_t*)(&yylval)) = 273;
  llvm_cbe_tmp__3 = 273;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__344:
  llvm_cbe_tmp__206 = yytext;
  *((uint32_t*)(&yylval)) = 272;
  llvm_cbe_tmp__207 = printf(((&_OC_str_OC_14.array[((int32_t)0)])), llvm_cbe_tmp__206, 272);
  llvm_cbe_tmp__208 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__42 = ((1) & 1);
  llvm_cbe_tmp__209 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__208);
  llvm_cbe_tmp__210 = yytext;
  llvm_cbe_tmp__211 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__41));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__209, llvm_cbe_tmp__210, (((int64_t)(int32_t)llvm_cbe_tmp__211)), (&llvm_cbe_tmp__41));
  goto llvm_cbe_tmp__390;

llvm_cbe_tmp__390:
  llvm_cbe_tmp__42 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__209;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__41));
  *((uint32_t*)(&yylval)) = 272;
  llvm_cbe_tmp__3 = 272;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__345:
  llvm_cbe_tmp__212 = yytext;
  *((uint32_t*)(&yylval)) = 274;
  llvm_cbe_tmp__213 = printf(((&_OC_str_OC_15.array[((int32_t)0)])), llvm_cbe_tmp__212, 274);
  llvm_cbe_tmp__214 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__44 = ((1) & 1);
  llvm_cbe_tmp__215 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__214);
  llvm_cbe_tmp__216 = yytext;
  llvm_cbe_tmp__217 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__43));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__215, llvm_cbe_tmp__216, (((int64_t)(int32_t)llvm_cbe_tmp__217)), (&llvm_cbe_tmp__43));
  goto llvm_cbe_tmp__391;

llvm_cbe_tmp__391:
  llvm_cbe_tmp__44 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__215;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__43));
  *((uint32_t*)(&yylval)) = 274;
  llvm_cbe_tmp__3 = 274;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__346:
  llvm_cbe_tmp__218 = yytext;
  *((uint32_t*)(&yylval)) = 275;
  llvm_cbe_tmp__219 = printf(((&_OC_str_OC_16.array[((int32_t)0)])), llvm_cbe_tmp__218, 275);
  llvm_cbe_tmp__220 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__46 = ((1) & 1);
  llvm_cbe_tmp__221 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__220);
  llvm_cbe_tmp__222 = yytext;
  llvm_cbe_tmp__223 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__45));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__221, llvm_cbe_tmp__222, (((int64_t)(int32_t)llvm_cbe_tmp__223)), (&llvm_cbe_tmp__45));
  goto llvm_cbe_tmp__392;

llvm_cbe_tmp__392:
  llvm_cbe_tmp__46 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__221;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__45));
  *((uint32_t*)(&yylval)) = 275;
  llvm_cbe_tmp__3 = 275;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__347:
  llvm_cbe_tmp__224 = yytext;
  *((uint32_t*)(&yylval)) = 276;
  llvm_cbe_tmp__225 = printf(((&_OC_str_OC_17.array[((int32_t)0)])), llvm_cbe_tmp__224, 276);
  llvm_cbe_tmp__226 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__48 = ((1) & 1);
  llvm_cbe_tmp__227 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__226);
  llvm_cbe_tmp__228 = yytext;
  llvm_cbe_tmp__229 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__47));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__227, llvm_cbe_tmp__228, (((int64_t)(int32_t)llvm_cbe_tmp__229)), (&llvm_cbe_tmp__47));
  goto llvm_cbe_tmp__393;

llvm_cbe_tmp__393:
  llvm_cbe_tmp__48 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__227;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__47));
  *((uint32_t*)(&yylval)) = 276;
  llvm_cbe_tmp__3 = 276;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__348:
  llvm_cbe_tmp__230 = yytext;
  *((uint32_t*)(&yylval)) = 277;
  llvm_cbe_tmp__231 = printf(((&_OC_str_OC_18.array[((int32_t)0)])), llvm_cbe_tmp__230, 277);
  llvm_cbe_tmp__232 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__50 = ((1) & 1);
  llvm_cbe_tmp__233 = ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)llvm_cbe_tmp__232);
  llvm_cbe_tmp__234 = yytext;
  llvm_cbe_tmp__235 = yyleng;
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__49));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(llvm_cbe_tmp__233, llvm_cbe_tmp__234, (((int64_t)(int32_t)llvm_cbe_tmp__235)), (&llvm_cbe_tmp__49));
  goto llvm_cbe_tmp__394;

llvm_cbe_tmp__394:
  llvm_cbe_tmp__50 = ((0) & 1);
  *((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)(&yylval)) = llvm_cbe_tmp__233;
  _ZNSaIcED1Ev((&llvm_cbe_tmp__49));
  *((uint32_t*)(&yylval)) = 277;
  llvm_cbe_tmp__3 = 277;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__349:
  llvm_cbe_tmp__236 = printf(((&_OC_str_OC_19.array[((int32_t)0)])));
  llvm_cbe_tmp__3 = 0;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__351:
  llvm_cbe_tmp__3 = 0;
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__326:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_20.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__375:
  llvm_cbe_tmp__296 = llvm_cbe_tmp__3;
  return llvm_cbe_tmp__296;
}


static void _ZL21yyensure_buffer_stackv(void) {
  uint64_t llvm_cbe_tmp__395;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__396;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__397;
  uint64_t llvm_cbe_tmp__398;
  uint8_t* llvm_cbe_tmp__399;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__400;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__401;
  uint64_t llvm_cbe_tmp__402;
  uint8_t* llvm_cbe_tmp__403;
  uint64_t llvm_cbe_tmp__404;
  uint64_t llvm_cbe_tmp__405;
  uint64_t llvm_cbe_tmp__406;
  uint64_t llvm_cbe_tmp__407;
  uint64_t llvm_cbe_tmp__408;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__409;
  uint64_t llvm_cbe_tmp__410;
  uint8_t* llvm_cbe_tmp__411;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__412;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__413;
  uint64_t llvm_cbe_tmp__414;
  uint64_t llvm_cbe_tmp__415;
  uint8_t* llvm_cbe_tmp__416;
  uint64_t llvm_cbe_tmp__417;

  llvm_cbe_tmp__397 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__397 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__418;
  } else {
    goto llvm_cbe_tmp__419;
  }

llvm_cbe_tmp__419:
  llvm_cbe_tmp__395 = UINT64_C(1);
  llvm_cbe_tmp__398 = llvm_cbe_tmp__395;
  llvm_cbe_tmp__399 = _Z7yyallocm((llvm_mul_u64(llvm_cbe_tmp__398, UINT64_C(8))));
  _ZL15yy_buffer_stack = (((struct l_struct_struct_OC_yy_buffer_state**)llvm_cbe_tmp__399));
  llvm_cbe_tmp__400 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__400 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__420;
  } else {
    goto llvm_cbe_tmp__421;
  }

llvm_cbe_tmp__421:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_29.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__420:
  llvm_cbe_tmp__401 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__402 = llvm_cbe_tmp__395;
  llvm_cbe_tmp__403 = memset((((uint8_t*)llvm_cbe_tmp__401)), 0, (llvm_mul_u64(llvm_cbe_tmp__402, UINT64_C(8))));
  llvm_cbe_tmp__404 = llvm_cbe_tmp__395;
  _ZL19yy_buffer_stack_max = llvm_cbe_tmp__404;
  _ZL19yy_buffer_stack_top = UINT64_C(0);
  goto llvm_cbe_tmp__422;

llvm_cbe_tmp__418:
  llvm_cbe_tmp__405 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__406 = _ZL19yy_buffer_stack_max;
  if ((((((uint64_t)llvm_cbe_tmp__405) >= ((uint64_t)(llvm_sub_u64(llvm_cbe_tmp__406, UINT64_C(1)))))&1))) {
    goto llvm_cbe_tmp__423;
  } else {
    goto llvm_cbe_tmp__422;
  }

llvm_cbe_tmp__423:
  llvm_cbe_tmp__396 = UINT64_C(8);
  llvm_cbe_tmp__407 = _ZL19yy_buffer_stack_max;
  llvm_cbe_tmp__408 = llvm_cbe_tmp__396;
  llvm_cbe_tmp__395 = (llvm_add_u64(llvm_cbe_tmp__407, llvm_cbe_tmp__408));
  llvm_cbe_tmp__409 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__410 = llvm_cbe_tmp__395;
  llvm_cbe_tmp__411 = _Z9yyreallocPvm((((uint8_t*)llvm_cbe_tmp__409)), (llvm_mul_u64(llvm_cbe_tmp__410, UINT64_C(8))));
  _ZL15yy_buffer_stack = (((struct l_struct_struct_OC_yy_buffer_state**)llvm_cbe_tmp__411));
  llvm_cbe_tmp__412 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__412 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__424;
  } else {
    goto llvm_cbe_tmp__425;
  }

llvm_cbe_tmp__425:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_29.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__424:
  llvm_cbe_tmp__413 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__414 = _ZL19yy_buffer_stack_max;
  llvm_cbe_tmp__415 = llvm_cbe_tmp__396;
  llvm_cbe_tmp__416 = memset((((uint8_t*)((&llvm_cbe_tmp__413[((int64_t)llvm_cbe_tmp__414)])))), 0, (llvm_mul_u64(llvm_cbe_tmp__415, UINT64_C(8))));
  llvm_cbe_tmp__417 = llvm_cbe_tmp__395;
  _ZL19yy_buffer_stack_max = llvm_cbe_tmp__417;
  goto llvm_cbe_tmp__422;

llvm_cbe_tmp__422:
  return;
}


struct l_struct_struct_OC_yy_buffer_state* _Z16yy_create_bufferP8_IO_FILEi(struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__426, uint32_t llvm_cbe_tmp__427) {
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__428;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__429;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__430;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__431;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__432;
  uint32_t llvm_cbe_tmp__433;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__434;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__435;
  uint32_t llvm_cbe_tmp__436;
  uint8_t* llvm_cbe_tmp__437;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__438;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__439;
  uint8_t* llvm_cbe_tmp__440;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__441;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__442;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__443;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__444;

  llvm_cbe_tmp__428 = llvm_cbe_tmp__426;
  llvm_cbe_tmp__429 = llvm_cbe_tmp__427;
  llvm_cbe_tmp__431 = _Z7yyallocm(UINT64_C(64));
  llvm_cbe_tmp__430 = (((struct l_struct_struct_OC_yy_buffer_state*)llvm_cbe_tmp__431));
  llvm_cbe_tmp__432 = llvm_cbe_tmp__430;
  if ((((llvm_cbe_tmp__432 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__445;
  } else {
    goto llvm_cbe_tmp__446;
  }

llvm_cbe_tmp__446:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_21.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__445:
  llvm_cbe_tmp__433 = llvm_cbe_tmp__429;
  llvm_cbe_tmp__434 = llvm_cbe_tmp__430;
  *((&llvm_cbe_tmp__434->field3)) = llvm_cbe_tmp__433;
  llvm_cbe_tmp__435 = llvm_cbe_tmp__430;
  llvm_cbe_tmp__436 = *((&llvm_cbe_tmp__435->field3));
  llvm_cbe_tmp__437 = _Z7yyallocm((((int64_t)(int32_t)(llvm_add_u32(llvm_cbe_tmp__436, 2)))));
  llvm_cbe_tmp__438 = llvm_cbe_tmp__430;
  *((&llvm_cbe_tmp__438->field1)) = llvm_cbe_tmp__437;
  llvm_cbe_tmp__439 = llvm_cbe_tmp__430;
  llvm_cbe_tmp__440 = *((&llvm_cbe_tmp__439->field1));
  if ((((llvm_cbe_tmp__440 != ((uint8_t*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__447;
  } else {
    goto llvm_cbe_tmp__448;
  }

llvm_cbe_tmp__448:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_21.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__447:
  llvm_cbe_tmp__441 = llvm_cbe_tmp__430;
  *((&llvm_cbe_tmp__441->field5)) = 1;
  llvm_cbe_tmp__442 = llvm_cbe_tmp__430;
  llvm_cbe_tmp__443 = llvm_cbe_tmp__428;
  _ZL14yy_init_bufferP15yy_buffer_stateP8_IO_FILE(llvm_cbe_tmp__442, llvm_cbe_tmp__443);
  llvm_cbe_tmp__444 = llvm_cbe_tmp__430;
  return llvm_cbe_tmp__444;
}


static void _ZL20yy_load_buffer_statev(void) {
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__449;
  uint64_t llvm_cbe_tmp__450;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__451;
  uint32_t llvm_cbe_tmp__452;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__453;
  uint64_t llvm_cbe_tmp__454;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__455;
  uint8_t* llvm_cbe_tmp__456;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__457;
  uint64_t llvm_cbe_tmp__458;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__459;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__460;
  uint8_t* llvm_cbe_tmp__461;
  uint8_t llvm_cbe_tmp__462;

  llvm_cbe_tmp__449 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__450 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__451 = *((&llvm_cbe_tmp__449[((int64_t)llvm_cbe_tmp__450)]));
  llvm_cbe_tmp__452 = *((&llvm_cbe_tmp__451->field4));
  _ZL10yy_n_chars = llvm_cbe_tmp__452;
  llvm_cbe_tmp__453 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__454 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__455 = *((&llvm_cbe_tmp__453[((int64_t)llvm_cbe_tmp__454)]));
  llvm_cbe_tmp__456 = *((&llvm_cbe_tmp__455->field2));
  _ZL10yy_c_buf_p = llvm_cbe_tmp__456;
  yytext = llvm_cbe_tmp__456;
  llvm_cbe_tmp__457 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__458 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__459 = *((&llvm_cbe_tmp__457[((int64_t)llvm_cbe_tmp__458)]));
  llvm_cbe_tmp__460 = *((&llvm_cbe_tmp__459->field0));
  yyin = llvm_cbe_tmp__460;
  llvm_cbe_tmp__461 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__462 = *llvm_cbe_tmp__461;
  _ZL12yy_hold_char = llvm_cbe_tmp__462;
}


static uint32_t _ZL21yy_get_previous_statev(void) {
  uint32_t llvm_cbe_tmp__463;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__464;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__465;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__466;
  uint8_t* llvm_cbe_tmp__467;
  uint8_t* llvm_cbe_tmp__468;
  uint8_t* llvm_cbe_tmp__469;
  uint8_t* llvm_cbe_tmp__470;
  uint8_t llvm_cbe_tmp__471;
  uint8_t* llvm_cbe_tmp__472;
  uint8_t llvm_cbe_tmp__473;
  uint8_t llvm_cbe_tmp__474;
  uint32_t llvm_cbe_tmp__475;
  uint32_t llvm_cbe_tmp__476;
  uint32_t llvm_cbe_tmp__476__PHI_TEMPORARY;
  uint32_t llvm_cbe_tmp__477;
  uint16_t llvm_cbe_tmp__478;
  uint32_t llvm_cbe_tmp__479;
  uint8_t* llvm_cbe_tmp__480;
  uint32_t llvm_cbe_tmp__481;
  uint16_t llvm_cbe_tmp__482;
  uint8_t llvm_cbe_tmp__483;
  uint16_t llvm_cbe_tmp__484;
  uint32_t llvm_cbe_tmp__485;
  uint32_t llvm_cbe_tmp__486;
  uint16_t llvm_cbe_tmp__487;
  uint32_t llvm_cbe_tmp__488;
  uint8_t llvm_cbe_tmp__489;
  uint8_t llvm_cbe_tmp__490;
  uint32_t llvm_cbe_tmp__491;
  uint16_t llvm_cbe_tmp__492;
  uint8_t llvm_cbe_tmp__493;
  uint16_t llvm_cbe_tmp__494;
  uint8_t* llvm_cbe_tmp__495;
  uint32_t llvm_cbe_tmp__496;

  llvm_cbe_tmp__466 = _ZL8yy_start;
  llvm_cbe_tmp__463 = llvm_cbe_tmp__466;
  llvm_cbe_tmp__467 = yytext;
  llvm_cbe_tmp__464 = ((&(*llvm_cbe_tmp__467)));
  goto llvm_cbe_tmp__497;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__497:
  llvm_cbe_tmp__468 = llvm_cbe_tmp__464;
  llvm_cbe_tmp__469 = _ZL10yy_c_buf_p;
  if ((((((uint64_t)llvm_cbe_tmp__468) < ((uint64_t)llvm_cbe_tmp__469))&1))) {
    goto llvm_cbe_tmp__498;
  } else {
    goto llvm_cbe_tmp__499;
  }

llvm_cbe_tmp__498:
  llvm_cbe_tmp__470 = llvm_cbe_tmp__464;
  llvm_cbe_tmp__471 = *llvm_cbe_tmp__470;
  if ((((llvm_cbe_tmp__471 != ((uint8_t)0))&1))) {
    goto llvm_cbe_tmp__500;
  } else {
    goto llvm_cbe_tmp__501;
  }

llvm_cbe_tmp__501:
  llvm_cbe_tmp__476__PHI_TEMPORARY = 1;   /* for PHI node */
  goto llvm_cbe_tmp__502;

llvm_cbe_tmp__500:
  llvm_cbe_tmp__472 = llvm_cbe_tmp__464;
  llvm_cbe_tmp__473 = *llvm_cbe_tmp__472;
  llvm_cbe_tmp__474 = *((&_ZL5yy_ec.array[((int64_t)(((uint64_t)(uint8_t)llvm_cbe_tmp__473)))]));
  llvm_cbe_tmp__475 = ((uint32_t)(uint8_t)llvm_cbe_tmp__474);
  llvm_cbe_tmp__476__PHI_TEMPORARY = llvm_cbe_tmp__475;   /* for PHI node */
  goto llvm_cbe_tmp__502;

llvm_cbe_tmp__502:
  llvm_cbe_tmp__476 = llvm_cbe_tmp__476__PHI_TEMPORARY;
  llvm_cbe_tmp__465 = (((uint8_t)llvm_cbe_tmp__476));
  llvm_cbe_tmp__477 = llvm_cbe_tmp__463;
  llvm_cbe_tmp__478 = *((&_ZL9yy_accept.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__477)))]));
  if ((((llvm_cbe_tmp__478 != ((uint16_t)0))&1))) {
    goto llvm_cbe_tmp__503;
  } else {
    goto llvm_cbe_tmp__504;
  }

llvm_cbe_tmp__503:
  llvm_cbe_tmp__479 = llvm_cbe_tmp__463;
  _ZL23yy_last_accepting_state = llvm_cbe_tmp__479;
  llvm_cbe_tmp__480 = llvm_cbe_tmp__464;
  _ZL22yy_last_accepting_cpos = llvm_cbe_tmp__480;
  goto llvm_cbe_tmp__504;

llvm_cbe_tmp__504:
  goto llvm_cbe_tmp__505;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__505:
  llvm_cbe_tmp__481 = llvm_cbe_tmp__463;
  llvm_cbe_tmp__482 = *((&_ZL7yy_base.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__481)))]));
  llvm_cbe_tmp__483 = llvm_cbe_tmp__465;
  llvm_cbe_tmp__484 = *((&_ZL6yy_chk.array[((int64_t)(((int64_t)(int32_t)(llvm_add_u32((((int32_t)(int16_t)llvm_cbe_tmp__482)), (((uint32_t)(uint8_t)llvm_cbe_tmp__483)))))))]));
  llvm_cbe_tmp__485 = llvm_cbe_tmp__463;
  if (((((((int32_t)(int16_t)llvm_cbe_tmp__484)) != llvm_cbe_tmp__485)&1))) {
    goto llvm_cbe_tmp__506;
  } else {
    goto llvm_cbe_tmp__507;
  }

llvm_cbe_tmp__506:
  llvm_cbe_tmp__486 = llvm_cbe_tmp__463;
  llvm_cbe_tmp__487 = *((&_ZL6yy_def.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__486)))]));
  llvm_cbe_tmp__463 = (((int32_t)(int16_t)llvm_cbe_tmp__487));
  llvm_cbe_tmp__488 = llvm_cbe_tmp__463;
  if ((((((int32_t)llvm_cbe_tmp__488) >= ((int32_t)33u))&1))) {
    goto llvm_cbe_tmp__508;
  } else {
    goto llvm_cbe_tmp__509;
  }

llvm_cbe_tmp__508:
  llvm_cbe_tmp__489 = llvm_cbe_tmp__465;
  llvm_cbe_tmp__490 = *((&_ZL7yy_meta.array[((int64_t)(((uint64_t)(uint8_t)llvm_cbe_tmp__489)))]));
  llvm_cbe_tmp__465 = llvm_cbe_tmp__490;
  goto llvm_cbe_tmp__509;

llvm_cbe_tmp__509:
  goto llvm_cbe_tmp__505;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__507:
  llvm_cbe_tmp__491 = llvm_cbe_tmp__463;
  llvm_cbe_tmp__492 = *((&_ZL7yy_base.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__491)))]));
  llvm_cbe_tmp__493 = llvm_cbe_tmp__465;
  llvm_cbe_tmp__494 = *((&_ZL6yy_nxt.array[((int64_t)(((int64_t)(int32_t)(llvm_add_u32((((int32_t)(int16_t)llvm_cbe_tmp__492)), (((uint32_t)(uint8_t)llvm_cbe_tmp__493)))))))]));
  llvm_cbe_tmp__463 = (((int32_t)(int16_t)llvm_cbe_tmp__494));
  goto llvm_cbe_tmp__510;

llvm_cbe_tmp__510:
  llvm_cbe_tmp__495 = llvm_cbe_tmp__464;
  llvm_cbe_tmp__464 = ((&llvm_cbe_tmp__495[((int32_t)1)]));
  goto llvm_cbe_tmp__497;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__499:
  llvm_cbe_tmp__496 = llvm_cbe_tmp__463;
  return llvm_cbe_tmp__496;
}


static uint32_t _ZL16yy_try_NUL_transi(uint32_t llvm_cbe_tmp__511) {
  uint32_t llvm_cbe_tmp__512;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__513;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__514;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__515;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__516;
  uint32_t llvm_cbe_tmp__517;
  uint16_t llvm_cbe_tmp__518;
  uint32_t llvm_cbe_tmp__519;
  uint8_t* llvm_cbe_tmp__520;
  uint32_t llvm_cbe_tmp__521;
  uint16_t llvm_cbe_tmp__522;
  uint8_t llvm_cbe_tmp__523;
  uint16_t llvm_cbe_tmp__524;
  uint32_t llvm_cbe_tmp__525;
  uint32_t llvm_cbe_tmp__526;
  uint16_t llvm_cbe_tmp__527;
  uint32_t llvm_cbe_tmp__528;
  uint8_t llvm_cbe_tmp__529;
  uint8_t llvm_cbe_tmp__530;
  uint32_t llvm_cbe_tmp__531;
  uint16_t llvm_cbe_tmp__532;
  uint8_t llvm_cbe_tmp__533;
  uint16_t llvm_cbe_tmp__534;
  uint32_t llvm_cbe_tmp__535;
  uint32_t llvm_cbe_tmp__536;
  uint32_t llvm_cbe_tmp__537;
  uint32_t llvm_cbe_tmp__538;
  uint32_t llvm_cbe_tmp__538__PHI_TEMPORARY;

  llvm_cbe_tmp__512 = llvm_cbe_tmp__511;
  llvm_cbe_tmp__516 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__514 = llvm_cbe_tmp__516;
  llvm_cbe_tmp__515 = 1;
  llvm_cbe_tmp__517 = llvm_cbe_tmp__512;
  llvm_cbe_tmp__518 = *((&_ZL9yy_accept.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__517)))]));
  if ((((llvm_cbe_tmp__518 != ((uint16_t)0))&1))) {
    goto llvm_cbe_tmp__539;
  } else {
    goto llvm_cbe_tmp__540;
  }

llvm_cbe_tmp__539:
  llvm_cbe_tmp__519 = llvm_cbe_tmp__512;
  _ZL23yy_last_accepting_state = llvm_cbe_tmp__519;
  llvm_cbe_tmp__520 = llvm_cbe_tmp__514;
  _ZL22yy_last_accepting_cpos = llvm_cbe_tmp__520;
  goto llvm_cbe_tmp__540;

llvm_cbe_tmp__540:
  goto llvm_cbe_tmp__541;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__541:
  llvm_cbe_tmp__521 = llvm_cbe_tmp__512;
  llvm_cbe_tmp__522 = *((&_ZL7yy_base.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__521)))]));
  llvm_cbe_tmp__523 = llvm_cbe_tmp__515;
  llvm_cbe_tmp__524 = *((&_ZL6yy_chk.array[((int64_t)(((int64_t)(int32_t)(llvm_add_u32((((int32_t)(int16_t)llvm_cbe_tmp__522)), (((uint32_t)(uint8_t)llvm_cbe_tmp__523)))))))]));
  llvm_cbe_tmp__525 = llvm_cbe_tmp__512;
  if (((((((int32_t)(int16_t)llvm_cbe_tmp__524)) != llvm_cbe_tmp__525)&1))) {
    goto llvm_cbe_tmp__542;
  } else {
    goto llvm_cbe_tmp__543;
  }

llvm_cbe_tmp__542:
  llvm_cbe_tmp__526 = llvm_cbe_tmp__512;
  llvm_cbe_tmp__527 = *((&_ZL6yy_def.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__526)))]));
  llvm_cbe_tmp__512 = (((int32_t)(int16_t)llvm_cbe_tmp__527));
  llvm_cbe_tmp__528 = llvm_cbe_tmp__512;
  if ((((((int32_t)llvm_cbe_tmp__528) >= ((int32_t)33u))&1))) {
    goto llvm_cbe_tmp__544;
  } else {
    goto llvm_cbe_tmp__545;
  }

llvm_cbe_tmp__544:
  llvm_cbe_tmp__529 = llvm_cbe_tmp__515;
  llvm_cbe_tmp__530 = *((&_ZL7yy_meta.array[((int64_t)(((uint64_t)(uint8_t)llvm_cbe_tmp__529)))]));
  llvm_cbe_tmp__515 = llvm_cbe_tmp__530;
  goto llvm_cbe_tmp__545;

llvm_cbe_tmp__545:
  goto llvm_cbe_tmp__541;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__543:
  llvm_cbe_tmp__531 = llvm_cbe_tmp__512;
  llvm_cbe_tmp__532 = *((&_ZL7yy_base.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__531)))]));
  llvm_cbe_tmp__533 = llvm_cbe_tmp__515;
  llvm_cbe_tmp__534 = *((&_ZL6yy_nxt.array[((int64_t)(((int64_t)(int32_t)(llvm_add_u32((((int32_t)(int16_t)llvm_cbe_tmp__532)), (((uint32_t)(uint8_t)llvm_cbe_tmp__533)))))))]));
  llvm_cbe_tmp__512 = (((int32_t)(int16_t)llvm_cbe_tmp__534));
  llvm_cbe_tmp__535 = llvm_cbe_tmp__512;
  llvm_cbe_tmp__513 = (((uint32_t)(bool)(((llvm_cbe_tmp__535 == 32u)&1))));
  llvm_cbe_tmp__536 = llvm_cbe_tmp__513;
  if ((((llvm_cbe_tmp__536 != 0u)&1))) {
    goto llvm_cbe_tmp__546;
  } else {
    goto llvm_cbe_tmp__547;
  }

llvm_cbe_tmp__546:
  llvm_cbe_tmp__538__PHI_TEMPORARY = 0;   /* for PHI node */
  goto llvm_cbe_tmp__548;

llvm_cbe_tmp__547:
  llvm_cbe_tmp__537 = llvm_cbe_tmp__512;
  llvm_cbe_tmp__538__PHI_TEMPORARY = llvm_cbe_tmp__537;   /* for PHI node */
  goto llvm_cbe_tmp__548;

llvm_cbe_tmp__548:
  llvm_cbe_tmp__538 = llvm_cbe_tmp__538__PHI_TEMPORARY;
  return llvm_cbe_tmp__538;
}


static uint32_t _ZL18yy_get_next_bufferv(void) {
  uint32_t llvm_cbe_tmp__549;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__550;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__551;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__552;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__553;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__554;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__555;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__556;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__557;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__558;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__559;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__560;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__561;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__562;
  uint64_t llvm_cbe_tmp__563;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__564;
  uint8_t* llvm_cbe_tmp__565;
  uint8_t* llvm_cbe_tmp__566;
  uint8_t* llvm_cbe_tmp__567;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__568;
  uint64_t llvm_cbe_tmp__569;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__570;
  uint8_t* llvm_cbe_tmp__571;
  uint32_t llvm_cbe_tmp__572;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__573;
  uint64_t llvm_cbe_tmp__574;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__575;
  uint32_t llvm_cbe_tmp__576;
  uint8_t* llvm_cbe_tmp__577;
  uint8_t* llvm_cbe_tmp__578;
  uint8_t* llvm_cbe_tmp__579;
  uint8_t* llvm_cbe_tmp__580;
  uint32_t llvm_cbe_tmp__581;
  uint32_t llvm_cbe_tmp__582;
  uint8_t* llvm_cbe_tmp__583;
  uint8_t llvm_cbe_tmp__584;
  uint8_t* llvm_cbe_tmp__585;
  uint32_t llvm_cbe_tmp__586;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__587;
  uint64_t llvm_cbe_tmp__588;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__589;
  uint32_t llvm_cbe_tmp__590;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__591;
  uint64_t llvm_cbe_tmp__592;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__593;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__594;
  uint64_t llvm_cbe_tmp__595;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__596;
  uint32_t llvm_cbe_tmp__597;
  uint32_t llvm_cbe_tmp__598;
  uint32_t llvm_cbe_tmp__599;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__600;
  uint64_t llvm_cbe_tmp__601;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__602;
  uint8_t* llvm_cbe_tmp__603;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__604;
  uint8_t* llvm_cbe_tmp__605;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__606;
  uint32_t llvm_cbe_tmp__607;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__608;
  uint32_t llvm_cbe_tmp__609;
  uint32_t llvm_cbe_tmp__610;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__611;
  uint32_t llvm_cbe_tmp__612;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__613;
  uint32_t* llvm_cbe_tmp__614;
  uint32_t llvm_cbe_tmp__615;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__616;
  uint32_t* llvm_cbe_tmp__617;
  uint32_t llvm_cbe_tmp__618;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__619;
  uint8_t* llvm_cbe_tmp__620;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__621;
  uint32_t llvm_cbe_tmp__622;
  uint8_t* llvm_cbe_tmp__623;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__624;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__625;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__626;
  uint8_t* llvm_cbe_tmp__627;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__628;
  uint8_t* llvm_cbe_tmp__629;
  uint32_t llvm_cbe_tmp__630;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__631;
  uint64_t llvm_cbe_tmp__632;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__633;
  uint32_t llvm_cbe_tmp__634;
  uint32_t llvm_cbe_tmp__635;
  uint32_t llvm_cbe_tmp__636;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__637;
  uint64_t llvm_cbe_tmp__638;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__639;
  uint32_t llvm_cbe_tmp__640;
  uint32_t llvm_cbe_tmp__641;
  uint32_t llvm_cbe_tmp__642;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__643;
  uint32_t llvm_cbe_tmp__644;
  uint32_t llvm_cbe_tmp__645;
  bool llvm_cbe_tmp__646;
  bool llvm_cbe_tmp__646__PHI_TEMPORARY;
  uint32_t llvm_cbe_tmp__647;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__648;
  uint64_t llvm_cbe_tmp__649;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__650;
  uint8_t* llvm_cbe_tmp__651;
  uint32_t llvm_cbe_tmp__652;
  uint32_t llvm_cbe_tmp__653;
  uint32_t llvm_cbe_tmp__654;
  uint32_t llvm_cbe_tmp__655;
  uint32_t llvm_cbe_tmp__656;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__657;
  uint64_t llvm_cbe_tmp__658;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__659;
  uint8_t* llvm_cbe_tmp__660;
  uint32_t llvm_cbe_tmp__661;
  uint32_t llvm_cbe_tmp__662;
  uint32_t llvm_cbe_tmp__663;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__664;
  uint32_t llvm_cbe_tmp__665;
  uint32_t llvm_cbe_tmp__666;
  uint32_t* llvm_cbe_tmp__667;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__668;
  uint64_t llvm_cbe_tmp__669;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__670;
  uint8_t* llvm_cbe_tmp__671;
  uint32_t llvm_cbe_tmp__672;
  uint32_t llvm_cbe_tmp__673;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__674;
  uint64_t llvm_cbe_tmp__675;
  uint32_t llvm_cbe_tmp__676;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__677;
  uint32_t llvm_cbe_tmp__678;
  bool llvm_cbe_tmp__679;
  bool llvm_cbe_tmp__679__PHI_TEMPORARY;
  uint32_t* llvm_cbe_tmp__680;
  uint32_t llvm_cbe_tmp__681;
  uint32_t* llvm_cbe_tmp__682;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__683;
  uint32_t llvm_cbe_tmp__684;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__685;
  uint64_t llvm_cbe_tmp__686;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__687;
  uint32_t llvm_cbe_tmp__688;
  uint32_t llvm_cbe_tmp__689;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__690;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__691;
  uint64_t llvm_cbe_tmp__692;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__693;
  uint32_t llvm_cbe_tmp__694;
  uint32_t llvm_cbe_tmp__695;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__696;
  uint64_t llvm_cbe_tmp__697;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__698;
  uint32_t llvm_cbe_tmp__699;
  uint32_t llvm_cbe_tmp__700;
  uint32_t llvm_cbe_tmp__701;
  uint32_t llvm_cbe_tmp__702;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__703;
  uint64_t llvm_cbe_tmp__704;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__705;
  uint8_t* llvm_cbe_tmp__706;
  uint32_t llvm_cbe_tmp__707;
  uint8_t* llvm_cbe_tmp__708;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__709;
  uint64_t llvm_cbe_tmp__710;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__711;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__712;
  uint64_t llvm_cbe_tmp__713;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__714;
  uint8_t* llvm_cbe_tmp__715;
  uint32_t llvm_cbe_tmp__716;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__717;
  uint64_t llvm_cbe_tmp__718;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__719;
  uint32_t llvm_cbe_tmp__720;
  uint32_t llvm_cbe_tmp__721;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__722;
  uint64_t llvm_cbe_tmp__723;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__724;
  uint8_t* llvm_cbe_tmp__725;
  uint32_t llvm_cbe_tmp__726;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__727;
  uint64_t llvm_cbe_tmp__728;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__729;
  uint8_t* llvm_cbe_tmp__730;
  uint32_t llvm_cbe_tmp__731;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__732;
  uint64_t llvm_cbe_tmp__733;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__734;
  uint8_t* llvm_cbe_tmp__735;
  uint32_t llvm_cbe_tmp__736;
  uint32_t llvm_cbe_tmp__737;

  llvm_cbe_tmp__562 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__563 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__564 = *((&llvm_cbe_tmp__562[((int64_t)llvm_cbe_tmp__563)]));
  llvm_cbe_tmp__565 = *((&llvm_cbe_tmp__564->field1));
  llvm_cbe_tmp__550 = llvm_cbe_tmp__565;
  llvm_cbe_tmp__566 = yytext;
  llvm_cbe_tmp__551 = llvm_cbe_tmp__566;
  llvm_cbe_tmp__567 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__568 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__569 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__570 = *((&llvm_cbe_tmp__568[((int64_t)llvm_cbe_tmp__569)]));
  llvm_cbe_tmp__571 = *((&llvm_cbe_tmp__570->field1));
  llvm_cbe_tmp__572 = _ZL10yy_n_chars;
  if ((((((uint64_t)llvm_cbe_tmp__567) > ((uint64_t)((&llvm_cbe_tmp__571[((int64_t)(((int64_t)(int32_t)(llvm_add_u32(llvm_cbe_tmp__572, 1)))))]))))&1))) {
    goto llvm_cbe_tmp__738;
  } else {
    goto llvm_cbe_tmp__739;
  }

llvm_cbe_tmp__738:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_25.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__739:
  llvm_cbe_tmp__573 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__574 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__575 = *((&llvm_cbe_tmp__573[((int64_t)llvm_cbe_tmp__574)]));
  llvm_cbe_tmp__576 = *((&llvm_cbe_tmp__575->field10));
  if ((((llvm_cbe_tmp__576 == 0u)&1))) {
    goto llvm_cbe_tmp__740;
  } else {
    goto llvm_cbe_tmp__741;
  }

llvm_cbe_tmp__740:
  llvm_cbe_tmp__577 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__578 = yytext;
  if (((((llvm_sub_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__577)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__578)))), UINT64_C(0))) == UINT64_C(1))&1))) {
    goto llvm_cbe_tmp__742;
  } else {
    goto llvm_cbe_tmp__743;
  }

llvm_cbe_tmp__742:
  llvm_cbe_tmp__549 = 1;
  goto llvm_cbe_tmp__744;

llvm_cbe_tmp__743:
  llvm_cbe_tmp__549 = 2;
  goto llvm_cbe_tmp__744;

llvm_cbe_tmp__741:
  llvm_cbe_tmp__579 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__580 = yytext;
  llvm_cbe_tmp__552 = (((uint32_t)(llvm_sub_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__579)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__580)))), UINT64_C(1)))));
  llvm_cbe_tmp__553 = 0;
  goto llvm_cbe_tmp__745;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__745:
  llvm_cbe_tmp__581 = llvm_cbe_tmp__553;
  llvm_cbe_tmp__582 = llvm_cbe_tmp__552;
  if ((((((int32_t)llvm_cbe_tmp__581) < ((int32_t)llvm_cbe_tmp__582))&1))) {
    goto llvm_cbe_tmp__746;
  } else {
    goto llvm_cbe_tmp__747;
  }

llvm_cbe_tmp__746:
  llvm_cbe_tmp__583 = llvm_cbe_tmp__551;
  llvm_cbe_tmp__551 = ((&llvm_cbe_tmp__583[((int32_t)1)]));
  llvm_cbe_tmp__584 = *llvm_cbe_tmp__583;
  llvm_cbe_tmp__585 = llvm_cbe_tmp__550;
  llvm_cbe_tmp__550 = ((&llvm_cbe_tmp__585[((int32_t)1)]));
  *llvm_cbe_tmp__585 = llvm_cbe_tmp__584;
  goto llvm_cbe_tmp__748;

llvm_cbe_tmp__748:
  llvm_cbe_tmp__586 = llvm_cbe_tmp__553;
  llvm_cbe_tmp__553 = (llvm_add_u32(llvm_cbe_tmp__586, 1));
  goto llvm_cbe_tmp__745;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__747:
  llvm_cbe_tmp__587 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__588 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__589 = *((&llvm_cbe_tmp__587[((int64_t)llvm_cbe_tmp__588)]));
  llvm_cbe_tmp__590 = *((&llvm_cbe_tmp__589->field11));
  if ((((llvm_cbe_tmp__590 == 2u)&1))) {
    goto llvm_cbe_tmp__749;
  } else {
    goto llvm_cbe_tmp__750;
  }

llvm_cbe_tmp__749:
  _ZL10yy_n_chars = 0;
  llvm_cbe_tmp__591 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__592 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__593 = *((&llvm_cbe_tmp__591[((int64_t)llvm_cbe_tmp__592)]));
  *((&llvm_cbe_tmp__593->field4)) = 0;
  goto llvm_cbe_tmp__751;

llvm_cbe_tmp__750:
  llvm_cbe_tmp__594 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__595 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__596 = *((&llvm_cbe_tmp__594[((int64_t)llvm_cbe_tmp__595)]));
  llvm_cbe_tmp__597 = *((&llvm_cbe_tmp__596->field3));
  llvm_cbe_tmp__598 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__555 = (llvm_sub_u32((llvm_sub_u32(llvm_cbe_tmp__597, llvm_cbe_tmp__598)), 1));
  goto llvm_cbe_tmp__752;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__752:
  llvm_cbe_tmp__599 = llvm_cbe_tmp__555;
  if ((((((int32_t)llvm_cbe_tmp__599) <= ((int32_t)0u))&1))) {
    goto llvm_cbe_tmp__753;
  } else {
    goto llvm_cbe_tmp__754;
  }

llvm_cbe_tmp__753:
  llvm_cbe_tmp__600 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__601 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__602 = *((&llvm_cbe_tmp__600[((int64_t)llvm_cbe_tmp__601)]));
  llvm_cbe_tmp__556 = llvm_cbe_tmp__602;
  llvm_cbe_tmp__603 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__604 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__605 = *((&llvm_cbe_tmp__604->field1));
  llvm_cbe_tmp__557 = (((uint32_t)(llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__603)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__605))))));
  llvm_cbe_tmp__606 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__607 = *((&llvm_cbe_tmp__606->field5));
  if ((((llvm_cbe_tmp__607 != 0u)&1))) {
    goto llvm_cbe_tmp__755;
  } else {
    goto llvm_cbe_tmp__756;
  }

llvm_cbe_tmp__756:
  llvm_cbe_tmp__625 = llvm_cbe_tmp__556;
  *((&llvm_cbe_tmp__625->field1)) = ((uint8_t*)/*NULL*/0);
  goto llvm_cbe_tmp__757;

llvm_cbe_tmp__755:
  llvm_cbe_tmp__608 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__609 = *((&llvm_cbe_tmp__608->field3));
  llvm_cbe_tmp__558 = (llvm_mul_u32(llvm_cbe_tmp__609, 2));
  llvm_cbe_tmp__610 = llvm_cbe_tmp__558;
  if ((((((int32_t)llvm_cbe_tmp__610) <= ((int32_t)0u))&1))) {
    goto llvm_cbe_tmp__758;
  } else {
    goto llvm_cbe_tmp__759;
  }

llvm_cbe_tmp__759:
  llvm_cbe_tmp__616 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__617 = (&llvm_cbe_tmp__616->field3);
  llvm_cbe_tmp__618 = *llvm_cbe_tmp__617;
  *llvm_cbe_tmp__617 = (llvm_mul_u32(llvm_cbe_tmp__618, 2));
  goto llvm_cbe_tmp__760;

llvm_cbe_tmp__758:
  llvm_cbe_tmp__611 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__612 = *((&llvm_cbe_tmp__611->field3));
  llvm_cbe_tmp__613 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__614 = (&llvm_cbe_tmp__613->field3);
  llvm_cbe_tmp__615 = *llvm_cbe_tmp__614;
  *llvm_cbe_tmp__614 = (llvm_add_u32(llvm_cbe_tmp__615, (llvm_sdiv_u32(llvm_cbe_tmp__612, 8))));
  goto llvm_cbe_tmp__760;

llvm_cbe_tmp__760:
  llvm_cbe_tmp__619 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__620 = *((&llvm_cbe_tmp__619->field1));
  llvm_cbe_tmp__621 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__622 = *((&llvm_cbe_tmp__621->field3));
  llvm_cbe_tmp__623 = _Z9yyreallocPvm(llvm_cbe_tmp__620, (((int64_t)(int32_t)(llvm_add_u32(llvm_cbe_tmp__622, 2)))));
  llvm_cbe_tmp__624 = llvm_cbe_tmp__556;
  *((&llvm_cbe_tmp__624->field1)) = llvm_cbe_tmp__623;
  goto llvm_cbe_tmp__757;

llvm_cbe_tmp__757:
  llvm_cbe_tmp__626 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__627 = *((&llvm_cbe_tmp__626->field1));
  if ((((llvm_cbe_tmp__627 != ((uint8_t*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__761;
  } else {
    goto llvm_cbe_tmp__762;
  }

llvm_cbe_tmp__761:
  llvm_cbe_tmp__628 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__629 = *((&llvm_cbe_tmp__628->field1));
  llvm_cbe_tmp__630 = llvm_cbe_tmp__557;
  _ZL10yy_c_buf_p = ((&llvm_cbe_tmp__629[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__630)))]));
  llvm_cbe_tmp__631 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__632 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__633 = *((&llvm_cbe_tmp__631[((int64_t)llvm_cbe_tmp__632)]));
  llvm_cbe_tmp__634 = *((&llvm_cbe_tmp__633->field3));
  llvm_cbe_tmp__635 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__555 = (llvm_sub_u32((llvm_sub_u32(llvm_cbe_tmp__634, llvm_cbe_tmp__635)), 1));
  goto llvm_cbe_tmp__752;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__762:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_26.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__754:
  llvm_cbe_tmp__636 = llvm_cbe_tmp__555;
  if ((((((int32_t)llvm_cbe_tmp__636) > ((int32_t)8192u))&1))) {
    goto llvm_cbe_tmp__763;
  } else {
    goto llvm_cbe_tmp__764;
  }

llvm_cbe_tmp__763:
  llvm_cbe_tmp__555 = 8192;
  goto llvm_cbe_tmp__764;

llvm_cbe_tmp__764:
  llvm_cbe_tmp__637 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__638 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__639 = *((&llvm_cbe_tmp__637[((int64_t)llvm_cbe_tmp__638)]));
  llvm_cbe_tmp__640 = *((&llvm_cbe_tmp__639->field6));
  if ((((llvm_cbe_tmp__640 != 0u)&1))) {
    goto llvm_cbe_tmp__765;
  } else {
    goto llvm_cbe_tmp__766;
  }

llvm_cbe_tmp__765:
  llvm_cbe_tmp__559 = 42;
  llvm_cbe_tmp__560 = 0;
  goto llvm_cbe_tmp__767;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__767:
  llvm_cbe_tmp__641 = llvm_cbe_tmp__560;
  llvm_cbe_tmp__642 = llvm_cbe_tmp__555;
  if ((((((int32_t)llvm_cbe_tmp__641) < ((int32_t)llvm_cbe_tmp__642))&1))) {
    goto llvm_cbe_tmp__768;
  } else {
    llvm_cbe_tmp__646__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__769;
  }

llvm_cbe_tmp__768:
  llvm_cbe_tmp__643 = yyin;
  llvm_cbe_tmp__644 = getc(llvm_cbe_tmp__643);
  llvm_cbe_tmp__559 = llvm_cbe_tmp__644;
  if ((((llvm_cbe_tmp__644 != 4294967295u)&1))) {
    goto llvm_cbe_tmp__770;
  } else {
    llvm_cbe_tmp__646__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__769;
  }

llvm_cbe_tmp__770:
  llvm_cbe_tmp__645 = llvm_cbe_tmp__559;
  llvm_cbe_tmp__646__PHI_TEMPORARY = (((llvm_cbe_tmp__645 != 10u)&1));   /* for PHI node */
  goto llvm_cbe_tmp__769;

llvm_cbe_tmp__769:
  llvm_cbe_tmp__646 = ((llvm_cbe_tmp__646__PHI_TEMPORARY)&1);
  if (llvm_cbe_tmp__646) {
    goto llvm_cbe_tmp__771;
  } else {
    goto llvm_cbe_tmp__772;
  }

llvm_cbe_tmp__771:
  llvm_cbe_tmp__647 = llvm_cbe_tmp__559;
  llvm_cbe_tmp__648 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__649 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__650 = *((&llvm_cbe_tmp__648[((int64_t)llvm_cbe_tmp__649)]));
  llvm_cbe_tmp__651 = *((&llvm_cbe_tmp__650->field1));
  llvm_cbe_tmp__652 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__653 = llvm_cbe_tmp__560;
  *((&((&llvm_cbe_tmp__651[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__652)))]))[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__653)))])) = (((uint8_t)llvm_cbe_tmp__647));
  goto llvm_cbe_tmp__773;

llvm_cbe_tmp__773:
  llvm_cbe_tmp__654 = llvm_cbe_tmp__560;
  llvm_cbe_tmp__560 = (llvm_add_u32(llvm_cbe_tmp__654, 1));
  goto llvm_cbe_tmp__767;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__772:
  llvm_cbe_tmp__655 = llvm_cbe_tmp__559;
  if ((((llvm_cbe_tmp__655 == 10u)&1))) {
    goto llvm_cbe_tmp__774;
  } else {
    goto llvm_cbe_tmp__775;
  }

llvm_cbe_tmp__774:
  llvm_cbe_tmp__656 = llvm_cbe_tmp__559;
  llvm_cbe_tmp__657 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__658 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__659 = *((&llvm_cbe_tmp__657[((int64_t)llvm_cbe_tmp__658)]));
  llvm_cbe_tmp__660 = *((&llvm_cbe_tmp__659->field1));
  llvm_cbe_tmp__661 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__662 = llvm_cbe_tmp__560;
  llvm_cbe_tmp__560 = (llvm_add_u32(llvm_cbe_tmp__662, 1));
  *((&((&llvm_cbe_tmp__660[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__661)))]))[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__662)))])) = (((uint8_t)llvm_cbe_tmp__656));
  goto llvm_cbe_tmp__775;

llvm_cbe_tmp__775:
  llvm_cbe_tmp__663 = llvm_cbe_tmp__559;
  if ((((llvm_cbe_tmp__663 == 4294967295u)&1))) {
    goto llvm_cbe_tmp__776;
  } else {
    goto llvm_cbe_tmp__777;
  }

llvm_cbe_tmp__776:
  llvm_cbe_tmp__664 = yyin;
  llvm_cbe_tmp__665 = ferror(llvm_cbe_tmp__664);
  if ((((llvm_cbe_tmp__665 != 0u)&1))) {
    goto llvm_cbe_tmp__778;
  } else {
    goto llvm_cbe_tmp__777;
  }

llvm_cbe_tmp__778:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_27.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__777:
  llvm_cbe_tmp__666 = llvm_cbe_tmp__560;
  _ZL10yy_n_chars = llvm_cbe_tmp__666;
  goto llvm_cbe_tmp__779;

llvm_cbe_tmp__766:
  llvm_cbe_tmp__667 = __errno_location();
  *llvm_cbe_tmp__667 = 0;
  goto llvm_cbe_tmp__780;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__780:
  llvm_cbe_tmp__668 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__669 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__670 = *((&llvm_cbe_tmp__668[((int64_t)llvm_cbe_tmp__669)]));
  llvm_cbe_tmp__671 = *((&llvm_cbe_tmp__670->field1));
  llvm_cbe_tmp__672 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__673 = llvm_cbe_tmp__555;
  llvm_cbe_tmp__674 = yyin;
  llvm_cbe_tmp__675 = fread(((&llvm_cbe_tmp__671[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__672)))])), UINT64_C(1), (((int64_t)(int32_t)llvm_cbe_tmp__673)), llvm_cbe_tmp__674);
  llvm_cbe_tmp__676 = ((uint32_t)llvm_cbe_tmp__675);
  _ZL10yy_n_chars = llvm_cbe_tmp__676;
  if ((((llvm_cbe_tmp__676 == 0u)&1))) {
    goto llvm_cbe_tmp__781;
  } else {
    llvm_cbe_tmp__679__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__782;
  }

llvm_cbe_tmp__781:
  llvm_cbe_tmp__677 = yyin;
  llvm_cbe_tmp__678 = ferror(llvm_cbe_tmp__677);
  llvm_cbe_tmp__679__PHI_TEMPORARY = (((llvm_cbe_tmp__678 != 0u)&1));   /* for PHI node */
  goto llvm_cbe_tmp__782;

llvm_cbe_tmp__782:
  llvm_cbe_tmp__679 = ((llvm_cbe_tmp__679__PHI_TEMPORARY)&1);
  if (llvm_cbe_tmp__679) {
    goto llvm_cbe_tmp__783;
  } else {
    goto llvm_cbe_tmp__784;
  }

llvm_cbe_tmp__783:
  llvm_cbe_tmp__680 = __errno_location();
  llvm_cbe_tmp__681 = *llvm_cbe_tmp__680;
  if ((((llvm_cbe_tmp__681 != 4u)&1))) {
    goto llvm_cbe_tmp__785;
  } else {
    goto llvm_cbe_tmp__786;
  }

llvm_cbe_tmp__786:
  llvm_cbe_tmp__682 = __errno_location();
  *llvm_cbe_tmp__682 = 0;
  llvm_cbe_tmp__683 = yyin;
  clearerr(llvm_cbe_tmp__683);
  goto llvm_cbe_tmp__780;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__785:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_27.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__784:
  goto llvm_cbe_tmp__779;

llvm_cbe_tmp__779:
  llvm_cbe_tmp__684 = _ZL10yy_n_chars;
  llvm_cbe_tmp__685 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__686 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__687 = *((&llvm_cbe_tmp__685[((int64_t)llvm_cbe_tmp__686)]));
  *((&llvm_cbe_tmp__687->field4)) = llvm_cbe_tmp__684;
  goto llvm_cbe_tmp__751;

llvm_cbe_tmp__751:
  llvm_cbe_tmp__688 = _ZL10yy_n_chars;
  if ((((llvm_cbe_tmp__688 == 0u)&1))) {
    goto llvm_cbe_tmp__787;
  } else {
    goto llvm_cbe_tmp__788;
  }

llvm_cbe_tmp__787:
  llvm_cbe_tmp__689 = llvm_cbe_tmp__552;
  if ((((llvm_cbe_tmp__689 == 0u)&1))) {
    goto llvm_cbe_tmp__789;
  } else {
    goto llvm_cbe_tmp__790;
  }

llvm_cbe_tmp__789:
  llvm_cbe_tmp__554 = 1;
  llvm_cbe_tmp__690 = yyin;
  _Z9yyrestartP8_IO_FILE(llvm_cbe_tmp__690);
  goto llvm_cbe_tmp__791;

llvm_cbe_tmp__790:
  llvm_cbe_tmp__554 = 2;
  llvm_cbe_tmp__691 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__692 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__693 = *((&llvm_cbe_tmp__691[((int64_t)llvm_cbe_tmp__692)]));
  *((&llvm_cbe_tmp__693->field11)) = 2;
  goto llvm_cbe_tmp__791;

llvm_cbe_tmp__791:
  goto llvm_cbe_tmp__792;

llvm_cbe_tmp__788:
  llvm_cbe_tmp__554 = 0;
  goto llvm_cbe_tmp__792;

llvm_cbe_tmp__792:
  llvm_cbe_tmp__694 = _ZL10yy_n_chars;
  llvm_cbe_tmp__695 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__696 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__697 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__698 = *((&llvm_cbe_tmp__696[((int64_t)llvm_cbe_tmp__697)]));
  llvm_cbe_tmp__699 = *((&llvm_cbe_tmp__698->field3));
  if ((((((int32_t)(llvm_add_u32(llvm_cbe_tmp__694, llvm_cbe_tmp__695))) > ((int32_t)llvm_cbe_tmp__699))&1))) {
    goto llvm_cbe_tmp__793;
  } else {
    goto llvm_cbe_tmp__794;
  }

llvm_cbe_tmp__793:
  llvm_cbe_tmp__700 = _ZL10yy_n_chars;
  llvm_cbe_tmp__701 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__702 = _ZL10yy_n_chars;
  llvm_cbe_tmp__561 = (llvm_add_u32((llvm_add_u32(llvm_cbe_tmp__700, llvm_cbe_tmp__701)), (llvm_ashr_u32(llvm_cbe_tmp__702, 1))));
  llvm_cbe_tmp__703 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__704 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__705 = *((&llvm_cbe_tmp__703[((int64_t)llvm_cbe_tmp__704)]));
  llvm_cbe_tmp__706 = *((&llvm_cbe_tmp__705->field1));
  llvm_cbe_tmp__707 = llvm_cbe_tmp__561;
  llvm_cbe_tmp__708 = _Z9yyreallocPvm(llvm_cbe_tmp__706, (((int64_t)(int32_t)llvm_cbe_tmp__707)));
  llvm_cbe_tmp__709 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__710 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__711 = *((&llvm_cbe_tmp__709[((int64_t)llvm_cbe_tmp__710)]));
  *((&llvm_cbe_tmp__711->field1)) = llvm_cbe_tmp__708;
  llvm_cbe_tmp__712 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__713 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__714 = *((&llvm_cbe_tmp__712[((int64_t)llvm_cbe_tmp__713)]));
  llvm_cbe_tmp__715 = *((&llvm_cbe_tmp__714->field1));
  if ((((llvm_cbe_tmp__715 != ((uint8_t*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__795;
  } else {
    goto llvm_cbe_tmp__796;
  }

llvm_cbe_tmp__796:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_28.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__795:
  llvm_cbe_tmp__716 = llvm_cbe_tmp__561;
  llvm_cbe_tmp__717 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__718 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__719 = *((&llvm_cbe_tmp__717[((int64_t)llvm_cbe_tmp__718)]));
  *((&llvm_cbe_tmp__719->field3)) = (llvm_sub_u32(llvm_cbe_tmp__716, 2));
  goto llvm_cbe_tmp__794;

llvm_cbe_tmp__794:
  llvm_cbe_tmp__720 = llvm_cbe_tmp__552;
  llvm_cbe_tmp__721 = _ZL10yy_n_chars;
  _ZL10yy_n_chars = (llvm_add_u32(llvm_cbe_tmp__721, llvm_cbe_tmp__720));
  llvm_cbe_tmp__722 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__723 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__724 = *((&llvm_cbe_tmp__722[((int64_t)llvm_cbe_tmp__723)]));
  llvm_cbe_tmp__725 = *((&llvm_cbe_tmp__724->field1));
  llvm_cbe_tmp__726 = _ZL10yy_n_chars;
  *((&llvm_cbe_tmp__725[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__726)))])) = 0;
  llvm_cbe_tmp__727 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__728 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__729 = *((&llvm_cbe_tmp__727[((int64_t)llvm_cbe_tmp__728)]));
  llvm_cbe_tmp__730 = *((&llvm_cbe_tmp__729->field1));
  llvm_cbe_tmp__731 = _ZL10yy_n_chars;
  *((&llvm_cbe_tmp__730[((int64_t)(((int64_t)(int32_t)(llvm_add_u32(llvm_cbe_tmp__731, 1)))))])) = 0;
  llvm_cbe_tmp__732 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__733 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__734 = *((&llvm_cbe_tmp__732[((int64_t)llvm_cbe_tmp__733)]));
  llvm_cbe_tmp__735 = *((&llvm_cbe_tmp__734->field1));
  yytext = ((&(*llvm_cbe_tmp__735)));
  llvm_cbe_tmp__736 = llvm_cbe_tmp__554;
  llvm_cbe_tmp__549 = llvm_cbe_tmp__736;
  goto llvm_cbe_tmp__744;

llvm_cbe_tmp__744:
  llvm_cbe_tmp__737 = llvm_cbe_tmp__549;
  return llvm_cbe_tmp__737;
}


void _Z9yyrestartP8_IO_FILE(struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__797) {
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__798;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__799;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__800;
  uint64_t llvm_cbe_tmp__801;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__802;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__803;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__803__PHI_TEMPORARY;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__804;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__805;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__806;
  uint64_t llvm_cbe_tmp__807;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__808;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__809;
  uint64_t llvm_cbe_tmp__810;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__811;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__812;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__812__PHI_TEMPORARY;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__813;

  llvm_cbe_tmp__798 = llvm_cbe_tmp__797;
  llvm_cbe_tmp__799 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__799 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__814;
  } else {
    goto llvm_cbe_tmp__815;
  }

llvm_cbe_tmp__814:
  llvm_cbe_tmp__800 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__801 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__802 = *((&llvm_cbe_tmp__800[((int64_t)llvm_cbe_tmp__801)]));
  llvm_cbe_tmp__803__PHI_TEMPORARY = llvm_cbe_tmp__802;   /* for PHI node */
  goto llvm_cbe_tmp__816;

llvm_cbe_tmp__815:
  llvm_cbe_tmp__803__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__816;

llvm_cbe_tmp__816:
  llvm_cbe_tmp__803 = llvm_cbe_tmp__803__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__803 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__817;
  } else {
    goto llvm_cbe_tmp__818;
  }

llvm_cbe_tmp__818:
  _ZL21yyensure_buffer_stackv();
  llvm_cbe_tmp__804 = yyin;
  llvm_cbe_tmp__805 = _Z16yy_create_bufferP8_IO_FILEi(llvm_cbe_tmp__804, 16384);
  llvm_cbe_tmp__806 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__807 = _ZL19yy_buffer_stack_top;
  *((&llvm_cbe_tmp__806[((int64_t)llvm_cbe_tmp__807)])) = llvm_cbe_tmp__805;
  goto llvm_cbe_tmp__817;

llvm_cbe_tmp__817:
  llvm_cbe_tmp__808 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__808 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__819;
  } else {
    goto llvm_cbe_tmp__820;
  }

llvm_cbe_tmp__819:
  llvm_cbe_tmp__809 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__810 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__811 = *((&llvm_cbe_tmp__809[((int64_t)llvm_cbe_tmp__810)]));
  llvm_cbe_tmp__812__PHI_TEMPORARY = llvm_cbe_tmp__811;   /* for PHI node */
  goto llvm_cbe_tmp__821;

llvm_cbe_tmp__820:
  llvm_cbe_tmp__812__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__821;

llvm_cbe_tmp__821:
  llvm_cbe_tmp__812 = llvm_cbe_tmp__812__PHI_TEMPORARY;
  llvm_cbe_tmp__813 = llvm_cbe_tmp__798;
  _ZL14yy_init_bufferP15yy_buffer_stateP8_IO_FILE(llvm_cbe_tmp__812, llvm_cbe_tmp__813);
  _ZL20yy_load_buffer_statev();
}


static __noreturn void _ZL14yy_fatal_errorPKc(uint8_t* llvm_cbe_tmp__822) {
  uint8_t* llvm_cbe_tmp__823;    /* Address-exposed local */
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__824;
  uint8_t* llvm_cbe_tmp__825;
  uint32_t llvm_cbe_tmp__826;

  llvm_cbe_tmp__823 = llvm_cbe_tmp__822;
  llvm_cbe_tmp__824 = stderr;
  llvm_cbe_tmp__825 = llvm_cbe_tmp__823;
  llvm_cbe_tmp__826 = fprintf(llvm_cbe_tmp__824, ((&_OC_str_OC_30.array[((int32_t)0)])), llvm_cbe_tmp__825);
  exit(2);
  __builtin_unreachable();

}


static void _ZL14yy_init_bufferP15yy_buffer_stateP8_IO_FILE(struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__827, struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__828) {
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__829;    /* Address-exposed local */
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__830;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__831;    /* Address-exposed local */
  uint32_t* llvm_cbe_tmp__832;
  uint32_t llvm_cbe_tmp__833;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__834;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__835;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__836;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__837;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__838;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__839;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__840;
  uint64_t llvm_cbe_tmp__841;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__842;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__843;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__843__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__844;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__845;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__846;
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__847;
  uint32_t llvm_cbe_tmp__848;
  uint32_t llvm_cbe_tmp__849;
  uint32_t llvm_cbe_tmp__850;
  uint32_t llvm_cbe_tmp__851;
  uint32_t llvm_cbe_tmp__851__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__852;
  uint32_t llvm_cbe_tmp__853;
  uint32_t* llvm_cbe_tmp__854;

  llvm_cbe_tmp__829 = llvm_cbe_tmp__827;
  llvm_cbe_tmp__830 = llvm_cbe_tmp__828;
  llvm_cbe_tmp__832 = __errno_location();
  llvm_cbe_tmp__833 = *llvm_cbe_tmp__832;
  llvm_cbe_tmp__831 = llvm_cbe_tmp__833;
  llvm_cbe_tmp__834 = llvm_cbe_tmp__829;
  _Z15yy_flush_bufferP15yy_buffer_state(llvm_cbe_tmp__834);
  llvm_cbe_tmp__835 = llvm_cbe_tmp__830;
  llvm_cbe_tmp__836 = llvm_cbe_tmp__829;
  *((&llvm_cbe_tmp__836->field0)) = llvm_cbe_tmp__835;
  llvm_cbe_tmp__837 = llvm_cbe_tmp__829;
  *((&llvm_cbe_tmp__837->field10)) = 1;
  llvm_cbe_tmp__838 = llvm_cbe_tmp__829;
  llvm_cbe_tmp__839 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__839 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__855;
  } else {
    goto llvm_cbe_tmp__856;
  }

llvm_cbe_tmp__855:
  llvm_cbe_tmp__840 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__841 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__842 = *((&llvm_cbe_tmp__840[((int64_t)llvm_cbe_tmp__841)]));
  llvm_cbe_tmp__843__PHI_TEMPORARY = llvm_cbe_tmp__842;   /* for PHI node */
  goto llvm_cbe_tmp__857;

llvm_cbe_tmp__856:
  llvm_cbe_tmp__843__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__857;

llvm_cbe_tmp__857:
  llvm_cbe_tmp__843 = llvm_cbe_tmp__843__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__838 != llvm_cbe_tmp__843)&1))) {
    goto llvm_cbe_tmp__858;
  } else {
    goto llvm_cbe_tmp__859;
  }

llvm_cbe_tmp__858:
  llvm_cbe_tmp__844 = llvm_cbe_tmp__829;
  *((&llvm_cbe_tmp__844->field8)) = 1;
  llvm_cbe_tmp__845 = llvm_cbe_tmp__829;
  *((&llvm_cbe_tmp__845->field9)) = 0;
  goto llvm_cbe_tmp__859;

llvm_cbe_tmp__859:
  llvm_cbe_tmp__846 = llvm_cbe_tmp__830;
  if ((((llvm_cbe_tmp__846 != ((struct l_struct_struct_OC__IO_FILE*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__860;
  } else {
    goto llvm_cbe_tmp__861;
  }

llvm_cbe_tmp__860:
  llvm_cbe_tmp__847 = llvm_cbe_tmp__830;
  llvm_cbe_tmp__848 = fileno(llvm_cbe_tmp__847);
  llvm_cbe_tmp__849 = isatty(llvm_cbe_tmp__848);
  llvm_cbe_tmp__850 = ((uint32_t)(bool)(((((int32_t)llvm_cbe_tmp__849) > ((int32_t)0u))&1)));
  llvm_cbe_tmp__851__PHI_TEMPORARY = llvm_cbe_tmp__850;   /* for PHI node */
  goto llvm_cbe_tmp__862;

llvm_cbe_tmp__861:
  llvm_cbe_tmp__851__PHI_TEMPORARY = 0;   /* for PHI node */
  goto llvm_cbe_tmp__862;

llvm_cbe_tmp__862:
  llvm_cbe_tmp__851 = llvm_cbe_tmp__851__PHI_TEMPORARY;
  llvm_cbe_tmp__852 = llvm_cbe_tmp__829;
  *((&llvm_cbe_tmp__852->field6)) = llvm_cbe_tmp__851;
  llvm_cbe_tmp__853 = llvm_cbe_tmp__831;
  llvm_cbe_tmp__854 = __errno_location();
  *llvm_cbe_tmp__854 = llvm_cbe_tmp__853;
}


void _Z19yy_switch_to_bufferP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__863) {
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__864;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__865;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__866;
  uint64_t llvm_cbe_tmp__867;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__868;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__869;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__869__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__870;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__871;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__872;
  uint64_t llvm_cbe_tmp__873;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__874;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__875;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__875__PHI_TEMPORARY;
  uint8_t llvm_cbe_tmp__876;
  uint8_t* llvm_cbe_tmp__877;
  uint8_t* llvm_cbe_tmp__878;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__879;
  uint64_t llvm_cbe_tmp__880;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__881;
  uint32_t llvm_cbe_tmp__882;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__883;
  uint64_t llvm_cbe_tmp__884;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__885;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__886;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__887;
  uint64_t llvm_cbe_tmp__888;

  llvm_cbe_tmp__864 = llvm_cbe_tmp__863;
  _ZL21yyensure_buffer_stackv();
  llvm_cbe_tmp__865 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__865 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__889;
  } else {
    goto llvm_cbe_tmp__890;
  }

llvm_cbe_tmp__889:
  llvm_cbe_tmp__866 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__867 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__868 = *((&llvm_cbe_tmp__866[((int64_t)llvm_cbe_tmp__867)]));
  llvm_cbe_tmp__869__PHI_TEMPORARY = llvm_cbe_tmp__868;   /* for PHI node */
  goto llvm_cbe_tmp__891;

llvm_cbe_tmp__890:
  llvm_cbe_tmp__869__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__891;

llvm_cbe_tmp__891:
  llvm_cbe_tmp__869 = llvm_cbe_tmp__869__PHI_TEMPORARY;
  llvm_cbe_tmp__870 = llvm_cbe_tmp__864;
  if ((((llvm_cbe_tmp__869 == llvm_cbe_tmp__870)&1))) {
    goto llvm_cbe_tmp__892;
  } else {
    goto llvm_cbe_tmp__893;
  }

llvm_cbe_tmp__892:
  goto llvm_cbe_tmp__894;

llvm_cbe_tmp__893:
  llvm_cbe_tmp__871 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__871 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__895;
  } else {
    goto llvm_cbe_tmp__896;
  }

llvm_cbe_tmp__895:
  llvm_cbe_tmp__872 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__873 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__874 = *((&llvm_cbe_tmp__872[((int64_t)llvm_cbe_tmp__873)]));
  llvm_cbe_tmp__875__PHI_TEMPORARY = llvm_cbe_tmp__874;   /* for PHI node */
  goto llvm_cbe_tmp__897;

llvm_cbe_tmp__896:
  llvm_cbe_tmp__875__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__897;

llvm_cbe_tmp__897:
  llvm_cbe_tmp__875 = llvm_cbe_tmp__875__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__875 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__898;
  } else {
    goto llvm_cbe_tmp__899;
  }

llvm_cbe_tmp__898:
  llvm_cbe_tmp__876 = _ZL12yy_hold_char;
  llvm_cbe_tmp__877 = _ZL10yy_c_buf_p;
  *llvm_cbe_tmp__877 = llvm_cbe_tmp__876;
  llvm_cbe_tmp__878 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__879 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__880 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__881 = *((&llvm_cbe_tmp__879[((int64_t)llvm_cbe_tmp__880)]));
  *((&llvm_cbe_tmp__881->field2)) = llvm_cbe_tmp__878;
  llvm_cbe_tmp__882 = _ZL10yy_n_chars;
  llvm_cbe_tmp__883 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__884 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__885 = *((&llvm_cbe_tmp__883[((int64_t)llvm_cbe_tmp__884)]));
  *((&llvm_cbe_tmp__885->field4)) = llvm_cbe_tmp__882;
  goto llvm_cbe_tmp__899;

llvm_cbe_tmp__899:
  llvm_cbe_tmp__886 = llvm_cbe_tmp__864;
  llvm_cbe_tmp__887 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__888 = _ZL19yy_buffer_stack_top;
  *((&llvm_cbe_tmp__887[((int64_t)llvm_cbe_tmp__888)])) = llvm_cbe_tmp__886;
  _ZL20yy_load_buffer_statev();
  _ZL27yy_did_buffer_switch_on_eof = 1;
  goto llvm_cbe_tmp__894;

llvm_cbe_tmp__894:
  return;
}


uint8_t* _Z7yyallocm(uint64_t llvm_cbe_tmp__900) {
  uint64_t llvm_cbe_tmp__901;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__902;
  uint8_t* llvm_cbe_tmp__903;

  llvm_cbe_tmp__901 = llvm_cbe_tmp__900;
  llvm_cbe_tmp__902 = llvm_cbe_tmp__901;
  llvm_cbe_tmp__903 = malloc(llvm_cbe_tmp__902);
  return llvm_cbe_tmp__903;
}


void _Z16yy_delete_bufferP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__904) {
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__905;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__906;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__907;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__908;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__909;
  uint64_t llvm_cbe_tmp__910;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__911;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__912;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__912__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__913;
  uint64_t llvm_cbe_tmp__914;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__915;
  uint32_t llvm_cbe_tmp__916;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__917;
  uint8_t* llvm_cbe_tmp__918;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__919;

  llvm_cbe_tmp__905 = llvm_cbe_tmp__904;
  llvm_cbe_tmp__906 = llvm_cbe_tmp__905;
  if ((((llvm_cbe_tmp__906 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__920;
  } else {
    goto llvm_cbe_tmp__921;
  }

llvm_cbe_tmp__921:
  goto llvm_cbe_tmp__922;

llvm_cbe_tmp__920:
  llvm_cbe_tmp__907 = llvm_cbe_tmp__905;
  llvm_cbe_tmp__908 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__908 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__923;
  } else {
    goto llvm_cbe_tmp__924;
  }

llvm_cbe_tmp__923:
  llvm_cbe_tmp__909 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__910 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__911 = *((&llvm_cbe_tmp__909[((int64_t)llvm_cbe_tmp__910)]));
  llvm_cbe_tmp__912__PHI_TEMPORARY = llvm_cbe_tmp__911;   /* for PHI node */
  goto llvm_cbe_tmp__925;

llvm_cbe_tmp__924:
  llvm_cbe_tmp__912__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__925;

llvm_cbe_tmp__925:
  llvm_cbe_tmp__912 = llvm_cbe_tmp__912__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__907 == llvm_cbe_tmp__912)&1))) {
    goto llvm_cbe_tmp__926;
  } else {
    goto llvm_cbe_tmp__927;
  }

llvm_cbe_tmp__926:
  llvm_cbe_tmp__913 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__914 = _ZL19yy_buffer_stack_top;
  *((&llvm_cbe_tmp__913[((int64_t)llvm_cbe_tmp__914)])) = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);
  goto llvm_cbe_tmp__927;

llvm_cbe_tmp__927:
  llvm_cbe_tmp__915 = llvm_cbe_tmp__905;
  llvm_cbe_tmp__916 = *((&llvm_cbe_tmp__915->field5));
  if ((((llvm_cbe_tmp__916 != 0u)&1))) {
    goto llvm_cbe_tmp__928;
  } else {
    goto llvm_cbe_tmp__929;
  }

llvm_cbe_tmp__928:
  llvm_cbe_tmp__917 = llvm_cbe_tmp__905;
  llvm_cbe_tmp__918 = *((&llvm_cbe_tmp__917->field1));
  _Z6yyfreePv(llvm_cbe_tmp__918);
  goto llvm_cbe_tmp__929;

llvm_cbe_tmp__929:
  llvm_cbe_tmp__919 = llvm_cbe_tmp__905;
  _Z6yyfreePv((((uint8_t*)llvm_cbe_tmp__919)));
  goto llvm_cbe_tmp__922;

llvm_cbe_tmp__922:
  return;
}


void _Z6yyfreePv(uint8_t* llvm_cbe_tmp__930) {
  uint8_t* llvm_cbe_tmp__931;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__932;

  llvm_cbe_tmp__931 = llvm_cbe_tmp__930;
  llvm_cbe_tmp__932 = llvm_cbe_tmp__931;
  free(llvm_cbe_tmp__932);
}


void _Z15yy_flush_bufferP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__933) {
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__934;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__935;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__936;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__937;
  uint8_t* llvm_cbe_tmp__938;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__939;
  uint8_t* llvm_cbe_tmp__940;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__941;
  uint8_t* llvm_cbe_tmp__942;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__943;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__944;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__945;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__946;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__947;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__948;
  uint64_t llvm_cbe_tmp__949;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__950;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__951;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__951__PHI_TEMPORARY;

  llvm_cbe_tmp__934 = llvm_cbe_tmp__933;
  llvm_cbe_tmp__935 = llvm_cbe_tmp__934;
  if ((((llvm_cbe_tmp__935 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__952;
  } else {
    goto llvm_cbe_tmp__953;
  }

llvm_cbe_tmp__953:
  goto llvm_cbe_tmp__954;

llvm_cbe_tmp__952:
  llvm_cbe_tmp__936 = llvm_cbe_tmp__934;
  *((&llvm_cbe_tmp__936->field4)) = 0;
  llvm_cbe_tmp__937 = llvm_cbe_tmp__934;
  llvm_cbe_tmp__938 = *((&llvm_cbe_tmp__937->field1));
  *((&(*llvm_cbe_tmp__938))) = 0;
  llvm_cbe_tmp__939 = llvm_cbe_tmp__934;
  llvm_cbe_tmp__940 = *((&llvm_cbe_tmp__939->field1));
  *((&llvm_cbe_tmp__940[((int64_t)UINT64_C(1))])) = 0;
  llvm_cbe_tmp__941 = llvm_cbe_tmp__934;
  llvm_cbe_tmp__942 = *((&llvm_cbe_tmp__941->field1));
  llvm_cbe_tmp__943 = llvm_cbe_tmp__934;
  *((&llvm_cbe_tmp__943->field2)) = ((&(*llvm_cbe_tmp__942)));
  llvm_cbe_tmp__944 = llvm_cbe_tmp__934;
  *((&llvm_cbe_tmp__944->field7)) = 1;
  llvm_cbe_tmp__945 = llvm_cbe_tmp__934;
  *((&llvm_cbe_tmp__945->field11)) = 0;
  llvm_cbe_tmp__946 = llvm_cbe_tmp__934;
  llvm_cbe_tmp__947 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__947 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__955;
  } else {
    goto llvm_cbe_tmp__956;
  }

llvm_cbe_tmp__955:
  llvm_cbe_tmp__948 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__949 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__950 = *((&llvm_cbe_tmp__948[((int64_t)llvm_cbe_tmp__949)]));
  llvm_cbe_tmp__951__PHI_TEMPORARY = llvm_cbe_tmp__950;   /* for PHI node */
  goto llvm_cbe_tmp__957;

llvm_cbe_tmp__956:
  llvm_cbe_tmp__951__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__957;

llvm_cbe_tmp__957:
  llvm_cbe_tmp__951 = llvm_cbe_tmp__951__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__946 == llvm_cbe_tmp__951)&1))) {
    goto llvm_cbe_tmp__958;
  } else {
    goto llvm_cbe_tmp__954;
  }

llvm_cbe_tmp__958:
  _ZL20yy_load_buffer_statev();
  goto llvm_cbe_tmp__954;

llvm_cbe_tmp__954:
  return;
}


void _Z19yypush_buffer_stateP15yy_buffer_state(struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__959) {
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__960;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__961;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__962;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__963;
  uint64_t llvm_cbe_tmp__964;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__965;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__966;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__966__PHI_TEMPORARY;
  uint8_t llvm_cbe_tmp__967;
  uint8_t* llvm_cbe_tmp__968;
  uint8_t* llvm_cbe_tmp__969;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__970;
  uint64_t llvm_cbe_tmp__971;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__972;
  uint32_t llvm_cbe_tmp__973;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__974;
  uint64_t llvm_cbe_tmp__975;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__976;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__977;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__978;
  uint64_t llvm_cbe_tmp__979;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__980;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__981;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__981__PHI_TEMPORARY;
  uint64_t llvm_cbe_tmp__982;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__983;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__984;
  uint64_t llvm_cbe_tmp__985;

  llvm_cbe_tmp__960 = llvm_cbe_tmp__959;
  llvm_cbe_tmp__961 = llvm_cbe_tmp__960;
  if ((((llvm_cbe_tmp__961 == ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__986;
  } else {
    goto llvm_cbe_tmp__987;
  }

llvm_cbe_tmp__986:
  goto llvm_cbe_tmp__988;

llvm_cbe_tmp__987:
  _ZL21yyensure_buffer_stackv();
  llvm_cbe_tmp__962 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__962 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__989;
  } else {
    goto llvm_cbe_tmp__990;
  }

llvm_cbe_tmp__989:
  llvm_cbe_tmp__963 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__964 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__965 = *((&llvm_cbe_tmp__963[((int64_t)llvm_cbe_tmp__964)]));
  llvm_cbe_tmp__966__PHI_TEMPORARY = llvm_cbe_tmp__965;   /* for PHI node */
  goto llvm_cbe_tmp__991;

llvm_cbe_tmp__990:
  llvm_cbe_tmp__966__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__991;

llvm_cbe_tmp__991:
  llvm_cbe_tmp__966 = llvm_cbe_tmp__966__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__966 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__992;
  } else {
    goto llvm_cbe_tmp__993;
  }

llvm_cbe_tmp__992:
  llvm_cbe_tmp__967 = _ZL12yy_hold_char;
  llvm_cbe_tmp__968 = _ZL10yy_c_buf_p;
  *llvm_cbe_tmp__968 = llvm_cbe_tmp__967;
  llvm_cbe_tmp__969 = _ZL10yy_c_buf_p;
  llvm_cbe_tmp__970 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__971 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__972 = *((&llvm_cbe_tmp__970[((int64_t)llvm_cbe_tmp__971)]));
  *((&llvm_cbe_tmp__972->field2)) = llvm_cbe_tmp__969;
  llvm_cbe_tmp__973 = _ZL10yy_n_chars;
  llvm_cbe_tmp__974 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__975 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__976 = *((&llvm_cbe_tmp__974[((int64_t)llvm_cbe_tmp__975)]));
  *((&llvm_cbe_tmp__976->field4)) = llvm_cbe_tmp__973;
  goto llvm_cbe_tmp__993;

llvm_cbe_tmp__993:
  llvm_cbe_tmp__977 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__977 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__994;
  } else {
    goto llvm_cbe_tmp__995;
  }

llvm_cbe_tmp__994:
  llvm_cbe_tmp__978 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__979 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__980 = *((&llvm_cbe_tmp__978[((int64_t)llvm_cbe_tmp__979)]));
  llvm_cbe_tmp__981__PHI_TEMPORARY = llvm_cbe_tmp__980;   /* for PHI node */
  goto llvm_cbe_tmp__996;

llvm_cbe_tmp__995:
  llvm_cbe_tmp__981__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__996;

llvm_cbe_tmp__996:
  llvm_cbe_tmp__981 = llvm_cbe_tmp__981__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__981 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__997;
  } else {
    goto llvm_cbe_tmp__998;
  }

llvm_cbe_tmp__997:
  llvm_cbe_tmp__982 = _ZL19yy_buffer_stack_top;
  _ZL19yy_buffer_stack_top = (llvm_add_u64(llvm_cbe_tmp__982, UINT64_C(1)));
  goto llvm_cbe_tmp__998;

llvm_cbe_tmp__998:
  llvm_cbe_tmp__983 = llvm_cbe_tmp__960;
  llvm_cbe_tmp__984 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__985 = _ZL19yy_buffer_stack_top;
  *((&llvm_cbe_tmp__984[((int64_t)llvm_cbe_tmp__985)])) = llvm_cbe_tmp__983;
  _ZL20yy_load_buffer_statev();
  _ZL27yy_did_buffer_switch_on_eof = 1;
  goto llvm_cbe_tmp__988;

llvm_cbe_tmp__988:
  return;
}


void _Z18yypop_buffer_statev(void) {
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__999;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1000;
  uint64_t llvm_cbe_tmp__1001;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1002;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1003;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1003__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1004;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1005;
  uint64_t llvm_cbe_tmp__1006;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1007;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1008;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1008__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1009;
  uint64_t llvm_cbe_tmp__1010;
  uint64_t llvm_cbe_tmp__1011;
  uint64_t llvm_cbe_tmp__1012;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1013;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1014;
  uint64_t llvm_cbe_tmp__1015;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1016;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1017;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1017__PHI_TEMPORARY;

  llvm_cbe_tmp__999 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__999 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1018;
  } else {
    goto llvm_cbe_tmp__1019;
  }

llvm_cbe_tmp__1018:
  llvm_cbe_tmp__1000 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__1001 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__1002 = *((&llvm_cbe_tmp__1000[((int64_t)llvm_cbe_tmp__1001)]));
  llvm_cbe_tmp__1003__PHI_TEMPORARY = llvm_cbe_tmp__1002;   /* for PHI node */
  goto llvm_cbe_tmp__1020;

llvm_cbe_tmp__1019:
  llvm_cbe_tmp__1003__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__1020;

llvm_cbe_tmp__1020:
  llvm_cbe_tmp__1003 = llvm_cbe_tmp__1003__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__1003 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1021;
  } else {
    goto llvm_cbe_tmp__1022;
  }

llvm_cbe_tmp__1022:
  goto llvm_cbe_tmp__1023;

llvm_cbe_tmp__1021:
  llvm_cbe_tmp__1004 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__1004 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1024;
  } else {
    goto llvm_cbe_tmp__1025;
  }

llvm_cbe_tmp__1024:
  llvm_cbe_tmp__1005 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__1006 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__1007 = *((&llvm_cbe_tmp__1005[((int64_t)llvm_cbe_tmp__1006)]));
  llvm_cbe_tmp__1008__PHI_TEMPORARY = llvm_cbe_tmp__1007;   /* for PHI node */
  goto llvm_cbe_tmp__1026;

llvm_cbe_tmp__1025:
  llvm_cbe_tmp__1008__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__1026;

llvm_cbe_tmp__1026:
  llvm_cbe_tmp__1008 = llvm_cbe_tmp__1008__PHI_TEMPORARY;
  _Z16yy_delete_bufferP15yy_buffer_state(llvm_cbe_tmp__1008);
  llvm_cbe_tmp__1009 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__1010 = _ZL19yy_buffer_stack_top;
  *((&llvm_cbe_tmp__1009[((int64_t)llvm_cbe_tmp__1010)])) = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);
  llvm_cbe_tmp__1011 = _ZL19yy_buffer_stack_top;
  if ((((((uint64_t)llvm_cbe_tmp__1011) > ((uint64_t)UINT64_C(0)))&1))) {
    goto llvm_cbe_tmp__1027;
  } else {
    goto llvm_cbe_tmp__1028;
  }

llvm_cbe_tmp__1027:
  llvm_cbe_tmp__1012 = _ZL19yy_buffer_stack_top;
  _ZL19yy_buffer_stack_top = (llvm_add_u64(llvm_cbe_tmp__1012, UINT64_C(18446744073709551615)));
  goto llvm_cbe_tmp__1028;

llvm_cbe_tmp__1028:
  llvm_cbe_tmp__1013 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__1013 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1029;
  } else {
    goto llvm_cbe_tmp__1030;
  }

llvm_cbe_tmp__1029:
  llvm_cbe_tmp__1014 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__1015 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__1016 = *((&llvm_cbe_tmp__1014[((int64_t)llvm_cbe_tmp__1015)]));
  llvm_cbe_tmp__1017__PHI_TEMPORARY = llvm_cbe_tmp__1016;   /* for PHI node */
  goto llvm_cbe_tmp__1031;

llvm_cbe_tmp__1030:
  llvm_cbe_tmp__1017__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__1031;

llvm_cbe_tmp__1031:
  llvm_cbe_tmp__1017 = llvm_cbe_tmp__1017__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__1017 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1032;
  } else {
    goto llvm_cbe_tmp__1023;
  }

llvm_cbe_tmp__1032:
  _ZL20yy_load_buffer_statev();
  _ZL27yy_did_buffer_switch_on_eof = 1;
  goto llvm_cbe_tmp__1023;

llvm_cbe_tmp__1023:
  return;
}


struct l_struct_struct_OC_yy_buffer_state* _Z14yy_scan_bufferPcm(uint8_t* llvm_cbe_tmp__1033, uint64_t llvm_cbe_tmp__1034) {
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1035;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1036;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1037;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1038;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1039;
  uint8_t* llvm_cbe_tmp__1040;
  uint64_t llvm_cbe_tmp__1041;
  uint8_t llvm_cbe_tmp__1042;
  uint8_t* llvm_cbe_tmp__1043;
  uint64_t llvm_cbe_tmp__1044;
  uint8_t llvm_cbe_tmp__1045;
  uint8_t* llvm_cbe_tmp__1046;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1047;
  uint64_t llvm_cbe_tmp__1048;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1049;
  uint8_t* llvm_cbe_tmp__1050;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1051;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1052;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1053;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1054;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1055;
  uint32_t llvm_cbe_tmp__1056;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1057;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1058;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1059;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1060;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1061;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1062;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1063;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1064;

  llvm_cbe_tmp__1036 = llvm_cbe_tmp__1033;
  llvm_cbe_tmp__1037 = llvm_cbe_tmp__1034;
  llvm_cbe_tmp__1039 = llvm_cbe_tmp__1037;
  if ((((((uint64_t)llvm_cbe_tmp__1039) < ((uint64_t)UINT64_C(2)))&1))) {
    goto llvm_cbe_tmp__1065;
  } else {
    goto llvm_cbe_tmp__1066;
  }

llvm_cbe_tmp__1066:
  llvm_cbe_tmp__1040 = llvm_cbe_tmp__1036;
  llvm_cbe_tmp__1041 = llvm_cbe_tmp__1037;
  llvm_cbe_tmp__1042 = *((&llvm_cbe_tmp__1040[((int64_t)(llvm_sub_u64(llvm_cbe_tmp__1041, UINT64_C(2))))]));
  if (((((((int32_t)(int8_t)llvm_cbe_tmp__1042)) != 0u)&1))) {
    goto llvm_cbe_tmp__1065;
  } else {
    goto llvm_cbe_tmp__1067;
  }

llvm_cbe_tmp__1067:
  llvm_cbe_tmp__1043 = llvm_cbe_tmp__1036;
  llvm_cbe_tmp__1044 = llvm_cbe_tmp__1037;
  llvm_cbe_tmp__1045 = *((&llvm_cbe_tmp__1043[((int64_t)(llvm_sub_u64(llvm_cbe_tmp__1044, UINT64_C(1))))]));
  if (((((((int32_t)(int8_t)llvm_cbe_tmp__1045)) != 0u)&1))) {
    goto llvm_cbe_tmp__1065;
  } else {
    goto llvm_cbe_tmp__1068;
  }

llvm_cbe_tmp__1065:
  llvm_cbe_tmp__1035 = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);
  goto llvm_cbe_tmp__1069;

llvm_cbe_tmp__1068:
  llvm_cbe_tmp__1046 = _Z7yyallocm(UINT64_C(64));
  llvm_cbe_tmp__1038 = (((struct l_struct_struct_OC_yy_buffer_state*)llvm_cbe_tmp__1046));
  llvm_cbe_tmp__1047 = llvm_cbe_tmp__1038;
  if ((((llvm_cbe_tmp__1047 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1070;
  } else {
    goto llvm_cbe_tmp__1071;
  }

llvm_cbe_tmp__1071:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_22.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__1070:
  llvm_cbe_tmp__1048 = llvm_cbe_tmp__1037;
  llvm_cbe_tmp__1049 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1049->field3)) = (((uint32_t)(llvm_sub_u64(llvm_cbe_tmp__1048, UINT64_C(2)))));
  llvm_cbe_tmp__1050 = llvm_cbe_tmp__1036;
  llvm_cbe_tmp__1051 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1051->field1)) = llvm_cbe_tmp__1050;
  llvm_cbe_tmp__1052 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1052->field2)) = llvm_cbe_tmp__1050;
  llvm_cbe_tmp__1053 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1053->field5)) = 0;
  llvm_cbe_tmp__1054 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1054->field0)) = ((struct l_struct_struct_OC__IO_FILE*)/*NULL*/0);
  llvm_cbe_tmp__1055 = llvm_cbe_tmp__1038;
  llvm_cbe_tmp__1056 = *((&llvm_cbe_tmp__1055->field3));
  llvm_cbe_tmp__1057 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1057->field4)) = llvm_cbe_tmp__1056;
  llvm_cbe_tmp__1058 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1058->field6)) = 0;
  llvm_cbe_tmp__1059 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1059->field7)) = 1;
  llvm_cbe_tmp__1060 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1060->field10)) = 0;
  llvm_cbe_tmp__1061 = llvm_cbe_tmp__1038;
  *((&llvm_cbe_tmp__1061->field11)) = 0;
  llvm_cbe_tmp__1062 = llvm_cbe_tmp__1038;
  _Z19yy_switch_to_bufferP15yy_buffer_state(llvm_cbe_tmp__1062);
  llvm_cbe_tmp__1063 = llvm_cbe_tmp__1038;
  llvm_cbe_tmp__1035 = llvm_cbe_tmp__1063;
  goto llvm_cbe_tmp__1069;

llvm_cbe_tmp__1069:
  llvm_cbe_tmp__1064 = llvm_cbe_tmp__1035;
  return llvm_cbe_tmp__1064;
}


struct l_struct_struct_OC_yy_buffer_state* _Z14yy_scan_stringPKc(uint8_t* llvm_cbe_tmp__1072) {
  uint8_t* llvm_cbe_tmp__1073;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1074;
  uint8_t* llvm_cbe_tmp__1075;
  uint64_t llvm_cbe_tmp__1076;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1077;

  llvm_cbe_tmp__1073 = llvm_cbe_tmp__1072;
  llvm_cbe_tmp__1074 = llvm_cbe_tmp__1073;
  llvm_cbe_tmp__1075 = llvm_cbe_tmp__1073;
  llvm_cbe_tmp__1076 = strlen(llvm_cbe_tmp__1075);
  llvm_cbe_tmp__1077 = _Z13yy_scan_bytesPKci(llvm_cbe_tmp__1074, (((uint32_t)llvm_cbe_tmp__1076)));
  return llvm_cbe_tmp__1077;
}


struct l_struct_struct_OC_yy_buffer_state* _Z13yy_scan_bytesPKci(uint8_t* llvm_cbe_tmp__1078, uint32_t llvm_cbe_tmp__1079) {
  uint8_t* llvm_cbe_tmp__1080;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1081;    /* Address-exposed local */
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1082;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1083;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1084;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1085;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1086;
  uint64_t llvm_cbe_tmp__1087;
  uint8_t* llvm_cbe_tmp__1088;
  uint8_t* llvm_cbe_tmp__1089;
  uint32_t llvm_cbe_tmp__1090;
  uint32_t llvm_cbe_tmp__1091;
  uint8_t* llvm_cbe_tmp__1092;
  uint32_t llvm_cbe_tmp__1093;
  uint8_t llvm_cbe_tmp__1094;
  uint8_t* llvm_cbe_tmp__1095;
  uint32_t llvm_cbe_tmp__1096;
  uint32_t llvm_cbe_tmp__1097;
  uint8_t* llvm_cbe_tmp__1098;
  uint32_t llvm_cbe_tmp__1099;
  uint8_t* llvm_cbe_tmp__1100;
  uint32_t llvm_cbe_tmp__1101;
  uint8_t* llvm_cbe_tmp__1102;
  uint64_t llvm_cbe_tmp__1103;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1104;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1105;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1106;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1107;

  llvm_cbe_tmp__1080 = llvm_cbe_tmp__1078;
  llvm_cbe_tmp__1081 = llvm_cbe_tmp__1079;
  llvm_cbe_tmp__1086 = llvm_cbe_tmp__1081;
  llvm_cbe_tmp__1084 = (((int64_t)(int32_t)(llvm_add_u32(llvm_cbe_tmp__1086, 2))));
  llvm_cbe_tmp__1087 = llvm_cbe_tmp__1084;
  llvm_cbe_tmp__1088 = _Z7yyallocm(llvm_cbe_tmp__1087);
  llvm_cbe_tmp__1083 = llvm_cbe_tmp__1088;
  llvm_cbe_tmp__1089 = llvm_cbe_tmp__1083;
  if ((((llvm_cbe_tmp__1089 != ((uint8_t*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1108;
  } else {
    goto llvm_cbe_tmp__1109;
  }

llvm_cbe_tmp__1109:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_23.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__1108:
  llvm_cbe_tmp__1085 = 0;
  goto llvm_cbe_tmp__1110;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1110:
  llvm_cbe_tmp__1090 = llvm_cbe_tmp__1085;
  llvm_cbe_tmp__1091 = llvm_cbe_tmp__1081;
  if ((((((int32_t)llvm_cbe_tmp__1090) < ((int32_t)llvm_cbe_tmp__1091))&1))) {
    goto llvm_cbe_tmp__1111;
  } else {
    goto llvm_cbe_tmp__1112;
  }

llvm_cbe_tmp__1111:
  llvm_cbe_tmp__1092 = llvm_cbe_tmp__1080;
  llvm_cbe_tmp__1093 = llvm_cbe_tmp__1085;
  llvm_cbe_tmp__1094 = *((&llvm_cbe_tmp__1092[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__1093)))]));
  llvm_cbe_tmp__1095 = llvm_cbe_tmp__1083;
  llvm_cbe_tmp__1096 = llvm_cbe_tmp__1085;
  *((&llvm_cbe_tmp__1095[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__1096)))])) = llvm_cbe_tmp__1094;
  goto llvm_cbe_tmp__1113;

llvm_cbe_tmp__1113:
  llvm_cbe_tmp__1097 = llvm_cbe_tmp__1085;
  llvm_cbe_tmp__1085 = (llvm_add_u32(llvm_cbe_tmp__1097, 1));
  goto llvm_cbe_tmp__1110;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1112:
  llvm_cbe_tmp__1098 = llvm_cbe_tmp__1083;
  llvm_cbe_tmp__1099 = llvm_cbe_tmp__1081;
  *((&llvm_cbe_tmp__1098[((int64_t)(((int64_t)(int32_t)(llvm_add_u32(llvm_cbe_tmp__1099, 1)))))])) = 0;
  llvm_cbe_tmp__1100 = llvm_cbe_tmp__1083;
  llvm_cbe_tmp__1101 = llvm_cbe_tmp__1081;
  *((&llvm_cbe_tmp__1100[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__1101)))])) = 0;
  llvm_cbe_tmp__1102 = llvm_cbe_tmp__1083;
  llvm_cbe_tmp__1103 = llvm_cbe_tmp__1084;
  llvm_cbe_tmp__1104 = _Z14yy_scan_bufferPcm(llvm_cbe_tmp__1102, llvm_cbe_tmp__1103);
  llvm_cbe_tmp__1082 = llvm_cbe_tmp__1104;
  llvm_cbe_tmp__1105 = llvm_cbe_tmp__1082;
  if ((((llvm_cbe_tmp__1105 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1114;
  } else {
    goto llvm_cbe_tmp__1115;
  }

llvm_cbe_tmp__1115:
  _ZL14yy_fatal_errorPKc(((&_OC_str_OC_24.array[((int32_t)0)])));
  __builtin_unreachable();

llvm_cbe_tmp__1114:
  llvm_cbe_tmp__1106 = llvm_cbe_tmp__1082;
  *((&llvm_cbe_tmp__1106->field5)) = 1;
  llvm_cbe_tmp__1107 = llvm_cbe_tmp__1082;
  return llvm_cbe_tmp__1107;
}


uint32_t _Z12yyget_linenov(void) {
  uint32_t llvm_cbe_tmp__1116;

  llvm_cbe_tmp__1116 = yylineno;
  return llvm_cbe_tmp__1116;
}


struct l_struct_struct_OC__IO_FILE* _Z8yyget_inv(void) {
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1117;

  llvm_cbe_tmp__1117 = yyin;
  return llvm_cbe_tmp__1117;
}


struct l_struct_struct_OC__IO_FILE* _Z9yyget_outv(void) {
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1118;

  llvm_cbe_tmp__1118 = yyout;
  return llvm_cbe_tmp__1118;
}


uint32_t _Z10yyget_lengv(void) {
  uint32_t llvm_cbe_tmp__1119;

  llvm_cbe_tmp__1119 = yyleng;
  return llvm_cbe_tmp__1119;
}


uint8_t* _Z10yyget_textv(void) {
  uint8_t* llvm_cbe_tmp__1120;

  llvm_cbe_tmp__1120 = yytext;
  return llvm_cbe_tmp__1120;
}


void _Z12yyset_linenoi(uint32_t llvm_cbe_tmp__1121) {
  uint32_t llvm_cbe_tmp__1122;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1123;

  llvm_cbe_tmp__1122 = llvm_cbe_tmp__1121;
  llvm_cbe_tmp__1123 = llvm_cbe_tmp__1122;
  yylineno = llvm_cbe_tmp__1123;
}


void _Z8yyset_inP8_IO_FILE(struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1124) {
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1125;    /* Address-exposed local */
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1126;

  llvm_cbe_tmp__1125 = llvm_cbe_tmp__1124;
  llvm_cbe_tmp__1126 = llvm_cbe_tmp__1125;
  yyin = llvm_cbe_tmp__1126;
}


void _Z9yyset_outP8_IO_FILE(struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1127) {
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1128;    /* Address-exposed local */
  struct l_struct_struct_OC__IO_FILE* llvm_cbe_tmp__1129;

  llvm_cbe_tmp__1128 = llvm_cbe_tmp__1127;
  llvm_cbe_tmp__1129 = llvm_cbe_tmp__1128;
  yyout = llvm_cbe_tmp__1129;
}


uint32_t _Z11yyget_debugv(void) {
  uint32_t llvm_cbe_tmp__1130;

  llvm_cbe_tmp__1130 = yy_flex_debug;
  return llvm_cbe_tmp__1130;
}


void _Z11yyset_debugi(uint32_t llvm_cbe_tmp__1131) {
  uint32_t llvm_cbe_tmp__1132;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1133;

  llvm_cbe_tmp__1132 = llvm_cbe_tmp__1131;
  llvm_cbe_tmp__1133 = llvm_cbe_tmp__1132;
  yy_flex_debug = llvm_cbe_tmp__1133;
}


uint32_t _Z13yylex_destroyv(void) {
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1134;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1135;
  uint64_t llvm_cbe_tmp__1136;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1137;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1138;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1138__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1139;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1140;
  uint64_t llvm_cbe_tmp__1141;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1142;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1143;
  struct l_struct_struct_OC_yy_buffer_state* llvm_cbe_tmp__1143__PHI_TEMPORARY;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1144;
  uint64_t llvm_cbe_tmp__1145;
  struct l_struct_struct_OC_yy_buffer_state** llvm_cbe_tmp__1146;
  uint32_t llvm_cbe_tmp__1147;

  goto llvm_cbe_tmp__1148;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1148:
  llvm_cbe_tmp__1134 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__1134 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1149;
  } else {
    goto llvm_cbe_tmp__1150;
  }

llvm_cbe_tmp__1150:
  llvm_cbe_tmp__1138__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__1151;

llvm_cbe_tmp__1149:
  llvm_cbe_tmp__1135 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__1136 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__1137 = *((&llvm_cbe_tmp__1135[((int64_t)llvm_cbe_tmp__1136)]));
  llvm_cbe_tmp__1138__PHI_TEMPORARY = llvm_cbe_tmp__1137;   /* for PHI node */
  goto llvm_cbe_tmp__1151;

llvm_cbe_tmp__1151:
  llvm_cbe_tmp__1138 = llvm_cbe_tmp__1138__PHI_TEMPORARY;
  if ((((llvm_cbe_tmp__1138 != ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1152;
  } else {
    goto llvm_cbe_tmp__1153;
  }

llvm_cbe_tmp__1152:
  llvm_cbe_tmp__1139 = _ZL15yy_buffer_stack;
  if ((((llvm_cbe_tmp__1139 != ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1154;
  } else {
    goto llvm_cbe_tmp__1155;
  }

llvm_cbe_tmp__1155:
  llvm_cbe_tmp__1143__PHI_TEMPORARY = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__1156;

llvm_cbe_tmp__1154:
  llvm_cbe_tmp__1140 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__1141 = _ZL19yy_buffer_stack_top;
  llvm_cbe_tmp__1142 = *((&llvm_cbe_tmp__1140[((int64_t)llvm_cbe_tmp__1141)]));
  llvm_cbe_tmp__1143__PHI_TEMPORARY = llvm_cbe_tmp__1142;   /* for PHI node */
  goto llvm_cbe_tmp__1156;

llvm_cbe_tmp__1156:
  llvm_cbe_tmp__1143 = llvm_cbe_tmp__1143__PHI_TEMPORARY;
  _Z16yy_delete_bufferP15yy_buffer_state(llvm_cbe_tmp__1143);
  llvm_cbe_tmp__1144 = _ZL15yy_buffer_stack;
  llvm_cbe_tmp__1145 = _ZL19yy_buffer_stack_top;
  *((&llvm_cbe_tmp__1144[((int64_t)llvm_cbe_tmp__1145)])) = ((struct l_struct_struct_OC_yy_buffer_state*)/*NULL*/0);
  _Z18yypop_buffer_statev();
  goto llvm_cbe_tmp__1148;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1153:
  llvm_cbe_tmp__1146 = _ZL15yy_buffer_stack;
  _Z6yyfreePv((((uint8_t*)llvm_cbe_tmp__1146)));
  _ZL15yy_buffer_stack = ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0);
  llvm_cbe_tmp__1147 = _ZL15yy_init_globalsv();
  return 0;
}


static uint32_t _ZL15yy_init_globalsv(void) {
  _ZL15yy_buffer_stack = ((struct l_struct_struct_OC_yy_buffer_state**)/*NULL*/0);
  _ZL19yy_buffer_stack_top = UINT64_C(0);
  _ZL19yy_buffer_stack_max = UINT64_C(0);
  _ZL10yy_c_buf_p = ((uint8_t*)/*NULL*/0);
  _ZL7yy_init = 0;
  _ZL8yy_start = 0;
  yyin = ((struct l_struct_struct_OC__IO_FILE*)/*NULL*/0);
  yyout = ((struct l_struct_struct_OC__IO_FILE*)/*NULL*/0);
  return 0;
}


uint8_t* _Z9yyreallocPvm(uint8_t* llvm_cbe_tmp__1157, uint64_t llvm_cbe_tmp__1158) {
  uint8_t* llvm_cbe_tmp__1159;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1160;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1161;
  uint64_t llvm_cbe_tmp__1162;
  uint8_t* llvm_cbe_tmp__1163;

  llvm_cbe_tmp__1159 = llvm_cbe_tmp__1157;
  llvm_cbe_tmp__1160 = llvm_cbe_tmp__1158;
  llvm_cbe_tmp__1161 = llvm_cbe_tmp__1159;
  llvm_cbe_tmp__1162 = llvm_cbe_tmp__1160;
  llvm_cbe_tmp__1163 = realloc(llvm_cbe_tmp__1161, llvm_cbe_tmp__1162);
  return llvm_cbe_tmp__1163;
}


static void _GLOBAL__sub_I_tokens_OC_cpp(void) {
  __cxx_global_var_init();
}

