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
struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init;
struct l_struct_class_OC_Node;
struct l_struct_class_OC_NExpression;
struct l_struct_class_OC_NStatement;
struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl;
struct l_struct_struct_OC_std_KD__KD__Vector_base;
struct l_struct_class_OC_std_KD__KD_vector;
struct l_struct_class_OC_NBlock;
struct l_struct_union_OC_YYSTYPE;
struct l_struct_union_OC_yyalloc;
struct l_struct_struct_OC_std_KD__KD___cxx11_KD__KD_basic_string_MD_char_MC__AC_std_KD__KD_char_traits_MD_char_OD__MC__AC_std_KD__KD_allocator_MD_char_OD__AC__OD__KD__KD__Alloc_hider;
struct l_struct_union_OC_anon;
struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string;
struct l_struct_class_OC_std_KD__KD_allocator_OC_0;
struct l_struct_class_OC_NExpressionStatement;
struct l_struct_class_OC_NIdentifier;
struct l_struct_class_OC_NVariableDeclaration;
struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl;
struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4;
struct l_struct_class_OC_std_KD__KD_vector_OC_3;
struct l_struct_class_OC_NFunctionDeclaration;
struct l_struct_class_OC_NDouble;
struct l_struct_class_OC_NAssignment;
struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl;
struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9;
struct l_struct_class_OC_std_KD__KD_vector_OC_8;
struct l_struct_class_OC_NMethodCall;
struct l_struct_class_OC_NBinaryOperator;
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14;
struct l_struct_class_OC_std_KD__KD_allocator;
struct l_struct_class_OC_std_KD__KD_allocator_OC_5;
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15;
struct l_struct_class_OC_std_KD__KD_allocator_OC_10;
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17;
struct l_struct_class_OC_llvm_KD__KD_PointerIntPair;
struct l_struct_class_OC_llvm_KD__KD_Use;
struct l_struct_class_OC_llvm_KD__KD_Value;
struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator;
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator;
struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6;
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13;
struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11;
struct l_struct_class_OC_std_KD__KD_move_iterator;
struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16;
struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18;
struct l_unnamed_1;
struct l_unnamed_3;
struct l_unnamed_2;
typedef uint32_t l_fptr_2(int, ...);

/* Types Definitions */
struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init {
  uint8_t field0;
};
struct l_struct_class_OC_Node {
  l_fptr_2** field0;
};
struct l_struct_class_OC_NExpression {
  struct l_struct_class_OC_Node field0;
};
struct l_struct_class_OC_NStatement {
  struct l_struct_class_OC_Node field0;
};
struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl {
  struct l_struct_class_OC_NStatement** field0;
  struct l_struct_class_OC_NStatement** field1;
  struct l_struct_class_OC_NStatement** field2;
};
struct l_struct_struct_OC_std_KD__KD__Vector_base {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl field0;
};
struct l_struct_class_OC_std_KD__KD_vector {
  struct l_struct_struct_OC_std_KD__KD__Vector_base field0;
};
struct l_struct_class_OC_NBlock {
  struct l_struct_class_OC_NExpression field0;
  struct l_struct_class_OC_std_KD__KD_vector field1;
};
struct l_struct_union_OC_YYSTYPE {
  struct l_struct_class_OC_Node* field0;
};
struct l_struct_union_OC_yyalloc {
  struct l_struct_union_OC_YYSTYPE field0;
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
struct l_struct_class_OC_std_KD__KD_allocator_OC_0 {
  uint8_t field0;
};
struct l_struct_class_OC_NExpressionStatement {
  struct l_struct_class_OC_NStatement field0;
  struct l_struct_class_OC_NExpression* field1;
};
struct l_struct_class_OC_NIdentifier {
  struct l_struct_class_OC_NExpression field0;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string field1;
};
struct l_struct_class_OC_NVariableDeclaration {
  struct l_struct_class_OC_NStatement field0;
  struct l_struct_class_OC_NIdentifier* field1;
  struct l_struct_class_OC_NIdentifier* field2;
  struct l_struct_class_OC_NExpression* field3;
};
struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl {
  struct l_struct_class_OC_NVariableDeclaration** field0;
  struct l_struct_class_OC_NVariableDeclaration** field1;
  struct l_struct_class_OC_NVariableDeclaration** field2;
};
struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4 {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl field0;
};
struct l_struct_class_OC_std_KD__KD_vector_OC_3 {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4 field0;
};
struct l_struct_class_OC_NFunctionDeclaration {
  struct l_struct_class_OC_NStatement field0;
  struct l_struct_class_OC_NIdentifier* field1;
  struct l_struct_class_OC_NIdentifier* field2;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3 field3;
  struct l_struct_class_OC_NBlock* field4;
};
struct l_struct_class_OC_NDouble {
  struct l_struct_class_OC_NExpression field0;
  double field1;
};
struct l_struct_class_OC_NAssignment {
  struct l_struct_class_OC_NExpression field0;
  struct l_struct_class_OC_NIdentifier* field1;
  struct l_struct_class_OC_NExpression* field2;
};
struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl {
  struct l_struct_class_OC_NExpression** field0;
  struct l_struct_class_OC_NExpression** field1;
  struct l_struct_class_OC_NExpression** field2;
};
struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9 {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl field0;
};
struct l_struct_class_OC_std_KD__KD_vector_OC_8 {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9 field0;
};
struct l_struct_class_OC_NMethodCall {
  struct l_struct_class_OC_NExpression field0;
  struct l_struct_class_OC_NIdentifier* field1;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8 field2;
};
struct l_struct_class_OC_NBinaryOperator {
  struct l_struct_class_OC_NExpression field0;
  uint32_t field1;
  struct l_struct_class_OC_NExpression* field2;
  struct l_struct_class_OC_NExpression* field3;
};
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14 {
  struct l_struct_class_OC_NStatement** field0;
};
struct l_struct_class_OC_std_KD__KD_allocator {
  uint8_t field0;
};
struct l_struct_class_OC_std_KD__KD_allocator_OC_5 {
  uint8_t field0;
};
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15 {
  struct l_struct_class_OC_NVariableDeclaration** field0;
};
struct l_struct_class_OC_std_KD__KD_allocator_OC_10 {
  uint8_t field0;
};
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17 {
  struct l_struct_class_OC_NExpression** field0;
};
struct l_struct_class_OC_llvm_KD__KD_PointerIntPair {
  uint64_t field0;
};
struct l_struct_class_OC_llvm_KD__KD_Use {
  struct l_struct_class_OC_llvm_KD__KD_Value* field0;
  struct l_struct_class_OC_llvm_KD__KD_Use* field1;
  struct l_struct_class_OC_llvm_KD__KD_PointerIntPair field2;
};
struct l_struct_class_OC_llvm_KD__KD_Value {
  void* field0;
  struct l_struct_class_OC_llvm_KD__KD_Use* field1;
  uint8_t field2;
  uint8_t field3;
  uint16_t field4;
  uint32_t field5;
};
struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator {
  uint8_t field0;
};
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator {
  struct l_struct_class_OC_NVariableDeclaration** field0;
};
struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6 {
  uint8_t field0;
};
struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 {
  struct l_struct_class_OC_NExpression** field0;
};
struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11 {
  uint8_t field0;
};
struct l_struct_class_OC_std_KD__KD_move_iterator {
  struct l_struct_class_OC_NStatement** field0;
};
struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 {
  struct l_struct_class_OC_NVariableDeclaration** field0;
};
struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 {
  struct l_struct_class_OC_NExpression** field0;
};
struct l_array_11_uint8_t {
  uint8_t array[11];
};
struct l_array_54_uint8_t {
  uint8_t array[54];
};
struct l_array_278_uint8_t {
  uint8_t array[278];
};
struct l_array_87_uint8_t {
  uint8_t array[87];
};
struct l_array_38_uint8_t {
  uint8_t array[38];
};
struct l_array_13_uint8_t {
  uint8_t array[13];
};
struct l_array_18_uint8_t {
  uint8_t array[18];
};
struct l_array_15_uint8_t {
  uint8_t array[15];
};
struct l_array_17_uint8_t {
  uint8_t array[17];
};
struct l_array_30_uint8_t {
  uint8_t array[30];
};
struct l_array_5_uint8_t_KC_ {
  uint8_t* array[5];
};
struct l_unnamed_1 {
  struct l_array_5_uint8_t_KC_ field0;
};
struct l_unnamed_3 {
  uint8_t* field0;
  uint8_t* field1;
  uint8_t* field2;
};
struct l_array_14_uint8_t {
  uint8_t array[14];
};
struct l_array_6_uint8_t {
  uint8_t array[6];
};
struct l_unnamed_2 {
  uint8_t* field0;
  uint8_t* field1;
};
struct l_array_23_uint8_t {
  uint8_t array[23];
};
struct l_array_9_uint8_t {
  uint8_t array[9];
};
struct l_array_26_uint8_t {
  uint8_t array[26];
};
struct l_array_200_uint16_t {
  uint16_t array[200];
};
struct l_array_200_struct_AC_l_struct_union_OC_YYSTYPE {
  struct l_struct_union_OC_YYSTYPE array[200];
};

/* Function definitions */


typedef void l_fptr_1(uint8_t*);

/* External Global Variable Declarations */
extern uint8_t __dso_handle;
extern uint8_t* _ZTVN10__cxxabiv120__si_class_type_infoE;
extern uint8_t* _ZTVN10__cxxabiv117__class_type_infoE;

/* Function Declarations */
static void __cxx_global_var_init(void) __ATTRIBUTELIST__((noinline));
void _ZNSt8ios_base4InitC1Ev(struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init*);
void _ZNSt8ios_base4InitD1Ev(struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init*) __ATTRIBUTELIST__((nothrow));
uint32_t __cxa_atexit(l_fptr_1*, uint8_t*, uint8_t*) __ATTRIBUTELIST__((nothrow));
void _Z7yyerrorPKc(uint8_t*) __ATTRIBUTELIST__((noinline));
uint32_t printf(uint8_t*, ...);
uint32_t _Z7yyparsev(void) __ATTRIBUTELIST__((noinline));
uint8_t* malloc(uint64_t) __ATTRIBUTELIST__((nothrow));
void free(uint8_t*) __ATTRIBUTELIST__((nothrow));
uint32_t _Z5yylexv(void);
uint8_t* _Znwm(uint64_t);
void _ZN6NBlockC2Ev(struct l_struct_class_OC_NBlock*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint32_t __gxx_personality_v0(int, ...);
void _ZdlPv(uint8_t*) __ATTRIBUTELIST__((nothrow));
void _ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_(struct l_struct_class_OC_std_KD__KD_vector*, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZN20NExpressionStatementC2ER11NExpression(struct l_struct_class_OC_NExpressionStatement*, struct l_struct_class_OC_NExpression*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NVariableDeclarationC2ERK11NIdentifierRS0_(struct l_struct_class_OC_NVariableDeclaration*, struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_NIdentifier*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NVariableDeclarationC2ERK11NIdentifierRS0_P11NExpression(struct l_struct_class_OC_NVariableDeclaration*, struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_NExpression*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NFunctionDeclarationC2ERK11NIdentifierS2_RKSt6vectorIP20NVariableDeclarationSaIS5_EER6NBlock(struct l_struct_class_OC_NFunctionDeclaration*, struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_std_KD__KD_vector_OC_3*, struct l_struct_class_OC_NBlock*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_(struct l_struct_class_OC_std_KD__KD_vector_OC_3*, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*) __ATTRIBUTELIST__((nothrow));
uint8_t* _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv(struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*) __ATTRIBUTELIST__((nothrow));
void _ZNSaIcEC1Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_0*) __ATTRIBUTELIST__((nothrow));
void _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_(struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*, uint8_t*, struct l_struct_class_OC_std_KD__KD_allocator_OC_0*);
void _ZNSaIcED1Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_0*) __ATTRIBUTELIST__((nothrow));
double atof(uint8_t*) __ATTRIBUTELIST__((nothrow, pure));
void _ZN7NDoubleC2Ed(struct l_struct_class_OC_NDouble*, double) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NAssignmentC2ER11NIdentifierR11NExpression(struct l_struct_class_OC_NAssignment*, struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_NExpression*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NMethodCallC2ERK11NIdentifierRSt6vectorIP11NExpressionSaIS5_EE(struct l_struct_class_OC_NMethodCall*, struct l_struct_class_OC_NIdentifier*, struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP11NExpressionSaIS1_EED2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN15NBinaryOperatorC2ER11NExpressioniS1_(struct l_struct_class_OC_NBinaryOperator*, struct l_struct_class_OC_NExpression*, uint32_t, struct l_struct_class_OC_NExpression*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_(struct l_struct_class_OC_std_KD__KD_vector_OC_8*, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
static void _ZL10yydestructPKciP7YYSTYPE(uint8_t*, uint32_t, struct l_struct_union_OC_YYSTYPE*) __ATTRIBUTELIST__((noinline, nothrow));
void _ZN11NExpressionC2Ev(struct l_struct_class_OC_NExpression*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP10NStatementSaIS1_EEC2Ev(struct l_struct_class_OC_std_KD__KD_vector*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN6NBlockD2Ev(struct l_struct_class_OC_NBlock*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN6NBlockD0Ev(struct l_struct_class_OC_NBlock*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN6NBlock7codeGenER14CodeGenContext(struct l_struct_class_OC_NBlock*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN4NodeC2Ev(struct l_struct_class_OC_Node*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NExpressionD2Ev(struct l_struct_class_OC_NExpression*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NExpressionD0Ev(struct l_struct_class_OC_NExpression*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN4Node7codeGenER14CodeGenContext(struct l_struct_class_OC_Node*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN4NodeD2Ev(struct l_struct_class_OC_Node*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN4NodeD0Ev(struct l_struct_class_OC_Node*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP10NStatementSaIS1_EEC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
__noreturn void __clang_call_terminate(uint8_t*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__ __HIDDEN__;
uint8_t* __cxa_begin_catch(uint8_t*);
void _ZSt9terminatev(void);
void _ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSaIP10NStatementEC2Ev(struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP10NStatementEC2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP10NStatementSaIS1_EED2Ev(struct l_struct_class_OC_std_KD__KD_vector*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator* _ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP10NStatementSaIS1_EED2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZSt8_DestroyIPP10NStatementEvT_S3_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Destroy_auxILb1EE9__destroyIPP10NStatementEEvT_S5_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m(struct l_struct_struct_OC_std_KD__KD__Vector_base*, struct l_struct_class_OC_NStatement**, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implD2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP10NStatementEE10deallocateERS2_PS1_m(struct l_struct_class_OC_std_KD__KD_allocator*, struct l_struct_class_OC_NStatement**, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP10NStatementE10deallocateEPS2_m(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*, struct l_struct_class_OC_NStatement**, uint64_t) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSaIP10NStatementED2Ev(struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP10NStatementED2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN10NStatementC2Ev(struct l_struct_class_OC_NStatement*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NExpressionStatementD2Ev(struct l_struct_class_OC_NExpressionStatement*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NExpressionStatementD0Ev(struct l_struct_class_OC_NExpressionStatement*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN20NExpressionStatement7codeGenER14CodeGenContext(struct l_struct_class_OC_NExpressionStatement*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN10NStatementD2Ev(struct l_struct_class_OC_NStatement*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN10NStatementD0Ev(struct l_struct_class_OC_NStatement*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NVariableDeclarationD2Ev(struct l_struct_class_OC_NVariableDeclaration*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NVariableDeclarationD0Ev(struct l_struct_class_OC_NVariableDeclaration*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN20NVariableDeclaration7codeGenER14CodeGenContext(struct l_struct_class_OC_NVariableDeclaration*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2ERKS3_(struct l_struct_class_OC_std_KD__KD_vector_OC_3*, struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZN20NFunctionDeclarationD2Ev(struct l_struct_class_OC_NFunctionDeclaration*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN20NFunctionDeclarationD0Ev(struct l_struct_class_OC_NFunctionDeclaration*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN20NFunctionDeclaration7codeGenER14CodeGenContext(struct l_struct_class_OC_NFunctionDeclaration*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_5 _ZN9__gnu_cxx14__alloc_traitsISaIP20NVariableDeclarationES2_E17_S_select_on_copyERKS3_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_5* _ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2EmRKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*, uint64_t, struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSaIP20NVariableDeclarationED2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_5* _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_5 _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE37select_on_container_copy_constructionERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSaIP20NVariableDeclarationEC2ERKS1_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*, struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*, struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2ERKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl*, struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE17_M_create_storageEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8allocateERS2_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8allocateEmPKv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*, uint64_t, uint8_t*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
uint64_t _ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
__noreturn void _ZSt17__throw_bad_allocv(void);
void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationED2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_(struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt13__copy_move_aILb0EPKP20NVariableDeclarationPS1_ET1_T0_S6_S5_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration*** _ZNK9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator*, struct l_struct_class_OC_NVariableDeclaration***) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*, struct l_struct_class_OC_NVariableDeclaration**, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE10deallocateERS2_PS1_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*, struct l_struct_class_OC_NVariableDeclaration**, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE10deallocateEPS2_m(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*, struct l_struct_class_OC_NVariableDeclaration**, uint64_t) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_(struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*, struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*);
void _ZN11NIdentifierD2Ev(struct l_struct_class_OC_NIdentifier*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NIdentifierD0Ev(struct l_struct_class_OC_NIdentifier*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN11NIdentifier7codeGenER14CodeGenContext(struct l_struct_class_OC_NIdentifier*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN7NDoubleD2Ev(struct l_struct_class_OC_NDouble*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN7NDoubleD0Ev(struct l_struct_class_OC_NDouble*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN7NDouble7codeGenER14CodeGenContext(struct l_struct_class_OC_NDouble*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NAssignmentD2Ev(struct l_struct_class_OC_NAssignment*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NAssignmentD0Ev(struct l_struct_class_OC_NAssignment*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN11NAssignment7codeGenER14CodeGenContext(struct l_struct_class_OC_NAssignment*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP11NExpressionSaIS1_EEC2ERKS3_(struct l_struct_class_OC_std_KD__KD_vector_OC_8*, struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZN11NMethodCallD2Ev(struct l_struct_class_OC_NMethodCall*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN11NMethodCallD0Ev(struct l_struct_class_OC_NMethodCall*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN11NMethodCall7codeGenER14CodeGenContext(struct l_struct_class_OC_NMethodCall*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_10 _ZN9__gnu_cxx14__alloc_traitsISaIP11NExpressionES2_E17_S_select_on_copyERKS3_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_10* _ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2EmRKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*, uint64_t, struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSaIP11NExpressionED2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNKSt6vectorIP11NExpressionSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNKSt6vectorIP11NExpressionSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_10* _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator_OC_10 _ZNSt16allocator_traitsISaIP11NExpressionEE37select_on_container_copy_constructionERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSaIP11NExpressionEC2ERKS1_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*, struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*, struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2ERKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl*, struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE17_M_create_storageEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt16allocator_traitsISaIP11NExpressionEE8allocateERS2_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZN9__gnu_cxx13new_allocatorIP11NExpressionE8allocateEmPKv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*, uint64_t, uint8_t*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
uint64_t _ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP11NExpressionED2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_(struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt13__copy_move_aILb0EPKP11NExpressionPS1_ET1_T0_S6_S5_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt12__niter_baseIPP11NExpressionET_S3_(struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression*** _ZNK9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13*, struct l_struct_class_OC_NExpression***) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*, struct l_struct_class_OC_NExpression**, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP11NExpressionEE10deallocateERS2_PS1_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*, struct l_struct_class_OC_NExpression**, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP11NExpressionE10deallocateEPS2_m(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*, struct l_struct_class_OC_NExpression**, uint64_t) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN15NBinaryOperatorD2Ev(struct l_struct_class_OC_NBinaryOperator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN15NBinaryOperatorD0Ev(struct l_struct_class_OC_NBinaryOperator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_llvm_KD__KD_Value* _ZN15NBinaryOperator7codeGenER14CodeGenContext(struct l_struct_class_OC_NBinaryOperator*, void*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZSt8_DestroyIPP11NExpressionEvT_S3_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Destroy_auxILb1EE9__destroyIPP11NExpressionEEvT_S5_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSaIP11NExpressionEC2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZSt8_DestroyIPP20NVariableDeclarationEvT_S3_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Destroy_auxILb1EE9__destroyIPP20NVariableDeclarationEEvT_S5_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(struct l_struct_class_OC_std_KD__KD_allocator*, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP10NStatementSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(struct l_struct_class_OC_std_KD__KD_vector*, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZNSt6vectorIP10NStatementSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP10NStatementE9constructIS2_JRKS2_EEEvPT_DpOT0_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP10NStatementSaIS1_EE12_M_check_lenEmPKc(struct l_struct_class_OC_std_KD__KD_vector*, uint64_t, uint8_t*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
uint64_t _ZN9__gnu_cxxmiIPP10NStatementSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14*, struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZNSt6vectorIP10NStatementSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZNSt12_Vector_baseIP10NStatementSaIS1_EE11_M_allocateEm(struct l_struct_struct_OC_std_KD__KD__Vector_base*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement*** _ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP10NStatementEE7destroyIS1_EEvRS2_PT_(struct l_struct_class_OC_std_KD__KD_allocator*, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void __cxa_rethrow(void);
void __cxa_end_catch(void);
uint64_t _ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(struct l_struct_class_OC_std_KD__KD_vector*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(struct l_struct_class_OC_std_KD__KD_vector*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
__noreturn void _ZSt20__throw_length_errorPKc(uint8_t*);
uint64_t* _ZSt3maxImERKT_S2_S2_(uint64_t*, uint64_t*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNSt16allocator_traitsISaIP10NStatementEE8max_sizeERKS2_(struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_std_KD__KD_allocator* _ZNKSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14*, struct l_struct_class_OC_NStatement***) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZNSt16allocator_traitsISaIP10NStatementEE8allocateERS2_m(struct l_struct_class_OC_std_KD__KD_allocator*, uint64_t) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZN9__gnu_cxx13new_allocatorIP10NStatementE8allocateEmPKv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*, uint64_t, uint8_t*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt22__uninitialized_copy_aISt13move_iteratorIPP10NStatementES3_S2_ET0_T_S6_S5_RSaIT1_E(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_std_KD__KD_allocator*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_(struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt18uninitialized_copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP10NStatementES5_EET0_T_S8_S7_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt4copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt14__copy_move_a2ILb1EPP10NStatementS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt13__copy_move_aILb1EPP10NStatementS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt12__niter_baseIPP10NStatementET_S3_(struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP10NStatementEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZSt12__miter_baseIPP10NStatementET_S3_(struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NStatement** _ZNKSt13move_iteratorIPP10NStatementE4baseEv(struct l_struct_class_OC_std_KD__KD_move_iterator*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt13move_iteratorIPP10NStatementEC2ES2_(struct l_struct_class_OC_std_KD__KD_move_iterator*, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP10NStatementE7destroyIS2_EEvPT_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*, struct l_struct_class_OC_NStatement**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSaIP20NVariableDeclarationEC2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(struct l_struct_class_OC_std_KD__KD_vector_OC_3*, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE9constructIS2_JRKS2_EEEvPT_DpOT0_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE12_M_check_lenEmPKc(struct l_struct_class_OC_std_KD__KD_vector_OC_3*, uint64_t, uint8_t*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
uint64_t _ZN9__gnu_cxxmiIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15*, struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration*** _ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE7destroyIS1_EEvRS2_PT_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8max_sizeERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15*, struct l_struct_class_OC_NVariableDeclaration***) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt22__uninitialized_copy_aISt13move_iteratorIPP20NVariableDeclarationES3_S2_ET0_T_S6_S5_RSaIT1_E(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_std_KD__KD_allocator_OC_5*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_(struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt18uninitialized_copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP20NVariableDeclarationES5_EET0_T_S8_S7_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt4copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt14__copy_move_a2ILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt13__copy_move_aILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZSt12__miter_baseIPP20NVariableDeclarationET_S3_(struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NVariableDeclaration** _ZNKSt13move_iteratorIPP20NVariableDeclarationE4baseEv(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt13move_iteratorIPP20NVariableDeclarationEC2ES2_(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16*, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE7destroyIS2_EEvPT_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*, struct l_struct_class_OC_NVariableDeclaration**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
void _ZNSt6vectorIP11NExpressionSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(struct l_struct_class_OC_std_KD__KD_vector_OC_8*, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt6vectorIP11NExpressionSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP11NExpressionE9constructIS2_JRKS2_EEEvPT_DpOT0_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP11NExpressionSaIS1_EE12_M_check_lenEmPKc(struct l_struct_class_OC_std_KD__KD_vector_OC_8*, uint64_t, uint8_t*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
uint64_t _ZN9__gnu_cxxmiIPP11NExpressionSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17*, struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt6vectorIP11NExpressionSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression*** _ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt16allocator_traitsISaIP11NExpressionEE7destroyIS1_EEvRS2_PT_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
uint64_t _ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
uint64_t _ZNSt16allocator_traitsISaIP11NExpressionEE8max_sizeERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17*, struct l_struct_class_OC_NExpression***) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt22__uninitialized_copy_aISt13move_iteratorIPP11NExpressionES3_S2_ET0_T_S6_S5_RSaIT1_E(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_std_KD__KD_allocator_OC_10*) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_(struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt18uninitialized_copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP11NExpressionES5_EET0_T_S8_S7_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt4copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt14__copy_move_a2ILb1EPP11NExpressionS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt13__copy_move_aILb1EPP11NExpressionS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZSt12__miter_baseIPP11NExpressionET_S3_(struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
struct l_struct_class_OC_NExpression** _ZNKSt13move_iteratorIPP11NExpressionE4baseEv(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18*) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZNSt13move_iteratorIPP11NExpressionEC2ES2_(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18*, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
void _ZN9__gnu_cxx13new_allocatorIP11NExpressionE7destroyIS2_EEvPT_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*, struct l_struct_class_OC_NExpression**) __ATTRIBUTELIST__((noinline, nothrow)) __ATTRIBUTE_WEAK__;
static void _GLOBAL__sub_I_parser_OC_cpp(void) __ATTRIBUTELIST__((noinline));
uint8_t* memcpy(uint8_t*, uint8_t*, uint64_t);
uint8_t* memmove(uint8_t*, uint8_t*, uint64_t);


/* Global Variable Definitions and Initialization */
static struct l_struct_class_OC_std_KD__KD_ios_base_KD__KD_Init _ZStL8__ioinit;
struct l_struct_class_OC_NBlock* programBlock;
static struct l_array_11_uint8_t _OC_str = { "ERROR: %sn" };
uint32_t yychar;
struct l_struct_union_OC_YYSTYPE yylval;
uint32_t yynerrs;
static __MSALIGN__(16) struct l_array_54_uint8_t _ZL6yypact __attribute__((aligned(16))) = { { 22, -33, -33, -33, 22, 3, 22, -33, -33, -33, 19, -33, 64u, 6, 47, -33, -33, 22, 22, 17, -33, -33, -33, -33, -33, -33, -33, -33, -33, -33, 22, -33, 64u, 64u, 24, 22, 2, 64u, -33, 22, 64u, -33, 25, 2, 64u, 29, 2, 11, 4, -33, -33, -33, 8, -33 } };
static __MSALIGN__(16) struct l_array_278_uint8_t _ZL11yytranslate __attribute__((aligned(16))) = { { 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 } };
static __MSALIGN__(16) struct l_array_87_uint8_t _ZL7yycheck __attribute__((aligned(16))) = { { 0, 6, 4, 0, 36, 3, 6, 3, 4, 5, 10, 3, 4, 5, 46, 17, 18, 13, 12, 13, 16, 13, 3, 12, 16, 3, 4, 5, 30, 12, 13, 12, 13, 35, 48, 13, 36, 39, 14, 14, -1, 17, 17, 43, 15, -1, 46, 52, 48, -1, -1, -1, 52, 6, 7, 8, 9, 10, 11, -1, -1, 14, -1, -1, -1, -1, 19, 20, 21, 22, 6, 7, 8, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1, 19, 20, 21, 22 } };
static __MSALIGN__(16) struct l_array_87_uint8_t _ZL7yytable __attribute__((aligned(16))) = { { 10, 16, 14, 15, 41, 1, 10, 1, 2, 3, 19, 1, 2, 3, 50, 32, 33, 4, 17, 18, 51, 4, 1, 35, 53, 1, 2, 3, 37, 35, 36, 17, 18, 40, 52, 4, 43, 44, 38, 45, 0, 39, 46, 47, 48, 0, 43, 16, 10, 0, 0, 0, 10, 20, 21, 22, 23, 24, 25, 0, 0, 31, 0, 0, 0, 0, 26, 27, 28, 29, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 0, 26, 27, 28, 29 } };
static __MSALIGN__(16) struct l_array_54_uint8_t _ZL8yydefact __attribute__((aligned(16))) = { { 0, 16, 17, 18, 0, 0, 2, 3, 5, 6, 21, 22, 7, 21, 0, 1, 4, 0, 25, 10, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0, 24, 19, 26, 0, 0, 13, 23, 20, 0, 11, 14, 0, 0, 27, 0, 0, 10, 0, 12, 15, 9, 0, 8 } };
static __MSALIGN__(16) struct l_array_38_uint8_t _ZL4yyr2 __attribute__((aligned(16))) = { { 0, 2, 1, 1, 2, 1, 1, 1, 3, 2, 2, 4, 6, 0, 1, 3, 1, 1, 1, 3, 4, 1, 1, 3, 3, 0, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
static __MSALIGN__(16) struct l_array_38_uint8_t _ZL4yyr1 __attribute__((aligned(16))) = { { 0, 23, 24, 25, 25, 26, 26, 26, 27, 27, 28, 28, 29, 30, 30, 30, 31, 32, 32, 33, 33, 33, 33, 33, 33, 34, 34, 34, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35 } };
static struct l_array_13_uint8_t _ZL7yypgoto = { { -33, -33, -14, -5, -33, -32, -33, -33, 0, -33, -2, -33, -33 } };
static struct l_array_13_uint8_t _ZL9yydefgoto = { { -1, 5, 6, 7, 49, 8, 9, 42, 13, 11, 12, 34, 30 } };
static struct l_array_13_uint8_t _OC_str_OC_1 = { "syntax error" };
static struct l_array_18_uint8_t _OC_str_OC_2 = { "Error: discarding" };
static struct l_array_15_uint8_t _OC_str_OC_3 = { "Error: popping" };
static __MSALIGN__(16) struct l_array_54_uint8_t _ZL6yystos __attribute__((aligned(16))) = { { 0, 3, 4, 5, 13, 24, 25, 26, 28, 29, 31, 32, 33, 31, 33, 0, 26, 12, 13, 31, 6, 7, 8, 9, 10, 11, 19, 20, 21, 22, 35, 14, 33, 33, 34, 12, 13, 33, 14, 17, 33, 28, 30, 31, 33, 14, 17, 31, 15, 27, 28, 16, 25, 16 } };
static struct l_array_17_uint8_t _OC_str_OC_4 = { "memory exhausted" };
static struct l_array_30_uint8_t _OC_str_OC_5 = { "Cleanup: discarding lookahead" };
static struct l_array_17_uint8_t _OC_str_OC_6 = { "Cleanup: popping" };
struct l_unnamed_1 _ZTV6NBlock __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI6NBlock)), ((uint8_t*)_ZN6NBlockD2Ev), ((uint8_t*)_ZN6NBlockD0Ev), ((uint8_t*)_ZN6NBlock7codeGenER14CodeGenContext) } } };
struct l_array_8_uint8_t _ZTS6NBlock __attribute__((common)) = { "6NBlock" };
struct l_array_14_uint8_t _ZTS11NExpression __attribute__((common)) = { "11NExpression" };
struct l_array_6_uint8_t _ZTS4Node __attribute__((common)) = { "4Node" };
struct l_unnamed_2 _ZTI4Node __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv117__class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS4Node.array[((int32_t)0)])) };
struct l_unnamed_3 _ZTI11NExpression __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS11NExpression.array[((int32_t)0)])), ((uint8_t*)(&_ZTI4Node)) };
struct l_unnamed_3 _ZTI6NBlock __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS6NBlock.array[((int32_t)0)])), ((uint8_t*)(&_ZTI11NExpression)) };
struct l_unnamed_1 _ZTV11NExpression __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI11NExpression)), ((uint8_t*)_ZN11NExpressionD2Ev), ((uint8_t*)_ZN11NExpressionD0Ev), ((uint8_t*)_ZN4Node7codeGenER14CodeGenContext) } } };
struct l_unnamed_1 _ZTV4Node __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI4Node)), ((uint8_t*)_ZN4NodeD2Ev), ((uint8_t*)_ZN4NodeD0Ev), ((uint8_t*)_ZN4Node7codeGenER14CodeGenContext) } } };
struct l_unnamed_1 _ZTV20NExpressionStatement __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI20NExpressionStatement)), ((uint8_t*)_ZN20NExpressionStatementD2Ev), ((uint8_t*)_ZN20NExpressionStatementD0Ev), ((uint8_t*)_ZN20NExpressionStatement7codeGenER14CodeGenContext) } } };
struct l_array_23_uint8_t _ZTS20NExpressionStatement __attribute__((common)) = { "20NExpressionStatement" };
struct l_array_13_uint8_t _ZTS10NStatement __attribute__((common)) = { "10NStatement" };
struct l_unnamed_3 _ZTI10NStatement __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS10NStatement.array[((int32_t)0)])), ((uint8_t*)(&_ZTI4Node)) };
struct l_unnamed_3 _ZTI20NExpressionStatement __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS20NExpressionStatement.array[((int32_t)0)])), ((uint8_t*)(&_ZTI10NStatement)) };
struct l_unnamed_1 _ZTV10NStatement __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI10NStatement)), ((uint8_t*)_ZN10NStatementD2Ev), ((uint8_t*)_ZN10NStatementD0Ev), ((uint8_t*)_ZN4Node7codeGenER14CodeGenContext) } } };
struct l_unnamed_1 _ZTV20NVariableDeclaration __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI20NVariableDeclaration)), ((uint8_t*)_ZN20NVariableDeclarationD2Ev), ((uint8_t*)_ZN20NVariableDeclarationD0Ev), ((uint8_t*)_ZN20NVariableDeclaration7codeGenER14CodeGenContext) } } };
struct l_array_23_uint8_t _ZTS20NVariableDeclaration __attribute__((common)) = { "20NVariableDeclaration" };
struct l_unnamed_3 _ZTI20NVariableDeclaration __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS20NVariableDeclaration.array[((int32_t)0)])), ((uint8_t*)(&_ZTI10NStatement)) };
struct l_unnamed_1 _ZTV20NFunctionDeclaration __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI20NFunctionDeclaration)), ((uint8_t*)_ZN20NFunctionDeclarationD2Ev), ((uint8_t*)_ZN20NFunctionDeclarationD0Ev), ((uint8_t*)_ZN20NFunctionDeclaration7codeGenER14CodeGenContext) } } };
struct l_array_23_uint8_t _ZTS20NFunctionDeclaration __attribute__((common)) = { "20NFunctionDeclaration" };
struct l_unnamed_3 _ZTI20NFunctionDeclaration __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS20NFunctionDeclaration.array[((int32_t)0)])), ((uint8_t*)(&_ZTI10NStatement)) };
struct l_unnamed_1 _ZTV11NIdentifier __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI11NIdentifier)), ((uint8_t*)_ZN11NIdentifierD2Ev), ((uint8_t*)_ZN11NIdentifierD0Ev), ((uint8_t*)_ZN11NIdentifier7codeGenER14CodeGenContext) } } };
struct l_array_14_uint8_t _ZTS11NIdentifier __attribute__((common)) = { "11NIdentifier" };
struct l_unnamed_3 _ZTI11NIdentifier __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS11NIdentifier.array[((int32_t)0)])), ((uint8_t*)(&_ZTI11NExpression)) };
struct l_unnamed_1 _ZTV7NDouble __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI7NDouble)), ((uint8_t*)_ZN7NDoubleD2Ev), ((uint8_t*)_ZN7NDoubleD0Ev), ((uint8_t*)_ZN7NDouble7codeGenER14CodeGenContext) } } };
struct l_array_9_uint8_t _ZTS7NDouble __attribute__((common)) = { "7NDouble" };
struct l_unnamed_3 _ZTI7NDouble __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS7NDouble.array[((int32_t)0)])), ((uint8_t*)(&_ZTI11NExpression)) };
struct l_unnamed_1 _ZTV11NAssignment __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI11NAssignment)), ((uint8_t*)_ZN11NAssignmentD2Ev), ((uint8_t*)_ZN11NAssignmentD0Ev), ((uint8_t*)_ZN11NAssignment7codeGenER14CodeGenContext) } } };
struct l_array_14_uint8_t _ZTS11NAssignment __attribute__((common)) = { "11NAssignment" };
struct l_unnamed_3 _ZTI11NAssignment __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS11NAssignment.array[((int32_t)0)])), ((uint8_t*)(&_ZTI11NExpression)) };
struct l_unnamed_1 _ZTV11NMethodCall __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI11NMethodCall)), ((uint8_t*)_ZN11NMethodCallD2Ev), ((uint8_t*)_ZN11NMethodCallD0Ev), ((uint8_t*)_ZN11NMethodCall7codeGenER14CodeGenContext) } } };
struct l_array_14_uint8_t _ZTS11NMethodCall __attribute__((common)) = { "11NMethodCall" };
struct l_unnamed_3 _ZTI11NMethodCall __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS11NMethodCall.array[((int32_t)0)])), ((uint8_t*)(&_ZTI11NExpression)) };
struct l_unnamed_1 _ZTV15NBinaryOperator __attribute__((common)) = { { { ((uint8_t*)/*NULL*/0), ((uint8_t*)(&_ZTI15NBinaryOperator)), ((uint8_t*)_ZN15NBinaryOperatorD2Ev), ((uint8_t*)_ZN15NBinaryOperatorD0Ev), ((uint8_t*)_ZN15NBinaryOperator7codeGenER14CodeGenContext) } } };
struct l_array_18_uint8_t _ZTS15NBinaryOperator __attribute__((common)) = { "15NBinaryOperator" };
struct l_unnamed_3 _ZTI15NBinaryOperator __attribute__((common)) = { ((uint8_t*)((&(&_ZTVN10__cxxabiv120__si_class_type_infoE)[((int64_t)UINT64_C(2))]))), ((&_ZTS15NBinaryOperator.array[((int32_t)0)])), ((uint8_t*)(&_ZTI11NExpression)) };
static struct l_array_9_uint8_t _OC_str_OC_7 = { "Deleting" };
static struct l_array_26_uint8_t _OC_str_OC_8 = { "vector::_M_realloc_insert" };


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
static __forceinline uint64_t llvm_mul_u64(uint64_t a, uint64_t b) {
  uint64_t r = a * b;
  return r;
}
static __forceinline uint64_t llvm_udiv_u64(uint64_t a, uint64_t b) {
  uint64_t r = a / b;
  return r;
}
static __forceinline uint64_t llvm_sdiv_u64(int64_t a, int64_t b) {
  uint64_t r = a / b;
  return r;
}
static __forceinline uint32_t llvm_neg_u32(uint32_t a) {
  uint32_t r = -a;
  return r;
}
static __forceinline uint64_t llvm_neg_u64(uint64_t a) {
  uint64_t r = -a;
  return r;
}


/* Function Bodies */

static void __cxx_global_var_init(void) {
  uint32_t llvm_cbe_tmp__1;

  _ZNSt8ios_base4InitC1Ev((&_ZStL8__ioinit));
  llvm_cbe_tmp__1 = __cxa_atexit(((l_fptr_1*)_ZNSt8ios_base4InitD1Ev), ((&_ZStL8__ioinit.field0)), (&__dso_handle));
}


void _Z7yyerrorPKc(uint8_t* llvm_cbe_tmp__2) {
  uint8_t* llvm_cbe_tmp__3;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__4;
  uint32_t llvm_cbe_tmp__5;

  llvm_cbe_tmp__3 = llvm_cbe_tmp__2;
  llvm_cbe_tmp__4 = llvm_cbe_tmp__3;
  llvm_cbe_tmp__5 = printf(((&_OC_str.array[((int32_t)0)])), llvm_cbe_tmp__4);
}


uint32_t _Z7yyparsev(void) {
  uint32_t llvm_cbe_tmp__6;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__7;    /* Address-exposed local */
  __MSALIGN__(16) struct l_array_200_uint16_t llvm_cbe_tmp__8 __attribute__((aligned(16)));    /* Address-exposed local */
  uint16_t* llvm_cbe_tmp__9;    /* Address-exposed local */
  uint16_t* llvm_cbe_tmp__10;    /* Address-exposed local */
  __MSALIGN__(16) struct l_array_200_struct_AC_l_struct_union_OC_YYSTYPE llvm_cbe_tmp__11 __attribute__((aligned(16)));    /* Address-exposed local */
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__12;    /* Address-exposed local */
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__13;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__14;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__15;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__16;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__17;    /* Address-exposed local */
  struct l_struct_union_OC_YYSTYPE llvm_cbe_tmp__18;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__19;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__20;    /* Address-exposed local */
  uint16_t* llvm_cbe_tmp__21;    /* Address-exposed local */
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__22;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__23;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__24;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__25;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__26;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string llvm_cbe_tmp__27;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_0 llvm_cbe_tmp__28;    /* Address-exposed local */
  bool llvm_cbe_tmp__29;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__30;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__31;    /* Address-exposed local */
  uint16_t* llvm_cbe_tmp__32;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__33;
  uint16_t* llvm_cbe_tmp__34;
  uint32_t llvm_cbe_tmp__35;
  uint16_t* llvm_cbe_tmp__36;
  uint16_t* llvm_cbe_tmp__37;
  uint64_t llvm_cbe_tmp__38;
  uint16_t* llvm_cbe_tmp__39;
  uint16_t* llvm_cbe_tmp__40;
  uint16_t* llvm_cbe_tmp__41;
  uint64_t llvm_cbe_tmp__42;
  uint64_t llvm_cbe_tmp__43;
  uint64_t llvm_cbe_tmp__44;
  uint16_t* llvm_cbe_tmp__45;
  uint64_t llvm_cbe_tmp__46;
  uint8_t* llvm_cbe_tmp__47;
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__48;
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__49;
  uint16_t* llvm_cbe_tmp__50;
  uint64_t llvm_cbe_tmp__51;
  uint8_t* llvm_cbe_tmp__52;
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__53;
  uint64_t llvm_cbe_tmp__54;
  uint64_t llvm_cbe_tmp__55;
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__56;
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__57;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__58;
  uint64_t llvm_cbe_tmp__59;
  uint8_t* llvm_cbe_tmp__60;
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__61;
  uint64_t llvm_cbe_tmp__62;
  uint64_t llvm_cbe_tmp__63;
  struct l_struct_union_OC_yyalloc* llvm_cbe_tmp__64;
  uint16_t* llvm_cbe_tmp__65;
  uint16_t* llvm_cbe_tmp__66;
  uint16_t* llvm_cbe_tmp__67;
  uint64_t llvm_cbe_tmp__68;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__69;
  uint64_t llvm_cbe_tmp__70;
  uint16_t* llvm_cbe_tmp__71;
  uint64_t llvm_cbe_tmp__72;
  uint16_t* llvm_cbe_tmp__73;
  uint32_t llvm_cbe_tmp__74;
  uint32_t llvm_cbe_tmp__75;
  uint8_t llvm_cbe_tmp__76;
  uint32_t llvm_cbe_tmp__77;
  uint32_t llvm_cbe_tmp__78;
  uint32_t llvm_cbe_tmp__79;
  uint32_t llvm_cbe_tmp__80;
  uint32_t llvm_cbe_tmp__81;
  uint32_t llvm_cbe_tmp__82;
  uint8_t llvm_cbe_tmp__83;
  uint32_t llvm_cbe_tmp__84;
  uint32_t llvm_cbe_tmp__85;
  uint32_t llvm_cbe_tmp__85__PHI_TEMPORARY;
  uint32_t llvm_cbe_tmp__86;
  uint32_t llvm_cbe_tmp__87;
  uint32_t llvm_cbe_tmp__88;
  uint32_t llvm_cbe_tmp__89;
  uint32_t llvm_cbe_tmp__90;
  uint8_t llvm_cbe_tmp__91;
  uint32_t llvm_cbe_tmp__92;
  uint32_t llvm_cbe_tmp__93;
  uint8_t llvm_cbe_tmp__94;
  uint32_t llvm_cbe_tmp__95;
  uint32_t llvm_cbe_tmp__96;
  uint32_t llvm_cbe_tmp__97;
  uint32_t llvm_cbe_tmp__98;
  uint32_t llvm_cbe_tmp__99;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__100;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__101;
  uint8_t* llvm_cbe_tmp__102;
  uint32_t llvm_cbe_tmp__103;
  uint8_t llvm_cbe_tmp__104;
  uint32_t llvm_cbe_tmp__105;
  uint32_t llvm_cbe_tmp__106;
  uint8_t llvm_cbe_tmp__107;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__108;
  uint32_t llvm_cbe_tmp__109;
  uint8_t* llvm_cbe_tmp__110;
  uint32_t llvm_cbe_tmp__111;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__112;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__113;
  uint8_t* llvm_cbe_tmp__114;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__115;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__116;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__117;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__118;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__119;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__120;
  uint8_t* llvm_cbe_tmp__121;
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__122;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__123;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__124;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__125;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__126;
  uint8_t* llvm_cbe_tmp__127;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__128;
  uint8_t* llvm_cbe_tmp__129;
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__130;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__131;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__132;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__133;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__134;
  uint8_t* llvm_cbe_tmp__135;
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__136;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__137;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__138;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__139;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__140;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__141;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__142;
  uint8_t* llvm_cbe_tmp__143;
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__144;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__145;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__146;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__147;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__148;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__149;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__150;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__151;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__152;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__153;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__154;
  uint8_t* llvm_cbe_tmp__155;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__156;
  uint8_t* llvm_cbe_tmp__157;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__158;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__159;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__160;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__161;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__162;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__163;
  uint8_t* llvm_cbe_tmp__164;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__165;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__166;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__167;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__168;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__169;
  uint8_t* llvm_cbe_tmp__170;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__171;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__172;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__173;
  uint8_t* llvm_cbe_tmp__174;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__175;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__176;
  uint8_t* llvm_cbe_tmp__177;
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__178;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__179;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__180;
  uint8_t* llvm_cbe_tmp__181;
  double llvm_cbe_tmp__182;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__183;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__184;
  uint8_t* llvm_cbe_tmp__185;
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__186;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__187;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__188;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__189;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__190;
  uint8_t* llvm_cbe_tmp__191;
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__192;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__193;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__194;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__195;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__196;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__197;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__198;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__199;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__200;
  uint8_t* llvm_cbe_tmp__201;
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__202;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__203;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__204;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__205;
  uint32_t llvm_cbe_tmp__206;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__207;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__208;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__209;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__210;
  uint8_t* llvm_cbe_tmp__211;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__212;
  uint8_t* llvm_cbe_tmp__213;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__214;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__215;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__216;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__217;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__218;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__219;
  uint32_t llvm_cbe_tmp__220;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__221;
  uint32_t llvm_cbe_tmp__222;
  uint16_t* llvm_cbe_tmp__223;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__224;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__225;
  uint8_t* llvm_cbe_tmp__226;
  uint32_t llvm_cbe_tmp__227;
  uint8_t llvm_cbe_tmp__228;
  uint32_t llvm_cbe_tmp__229;
  uint8_t llvm_cbe_tmp__230;
  uint16_t* llvm_cbe_tmp__231;
  uint16_t llvm_cbe_tmp__232;
  uint32_t llvm_cbe_tmp__233;
  uint32_t llvm_cbe_tmp__234;
  uint32_t llvm_cbe_tmp__235;
  uint8_t llvm_cbe_tmp__236;
  uint16_t* llvm_cbe_tmp__237;
  uint16_t llvm_cbe_tmp__238;
  uint32_t llvm_cbe_tmp__239;
  uint8_t llvm_cbe_tmp__240;
  uint32_t llvm_cbe_tmp__241;
  uint32_t llvm_cbe_tmp__242;
  uint8_t llvm_cbe_tmp__243;
  uint32_t llvm_cbe_tmp__244;
  uint32_t llvm_cbe_tmp__245;
  uint32_t llvm_cbe_tmp__245__PHI_TEMPORARY;
  uint32_t llvm_cbe_tmp__246;
  uint32_t llvm_cbe_tmp__247;
  uint32_t llvm_cbe_tmp__248;
  uint8_t llvm_cbe_tmp__249;
  uint32_t llvm_cbe_tmp__250;
  uint32_t llvm_cbe_tmp__251;
  uint32_t llvm_cbe_tmp__251__PHI_TEMPORARY;
  uint32_t llvm_cbe_tmp__252;
  uint32_t llvm_cbe_tmp__252__PHI_TEMPORARY;
  uint32_t llvm_cbe_tmp__253;
  uint32_t llvm_cbe_tmp__254;
  uint32_t llvm_cbe_tmp__255;
  uint32_t llvm_cbe_tmp__256;
  uint32_t llvm_cbe_tmp__257;
  uint32_t llvm_cbe_tmp__258;
  uint32_t llvm_cbe_tmp__259;
  uint8_t llvm_cbe_tmp__260;
  uint32_t llvm_cbe_tmp__261;
  uint32_t llvm_cbe_tmp__262;
  uint32_t llvm_cbe_tmp__263;
  uint32_t llvm_cbe_tmp__264;
  uint32_t llvm_cbe_tmp__265;
  uint8_t llvm_cbe_tmp__266;
  uint32_t llvm_cbe_tmp__267;
  uint8_t llvm_cbe_tmp__268;
  uint32_t llvm_cbe_tmp__269;
  uint16_t* llvm_cbe_tmp__270;
  uint16_t* llvm_cbe_tmp__271;
  uint32_t llvm_cbe_tmp__272;
  uint8_t llvm_cbe_tmp__273;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__274;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__275;
  uint16_t* llvm_cbe_tmp__276;
  uint16_t* llvm_cbe_tmp__277;
  uint16_t llvm_cbe_tmp__278;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__279;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__280;
  uint8_t* llvm_cbe_tmp__281;
  uint32_t llvm_cbe_tmp__282;
  uint32_t llvm_cbe_tmp__283;
  uint32_t llvm_cbe_tmp__284;
  uint32_t llvm_cbe_tmp__285;
  uint8_t llvm_cbe_tmp__286;
  uint32_t llvm_cbe_tmp__287;
  uint32_t llvm_cbe_tmp__288;
  uint32_t llvm_cbe_tmp__288__PHI_TEMPORARY;
  uint32_t llvm_cbe_tmp__289;
  uint32_t llvm_cbe_tmp__290;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__291;
  uint32_t llvm_cbe_tmp__292;
  uint16_t* llvm_cbe_tmp__293;
  uint16_t* llvm_cbe_tmp__294;
  uint16_t* llvm_cbe_tmp__295;
  uint16_t* llvm_cbe_tmp__296;
  uint16_t llvm_cbe_tmp__297;
  uint8_t llvm_cbe_tmp__298;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__299;
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__300;
  uint16_t* llvm_cbe_tmp__301;
  uint16_t* llvm_cbe_tmp__302;
  uint16_t* llvm_cbe_tmp__303;
  uint32_t llvm_cbe_tmp__304;

  llvm_cbe_tmp__17 = 0;
  llvm_cbe_tmp__19 = 0;
  llvm_cbe_tmp__32 = (&llvm_cbe_tmp__8.array[((int32_t)0)]);
  llvm_cbe_tmp__9 = llvm_cbe_tmp__32;
  llvm_cbe_tmp__10 = llvm_cbe_tmp__32;
  llvm_cbe_tmp__33 = (&llvm_cbe_tmp__11.array[((int32_t)0)]);
  llvm_cbe_tmp__12 = llvm_cbe_tmp__33;
  llvm_cbe_tmp__13 = llvm_cbe_tmp__33;
  llvm_cbe_tmp__14 = UINT64_C(200);
  llvm_cbe_tmp__6 = 0;
  llvm_cbe_tmp__7 = 0;
  yynerrs = 0;
  yychar = -2;
  goto llvm_cbe_tmp__305;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__305:
  llvm_cbe_tmp__35 = llvm_cbe_tmp__6;
  llvm_cbe_tmp__36 = llvm_cbe_tmp__10;
  *llvm_cbe_tmp__36 = (((uint16_t)llvm_cbe_tmp__35));
  llvm_cbe_tmp__37 = llvm_cbe_tmp__9;
  llvm_cbe_tmp__38 = llvm_cbe_tmp__14;
  llvm_cbe_tmp__39 = llvm_cbe_tmp__10;
  if ((((((uint64_t)((&((&llvm_cbe_tmp__37[((int64_t)llvm_cbe_tmp__38)]))[((int64_t)UINT64_C(18446744073709551615))]))) <= ((uint64_t)llvm_cbe_tmp__39))&1))) {
    goto llvm_cbe_tmp__306;
  } else {
    goto llvm_cbe_tmp__307;
  }

llvm_cbe_tmp__306:
  llvm_cbe_tmp__40 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__41 = llvm_cbe_tmp__9;
  llvm_cbe_tmp__20 = (llvm_add_u64((llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__40)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__41)))), UINT64_C(2))), UINT64_C(1)));
  llvm_cbe_tmp__42 = llvm_cbe_tmp__14;
  if ((((((uint64_t)UINT64_C(10000)) <= ((uint64_t)llvm_cbe_tmp__42))&1))) {
    goto llvm_cbe_tmp__308;
  } else {
    goto llvm_cbe_tmp__309;
  }

llvm_cbe_tmp__309:
  llvm_cbe_tmp__43 = llvm_cbe_tmp__14;
  llvm_cbe_tmp__14 = (llvm_mul_u64(llvm_cbe_tmp__43, UINT64_C(2)));
  llvm_cbe_tmp__44 = llvm_cbe_tmp__14;
  if ((((((uint64_t)UINT64_C(10000)) < ((uint64_t)llvm_cbe_tmp__44))&1))) {
    goto llvm_cbe_tmp__310;
  } else {
    goto llvm_cbe_tmp__311;
  }

llvm_cbe_tmp__310:
  llvm_cbe_tmp__14 = UINT64_C(10000);
  goto llvm_cbe_tmp__311;

llvm_cbe_tmp__311:
  llvm_cbe_tmp__45 = llvm_cbe_tmp__9;
  llvm_cbe_tmp__21 = llvm_cbe_tmp__45;
  llvm_cbe_tmp__46 = llvm_cbe_tmp__14;
  llvm_cbe_tmp__47 = malloc((llvm_add_u64((llvm_mul_u64(llvm_cbe_tmp__46, UINT64_C(10))), UINT64_C(7))));
  llvm_cbe_tmp__22 = (((struct l_struct_union_OC_yyalloc*)llvm_cbe_tmp__47));
  llvm_cbe_tmp__48 = llvm_cbe_tmp__22;
  if ((((llvm_cbe_tmp__48 != ((struct l_struct_union_OC_yyalloc*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__312;
  } else {
    goto llvm_cbe_tmp__313;
  }

llvm_cbe_tmp__312:
  goto llvm_cbe_tmp__314;

llvm_cbe_tmp__314:
  llvm_cbe_tmp__49 = llvm_cbe_tmp__22;
  llvm_cbe_tmp__50 = llvm_cbe_tmp__9;
  llvm_cbe_tmp__51 = llvm_cbe_tmp__20;
  llvm_cbe_tmp__52 = memcpy((((uint8_t*)(((uint16_t*)llvm_cbe_tmp__49)))), (((uint8_t*)llvm_cbe_tmp__50)), (llvm_mul_u64(llvm_cbe_tmp__51, UINT64_C(2))));
  llvm_cbe_tmp__53 = llvm_cbe_tmp__22;
  llvm_cbe_tmp__9 = (((uint16_t*)llvm_cbe_tmp__53));
  llvm_cbe_tmp__54 = llvm_cbe_tmp__14;
  llvm_cbe_tmp__23 = (llvm_add_u64((llvm_mul_u64(llvm_cbe_tmp__54, UINT64_C(2))), UINT64_C(7)));
  llvm_cbe_tmp__55 = llvm_cbe_tmp__23;
  llvm_cbe_tmp__56 = llvm_cbe_tmp__22;
  llvm_cbe_tmp__22 = ((&llvm_cbe_tmp__56[((int64_t)(llvm_udiv_u64(llvm_cbe_tmp__55, UINT64_C(8))))]));
  goto llvm_cbe_tmp__315;

llvm_cbe_tmp__315:
  goto llvm_cbe_tmp__316;

llvm_cbe_tmp__316:
  llvm_cbe_tmp__57 = llvm_cbe_tmp__22;
  llvm_cbe_tmp__58 = llvm_cbe_tmp__12;
  llvm_cbe_tmp__59 = llvm_cbe_tmp__20;
  llvm_cbe_tmp__60 = memcpy((((uint8_t*)(((struct l_struct_union_OC_YYSTYPE*)llvm_cbe_tmp__57)))), (((uint8_t*)llvm_cbe_tmp__58)), (llvm_mul_u64(llvm_cbe_tmp__59, UINT64_C(8))));
  llvm_cbe_tmp__61 = llvm_cbe_tmp__22;
  llvm_cbe_tmp__12 = (((struct l_struct_union_OC_YYSTYPE*)llvm_cbe_tmp__61));
  llvm_cbe_tmp__62 = llvm_cbe_tmp__14;
  llvm_cbe_tmp__24 = (llvm_add_u64((llvm_mul_u64(llvm_cbe_tmp__62, UINT64_C(8))), UINT64_C(7)));
  llvm_cbe_tmp__63 = llvm_cbe_tmp__24;
  llvm_cbe_tmp__64 = llvm_cbe_tmp__22;
  llvm_cbe_tmp__22 = ((&llvm_cbe_tmp__64[((int64_t)(llvm_udiv_u64(llvm_cbe_tmp__63, UINT64_C(8))))]));
  goto llvm_cbe_tmp__317;

llvm_cbe_tmp__317:
  llvm_cbe_tmp__65 = llvm_cbe_tmp__21;
  if ((((llvm_cbe_tmp__65 != ((&llvm_cbe_tmp__8.array[((int32_t)0)])))&1))) {
    goto llvm_cbe_tmp__318;
  } else {
    goto llvm_cbe_tmp__319;
  }

llvm_cbe_tmp__318:
  llvm_cbe_tmp__66 = llvm_cbe_tmp__21;
  free((((uint8_t*)llvm_cbe_tmp__66)));
  goto llvm_cbe_tmp__319;

llvm_cbe_tmp__319:
  llvm_cbe_tmp__67 = llvm_cbe_tmp__9;
  llvm_cbe_tmp__68 = llvm_cbe_tmp__20;
  llvm_cbe_tmp__10 = ((&((&llvm_cbe_tmp__67[((int64_t)llvm_cbe_tmp__68)]))[((int64_t)UINT64_C(18446744073709551615))]));
  llvm_cbe_tmp__69 = llvm_cbe_tmp__12;
  llvm_cbe_tmp__70 = llvm_cbe_tmp__20;
  llvm_cbe_tmp__13 = ((&((&llvm_cbe_tmp__69[((int64_t)llvm_cbe_tmp__70)]))[((int64_t)UINT64_C(18446744073709551615))]));
  llvm_cbe_tmp__71 = llvm_cbe_tmp__9;
  llvm_cbe_tmp__72 = llvm_cbe_tmp__14;
  llvm_cbe_tmp__73 = llvm_cbe_tmp__10;
  if ((((((uint64_t)((&((&llvm_cbe_tmp__71[((int64_t)llvm_cbe_tmp__72)]))[((int64_t)UINT64_C(18446744073709551615))]))) <= ((uint64_t)llvm_cbe_tmp__73))&1))) {
    goto llvm_cbe_tmp__320;
  } else {
    goto llvm_cbe_tmp__321;
  }

llvm_cbe_tmp__321:
  goto llvm_cbe_tmp__307;

llvm_cbe_tmp__307:
  llvm_cbe_tmp__74 = llvm_cbe_tmp__6;
  if ((((llvm_cbe_tmp__74 == 15u)&1))) {
    goto llvm_cbe_tmp__322;
  } else {
    goto llvm_cbe_tmp__323;
  }

llvm_cbe_tmp__323:
  goto llvm_cbe_tmp__324;

llvm_cbe_tmp__324:
  llvm_cbe_tmp__75 = llvm_cbe_tmp__6;
  llvm_cbe_tmp__76 = *((&_ZL6yypact.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__75)))]));
  llvm_cbe_tmp__15 = (((int32_t)(int8_t)llvm_cbe_tmp__76));
  llvm_cbe_tmp__77 = llvm_cbe_tmp__15;
  if ((((llvm_cbe_tmp__77 == 4294967263u)&1))) {
    goto llvm_cbe_tmp__325;
  } else {
    goto llvm_cbe_tmp__326;
  }

llvm_cbe_tmp__326:
  llvm_cbe_tmp__78 = yychar;
  if ((((llvm_cbe_tmp__78 == 4294967294u)&1))) {
    goto llvm_cbe_tmp__327;
  } else {
    goto llvm_cbe_tmp__328;
  }

llvm_cbe_tmp__327:
  llvm_cbe_tmp__79 = _Z5yylexv();
  yychar = llvm_cbe_tmp__79;
  goto llvm_cbe_tmp__328;

llvm_cbe_tmp__328:
  llvm_cbe_tmp__80 = yychar;
  if ((((((int32_t)llvm_cbe_tmp__80) <= ((int32_t)0u))&1))) {
    goto llvm_cbe_tmp__329;
  } else {
    goto llvm_cbe_tmp__330;
  }

llvm_cbe_tmp__330:
  llvm_cbe_tmp__81 = yychar;
  if ((((((uint32_t)llvm_cbe_tmp__81) <= ((uint32_t)277u))&1))) {
    goto llvm_cbe_tmp__331;
  } else {
    goto llvm_cbe_tmp__332;
  }

llvm_cbe_tmp__332:
  llvm_cbe_tmp__85__PHI_TEMPORARY = 2;   /* for PHI node */
  goto llvm_cbe_tmp__333;

llvm_cbe_tmp__331:
  llvm_cbe_tmp__82 = yychar;
  llvm_cbe_tmp__83 = *((&_ZL11yytranslate.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__82)))]));
  llvm_cbe_tmp__84 = ((uint32_t)(uint8_t)llvm_cbe_tmp__83);
  llvm_cbe_tmp__85__PHI_TEMPORARY = llvm_cbe_tmp__84;   /* for PHI node */
  goto llvm_cbe_tmp__333;

llvm_cbe_tmp__333:
  llvm_cbe_tmp__85 = llvm_cbe_tmp__85__PHI_TEMPORARY;
  llvm_cbe_tmp__17 = llvm_cbe_tmp__85;
  goto llvm_cbe_tmp__334;

llvm_cbe_tmp__329:
  llvm_cbe_tmp__17 = 0;
  yychar = 0;
  goto llvm_cbe_tmp__334;

llvm_cbe_tmp__334:
  llvm_cbe_tmp__86 = llvm_cbe_tmp__17;
  llvm_cbe_tmp__87 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__15 = (llvm_add_u32(llvm_cbe_tmp__87, llvm_cbe_tmp__86));
  llvm_cbe_tmp__88 = llvm_cbe_tmp__15;
  if ((((((int32_t)llvm_cbe_tmp__88) < ((int32_t)0u))&1))) {
    goto llvm_cbe_tmp__335;
  } else {
    goto llvm_cbe_tmp__336;
  }

llvm_cbe_tmp__336:
  llvm_cbe_tmp__89 = llvm_cbe_tmp__15;
  if ((((((int32_t)86u) < ((int32_t)llvm_cbe_tmp__89))&1))) {
    goto llvm_cbe_tmp__335;
  } else {
    goto llvm_cbe_tmp__337;
  }

llvm_cbe_tmp__337:
  llvm_cbe_tmp__90 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__91 = *((&_ZL7yycheck.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__90)))]));
  llvm_cbe_tmp__92 = llvm_cbe_tmp__17;
  if (((((((int32_t)(int8_t)llvm_cbe_tmp__91)) != llvm_cbe_tmp__92)&1))) {
    goto llvm_cbe_tmp__335;
  } else {
    goto llvm_cbe_tmp__338;
  }

llvm_cbe_tmp__338:
  llvm_cbe_tmp__93 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__94 = *((&_ZL7yytable.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__93)))]));
  llvm_cbe_tmp__15 = (((uint32_t)(uint8_t)llvm_cbe_tmp__94));
  llvm_cbe_tmp__95 = llvm_cbe_tmp__15;
  if ((((((int32_t)llvm_cbe_tmp__95) <= ((int32_t)0u))&1))) {
    goto llvm_cbe_tmp__339;
  } else {
    goto llvm_cbe_tmp__340;
  }

llvm_cbe_tmp__340:
  llvm_cbe_tmp__97 = llvm_cbe_tmp__7;
  if ((((llvm_cbe_tmp__97 != 0u)&1))) {
    goto llvm_cbe_tmp__341;
  } else {
    goto llvm_cbe_tmp__342;
  }

llvm_cbe_tmp__341:
  llvm_cbe_tmp__98 = llvm_cbe_tmp__7;
  llvm_cbe_tmp__7 = (llvm_add_u32(llvm_cbe_tmp__98, -1));
  goto llvm_cbe_tmp__342;

llvm_cbe_tmp__342:
  yychar = -2;
  llvm_cbe_tmp__99 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__6 = llvm_cbe_tmp__99;
  llvm_cbe_tmp__100 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__101 = (&llvm_cbe_tmp__100[((int32_t)1)]);
  llvm_cbe_tmp__13 = llvm_cbe_tmp__101;
  llvm_cbe_tmp__102 = memcpy((((uint8_t*)llvm_cbe_tmp__101)), ((uint8_t*)(&yylval)), UINT64_C(8));
  goto llvm_cbe_tmp__343;

llvm_cbe_tmp__339:
  llvm_cbe_tmp__96 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__15 = (llvm_neg_u32(llvm_cbe_tmp__96));
  goto llvm_cbe_tmp__344;

llvm_cbe_tmp__335:
  goto llvm_cbe_tmp__345;

llvm_cbe_tmp__325:
  goto llvm_cbe_tmp__345;

llvm_cbe_tmp__345:
  llvm_cbe_tmp__103 = llvm_cbe_tmp__6;
  llvm_cbe_tmp__104 = *((&_ZL8yydefact.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__103)))]));
  llvm_cbe_tmp__15 = (((uint32_t)(uint8_t)llvm_cbe_tmp__104));
  llvm_cbe_tmp__105 = llvm_cbe_tmp__15;
  if ((((llvm_cbe_tmp__105 == 0u)&1))) {
    goto llvm_cbe_tmp__346;
  } else {
    goto llvm_cbe_tmp__347;
  }

llvm_cbe_tmp__347:
  goto llvm_cbe_tmp__344;

llvm_cbe_tmp__344:
  llvm_cbe_tmp__106 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__107 = *((&_ZL4yyr2.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__106)))]));
  llvm_cbe_tmp__19 = (((uint32_t)(uint8_t)llvm_cbe_tmp__107));
  llvm_cbe_tmp__108 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__109 = llvm_cbe_tmp__19;
  llvm_cbe_tmp__110 = memcpy((((uint8_t*)(&llvm_cbe_tmp__18))), (((uint8_t*)((&llvm_cbe_tmp__108[((int64_t)(((int64_t)(int32_t)(llvm_sub_u32(1, llvm_cbe_tmp__109)))))])))), UINT64_C(8));
  llvm_cbe_tmp__111 = llvm_cbe_tmp__15;
  switch (llvm_cbe_tmp__111) {
  default:
    goto llvm_cbe_tmp__348;
  case 2u:
    goto llvm_cbe_tmp__349;
  case 3u:
    goto llvm_cbe_tmp__350;
  case 4u:
    goto llvm_cbe_tmp__351;
  case 7u:
    goto llvm_cbe_tmp__352;
  case 8u:
    goto llvm_cbe_tmp__353;
  case 9u:
    goto llvm_cbe_tmp__354;
  case 10u:
    goto llvm_cbe_tmp__355;
  case 11u:
    goto llvm_cbe_tmp__356;
  case 12u:
    goto llvm_cbe_tmp__357;
  case 13u:
    goto llvm_cbe_tmp__358;
  case 14u:
    goto llvm_cbe_tmp__359;
  case 15u:
    goto llvm_cbe_tmp__360;
  case 16u:
    goto llvm_cbe_tmp__361;
  case 17u:
    goto llvm_cbe_tmp__362;
  case 18u:
    goto llvm_cbe_tmp__363;
  case 19u:
    goto llvm_cbe_tmp__364;
  case 20u:
    goto llvm_cbe_tmp__365;
  case 21u:
    goto llvm_cbe_tmp__366;
  case 23u:
    goto llvm_cbe_tmp__367;
  case 24u:
    goto llvm_cbe_tmp__368;
  case 25u:
    goto llvm_cbe_tmp__369;
  case 26u:
    goto llvm_cbe_tmp__370;
  case 27u:
    goto llvm_cbe_tmp__371;
  }

llvm_cbe_tmp__371:
  llvm_cbe_tmp__217 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__218 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_8**)((&llvm_cbe_tmp__217[((int64_t)UINT64_C(18446744073709551614))]))));
  llvm_cbe_tmp__219 = llvm_cbe_tmp__13;
  _ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_(llvm_cbe_tmp__218, (((struct l_struct_class_OC_NExpression**)((&(*llvm_cbe_tmp__219))))));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__370:
  llvm_cbe_tmp__213 = _Znwm(UINT64_C(24));
  llvm_cbe_tmp__214 = ((struct l_struct_class_OC_std_KD__KD_vector_OC_8*)llvm_cbe_tmp__213);
  _ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev(llvm_cbe_tmp__214);
  *(((struct l_struct_class_OC_std_KD__KD_vector_OC_8**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__214;
  llvm_cbe_tmp__215 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_8**)(&llvm_cbe_tmp__18)));
  llvm_cbe_tmp__216 = llvm_cbe_tmp__13;
  _ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_(llvm_cbe_tmp__215, (((struct l_struct_class_OC_NExpression**)((&(*llvm_cbe_tmp__216))))));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__369:
  llvm_cbe_tmp__211 = _Znwm(UINT64_C(24));
  llvm_cbe_tmp__212 = ((struct l_struct_class_OC_std_KD__KD_vector_OC_8*)llvm_cbe_tmp__211);
  _ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev(llvm_cbe_tmp__212);
  *(((struct l_struct_class_OC_std_KD__KD_vector_OC_8**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__212;
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__368:
  llvm_cbe_tmp__209 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__210 = *(((struct l_struct_class_OC_NExpression**)((&llvm_cbe_tmp__209[((int64_t)UINT64_C(18446744073709551615))]))));
  *(((struct l_struct_class_OC_NExpression**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__210;
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__367:
  llvm_cbe_tmp__201 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__202 = ((struct l_struct_class_OC_NBinaryOperator*)llvm_cbe_tmp__201);
  llvm_cbe_tmp__203 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__204 = *(((struct l_struct_class_OC_NExpression**)((&llvm_cbe_tmp__203[((int64_t)UINT64_C(18446744073709551614))]))));
  llvm_cbe_tmp__205 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__206 = *(((uint32_t*)((&llvm_cbe_tmp__205[((int64_t)UINT64_C(18446744073709551615))]))));
  llvm_cbe_tmp__207 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__208 = *(((struct l_struct_class_OC_NExpression**)((&(*llvm_cbe_tmp__207)))));
  _ZN15NBinaryOperatorC2ER11NExpressioniS1_(llvm_cbe_tmp__202, llvm_cbe_tmp__204, llvm_cbe_tmp__206, llvm_cbe_tmp__208);
  goto llvm_cbe_tmp__373;

llvm_cbe_tmp__373:
  *(((struct l_struct_class_OC_NExpression**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__202));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__366:
  llvm_cbe_tmp__199 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__200 = *(((struct l_struct_class_OC_NIdentifier**)((&(*llvm_cbe_tmp__199)))));
  *(((struct l_struct_class_OC_NIdentifier**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__200;
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__365:
  llvm_cbe_tmp__191 = _Znwm(UINT64_C(40));
  llvm_cbe_tmp__192 = ((struct l_struct_class_OC_NMethodCall*)llvm_cbe_tmp__191);
  llvm_cbe_tmp__193 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__194 = *(((struct l_struct_class_OC_NIdentifier**)((&llvm_cbe_tmp__193[((int64_t)UINT64_C(18446744073709551613))]))));
  llvm_cbe_tmp__195 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__196 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_8**)((&llvm_cbe_tmp__195[((int64_t)UINT64_C(18446744073709551615))]))));
  _ZN11NMethodCallC2ERK11NIdentifierRSt6vectorIP11NExpressionSaIS5_EE(llvm_cbe_tmp__192, llvm_cbe_tmp__194, llvm_cbe_tmp__196);
  goto llvm_cbe_tmp__374;

llvm_cbe_tmp__374:
  *(((struct l_struct_class_OC_NExpression**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__192));
  llvm_cbe_tmp__197 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__198 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_8**)((&llvm_cbe_tmp__197[((int64_t)UINT64_C(18446744073709551615))]))));
  if ((((llvm_cbe_tmp__198 == ((struct l_struct_class_OC_std_KD__KD_vector_OC_8*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__375;
  } else {
    goto llvm_cbe_tmp__376;
  }

llvm_cbe_tmp__376:
  _ZNSt6vectorIP11NExpressionSaIS1_EED2Ev(llvm_cbe_tmp__198);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__198)));
  goto llvm_cbe_tmp__375;

llvm_cbe_tmp__375:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__364:
  llvm_cbe_tmp__185 = _Znwm(UINT64_C(24));
  llvm_cbe_tmp__186 = ((struct l_struct_class_OC_NAssignment*)llvm_cbe_tmp__185);
  llvm_cbe_tmp__187 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__188 = *(((struct l_struct_class_OC_NIdentifier**)((&llvm_cbe_tmp__187[((int64_t)UINT64_C(18446744073709551614))]))));
  llvm_cbe_tmp__189 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__190 = *(((struct l_struct_class_OC_NExpression**)((&(*llvm_cbe_tmp__189)))));
  _ZN11NAssignmentC2ER11NIdentifierR11NExpression(llvm_cbe_tmp__186, llvm_cbe_tmp__188, llvm_cbe_tmp__190);
  goto llvm_cbe_tmp__377;

llvm_cbe_tmp__377:
  *(((struct l_struct_class_OC_NExpression**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__186));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__363:
  llvm_cbe_tmp__177 = _Znwm(UINT64_C(16));
  llvm_cbe_tmp__178 = ((struct l_struct_class_OC_NDouble*)llvm_cbe_tmp__177);
  llvm_cbe_tmp__179 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__180 = *(((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)((&(*llvm_cbe_tmp__179)))));
  llvm_cbe_tmp__181 = _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv(llvm_cbe_tmp__180);
  llvm_cbe_tmp__182 = atof(llvm_cbe_tmp__181);
  _ZN7NDoubleC2Ed(llvm_cbe_tmp__178, llvm_cbe_tmp__182);
  goto llvm_cbe_tmp__378;

llvm_cbe_tmp__378:
  *(((struct l_struct_class_OC_NExpression**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__178));
  llvm_cbe_tmp__183 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__184 = *(((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)((&(*llvm_cbe_tmp__183)))));
  if ((((llvm_cbe_tmp__184 == ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__379;
  } else {
    goto llvm_cbe_tmp__380;
  }

llvm_cbe_tmp__380:
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(llvm_cbe_tmp__184);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__184)));
  goto llvm_cbe_tmp__379;

llvm_cbe_tmp__379:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__362:
  llvm_cbe_tmp__170 = _Znwm(UINT64_C(40));
  llvm_cbe_tmp__29 = ((1) & 1);
  llvm_cbe_tmp__171 = ((struct l_struct_class_OC_NIdentifier*)llvm_cbe_tmp__170);
  llvm_cbe_tmp__172 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__173 = *(((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)((&(*llvm_cbe_tmp__172)))));
  llvm_cbe_tmp__174 = _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv(llvm_cbe_tmp__173);
  _ZNSaIcEC1Ev((&llvm_cbe_tmp__28));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_((&llvm_cbe_tmp__27), llvm_cbe_tmp__174, (&llvm_cbe_tmp__28));
  goto llvm_cbe_tmp__381;

llvm_cbe_tmp__381:
  _ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(llvm_cbe_tmp__171, (&llvm_cbe_tmp__27));
  goto llvm_cbe_tmp__382;

llvm_cbe_tmp__382:
  llvm_cbe_tmp__29 = ((0) & 1);
  *(((struct l_struct_class_OC_NExpression**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__171));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev((&llvm_cbe_tmp__27));
  _ZNSaIcED1Ev((&llvm_cbe_tmp__28));
  llvm_cbe_tmp__175 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__176 = *(((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)((&(*llvm_cbe_tmp__175)))));
  if ((((llvm_cbe_tmp__176 == ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__383;
  } else {
    goto llvm_cbe_tmp__384;
  }

llvm_cbe_tmp__384:
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(llvm_cbe_tmp__176);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__176)));
  goto llvm_cbe_tmp__383;

llvm_cbe_tmp__383:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__361:
  llvm_cbe_tmp__164 = _Znwm(UINT64_C(40));
  llvm_cbe_tmp__165 = ((struct l_struct_class_OC_NIdentifier*)llvm_cbe_tmp__164);
  llvm_cbe_tmp__166 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__167 = *(((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)((&(*llvm_cbe_tmp__166)))));
  _ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(llvm_cbe_tmp__165, llvm_cbe_tmp__167);
  goto llvm_cbe_tmp__385;

llvm_cbe_tmp__385:
  *(((struct l_struct_class_OC_NIdentifier**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__165;
  llvm_cbe_tmp__168 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__169 = *(((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string**)((&(*llvm_cbe_tmp__168)))));
  if ((((llvm_cbe_tmp__169 == ((struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__386;
  } else {
    goto llvm_cbe_tmp__387;
  }

llvm_cbe_tmp__387:
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(llvm_cbe_tmp__169);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__169)));
  goto llvm_cbe_tmp__386;

llvm_cbe_tmp__386:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__360:
  llvm_cbe_tmp__161 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__162 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_3**)((&llvm_cbe_tmp__161[((int64_t)UINT64_C(18446744073709551614))]))));
  llvm_cbe_tmp__163 = llvm_cbe_tmp__13;
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_(llvm_cbe_tmp__162, (((struct l_struct_class_OC_NVariableDeclaration**)((&(*llvm_cbe_tmp__163))))));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__359:
  llvm_cbe_tmp__157 = _Znwm(UINT64_C(24));
  llvm_cbe_tmp__158 = ((struct l_struct_class_OC_std_KD__KD_vector_OC_3*)llvm_cbe_tmp__157);
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev(llvm_cbe_tmp__158);
  *(((struct l_struct_class_OC_std_KD__KD_vector_OC_3**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__158;
  llvm_cbe_tmp__159 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_3**)(&llvm_cbe_tmp__18)));
  llvm_cbe_tmp__160 = llvm_cbe_tmp__13;
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_(llvm_cbe_tmp__159, (((struct l_struct_class_OC_NVariableDeclaration**)((&(*llvm_cbe_tmp__160))))));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__358:
  llvm_cbe_tmp__155 = _Znwm(UINT64_C(24));
  llvm_cbe_tmp__156 = ((struct l_struct_class_OC_std_KD__KD_vector_OC_3*)llvm_cbe_tmp__155);
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev(llvm_cbe_tmp__156);
  *(((struct l_struct_class_OC_std_KD__KD_vector_OC_3**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__156;
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__357:
  llvm_cbe_tmp__143 = _Znwm(UINT64_C(56));
  llvm_cbe_tmp__144 = ((struct l_struct_class_OC_NFunctionDeclaration*)llvm_cbe_tmp__143);
  llvm_cbe_tmp__145 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__146 = *(((struct l_struct_class_OC_NIdentifier**)((&llvm_cbe_tmp__145[((int64_t)UINT64_C(18446744073709551611))]))));
  llvm_cbe_tmp__147 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__148 = *(((struct l_struct_class_OC_NIdentifier**)((&llvm_cbe_tmp__147[((int64_t)UINT64_C(18446744073709551612))]))));
  llvm_cbe_tmp__149 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__150 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_3**)((&llvm_cbe_tmp__149[((int64_t)UINT64_C(18446744073709551614))]))));
  llvm_cbe_tmp__151 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__152 = *(((struct l_struct_class_OC_NBlock**)((&(*llvm_cbe_tmp__151)))));
  _ZN20NFunctionDeclarationC2ERK11NIdentifierS2_RKSt6vectorIP20NVariableDeclarationSaIS5_EER6NBlock(llvm_cbe_tmp__144, llvm_cbe_tmp__146, llvm_cbe_tmp__148, llvm_cbe_tmp__150, llvm_cbe_tmp__152);
  goto llvm_cbe_tmp__388;

llvm_cbe_tmp__388:
  *(((struct l_struct_class_OC_NStatement**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__144));
  llvm_cbe_tmp__153 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__154 = *(((struct l_struct_class_OC_std_KD__KD_vector_OC_3**)((&llvm_cbe_tmp__153[((int64_t)UINT64_C(18446744073709551614))]))));
  if ((((llvm_cbe_tmp__154 == ((struct l_struct_class_OC_std_KD__KD_vector_OC_3*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__389;
  } else {
    goto llvm_cbe_tmp__390;
  }

llvm_cbe_tmp__390:
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev(llvm_cbe_tmp__154);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__154)));
  goto llvm_cbe_tmp__389;

llvm_cbe_tmp__389:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__356:
  llvm_cbe_tmp__135 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__136 = ((struct l_struct_class_OC_NVariableDeclaration*)llvm_cbe_tmp__135);
  llvm_cbe_tmp__137 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__138 = *(((struct l_struct_class_OC_NIdentifier**)((&llvm_cbe_tmp__137[((int64_t)UINT64_C(18446744073709551613))]))));
  llvm_cbe_tmp__139 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__140 = *(((struct l_struct_class_OC_NIdentifier**)((&llvm_cbe_tmp__139[((int64_t)UINT64_C(18446744073709551614))]))));
  llvm_cbe_tmp__141 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__142 = *(((struct l_struct_class_OC_NExpression**)((&(*llvm_cbe_tmp__141)))));
  _ZN20NVariableDeclarationC2ERK11NIdentifierRS0_P11NExpression(llvm_cbe_tmp__136, llvm_cbe_tmp__138, llvm_cbe_tmp__140, llvm_cbe_tmp__142);
  goto llvm_cbe_tmp__391;

llvm_cbe_tmp__391:
  *(((struct l_struct_class_OC_NStatement**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__136));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__355:
  llvm_cbe_tmp__129 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__130 = ((struct l_struct_class_OC_NVariableDeclaration*)llvm_cbe_tmp__129);
  llvm_cbe_tmp__131 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__132 = *(((struct l_struct_class_OC_NIdentifier**)((&llvm_cbe_tmp__131[((int64_t)UINT64_C(18446744073709551615))]))));
  llvm_cbe_tmp__133 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__134 = *(((struct l_struct_class_OC_NIdentifier**)((&(*llvm_cbe_tmp__133)))));
  _ZN20NVariableDeclarationC2ERK11NIdentifierRS0_(llvm_cbe_tmp__130, llvm_cbe_tmp__132, llvm_cbe_tmp__134);
  goto llvm_cbe_tmp__392;

llvm_cbe_tmp__392:
  *(((struct l_struct_class_OC_NStatement**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__130));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__354:
  llvm_cbe_tmp__127 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__128 = ((struct l_struct_class_OC_NBlock*)llvm_cbe_tmp__127);
  _ZN6NBlockC2Ev(llvm_cbe_tmp__128);
  goto llvm_cbe_tmp__393;

llvm_cbe_tmp__393:
  *(((struct l_struct_class_OC_NBlock**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__128;
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__353:
  llvm_cbe_tmp__125 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__126 = *(((struct l_struct_class_OC_NBlock**)((&llvm_cbe_tmp__125[((int64_t)UINT64_C(18446744073709551615))]))));
  *(((struct l_struct_class_OC_NBlock**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__126;
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__352:
  llvm_cbe_tmp__121 = _Znwm(UINT64_C(16));
  llvm_cbe_tmp__122 = ((struct l_struct_class_OC_NExpressionStatement*)llvm_cbe_tmp__121);
  llvm_cbe_tmp__123 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__124 = *(((struct l_struct_class_OC_NExpression**)((&(*llvm_cbe_tmp__123)))));
  _ZN20NExpressionStatementC2ER11NExpression(llvm_cbe_tmp__122, llvm_cbe_tmp__124);
  goto llvm_cbe_tmp__394;

llvm_cbe_tmp__394:
  *(((struct l_struct_class_OC_NStatement**)(&llvm_cbe_tmp__18))) = (((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__122));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__351:
  llvm_cbe_tmp__118 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__119 = *(((struct l_struct_class_OC_NBlock**)((&llvm_cbe_tmp__118[((int64_t)UINT64_C(18446744073709551615))]))));
  llvm_cbe_tmp__120 = llvm_cbe_tmp__13;
  _ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_(((&llvm_cbe_tmp__119->field1)), (((struct l_struct_class_OC_NStatement**)((&(*llvm_cbe_tmp__120))))));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__350:
  llvm_cbe_tmp__114 = _Znwm(UINT64_C(32));
  llvm_cbe_tmp__115 = ((struct l_struct_class_OC_NBlock*)llvm_cbe_tmp__114);
  _ZN6NBlockC2Ev(llvm_cbe_tmp__115);
  goto llvm_cbe_tmp__395;

llvm_cbe_tmp__395:
  *(((struct l_struct_class_OC_NBlock**)(&llvm_cbe_tmp__18))) = llvm_cbe_tmp__115;
  llvm_cbe_tmp__116 = *(((struct l_struct_class_OC_NBlock**)(&llvm_cbe_tmp__18)));
  llvm_cbe_tmp__117 = llvm_cbe_tmp__13;
  _ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_(((&llvm_cbe_tmp__116->field1)), (((struct l_struct_class_OC_NStatement**)((&(*llvm_cbe_tmp__117))))));
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__349:
  llvm_cbe_tmp__112 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__113 = *(((struct l_struct_class_OC_NBlock**)((&(*llvm_cbe_tmp__112)))));
  programBlock = llvm_cbe_tmp__113;
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__348:
  goto llvm_cbe_tmp__372;

llvm_cbe_tmp__372:
  llvm_cbe_tmp__220 = llvm_cbe_tmp__19;
  llvm_cbe_tmp__221 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__13 = ((&llvm_cbe_tmp__221[((int64_t)(llvm_neg_u64((((int64_t)(int32_t)llvm_cbe_tmp__220)))))]));
  llvm_cbe_tmp__222 = llvm_cbe_tmp__19;
  llvm_cbe_tmp__223 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__10 = ((&llvm_cbe_tmp__223[((int64_t)(llvm_neg_u64((((int64_t)(int32_t)llvm_cbe_tmp__222)))))]));
  llvm_cbe_tmp__19 = 0;
  llvm_cbe_tmp__224 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__225 = (&llvm_cbe_tmp__224[((int32_t)1)]);
  llvm_cbe_tmp__13 = llvm_cbe_tmp__225;
  llvm_cbe_tmp__226 = memcpy((((uint8_t*)llvm_cbe_tmp__225)), (((uint8_t*)(&llvm_cbe_tmp__18))), UINT64_C(8));
  llvm_cbe_tmp__227 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__228 = *((&_ZL4yyr1.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__227)))]));
  llvm_cbe_tmp__30 = (llvm_sub_u32((((uint32_t)(uint8_t)llvm_cbe_tmp__228)), 23));
  llvm_cbe_tmp__229 = llvm_cbe_tmp__30;
  llvm_cbe_tmp__230 = *((&_ZL7yypgoto.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__229)))]));
  llvm_cbe_tmp__231 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__232 = *llvm_cbe_tmp__231;
  llvm_cbe_tmp__31 = (llvm_add_u32((((int32_t)(int8_t)llvm_cbe_tmp__230)), (((int32_t)(int16_t)llvm_cbe_tmp__232))));
  llvm_cbe_tmp__233 = llvm_cbe_tmp__31;
  if ((((((int32_t)0u) <= ((int32_t)llvm_cbe_tmp__233))&1))) {
    goto llvm_cbe_tmp__396;
  } else {
    goto llvm_cbe_tmp__397;
  }

llvm_cbe_tmp__396:
  llvm_cbe_tmp__234 = llvm_cbe_tmp__31;
  if ((((((int32_t)llvm_cbe_tmp__234) <= ((int32_t)86u))&1))) {
    goto llvm_cbe_tmp__398;
  } else {
    goto llvm_cbe_tmp__397;
  }

llvm_cbe_tmp__398:
  llvm_cbe_tmp__235 = llvm_cbe_tmp__31;
  llvm_cbe_tmp__236 = *((&_ZL7yycheck.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__235)))]));
  llvm_cbe_tmp__237 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__238 = *llvm_cbe_tmp__237;
  if (((((((int32_t)(int8_t)llvm_cbe_tmp__236)) == (((int32_t)(int16_t)llvm_cbe_tmp__238)))&1))) {
    goto llvm_cbe_tmp__399;
  } else {
    goto llvm_cbe_tmp__397;
  }

llvm_cbe_tmp__397:
  llvm_cbe_tmp__242 = llvm_cbe_tmp__30;
  llvm_cbe_tmp__243 = *((&_ZL9yydefgoto.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__242)))]));
  llvm_cbe_tmp__244 = ((int32_t)(int8_t)llvm_cbe_tmp__243);
  llvm_cbe_tmp__245__PHI_TEMPORARY = llvm_cbe_tmp__244;   /* for PHI node */
  goto llvm_cbe_tmp__400;

llvm_cbe_tmp__399:
  llvm_cbe_tmp__239 = llvm_cbe_tmp__31;
  llvm_cbe_tmp__240 = *((&_ZL7yytable.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__239)))]));
  llvm_cbe_tmp__241 = ((uint32_t)(uint8_t)llvm_cbe_tmp__240);
  llvm_cbe_tmp__245__PHI_TEMPORARY = llvm_cbe_tmp__241;   /* for PHI node */
  goto llvm_cbe_tmp__400;

llvm_cbe_tmp__400:
  llvm_cbe_tmp__245 = llvm_cbe_tmp__245__PHI_TEMPORARY;
  llvm_cbe_tmp__6 = llvm_cbe_tmp__245;
  goto llvm_cbe_tmp__343;

llvm_cbe_tmp__346:
  goto llvm_cbe_tmp__401;

llvm_cbe_tmp__401:
  llvm_cbe_tmp__246 = yychar;
  if ((((llvm_cbe_tmp__246 == 4294967294u)&1))) {
    goto llvm_cbe_tmp__402;
  } else {
    goto llvm_cbe_tmp__403;
  }

llvm_cbe_tmp__403:
  llvm_cbe_tmp__247 = yychar;
  if ((((((uint32_t)llvm_cbe_tmp__247) <= ((uint32_t)277u))&1))) {
    goto llvm_cbe_tmp__404;
  } else {
    goto llvm_cbe_tmp__405;
  }

llvm_cbe_tmp__405:
  llvm_cbe_tmp__251__PHI_TEMPORARY = 2;   /* for PHI node */
  goto llvm_cbe_tmp__406;

llvm_cbe_tmp__404:
  llvm_cbe_tmp__248 = yychar;
  llvm_cbe_tmp__249 = *((&_ZL11yytranslate.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__248)))]));
  llvm_cbe_tmp__250 = ((uint32_t)(uint8_t)llvm_cbe_tmp__249);
  llvm_cbe_tmp__251__PHI_TEMPORARY = llvm_cbe_tmp__250;   /* for PHI node */
  goto llvm_cbe_tmp__406;

llvm_cbe_tmp__406:
  llvm_cbe_tmp__251 = llvm_cbe_tmp__251__PHI_TEMPORARY;
  llvm_cbe_tmp__252__PHI_TEMPORARY = llvm_cbe_tmp__251;   /* for PHI node */
  goto llvm_cbe_tmp__407;

llvm_cbe_tmp__402:
  llvm_cbe_tmp__252__PHI_TEMPORARY = -2;   /* for PHI node */
  goto llvm_cbe_tmp__407;

llvm_cbe_tmp__407:
  llvm_cbe_tmp__252 = llvm_cbe_tmp__252__PHI_TEMPORARY;
  llvm_cbe_tmp__17 = llvm_cbe_tmp__252;
  llvm_cbe_tmp__253 = llvm_cbe_tmp__7;
  if ((((llvm_cbe_tmp__253 != 0u)&1))) {
    goto llvm_cbe_tmp__408;
  } else {
    goto llvm_cbe_tmp__409;
  }

llvm_cbe_tmp__409:
  llvm_cbe_tmp__254 = yynerrs;
  yynerrs = (llvm_add_u32(llvm_cbe_tmp__254, 1));
  _Z7yyerrorPKc(((&_OC_str_OC_1.array[((int32_t)0)])));
  goto llvm_cbe_tmp__408;

llvm_cbe_tmp__408:
  llvm_cbe_tmp__255 = llvm_cbe_tmp__7;
  if ((((llvm_cbe_tmp__255 == 3u)&1))) {
    goto llvm_cbe_tmp__410;
  } else {
    goto llvm_cbe_tmp__411;
  }

llvm_cbe_tmp__410:
  llvm_cbe_tmp__256 = yychar;
  if ((((((int32_t)llvm_cbe_tmp__256) <= ((int32_t)0u))&1))) {
    goto llvm_cbe_tmp__412;
  } else {
    goto llvm_cbe_tmp__413;
  }

llvm_cbe_tmp__413:
  llvm_cbe_tmp__258 = llvm_cbe_tmp__17;
  _ZL10yydestructPKciP7YYSTYPE(((&_OC_str_OC_2.array[((int32_t)0)])), llvm_cbe_tmp__258, (&yylval));
  yychar = -2;
  goto llvm_cbe_tmp__414;

llvm_cbe_tmp__412:
  llvm_cbe_tmp__257 = yychar;
  if ((((llvm_cbe_tmp__257 == 0u)&1))) {
    goto llvm_cbe_tmp__415;
  } else {
    goto llvm_cbe_tmp__416;
  }

llvm_cbe_tmp__416:
  goto llvm_cbe_tmp__414;

llvm_cbe_tmp__414:
  goto llvm_cbe_tmp__411;

llvm_cbe_tmp__411:
  goto llvm_cbe_tmp__417;

llvm_cbe_tmp__417:
  llvm_cbe_tmp__7 = 3;
  goto llvm_cbe_tmp__418;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__418:
  llvm_cbe_tmp__259 = llvm_cbe_tmp__6;
  llvm_cbe_tmp__260 = *((&_ZL6yypact.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__259)))]));
  llvm_cbe_tmp__15 = (((int32_t)(int8_t)llvm_cbe_tmp__260));
  llvm_cbe_tmp__261 = llvm_cbe_tmp__15;
  if ((((llvm_cbe_tmp__261 == 4294967263u)&1))) {
    goto llvm_cbe_tmp__419;
  } else {
    goto llvm_cbe_tmp__420;
  }

llvm_cbe_tmp__420:
  llvm_cbe_tmp__262 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__15 = (llvm_add_u32(llvm_cbe_tmp__262, 1));
  llvm_cbe_tmp__263 = llvm_cbe_tmp__15;
  if ((((((int32_t)0u) <= ((int32_t)llvm_cbe_tmp__263))&1))) {
    goto llvm_cbe_tmp__421;
  } else {
    goto llvm_cbe_tmp__422;
  }

llvm_cbe_tmp__421:
  llvm_cbe_tmp__264 = llvm_cbe_tmp__15;
  if ((((((int32_t)llvm_cbe_tmp__264) <= ((int32_t)86u))&1))) {
    goto llvm_cbe_tmp__423;
  } else {
    goto llvm_cbe_tmp__422;
  }

llvm_cbe_tmp__423:
  llvm_cbe_tmp__265 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__266 = *((&_ZL7yycheck.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__265)))]));
  if (((((((int32_t)(int8_t)llvm_cbe_tmp__266)) == 1u)&1))) {
    goto llvm_cbe_tmp__424;
  } else {
    goto llvm_cbe_tmp__422;
  }

llvm_cbe_tmp__424:
  llvm_cbe_tmp__267 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__268 = *((&_ZL7yytable.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__267)))]));
  llvm_cbe_tmp__15 = (((uint32_t)(uint8_t)llvm_cbe_tmp__268));
  llvm_cbe_tmp__269 = llvm_cbe_tmp__15;
  if ((((((int32_t)0u) < ((int32_t)llvm_cbe_tmp__269))&1))) {
    goto llvm_cbe_tmp__425;
  } else {
    goto llvm_cbe_tmp__426;
  }

llvm_cbe_tmp__426:
  goto llvm_cbe_tmp__422;

llvm_cbe_tmp__422:
  goto llvm_cbe_tmp__419;

llvm_cbe_tmp__419:
  llvm_cbe_tmp__270 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__271 = llvm_cbe_tmp__9;
  if ((((llvm_cbe_tmp__270 == llvm_cbe_tmp__271)&1))) {
    goto llvm_cbe_tmp__427;
  } else {
    goto llvm_cbe_tmp__428;
  }

llvm_cbe_tmp__428:
  llvm_cbe_tmp__272 = llvm_cbe_tmp__6;
  llvm_cbe_tmp__273 = *((&_ZL6yystos.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__272)))]));
  llvm_cbe_tmp__274 = llvm_cbe_tmp__13;
  _ZL10yydestructPKciP7YYSTYPE(((&_OC_str_OC_3.array[((int32_t)0)])), (((uint32_t)(uint8_t)llvm_cbe_tmp__273)), llvm_cbe_tmp__274);
  llvm_cbe_tmp__275 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__13 = ((&llvm_cbe_tmp__275[((int64_t)UINT64_C(18446744073709551615))]));
  llvm_cbe_tmp__276 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__10 = ((&llvm_cbe_tmp__276[((int64_t)UINT64_C(18446744073709551615))]));
  llvm_cbe_tmp__277 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__278 = *llvm_cbe_tmp__277;
  llvm_cbe_tmp__6 = (((int32_t)(int16_t)llvm_cbe_tmp__278));
  goto llvm_cbe_tmp__418;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__425:
  goto llvm_cbe_tmp__429;

llvm_cbe_tmp__429:
  llvm_cbe_tmp__279 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__280 = (&llvm_cbe_tmp__279[((int32_t)1)]);
  llvm_cbe_tmp__13 = llvm_cbe_tmp__280;
  llvm_cbe_tmp__281 = memcpy((((uint8_t*)llvm_cbe_tmp__280)), ((uint8_t*)(&yylval)), UINT64_C(8));
  llvm_cbe_tmp__282 = llvm_cbe_tmp__15;
  llvm_cbe_tmp__6 = llvm_cbe_tmp__282;
  goto llvm_cbe_tmp__343;

llvm_cbe_tmp__343:
  llvm_cbe_tmp__34 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__10 = ((&llvm_cbe_tmp__34[((int32_t)1)]));
  goto llvm_cbe_tmp__305;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__308:
  goto llvm_cbe_tmp__430;

llvm_cbe_tmp__313:
  goto llvm_cbe_tmp__430;

llvm_cbe_tmp__320:
  goto llvm_cbe_tmp__431;

llvm_cbe_tmp__322:
  goto llvm_cbe_tmp__432;

llvm_cbe_tmp__415:
  goto llvm_cbe_tmp__431;

llvm_cbe_tmp__427:
  goto llvm_cbe_tmp__431;

llvm_cbe_tmp__432:
  llvm_cbe_tmp__16 = 0;
  goto llvm_cbe_tmp__433;

llvm_cbe_tmp__431:
  llvm_cbe_tmp__16 = 1;
  goto llvm_cbe_tmp__433;

llvm_cbe_tmp__430:
  _Z7yyerrorPKc(((&_OC_str_OC_4.array[((int32_t)0)])));
  llvm_cbe_tmp__16 = 2;
  goto llvm_cbe_tmp__433;

llvm_cbe_tmp__433:
  llvm_cbe_tmp__283 = yychar;
  if ((((llvm_cbe_tmp__283 != 4294967294u)&1))) {
    goto llvm_cbe_tmp__434;
  } else {
    goto llvm_cbe_tmp__435;
  }

llvm_cbe_tmp__434:
  llvm_cbe_tmp__284 = yychar;
  if ((((((uint32_t)llvm_cbe_tmp__284) <= ((uint32_t)277u))&1))) {
    goto llvm_cbe_tmp__436;
  } else {
    goto llvm_cbe_tmp__437;
  }

llvm_cbe_tmp__436:
  llvm_cbe_tmp__285 = yychar;
  llvm_cbe_tmp__286 = *((&_ZL11yytranslate.array[((int64_t)(((int64_t)(int32_t)llvm_cbe_tmp__285)))]));
  llvm_cbe_tmp__287 = ((uint32_t)(uint8_t)llvm_cbe_tmp__286);
  llvm_cbe_tmp__288__PHI_TEMPORARY = llvm_cbe_tmp__287;   /* for PHI node */
  goto llvm_cbe_tmp__438;

llvm_cbe_tmp__437:
  llvm_cbe_tmp__288__PHI_TEMPORARY = 2;   /* for PHI node */
  goto llvm_cbe_tmp__438;

llvm_cbe_tmp__438:
  llvm_cbe_tmp__288 = llvm_cbe_tmp__288__PHI_TEMPORARY;
  llvm_cbe_tmp__17 = llvm_cbe_tmp__288;
  llvm_cbe_tmp__289 = llvm_cbe_tmp__17;
  _ZL10yydestructPKciP7YYSTYPE(((&_OC_str_OC_5.array[((int32_t)0)])), llvm_cbe_tmp__289, (&yylval));
  goto llvm_cbe_tmp__435;

llvm_cbe_tmp__435:
  llvm_cbe_tmp__290 = llvm_cbe_tmp__19;
  llvm_cbe_tmp__291 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__13 = ((&llvm_cbe_tmp__291[((int64_t)(llvm_neg_u64((((int64_t)(int32_t)llvm_cbe_tmp__290)))))]));
  llvm_cbe_tmp__292 = llvm_cbe_tmp__19;
  llvm_cbe_tmp__293 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__10 = ((&llvm_cbe_tmp__293[((int64_t)(llvm_neg_u64((((int64_t)(int32_t)llvm_cbe_tmp__292)))))]));
  goto llvm_cbe_tmp__439;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__439:
  llvm_cbe_tmp__294 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__295 = llvm_cbe_tmp__9;
  if ((((llvm_cbe_tmp__294 != llvm_cbe_tmp__295)&1))) {
    goto llvm_cbe_tmp__440;
  } else {
    goto llvm_cbe_tmp__441;
  }

llvm_cbe_tmp__440:
  llvm_cbe_tmp__296 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__297 = *llvm_cbe_tmp__296;
  llvm_cbe_tmp__298 = *((&_ZL6yystos.array[((int64_t)(((int64_t)(int16_t)llvm_cbe_tmp__297)))]));
  llvm_cbe_tmp__299 = llvm_cbe_tmp__13;
  _ZL10yydestructPKciP7YYSTYPE(((&_OC_str_OC_6.array[((int32_t)0)])), (((uint32_t)(uint8_t)llvm_cbe_tmp__298)), llvm_cbe_tmp__299);
  llvm_cbe_tmp__300 = llvm_cbe_tmp__13;
  llvm_cbe_tmp__13 = ((&llvm_cbe_tmp__300[((int64_t)UINT64_C(18446744073709551615))]));
  llvm_cbe_tmp__301 = llvm_cbe_tmp__10;
  llvm_cbe_tmp__10 = ((&llvm_cbe_tmp__301[((int64_t)UINT64_C(18446744073709551615))]));
  goto llvm_cbe_tmp__439;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__441:
  llvm_cbe_tmp__302 = llvm_cbe_tmp__9;
  if ((((llvm_cbe_tmp__302 != ((&llvm_cbe_tmp__8.array[((int32_t)0)])))&1))) {
    goto llvm_cbe_tmp__442;
  } else {
    goto llvm_cbe_tmp__443;
  }

llvm_cbe_tmp__442:
  llvm_cbe_tmp__303 = llvm_cbe_tmp__9;
  free((((uint8_t*)llvm_cbe_tmp__303)));
  goto llvm_cbe_tmp__443;

llvm_cbe_tmp__443:
  llvm_cbe_tmp__304 = llvm_cbe_tmp__16;
  return llvm_cbe_tmp__304;
}


void _ZN6NBlockC2Ev(struct l_struct_class_OC_NBlock* llvm_cbe_tmp__444) {
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__445;    /* Address-exposed local */
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__446;

  llvm_cbe_tmp__445 = llvm_cbe_tmp__444;
  llvm_cbe_tmp__446 = llvm_cbe_tmp__445;
  _ZN11NExpressionC2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__446)));
  *(((l_fptr_2***)llvm_cbe_tmp__446)) = ((l_fptr_2**)((&_ZTV6NBlock.field0.array[((int32_t)2)])));
  _ZNSt6vectorIP10NStatementSaIS1_EEC2Ev(((&llvm_cbe_tmp__446->field1)));
}


void _ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__447, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__448) {
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__449;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__450;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14 llvm_cbe_tmp__451;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__452;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__453;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__454;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__455;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__456;
  struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__457;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__458;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__459;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__460;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__461;

  llvm_cbe_tmp__449 = llvm_cbe_tmp__447;
  llvm_cbe_tmp__450 = llvm_cbe_tmp__448;
  llvm_cbe_tmp__452 = llvm_cbe_tmp__449;
  llvm_cbe_tmp__453 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__452))->field0))->field1));
  llvm_cbe_tmp__454 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__452))->field0))->field2));
  if ((((llvm_cbe_tmp__453 != llvm_cbe_tmp__454)&1))) {
    goto llvm_cbe_tmp__462;
  } else {
    goto llvm_cbe_tmp__463;
  }

llvm_cbe_tmp__462:
  llvm_cbe_tmp__455 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__452))->field0))->field1));
  llvm_cbe_tmp__456 = llvm_cbe_tmp__450;
  _ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_((((struct l_struct_class_OC_std_KD__KD_allocator*)((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__452))->field0)))), llvm_cbe_tmp__455, llvm_cbe_tmp__456);
  llvm_cbe_tmp__457 = (&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__452))->field0))->field1);
  llvm_cbe_tmp__458 = *llvm_cbe_tmp__457;
  *llvm_cbe_tmp__457 = ((&llvm_cbe_tmp__458[((int32_t)1)]));
  goto llvm_cbe_tmp__464;

llvm_cbe_tmp__463:
  llvm_cbe_tmp__459 = _ZNSt6vectorIP10NStatementSaIS1_EE3endEv(llvm_cbe_tmp__452);
  *((&llvm_cbe_tmp__451.field0)) = llvm_cbe_tmp__459;
  llvm_cbe_tmp__460 = llvm_cbe_tmp__450;
  llvm_cbe_tmp__461 = *((&llvm_cbe_tmp__451.field0));
  _ZNSt6vectorIP10NStatementSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(llvm_cbe_tmp__452, llvm_cbe_tmp__461, llvm_cbe_tmp__460);
  goto llvm_cbe_tmp__464;

llvm_cbe_tmp__464:
  return;
}


void _ZN20NExpressionStatementC2ER11NExpression(struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__465, struct l_struct_class_OC_NExpression* llvm_cbe_tmp__466) {
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__467;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__468;    /* Address-exposed local */
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__469;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__470;

  llvm_cbe_tmp__467 = llvm_cbe_tmp__465;
  llvm_cbe_tmp__468 = llvm_cbe_tmp__466;
  llvm_cbe_tmp__469 = llvm_cbe_tmp__467;
  _ZN10NStatementC2Ev((((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__469)));
  *(((l_fptr_2***)llvm_cbe_tmp__469)) = ((l_fptr_2**)((&_ZTV20NExpressionStatement.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__470 = llvm_cbe_tmp__468;
  *((&llvm_cbe_tmp__469->field1)) = llvm_cbe_tmp__470;
}


void _ZN20NVariableDeclarationC2ERK11NIdentifierRS0_(struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__471, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__472, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__473) {
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__474;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__475;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__476;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__477;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__478;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__479;

  llvm_cbe_tmp__474 = llvm_cbe_tmp__471;
  llvm_cbe_tmp__475 = llvm_cbe_tmp__472;
  llvm_cbe_tmp__476 = llvm_cbe_tmp__473;
  llvm_cbe_tmp__477 = llvm_cbe_tmp__474;
  _ZN10NStatementC2Ev((((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__477)));
  *(((l_fptr_2***)llvm_cbe_tmp__477)) = ((l_fptr_2**)((&_ZTV20NVariableDeclaration.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__478 = llvm_cbe_tmp__475;
  *((&llvm_cbe_tmp__477->field1)) = llvm_cbe_tmp__478;
  llvm_cbe_tmp__479 = llvm_cbe_tmp__476;
  *((&llvm_cbe_tmp__477->field2)) = llvm_cbe_tmp__479;
}


void _ZN20NVariableDeclarationC2ERK11NIdentifierRS0_P11NExpression(struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__480, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__481, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__482, struct l_struct_class_OC_NExpression* llvm_cbe_tmp__483) {
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__484;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__485;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__486;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__487;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__488;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__489;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__490;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__491;

  llvm_cbe_tmp__484 = llvm_cbe_tmp__480;
  llvm_cbe_tmp__485 = llvm_cbe_tmp__481;
  llvm_cbe_tmp__486 = llvm_cbe_tmp__482;
  llvm_cbe_tmp__487 = llvm_cbe_tmp__483;
  llvm_cbe_tmp__488 = llvm_cbe_tmp__484;
  _ZN10NStatementC2Ev((((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__488)));
  *(((l_fptr_2***)llvm_cbe_tmp__488)) = ((l_fptr_2**)((&_ZTV20NVariableDeclaration.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__489 = llvm_cbe_tmp__485;
  *((&llvm_cbe_tmp__488->field1)) = llvm_cbe_tmp__489;
  llvm_cbe_tmp__490 = llvm_cbe_tmp__486;
  *((&llvm_cbe_tmp__488->field2)) = llvm_cbe_tmp__490;
  llvm_cbe_tmp__491 = llvm_cbe_tmp__487;
  *((&llvm_cbe_tmp__488->field3)) = llvm_cbe_tmp__491;
}


void _ZN20NFunctionDeclarationC2ERK11NIdentifierS2_RKSt6vectorIP20NVariableDeclarationSaIS5_EER6NBlock(struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__492, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__493, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__494, struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__495, struct l_struct_class_OC_NBlock* llvm_cbe_tmp__496) {
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__497;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__498;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__499;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__500;    /* Address-exposed local */
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__501;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__502;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__503;    /* Address-exposed local */
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__504;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__505;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__506;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__507;
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__508;

  llvm_cbe_tmp__497 = llvm_cbe_tmp__492;
  llvm_cbe_tmp__498 = llvm_cbe_tmp__493;
  llvm_cbe_tmp__499 = llvm_cbe_tmp__494;
  llvm_cbe_tmp__500 = llvm_cbe_tmp__495;
  llvm_cbe_tmp__501 = llvm_cbe_tmp__496;
  llvm_cbe_tmp__504 = llvm_cbe_tmp__497;
  _ZN10NStatementC2Ev((((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__504)));
  *(((l_fptr_2***)llvm_cbe_tmp__504)) = ((l_fptr_2**)((&_ZTV20NFunctionDeclaration.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__505 = llvm_cbe_tmp__498;
  *((&llvm_cbe_tmp__504->field1)) = llvm_cbe_tmp__505;
  llvm_cbe_tmp__506 = llvm_cbe_tmp__499;
  *((&llvm_cbe_tmp__504->field2)) = llvm_cbe_tmp__506;
  llvm_cbe_tmp__507 = llvm_cbe_tmp__500;
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2ERKS3_(((&llvm_cbe_tmp__504->field3)), llvm_cbe_tmp__507);
  goto llvm_cbe_tmp__509;

llvm_cbe_tmp__509:
  llvm_cbe_tmp__508 = llvm_cbe_tmp__501;
  *((&llvm_cbe_tmp__504->field4)) = llvm_cbe_tmp__508;
}


void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__510) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__511;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__512;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__513;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__514;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__515;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__516;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__517;

  llvm_cbe_tmp__511 = llvm_cbe_tmp__510;
  llvm_cbe_tmp__514 = llvm_cbe_tmp__511;
  llvm_cbe_tmp__515 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__514))->field0))->field0));
  llvm_cbe_tmp__516 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__514))->field0))->field1));
  llvm_cbe_tmp__517 = _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__514)));
  _ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(llvm_cbe_tmp__515, llvm_cbe_tmp__516, llvm_cbe_tmp__517);
  goto llvm_cbe_tmp__518;

llvm_cbe_tmp__518:
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__514)));
}


void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__519) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__520;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__521;

  llvm_cbe_tmp__520 = llvm_cbe_tmp__519;
  llvm_cbe_tmp__521 = llvm_cbe_tmp__520;
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2Ev((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__521)));
  goto llvm_cbe_tmp__522;

llvm_cbe_tmp__522:
  return;
}


void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__523, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__524) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__525;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__526;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15 llvm_cbe_tmp__527;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__528;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__529;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__530;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__531;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__532;
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__533;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__534;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__535;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__536;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__537;

  llvm_cbe_tmp__525 = llvm_cbe_tmp__523;
  llvm_cbe_tmp__526 = llvm_cbe_tmp__524;
  llvm_cbe_tmp__528 = llvm_cbe_tmp__525;
  llvm_cbe_tmp__529 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__528))->field0))->field1));
  llvm_cbe_tmp__530 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__528))->field0))->field2));
  if ((((llvm_cbe_tmp__529 != llvm_cbe_tmp__530)&1))) {
    goto llvm_cbe_tmp__538;
  } else {
    goto llvm_cbe_tmp__539;
  }

llvm_cbe_tmp__538:
  llvm_cbe_tmp__531 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__528))->field0))->field1));
  llvm_cbe_tmp__532 = llvm_cbe_tmp__526;
  _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_((((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__528))->field0)))), llvm_cbe_tmp__531, llvm_cbe_tmp__532);
  llvm_cbe_tmp__533 = (&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__528))->field0))->field1);
  llvm_cbe_tmp__534 = *llvm_cbe_tmp__533;
  *llvm_cbe_tmp__533 = ((&llvm_cbe_tmp__534[((int32_t)1)]));
  goto llvm_cbe_tmp__540;

llvm_cbe_tmp__539:
  llvm_cbe_tmp__535 = _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(llvm_cbe_tmp__528);
  *((&llvm_cbe_tmp__527.field0)) = llvm_cbe_tmp__535;
  llvm_cbe_tmp__536 = llvm_cbe_tmp__526;
  llvm_cbe_tmp__537 = *((&llvm_cbe_tmp__527.field0));
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(llvm_cbe_tmp__528, llvm_cbe_tmp__537, llvm_cbe_tmp__536);
  goto llvm_cbe_tmp__540;

llvm_cbe_tmp__540:
  return;
}


void _ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__541, struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__542) {
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__543;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__544;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__545;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__546;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__547;
  struct l_struct_class_OC_std_KD__KD___cxx11_KD__KD_basic_string* llvm_cbe_tmp__548;

  llvm_cbe_tmp__543 = llvm_cbe_tmp__541;
  llvm_cbe_tmp__544 = llvm_cbe_tmp__542;
  llvm_cbe_tmp__547 = llvm_cbe_tmp__543;
  _ZN11NExpressionC2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__547)));
  *(((l_fptr_2***)llvm_cbe_tmp__547)) = ((l_fptr_2**)((&_ZTV11NIdentifier.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__548 = llvm_cbe_tmp__544;
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_(((&llvm_cbe_tmp__547->field1)), llvm_cbe_tmp__548);
  goto llvm_cbe_tmp__549;

llvm_cbe_tmp__549:
  return;
}


void _ZN7NDoubleC2Ed(struct l_struct_class_OC_NDouble* llvm_cbe_tmp__550, double llvm_cbe_tmp__551) {
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__552;    /* Address-exposed local */
  double llvm_cbe_tmp__553;    /* Address-exposed local */
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__554;
  double llvm_cbe_tmp__555;

  llvm_cbe_tmp__552 = llvm_cbe_tmp__550;
  llvm_cbe_tmp__553 = llvm_cbe_tmp__551;
  llvm_cbe_tmp__554 = llvm_cbe_tmp__552;
  _ZN11NExpressionC2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__554)));
  *(((l_fptr_2***)llvm_cbe_tmp__554)) = ((l_fptr_2**)((&_ZTV7NDouble.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__555 = llvm_cbe_tmp__553;
  *((&llvm_cbe_tmp__554->field1)) = llvm_cbe_tmp__555;
}


void _ZN11NAssignmentC2ER11NIdentifierR11NExpression(struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__556, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__557, struct l_struct_class_OC_NExpression* llvm_cbe_tmp__558) {
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__559;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__560;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__561;    /* Address-exposed local */
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__562;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__563;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__564;

  llvm_cbe_tmp__559 = llvm_cbe_tmp__556;
  llvm_cbe_tmp__560 = llvm_cbe_tmp__557;
  llvm_cbe_tmp__561 = llvm_cbe_tmp__558;
  llvm_cbe_tmp__562 = llvm_cbe_tmp__559;
  _ZN11NExpressionC2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__562)));
  *(((l_fptr_2***)llvm_cbe_tmp__562)) = ((l_fptr_2**)((&_ZTV11NAssignment.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__563 = llvm_cbe_tmp__560;
  *((&llvm_cbe_tmp__562->field1)) = llvm_cbe_tmp__563;
  llvm_cbe_tmp__564 = llvm_cbe_tmp__561;
  *((&llvm_cbe_tmp__562->field2)) = llvm_cbe_tmp__564;
}


void _ZN11NMethodCallC2ERK11NIdentifierRSt6vectorIP11NExpressionSaIS5_EE(struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__565, struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__566, struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__567) {
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__568;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__569;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__570;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__571;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__572;    /* Address-exposed local */
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__573;
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__574;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__575;

  llvm_cbe_tmp__568 = llvm_cbe_tmp__565;
  llvm_cbe_tmp__569 = llvm_cbe_tmp__566;
  llvm_cbe_tmp__570 = llvm_cbe_tmp__567;
  llvm_cbe_tmp__573 = llvm_cbe_tmp__568;
  _ZN11NExpressionC2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__573)));
  *(((l_fptr_2***)llvm_cbe_tmp__573)) = ((l_fptr_2**)((&_ZTV11NMethodCall.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__574 = llvm_cbe_tmp__569;
  *((&llvm_cbe_tmp__573->field1)) = llvm_cbe_tmp__574;
  llvm_cbe_tmp__575 = llvm_cbe_tmp__570;
  _ZNSt6vectorIP11NExpressionSaIS1_EEC2ERKS3_(((&llvm_cbe_tmp__573->field2)), llvm_cbe_tmp__575);
  goto llvm_cbe_tmp__576;

llvm_cbe_tmp__576:
  return;
}


void _ZNSt6vectorIP11NExpressionSaIS1_EED2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__577) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__578;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__579;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__580;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__581;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__582;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__583;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__584;

  llvm_cbe_tmp__578 = llvm_cbe_tmp__577;
  llvm_cbe_tmp__581 = llvm_cbe_tmp__578;
  llvm_cbe_tmp__582 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__581))->field0))->field0));
  llvm_cbe_tmp__583 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__581))->field0))->field1));
  llvm_cbe_tmp__584 = _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__581)));
  _ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(llvm_cbe_tmp__582, llvm_cbe_tmp__583, llvm_cbe_tmp__584);
  goto llvm_cbe_tmp__585;

llvm_cbe_tmp__585:
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__581)));
}


void _ZN15NBinaryOperatorC2ER11NExpressioniS1_(struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__586, struct l_struct_class_OC_NExpression* llvm_cbe_tmp__587, uint32_t llvm_cbe_tmp__588, struct l_struct_class_OC_NExpression* llvm_cbe_tmp__589) {
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__590;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__591;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__592;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__593;    /* Address-exposed local */
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__594;
  uint32_t llvm_cbe_tmp__595;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__596;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__597;

  llvm_cbe_tmp__590 = llvm_cbe_tmp__586;
  llvm_cbe_tmp__591 = llvm_cbe_tmp__587;
  llvm_cbe_tmp__592 = llvm_cbe_tmp__588;
  llvm_cbe_tmp__593 = llvm_cbe_tmp__589;
  llvm_cbe_tmp__594 = llvm_cbe_tmp__590;
  _ZN11NExpressionC2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__594)));
  *(((l_fptr_2***)llvm_cbe_tmp__594)) = ((l_fptr_2**)((&_ZTV15NBinaryOperator.field0.array[((int32_t)2)])));
  llvm_cbe_tmp__595 = llvm_cbe_tmp__592;
  *((&llvm_cbe_tmp__594->field1)) = llvm_cbe_tmp__595;
  llvm_cbe_tmp__596 = llvm_cbe_tmp__591;
  *((&llvm_cbe_tmp__594->field2)) = llvm_cbe_tmp__596;
  llvm_cbe_tmp__597 = llvm_cbe_tmp__593;
  *((&llvm_cbe_tmp__594->field3)) = llvm_cbe_tmp__597;
}


void _ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__598) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__599;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__600;

  llvm_cbe_tmp__599 = llvm_cbe_tmp__598;
  llvm_cbe_tmp__600 = llvm_cbe_tmp__599;
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2Ev((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__600)));
  goto llvm_cbe_tmp__601;

llvm_cbe_tmp__601:
  return;
}


void _ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__602, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__603) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__604;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__605;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17 llvm_cbe_tmp__606;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__607;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__608;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__609;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__610;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__611;
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__612;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__613;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__614;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__615;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__616;

  llvm_cbe_tmp__604 = llvm_cbe_tmp__602;
  llvm_cbe_tmp__605 = llvm_cbe_tmp__603;
  llvm_cbe_tmp__607 = llvm_cbe_tmp__604;
  llvm_cbe_tmp__608 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__607))->field0))->field1));
  llvm_cbe_tmp__609 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__607))->field0))->field2));
  if ((((llvm_cbe_tmp__608 != llvm_cbe_tmp__609)&1))) {
    goto llvm_cbe_tmp__617;
  } else {
    goto llvm_cbe_tmp__618;
  }

llvm_cbe_tmp__617:
  llvm_cbe_tmp__610 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__607))->field0))->field1));
  llvm_cbe_tmp__611 = llvm_cbe_tmp__605;
  _ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_((((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__607))->field0)))), llvm_cbe_tmp__610, llvm_cbe_tmp__611);
  llvm_cbe_tmp__612 = (&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__607))->field0))->field1);
  llvm_cbe_tmp__613 = *llvm_cbe_tmp__612;
  *llvm_cbe_tmp__612 = ((&llvm_cbe_tmp__613[((int32_t)1)]));
  goto llvm_cbe_tmp__619;

llvm_cbe_tmp__618:
  llvm_cbe_tmp__614 = _ZNSt6vectorIP11NExpressionSaIS1_EE3endEv(llvm_cbe_tmp__607);
  *((&llvm_cbe_tmp__606.field0)) = llvm_cbe_tmp__614;
  llvm_cbe_tmp__615 = llvm_cbe_tmp__605;
  llvm_cbe_tmp__616 = *((&llvm_cbe_tmp__606.field0));
  _ZNSt6vectorIP11NExpressionSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(llvm_cbe_tmp__607, llvm_cbe_tmp__616, llvm_cbe_tmp__615);
  goto llvm_cbe_tmp__619;

llvm_cbe_tmp__619:
  return;
}


static void _ZL10yydestructPKciP7YYSTYPE(uint8_t* llvm_cbe_tmp__620, uint32_t llvm_cbe_tmp__621, struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__622) {
  uint8_t* llvm_cbe_tmp__623;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__624;    /* Address-exposed local */
  struct l_struct_union_OC_YYSTYPE* llvm_cbe_tmp__625;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__626;

  llvm_cbe_tmp__623 = llvm_cbe_tmp__620;
  llvm_cbe_tmp__624 = llvm_cbe_tmp__621;
  llvm_cbe_tmp__625 = llvm_cbe_tmp__622;
  llvm_cbe_tmp__626 = llvm_cbe_tmp__623;
  if ((((llvm_cbe_tmp__626 != ((uint8_t*)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__627;
  } else {
    goto llvm_cbe_tmp__628;
  }

llvm_cbe_tmp__628:
  llvm_cbe_tmp__623 = ((&_OC_str_OC_7.array[((int32_t)0)]));
  goto llvm_cbe_tmp__627;

llvm_cbe_tmp__627:
  return;
}


void _ZN11NExpressionC2Ev(struct l_struct_class_OC_NExpression* llvm_cbe_tmp__629) {
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__630;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__631;

  llvm_cbe_tmp__630 = llvm_cbe_tmp__629;
  llvm_cbe_tmp__631 = llvm_cbe_tmp__630;
  _ZN4NodeC2Ev((((struct l_struct_class_OC_Node*)llvm_cbe_tmp__631)));
  *(((l_fptr_2***)llvm_cbe_tmp__631)) = ((l_fptr_2**)((&_ZTV11NExpression.field0.array[((int32_t)2)])));
}


void _ZNSt6vectorIP10NStatementSaIS1_EEC2Ev(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__632) {
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__633;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__634;

  llvm_cbe_tmp__633 = llvm_cbe_tmp__632;
  llvm_cbe_tmp__634 = llvm_cbe_tmp__633;
  _ZNSt12_Vector_baseIP10NStatementSaIS1_EEC2Ev((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__634)));
  goto llvm_cbe_tmp__635;

llvm_cbe_tmp__635:
  return;
}


void _ZN6NBlockD2Ev(struct l_struct_class_OC_NBlock* llvm_cbe_tmp__636) {
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__637;    /* Address-exposed local */
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__638;

  llvm_cbe_tmp__637 = llvm_cbe_tmp__636;
  llvm_cbe_tmp__638 = llvm_cbe_tmp__637;
  *(((l_fptr_2***)llvm_cbe_tmp__638)) = ((l_fptr_2**)((&_ZTV6NBlock.field0.array[((int32_t)2)])));
  _ZNSt6vectorIP10NStatementSaIS1_EED2Ev(((&llvm_cbe_tmp__638->field1)));
  _ZN11NExpressionD2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__638)));
}


void _ZN6NBlockD0Ev(struct l_struct_class_OC_NBlock* llvm_cbe_tmp__639) {
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__640;    /* Address-exposed local */
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__641;

  llvm_cbe_tmp__640 = llvm_cbe_tmp__639;
  llvm_cbe_tmp__641 = llvm_cbe_tmp__640;
  _ZN6NBlockD2Ev(llvm_cbe_tmp__641);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__641)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN6NBlock7codeGenER14CodeGenContext(struct l_struct_class_OC_NBlock* llvm_cbe_tmp__642, void* llvm_cbe_tmp__643) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__644;    /* Address-exposed local */
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__645;    /* Address-exposed local */
  void* llvm_cbe_tmp__646;    /* Address-exposed local */
  struct l_struct_class_OC_NBlock* llvm_cbe_tmp__647;

  llvm_cbe_tmp__645 = llvm_cbe_tmp__642;
  llvm_cbe_tmp__646 = llvm_cbe_tmp__643;
  llvm_cbe_tmp__647 = llvm_cbe_tmp__645;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZN4NodeC2Ev(struct l_struct_class_OC_Node* llvm_cbe_tmp__648) {
  struct l_struct_class_OC_Node* llvm_cbe_tmp__649;    /* Address-exposed local */
  struct l_struct_class_OC_Node* llvm_cbe_tmp__650;

  llvm_cbe_tmp__649 = llvm_cbe_tmp__648;
  llvm_cbe_tmp__650 = llvm_cbe_tmp__649;
  *(((l_fptr_2***)llvm_cbe_tmp__650)) = ((l_fptr_2**)((&_ZTV4Node.field0.array[((int32_t)2)])));
}


void _ZN11NExpressionD2Ev(struct l_struct_class_OC_NExpression* llvm_cbe_tmp__651) {
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__652;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__653;

  llvm_cbe_tmp__652 = llvm_cbe_tmp__651;
  llvm_cbe_tmp__653 = llvm_cbe_tmp__652;
  _ZN4NodeD2Ev((((struct l_struct_class_OC_Node*)llvm_cbe_tmp__653)));
}


void _ZN11NExpressionD0Ev(struct l_struct_class_OC_NExpression* llvm_cbe_tmp__654) {
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__655;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__656;

  llvm_cbe_tmp__655 = llvm_cbe_tmp__654;
  llvm_cbe_tmp__656 = llvm_cbe_tmp__655;
  _ZN11NExpressionD2Ev(llvm_cbe_tmp__656);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__656)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN4Node7codeGenER14CodeGenContext(struct l_struct_class_OC_Node* llvm_cbe_tmp__657, void* llvm_cbe_tmp__658) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__659;    /* Address-exposed local */
  struct l_struct_class_OC_Node* llvm_cbe_tmp__660;    /* Address-exposed local */
  void* llvm_cbe_tmp__661;    /* Address-exposed local */
  struct l_struct_class_OC_Node* llvm_cbe_tmp__662;

  llvm_cbe_tmp__660 = llvm_cbe_tmp__657;
  llvm_cbe_tmp__661 = llvm_cbe_tmp__658;
  llvm_cbe_tmp__662 = llvm_cbe_tmp__660;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZN4NodeD2Ev(struct l_struct_class_OC_Node* llvm_cbe_tmp__663) {
  struct l_struct_class_OC_Node* llvm_cbe_tmp__664;    /* Address-exposed local */
  struct l_struct_class_OC_Node* llvm_cbe_tmp__665;

  llvm_cbe_tmp__664 = llvm_cbe_tmp__663;
  llvm_cbe_tmp__665 = llvm_cbe_tmp__664;
}


void _ZN4NodeD0Ev(struct l_struct_class_OC_Node* llvm_cbe_tmp__666) {
  struct l_struct_class_OC_Node* llvm_cbe_tmp__667;    /* Address-exposed local */
  struct l_struct_class_OC_Node* llvm_cbe_tmp__668;

  llvm_cbe_tmp__667 = llvm_cbe_tmp__666;
  llvm_cbe_tmp__668 = llvm_cbe_tmp__667;
  _ZN4NodeD2Ev(llvm_cbe_tmp__668);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__668)));
}


void _ZNSt12_Vector_baseIP10NStatementSaIS1_EEC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__669) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__670;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__671;

  llvm_cbe_tmp__670 = llvm_cbe_tmp__669;
  llvm_cbe_tmp__671 = llvm_cbe_tmp__670;
  _ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implC2Ev(((&llvm_cbe_tmp__671->field0)));
}


__noreturn void __clang_call_terminate(uint8_t* llvm_cbe_tmp__672) {
  uint8_t* llvm_cbe_tmp__673;

  llvm_cbe_tmp__673 = __cxa_begin_catch(llvm_cbe_tmp__672);
  _ZSt9terminatev();
  __builtin_unreachable();

}


void _ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__674) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__675;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__676;

  llvm_cbe_tmp__675 = llvm_cbe_tmp__674;
  llvm_cbe_tmp__676 = llvm_cbe_tmp__675;
  _ZNSaIP10NStatementEC2Ev((((struct l_struct_class_OC_std_KD__KD_allocator*)llvm_cbe_tmp__676)));
  *((&llvm_cbe_tmp__676->field0)) = ((struct l_struct_class_OC_NStatement**)/*NULL*/0);
  *((&llvm_cbe_tmp__676->field1)) = ((struct l_struct_class_OC_NStatement**)/*NULL*/0);
  *((&llvm_cbe_tmp__676->field2)) = ((struct l_struct_class_OC_NStatement**)/*NULL*/0);
}


void _ZNSaIP10NStatementEC2Ev(struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__677) {
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__678;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__679;

  llvm_cbe_tmp__678 = llvm_cbe_tmp__677;
  llvm_cbe_tmp__679 = llvm_cbe_tmp__678;
  _ZN9__gnu_cxx13new_allocatorIP10NStatementEC2Ev((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*)llvm_cbe_tmp__679)));
}


void _ZN9__gnu_cxx13new_allocatorIP10NStatementEC2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__680) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__681;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__682;

  llvm_cbe_tmp__681 = llvm_cbe_tmp__680;
  llvm_cbe_tmp__682 = llvm_cbe_tmp__681;
}


void _ZNSt6vectorIP10NStatementSaIS1_EED2Ev(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__683) {
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__684;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__685;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__686;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__687;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__688;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__689;
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__690;

  llvm_cbe_tmp__684 = llvm_cbe_tmp__683;
  llvm_cbe_tmp__687 = llvm_cbe_tmp__684;
  llvm_cbe_tmp__688 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__687))->field0))->field0));
  llvm_cbe_tmp__689 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__687))->field0))->field1));
  llvm_cbe_tmp__690 = _ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__687)));
  _ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(llvm_cbe_tmp__688, llvm_cbe_tmp__689, llvm_cbe_tmp__690);
  goto llvm_cbe_tmp__691;

llvm_cbe_tmp__691:
  _ZNSt12_Vector_baseIP10NStatementSaIS1_EED2Ev((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__687)));
}


void _ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__692, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__693, struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__694) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__695;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__696;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__697;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__698;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__699;

  llvm_cbe_tmp__695 = llvm_cbe_tmp__692;
  llvm_cbe_tmp__696 = llvm_cbe_tmp__693;
  llvm_cbe_tmp__697 = llvm_cbe_tmp__694;
  llvm_cbe_tmp__698 = llvm_cbe_tmp__695;
  llvm_cbe_tmp__699 = llvm_cbe_tmp__696;
  _ZSt8_DestroyIPP10NStatementEvT_S3_(llvm_cbe_tmp__698, llvm_cbe_tmp__699);
}


struct l_struct_class_OC_std_KD__KD_allocator* _ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__700) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__701;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__702;

  llvm_cbe_tmp__701 = llvm_cbe_tmp__700;
  llvm_cbe_tmp__702 = llvm_cbe_tmp__701;
  return (((struct l_struct_class_OC_std_KD__KD_allocator*)((&llvm_cbe_tmp__702->field0))));
}


void _ZNSt12_Vector_baseIP10NStatementSaIS1_EED2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__703) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__704;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__705;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__706;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__707;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__708;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__709;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__710;

  llvm_cbe_tmp__704 = llvm_cbe_tmp__703;
  llvm_cbe_tmp__707 = llvm_cbe_tmp__704;
  llvm_cbe_tmp__708 = *((&((&llvm_cbe_tmp__707->field0))->field0));
  llvm_cbe_tmp__709 = *((&((&llvm_cbe_tmp__707->field0))->field2));
  llvm_cbe_tmp__710 = *((&((&llvm_cbe_tmp__707->field0))->field0));
  _ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m(llvm_cbe_tmp__707, llvm_cbe_tmp__708, (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__709)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__710)))), UINT64_C(8))));
  goto llvm_cbe_tmp__711;

llvm_cbe_tmp__711:
  _ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implD2Ev(((&llvm_cbe_tmp__707->field0)));
}


void _ZSt8_DestroyIPP10NStatementEvT_S3_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__712, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__713) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__714;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__715;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__716;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__717;

  llvm_cbe_tmp__714 = llvm_cbe_tmp__712;
  llvm_cbe_tmp__715 = llvm_cbe_tmp__713;
  llvm_cbe_tmp__716 = llvm_cbe_tmp__714;
  llvm_cbe_tmp__717 = llvm_cbe_tmp__715;
  _ZNSt12_Destroy_auxILb1EE9__destroyIPP10NStatementEEvT_S5_(llvm_cbe_tmp__716, llvm_cbe_tmp__717);
}


void _ZNSt12_Destroy_auxILb1EE9__destroyIPP10NStatementEEvT_S5_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__718, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__719) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__720;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__721;    /* Address-exposed local */

  llvm_cbe_tmp__720 = llvm_cbe_tmp__718;
  llvm_cbe_tmp__721 = llvm_cbe_tmp__719;
}


void _ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m(struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__722, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__723, uint64_t llvm_cbe_tmp__724) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__725;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__726;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__727;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__728;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__729;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__730;
  uint64_t llvm_cbe_tmp__731;

  llvm_cbe_tmp__725 = llvm_cbe_tmp__722;
  llvm_cbe_tmp__726 = llvm_cbe_tmp__723;
  llvm_cbe_tmp__727 = llvm_cbe_tmp__724;
  llvm_cbe_tmp__728 = llvm_cbe_tmp__725;
  llvm_cbe_tmp__729 = llvm_cbe_tmp__726;
  if ((((llvm_cbe_tmp__729 != ((struct l_struct_class_OC_NStatement**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__732;
  } else {
    goto llvm_cbe_tmp__733;
  }

llvm_cbe_tmp__732:
  llvm_cbe_tmp__730 = llvm_cbe_tmp__726;
  llvm_cbe_tmp__731 = llvm_cbe_tmp__727;
  _ZNSt16allocator_traitsISaIP10NStatementEE10deallocateERS2_PS1_m((((struct l_struct_class_OC_std_KD__KD_allocator*)((&llvm_cbe_tmp__728->field0)))), llvm_cbe_tmp__730, llvm_cbe_tmp__731);
  goto llvm_cbe_tmp__733;

llvm_cbe_tmp__733:
  return;
}


void _ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implD2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__734) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__735;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NStatement_AC__KC__MC__AC_std_KD__KD_allocator_MD_NStatement_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__736;

  llvm_cbe_tmp__735 = llvm_cbe_tmp__734;
  llvm_cbe_tmp__736 = llvm_cbe_tmp__735;
  _ZNSaIP10NStatementED2Ev((((struct l_struct_class_OC_std_KD__KD_allocator*)llvm_cbe_tmp__736)));
}


void _ZNSt16allocator_traitsISaIP10NStatementEE10deallocateERS2_PS1_m(struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__737, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__738, uint64_t llvm_cbe_tmp__739) {
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__740;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__741;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__742;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__743;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__744;
  uint64_t llvm_cbe_tmp__745;

  llvm_cbe_tmp__740 = llvm_cbe_tmp__737;
  llvm_cbe_tmp__741 = llvm_cbe_tmp__738;
  llvm_cbe_tmp__742 = llvm_cbe_tmp__739;
  llvm_cbe_tmp__743 = llvm_cbe_tmp__740;
  llvm_cbe_tmp__744 = llvm_cbe_tmp__741;
  llvm_cbe_tmp__745 = llvm_cbe_tmp__742;
  _ZN9__gnu_cxx13new_allocatorIP10NStatementE10deallocateEPS2_m((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*)llvm_cbe_tmp__743)), llvm_cbe_tmp__744, llvm_cbe_tmp__745);
}


void _ZN9__gnu_cxx13new_allocatorIP10NStatementE10deallocateEPS2_m(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__746, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__747, uint64_t llvm_cbe_tmp__748) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__749;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__750;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__751;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__752;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__753;

  llvm_cbe_tmp__749 = llvm_cbe_tmp__746;
  llvm_cbe_tmp__750 = llvm_cbe_tmp__747;
  llvm_cbe_tmp__751 = llvm_cbe_tmp__748;
  llvm_cbe_tmp__752 = llvm_cbe_tmp__749;
  llvm_cbe_tmp__753 = llvm_cbe_tmp__750;
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__753)));
}


void _ZNSaIP10NStatementED2Ev(struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__754) {
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__755;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__756;

  llvm_cbe_tmp__755 = llvm_cbe_tmp__754;
  llvm_cbe_tmp__756 = llvm_cbe_tmp__755;
  _ZN9__gnu_cxx13new_allocatorIP10NStatementED2Ev((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*)llvm_cbe_tmp__756)));
}


void _ZN9__gnu_cxx13new_allocatorIP10NStatementED2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__757) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__758;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__759;

  llvm_cbe_tmp__758 = llvm_cbe_tmp__757;
  llvm_cbe_tmp__759 = llvm_cbe_tmp__758;
}


void _ZN10NStatementC2Ev(struct l_struct_class_OC_NStatement* llvm_cbe_tmp__760) {
  struct l_struct_class_OC_NStatement* llvm_cbe_tmp__761;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement* llvm_cbe_tmp__762;

  llvm_cbe_tmp__761 = llvm_cbe_tmp__760;
  llvm_cbe_tmp__762 = llvm_cbe_tmp__761;
  _ZN4NodeC2Ev((((struct l_struct_class_OC_Node*)llvm_cbe_tmp__762)));
  *(((l_fptr_2***)llvm_cbe_tmp__762)) = ((l_fptr_2**)((&_ZTV10NStatement.field0.array[((int32_t)2)])));
}


void _ZN20NExpressionStatementD2Ev(struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__763) {
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__764;    /* Address-exposed local */
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__765;

  llvm_cbe_tmp__764 = llvm_cbe_tmp__763;
  llvm_cbe_tmp__765 = llvm_cbe_tmp__764;
  _ZN10NStatementD2Ev((((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__765)));
}


void _ZN20NExpressionStatementD0Ev(struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__766) {
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__767;    /* Address-exposed local */
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__768;

  llvm_cbe_tmp__767 = llvm_cbe_tmp__766;
  llvm_cbe_tmp__768 = llvm_cbe_tmp__767;
  _ZN20NExpressionStatementD2Ev(llvm_cbe_tmp__768);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__768)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN20NExpressionStatement7codeGenER14CodeGenContext(struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__769, void* llvm_cbe_tmp__770) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__771;    /* Address-exposed local */
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__772;    /* Address-exposed local */
  void* llvm_cbe_tmp__773;    /* Address-exposed local */
  struct l_struct_class_OC_NExpressionStatement* llvm_cbe_tmp__774;

  llvm_cbe_tmp__772 = llvm_cbe_tmp__769;
  llvm_cbe_tmp__773 = llvm_cbe_tmp__770;
  llvm_cbe_tmp__774 = llvm_cbe_tmp__772;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZN10NStatementD2Ev(struct l_struct_class_OC_NStatement* llvm_cbe_tmp__775) {
  struct l_struct_class_OC_NStatement* llvm_cbe_tmp__776;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement* llvm_cbe_tmp__777;

  llvm_cbe_tmp__776 = llvm_cbe_tmp__775;
  llvm_cbe_tmp__777 = llvm_cbe_tmp__776;
  _ZN4NodeD2Ev((((struct l_struct_class_OC_Node*)llvm_cbe_tmp__777)));
}


void _ZN10NStatementD0Ev(struct l_struct_class_OC_NStatement* llvm_cbe_tmp__778) {
  struct l_struct_class_OC_NStatement* llvm_cbe_tmp__779;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement* llvm_cbe_tmp__780;

  llvm_cbe_tmp__779 = llvm_cbe_tmp__778;
  llvm_cbe_tmp__780 = llvm_cbe_tmp__779;
  _ZN10NStatementD2Ev(llvm_cbe_tmp__780);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__780)));
}


void _ZN20NVariableDeclarationD2Ev(struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__781) {
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__782;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__783;

  llvm_cbe_tmp__782 = llvm_cbe_tmp__781;
  llvm_cbe_tmp__783 = llvm_cbe_tmp__782;
  _ZN10NStatementD2Ev((((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__783)));
}


void _ZN20NVariableDeclarationD0Ev(struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__784) {
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__785;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__786;

  llvm_cbe_tmp__785 = llvm_cbe_tmp__784;
  llvm_cbe_tmp__786 = llvm_cbe_tmp__785;
  _ZN20NVariableDeclarationD2Ev(llvm_cbe_tmp__786);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__786)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN20NVariableDeclaration7codeGenER14CodeGenContext(struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__787, void* llvm_cbe_tmp__788) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__789;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__790;    /* Address-exposed local */
  void* llvm_cbe_tmp__791;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__792;

  llvm_cbe_tmp__790 = llvm_cbe_tmp__787;
  llvm_cbe_tmp__791 = llvm_cbe_tmp__788;
  llvm_cbe_tmp__792 = llvm_cbe_tmp__790;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2ERKS3_(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__793, struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__794) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__795;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__796;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5 llvm_cbe_tmp__797;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__798;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__799;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__800;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__801;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__802;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__803;
  uint64_t llvm_cbe_tmp__804;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__805;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__806;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__807;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__808;
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__809;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__810;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__811;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__812;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__813;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__814;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__815;

  llvm_cbe_tmp__795 = llvm_cbe_tmp__793;
  llvm_cbe_tmp__796 = llvm_cbe_tmp__794;
  llvm_cbe_tmp__802 = llvm_cbe_tmp__795;
  llvm_cbe_tmp__803 = llvm_cbe_tmp__796;
  llvm_cbe_tmp__804 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(llvm_cbe_tmp__803);
  llvm_cbe_tmp__805 = llvm_cbe_tmp__796;
  llvm_cbe_tmp__806 = _ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__805)));
  llvm_cbe_tmp__797 = _ZN9__gnu_cxx14__alloc_traitsISaIP20NVariableDeclarationES2_E17_S_select_on_copyERKS3_(llvm_cbe_tmp__806);
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2EmRKS2_((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__802)), llvm_cbe_tmp__804, (&llvm_cbe_tmp__797));
  goto llvm_cbe_tmp__816;

llvm_cbe_tmp__816:
  _ZNSaIP20NVariableDeclarationED2Ev((&llvm_cbe_tmp__797));
  llvm_cbe_tmp__807 = llvm_cbe_tmp__796;
  llvm_cbe_tmp__808 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(llvm_cbe_tmp__807);
  *((&llvm_cbe_tmp__800.field0)) = llvm_cbe_tmp__808;
  llvm_cbe_tmp__809 = llvm_cbe_tmp__796;
  llvm_cbe_tmp__810 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(llvm_cbe_tmp__809);
  *((&llvm_cbe_tmp__801.field0)) = llvm_cbe_tmp__810;
  llvm_cbe_tmp__811 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__802))->field0))->field0));
  llvm_cbe_tmp__812 = _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__802)));
  llvm_cbe_tmp__813 = *((&llvm_cbe_tmp__800.field0));
  llvm_cbe_tmp__814 = *((&llvm_cbe_tmp__801.field0));
  llvm_cbe_tmp__815 = _ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(llvm_cbe_tmp__813, llvm_cbe_tmp__814, llvm_cbe_tmp__811, llvm_cbe_tmp__812);
  goto llvm_cbe_tmp__817;

llvm_cbe_tmp__817:
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__802))->field0))->field1)) = llvm_cbe_tmp__815;
}


void _ZN20NFunctionDeclarationD2Ev(struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__818) {
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__819;    /* Address-exposed local */
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__820;

  llvm_cbe_tmp__819 = llvm_cbe_tmp__818;
  llvm_cbe_tmp__820 = llvm_cbe_tmp__819;
  *(((l_fptr_2***)llvm_cbe_tmp__820)) = ((l_fptr_2**)((&_ZTV20NFunctionDeclaration.field0.array[((int32_t)2)])));
  _ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev(((&llvm_cbe_tmp__820->field3)));
  _ZN10NStatementD2Ev((((struct l_struct_class_OC_NStatement*)llvm_cbe_tmp__820)));
}


void _ZN20NFunctionDeclarationD0Ev(struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__821) {
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__822;    /* Address-exposed local */
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__823;

  llvm_cbe_tmp__822 = llvm_cbe_tmp__821;
  llvm_cbe_tmp__823 = llvm_cbe_tmp__822;
  _ZN20NFunctionDeclarationD2Ev(llvm_cbe_tmp__823);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__823)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN20NFunctionDeclaration7codeGenER14CodeGenContext(struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__824, void* llvm_cbe_tmp__825) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__826;    /* Address-exposed local */
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__827;    /* Address-exposed local */
  void* llvm_cbe_tmp__828;    /* Address-exposed local */
  struct l_struct_class_OC_NFunctionDeclaration* llvm_cbe_tmp__829;

  llvm_cbe_tmp__827 = llvm_cbe_tmp__824;
  llvm_cbe_tmp__828 = llvm_cbe_tmp__825;
  llvm_cbe_tmp__829 = llvm_cbe_tmp__827;
  llvm_OC_trap();
  __builtin_unreachable();

}


uint64_t _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__830) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__831;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__832;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__833;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__834;

  llvm_cbe_tmp__831 = llvm_cbe_tmp__830;
  llvm_cbe_tmp__832 = llvm_cbe_tmp__831;
  llvm_cbe_tmp__833 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__832))->field0))->field1));
  llvm_cbe_tmp__834 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__832))->field0))->field0));
  return (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__833)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__834)))), UINT64_C(8)));
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_5 _ZN9__gnu_cxx14__alloc_traitsISaIP20NVariableDeclarationES2_E17_S_select_on_copyERKS3_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__835) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5 StructReturn;  /* Struct return temporary */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5*llvm_cbe_tmp__836 = &StructReturn;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__837;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__838;

  llvm_cbe_tmp__837 = llvm_cbe_tmp__835;
  llvm_cbe_tmp__838 = llvm_cbe_tmp__837;
  *(llvm_cbe_tmp__836) = _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE37select_on_container_copy_constructionERKS2_(llvm_cbe_tmp__838);
  return StructReturn;
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_5* _ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__839) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__840;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__841;

  llvm_cbe_tmp__840 = llvm_cbe_tmp__839;
  llvm_cbe_tmp__841 = llvm_cbe_tmp__840;
  return (((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)((&llvm_cbe_tmp__841->field0))));
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2EmRKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__842, uint64_t llvm_cbe_tmp__843, struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__844) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__845;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__846;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__847;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__848;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__849;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__850;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__851;
  uint64_t llvm_cbe_tmp__852;

  llvm_cbe_tmp__845 = llvm_cbe_tmp__842;
  llvm_cbe_tmp__846 = llvm_cbe_tmp__843;
  llvm_cbe_tmp__847 = llvm_cbe_tmp__844;
  llvm_cbe_tmp__850 = llvm_cbe_tmp__845;
  llvm_cbe_tmp__851 = llvm_cbe_tmp__847;
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2ERKS2_(((&llvm_cbe_tmp__850->field0)), llvm_cbe_tmp__851);
  llvm_cbe_tmp__852 = llvm_cbe_tmp__846;
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE17_M_create_storageEm(llvm_cbe_tmp__850, llvm_cbe_tmp__852);
  goto llvm_cbe_tmp__853;

llvm_cbe_tmp__853:
  return;
}


void _ZNSaIP20NVariableDeclarationED2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__854) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__855;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__856;

  llvm_cbe_tmp__855 = llvm_cbe_tmp__854;
  llvm_cbe_tmp__856 = llvm_cbe_tmp__855;
  _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationED2Ev((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__856)));
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__857, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__858, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__859, struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__860) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__861;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__862;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__863;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__864;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__865;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__866;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__867;
  uint8_t* llvm_cbe_tmp__868;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__869;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__870;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__871;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__872;

  *((&llvm_cbe_tmp__861.field0)) = llvm_cbe_tmp__857;
  *((&llvm_cbe_tmp__862.field0)) = llvm_cbe_tmp__858;
  llvm_cbe_tmp__863 = llvm_cbe_tmp__859;
  llvm_cbe_tmp__864 = llvm_cbe_tmp__860;
  llvm_cbe_tmp__867 = memcpy((((uint8_t*)(&llvm_cbe_tmp__865))), (((uint8_t*)(&llvm_cbe_tmp__861))), UINT64_C(8));
  llvm_cbe_tmp__868 = memcpy((((uint8_t*)(&llvm_cbe_tmp__866))), (((uint8_t*)(&llvm_cbe_tmp__862))), UINT64_C(8));
  llvm_cbe_tmp__869 = llvm_cbe_tmp__863;
  llvm_cbe_tmp__870 = *((&llvm_cbe_tmp__865.field0));
  llvm_cbe_tmp__871 = *((&llvm_cbe_tmp__866.field0));
  llvm_cbe_tmp__872 = _ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(llvm_cbe_tmp__870, llvm_cbe_tmp__871, llvm_cbe_tmp__869);
  return llvm_cbe_tmp__872;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__873) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__874;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__875;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__876;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__877;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__878;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__879;

  llvm_cbe_tmp__875 = llvm_cbe_tmp__873;
  llvm_cbe_tmp__877 = llvm_cbe_tmp__875;
  llvm_cbe_tmp__878 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__877))->field0))->field0));
  llvm_cbe_tmp__876 = llvm_cbe_tmp__878;
  _ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_((&llvm_cbe_tmp__874), (&llvm_cbe_tmp__876));
  llvm_cbe_tmp__879 = *((&llvm_cbe_tmp__874.field0));
  return llvm_cbe_tmp__879;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__880) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__881;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__882;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__883;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__884;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__885;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__886;

  llvm_cbe_tmp__882 = llvm_cbe_tmp__880;
  llvm_cbe_tmp__884 = llvm_cbe_tmp__882;
  llvm_cbe_tmp__885 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__884))->field0))->field1));
  llvm_cbe_tmp__883 = llvm_cbe_tmp__885;
  _ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_((&llvm_cbe_tmp__881), (&llvm_cbe_tmp__883));
  llvm_cbe_tmp__886 = *((&llvm_cbe_tmp__881.field0));
  return llvm_cbe_tmp__886;
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_5* _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__887) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__888;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__889;

  llvm_cbe_tmp__888 = llvm_cbe_tmp__887;
  llvm_cbe_tmp__889 = llvm_cbe_tmp__888;
  return (((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)((&llvm_cbe_tmp__889->field0))));
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__890) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__891;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__892;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__893;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__894;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__895;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__896;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__897;

  llvm_cbe_tmp__891 = llvm_cbe_tmp__890;
  llvm_cbe_tmp__894 = llvm_cbe_tmp__891;
  llvm_cbe_tmp__895 = *((&((&llvm_cbe_tmp__894->field0))->field0));
  llvm_cbe_tmp__896 = *((&((&llvm_cbe_tmp__894->field0))->field2));
  llvm_cbe_tmp__897 = *((&((&llvm_cbe_tmp__894->field0))->field0));
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m(llvm_cbe_tmp__894, llvm_cbe_tmp__895, (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__896)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__897)))), UINT64_C(8))));
  goto llvm_cbe_tmp__898;

llvm_cbe_tmp__898:
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev(((&llvm_cbe_tmp__894->field0)));
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_5 _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE37select_on_container_copy_constructionERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__899) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5 StructReturn;  /* Struct return temporary */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5*llvm_cbe_tmp__900 = &StructReturn;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__901;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__902;

  llvm_cbe_tmp__901 = llvm_cbe_tmp__899;
  llvm_cbe_tmp__902 = llvm_cbe_tmp__901;
  _ZNSaIP20NVariableDeclarationEC2ERKS1_(llvm_cbe_tmp__900, llvm_cbe_tmp__902);
  return StructReturn;
}


void _ZNSaIP20NVariableDeclarationEC2ERKS1_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__903, struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__904) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__905;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__906;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__907;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__908;

  llvm_cbe_tmp__905 = llvm_cbe_tmp__903;
  llvm_cbe_tmp__906 = llvm_cbe_tmp__904;
  llvm_cbe_tmp__907 = llvm_cbe_tmp__905;
  llvm_cbe_tmp__908 = llvm_cbe_tmp__906;
  _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2ERKS3_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__907)), (((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__908)));
}


void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__909, struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__910) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__911;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__912;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__913;

  llvm_cbe_tmp__911 = llvm_cbe_tmp__909;
  llvm_cbe_tmp__912 = llvm_cbe_tmp__910;
  llvm_cbe_tmp__913 = llvm_cbe_tmp__911;
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2ERKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__914, struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__915) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__916;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__917;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__918;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__919;

  llvm_cbe_tmp__916 = llvm_cbe_tmp__914;
  llvm_cbe_tmp__917 = llvm_cbe_tmp__915;
  llvm_cbe_tmp__918 = llvm_cbe_tmp__916;
  llvm_cbe_tmp__919 = llvm_cbe_tmp__917;
  _ZNSaIP20NVariableDeclarationEC2ERKS1_((((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)llvm_cbe_tmp__918)), llvm_cbe_tmp__919);
  *((&llvm_cbe_tmp__918->field0)) = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);
  *((&llvm_cbe_tmp__918->field1)) = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);
  *((&llvm_cbe_tmp__918->field2)) = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE17_M_create_storageEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__920, uint64_t llvm_cbe_tmp__921) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__922;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__923;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__924;
  uint64_t llvm_cbe_tmp__925;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__926;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__927;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__928;
  uint64_t llvm_cbe_tmp__929;

  llvm_cbe_tmp__922 = llvm_cbe_tmp__920;
  llvm_cbe_tmp__923 = llvm_cbe_tmp__921;
  llvm_cbe_tmp__924 = llvm_cbe_tmp__922;
  llvm_cbe_tmp__925 = llvm_cbe_tmp__923;
  llvm_cbe_tmp__926 = _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm(llvm_cbe_tmp__924, llvm_cbe_tmp__925);
  *((&((&llvm_cbe_tmp__924->field0))->field0)) = llvm_cbe_tmp__926;
  llvm_cbe_tmp__927 = *((&((&llvm_cbe_tmp__924->field0))->field0));
  *((&((&llvm_cbe_tmp__924->field0))->field1)) = llvm_cbe_tmp__927;
  llvm_cbe_tmp__928 = *((&((&llvm_cbe_tmp__924->field0))->field0));
  llvm_cbe_tmp__929 = llvm_cbe_tmp__923;
  *((&((&llvm_cbe_tmp__924->field0))->field2)) = ((&llvm_cbe_tmp__928[((int64_t)llvm_cbe_tmp__929)]));
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__930) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__931;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__932;

  llvm_cbe_tmp__931 = llvm_cbe_tmp__930;
  llvm_cbe_tmp__932 = llvm_cbe_tmp__931;
  _ZNSaIP20NVariableDeclarationED2Ev((((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)llvm_cbe_tmp__932)));
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__933, uint64_t llvm_cbe_tmp__934) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__935;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__936;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__937;
  uint64_t llvm_cbe_tmp__938;
  uint64_t llvm_cbe_tmp__939;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__940;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__941;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__941__PHI_TEMPORARY;

  llvm_cbe_tmp__935 = llvm_cbe_tmp__933;
  llvm_cbe_tmp__936 = llvm_cbe_tmp__934;
  llvm_cbe_tmp__937 = llvm_cbe_tmp__935;
  llvm_cbe_tmp__938 = llvm_cbe_tmp__936;
  if ((((llvm_cbe_tmp__938 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__942;
  } else {
    goto llvm_cbe_tmp__943;
  }

llvm_cbe_tmp__942:
  llvm_cbe_tmp__939 = llvm_cbe_tmp__936;
  llvm_cbe_tmp__940 = _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8allocateERS2_m((((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)((&llvm_cbe_tmp__937->field0)))), llvm_cbe_tmp__939);
  llvm_cbe_tmp__941__PHI_TEMPORARY = llvm_cbe_tmp__940;   /* for PHI node */
  goto llvm_cbe_tmp__944;

llvm_cbe_tmp__943:
  llvm_cbe_tmp__941__PHI_TEMPORARY = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__944;

llvm_cbe_tmp__944:
  llvm_cbe_tmp__941 = llvm_cbe_tmp__941__PHI_TEMPORARY;
  return llvm_cbe_tmp__941;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8allocateERS2_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__945, uint64_t llvm_cbe_tmp__946) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__947;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__948;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__949;
  uint64_t llvm_cbe_tmp__950;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__951;

  llvm_cbe_tmp__947 = llvm_cbe_tmp__945;
  llvm_cbe_tmp__948 = llvm_cbe_tmp__946;
  llvm_cbe_tmp__949 = llvm_cbe_tmp__947;
  llvm_cbe_tmp__950 = llvm_cbe_tmp__948;
  llvm_cbe_tmp__951 = _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8allocateEmPKv((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__949)), llvm_cbe_tmp__950, ((uint8_t*)/*NULL*/0));
  return llvm_cbe_tmp__951;
}


struct l_struct_class_OC_NVariableDeclaration** _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8allocateEmPKv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__952, uint64_t llvm_cbe_tmp__953, uint8_t* llvm_cbe_tmp__954) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__955;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__956;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__957;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__958;
  uint64_t llvm_cbe_tmp__959;
  uint64_t llvm_cbe_tmp__960;
  uint64_t llvm_cbe_tmp__961;
  uint8_t* llvm_cbe_tmp__962;

  llvm_cbe_tmp__955 = llvm_cbe_tmp__952;
  llvm_cbe_tmp__956 = llvm_cbe_tmp__953;
  llvm_cbe_tmp__957 = llvm_cbe_tmp__954;
  llvm_cbe_tmp__958 = llvm_cbe_tmp__955;
  llvm_cbe_tmp__959 = llvm_cbe_tmp__956;
  llvm_cbe_tmp__960 = _ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv(llvm_cbe_tmp__958);
  if ((((((uint64_t)llvm_cbe_tmp__959) > ((uint64_t)llvm_cbe_tmp__960))&1))) {
    goto llvm_cbe_tmp__963;
  } else {
    goto llvm_cbe_tmp__964;
  }

llvm_cbe_tmp__963:
  _ZSt17__throw_bad_allocv();
  __builtin_unreachable();

llvm_cbe_tmp__964:
  llvm_cbe_tmp__961 = llvm_cbe_tmp__956;
  llvm_cbe_tmp__962 = _Znwm((llvm_mul_u64(llvm_cbe_tmp__961, UINT64_C(8))));
  return (((struct l_struct_class_OC_NVariableDeclaration**)llvm_cbe_tmp__962));
}


uint64_t _ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__965) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__966;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__967;

  llvm_cbe_tmp__966 = llvm_cbe_tmp__965;
  llvm_cbe_tmp__967 = llvm_cbe_tmp__966;
  return UINT64_C(2305843009213693951);
}


void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationED2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__968) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__969;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__970;

  llvm_cbe_tmp__969 = llvm_cbe_tmp__968;
  llvm_cbe_tmp__970 = llvm_cbe_tmp__969;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__971, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__972, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__973) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__974;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__975;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__976;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__977;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__978;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__979;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__980;
  uint8_t* llvm_cbe_tmp__981;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__982;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__983;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__984;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__985;

  *((&llvm_cbe_tmp__974.field0)) = llvm_cbe_tmp__971;
  *((&llvm_cbe_tmp__975.field0)) = llvm_cbe_tmp__972;
  llvm_cbe_tmp__976 = llvm_cbe_tmp__973;
  llvm_cbe_tmp__977 = 1;
  llvm_cbe_tmp__980 = memcpy((((uint8_t*)(&llvm_cbe_tmp__978))), (((uint8_t*)(&llvm_cbe_tmp__974))), UINT64_C(8));
  llvm_cbe_tmp__981 = memcpy((((uint8_t*)(&llvm_cbe_tmp__979))), (((uint8_t*)(&llvm_cbe_tmp__975))), UINT64_C(8));
  llvm_cbe_tmp__982 = llvm_cbe_tmp__976;
  llvm_cbe_tmp__983 = *((&llvm_cbe_tmp__978.field0));
  llvm_cbe_tmp__984 = *((&llvm_cbe_tmp__979.field0));
  llvm_cbe_tmp__985 = _ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(llvm_cbe_tmp__983, llvm_cbe_tmp__984, llvm_cbe_tmp__982);
  return llvm_cbe_tmp__985;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__986, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__987, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__988) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__989;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__990;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__991;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__992;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__993;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__994;
  uint8_t* llvm_cbe_tmp__995;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__996;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__997;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__998;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__999;

  *((&llvm_cbe_tmp__989.field0)) = llvm_cbe_tmp__986;
  *((&llvm_cbe_tmp__990.field0)) = llvm_cbe_tmp__987;
  llvm_cbe_tmp__991 = llvm_cbe_tmp__988;
  llvm_cbe_tmp__994 = memcpy((((uint8_t*)(&llvm_cbe_tmp__992))), (((uint8_t*)(&llvm_cbe_tmp__989))), UINT64_C(8));
  llvm_cbe_tmp__995 = memcpy((((uint8_t*)(&llvm_cbe_tmp__993))), (((uint8_t*)(&llvm_cbe_tmp__990))), UINT64_C(8));
  llvm_cbe_tmp__996 = llvm_cbe_tmp__991;
  llvm_cbe_tmp__997 = *((&llvm_cbe_tmp__992.field0));
  llvm_cbe_tmp__998 = *((&llvm_cbe_tmp__993.field0));
  llvm_cbe_tmp__999 = _ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(llvm_cbe_tmp__997, llvm_cbe_tmp__998, llvm_cbe_tmp__996);
  return llvm_cbe_tmp__999;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1000, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1001, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1002) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1003;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1004;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1005;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1006;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1007;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1008;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1009;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1010;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1011;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1012;
  uint8_t* llvm_cbe_tmp__1013;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1014;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1015;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1016;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1017;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1018;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1019;

  *((&llvm_cbe_tmp__1003.field0)) = llvm_cbe_tmp__1000;
  *((&llvm_cbe_tmp__1004.field0)) = llvm_cbe_tmp__1001;
  llvm_cbe_tmp__1005 = llvm_cbe_tmp__1002;
  llvm_cbe_tmp__1010 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1007))), (((uint8_t*)(&llvm_cbe_tmp__1003))), UINT64_C(8));
  llvm_cbe_tmp__1011 = *((&llvm_cbe_tmp__1007.field0));
  llvm_cbe_tmp__1012 = _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_(llvm_cbe_tmp__1011);
  *((&llvm_cbe_tmp__1006.field0)) = llvm_cbe_tmp__1012;
  llvm_cbe_tmp__1013 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1009))), (((uint8_t*)(&llvm_cbe_tmp__1004))), UINT64_C(8));
  llvm_cbe_tmp__1014 = *((&llvm_cbe_tmp__1009.field0));
  llvm_cbe_tmp__1015 = _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_(llvm_cbe_tmp__1014);
  *((&llvm_cbe_tmp__1008.field0)) = llvm_cbe_tmp__1015;
  llvm_cbe_tmp__1016 = llvm_cbe_tmp__1005;
  llvm_cbe_tmp__1017 = *((&llvm_cbe_tmp__1006.field0));
  llvm_cbe_tmp__1018 = *((&llvm_cbe_tmp__1008.field0));
  llvm_cbe_tmp__1019 = _ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(llvm_cbe_tmp__1017, llvm_cbe_tmp__1018, llvm_cbe_tmp__1016);
  return llvm_cbe_tmp__1019;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1020, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1021, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1022) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1023;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1024;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1025;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1026;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1027;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1028;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1029;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1030;
  uint8_t* llvm_cbe_tmp__1031;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1032;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1033;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1034;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1035;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1036;

  *((&llvm_cbe_tmp__1023.field0)) = llvm_cbe_tmp__1020;
  *((&llvm_cbe_tmp__1024.field0)) = llvm_cbe_tmp__1021;
  llvm_cbe_tmp__1025 = llvm_cbe_tmp__1022;
  llvm_cbe_tmp__1028 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1026))), (((uint8_t*)(&llvm_cbe_tmp__1023))), UINT64_C(8));
  llvm_cbe_tmp__1029 = *((&llvm_cbe_tmp__1026.field0));
  llvm_cbe_tmp__1030 = _ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(llvm_cbe_tmp__1029);
  llvm_cbe_tmp__1031 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1027))), (((uint8_t*)(&llvm_cbe_tmp__1024))), UINT64_C(8));
  llvm_cbe_tmp__1032 = *((&llvm_cbe_tmp__1027.field0));
  llvm_cbe_tmp__1033 = _ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(llvm_cbe_tmp__1032);
  llvm_cbe_tmp__1034 = llvm_cbe_tmp__1025;
  llvm_cbe_tmp__1035 = _ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(llvm_cbe_tmp__1034);
  llvm_cbe_tmp__1036 = _ZSt13__copy_move_aILb0EPKP20NVariableDeclarationPS1_ET1_T0_S6_S5_(llvm_cbe_tmp__1030, llvm_cbe_tmp__1033, llvm_cbe_tmp__1035);
  return llvm_cbe_tmp__1036;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1037) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1038;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1039;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1040;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1041;

  *((&llvm_cbe_tmp__1039.field0)) = llvm_cbe_tmp__1037;
  llvm_cbe_tmp__1040 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1038))), (((uint8_t*)(&llvm_cbe_tmp__1039))), UINT64_C(8));
  llvm_cbe_tmp__1041 = *((&llvm_cbe_tmp__1038.field0));
  return llvm_cbe_tmp__1041;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt13__copy_move_aILb0EPKP20NVariableDeclarationPS1_ET1_T0_S6_S5_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1042, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1043, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1044) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1045;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1046;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1047;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__1048;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1049;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1050;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1051;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1052;

  llvm_cbe_tmp__1045 = llvm_cbe_tmp__1042;
  llvm_cbe_tmp__1046 = llvm_cbe_tmp__1043;
  llvm_cbe_tmp__1047 = llvm_cbe_tmp__1044;
  llvm_cbe_tmp__1048 = 1;
  llvm_cbe_tmp__1049 = llvm_cbe_tmp__1045;
  llvm_cbe_tmp__1050 = llvm_cbe_tmp__1046;
  llvm_cbe_tmp__1051 = llvm_cbe_tmp__1047;
  llvm_cbe_tmp__1052 = _ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(llvm_cbe_tmp__1049, llvm_cbe_tmp__1050, llvm_cbe_tmp__1051);
  return llvm_cbe_tmp__1052;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1053) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator llvm_cbe_tmp__1054;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__1055;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1056;

  *((&llvm_cbe_tmp__1054.field0)) = llvm_cbe_tmp__1053;
  llvm_cbe_tmp__1055 = _ZNK9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__1054));
  llvm_cbe_tmp__1056 = *llvm_cbe_tmp__1055;
  return llvm_cbe_tmp__1056;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1057) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1058;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1059;

  llvm_cbe_tmp__1058 = llvm_cbe_tmp__1057;
  llvm_cbe_tmp__1059 = llvm_cbe_tmp__1058;
  return llvm_cbe_tmp__1059;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1060, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1061, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1062) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1063;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1064;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1065;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1066;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1067;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1068;
  uint64_t llvm_cbe_tmp__1069;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1070;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1071;
  uint64_t llvm_cbe_tmp__1072;
  uint8_t* llvm_cbe_tmp__1073;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1074;
  uint64_t llvm_cbe_tmp__1075;

  llvm_cbe_tmp__1063 = llvm_cbe_tmp__1060;
  llvm_cbe_tmp__1064 = llvm_cbe_tmp__1061;
  llvm_cbe_tmp__1065 = llvm_cbe_tmp__1062;
  llvm_cbe_tmp__1067 = llvm_cbe_tmp__1064;
  llvm_cbe_tmp__1068 = llvm_cbe_tmp__1063;
  llvm_cbe_tmp__1066 = (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1067)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1068)))), UINT64_C(8)));
  llvm_cbe_tmp__1069 = llvm_cbe_tmp__1066;
  if ((((llvm_cbe_tmp__1069 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__1076;
  } else {
    goto llvm_cbe_tmp__1077;
  }

llvm_cbe_tmp__1076:
  llvm_cbe_tmp__1070 = llvm_cbe_tmp__1065;
  llvm_cbe_tmp__1071 = llvm_cbe_tmp__1063;
  llvm_cbe_tmp__1072 = llvm_cbe_tmp__1066;
  llvm_cbe_tmp__1073 = memmove((((uint8_t*)llvm_cbe_tmp__1070)), (((uint8_t*)llvm_cbe_tmp__1071)), (llvm_mul_u64(UINT64_C(8), llvm_cbe_tmp__1072)));
  goto llvm_cbe_tmp__1077;

llvm_cbe_tmp__1077:
  llvm_cbe_tmp__1074 = llvm_cbe_tmp__1065;
  llvm_cbe_tmp__1075 = llvm_cbe_tmp__1066;
  return ((&llvm_cbe_tmp__1074[((int64_t)llvm_cbe_tmp__1075)]));
}


struct l_struct_class_OC_NVariableDeclaration*** _ZNK9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator* llvm_cbe_tmp__1078) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator* llvm_cbe_tmp__1079;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator* llvm_cbe_tmp__1080;

  llvm_cbe_tmp__1079 = llvm_cbe_tmp__1078;
  llvm_cbe_tmp__1080 = llvm_cbe_tmp__1079;
  return ((&llvm_cbe_tmp__1080->field0));
}


void _ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator* llvm_cbe_tmp__1081, struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__1082) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator* llvm_cbe_tmp__1083;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__1084;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator* llvm_cbe_tmp__1085;
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__1086;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1087;

  llvm_cbe_tmp__1083 = llvm_cbe_tmp__1081;
  llvm_cbe_tmp__1084 = llvm_cbe_tmp__1082;
  llvm_cbe_tmp__1085 = llvm_cbe_tmp__1083;
  llvm_cbe_tmp__1086 = llvm_cbe_tmp__1084;
  llvm_cbe_tmp__1087 = *llvm_cbe_tmp__1086;
  *((&llvm_cbe_tmp__1085->field0)) = llvm_cbe_tmp__1087;
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__1088, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1089, uint64_t llvm_cbe_tmp__1090) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__1091;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1092;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1093;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__1094;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1095;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1096;
  uint64_t llvm_cbe_tmp__1097;

  llvm_cbe_tmp__1091 = llvm_cbe_tmp__1088;
  llvm_cbe_tmp__1092 = llvm_cbe_tmp__1089;
  llvm_cbe_tmp__1093 = llvm_cbe_tmp__1090;
  llvm_cbe_tmp__1094 = llvm_cbe_tmp__1091;
  llvm_cbe_tmp__1095 = llvm_cbe_tmp__1092;
  if ((((llvm_cbe_tmp__1095 != ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1098;
  } else {
    goto llvm_cbe_tmp__1099;
  }

llvm_cbe_tmp__1098:
  llvm_cbe_tmp__1096 = llvm_cbe_tmp__1092;
  llvm_cbe_tmp__1097 = llvm_cbe_tmp__1093;
  _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE10deallocateERS2_PS1_m((((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)((&llvm_cbe_tmp__1094->field0)))), llvm_cbe_tmp__1096, llvm_cbe_tmp__1097);
  goto llvm_cbe_tmp__1099;

llvm_cbe_tmp__1099:
  return;
}


void _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE10deallocateERS2_PS1_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1100, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1101, uint64_t llvm_cbe_tmp__1102) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1103;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1104;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1105;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1106;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1107;
  uint64_t llvm_cbe_tmp__1108;

  llvm_cbe_tmp__1103 = llvm_cbe_tmp__1100;
  llvm_cbe_tmp__1104 = llvm_cbe_tmp__1101;
  llvm_cbe_tmp__1105 = llvm_cbe_tmp__1102;
  llvm_cbe_tmp__1106 = llvm_cbe_tmp__1103;
  llvm_cbe_tmp__1107 = llvm_cbe_tmp__1104;
  llvm_cbe_tmp__1108 = llvm_cbe_tmp__1105;
  _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE10deallocateEPS2_m((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__1106)), llvm_cbe_tmp__1107, llvm_cbe_tmp__1108);
}


void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE10deallocateEPS2_m(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1109, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1110, uint64_t llvm_cbe_tmp__1111) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1112;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1113;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1114;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1115;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1116;

  llvm_cbe_tmp__1112 = llvm_cbe_tmp__1109;
  llvm_cbe_tmp__1113 = llvm_cbe_tmp__1110;
  llvm_cbe_tmp__1114 = llvm_cbe_tmp__1111;
  llvm_cbe_tmp__1115 = llvm_cbe_tmp__1112;
  llvm_cbe_tmp__1116 = llvm_cbe_tmp__1113;
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__1116)));
}


void _ZN11NIdentifierD2Ev(struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1117) {
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1118;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1119;

  llvm_cbe_tmp__1118 = llvm_cbe_tmp__1117;
  llvm_cbe_tmp__1119 = llvm_cbe_tmp__1118;
  *(((l_fptr_2***)llvm_cbe_tmp__1119)) = ((l_fptr_2**)((&_ZTV11NIdentifier.field0.array[((int32_t)2)])));
  _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(((&llvm_cbe_tmp__1119->field1)));
  _ZN11NExpressionD2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__1119)));
}


void _ZN11NIdentifierD0Ev(struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1120) {
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1121;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1122;

  llvm_cbe_tmp__1121 = llvm_cbe_tmp__1120;
  llvm_cbe_tmp__1122 = llvm_cbe_tmp__1121;
  _ZN11NIdentifierD2Ev(llvm_cbe_tmp__1122);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__1122)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN11NIdentifier7codeGenER14CodeGenContext(struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1123, void* llvm_cbe_tmp__1124) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__1125;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1126;    /* Address-exposed local */
  void* llvm_cbe_tmp__1127;    /* Address-exposed local */
  struct l_struct_class_OC_NIdentifier* llvm_cbe_tmp__1128;

  llvm_cbe_tmp__1126 = llvm_cbe_tmp__1123;
  llvm_cbe_tmp__1127 = llvm_cbe_tmp__1124;
  llvm_cbe_tmp__1128 = llvm_cbe_tmp__1126;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZN7NDoubleD2Ev(struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1129) {
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1130;    /* Address-exposed local */
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1131;

  llvm_cbe_tmp__1130 = llvm_cbe_tmp__1129;
  llvm_cbe_tmp__1131 = llvm_cbe_tmp__1130;
  _ZN11NExpressionD2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__1131)));
}


void _ZN7NDoubleD0Ev(struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1132) {
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1133;    /* Address-exposed local */
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1134;

  llvm_cbe_tmp__1133 = llvm_cbe_tmp__1132;
  llvm_cbe_tmp__1134 = llvm_cbe_tmp__1133;
  _ZN7NDoubleD2Ev(llvm_cbe_tmp__1134);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__1134)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN7NDouble7codeGenER14CodeGenContext(struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1135, void* llvm_cbe_tmp__1136) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__1137;    /* Address-exposed local */
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1138;    /* Address-exposed local */
  void* llvm_cbe_tmp__1139;    /* Address-exposed local */
  struct l_struct_class_OC_NDouble* llvm_cbe_tmp__1140;

  llvm_cbe_tmp__1138 = llvm_cbe_tmp__1135;
  llvm_cbe_tmp__1139 = llvm_cbe_tmp__1136;
  llvm_cbe_tmp__1140 = llvm_cbe_tmp__1138;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZN11NAssignmentD2Ev(struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1141) {
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1142;    /* Address-exposed local */
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1143;

  llvm_cbe_tmp__1142 = llvm_cbe_tmp__1141;
  llvm_cbe_tmp__1143 = llvm_cbe_tmp__1142;
  _ZN11NExpressionD2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__1143)));
}


void _ZN11NAssignmentD0Ev(struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1144) {
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1145;    /* Address-exposed local */
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1146;

  llvm_cbe_tmp__1145 = llvm_cbe_tmp__1144;
  llvm_cbe_tmp__1146 = llvm_cbe_tmp__1145;
  _ZN11NAssignmentD2Ev(llvm_cbe_tmp__1146);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__1146)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN11NAssignment7codeGenER14CodeGenContext(struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1147, void* llvm_cbe_tmp__1148) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__1149;    /* Address-exposed local */
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1150;    /* Address-exposed local */
  void* llvm_cbe_tmp__1151;    /* Address-exposed local */
  struct l_struct_class_OC_NAssignment* llvm_cbe_tmp__1152;

  llvm_cbe_tmp__1150 = llvm_cbe_tmp__1147;
  llvm_cbe_tmp__1151 = llvm_cbe_tmp__1148;
  llvm_cbe_tmp__1152 = llvm_cbe_tmp__1150;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZNSt6vectorIP11NExpressionSaIS1_EEC2ERKS3_(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1153, struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1154) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1155;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1156;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10 llvm_cbe_tmp__1157;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1158;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1159;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1160;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1161;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1162;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1163;
  uint64_t llvm_cbe_tmp__1164;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1165;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1166;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1167;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1168;
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1169;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1170;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1171;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1172;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1173;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1174;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1175;

  llvm_cbe_tmp__1155 = llvm_cbe_tmp__1153;
  llvm_cbe_tmp__1156 = llvm_cbe_tmp__1154;
  llvm_cbe_tmp__1162 = llvm_cbe_tmp__1155;
  llvm_cbe_tmp__1163 = llvm_cbe_tmp__1156;
  llvm_cbe_tmp__1164 = _ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(llvm_cbe_tmp__1163);
  llvm_cbe_tmp__1165 = llvm_cbe_tmp__1156;
  llvm_cbe_tmp__1166 = _ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1165)));
  llvm_cbe_tmp__1157 = _ZN9__gnu_cxx14__alloc_traitsISaIP11NExpressionES2_E17_S_select_on_copyERKS3_(llvm_cbe_tmp__1166);
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2EmRKS2_((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1162)), llvm_cbe_tmp__1164, (&llvm_cbe_tmp__1157));
  goto llvm_cbe_tmp__1176;

llvm_cbe_tmp__1176:
  _ZNSaIP11NExpressionED2Ev((&llvm_cbe_tmp__1157));
  llvm_cbe_tmp__1167 = llvm_cbe_tmp__1156;
  llvm_cbe_tmp__1168 = _ZNKSt6vectorIP11NExpressionSaIS1_EE5beginEv(llvm_cbe_tmp__1167);
  *((&llvm_cbe_tmp__1160.field0)) = llvm_cbe_tmp__1168;
  llvm_cbe_tmp__1169 = llvm_cbe_tmp__1156;
  llvm_cbe_tmp__1170 = _ZNKSt6vectorIP11NExpressionSaIS1_EE3endEv(llvm_cbe_tmp__1169);
  *((&llvm_cbe_tmp__1161.field0)) = llvm_cbe_tmp__1170;
  llvm_cbe_tmp__1171 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1162))->field0))->field0));
  llvm_cbe_tmp__1172 = _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1162)));
  llvm_cbe_tmp__1173 = *((&llvm_cbe_tmp__1160.field0));
  llvm_cbe_tmp__1174 = *((&llvm_cbe_tmp__1161.field0));
  llvm_cbe_tmp__1175 = _ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(llvm_cbe_tmp__1173, llvm_cbe_tmp__1174, llvm_cbe_tmp__1171, llvm_cbe_tmp__1172);
  goto llvm_cbe_tmp__1177;

llvm_cbe_tmp__1177:
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1162))->field0))->field1)) = llvm_cbe_tmp__1175;
}


void _ZN11NMethodCallD2Ev(struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1178) {
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1179;    /* Address-exposed local */
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1180;

  llvm_cbe_tmp__1179 = llvm_cbe_tmp__1178;
  llvm_cbe_tmp__1180 = llvm_cbe_tmp__1179;
  *(((l_fptr_2***)llvm_cbe_tmp__1180)) = ((l_fptr_2**)((&_ZTV11NMethodCall.field0.array[((int32_t)2)])));
  _ZNSt6vectorIP11NExpressionSaIS1_EED2Ev(((&llvm_cbe_tmp__1180->field2)));
  _ZN11NExpressionD2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__1180)));
}


void _ZN11NMethodCallD0Ev(struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1181) {
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1182;    /* Address-exposed local */
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1183;

  llvm_cbe_tmp__1182 = llvm_cbe_tmp__1181;
  llvm_cbe_tmp__1183 = llvm_cbe_tmp__1182;
  _ZN11NMethodCallD2Ev(llvm_cbe_tmp__1183);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__1183)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN11NMethodCall7codeGenER14CodeGenContext(struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1184, void* llvm_cbe_tmp__1185) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__1186;    /* Address-exposed local */
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1187;    /* Address-exposed local */
  void* llvm_cbe_tmp__1188;    /* Address-exposed local */
  struct l_struct_class_OC_NMethodCall* llvm_cbe_tmp__1189;

  llvm_cbe_tmp__1187 = llvm_cbe_tmp__1184;
  llvm_cbe_tmp__1188 = llvm_cbe_tmp__1185;
  llvm_cbe_tmp__1189 = llvm_cbe_tmp__1187;
  llvm_OC_trap();
  __builtin_unreachable();

}


uint64_t _ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1190) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1191;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1192;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1193;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1194;

  llvm_cbe_tmp__1191 = llvm_cbe_tmp__1190;
  llvm_cbe_tmp__1192 = llvm_cbe_tmp__1191;
  llvm_cbe_tmp__1193 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1192))->field0))->field1));
  llvm_cbe_tmp__1194 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1192))->field0))->field0));
  return (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1193)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1194)))), UINT64_C(8)));
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_10 _ZN9__gnu_cxx14__alloc_traitsISaIP11NExpressionES2_E17_S_select_on_copyERKS3_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1195) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10 StructReturn;  /* Struct return temporary */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10*llvm_cbe_tmp__1196 = &StructReturn;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1197;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1198;

  llvm_cbe_tmp__1197 = llvm_cbe_tmp__1195;
  llvm_cbe_tmp__1198 = llvm_cbe_tmp__1197;
  *(llvm_cbe_tmp__1196) = _ZNSt16allocator_traitsISaIP11NExpressionEE37select_on_container_copy_constructionERKS2_(llvm_cbe_tmp__1198);
  return StructReturn;
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_10* _ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1199) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1200;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1201;

  llvm_cbe_tmp__1200 = llvm_cbe_tmp__1199;
  llvm_cbe_tmp__1201 = llvm_cbe_tmp__1200;
  return (((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)((&llvm_cbe_tmp__1201->field0))));
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2EmRKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1202, uint64_t llvm_cbe_tmp__1203, struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1204) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1205;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1206;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1207;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1208;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1209;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1210;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1211;
  uint64_t llvm_cbe_tmp__1212;

  llvm_cbe_tmp__1205 = llvm_cbe_tmp__1202;
  llvm_cbe_tmp__1206 = llvm_cbe_tmp__1203;
  llvm_cbe_tmp__1207 = llvm_cbe_tmp__1204;
  llvm_cbe_tmp__1210 = llvm_cbe_tmp__1205;
  llvm_cbe_tmp__1211 = llvm_cbe_tmp__1207;
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2ERKS2_(((&llvm_cbe_tmp__1210->field0)), llvm_cbe_tmp__1211);
  llvm_cbe_tmp__1212 = llvm_cbe_tmp__1206;
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE17_M_create_storageEm(llvm_cbe_tmp__1210, llvm_cbe_tmp__1212);
  goto llvm_cbe_tmp__1213;

llvm_cbe_tmp__1213:
  return;
}


void _ZNSaIP11NExpressionED2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1214) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1215;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1216;

  llvm_cbe_tmp__1215 = llvm_cbe_tmp__1214;
  llvm_cbe_tmp__1216 = llvm_cbe_tmp__1215;
  _ZN9__gnu_cxx13new_allocatorIP11NExpressionED2Ev((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__1216)));
}


struct l_struct_class_OC_NExpression** _ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1217, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1218, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1219, struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1220) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1221;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1222;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1223;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1224;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1225;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1226;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1227;
  uint8_t* llvm_cbe_tmp__1228;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1229;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1230;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1231;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1232;

  *((&llvm_cbe_tmp__1221.field0)) = llvm_cbe_tmp__1217;
  *((&llvm_cbe_tmp__1222.field0)) = llvm_cbe_tmp__1218;
  llvm_cbe_tmp__1223 = llvm_cbe_tmp__1219;
  llvm_cbe_tmp__1224 = llvm_cbe_tmp__1220;
  llvm_cbe_tmp__1227 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1225))), (((uint8_t*)(&llvm_cbe_tmp__1221))), UINT64_C(8));
  llvm_cbe_tmp__1228 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1226))), (((uint8_t*)(&llvm_cbe_tmp__1222))), UINT64_C(8));
  llvm_cbe_tmp__1229 = llvm_cbe_tmp__1223;
  llvm_cbe_tmp__1230 = *((&llvm_cbe_tmp__1225.field0));
  llvm_cbe_tmp__1231 = *((&llvm_cbe_tmp__1226.field0));
  llvm_cbe_tmp__1232 = _ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(llvm_cbe_tmp__1230, llvm_cbe_tmp__1231, llvm_cbe_tmp__1229);
  return llvm_cbe_tmp__1232;
}


struct l_struct_class_OC_NExpression** _ZNKSt6vectorIP11NExpressionSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1233) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1234;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1235;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1236;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1237;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1238;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1239;

  llvm_cbe_tmp__1235 = llvm_cbe_tmp__1233;
  llvm_cbe_tmp__1237 = llvm_cbe_tmp__1235;
  llvm_cbe_tmp__1238 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1237))->field0))->field0));
  llvm_cbe_tmp__1236 = llvm_cbe_tmp__1238;
  _ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_((&llvm_cbe_tmp__1234), (&llvm_cbe_tmp__1236));
  llvm_cbe_tmp__1239 = *((&llvm_cbe_tmp__1234.field0));
  return llvm_cbe_tmp__1239;
}


struct l_struct_class_OC_NExpression** _ZNKSt6vectorIP11NExpressionSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1240) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1241;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1242;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1243;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__1244;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1245;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1246;

  llvm_cbe_tmp__1242 = llvm_cbe_tmp__1240;
  llvm_cbe_tmp__1244 = llvm_cbe_tmp__1242;
  llvm_cbe_tmp__1245 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__1244))->field0))->field1));
  llvm_cbe_tmp__1243 = llvm_cbe_tmp__1245;
  _ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_((&llvm_cbe_tmp__1241), (&llvm_cbe_tmp__1243));
  llvm_cbe_tmp__1246 = *((&llvm_cbe_tmp__1241.field0));
  return llvm_cbe_tmp__1246;
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_10* _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1247) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1248;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1249;

  llvm_cbe_tmp__1248 = llvm_cbe_tmp__1247;
  llvm_cbe_tmp__1249 = llvm_cbe_tmp__1248;
  return (((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)((&llvm_cbe_tmp__1249->field0))));
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1250) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1251;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1252;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1253;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1254;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1255;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1256;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1257;

  llvm_cbe_tmp__1251 = llvm_cbe_tmp__1250;
  llvm_cbe_tmp__1254 = llvm_cbe_tmp__1251;
  llvm_cbe_tmp__1255 = *((&((&llvm_cbe_tmp__1254->field0))->field0));
  llvm_cbe_tmp__1256 = *((&((&llvm_cbe_tmp__1254->field0))->field2));
  llvm_cbe_tmp__1257 = *((&((&llvm_cbe_tmp__1254->field0))->field0));
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m(llvm_cbe_tmp__1254, llvm_cbe_tmp__1255, (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1256)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1257)))), UINT64_C(8))));
  goto llvm_cbe_tmp__1258;

llvm_cbe_tmp__1258:
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev(((&llvm_cbe_tmp__1254->field0)));
}


struct l_struct_class_OC_std_KD__KD_allocator_OC_10 _ZNSt16allocator_traitsISaIP11NExpressionEE37select_on_container_copy_constructionERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1259) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10 StructReturn;  /* Struct return temporary */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10*llvm_cbe_tmp__1260 = &StructReturn;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1261;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1262;

  llvm_cbe_tmp__1261 = llvm_cbe_tmp__1259;
  llvm_cbe_tmp__1262 = llvm_cbe_tmp__1261;
  _ZNSaIP11NExpressionEC2ERKS1_(llvm_cbe_tmp__1260, llvm_cbe_tmp__1262);
  return StructReturn;
}


void _ZNSaIP11NExpressionEC2ERKS1_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1263, struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1264) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1265;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1266;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1267;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1268;

  llvm_cbe_tmp__1265 = llvm_cbe_tmp__1263;
  llvm_cbe_tmp__1266 = llvm_cbe_tmp__1264;
  llvm_cbe_tmp__1267 = llvm_cbe_tmp__1265;
  llvm_cbe_tmp__1268 = llvm_cbe_tmp__1266;
  _ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2ERKS3_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__1267)), (((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__1268)));
}


void _ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1269, struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1270) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1271;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1272;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1273;

  llvm_cbe_tmp__1271 = llvm_cbe_tmp__1269;
  llvm_cbe_tmp__1272 = llvm_cbe_tmp__1270;
  llvm_cbe_tmp__1273 = llvm_cbe_tmp__1271;
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2ERKS2_(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1274, struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1275) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1276;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1277;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1278;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1279;

  llvm_cbe_tmp__1276 = llvm_cbe_tmp__1274;
  llvm_cbe_tmp__1277 = llvm_cbe_tmp__1275;
  llvm_cbe_tmp__1278 = llvm_cbe_tmp__1276;
  llvm_cbe_tmp__1279 = llvm_cbe_tmp__1277;
  _ZNSaIP11NExpressionEC2ERKS1_((((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)llvm_cbe_tmp__1278)), llvm_cbe_tmp__1279);
  *((&llvm_cbe_tmp__1278->field0)) = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);
  *((&llvm_cbe_tmp__1278->field1)) = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);
  *((&llvm_cbe_tmp__1278->field2)) = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE17_M_create_storageEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1280, uint64_t llvm_cbe_tmp__1281) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1282;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1283;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1284;
  uint64_t llvm_cbe_tmp__1285;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1286;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1287;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1288;
  uint64_t llvm_cbe_tmp__1289;

  llvm_cbe_tmp__1282 = llvm_cbe_tmp__1280;
  llvm_cbe_tmp__1283 = llvm_cbe_tmp__1281;
  llvm_cbe_tmp__1284 = llvm_cbe_tmp__1282;
  llvm_cbe_tmp__1285 = llvm_cbe_tmp__1283;
  llvm_cbe_tmp__1286 = _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm(llvm_cbe_tmp__1284, llvm_cbe_tmp__1285);
  *((&((&llvm_cbe_tmp__1284->field0))->field0)) = llvm_cbe_tmp__1286;
  llvm_cbe_tmp__1287 = *((&((&llvm_cbe_tmp__1284->field0))->field0));
  *((&((&llvm_cbe_tmp__1284->field0))->field1)) = llvm_cbe_tmp__1287;
  llvm_cbe_tmp__1288 = *((&((&llvm_cbe_tmp__1284->field0))->field0));
  llvm_cbe_tmp__1289 = llvm_cbe_tmp__1283;
  *((&((&llvm_cbe_tmp__1284->field0))->field2)) = ((&llvm_cbe_tmp__1288[((int64_t)llvm_cbe_tmp__1289)]));
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1290) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1291;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1292;

  llvm_cbe_tmp__1291 = llvm_cbe_tmp__1290;
  llvm_cbe_tmp__1292 = llvm_cbe_tmp__1291;
  _ZNSaIP11NExpressionED2Ev((((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)llvm_cbe_tmp__1292)));
}


struct l_struct_class_OC_NExpression** _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1293, uint64_t llvm_cbe_tmp__1294) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1295;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1296;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1297;
  uint64_t llvm_cbe_tmp__1298;
  uint64_t llvm_cbe_tmp__1299;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1300;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1301;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1301__PHI_TEMPORARY;

  llvm_cbe_tmp__1295 = llvm_cbe_tmp__1293;
  llvm_cbe_tmp__1296 = llvm_cbe_tmp__1294;
  llvm_cbe_tmp__1297 = llvm_cbe_tmp__1295;
  llvm_cbe_tmp__1298 = llvm_cbe_tmp__1296;
  if ((((llvm_cbe_tmp__1298 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__1302;
  } else {
    goto llvm_cbe_tmp__1303;
  }

llvm_cbe_tmp__1302:
  llvm_cbe_tmp__1299 = llvm_cbe_tmp__1296;
  llvm_cbe_tmp__1300 = _ZNSt16allocator_traitsISaIP11NExpressionEE8allocateERS2_m((((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)((&llvm_cbe_tmp__1297->field0)))), llvm_cbe_tmp__1299);
  llvm_cbe_tmp__1301__PHI_TEMPORARY = llvm_cbe_tmp__1300;   /* for PHI node */
  goto llvm_cbe_tmp__1304;

llvm_cbe_tmp__1303:
  llvm_cbe_tmp__1301__PHI_TEMPORARY = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__1304;

llvm_cbe_tmp__1304:
  llvm_cbe_tmp__1301 = llvm_cbe_tmp__1301__PHI_TEMPORARY;
  return llvm_cbe_tmp__1301;
}


struct l_struct_class_OC_NExpression** _ZNSt16allocator_traitsISaIP11NExpressionEE8allocateERS2_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1305, uint64_t llvm_cbe_tmp__1306) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1307;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1308;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1309;
  uint64_t llvm_cbe_tmp__1310;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1311;

  llvm_cbe_tmp__1307 = llvm_cbe_tmp__1305;
  llvm_cbe_tmp__1308 = llvm_cbe_tmp__1306;
  llvm_cbe_tmp__1309 = llvm_cbe_tmp__1307;
  llvm_cbe_tmp__1310 = llvm_cbe_tmp__1308;
  llvm_cbe_tmp__1311 = _ZN9__gnu_cxx13new_allocatorIP11NExpressionE8allocateEmPKv((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__1309)), llvm_cbe_tmp__1310, ((uint8_t*)/*NULL*/0));
  return llvm_cbe_tmp__1311;
}


struct l_struct_class_OC_NExpression** _ZN9__gnu_cxx13new_allocatorIP11NExpressionE8allocateEmPKv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1312, uint64_t llvm_cbe_tmp__1313, uint8_t* llvm_cbe_tmp__1314) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1315;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1316;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1317;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1318;
  uint64_t llvm_cbe_tmp__1319;
  uint64_t llvm_cbe_tmp__1320;
  uint64_t llvm_cbe_tmp__1321;
  uint8_t* llvm_cbe_tmp__1322;

  llvm_cbe_tmp__1315 = llvm_cbe_tmp__1312;
  llvm_cbe_tmp__1316 = llvm_cbe_tmp__1313;
  llvm_cbe_tmp__1317 = llvm_cbe_tmp__1314;
  llvm_cbe_tmp__1318 = llvm_cbe_tmp__1315;
  llvm_cbe_tmp__1319 = llvm_cbe_tmp__1316;
  llvm_cbe_tmp__1320 = _ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv(llvm_cbe_tmp__1318);
  if ((((((uint64_t)llvm_cbe_tmp__1319) > ((uint64_t)llvm_cbe_tmp__1320))&1))) {
    goto llvm_cbe_tmp__1323;
  } else {
    goto llvm_cbe_tmp__1324;
  }

llvm_cbe_tmp__1323:
  _ZSt17__throw_bad_allocv();
  __builtin_unreachable();

llvm_cbe_tmp__1324:
  llvm_cbe_tmp__1321 = llvm_cbe_tmp__1316;
  llvm_cbe_tmp__1322 = _Znwm((llvm_mul_u64(llvm_cbe_tmp__1321, UINT64_C(8))));
  return (((struct l_struct_class_OC_NExpression**)llvm_cbe_tmp__1322));
}


uint64_t _ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1325) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1326;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1327;

  llvm_cbe_tmp__1326 = llvm_cbe_tmp__1325;
  llvm_cbe_tmp__1327 = llvm_cbe_tmp__1326;
  return UINT64_C(2305843009213693951);
}


void _ZN9__gnu_cxx13new_allocatorIP11NExpressionED2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1328) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1329;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1330;

  llvm_cbe_tmp__1329 = llvm_cbe_tmp__1328;
  llvm_cbe_tmp__1330 = llvm_cbe_tmp__1329;
}


struct l_struct_class_OC_NExpression** _ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1331, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1332, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1333) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1334;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1335;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1336;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__1337;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1338;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1339;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1340;
  uint8_t* llvm_cbe_tmp__1341;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1342;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1343;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1344;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1345;

  *((&llvm_cbe_tmp__1334.field0)) = llvm_cbe_tmp__1331;
  *((&llvm_cbe_tmp__1335.field0)) = llvm_cbe_tmp__1332;
  llvm_cbe_tmp__1336 = llvm_cbe_tmp__1333;
  llvm_cbe_tmp__1337 = 1;
  llvm_cbe_tmp__1340 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1338))), (((uint8_t*)(&llvm_cbe_tmp__1334))), UINT64_C(8));
  llvm_cbe_tmp__1341 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1339))), (((uint8_t*)(&llvm_cbe_tmp__1335))), UINT64_C(8));
  llvm_cbe_tmp__1342 = llvm_cbe_tmp__1336;
  llvm_cbe_tmp__1343 = *((&llvm_cbe_tmp__1338.field0));
  llvm_cbe_tmp__1344 = *((&llvm_cbe_tmp__1339.field0));
  llvm_cbe_tmp__1345 = _ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(llvm_cbe_tmp__1343, llvm_cbe_tmp__1344, llvm_cbe_tmp__1342);
  return llvm_cbe_tmp__1345;
}


struct l_struct_class_OC_NExpression** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1346, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1347, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1348) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1349;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1350;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1351;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1352;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1353;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1354;
  uint8_t* llvm_cbe_tmp__1355;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1356;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1357;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1358;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1359;

  *((&llvm_cbe_tmp__1349.field0)) = llvm_cbe_tmp__1346;
  *((&llvm_cbe_tmp__1350.field0)) = llvm_cbe_tmp__1347;
  llvm_cbe_tmp__1351 = llvm_cbe_tmp__1348;
  llvm_cbe_tmp__1354 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1352))), (((uint8_t*)(&llvm_cbe_tmp__1349))), UINT64_C(8));
  llvm_cbe_tmp__1355 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1353))), (((uint8_t*)(&llvm_cbe_tmp__1350))), UINT64_C(8));
  llvm_cbe_tmp__1356 = llvm_cbe_tmp__1351;
  llvm_cbe_tmp__1357 = *((&llvm_cbe_tmp__1352.field0));
  llvm_cbe_tmp__1358 = *((&llvm_cbe_tmp__1353.field0));
  llvm_cbe_tmp__1359 = _ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(llvm_cbe_tmp__1357, llvm_cbe_tmp__1358, llvm_cbe_tmp__1356);
  return llvm_cbe_tmp__1359;
}


struct l_struct_class_OC_NExpression** _ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1360, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1361, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1362) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1363;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1364;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1365;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1366;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1367;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1368;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1369;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1370;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1371;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1372;
  uint8_t* llvm_cbe_tmp__1373;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1374;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1375;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1376;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1377;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1378;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1379;

  *((&llvm_cbe_tmp__1363.field0)) = llvm_cbe_tmp__1360;
  *((&llvm_cbe_tmp__1364.field0)) = llvm_cbe_tmp__1361;
  llvm_cbe_tmp__1365 = llvm_cbe_tmp__1362;
  llvm_cbe_tmp__1370 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1367))), (((uint8_t*)(&llvm_cbe_tmp__1363))), UINT64_C(8));
  llvm_cbe_tmp__1371 = *((&llvm_cbe_tmp__1367.field0));
  llvm_cbe_tmp__1372 = _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_(llvm_cbe_tmp__1371);
  *((&llvm_cbe_tmp__1366.field0)) = llvm_cbe_tmp__1372;
  llvm_cbe_tmp__1373 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1369))), (((uint8_t*)(&llvm_cbe_tmp__1364))), UINT64_C(8));
  llvm_cbe_tmp__1374 = *((&llvm_cbe_tmp__1369.field0));
  llvm_cbe_tmp__1375 = _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_(llvm_cbe_tmp__1374);
  *((&llvm_cbe_tmp__1368.field0)) = llvm_cbe_tmp__1375;
  llvm_cbe_tmp__1376 = llvm_cbe_tmp__1365;
  llvm_cbe_tmp__1377 = *((&llvm_cbe_tmp__1366.field0));
  llvm_cbe_tmp__1378 = *((&llvm_cbe_tmp__1368.field0));
  llvm_cbe_tmp__1379 = _ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(llvm_cbe_tmp__1377, llvm_cbe_tmp__1378, llvm_cbe_tmp__1376);
  return llvm_cbe_tmp__1379;
}


struct l_struct_class_OC_NExpression** _ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1380, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1381, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1382) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1383;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1384;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1385;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1386;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1387;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1388;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1389;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1390;
  uint8_t* llvm_cbe_tmp__1391;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1392;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1393;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1394;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1395;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1396;

  *((&llvm_cbe_tmp__1383.field0)) = llvm_cbe_tmp__1380;
  *((&llvm_cbe_tmp__1384.field0)) = llvm_cbe_tmp__1381;
  llvm_cbe_tmp__1385 = llvm_cbe_tmp__1382;
  llvm_cbe_tmp__1388 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1386))), (((uint8_t*)(&llvm_cbe_tmp__1383))), UINT64_C(8));
  llvm_cbe_tmp__1389 = *((&llvm_cbe_tmp__1386.field0));
  llvm_cbe_tmp__1390 = _ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(llvm_cbe_tmp__1389);
  llvm_cbe_tmp__1391 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1387))), (((uint8_t*)(&llvm_cbe_tmp__1384))), UINT64_C(8));
  llvm_cbe_tmp__1392 = *((&llvm_cbe_tmp__1387.field0));
  llvm_cbe_tmp__1393 = _ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(llvm_cbe_tmp__1392);
  llvm_cbe_tmp__1394 = llvm_cbe_tmp__1385;
  llvm_cbe_tmp__1395 = _ZSt12__niter_baseIPP11NExpressionET_S3_(llvm_cbe_tmp__1394);
  llvm_cbe_tmp__1396 = _ZSt13__copy_move_aILb0EPKP11NExpressionPS1_ET1_T0_S6_S5_(llvm_cbe_tmp__1390, llvm_cbe_tmp__1393, llvm_cbe_tmp__1395);
  return llvm_cbe_tmp__1396;
}


struct l_struct_class_OC_NExpression** _ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1397) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1398;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1399;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1400;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1401;

  *((&llvm_cbe_tmp__1399.field0)) = llvm_cbe_tmp__1397;
  llvm_cbe_tmp__1400 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1398))), (((uint8_t*)(&llvm_cbe_tmp__1399))), UINT64_C(8));
  llvm_cbe_tmp__1401 = *((&llvm_cbe_tmp__1398.field0));
  return llvm_cbe_tmp__1401;
}


struct l_struct_class_OC_NExpression** _ZSt13__copy_move_aILb0EPKP11NExpressionPS1_ET1_T0_S6_S5_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1402, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1403, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1404) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1405;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1406;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1407;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__1408;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1409;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1410;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1411;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1412;

  llvm_cbe_tmp__1405 = llvm_cbe_tmp__1402;
  llvm_cbe_tmp__1406 = llvm_cbe_tmp__1403;
  llvm_cbe_tmp__1407 = llvm_cbe_tmp__1404;
  llvm_cbe_tmp__1408 = 1;
  llvm_cbe_tmp__1409 = llvm_cbe_tmp__1405;
  llvm_cbe_tmp__1410 = llvm_cbe_tmp__1406;
  llvm_cbe_tmp__1411 = llvm_cbe_tmp__1407;
  llvm_cbe_tmp__1412 = _ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(llvm_cbe_tmp__1409, llvm_cbe_tmp__1410, llvm_cbe_tmp__1411);
  return llvm_cbe_tmp__1412;
}


struct l_struct_class_OC_NExpression** _ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1413) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13 llvm_cbe_tmp__1414;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__1415;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1416;

  *((&llvm_cbe_tmp__1414.field0)) = llvm_cbe_tmp__1413;
  llvm_cbe_tmp__1415 = _ZNK9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__1414));
  llvm_cbe_tmp__1416 = *llvm_cbe_tmp__1415;
  return llvm_cbe_tmp__1416;
}


struct l_struct_class_OC_NExpression** _ZSt12__niter_baseIPP11NExpressionET_S3_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1417) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1418;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1419;

  llvm_cbe_tmp__1418 = llvm_cbe_tmp__1417;
  llvm_cbe_tmp__1419 = llvm_cbe_tmp__1418;
  return llvm_cbe_tmp__1419;
}


struct l_struct_class_OC_NExpression** _ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1420, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1421, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1422) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1423;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1424;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1425;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1426;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1427;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1428;
  uint64_t llvm_cbe_tmp__1429;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1430;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1431;
  uint64_t llvm_cbe_tmp__1432;
  uint8_t* llvm_cbe_tmp__1433;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1434;
  uint64_t llvm_cbe_tmp__1435;

  llvm_cbe_tmp__1423 = llvm_cbe_tmp__1420;
  llvm_cbe_tmp__1424 = llvm_cbe_tmp__1421;
  llvm_cbe_tmp__1425 = llvm_cbe_tmp__1422;
  llvm_cbe_tmp__1427 = llvm_cbe_tmp__1424;
  llvm_cbe_tmp__1428 = llvm_cbe_tmp__1423;
  llvm_cbe_tmp__1426 = (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1427)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1428)))), UINT64_C(8)));
  llvm_cbe_tmp__1429 = llvm_cbe_tmp__1426;
  if ((((llvm_cbe_tmp__1429 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__1436;
  } else {
    goto llvm_cbe_tmp__1437;
  }

llvm_cbe_tmp__1436:
  llvm_cbe_tmp__1430 = llvm_cbe_tmp__1425;
  llvm_cbe_tmp__1431 = llvm_cbe_tmp__1423;
  llvm_cbe_tmp__1432 = llvm_cbe_tmp__1426;
  llvm_cbe_tmp__1433 = memmove((((uint8_t*)llvm_cbe_tmp__1430)), (((uint8_t*)llvm_cbe_tmp__1431)), (llvm_mul_u64(UINT64_C(8), llvm_cbe_tmp__1432)));
  goto llvm_cbe_tmp__1437;

llvm_cbe_tmp__1437:
  llvm_cbe_tmp__1434 = llvm_cbe_tmp__1425;
  llvm_cbe_tmp__1435 = llvm_cbe_tmp__1426;
  return ((&llvm_cbe_tmp__1434[((int64_t)llvm_cbe_tmp__1435)]));
}


struct l_struct_class_OC_NExpression*** _ZNK9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13* llvm_cbe_tmp__1438) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13* llvm_cbe_tmp__1439;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13* llvm_cbe_tmp__1440;

  llvm_cbe_tmp__1439 = llvm_cbe_tmp__1438;
  llvm_cbe_tmp__1440 = llvm_cbe_tmp__1439;
  return ((&llvm_cbe_tmp__1440->field0));
}


void _ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13* llvm_cbe_tmp__1441, struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__1442) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13* llvm_cbe_tmp__1443;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__1444;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_13* llvm_cbe_tmp__1445;
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__1446;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1447;

  llvm_cbe_tmp__1443 = llvm_cbe_tmp__1441;
  llvm_cbe_tmp__1444 = llvm_cbe_tmp__1442;
  llvm_cbe_tmp__1445 = llvm_cbe_tmp__1443;
  llvm_cbe_tmp__1446 = llvm_cbe_tmp__1444;
  llvm_cbe_tmp__1447 = *llvm_cbe_tmp__1446;
  *((&llvm_cbe_tmp__1445->field0)) = llvm_cbe_tmp__1447;
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1448, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1449, uint64_t llvm_cbe_tmp__1450) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1451;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1452;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1453;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1454;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1455;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1456;
  uint64_t llvm_cbe_tmp__1457;

  llvm_cbe_tmp__1451 = llvm_cbe_tmp__1448;
  llvm_cbe_tmp__1452 = llvm_cbe_tmp__1449;
  llvm_cbe_tmp__1453 = llvm_cbe_tmp__1450;
  llvm_cbe_tmp__1454 = llvm_cbe_tmp__1451;
  llvm_cbe_tmp__1455 = llvm_cbe_tmp__1452;
  if ((((llvm_cbe_tmp__1455 != ((struct l_struct_class_OC_NExpression**)/*NULL*/0))&1))) {
    goto llvm_cbe_tmp__1458;
  } else {
    goto llvm_cbe_tmp__1459;
  }

llvm_cbe_tmp__1458:
  llvm_cbe_tmp__1456 = llvm_cbe_tmp__1452;
  llvm_cbe_tmp__1457 = llvm_cbe_tmp__1453;
  _ZNSt16allocator_traitsISaIP11NExpressionEE10deallocateERS2_PS1_m((((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)((&llvm_cbe_tmp__1454->field0)))), llvm_cbe_tmp__1456, llvm_cbe_tmp__1457);
  goto llvm_cbe_tmp__1459;

llvm_cbe_tmp__1459:
  return;
}


void _ZNSt16allocator_traitsISaIP11NExpressionEE10deallocateERS2_PS1_m(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1460, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1461, uint64_t llvm_cbe_tmp__1462) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1463;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1464;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1465;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1466;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1467;
  uint64_t llvm_cbe_tmp__1468;

  llvm_cbe_tmp__1463 = llvm_cbe_tmp__1460;
  llvm_cbe_tmp__1464 = llvm_cbe_tmp__1461;
  llvm_cbe_tmp__1465 = llvm_cbe_tmp__1462;
  llvm_cbe_tmp__1466 = llvm_cbe_tmp__1463;
  llvm_cbe_tmp__1467 = llvm_cbe_tmp__1464;
  llvm_cbe_tmp__1468 = llvm_cbe_tmp__1465;
  _ZN9__gnu_cxx13new_allocatorIP11NExpressionE10deallocateEPS2_m((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__1466)), llvm_cbe_tmp__1467, llvm_cbe_tmp__1468);
}


void _ZN9__gnu_cxx13new_allocatorIP11NExpressionE10deallocateEPS2_m(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1469, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1470, uint64_t llvm_cbe_tmp__1471) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1472;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1473;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1474;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1475;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1476;

  llvm_cbe_tmp__1472 = llvm_cbe_tmp__1469;
  llvm_cbe_tmp__1473 = llvm_cbe_tmp__1470;
  llvm_cbe_tmp__1474 = llvm_cbe_tmp__1471;
  llvm_cbe_tmp__1475 = llvm_cbe_tmp__1472;
  llvm_cbe_tmp__1476 = llvm_cbe_tmp__1473;
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__1476)));
}


void _ZN15NBinaryOperatorD2Ev(struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1477) {
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1478;    /* Address-exposed local */
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1479;

  llvm_cbe_tmp__1478 = llvm_cbe_tmp__1477;
  llvm_cbe_tmp__1479 = llvm_cbe_tmp__1478;
  _ZN11NExpressionD2Ev((((struct l_struct_class_OC_NExpression*)llvm_cbe_tmp__1479)));
}


void _ZN15NBinaryOperatorD0Ev(struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1480) {
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1481;    /* Address-exposed local */
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1482;

  llvm_cbe_tmp__1481 = llvm_cbe_tmp__1480;
  llvm_cbe_tmp__1482 = llvm_cbe_tmp__1481;
  _ZN15NBinaryOperatorD2Ev(llvm_cbe_tmp__1482);
  _ZdlPv((((uint8_t*)llvm_cbe_tmp__1482)));
}


struct l_struct_class_OC_llvm_KD__KD_Value* _ZN15NBinaryOperator7codeGenER14CodeGenContext(struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1483, void* llvm_cbe_tmp__1484) {
  struct l_struct_class_OC_llvm_KD__KD_Value* llvm_cbe_tmp__1485;    /* Address-exposed local */
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1486;    /* Address-exposed local */
  void* llvm_cbe_tmp__1487;    /* Address-exposed local */
  struct l_struct_class_OC_NBinaryOperator* llvm_cbe_tmp__1488;

  llvm_cbe_tmp__1486 = llvm_cbe_tmp__1483;
  llvm_cbe_tmp__1487 = llvm_cbe_tmp__1484;
  llvm_cbe_tmp__1488 = llvm_cbe_tmp__1486;
  llvm_OC_trap();
  __builtin_unreachable();

}


void _ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1489, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1490, struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1491) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1492;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1493;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1494;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1495;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1496;

  llvm_cbe_tmp__1492 = llvm_cbe_tmp__1489;
  llvm_cbe_tmp__1493 = llvm_cbe_tmp__1490;
  llvm_cbe_tmp__1494 = llvm_cbe_tmp__1491;
  llvm_cbe_tmp__1495 = llvm_cbe_tmp__1492;
  llvm_cbe_tmp__1496 = llvm_cbe_tmp__1493;
  _ZSt8_DestroyIPP11NExpressionEvT_S3_(llvm_cbe_tmp__1495, llvm_cbe_tmp__1496);
}


void _ZSt8_DestroyIPP11NExpressionEvT_S3_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1497, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1498) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1499;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1500;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1501;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1502;

  llvm_cbe_tmp__1499 = llvm_cbe_tmp__1497;
  llvm_cbe_tmp__1500 = llvm_cbe_tmp__1498;
  llvm_cbe_tmp__1501 = llvm_cbe_tmp__1499;
  llvm_cbe_tmp__1502 = llvm_cbe_tmp__1500;
  _ZNSt12_Destroy_auxILb1EE9__destroyIPP11NExpressionEEvT_S5_(llvm_cbe_tmp__1501, llvm_cbe_tmp__1502);
}


void _ZNSt12_Destroy_auxILb1EE9__destroyIPP11NExpressionEEvT_S5_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1503, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1504) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1505;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__1506;    /* Address-exposed local */

  llvm_cbe_tmp__1505 = llvm_cbe_tmp__1503;
  llvm_cbe_tmp__1506 = llvm_cbe_tmp__1504;
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1507) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1508;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9* llvm_cbe_tmp__1509;

  llvm_cbe_tmp__1508 = llvm_cbe_tmp__1507;
  llvm_cbe_tmp__1509 = llvm_cbe_tmp__1508;
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2Ev(((&llvm_cbe_tmp__1509->field0)));
}


void _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1510) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1511;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NExpression_AC__KC__MC__AC_std_KD__KD_allocator_MD_NExpression_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1512;

  llvm_cbe_tmp__1511 = llvm_cbe_tmp__1510;
  llvm_cbe_tmp__1512 = llvm_cbe_tmp__1511;
  _ZNSaIP11NExpressionEC2Ev((((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)llvm_cbe_tmp__1512)));
  *((&llvm_cbe_tmp__1512->field0)) = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);
  *((&llvm_cbe_tmp__1512->field1)) = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);
  *((&llvm_cbe_tmp__1512->field2)) = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);
}


void _ZNSaIP11NExpressionEC2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1513) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1514;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__1515;

  llvm_cbe_tmp__1514 = llvm_cbe_tmp__1513;
  llvm_cbe_tmp__1515 = llvm_cbe_tmp__1514;
  _ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2Ev((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__1515)));
}


void _ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1516) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1517;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__1518;

  llvm_cbe_tmp__1517 = llvm_cbe_tmp__1516;
  llvm_cbe_tmp__1518 = llvm_cbe_tmp__1517;
}


void _ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1519, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1520, struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1521) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1522;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1523;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1524;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1525;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1526;

  llvm_cbe_tmp__1522 = llvm_cbe_tmp__1519;
  llvm_cbe_tmp__1523 = llvm_cbe_tmp__1520;
  llvm_cbe_tmp__1524 = llvm_cbe_tmp__1521;
  llvm_cbe_tmp__1525 = llvm_cbe_tmp__1522;
  llvm_cbe_tmp__1526 = llvm_cbe_tmp__1523;
  _ZSt8_DestroyIPP20NVariableDeclarationEvT_S3_(llvm_cbe_tmp__1525, llvm_cbe_tmp__1526);
}


void _ZSt8_DestroyIPP20NVariableDeclarationEvT_S3_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1527, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1528) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1529;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1530;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1531;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1532;

  llvm_cbe_tmp__1529 = llvm_cbe_tmp__1527;
  llvm_cbe_tmp__1530 = llvm_cbe_tmp__1528;
  llvm_cbe_tmp__1531 = llvm_cbe_tmp__1529;
  llvm_cbe_tmp__1532 = llvm_cbe_tmp__1530;
  _ZNSt12_Destroy_auxILb1EE9__destroyIPP20NVariableDeclarationEEvT_S5_(llvm_cbe_tmp__1531, llvm_cbe_tmp__1532);
}


void _ZNSt12_Destroy_auxILb1EE9__destroyIPP20NVariableDeclarationEEvT_S5_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1533, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1534) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1535;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1536;    /* Address-exposed local */

  llvm_cbe_tmp__1535 = llvm_cbe_tmp__1533;
  llvm_cbe_tmp__1536 = llvm_cbe_tmp__1534;
}


void _ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1537, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1538, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1539) {
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1540;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1541;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1542;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1543;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1544;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1545;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1546;

  llvm_cbe_tmp__1540 = llvm_cbe_tmp__1537;
  llvm_cbe_tmp__1541 = llvm_cbe_tmp__1538;
  llvm_cbe_tmp__1542 = llvm_cbe_tmp__1539;
  llvm_cbe_tmp__1543 = llvm_cbe_tmp__1540;
  llvm_cbe_tmp__1544 = llvm_cbe_tmp__1541;
  llvm_cbe_tmp__1545 = llvm_cbe_tmp__1542;
  llvm_cbe_tmp__1546 = _ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__1545);
  _ZN9__gnu_cxx13new_allocatorIP10NStatementE9constructIS2_JRKS2_EEEvPT_DpOT0_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*)llvm_cbe_tmp__1543)), llvm_cbe_tmp__1544, llvm_cbe_tmp__1546);
}


void _ZNSt6vectorIP10NStatementSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1547, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1548, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1549) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14 llvm_cbe_tmp__1550;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1551;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1552;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1553;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1554;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1555;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1556;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14 llvm_cbe_tmp__1557;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1558;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1559;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1560;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1561;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1562;
  uint64_t llvm_cbe_tmp__1563;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1564;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1565;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1566;
  uint64_t llvm_cbe_tmp__1567;
  uint64_t llvm_cbe_tmp__1568;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1569;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1570;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1571;
  uint64_t llvm_cbe_tmp__1572;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1573;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1574;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1575;
  struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__1576;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1577;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1578;
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1579;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1580;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1581;
  struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__1582;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1583;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1584;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1585;
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1586;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1587;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1588;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1589;
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1590;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1591;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1592;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1593;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1594;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1595;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1596;
  uint64_t llvm_cbe_tmp__1597;

  *((&llvm_cbe_tmp__1550.field0)) = llvm_cbe_tmp__1548;
  llvm_cbe_tmp__1551 = llvm_cbe_tmp__1547;
  llvm_cbe_tmp__1552 = llvm_cbe_tmp__1549;
  llvm_cbe_tmp__1562 = llvm_cbe_tmp__1551;
  llvm_cbe_tmp__1563 = _ZNKSt6vectorIP10NStatementSaIS1_EE12_M_check_lenEmPKc(llvm_cbe_tmp__1562, UINT64_C(1), ((&_OC_str_OC_8.array[((int32_t)0)])));
  llvm_cbe_tmp__1553 = llvm_cbe_tmp__1563;
  llvm_cbe_tmp__1564 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562))->field0))->field0));
  llvm_cbe_tmp__1554 = llvm_cbe_tmp__1564;
  llvm_cbe_tmp__1565 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562))->field0))->field1));
  llvm_cbe_tmp__1555 = llvm_cbe_tmp__1565;
  llvm_cbe_tmp__1566 = _ZNSt6vectorIP10NStatementSaIS1_EE5beginEv(llvm_cbe_tmp__1562);
  *((&llvm_cbe_tmp__1557.field0)) = llvm_cbe_tmp__1566;
  llvm_cbe_tmp__1567 = _ZN9__gnu_cxxmiIPP10NStatementSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_((&llvm_cbe_tmp__1550), (&llvm_cbe_tmp__1557));
  llvm_cbe_tmp__1556 = llvm_cbe_tmp__1567;
  llvm_cbe_tmp__1568 = llvm_cbe_tmp__1553;
  llvm_cbe_tmp__1569 = _ZNSt12_Vector_baseIP10NStatementSaIS1_EE11_M_allocateEm((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562)), llvm_cbe_tmp__1568);
  llvm_cbe_tmp__1558 = llvm_cbe_tmp__1569;
  llvm_cbe_tmp__1570 = llvm_cbe_tmp__1558;
  llvm_cbe_tmp__1559 = llvm_cbe_tmp__1570;
  llvm_cbe_tmp__1571 = llvm_cbe_tmp__1558;
  llvm_cbe_tmp__1572 = llvm_cbe_tmp__1556;
  llvm_cbe_tmp__1573 = llvm_cbe_tmp__1552;
  llvm_cbe_tmp__1574 = _ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__1573);
  _ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_((((struct l_struct_class_OC_std_KD__KD_allocator*)((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562))->field0)))), ((&llvm_cbe_tmp__1571[((int64_t)llvm_cbe_tmp__1572)])), llvm_cbe_tmp__1574);
  goto llvm_cbe_tmp__1598;

llvm_cbe_tmp__1598:
  llvm_cbe_tmp__1559 = ((struct l_struct_class_OC_NStatement**)/*NULL*/0);
  llvm_cbe_tmp__1575 = llvm_cbe_tmp__1554;
  llvm_cbe_tmp__1576 = _ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__1550));
  llvm_cbe_tmp__1577 = *llvm_cbe_tmp__1576;
  llvm_cbe_tmp__1578 = llvm_cbe_tmp__1558;
  llvm_cbe_tmp__1579 = _ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562)));
  llvm_cbe_tmp__1580 = _ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_(llvm_cbe_tmp__1575, llvm_cbe_tmp__1577, llvm_cbe_tmp__1578, llvm_cbe_tmp__1579);
  goto llvm_cbe_tmp__1599;

llvm_cbe_tmp__1599:
  llvm_cbe_tmp__1559 = llvm_cbe_tmp__1580;
  llvm_cbe_tmp__1581 = llvm_cbe_tmp__1559;
  llvm_cbe_tmp__1559 = ((&llvm_cbe_tmp__1581[((int32_t)1)]));
  llvm_cbe_tmp__1582 = _ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__1550));
  llvm_cbe_tmp__1583 = *llvm_cbe_tmp__1582;
  llvm_cbe_tmp__1584 = llvm_cbe_tmp__1555;
  llvm_cbe_tmp__1585 = llvm_cbe_tmp__1559;
  llvm_cbe_tmp__1586 = _ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562)));
  llvm_cbe_tmp__1587 = _ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_(llvm_cbe_tmp__1583, llvm_cbe_tmp__1584, llvm_cbe_tmp__1585, llvm_cbe_tmp__1586);
  goto llvm_cbe_tmp__1600;

llvm_cbe_tmp__1600:
  llvm_cbe_tmp__1559 = llvm_cbe_tmp__1587;
  goto llvm_cbe_tmp__1601;

llvm_cbe_tmp__1601:
  llvm_cbe_tmp__1588 = llvm_cbe_tmp__1554;
  llvm_cbe_tmp__1589 = llvm_cbe_tmp__1555;
  llvm_cbe_tmp__1590 = _ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562)));
  _ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(llvm_cbe_tmp__1588, llvm_cbe_tmp__1589, llvm_cbe_tmp__1590);
  llvm_cbe_tmp__1591 = llvm_cbe_tmp__1554;
  llvm_cbe_tmp__1592 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562))->field0))->field2));
  llvm_cbe_tmp__1593 = llvm_cbe_tmp__1554;
  _ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562)), llvm_cbe_tmp__1591, (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1592)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1593)))), UINT64_C(8))));
  llvm_cbe_tmp__1594 = llvm_cbe_tmp__1558;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562))->field0))->field0)) = llvm_cbe_tmp__1594;
  llvm_cbe_tmp__1595 = llvm_cbe_tmp__1559;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562))->field0))->field1)) = llvm_cbe_tmp__1595;
  llvm_cbe_tmp__1596 = llvm_cbe_tmp__1558;
  llvm_cbe_tmp__1597 = llvm_cbe_tmp__1553;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1562))->field0))->field2)) = ((&llvm_cbe_tmp__1596[((int64_t)llvm_cbe_tmp__1597)]));
}


struct l_struct_class_OC_NStatement** _ZNSt6vectorIP10NStatementSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1602) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14 llvm_cbe_tmp__1603;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1604;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1605;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1606;

  llvm_cbe_tmp__1604 = llvm_cbe_tmp__1602;
  llvm_cbe_tmp__1605 = llvm_cbe_tmp__1604;
  _ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_((&llvm_cbe_tmp__1603), ((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1605))->field0))->field1)));
  llvm_cbe_tmp__1606 = *((&llvm_cbe_tmp__1603.field0));
  return llvm_cbe_tmp__1606;
}


void _ZN9__gnu_cxx13new_allocatorIP10NStatementE9constructIS2_JRKS2_EEEvPT_DpOT0_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1607, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1608, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1609) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1610;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1611;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1612;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1613;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1614;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1615;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1616;
  struct l_struct_class_OC_NStatement* llvm_cbe_tmp__1617;

  llvm_cbe_tmp__1610 = llvm_cbe_tmp__1607;
  llvm_cbe_tmp__1611 = llvm_cbe_tmp__1608;
  llvm_cbe_tmp__1612 = llvm_cbe_tmp__1609;
  llvm_cbe_tmp__1613 = llvm_cbe_tmp__1610;
  llvm_cbe_tmp__1614 = llvm_cbe_tmp__1611;
  llvm_cbe_tmp__1615 = llvm_cbe_tmp__1612;
  llvm_cbe_tmp__1616 = _ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__1615);
  llvm_cbe_tmp__1617 = *llvm_cbe_tmp__1616;
  *(((struct l_struct_class_OC_NStatement**)(((uint8_t*)llvm_cbe_tmp__1614)))) = llvm_cbe_tmp__1617;
}


struct l_struct_class_OC_NStatement** _ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1618) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1619;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1620;

  llvm_cbe_tmp__1619 = llvm_cbe_tmp__1618;
  llvm_cbe_tmp__1620 = llvm_cbe_tmp__1619;
  return llvm_cbe_tmp__1620;
}


uint64_t _ZNKSt6vectorIP10NStatementSaIS1_EE12_M_check_lenEmPKc(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1621, uint64_t llvm_cbe_tmp__1622, uint8_t* llvm_cbe_tmp__1623) {
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1624;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1625;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1626;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1627;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1628;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1629;
  uint64_t llvm_cbe_tmp__1630;
  uint64_t llvm_cbe_tmp__1631;
  uint64_t llvm_cbe_tmp__1632;
  uint8_t* llvm_cbe_tmp__1633;
  uint64_t llvm_cbe_tmp__1634;
  uint64_t llvm_cbe_tmp__1635;
  uint64_t* llvm_cbe_tmp__1636;
  uint64_t llvm_cbe_tmp__1637;
  uint64_t llvm_cbe_tmp__1638;
  uint64_t llvm_cbe_tmp__1639;
  uint64_t llvm_cbe_tmp__1640;
  uint64_t llvm_cbe_tmp__1641;
  uint64_t llvm_cbe_tmp__1642;
  uint64_t llvm_cbe_tmp__1643;
  uint64_t llvm_cbe_tmp__1644;
  uint64_t llvm_cbe_tmp__1644__PHI_TEMPORARY;

  llvm_cbe_tmp__1624 = llvm_cbe_tmp__1621;
  llvm_cbe_tmp__1625 = llvm_cbe_tmp__1622;
  llvm_cbe_tmp__1626 = llvm_cbe_tmp__1623;
  llvm_cbe_tmp__1629 = llvm_cbe_tmp__1624;
  llvm_cbe_tmp__1630 = _ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(llvm_cbe_tmp__1629);
  llvm_cbe_tmp__1631 = _ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(llvm_cbe_tmp__1629);
  llvm_cbe_tmp__1632 = llvm_cbe_tmp__1625;
  if ((((((uint64_t)(llvm_sub_u64(llvm_cbe_tmp__1630, llvm_cbe_tmp__1631))) < ((uint64_t)llvm_cbe_tmp__1632))&1))) {
    goto llvm_cbe_tmp__1645;
  } else {
    goto llvm_cbe_tmp__1646;
  }

llvm_cbe_tmp__1645:
  llvm_cbe_tmp__1633 = llvm_cbe_tmp__1626;
  _ZSt20__throw_length_errorPKc(llvm_cbe_tmp__1633);
  __builtin_unreachable();

llvm_cbe_tmp__1646:
  llvm_cbe_tmp__1634 = _ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(llvm_cbe_tmp__1629);
  llvm_cbe_tmp__1635 = _ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(llvm_cbe_tmp__1629);
  llvm_cbe_tmp__1628 = llvm_cbe_tmp__1635;
  llvm_cbe_tmp__1636 = _ZSt3maxImERKT_S2_S2_((&llvm_cbe_tmp__1628), (&llvm_cbe_tmp__1625));
  llvm_cbe_tmp__1637 = *llvm_cbe_tmp__1636;
  llvm_cbe_tmp__1627 = (llvm_add_u64(llvm_cbe_tmp__1634, llvm_cbe_tmp__1637));
  llvm_cbe_tmp__1638 = llvm_cbe_tmp__1627;
  llvm_cbe_tmp__1639 = _ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(llvm_cbe_tmp__1629);
  if ((((((uint64_t)llvm_cbe_tmp__1638) < ((uint64_t)llvm_cbe_tmp__1639))&1))) {
    goto llvm_cbe_tmp__1647;
  } else {
    goto llvm_cbe_tmp__1648;
  }

llvm_cbe_tmp__1648:
  llvm_cbe_tmp__1640 = llvm_cbe_tmp__1627;
  llvm_cbe_tmp__1641 = _ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(llvm_cbe_tmp__1629);
  if ((((((uint64_t)llvm_cbe_tmp__1640) > ((uint64_t)llvm_cbe_tmp__1641))&1))) {
    goto llvm_cbe_tmp__1647;
  } else {
    goto llvm_cbe_tmp__1649;
  }

llvm_cbe_tmp__1647:
  llvm_cbe_tmp__1642 = _ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(llvm_cbe_tmp__1629);
  llvm_cbe_tmp__1644__PHI_TEMPORARY = llvm_cbe_tmp__1642;   /* for PHI node */
  goto llvm_cbe_tmp__1650;

llvm_cbe_tmp__1649:
  llvm_cbe_tmp__1643 = llvm_cbe_tmp__1627;
  llvm_cbe_tmp__1644__PHI_TEMPORARY = llvm_cbe_tmp__1643;   /* for PHI node */
  goto llvm_cbe_tmp__1650;

llvm_cbe_tmp__1650:
  llvm_cbe_tmp__1644 = llvm_cbe_tmp__1644__PHI_TEMPORARY;
  return llvm_cbe_tmp__1644;
}


uint64_t _ZN9__gnu_cxxmiIPP10NStatementSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1651, struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1652) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1653;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1654;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1655;
  struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__1656;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1657;
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1658;
  struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__1659;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1660;

  llvm_cbe_tmp__1653 = llvm_cbe_tmp__1651;
  llvm_cbe_tmp__1654 = llvm_cbe_tmp__1652;
  llvm_cbe_tmp__1655 = llvm_cbe_tmp__1653;
  llvm_cbe_tmp__1656 = _ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(llvm_cbe_tmp__1655);
  llvm_cbe_tmp__1657 = *llvm_cbe_tmp__1656;
  llvm_cbe_tmp__1658 = llvm_cbe_tmp__1654;
  llvm_cbe_tmp__1659 = _ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(llvm_cbe_tmp__1658);
  llvm_cbe_tmp__1660 = *llvm_cbe_tmp__1659;
  return (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1657)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1660)))), UINT64_C(8)));
}


struct l_struct_class_OC_NStatement** _ZNSt6vectorIP10NStatementSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1661) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14 llvm_cbe_tmp__1662;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1663;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1664;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1665;

  llvm_cbe_tmp__1663 = llvm_cbe_tmp__1661;
  llvm_cbe_tmp__1664 = llvm_cbe_tmp__1663;
  _ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_((&llvm_cbe_tmp__1662), ((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1664))->field0))->field0)));
  llvm_cbe_tmp__1665 = *((&llvm_cbe_tmp__1662.field0));
  return llvm_cbe_tmp__1665;
}


struct l_struct_class_OC_NStatement** _ZNSt12_Vector_baseIP10NStatementSaIS1_EE11_M_allocateEm(struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__1666, uint64_t llvm_cbe_tmp__1667) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__1668;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1669;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__1670;
  uint64_t llvm_cbe_tmp__1671;
  uint64_t llvm_cbe_tmp__1672;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1673;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1674;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1674__PHI_TEMPORARY;

  llvm_cbe_tmp__1668 = llvm_cbe_tmp__1666;
  llvm_cbe_tmp__1669 = llvm_cbe_tmp__1667;
  llvm_cbe_tmp__1670 = llvm_cbe_tmp__1668;
  llvm_cbe_tmp__1671 = llvm_cbe_tmp__1669;
  if ((((llvm_cbe_tmp__1671 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__1675;
  } else {
    goto llvm_cbe_tmp__1676;
  }

llvm_cbe_tmp__1675:
  llvm_cbe_tmp__1672 = llvm_cbe_tmp__1669;
  llvm_cbe_tmp__1673 = _ZNSt16allocator_traitsISaIP10NStatementEE8allocateERS2_m((((struct l_struct_class_OC_std_KD__KD_allocator*)((&llvm_cbe_tmp__1670->field0)))), llvm_cbe_tmp__1672);
  llvm_cbe_tmp__1674__PHI_TEMPORARY = llvm_cbe_tmp__1673;   /* for PHI node */
  goto llvm_cbe_tmp__1677;

llvm_cbe_tmp__1676:
  llvm_cbe_tmp__1674__PHI_TEMPORARY = ((struct l_struct_class_OC_NStatement**)/*NULL*/0);   /* for PHI node */
  goto llvm_cbe_tmp__1677;

llvm_cbe_tmp__1677:
  llvm_cbe_tmp__1674 = llvm_cbe_tmp__1674__PHI_TEMPORARY;
  return llvm_cbe_tmp__1674;
}


struct l_struct_class_OC_NStatement** _ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1678, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1679, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1680, struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1681) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1682;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1683;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1684;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1685;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1686;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1687;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1688;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1689;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1690;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1691;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1692;
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1693;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1694;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1695;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1696;

  llvm_cbe_tmp__1682 = llvm_cbe_tmp__1678;
  llvm_cbe_tmp__1683 = llvm_cbe_tmp__1679;
  llvm_cbe_tmp__1684 = llvm_cbe_tmp__1680;
  llvm_cbe_tmp__1685 = llvm_cbe_tmp__1681;
  llvm_cbe_tmp__1688 = llvm_cbe_tmp__1682;
  llvm_cbe_tmp__1689 = _ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_(llvm_cbe_tmp__1688);
  *((&llvm_cbe_tmp__1686.field0)) = llvm_cbe_tmp__1689;
  llvm_cbe_tmp__1690 = llvm_cbe_tmp__1683;
  llvm_cbe_tmp__1691 = _ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_(llvm_cbe_tmp__1690);
  *((&llvm_cbe_tmp__1687.field0)) = llvm_cbe_tmp__1691;
  llvm_cbe_tmp__1692 = llvm_cbe_tmp__1684;
  llvm_cbe_tmp__1693 = llvm_cbe_tmp__1685;
  llvm_cbe_tmp__1694 = *((&llvm_cbe_tmp__1686.field0));
  llvm_cbe_tmp__1695 = *((&llvm_cbe_tmp__1687.field0));
  llvm_cbe_tmp__1696 = _ZSt22__uninitialized_copy_aISt13move_iteratorIPP10NStatementES3_S2_ET0_T_S6_S5_RSaIT1_E(llvm_cbe_tmp__1694, llvm_cbe_tmp__1695, llvm_cbe_tmp__1692, llvm_cbe_tmp__1693);
  return llvm_cbe_tmp__1696;
}


struct l_struct_class_OC_NStatement*** _ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1697) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1698;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1699;

  llvm_cbe_tmp__1698 = llvm_cbe_tmp__1697;
  llvm_cbe_tmp__1699 = llvm_cbe_tmp__1698;
  return ((&llvm_cbe_tmp__1699->field0));
}


void _ZNSt16allocator_traitsISaIP10NStatementEE7destroyIS1_EEvRS2_PT_(struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1700, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1701) {
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1702;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1703;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1704;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1705;

  llvm_cbe_tmp__1702 = llvm_cbe_tmp__1700;
  llvm_cbe_tmp__1703 = llvm_cbe_tmp__1701;
  llvm_cbe_tmp__1704 = llvm_cbe_tmp__1702;
  llvm_cbe_tmp__1705 = llvm_cbe_tmp__1703;
  _ZN9__gnu_cxx13new_allocatorIP10NStatementE7destroyIS2_EEvPT_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*)llvm_cbe_tmp__1704)), llvm_cbe_tmp__1705);
}


uint64_t _ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1706) {
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1707;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1708;
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1709;
  uint64_t llvm_cbe_tmp__1710;

  llvm_cbe_tmp__1707 = llvm_cbe_tmp__1706;
  llvm_cbe_tmp__1708 = llvm_cbe_tmp__1707;
  llvm_cbe_tmp__1709 = _ZNKSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1708)));
  llvm_cbe_tmp__1710 = _ZNSt16allocator_traitsISaIP10NStatementEE8max_sizeERKS2_(llvm_cbe_tmp__1709);
  return llvm_cbe_tmp__1710;
}


uint64_t _ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1711) {
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1712;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector* llvm_cbe_tmp__1713;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1714;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1715;

  llvm_cbe_tmp__1712 = llvm_cbe_tmp__1711;
  llvm_cbe_tmp__1713 = llvm_cbe_tmp__1712;
  llvm_cbe_tmp__1714 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1713))->field0))->field1));
  llvm_cbe_tmp__1715 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base*)llvm_cbe_tmp__1713))->field0))->field0));
  return (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1714)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1715)))), UINT64_C(8)));
}


uint64_t* _ZSt3maxImERKT_S2_S2_(uint64_t* llvm_cbe_tmp__1716, uint64_t* llvm_cbe_tmp__1717) {
  uint64_t* llvm_cbe_tmp__1718;    /* Address-exposed local */
  uint64_t* llvm_cbe_tmp__1719;    /* Address-exposed local */
  uint64_t* llvm_cbe_tmp__1720;    /* Address-exposed local */
  uint64_t* llvm_cbe_tmp__1721;
  uint64_t llvm_cbe_tmp__1722;
  uint64_t* llvm_cbe_tmp__1723;
  uint64_t llvm_cbe_tmp__1724;
  uint64_t* llvm_cbe_tmp__1725;
  uint64_t* llvm_cbe_tmp__1726;
  uint64_t* llvm_cbe_tmp__1727;

  llvm_cbe_tmp__1719 = llvm_cbe_tmp__1716;
  llvm_cbe_tmp__1720 = llvm_cbe_tmp__1717;
  llvm_cbe_tmp__1721 = llvm_cbe_tmp__1719;
  llvm_cbe_tmp__1722 = *llvm_cbe_tmp__1721;
  llvm_cbe_tmp__1723 = llvm_cbe_tmp__1720;
  llvm_cbe_tmp__1724 = *llvm_cbe_tmp__1723;
  if ((((((uint64_t)llvm_cbe_tmp__1722) < ((uint64_t)llvm_cbe_tmp__1724))&1))) {
    goto llvm_cbe_tmp__1728;
  } else {
    goto llvm_cbe_tmp__1729;
  }

llvm_cbe_tmp__1728:
  llvm_cbe_tmp__1725 = llvm_cbe_tmp__1720;
  llvm_cbe_tmp__1718 = llvm_cbe_tmp__1725;
  goto llvm_cbe_tmp__1730;

llvm_cbe_tmp__1729:
  llvm_cbe_tmp__1726 = llvm_cbe_tmp__1719;
  llvm_cbe_tmp__1718 = llvm_cbe_tmp__1726;
  goto llvm_cbe_tmp__1730;

llvm_cbe_tmp__1730:
  llvm_cbe_tmp__1727 = llvm_cbe_tmp__1718;
  return llvm_cbe_tmp__1727;
}


uint64_t _ZNSt16allocator_traitsISaIP10NStatementEE8max_sizeERKS2_(struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1731) {
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1732;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1733;
  uint64_t llvm_cbe_tmp__1734;

  llvm_cbe_tmp__1732 = llvm_cbe_tmp__1731;
  llvm_cbe_tmp__1733 = llvm_cbe_tmp__1732;
  llvm_cbe_tmp__1734 = _ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*)llvm_cbe_tmp__1733)));
  return llvm_cbe_tmp__1734;
}


struct l_struct_class_OC_std_KD__KD_allocator* _ZNKSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__1735) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__1736;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base* llvm_cbe_tmp__1737;

  llvm_cbe_tmp__1736 = llvm_cbe_tmp__1735;
  llvm_cbe_tmp__1737 = llvm_cbe_tmp__1736;
  return (((struct l_struct_class_OC_std_KD__KD_allocator*)((&llvm_cbe_tmp__1737->field0))));
}


uint64_t _ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1738) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1739;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1740;

  llvm_cbe_tmp__1739 = llvm_cbe_tmp__1738;
  llvm_cbe_tmp__1740 = llvm_cbe_tmp__1739;
  return UINT64_C(2305843009213693951);
}


void _ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1741, struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__1742) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1743;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__1744;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_14* llvm_cbe_tmp__1745;
  struct l_struct_class_OC_NStatement*** llvm_cbe_tmp__1746;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1747;

  llvm_cbe_tmp__1743 = llvm_cbe_tmp__1741;
  llvm_cbe_tmp__1744 = llvm_cbe_tmp__1742;
  llvm_cbe_tmp__1745 = llvm_cbe_tmp__1743;
  llvm_cbe_tmp__1746 = llvm_cbe_tmp__1744;
  llvm_cbe_tmp__1747 = *llvm_cbe_tmp__1746;
  *((&llvm_cbe_tmp__1745->field0)) = llvm_cbe_tmp__1747;
}


struct l_struct_class_OC_NStatement** _ZNSt16allocator_traitsISaIP10NStatementEE8allocateERS2_m(struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1748, uint64_t llvm_cbe_tmp__1749) {
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1750;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1751;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1752;
  uint64_t llvm_cbe_tmp__1753;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1754;

  llvm_cbe_tmp__1750 = llvm_cbe_tmp__1748;
  llvm_cbe_tmp__1751 = llvm_cbe_tmp__1749;
  llvm_cbe_tmp__1752 = llvm_cbe_tmp__1750;
  llvm_cbe_tmp__1753 = llvm_cbe_tmp__1751;
  llvm_cbe_tmp__1754 = _ZN9__gnu_cxx13new_allocatorIP10NStatementE8allocateEmPKv((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator*)llvm_cbe_tmp__1752)), llvm_cbe_tmp__1753, ((uint8_t*)/*NULL*/0));
  return llvm_cbe_tmp__1754;
}


struct l_struct_class_OC_NStatement** _ZN9__gnu_cxx13new_allocatorIP10NStatementE8allocateEmPKv(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1755, uint64_t llvm_cbe_tmp__1756, uint8_t* llvm_cbe_tmp__1757) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1758;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1759;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1760;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1761;
  uint64_t llvm_cbe_tmp__1762;
  uint64_t llvm_cbe_tmp__1763;
  uint64_t llvm_cbe_tmp__1764;
  uint8_t* llvm_cbe_tmp__1765;

  llvm_cbe_tmp__1758 = llvm_cbe_tmp__1755;
  llvm_cbe_tmp__1759 = llvm_cbe_tmp__1756;
  llvm_cbe_tmp__1760 = llvm_cbe_tmp__1757;
  llvm_cbe_tmp__1761 = llvm_cbe_tmp__1758;
  llvm_cbe_tmp__1762 = llvm_cbe_tmp__1759;
  llvm_cbe_tmp__1763 = _ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv(llvm_cbe_tmp__1761);
  if ((((((uint64_t)llvm_cbe_tmp__1762) > ((uint64_t)llvm_cbe_tmp__1763))&1))) {
    goto llvm_cbe_tmp__1766;
  } else {
    goto llvm_cbe_tmp__1767;
  }

llvm_cbe_tmp__1766:
  _ZSt17__throw_bad_allocv();
  __builtin_unreachable();

llvm_cbe_tmp__1767:
  llvm_cbe_tmp__1764 = llvm_cbe_tmp__1759;
  llvm_cbe_tmp__1765 = _Znwm((llvm_mul_u64(llvm_cbe_tmp__1764, UINT64_C(8))));
  return (((struct l_struct_class_OC_NStatement**)llvm_cbe_tmp__1765));
}


struct l_struct_class_OC_NStatement** _ZSt22__uninitialized_copy_aISt13move_iteratorIPP10NStatementES3_S2_ET0_T_S6_S5_RSaIT1_E(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1768, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1769, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1770, struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1771) {
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1772;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1773;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1774;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator* llvm_cbe_tmp__1775;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1776;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1777;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1778;
  uint8_t* llvm_cbe_tmp__1779;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1780;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1781;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1782;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1783;

  *((&llvm_cbe_tmp__1772.field0)) = llvm_cbe_tmp__1768;
  *((&llvm_cbe_tmp__1773.field0)) = llvm_cbe_tmp__1769;
  llvm_cbe_tmp__1774 = llvm_cbe_tmp__1770;
  llvm_cbe_tmp__1775 = llvm_cbe_tmp__1771;
  llvm_cbe_tmp__1778 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1776))), (((uint8_t*)(&llvm_cbe_tmp__1772))), UINT64_C(8));
  llvm_cbe_tmp__1779 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1777))), (((uint8_t*)(&llvm_cbe_tmp__1773))), UINT64_C(8));
  llvm_cbe_tmp__1780 = llvm_cbe_tmp__1774;
  llvm_cbe_tmp__1781 = *((&llvm_cbe_tmp__1776.field0));
  llvm_cbe_tmp__1782 = *((&llvm_cbe_tmp__1777.field0));
  llvm_cbe_tmp__1783 = _ZSt18uninitialized_copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(llvm_cbe_tmp__1781, llvm_cbe_tmp__1782, llvm_cbe_tmp__1780);
  return llvm_cbe_tmp__1783;
}


struct l_struct_class_OC_NStatement** _ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1784) {
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1785;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1786;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1787;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1788;

  llvm_cbe_tmp__1786 = llvm_cbe_tmp__1784;
  llvm_cbe_tmp__1787 = llvm_cbe_tmp__1786;
  _ZNSt13move_iteratorIPP10NStatementEC2ES2_((&llvm_cbe_tmp__1785), llvm_cbe_tmp__1787);
  llvm_cbe_tmp__1788 = *((&llvm_cbe_tmp__1785.field0));
  return llvm_cbe_tmp__1788;
}


struct l_struct_class_OC_NStatement** _ZSt18uninitialized_copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1789, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1790, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1791) {
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1792;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1793;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1794;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__1795;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1796;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1797;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1798;
  uint8_t* llvm_cbe_tmp__1799;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1800;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1801;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1802;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1803;

  *((&llvm_cbe_tmp__1792.field0)) = llvm_cbe_tmp__1789;
  *((&llvm_cbe_tmp__1793.field0)) = llvm_cbe_tmp__1790;
  llvm_cbe_tmp__1794 = llvm_cbe_tmp__1791;
  llvm_cbe_tmp__1795 = 1;
  llvm_cbe_tmp__1798 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1796))), (((uint8_t*)(&llvm_cbe_tmp__1792))), UINT64_C(8));
  llvm_cbe_tmp__1799 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1797))), (((uint8_t*)(&llvm_cbe_tmp__1793))), UINT64_C(8));
  llvm_cbe_tmp__1800 = llvm_cbe_tmp__1794;
  llvm_cbe_tmp__1801 = *((&llvm_cbe_tmp__1796.field0));
  llvm_cbe_tmp__1802 = *((&llvm_cbe_tmp__1797.field0));
  llvm_cbe_tmp__1803 = _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP10NStatementES5_EET0_T_S8_S7_(llvm_cbe_tmp__1801, llvm_cbe_tmp__1802, llvm_cbe_tmp__1800);
  return llvm_cbe_tmp__1803;
}


struct l_struct_class_OC_NStatement** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP10NStatementES5_EET0_T_S8_S7_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1804, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1805, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1806) {
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1807;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1808;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1809;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1810;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1811;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1812;
  uint8_t* llvm_cbe_tmp__1813;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1814;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1815;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1816;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1817;

  *((&llvm_cbe_tmp__1807.field0)) = llvm_cbe_tmp__1804;
  *((&llvm_cbe_tmp__1808.field0)) = llvm_cbe_tmp__1805;
  llvm_cbe_tmp__1809 = llvm_cbe_tmp__1806;
  llvm_cbe_tmp__1812 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1810))), (((uint8_t*)(&llvm_cbe_tmp__1807))), UINT64_C(8));
  llvm_cbe_tmp__1813 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1811))), (((uint8_t*)(&llvm_cbe_tmp__1808))), UINT64_C(8));
  llvm_cbe_tmp__1814 = llvm_cbe_tmp__1809;
  llvm_cbe_tmp__1815 = *((&llvm_cbe_tmp__1810.field0));
  llvm_cbe_tmp__1816 = *((&llvm_cbe_tmp__1811.field0));
  llvm_cbe_tmp__1817 = _ZSt4copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(llvm_cbe_tmp__1815, llvm_cbe_tmp__1816, llvm_cbe_tmp__1814);
  return llvm_cbe_tmp__1817;
}


struct l_struct_class_OC_NStatement** _ZSt4copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1818, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1819, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1820) {
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1821;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1822;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1823;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1824;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1825;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1826;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1827;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1828;
  uint8_t* llvm_cbe_tmp__1829;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1830;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1831;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1832;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1833;

  *((&llvm_cbe_tmp__1821.field0)) = llvm_cbe_tmp__1818;
  *((&llvm_cbe_tmp__1822.field0)) = llvm_cbe_tmp__1819;
  llvm_cbe_tmp__1823 = llvm_cbe_tmp__1820;
  llvm_cbe_tmp__1826 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1824))), (((uint8_t*)(&llvm_cbe_tmp__1821))), UINT64_C(8));
  llvm_cbe_tmp__1827 = *((&llvm_cbe_tmp__1824.field0));
  llvm_cbe_tmp__1828 = _ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(llvm_cbe_tmp__1827);
  llvm_cbe_tmp__1829 = memcpy((((uint8_t*)(&llvm_cbe_tmp__1825))), (((uint8_t*)(&llvm_cbe_tmp__1822))), UINT64_C(8));
  llvm_cbe_tmp__1830 = *((&llvm_cbe_tmp__1825.field0));
  llvm_cbe_tmp__1831 = _ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(llvm_cbe_tmp__1830);
  llvm_cbe_tmp__1832 = llvm_cbe_tmp__1823;
  llvm_cbe_tmp__1833 = _ZSt14__copy_move_a2ILb1EPP10NStatementS2_ET1_T0_S4_S3_(llvm_cbe_tmp__1828, llvm_cbe_tmp__1831, llvm_cbe_tmp__1832);
  return llvm_cbe_tmp__1833;
}


struct l_struct_class_OC_NStatement** _ZSt14__copy_move_a2ILb1EPP10NStatementS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1834, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1835, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1836) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1837;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1838;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1839;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1840;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1841;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1842;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1843;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1844;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1845;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1846;

  llvm_cbe_tmp__1837 = llvm_cbe_tmp__1834;
  llvm_cbe_tmp__1838 = llvm_cbe_tmp__1835;
  llvm_cbe_tmp__1839 = llvm_cbe_tmp__1836;
  llvm_cbe_tmp__1840 = llvm_cbe_tmp__1837;
  llvm_cbe_tmp__1841 = _ZSt12__niter_baseIPP10NStatementET_S3_(llvm_cbe_tmp__1840);
  llvm_cbe_tmp__1842 = llvm_cbe_tmp__1838;
  llvm_cbe_tmp__1843 = _ZSt12__niter_baseIPP10NStatementET_S3_(llvm_cbe_tmp__1842);
  llvm_cbe_tmp__1844 = llvm_cbe_tmp__1839;
  llvm_cbe_tmp__1845 = _ZSt12__niter_baseIPP10NStatementET_S3_(llvm_cbe_tmp__1844);
  llvm_cbe_tmp__1846 = _ZSt13__copy_move_aILb1EPP10NStatementS2_ET1_T0_S4_S3_(llvm_cbe_tmp__1841, llvm_cbe_tmp__1843, llvm_cbe_tmp__1845);
  return llvm_cbe_tmp__1846;
}


struct l_struct_class_OC_NStatement** _ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1847) {
  struct l_struct_class_OC_std_KD__KD_move_iterator llvm_cbe_tmp__1848;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1849;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1850;

  *((&llvm_cbe_tmp__1848.field0)) = llvm_cbe_tmp__1847;
  llvm_cbe_tmp__1849 = _ZNKSt13move_iteratorIPP10NStatementE4baseEv((&llvm_cbe_tmp__1848));
  llvm_cbe_tmp__1850 = _ZSt12__miter_baseIPP10NStatementET_S3_(llvm_cbe_tmp__1849);
  return llvm_cbe_tmp__1850;
}


struct l_struct_class_OC_NStatement** _ZSt13__copy_move_aILb1EPP10NStatementS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1851, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1852, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1853) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1854;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1855;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1856;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__1857;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1858;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1859;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1860;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1861;

  llvm_cbe_tmp__1854 = llvm_cbe_tmp__1851;
  llvm_cbe_tmp__1855 = llvm_cbe_tmp__1852;
  llvm_cbe_tmp__1856 = llvm_cbe_tmp__1853;
  llvm_cbe_tmp__1857 = 1;
  llvm_cbe_tmp__1858 = llvm_cbe_tmp__1854;
  llvm_cbe_tmp__1859 = llvm_cbe_tmp__1855;
  llvm_cbe_tmp__1860 = llvm_cbe_tmp__1856;
  llvm_cbe_tmp__1861 = _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP10NStatementEEPT_PKS5_S8_S6_(llvm_cbe_tmp__1858, llvm_cbe_tmp__1859, llvm_cbe_tmp__1860);
  return llvm_cbe_tmp__1861;
}


struct l_struct_class_OC_NStatement** _ZSt12__niter_baseIPP10NStatementET_S3_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1862) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1863;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1864;

  llvm_cbe_tmp__1863 = llvm_cbe_tmp__1862;
  llvm_cbe_tmp__1864 = llvm_cbe_tmp__1863;
  return llvm_cbe_tmp__1864;
}


struct l_struct_class_OC_NStatement** _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP10NStatementEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1865, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1866, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1867) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1868;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1869;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1870;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1871;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1872;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1873;
  uint64_t llvm_cbe_tmp__1874;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1875;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1876;
  uint64_t llvm_cbe_tmp__1877;
  uint8_t* llvm_cbe_tmp__1878;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1879;
  uint64_t llvm_cbe_tmp__1880;

  llvm_cbe_tmp__1868 = llvm_cbe_tmp__1865;
  llvm_cbe_tmp__1869 = llvm_cbe_tmp__1866;
  llvm_cbe_tmp__1870 = llvm_cbe_tmp__1867;
  llvm_cbe_tmp__1872 = llvm_cbe_tmp__1869;
  llvm_cbe_tmp__1873 = llvm_cbe_tmp__1868;
  llvm_cbe_tmp__1871 = (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1872)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1873)))), UINT64_C(8)));
  llvm_cbe_tmp__1874 = llvm_cbe_tmp__1871;
  if ((((llvm_cbe_tmp__1874 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__1881;
  } else {
    goto llvm_cbe_tmp__1882;
  }

llvm_cbe_tmp__1881:
  llvm_cbe_tmp__1875 = llvm_cbe_tmp__1870;
  llvm_cbe_tmp__1876 = llvm_cbe_tmp__1868;
  llvm_cbe_tmp__1877 = llvm_cbe_tmp__1871;
  llvm_cbe_tmp__1878 = memmove((((uint8_t*)llvm_cbe_tmp__1875)), (((uint8_t*)llvm_cbe_tmp__1876)), (llvm_mul_u64(UINT64_C(8), llvm_cbe_tmp__1877)));
  goto llvm_cbe_tmp__1882;

llvm_cbe_tmp__1882:
  llvm_cbe_tmp__1879 = llvm_cbe_tmp__1870;
  llvm_cbe_tmp__1880 = llvm_cbe_tmp__1871;
  return ((&llvm_cbe_tmp__1879[((int64_t)llvm_cbe_tmp__1880)]));
}


struct l_struct_class_OC_NStatement** _ZSt12__miter_baseIPP10NStatementET_S3_(struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1883) {
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1884;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1885;

  llvm_cbe_tmp__1884 = llvm_cbe_tmp__1883;
  llvm_cbe_tmp__1885 = llvm_cbe_tmp__1884;
  return llvm_cbe_tmp__1885;
}


struct l_struct_class_OC_NStatement** _ZNKSt13move_iteratorIPP10NStatementE4baseEv(struct l_struct_class_OC_std_KD__KD_move_iterator* llvm_cbe_tmp__1886) {
  struct l_struct_class_OC_std_KD__KD_move_iterator* llvm_cbe_tmp__1887;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator* llvm_cbe_tmp__1888;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1889;

  llvm_cbe_tmp__1887 = llvm_cbe_tmp__1886;
  llvm_cbe_tmp__1888 = llvm_cbe_tmp__1887;
  llvm_cbe_tmp__1889 = *((&llvm_cbe_tmp__1888->field0));
  return llvm_cbe_tmp__1889;
}


void _ZNSt13move_iteratorIPP10NStatementEC2ES2_(struct l_struct_class_OC_std_KD__KD_move_iterator* llvm_cbe_tmp__1890, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1891) {
  struct l_struct_class_OC_std_KD__KD_move_iterator* llvm_cbe_tmp__1892;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1893;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator* llvm_cbe_tmp__1894;
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1895;

  llvm_cbe_tmp__1892 = llvm_cbe_tmp__1890;
  llvm_cbe_tmp__1893 = llvm_cbe_tmp__1891;
  llvm_cbe_tmp__1894 = llvm_cbe_tmp__1892;
  llvm_cbe_tmp__1895 = llvm_cbe_tmp__1893;
  *((&llvm_cbe_tmp__1894->field0)) = llvm_cbe_tmp__1895;
}


void _ZN9__gnu_cxx13new_allocatorIP10NStatementE7destroyIS2_EEvPT_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1896, struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1897) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1898;    /* Address-exposed local */
  struct l_struct_class_OC_NStatement** llvm_cbe_tmp__1899;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator* llvm_cbe_tmp__1900;

  llvm_cbe_tmp__1898 = llvm_cbe_tmp__1896;
  llvm_cbe_tmp__1899 = llvm_cbe_tmp__1897;
  llvm_cbe_tmp__1900 = llvm_cbe_tmp__1898;
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__1901) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__1902;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4* llvm_cbe_tmp__1903;

  llvm_cbe_tmp__1902 = llvm_cbe_tmp__1901;
  llvm_cbe_tmp__1903 = llvm_cbe_tmp__1902;
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2Ev(((&llvm_cbe_tmp__1903->field0)));
}


void _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2Ev(struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1904) {
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1905;    /* Address-exposed local */
  struct l_struct_struct_OC_std_KD__KD__Vector_base_MD_NVariableDeclaration_AC__KC__MC__AC_std_KD__KD_allocator_MD_NVariableDeclaration_AC__KC__OD__AC__OD__KD__KD__Vector_impl* llvm_cbe_tmp__1906;

  llvm_cbe_tmp__1905 = llvm_cbe_tmp__1904;
  llvm_cbe_tmp__1906 = llvm_cbe_tmp__1905;
  _ZNSaIP20NVariableDeclarationEC2Ev((((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)llvm_cbe_tmp__1906)));
  *((&llvm_cbe_tmp__1906->field0)) = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);
  *((&llvm_cbe_tmp__1906->field1)) = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);
  *((&llvm_cbe_tmp__1906->field2)) = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);
}


void _ZNSaIP20NVariableDeclarationEC2Ev(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1907) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1908;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1909;

  llvm_cbe_tmp__1908 = llvm_cbe_tmp__1907;
  llvm_cbe_tmp__1909 = llvm_cbe_tmp__1908;
  _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2Ev((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__1909)));
}


void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2Ev(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1910) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1911;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1912;

  llvm_cbe_tmp__1911 = llvm_cbe_tmp__1910;
  llvm_cbe_tmp__1912 = llvm_cbe_tmp__1911;
}


void _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1913, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1914, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1915) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1916;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1917;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1918;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1919;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1920;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1921;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1922;

  llvm_cbe_tmp__1916 = llvm_cbe_tmp__1913;
  llvm_cbe_tmp__1917 = llvm_cbe_tmp__1914;
  llvm_cbe_tmp__1918 = llvm_cbe_tmp__1915;
  llvm_cbe_tmp__1919 = llvm_cbe_tmp__1916;
  llvm_cbe_tmp__1920 = llvm_cbe_tmp__1917;
  llvm_cbe_tmp__1921 = llvm_cbe_tmp__1918;
  llvm_cbe_tmp__1922 = _ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__1921);
  _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE9constructIS2_JRKS2_EEEvPT_DpOT0_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__1919)), llvm_cbe_tmp__1920, llvm_cbe_tmp__1922);
}


void _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__1923, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1924, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1925) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15 llvm_cbe_tmp__1926;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__1927;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1928;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1929;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1930;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1931;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__1932;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15 llvm_cbe_tmp__1933;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1934;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1935;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__1936;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__1937;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__1938;
  uint64_t llvm_cbe_tmp__1939;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1940;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1941;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1942;
  uint64_t llvm_cbe_tmp__1943;
  uint64_t llvm_cbe_tmp__1944;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1945;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1946;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1947;
  uint64_t llvm_cbe_tmp__1948;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1949;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1950;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1951;
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__1952;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1953;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1954;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1955;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1956;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1957;
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__1958;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1959;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1960;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1961;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1962;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1963;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1964;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1965;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__1966;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1967;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1968;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1969;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1970;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1971;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1972;
  uint64_t llvm_cbe_tmp__1973;

  *((&llvm_cbe_tmp__1926.field0)) = llvm_cbe_tmp__1924;
  llvm_cbe_tmp__1927 = llvm_cbe_tmp__1923;
  llvm_cbe_tmp__1928 = llvm_cbe_tmp__1925;
  llvm_cbe_tmp__1938 = llvm_cbe_tmp__1927;
  llvm_cbe_tmp__1939 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE12_M_check_lenEmPKc(llvm_cbe_tmp__1938, UINT64_C(1), ((&_OC_str_OC_8.array[((int32_t)0)])));
  llvm_cbe_tmp__1929 = llvm_cbe_tmp__1939;
  llvm_cbe_tmp__1940 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938))->field0))->field0));
  llvm_cbe_tmp__1930 = llvm_cbe_tmp__1940;
  llvm_cbe_tmp__1941 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938))->field0))->field1));
  llvm_cbe_tmp__1931 = llvm_cbe_tmp__1941;
  llvm_cbe_tmp__1942 = _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(llvm_cbe_tmp__1938);
  *((&llvm_cbe_tmp__1933.field0)) = llvm_cbe_tmp__1942;
  llvm_cbe_tmp__1943 = _ZN9__gnu_cxxmiIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_((&llvm_cbe_tmp__1926), (&llvm_cbe_tmp__1933));
  llvm_cbe_tmp__1932 = llvm_cbe_tmp__1943;
  llvm_cbe_tmp__1944 = llvm_cbe_tmp__1929;
  llvm_cbe_tmp__1945 = _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938)), llvm_cbe_tmp__1944);
  llvm_cbe_tmp__1934 = llvm_cbe_tmp__1945;
  llvm_cbe_tmp__1946 = llvm_cbe_tmp__1934;
  llvm_cbe_tmp__1935 = llvm_cbe_tmp__1946;
  llvm_cbe_tmp__1947 = llvm_cbe_tmp__1934;
  llvm_cbe_tmp__1948 = llvm_cbe_tmp__1932;
  llvm_cbe_tmp__1949 = llvm_cbe_tmp__1928;
  llvm_cbe_tmp__1950 = _ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__1949);
  _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_((((struct l_struct_class_OC_std_KD__KD_allocator_OC_5*)((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938))->field0)))), ((&llvm_cbe_tmp__1947[((int64_t)llvm_cbe_tmp__1948)])), llvm_cbe_tmp__1950);
  goto llvm_cbe_tmp__1974;

llvm_cbe_tmp__1974:
  llvm_cbe_tmp__1935 = ((struct l_struct_class_OC_NVariableDeclaration**)/*NULL*/0);
  llvm_cbe_tmp__1951 = llvm_cbe_tmp__1930;
  llvm_cbe_tmp__1952 = _ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__1926));
  llvm_cbe_tmp__1953 = *llvm_cbe_tmp__1952;
  llvm_cbe_tmp__1954 = llvm_cbe_tmp__1934;
  llvm_cbe_tmp__1955 = _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938)));
  llvm_cbe_tmp__1956 = _ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_(llvm_cbe_tmp__1951, llvm_cbe_tmp__1953, llvm_cbe_tmp__1954, llvm_cbe_tmp__1955);
  goto llvm_cbe_tmp__1975;

llvm_cbe_tmp__1975:
  llvm_cbe_tmp__1935 = llvm_cbe_tmp__1956;
  llvm_cbe_tmp__1957 = llvm_cbe_tmp__1935;
  llvm_cbe_tmp__1935 = ((&llvm_cbe_tmp__1957[((int32_t)1)]));
  llvm_cbe_tmp__1958 = _ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__1926));
  llvm_cbe_tmp__1959 = *llvm_cbe_tmp__1958;
  llvm_cbe_tmp__1960 = llvm_cbe_tmp__1931;
  llvm_cbe_tmp__1961 = llvm_cbe_tmp__1935;
  llvm_cbe_tmp__1962 = _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938)));
  llvm_cbe_tmp__1963 = _ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_(llvm_cbe_tmp__1959, llvm_cbe_tmp__1960, llvm_cbe_tmp__1961, llvm_cbe_tmp__1962);
  goto llvm_cbe_tmp__1976;

llvm_cbe_tmp__1976:
  llvm_cbe_tmp__1935 = llvm_cbe_tmp__1963;
  goto llvm_cbe_tmp__1977;

llvm_cbe_tmp__1977:
  llvm_cbe_tmp__1964 = llvm_cbe_tmp__1930;
  llvm_cbe_tmp__1965 = llvm_cbe_tmp__1931;
  llvm_cbe_tmp__1966 = _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938)));
  _ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(llvm_cbe_tmp__1964, llvm_cbe_tmp__1965, llvm_cbe_tmp__1966);
  llvm_cbe_tmp__1967 = llvm_cbe_tmp__1930;
  llvm_cbe_tmp__1968 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938))->field0))->field2));
  llvm_cbe_tmp__1969 = llvm_cbe_tmp__1930;
  _ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938)), llvm_cbe_tmp__1967, (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__1968)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__1969)))), UINT64_C(8))));
  llvm_cbe_tmp__1970 = llvm_cbe_tmp__1934;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938))->field0))->field0)) = llvm_cbe_tmp__1970;
  llvm_cbe_tmp__1971 = llvm_cbe_tmp__1935;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938))->field0))->field1)) = llvm_cbe_tmp__1971;
  llvm_cbe_tmp__1972 = llvm_cbe_tmp__1934;
  llvm_cbe_tmp__1973 = llvm_cbe_tmp__1929;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1938))->field0))->field2)) = ((&llvm_cbe_tmp__1972[((int64_t)llvm_cbe_tmp__1973)]));
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__1978) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15 llvm_cbe_tmp__1979;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__1980;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__1981;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1982;

  llvm_cbe_tmp__1980 = llvm_cbe_tmp__1978;
  llvm_cbe_tmp__1981 = llvm_cbe_tmp__1980;
  _ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_((&llvm_cbe_tmp__1979), ((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__1981))->field0))->field1)));
  llvm_cbe_tmp__1982 = *((&llvm_cbe_tmp__1979.field0));
  return llvm_cbe_tmp__1982;
}


void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE9constructIS2_JRKS2_EEEvPT_DpOT0_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1983, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1984, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1985) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1986;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1987;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1988;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__1989;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1990;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1991;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1992;
  struct l_struct_class_OC_NVariableDeclaration* llvm_cbe_tmp__1993;

  llvm_cbe_tmp__1986 = llvm_cbe_tmp__1983;
  llvm_cbe_tmp__1987 = llvm_cbe_tmp__1984;
  llvm_cbe_tmp__1988 = llvm_cbe_tmp__1985;
  llvm_cbe_tmp__1989 = llvm_cbe_tmp__1986;
  llvm_cbe_tmp__1990 = llvm_cbe_tmp__1987;
  llvm_cbe_tmp__1991 = llvm_cbe_tmp__1988;
  llvm_cbe_tmp__1992 = _ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__1991);
  llvm_cbe_tmp__1993 = *llvm_cbe_tmp__1992;
  *(((struct l_struct_class_OC_NVariableDeclaration**)(((uint8_t*)llvm_cbe_tmp__1990)))) = llvm_cbe_tmp__1993;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1994) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1995;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__1996;

  llvm_cbe_tmp__1995 = llvm_cbe_tmp__1994;
  llvm_cbe_tmp__1996 = llvm_cbe_tmp__1995;
  return llvm_cbe_tmp__1996;
}


uint64_t _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE12_M_check_lenEmPKc(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__1997, uint64_t llvm_cbe_tmp__1998, uint8_t* llvm_cbe_tmp__1999) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2000;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2001;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2002;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2003;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2004;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2005;
  uint64_t llvm_cbe_tmp__2006;
  uint64_t llvm_cbe_tmp__2007;
  uint64_t llvm_cbe_tmp__2008;
  uint8_t* llvm_cbe_tmp__2009;
  uint64_t llvm_cbe_tmp__2010;
  uint64_t llvm_cbe_tmp__2011;
  uint64_t* llvm_cbe_tmp__2012;
  uint64_t llvm_cbe_tmp__2013;
  uint64_t llvm_cbe_tmp__2014;
  uint64_t llvm_cbe_tmp__2015;
  uint64_t llvm_cbe_tmp__2016;
  uint64_t llvm_cbe_tmp__2017;
  uint64_t llvm_cbe_tmp__2018;
  uint64_t llvm_cbe_tmp__2019;
  uint64_t llvm_cbe_tmp__2020;
  uint64_t llvm_cbe_tmp__2020__PHI_TEMPORARY;

  llvm_cbe_tmp__2000 = llvm_cbe_tmp__1997;
  llvm_cbe_tmp__2001 = llvm_cbe_tmp__1998;
  llvm_cbe_tmp__2002 = llvm_cbe_tmp__1999;
  llvm_cbe_tmp__2005 = llvm_cbe_tmp__2000;
  llvm_cbe_tmp__2006 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(llvm_cbe_tmp__2005);
  llvm_cbe_tmp__2007 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(llvm_cbe_tmp__2005);
  llvm_cbe_tmp__2008 = llvm_cbe_tmp__2001;
  if ((((((uint64_t)(llvm_sub_u64(llvm_cbe_tmp__2006, llvm_cbe_tmp__2007))) < ((uint64_t)llvm_cbe_tmp__2008))&1))) {
    goto llvm_cbe_tmp__2021;
  } else {
    goto llvm_cbe_tmp__2022;
  }

llvm_cbe_tmp__2021:
  llvm_cbe_tmp__2009 = llvm_cbe_tmp__2002;
  _ZSt20__throw_length_errorPKc(llvm_cbe_tmp__2009);
  __builtin_unreachable();

llvm_cbe_tmp__2022:
  llvm_cbe_tmp__2010 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(llvm_cbe_tmp__2005);
  llvm_cbe_tmp__2011 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(llvm_cbe_tmp__2005);
  llvm_cbe_tmp__2004 = llvm_cbe_tmp__2011;
  llvm_cbe_tmp__2012 = _ZSt3maxImERKT_S2_S2_((&llvm_cbe_tmp__2004), (&llvm_cbe_tmp__2001));
  llvm_cbe_tmp__2013 = *llvm_cbe_tmp__2012;
  llvm_cbe_tmp__2003 = (llvm_add_u64(llvm_cbe_tmp__2010, llvm_cbe_tmp__2013));
  llvm_cbe_tmp__2014 = llvm_cbe_tmp__2003;
  llvm_cbe_tmp__2015 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(llvm_cbe_tmp__2005);
  if ((((((uint64_t)llvm_cbe_tmp__2014) < ((uint64_t)llvm_cbe_tmp__2015))&1))) {
    goto llvm_cbe_tmp__2023;
  } else {
    goto llvm_cbe_tmp__2024;
  }

llvm_cbe_tmp__2024:
  llvm_cbe_tmp__2016 = llvm_cbe_tmp__2003;
  llvm_cbe_tmp__2017 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(llvm_cbe_tmp__2005);
  if ((((((uint64_t)llvm_cbe_tmp__2016) > ((uint64_t)llvm_cbe_tmp__2017))&1))) {
    goto llvm_cbe_tmp__2023;
  } else {
    goto llvm_cbe_tmp__2025;
  }

llvm_cbe_tmp__2023:
  llvm_cbe_tmp__2018 = _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(llvm_cbe_tmp__2005);
  llvm_cbe_tmp__2020__PHI_TEMPORARY = llvm_cbe_tmp__2018;   /* for PHI node */
  goto llvm_cbe_tmp__2026;

llvm_cbe_tmp__2025:
  llvm_cbe_tmp__2019 = llvm_cbe_tmp__2003;
  llvm_cbe_tmp__2020__PHI_TEMPORARY = llvm_cbe_tmp__2019;   /* for PHI node */
  goto llvm_cbe_tmp__2026;

llvm_cbe_tmp__2026:
  llvm_cbe_tmp__2020 = llvm_cbe_tmp__2020__PHI_TEMPORARY;
  return llvm_cbe_tmp__2020;
}


uint64_t _ZN9__gnu_cxxmiIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2027, struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2028) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2029;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2030;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2031;
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__2032;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2033;
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2034;
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__2035;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2036;

  llvm_cbe_tmp__2029 = llvm_cbe_tmp__2027;
  llvm_cbe_tmp__2030 = llvm_cbe_tmp__2028;
  llvm_cbe_tmp__2031 = llvm_cbe_tmp__2029;
  llvm_cbe_tmp__2032 = _ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(llvm_cbe_tmp__2031);
  llvm_cbe_tmp__2033 = *llvm_cbe_tmp__2032;
  llvm_cbe_tmp__2034 = llvm_cbe_tmp__2030;
  llvm_cbe_tmp__2035 = _ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(llvm_cbe_tmp__2034);
  llvm_cbe_tmp__2036 = *llvm_cbe_tmp__2035;
  return (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__2033)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__2036)))), UINT64_C(8)));
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2037) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15 llvm_cbe_tmp__2038;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2039;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2040;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2041;

  llvm_cbe_tmp__2039 = llvm_cbe_tmp__2037;
  llvm_cbe_tmp__2040 = llvm_cbe_tmp__2039;
  _ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_((&llvm_cbe_tmp__2038), ((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__2040))->field0))->field0)));
  llvm_cbe_tmp__2041 = *((&llvm_cbe_tmp__2038.field0));
  return llvm_cbe_tmp__2041;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2042, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2043, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2044, struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2045) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2046;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2047;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2048;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2049;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2050;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2051;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2052;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2053;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2054;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2055;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2056;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2057;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2058;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2059;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2060;

  llvm_cbe_tmp__2046 = llvm_cbe_tmp__2042;
  llvm_cbe_tmp__2047 = llvm_cbe_tmp__2043;
  llvm_cbe_tmp__2048 = llvm_cbe_tmp__2044;
  llvm_cbe_tmp__2049 = llvm_cbe_tmp__2045;
  llvm_cbe_tmp__2052 = llvm_cbe_tmp__2046;
  llvm_cbe_tmp__2053 = _ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_(llvm_cbe_tmp__2052);
  *((&llvm_cbe_tmp__2050.field0)) = llvm_cbe_tmp__2053;
  llvm_cbe_tmp__2054 = llvm_cbe_tmp__2047;
  llvm_cbe_tmp__2055 = _ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_(llvm_cbe_tmp__2054);
  *((&llvm_cbe_tmp__2051.field0)) = llvm_cbe_tmp__2055;
  llvm_cbe_tmp__2056 = llvm_cbe_tmp__2048;
  llvm_cbe_tmp__2057 = llvm_cbe_tmp__2049;
  llvm_cbe_tmp__2058 = *((&llvm_cbe_tmp__2050.field0));
  llvm_cbe_tmp__2059 = *((&llvm_cbe_tmp__2051.field0));
  llvm_cbe_tmp__2060 = _ZSt22__uninitialized_copy_aISt13move_iteratorIPP20NVariableDeclarationES3_S2_ET0_T_S6_S5_RSaIT1_E(llvm_cbe_tmp__2058, llvm_cbe_tmp__2059, llvm_cbe_tmp__2056, llvm_cbe_tmp__2057);
  return llvm_cbe_tmp__2060;
}


struct l_struct_class_OC_NVariableDeclaration*** _ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2061) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2062;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2063;

  llvm_cbe_tmp__2062 = llvm_cbe_tmp__2061;
  llvm_cbe_tmp__2063 = llvm_cbe_tmp__2062;
  return ((&llvm_cbe_tmp__2063->field0));
}


void _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE7destroyIS1_EEvRS2_PT_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2064, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2065) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2066;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2067;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2068;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2069;

  llvm_cbe_tmp__2066 = llvm_cbe_tmp__2064;
  llvm_cbe_tmp__2067 = llvm_cbe_tmp__2065;
  llvm_cbe_tmp__2068 = llvm_cbe_tmp__2066;
  llvm_cbe_tmp__2069 = llvm_cbe_tmp__2067;
  _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE7destroyIS2_EEvPT_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__2068)), llvm_cbe_tmp__2069);
}


uint64_t _ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2070) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2071;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_3* llvm_cbe_tmp__2072;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2073;
  uint64_t llvm_cbe_tmp__2074;

  llvm_cbe_tmp__2071 = llvm_cbe_tmp__2070;
  llvm_cbe_tmp__2072 = llvm_cbe_tmp__2071;
  llvm_cbe_tmp__2073 = _ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_4*)llvm_cbe_tmp__2072)));
  llvm_cbe_tmp__2074 = _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8max_sizeERKS2_(llvm_cbe_tmp__2073);
  return llvm_cbe_tmp__2074;
}


uint64_t _ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8max_sizeERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2075) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2076;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2077;
  uint64_t llvm_cbe_tmp__2078;

  llvm_cbe_tmp__2076 = llvm_cbe_tmp__2075;
  llvm_cbe_tmp__2077 = llvm_cbe_tmp__2076;
  llvm_cbe_tmp__2078 = _ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6*)llvm_cbe_tmp__2077)));
  return llvm_cbe_tmp__2078;
}


void _ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2079, struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__2080) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2081;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__2082;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_15* llvm_cbe_tmp__2083;
  struct l_struct_class_OC_NVariableDeclaration*** llvm_cbe_tmp__2084;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2085;

  llvm_cbe_tmp__2081 = llvm_cbe_tmp__2079;
  llvm_cbe_tmp__2082 = llvm_cbe_tmp__2080;
  llvm_cbe_tmp__2083 = llvm_cbe_tmp__2081;
  llvm_cbe_tmp__2084 = llvm_cbe_tmp__2082;
  llvm_cbe_tmp__2085 = *llvm_cbe_tmp__2084;
  *((&llvm_cbe_tmp__2083->field0)) = llvm_cbe_tmp__2085;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt22__uninitialized_copy_aISt13move_iteratorIPP20NVariableDeclarationES3_S2_ET0_T_S6_S5_RSaIT1_E(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2086, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2087, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2088, struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2089) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2090;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2091;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2092;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_5* llvm_cbe_tmp__2093;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2094;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2095;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2096;
  uint8_t* llvm_cbe_tmp__2097;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2098;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2099;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2100;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2101;

  *((&llvm_cbe_tmp__2090.field0)) = llvm_cbe_tmp__2086;
  *((&llvm_cbe_tmp__2091.field0)) = llvm_cbe_tmp__2087;
  llvm_cbe_tmp__2092 = llvm_cbe_tmp__2088;
  llvm_cbe_tmp__2093 = llvm_cbe_tmp__2089;
  llvm_cbe_tmp__2096 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2094))), (((uint8_t*)(&llvm_cbe_tmp__2090))), UINT64_C(8));
  llvm_cbe_tmp__2097 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2095))), (((uint8_t*)(&llvm_cbe_tmp__2091))), UINT64_C(8));
  llvm_cbe_tmp__2098 = llvm_cbe_tmp__2092;
  llvm_cbe_tmp__2099 = *((&llvm_cbe_tmp__2094.field0));
  llvm_cbe_tmp__2100 = *((&llvm_cbe_tmp__2095.field0));
  llvm_cbe_tmp__2101 = _ZSt18uninitialized_copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(llvm_cbe_tmp__2099, llvm_cbe_tmp__2100, llvm_cbe_tmp__2098);
  return llvm_cbe_tmp__2101;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2102) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2103;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2104;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2105;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2106;

  llvm_cbe_tmp__2104 = llvm_cbe_tmp__2102;
  llvm_cbe_tmp__2105 = llvm_cbe_tmp__2104;
  _ZNSt13move_iteratorIPP20NVariableDeclarationEC2ES2_((&llvm_cbe_tmp__2103), llvm_cbe_tmp__2105);
  llvm_cbe_tmp__2106 = *((&llvm_cbe_tmp__2103.field0));
  return llvm_cbe_tmp__2106;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt18uninitialized_copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2107, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2108, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2109) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2110;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2111;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2112;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__2113;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2114;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2115;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2116;
  uint8_t* llvm_cbe_tmp__2117;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2118;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2119;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2120;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2121;

  *((&llvm_cbe_tmp__2110.field0)) = llvm_cbe_tmp__2107;
  *((&llvm_cbe_tmp__2111.field0)) = llvm_cbe_tmp__2108;
  llvm_cbe_tmp__2112 = llvm_cbe_tmp__2109;
  llvm_cbe_tmp__2113 = 1;
  llvm_cbe_tmp__2116 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2114))), (((uint8_t*)(&llvm_cbe_tmp__2110))), UINT64_C(8));
  llvm_cbe_tmp__2117 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2115))), (((uint8_t*)(&llvm_cbe_tmp__2111))), UINT64_C(8));
  llvm_cbe_tmp__2118 = llvm_cbe_tmp__2112;
  llvm_cbe_tmp__2119 = *((&llvm_cbe_tmp__2114.field0));
  llvm_cbe_tmp__2120 = *((&llvm_cbe_tmp__2115.field0));
  llvm_cbe_tmp__2121 = _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP20NVariableDeclarationES5_EET0_T_S8_S7_(llvm_cbe_tmp__2119, llvm_cbe_tmp__2120, llvm_cbe_tmp__2118);
  return llvm_cbe_tmp__2121;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP20NVariableDeclarationES5_EET0_T_S8_S7_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2122, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2123, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2124) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2125;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2126;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2127;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2128;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2129;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2130;
  uint8_t* llvm_cbe_tmp__2131;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2132;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2133;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2134;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2135;

  *((&llvm_cbe_tmp__2125.field0)) = llvm_cbe_tmp__2122;
  *((&llvm_cbe_tmp__2126.field0)) = llvm_cbe_tmp__2123;
  llvm_cbe_tmp__2127 = llvm_cbe_tmp__2124;
  llvm_cbe_tmp__2130 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2128))), (((uint8_t*)(&llvm_cbe_tmp__2125))), UINT64_C(8));
  llvm_cbe_tmp__2131 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2129))), (((uint8_t*)(&llvm_cbe_tmp__2126))), UINT64_C(8));
  llvm_cbe_tmp__2132 = llvm_cbe_tmp__2127;
  llvm_cbe_tmp__2133 = *((&llvm_cbe_tmp__2128.field0));
  llvm_cbe_tmp__2134 = *((&llvm_cbe_tmp__2129.field0));
  llvm_cbe_tmp__2135 = _ZSt4copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(llvm_cbe_tmp__2133, llvm_cbe_tmp__2134, llvm_cbe_tmp__2132);
  return llvm_cbe_tmp__2135;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt4copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2136, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2137, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2138) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2139;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2140;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2141;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2142;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2143;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2144;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2145;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2146;
  uint8_t* llvm_cbe_tmp__2147;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2148;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2149;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2150;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2151;

  *((&llvm_cbe_tmp__2139.field0)) = llvm_cbe_tmp__2136;
  *((&llvm_cbe_tmp__2140.field0)) = llvm_cbe_tmp__2137;
  llvm_cbe_tmp__2141 = llvm_cbe_tmp__2138;
  llvm_cbe_tmp__2144 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2142))), (((uint8_t*)(&llvm_cbe_tmp__2139))), UINT64_C(8));
  llvm_cbe_tmp__2145 = *((&llvm_cbe_tmp__2142.field0));
  llvm_cbe_tmp__2146 = _ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(llvm_cbe_tmp__2145);
  llvm_cbe_tmp__2147 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2143))), (((uint8_t*)(&llvm_cbe_tmp__2140))), UINT64_C(8));
  llvm_cbe_tmp__2148 = *((&llvm_cbe_tmp__2143.field0));
  llvm_cbe_tmp__2149 = _ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(llvm_cbe_tmp__2148);
  llvm_cbe_tmp__2150 = llvm_cbe_tmp__2141;
  llvm_cbe_tmp__2151 = _ZSt14__copy_move_a2ILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(llvm_cbe_tmp__2146, llvm_cbe_tmp__2149, llvm_cbe_tmp__2150);
  return llvm_cbe_tmp__2151;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt14__copy_move_a2ILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2152, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2153, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2154) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2155;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2156;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2157;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2158;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2159;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2160;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2161;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2162;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2163;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2164;

  llvm_cbe_tmp__2155 = llvm_cbe_tmp__2152;
  llvm_cbe_tmp__2156 = llvm_cbe_tmp__2153;
  llvm_cbe_tmp__2157 = llvm_cbe_tmp__2154;
  llvm_cbe_tmp__2158 = llvm_cbe_tmp__2155;
  llvm_cbe_tmp__2159 = _ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(llvm_cbe_tmp__2158);
  llvm_cbe_tmp__2160 = llvm_cbe_tmp__2156;
  llvm_cbe_tmp__2161 = _ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(llvm_cbe_tmp__2160);
  llvm_cbe_tmp__2162 = llvm_cbe_tmp__2157;
  llvm_cbe_tmp__2163 = _ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(llvm_cbe_tmp__2162);
  llvm_cbe_tmp__2164 = _ZSt13__copy_move_aILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(llvm_cbe_tmp__2159, llvm_cbe_tmp__2161, llvm_cbe_tmp__2163);
  return llvm_cbe_tmp__2164;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2165) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16 llvm_cbe_tmp__2166;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2167;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2168;

  *((&llvm_cbe_tmp__2166.field0)) = llvm_cbe_tmp__2165;
  llvm_cbe_tmp__2167 = _ZNKSt13move_iteratorIPP20NVariableDeclarationE4baseEv((&llvm_cbe_tmp__2166));
  llvm_cbe_tmp__2168 = _ZSt12__miter_baseIPP20NVariableDeclarationET_S3_(llvm_cbe_tmp__2167);
  return llvm_cbe_tmp__2168;
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt13__copy_move_aILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2169, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2170, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2171) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2172;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2173;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2174;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__2175;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2176;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2177;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2178;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2179;

  llvm_cbe_tmp__2172 = llvm_cbe_tmp__2169;
  llvm_cbe_tmp__2173 = llvm_cbe_tmp__2170;
  llvm_cbe_tmp__2174 = llvm_cbe_tmp__2171;
  llvm_cbe_tmp__2175 = 1;
  llvm_cbe_tmp__2176 = llvm_cbe_tmp__2172;
  llvm_cbe_tmp__2177 = llvm_cbe_tmp__2173;
  llvm_cbe_tmp__2178 = llvm_cbe_tmp__2174;
  llvm_cbe_tmp__2179 = _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(llvm_cbe_tmp__2176, llvm_cbe_tmp__2177, llvm_cbe_tmp__2178);
  return llvm_cbe_tmp__2179;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2180, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2181, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2182) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2183;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2184;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2185;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2186;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2187;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2188;
  uint64_t llvm_cbe_tmp__2189;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2190;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2191;
  uint64_t llvm_cbe_tmp__2192;
  uint8_t* llvm_cbe_tmp__2193;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2194;
  uint64_t llvm_cbe_tmp__2195;

  llvm_cbe_tmp__2183 = llvm_cbe_tmp__2180;
  llvm_cbe_tmp__2184 = llvm_cbe_tmp__2181;
  llvm_cbe_tmp__2185 = llvm_cbe_tmp__2182;
  llvm_cbe_tmp__2187 = llvm_cbe_tmp__2184;
  llvm_cbe_tmp__2188 = llvm_cbe_tmp__2183;
  llvm_cbe_tmp__2186 = (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__2187)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__2188)))), UINT64_C(8)));
  llvm_cbe_tmp__2189 = llvm_cbe_tmp__2186;
  if ((((llvm_cbe_tmp__2189 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__2196;
  } else {
    goto llvm_cbe_tmp__2197;
  }

llvm_cbe_tmp__2196:
  llvm_cbe_tmp__2190 = llvm_cbe_tmp__2185;
  llvm_cbe_tmp__2191 = llvm_cbe_tmp__2183;
  llvm_cbe_tmp__2192 = llvm_cbe_tmp__2186;
  llvm_cbe_tmp__2193 = memmove((((uint8_t*)llvm_cbe_tmp__2190)), (((uint8_t*)llvm_cbe_tmp__2191)), (llvm_mul_u64(UINT64_C(8), llvm_cbe_tmp__2192)));
  goto llvm_cbe_tmp__2197;

llvm_cbe_tmp__2197:
  llvm_cbe_tmp__2194 = llvm_cbe_tmp__2185;
  llvm_cbe_tmp__2195 = llvm_cbe_tmp__2186;
  return ((&llvm_cbe_tmp__2194[((int64_t)llvm_cbe_tmp__2195)]));
}


struct l_struct_class_OC_NVariableDeclaration** _ZSt12__miter_baseIPP20NVariableDeclarationET_S3_(struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2198) {
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2199;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2200;

  llvm_cbe_tmp__2199 = llvm_cbe_tmp__2198;
  llvm_cbe_tmp__2200 = llvm_cbe_tmp__2199;
  return llvm_cbe_tmp__2200;
}


struct l_struct_class_OC_NVariableDeclaration** _ZNKSt13move_iteratorIPP20NVariableDeclarationE4baseEv(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16* llvm_cbe_tmp__2201) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16* llvm_cbe_tmp__2202;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16* llvm_cbe_tmp__2203;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2204;

  llvm_cbe_tmp__2202 = llvm_cbe_tmp__2201;
  llvm_cbe_tmp__2203 = llvm_cbe_tmp__2202;
  llvm_cbe_tmp__2204 = *((&llvm_cbe_tmp__2203->field0));
  return llvm_cbe_tmp__2204;
}


void _ZNSt13move_iteratorIPP20NVariableDeclarationEC2ES2_(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16* llvm_cbe_tmp__2205, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2206) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16* llvm_cbe_tmp__2207;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2208;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_16* llvm_cbe_tmp__2209;
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2210;

  llvm_cbe_tmp__2207 = llvm_cbe_tmp__2205;
  llvm_cbe_tmp__2208 = llvm_cbe_tmp__2206;
  llvm_cbe_tmp__2209 = llvm_cbe_tmp__2207;
  llvm_cbe_tmp__2210 = llvm_cbe_tmp__2208;
  *((&llvm_cbe_tmp__2209->field0)) = llvm_cbe_tmp__2210;
}


void _ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE7destroyIS2_EEvPT_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__2211, struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2212) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__2213;    /* Address-exposed local */
  struct l_struct_class_OC_NVariableDeclaration** llvm_cbe_tmp__2214;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_6* llvm_cbe_tmp__2215;

  llvm_cbe_tmp__2213 = llvm_cbe_tmp__2211;
  llvm_cbe_tmp__2214 = llvm_cbe_tmp__2212;
  llvm_cbe_tmp__2215 = llvm_cbe_tmp__2213;
}


void _ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2216, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2217, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2218) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2219;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2220;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2221;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2222;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2223;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2224;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2225;

  llvm_cbe_tmp__2219 = llvm_cbe_tmp__2216;
  llvm_cbe_tmp__2220 = llvm_cbe_tmp__2217;
  llvm_cbe_tmp__2221 = llvm_cbe_tmp__2218;
  llvm_cbe_tmp__2222 = llvm_cbe_tmp__2219;
  llvm_cbe_tmp__2223 = llvm_cbe_tmp__2220;
  llvm_cbe_tmp__2224 = llvm_cbe_tmp__2221;
  llvm_cbe_tmp__2225 = _ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__2224);
  _ZN9__gnu_cxx13new_allocatorIP11NExpressionE9constructIS2_JRKS2_EEEvPT_DpOT0_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__2222)), llvm_cbe_tmp__2223, llvm_cbe_tmp__2225);
}


void _ZNSt6vectorIP11NExpressionSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2226, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2227, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2228) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17 llvm_cbe_tmp__2229;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2230;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2231;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2232;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2233;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2234;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2235;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17 llvm_cbe_tmp__2236;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2237;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2238;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2239;    /* Address-exposed local */
  uint32_t llvm_cbe_tmp__2240;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2241;
  uint64_t llvm_cbe_tmp__2242;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2243;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2244;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2245;
  uint64_t llvm_cbe_tmp__2246;
  uint64_t llvm_cbe_tmp__2247;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2248;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2249;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2250;
  uint64_t llvm_cbe_tmp__2251;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2252;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2253;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2254;
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__2255;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2256;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2257;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2258;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2259;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2260;
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__2261;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2262;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2263;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2264;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2265;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2266;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2267;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2268;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2269;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2270;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2271;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2272;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2273;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2274;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2275;
  uint64_t llvm_cbe_tmp__2276;

  *((&llvm_cbe_tmp__2229.field0)) = llvm_cbe_tmp__2227;
  llvm_cbe_tmp__2230 = llvm_cbe_tmp__2226;
  llvm_cbe_tmp__2231 = llvm_cbe_tmp__2228;
  llvm_cbe_tmp__2241 = llvm_cbe_tmp__2230;
  llvm_cbe_tmp__2242 = _ZNKSt6vectorIP11NExpressionSaIS1_EE12_M_check_lenEmPKc(llvm_cbe_tmp__2241, UINT64_C(1), ((&_OC_str_OC_8.array[((int32_t)0)])));
  llvm_cbe_tmp__2232 = llvm_cbe_tmp__2242;
  llvm_cbe_tmp__2243 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241))->field0))->field0));
  llvm_cbe_tmp__2233 = llvm_cbe_tmp__2243;
  llvm_cbe_tmp__2244 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241))->field0))->field1));
  llvm_cbe_tmp__2234 = llvm_cbe_tmp__2244;
  llvm_cbe_tmp__2245 = _ZNSt6vectorIP11NExpressionSaIS1_EE5beginEv(llvm_cbe_tmp__2241);
  *((&llvm_cbe_tmp__2236.field0)) = llvm_cbe_tmp__2245;
  llvm_cbe_tmp__2246 = _ZN9__gnu_cxxmiIPP11NExpressionSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_((&llvm_cbe_tmp__2229), (&llvm_cbe_tmp__2236));
  llvm_cbe_tmp__2235 = llvm_cbe_tmp__2246;
  llvm_cbe_tmp__2247 = llvm_cbe_tmp__2232;
  llvm_cbe_tmp__2248 = _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241)), llvm_cbe_tmp__2247);
  llvm_cbe_tmp__2237 = llvm_cbe_tmp__2248;
  llvm_cbe_tmp__2249 = llvm_cbe_tmp__2237;
  llvm_cbe_tmp__2238 = llvm_cbe_tmp__2249;
  llvm_cbe_tmp__2250 = llvm_cbe_tmp__2237;
  llvm_cbe_tmp__2251 = llvm_cbe_tmp__2235;
  llvm_cbe_tmp__2252 = llvm_cbe_tmp__2231;
  llvm_cbe_tmp__2253 = _ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__2252);
  _ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_((((struct l_struct_class_OC_std_KD__KD_allocator_OC_10*)((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241))->field0)))), ((&llvm_cbe_tmp__2250[((int64_t)llvm_cbe_tmp__2251)])), llvm_cbe_tmp__2253);
  goto llvm_cbe_tmp__2277;

llvm_cbe_tmp__2277:
  llvm_cbe_tmp__2238 = ((struct l_struct_class_OC_NExpression**)/*NULL*/0);
  llvm_cbe_tmp__2254 = llvm_cbe_tmp__2233;
  llvm_cbe_tmp__2255 = _ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__2229));
  llvm_cbe_tmp__2256 = *llvm_cbe_tmp__2255;
  llvm_cbe_tmp__2257 = llvm_cbe_tmp__2237;
  llvm_cbe_tmp__2258 = _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241)));
  llvm_cbe_tmp__2259 = _ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_(llvm_cbe_tmp__2254, llvm_cbe_tmp__2256, llvm_cbe_tmp__2257, llvm_cbe_tmp__2258);
  goto llvm_cbe_tmp__2278;

llvm_cbe_tmp__2278:
  llvm_cbe_tmp__2238 = llvm_cbe_tmp__2259;
  llvm_cbe_tmp__2260 = llvm_cbe_tmp__2238;
  llvm_cbe_tmp__2238 = ((&llvm_cbe_tmp__2260[((int32_t)1)]));
  llvm_cbe_tmp__2261 = _ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv((&llvm_cbe_tmp__2229));
  llvm_cbe_tmp__2262 = *llvm_cbe_tmp__2261;
  llvm_cbe_tmp__2263 = llvm_cbe_tmp__2234;
  llvm_cbe_tmp__2264 = llvm_cbe_tmp__2238;
  llvm_cbe_tmp__2265 = _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241)));
  llvm_cbe_tmp__2266 = _ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_(llvm_cbe_tmp__2262, llvm_cbe_tmp__2263, llvm_cbe_tmp__2264, llvm_cbe_tmp__2265);
  goto llvm_cbe_tmp__2279;

llvm_cbe_tmp__2279:
  llvm_cbe_tmp__2238 = llvm_cbe_tmp__2266;
  goto llvm_cbe_tmp__2280;

llvm_cbe_tmp__2280:
  llvm_cbe_tmp__2267 = llvm_cbe_tmp__2233;
  llvm_cbe_tmp__2268 = llvm_cbe_tmp__2234;
  llvm_cbe_tmp__2269 = _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241)));
  _ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(llvm_cbe_tmp__2267, llvm_cbe_tmp__2268, llvm_cbe_tmp__2269);
  llvm_cbe_tmp__2270 = llvm_cbe_tmp__2233;
  llvm_cbe_tmp__2271 = *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241))->field0))->field2));
  llvm_cbe_tmp__2272 = llvm_cbe_tmp__2233;
  _ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241)), llvm_cbe_tmp__2270, (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__2271)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__2272)))), UINT64_C(8))));
  llvm_cbe_tmp__2273 = llvm_cbe_tmp__2237;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241))->field0))->field0)) = llvm_cbe_tmp__2273;
  llvm_cbe_tmp__2274 = llvm_cbe_tmp__2238;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241))->field0))->field1)) = llvm_cbe_tmp__2274;
  llvm_cbe_tmp__2275 = llvm_cbe_tmp__2237;
  llvm_cbe_tmp__2276 = llvm_cbe_tmp__2232;
  *((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2241))->field0))->field2)) = ((&llvm_cbe_tmp__2275[((int64_t)llvm_cbe_tmp__2276)]));
}


struct l_struct_class_OC_NExpression** _ZNSt6vectorIP11NExpressionSaIS1_EE3endEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2281) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17 llvm_cbe_tmp__2282;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2283;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2284;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2285;

  llvm_cbe_tmp__2283 = llvm_cbe_tmp__2281;
  llvm_cbe_tmp__2284 = llvm_cbe_tmp__2283;
  _ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_((&llvm_cbe_tmp__2282), ((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2284))->field0))->field1)));
  llvm_cbe_tmp__2285 = *((&llvm_cbe_tmp__2282.field0));
  return llvm_cbe_tmp__2285;
}


void _ZN9__gnu_cxx13new_allocatorIP11NExpressionE9constructIS2_JRKS2_EEEvPT_DpOT0_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__2286, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2287, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2288) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__2289;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2290;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2291;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__2292;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2293;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2294;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2295;
  struct l_struct_class_OC_NExpression* llvm_cbe_tmp__2296;

  llvm_cbe_tmp__2289 = llvm_cbe_tmp__2286;
  llvm_cbe_tmp__2290 = llvm_cbe_tmp__2287;
  llvm_cbe_tmp__2291 = llvm_cbe_tmp__2288;
  llvm_cbe_tmp__2292 = llvm_cbe_tmp__2289;
  llvm_cbe_tmp__2293 = llvm_cbe_tmp__2290;
  llvm_cbe_tmp__2294 = llvm_cbe_tmp__2291;
  llvm_cbe_tmp__2295 = _ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(llvm_cbe_tmp__2294);
  llvm_cbe_tmp__2296 = *llvm_cbe_tmp__2295;
  *(((struct l_struct_class_OC_NExpression**)(((uint8_t*)llvm_cbe_tmp__2293)))) = llvm_cbe_tmp__2296;
}


struct l_struct_class_OC_NExpression** _ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2297) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2298;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2299;

  llvm_cbe_tmp__2298 = llvm_cbe_tmp__2297;
  llvm_cbe_tmp__2299 = llvm_cbe_tmp__2298;
  return llvm_cbe_tmp__2299;
}


uint64_t _ZNKSt6vectorIP11NExpressionSaIS1_EE12_M_check_lenEmPKc(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2300, uint64_t llvm_cbe_tmp__2301, uint8_t* llvm_cbe_tmp__2302) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2303;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2304;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2305;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2306;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2307;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2308;
  uint64_t llvm_cbe_tmp__2309;
  uint64_t llvm_cbe_tmp__2310;
  uint64_t llvm_cbe_tmp__2311;
  uint8_t* llvm_cbe_tmp__2312;
  uint64_t llvm_cbe_tmp__2313;
  uint64_t llvm_cbe_tmp__2314;
  uint64_t* llvm_cbe_tmp__2315;
  uint64_t llvm_cbe_tmp__2316;
  uint64_t llvm_cbe_tmp__2317;
  uint64_t llvm_cbe_tmp__2318;
  uint64_t llvm_cbe_tmp__2319;
  uint64_t llvm_cbe_tmp__2320;
  uint64_t llvm_cbe_tmp__2321;
  uint64_t llvm_cbe_tmp__2322;
  uint64_t llvm_cbe_tmp__2323;
  uint64_t llvm_cbe_tmp__2323__PHI_TEMPORARY;

  llvm_cbe_tmp__2303 = llvm_cbe_tmp__2300;
  llvm_cbe_tmp__2304 = llvm_cbe_tmp__2301;
  llvm_cbe_tmp__2305 = llvm_cbe_tmp__2302;
  llvm_cbe_tmp__2308 = llvm_cbe_tmp__2303;
  llvm_cbe_tmp__2309 = _ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(llvm_cbe_tmp__2308);
  llvm_cbe_tmp__2310 = _ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(llvm_cbe_tmp__2308);
  llvm_cbe_tmp__2311 = llvm_cbe_tmp__2304;
  if ((((((uint64_t)(llvm_sub_u64(llvm_cbe_tmp__2309, llvm_cbe_tmp__2310))) < ((uint64_t)llvm_cbe_tmp__2311))&1))) {
    goto llvm_cbe_tmp__2324;
  } else {
    goto llvm_cbe_tmp__2325;
  }

llvm_cbe_tmp__2324:
  llvm_cbe_tmp__2312 = llvm_cbe_tmp__2305;
  _ZSt20__throw_length_errorPKc(llvm_cbe_tmp__2312);
  __builtin_unreachable();

llvm_cbe_tmp__2325:
  llvm_cbe_tmp__2313 = _ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(llvm_cbe_tmp__2308);
  llvm_cbe_tmp__2314 = _ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(llvm_cbe_tmp__2308);
  llvm_cbe_tmp__2307 = llvm_cbe_tmp__2314;
  llvm_cbe_tmp__2315 = _ZSt3maxImERKT_S2_S2_((&llvm_cbe_tmp__2307), (&llvm_cbe_tmp__2304));
  llvm_cbe_tmp__2316 = *llvm_cbe_tmp__2315;
  llvm_cbe_tmp__2306 = (llvm_add_u64(llvm_cbe_tmp__2313, llvm_cbe_tmp__2316));
  llvm_cbe_tmp__2317 = llvm_cbe_tmp__2306;
  llvm_cbe_tmp__2318 = _ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(llvm_cbe_tmp__2308);
  if ((((((uint64_t)llvm_cbe_tmp__2317) < ((uint64_t)llvm_cbe_tmp__2318))&1))) {
    goto llvm_cbe_tmp__2326;
  } else {
    goto llvm_cbe_tmp__2327;
  }

llvm_cbe_tmp__2327:
  llvm_cbe_tmp__2319 = llvm_cbe_tmp__2306;
  llvm_cbe_tmp__2320 = _ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(llvm_cbe_tmp__2308);
  if ((((((uint64_t)llvm_cbe_tmp__2319) > ((uint64_t)llvm_cbe_tmp__2320))&1))) {
    goto llvm_cbe_tmp__2326;
  } else {
    goto llvm_cbe_tmp__2328;
  }

llvm_cbe_tmp__2326:
  llvm_cbe_tmp__2321 = _ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(llvm_cbe_tmp__2308);
  llvm_cbe_tmp__2323__PHI_TEMPORARY = llvm_cbe_tmp__2321;   /* for PHI node */
  goto llvm_cbe_tmp__2329;

llvm_cbe_tmp__2328:
  llvm_cbe_tmp__2322 = llvm_cbe_tmp__2306;
  llvm_cbe_tmp__2323__PHI_TEMPORARY = llvm_cbe_tmp__2322;   /* for PHI node */
  goto llvm_cbe_tmp__2329;

llvm_cbe_tmp__2329:
  llvm_cbe_tmp__2323 = llvm_cbe_tmp__2323__PHI_TEMPORARY;
  return llvm_cbe_tmp__2323;
}


uint64_t _ZN9__gnu_cxxmiIPP11NExpressionSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2330, struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2331) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2332;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2333;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2334;
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__2335;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2336;
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2337;
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__2338;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2339;

  llvm_cbe_tmp__2332 = llvm_cbe_tmp__2330;
  llvm_cbe_tmp__2333 = llvm_cbe_tmp__2331;
  llvm_cbe_tmp__2334 = llvm_cbe_tmp__2332;
  llvm_cbe_tmp__2335 = _ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(llvm_cbe_tmp__2334);
  llvm_cbe_tmp__2336 = *llvm_cbe_tmp__2335;
  llvm_cbe_tmp__2337 = llvm_cbe_tmp__2333;
  llvm_cbe_tmp__2338 = _ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(llvm_cbe_tmp__2337);
  llvm_cbe_tmp__2339 = *llvm_cbe_tmp__2338;
  return (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__2336)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__2339)))), UINT64_C(8)));
}


struct l_struct_class_OC_NExpression** _ZNSt6vectorIP11NExpressionSaIS1_EE5beginEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2340) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17 llvm_cbe_tmp__2341;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2342;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2343;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2344;

  llvm_cbe_tmp__2342 = llvm_cbe_tmp__2340;
  llvm_cbe_tmp__2343 = llvm_cbe_tmp__2342;
  _ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_((&llvm_cbe_tmp__2341), ((&((&(((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2343))->field0))->field0)));
  llvm_cbe_tmp__2344 = *((&llvm_cbe_tmp__2341.field0));
  return llvm_cbe_tmp__2344;
}


struct l_struct_class_OC_NExpression** _ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2345, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2346, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2347, struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2348) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2349;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2350;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2351;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2352;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2353;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2354;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2355;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2356;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2357;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2358;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2359;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2360;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2361;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2362;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2363;

  llvm_cbe_tmp__2349 = llvm_cbe_tmp__2345;
  llvm_cbe_tmp__2350 = llvm_cbe_tmp__2346;
  llvm_cbe_tmp__2351 = llvm_cbe_tmp__2347;
  llvm_cbe_tmp__2352 = llvm_cbe_tmp__2348;
  llvm_cbe_tmp__2355 = llvm_cbe_tmp__2349;
  llvm_cbe_tmp__2356 = _ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_(llvm_cbe_tmp__2355);
  *((&llvm_cbe_tmp__2353.field0)) = llvm_cbe_tmp__2356;
  llvm_cbe_tmp__2357 = llvm_cbe_tmp__2350;
  llvm_cbe_tmp__2358 = _ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_(llvm_cbe_tmp__2357);
  *((&llvm_cbe_tmp__2354.field0)) = llvm_cbe_tmp__2358;
  llvm_cbe_tmp__2359 = llvm_cbe_tmp__2351;
  llvm_cbe_tmp__2360 = llvm_cbe_tmp__2352;
  llvm_cbe_tmp__2361 = *((&llvm_cbe_tmp__2353.field0));
  llvm_cbe_tmp__2362 = *((&llvm_cbe_tmp__2354.field0));
  llvm_cbe_tmp__2363 = _ZSt22__uninitialized_copy_aISt13move_iteratorIPP11NExpressionES3_S2_ET0_T_S6_S5_RSaIT1_E(llvm_cbe_tmp__2361, llvm_cbe_tmp__2362, llvm_cbe_tmp__2359, llvm_cbe_tmp__2360);
  return llvm_cbe_tmp__2363;
}


struct l_struct_class_OC_NExpression*** _ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2364) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2365;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2366;

  llvm_cbe_tmp__2365 = llvm_cbe_tmp__2364;
  llvm_cbe_tmp__2366 = llvm_cbe_tmp__2365;
  return ((&llvm_cbe_tmp__2366->field0));
}


void _ZNSt16allocator_traitsISaIP11NExpressionEE7destroyIS1_EEvRS2_PT_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2367, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2368) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2369;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2370;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2371;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2372;

  llvm_cbe_tmp__2369 = llvm_cbe_tmp__2367;
  llvm_cbe_tmp__2370 = llvm_cbe_tmp__2368;
  llvm_cbe_tmp__2371 = llvm_cbe_tmp__2369;
  llvm_cbe_tmp__2372 = llvm_cbe_tmp__2370;
  _ZN9__gnu_cxx13new_allocatorIP11NExpressionE7destroyIS2_EEvPT_((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__2371)), llvm_cbe_tmp__2372);
}


uint64_t _ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2373) {
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2374;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_vector_OC_8* llvm_cbe_tmp__2375;
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2376;
  uint64_t llvm_cbe_tmp__2377;

  llvm_cbe_tmp__2374 = llvm_cbe_tmp__2373;
  llvm_cbe_tmp__2375 = llvm_cbe_tmp__2374;
  llvm_cbe_tmp__2376 = _ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv((((struct l_struct_struct_OC_std_KD__KD__Vector_base_OC_9*)llvm_cbe_tmp__2375)));
  llvm_cbe_tmp__2377 = _ZNSt16allocator_traitsISaIP11NExpressionEE8max_sizeERKS2_(llvm_cbe_tmp__2376);
  return llvm_cbe_tmp__2377;
}


uint64_t _ZNSt16allocator_traitsISaIP11NExpressionEE8max_sizeERKS2_(struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2378) {
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2379;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2380;
  uint64_t llvm_cbe_tmp__2381;

  llvm_cbe_tmp__2379 = llvm_cbe_tmp__2378;
  llvm_cbe_tmp__2380 = llvm_cbe_tmp__2379;
  llvm_cbe_tmp__2381 = _ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv((((struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11*)llvm_cbe_tmp__2380)));
  return llvm_cbe_tmp__2381;
}


void _ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_(struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2382, struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__2383) {
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2384;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__2385;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD___normal_iterator_OC_17* llvm_cbe_tmp__2386;
  struct l_struct_class_OC_NExpression*** llvm_cbe_tmp__2387;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2388;

  llvm_cbe_tmp__2384 = llvm_cbe_tmp__2382;
  llvm_cbe_tmp__2385 = llvm_cbe_tmp__2383;
  llvm_cbe_tmp__2386 = llvm_cbe_tmp__2384;
  llvm_cbe_tmp__2387 = llvm_cbe_tmp__2385;
  llvm_cbe_tmp__2388 = *llvm_cbe_tmp__2387;
  *((&llvm_cbe_tmp__2386->field0)) = llvm_cbe_tmp__2388;
}


struct l_struct_class_OC_NExpression** _ZSt22__uninitialized_copy_aISt13move_iteratorIPP11NExpressionES3_S2_ET0_T_S6_S5_RSaIT1_E(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2389, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2390, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2391, struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2392) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2393;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2394;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2395;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_allocator_OC_10* llvm_cbe_tmp__2396;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2397;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2398;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2399;
  uint8_t* llvm_cbe_tmp__2400;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2401;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2402;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2403;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2404;

  *((&llvm_cbe_tmp__2393.field0)) = llvm_cbe_tmp__2389;
  *((&llvm_cbe_tmp__2394.field0)) = llvm_cbe_tmp__2390;
  llvm_cbe_tmp__2395 = llvm_cbe_tmp__2391;
  llvm_cbe_tmp__2396 = llvm_cbe_tmp__2392;
  llvm_cbe_tmp__2399 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2397))), (((uint8_t*)(&llvm_cbe_tmp__2393))), UINT64_C(8));
  llvm_cbe_tmp__2400 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2398))), (((uint8_t*)(&llvm_cbe_tmp__2394))), UINT64_C(8));
  llvm_cbe_tmp__2401 = llvm_cbe_tmp__2395;
  llvm_cbe_tmp__2402 = *((&llvm_cbe_tmp__2397.field0));
  llvm_cbe_tmp__2403 = *((&llvm_cbe_tmp__2398.field0));
  llvm_cbe_tmp__2404 = _ZSt18uninitialized_copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(llvm_cbe_tmp__2402, llvm_cbe_tmp__2403, llvm_cbe_tmp__2401);
  return llvm_cbe_tmp__2404;
}


struct l_struct_class_OC_NExpression** _ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2405) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2406;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2407;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2408;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2409;

  llvm_cbe_tmp__2407 = llvm_cbe_tmp__2405;
  llvm_cbe_tmp__2408 = llvm_cbe_tmp__2407;
  _ZNSt13move_iteratorIPP11NExpressionEC2ES2_((&llvm_cbe_tmp__2406), llvm_cbe_tmp__2408);
  llvm_cbe_tmp__2409 = *((&llvm_cbe_tmp__2406.field0));
  return llvm_cbe_tmp__2409;
}


struct l_struct_class_OC_NExpression** _ZSt18uninitialized_copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2410, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2411, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2412) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2413;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2414;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2415;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__2416;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2417;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2418;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2419;
  uint8_t* llvm_cbe_tmp__2420;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2421;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2422;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2423;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2424;

  *((&llvm_cbe_tmp__2413.field0)) = llvm_cbe_tmp__2410;
  *((&llvm_cbe_tmp__2414.field0)) = llvm_cbe_tmp__2411;
  llvm_cbe_tmp__2415 = llvm_cbe_tmp__2412;
  llvm_cbe_tmp__2416 = 1;
  llvm_cbe_tmp__2419 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2417))), (((uint8_t*)(&llvm_cbe_tmp__2413))), UINT64_C(8));
  llvm_cbe_tmp__2420 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2418))), (((uint8_t*)(&llvm_cbe_tmp__2414))), UINT64_C(8));
  llvm_cbe_tmp__2421 = llvm_cbe_tmp__2415;
  llvm_cbe_tmp__2422 = *((&llvm_cbe_tmp__2417.field0));
  llvm_cbe_tmp__2423 = *((&llvm_cbe_tmp__2418.field0));
  llvm_cbe_tmp__2424 = _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP11NExpressionES5_EET0_T_S8_S7_(llvm_cbe_tmp__2422, llvm_cbe_tmp__2423, llvm_cbe_tmp__2421);
  return llvm_cbe_tmp__2424;
}


struct l_struct_class_OC_NExpression** _ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP11NExpressionES5_EET0_T_S8_S7_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2425, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2426, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2427) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2428;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2429;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2430;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2431;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2432;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2433;
  uint8_t* llvm_cbe_tmp__2434;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2435;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2436;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2437;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2438;

  *((&llvm_cbe_tmp__2428.field0)) = llvm_cbe_tmp__2425;
  *((&llvm_cbe_tmp__2429.field0)) = llvm_cbe_tmp__2426;
  llvm_cbe_tmp__2430 = llvm_cbe_tmp__2427;
  llvm_cbe_tmp__2433 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2431))), (((uint8_t*)(&llvm_cbe_tmp__2428))), UINT64_C(8));
  llvm_cbe_tmp__2434 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2432))), (((uint8_t*)(&llvm_cbe_tmp__2429))), UINT64_C(8));
  llvm_cbe_tmp__2435 = llvm_cbe_tmp__2430;
  llvm_cbe_tmp__2436 = *((&llvm_cbe_tmp__2431.field0));
  llvm_cbe_tmp__2437 = *((&llvm_cbe_tmp__2432.field0));
  llvm_cbe_tmp__2438 = _ZSt4copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(llvm_cbe_tmp__2436, llvm_cbe_tmp__2437, llvm_cbe_tmp__2435);
  return llvm_cbe_tmp__2438;
}


struct l_struct_class_OC_NExpression** _ZSt4copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2439, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2440, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2441) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2442;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2443;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2444;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2445;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2446;    /* Address-exposed local */
  uint8_t* llvm_cbe_tmp__2447;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2448;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2449;
  uint8_t* llvm_cbe_tmp__2450;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2451;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2452;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2453;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2454;

  *((&llvm_cbe_tmp__2442.field0)) = llvm_cbe_tmp__2439;
  *((&llvm_cbe_tmp__2443.field0)) = llvm_cbe_tmp__2440;
  llvm_cbe_tmp__2444 = llvm_cbe_tmp__2441;
  llvm_cbe_tmp__2447 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2445))), (((uint8_t*)(&llvm_cbe_tmp__2442))), UINT64_C(8));
  llvm_cbe_tmp__2448 = *((&llvm_cbe_tmp__2445.field0));
  llvm_cbe_tmp__2449 = _ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(llvm_cbe_tmp__2448);
  llvm_cbe_tmp__2450 = memcpy((((uint8_t*)(&llvm_cbe_tmp__2446))), (((uint8_t*)(&llvm_cbe_tmp__2443))), UINT64_C(8));
  llvm_cbe_tmp__2451 = *((&llvm_cbe_tmp__2446.field0));
  llvm_cbe_tmp__2452 = _ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(llvm_cbe_tmp__2451);
  llvm_cbe_tmp__2453 = llvm_cbe_tmp__2444;
  llvm_cbe_tmp__2454 = _ZSt14__copy_move_a2ILb1EPP11NExpressionS2_ET1_T0_S4_S3_(llvm_cbe_tmp__2449, llvm_cbe_tmp__2452, llvm_cbe_tmp__2453);
  return llvm_cbe_tmp__2454;
}


struct l_struct_class_OC_NExpression** _ZSt14__copy_move_a2ILb1EPP11NExpressionS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2455, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2456, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2457) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2458;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2459;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2460;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2461;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2462;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2463;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2464;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2465;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2466;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2467;

  llvm_cbe_tmp__2458 = llvm_cbe_tmp__2455;
  llvm_cbe_tmp__2459 = llvm_cbe_tmp__2456;
  llvm_cbe_tmp__2460 = llvm_cbe_tmp__2457;
  llvm_cbe_tmp__2461 = llvm_cbe_tmp__2458;
  llvm_cbe_tmp__2462 = _ZSt12__niter_baseIPP11NExpressionET_S3_(llvm_cbe_tmp__2461);
  llvm_cbe_tmp__2463 = llvm_cbe_tmp__2459;
  llvm_cbe_tmp__2464 = _ZSt12__niter_baseIPP11NExpressionET_S3_(llvm_cbe_tmp__2463);
  llvm_cbe_tmp__2465 = llvm_cbe_tmp__2460;
  llvm_cbe_tmp__2466 = _ZSt12__niter_baseIPP11NExpressionET_S3_(llvm_cbe_tmp__2465);
  llvm_cbe_tmp__2467 = _ZSt13__copy_move_aILb1EPP11NExpressionS2_ET1_T0_S4_S3_(llvm_cbe_tmp__2462, llvm_cbe_tmp__2464, llvm_cbe_tmp__2466);
  return llvm_cbe_tmp__2467;
}


struct l_struct_class_OC_NExpression** _ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2468) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18 llvm_cbe_tmp__2469;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2470;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2471;

  *((&llvm_cbe_tmp__2469.field0)) = llvm_cbe_tmp__2468;
  llvm_cbe_tmp__2470 = _ZNKSt13move_iteratorIPP11NExpressionE4baseEv((&llvm_cbe_tmp__2469));
  llvm_cbe_tmp__2471 = _ZSt12__miter_baseIPP11NExpressionET_S3_(llvm_cbe_tmp__2470);
  return llvm_cbe_tmp__2471;
}


struct l_struct_class_OC_NExpression** _ZSt13__copy_move_aILb1EPP11NExpressionS2_ET1_T0_S4_S3_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2472, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2473, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2474) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2475;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2476;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2477;    /* Address-exposed local */
  uint8_t llvm_cbe_tmp__2478;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2479;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2480;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2481;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2482;

  llvm_cbe_tmp__2475 = llvm_cbe_tmp__2472;
  llvm_cbe_tmp__2476 = llvm_cbe_tmp__2473;
  llvm_cbe_tmp__2477 = llvm_cbe_tmp__2474;
  llvm_cbe_tmp__2478 = 1;
  llvm_cbe_tmp__2479 = llvm_cbe_tmp__2475;
  llvm_cbe_tmp__2480 = llvm_cbe_tmp__2476;
  llvm_cbe_tmp__2481 = llvm_cbe_tmp__2477;
  llvm_cbe_tmp__2482 = _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(llvm_cbe_tmp__2479, llvm_cbe_tmp__2480, llvm_cbe_tmp__2481);
  return llvm_cbe_tmp__2482;
}


struct l_struct_class_OC_NExpression** _ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2483, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2484, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2485) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2486;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2487;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2488;    /* Address-exposed local */
  uint64_t llvm_cbe_tmp__2489;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2490;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2491;
  uint64_t llvm_cbe_tmp__2492;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2493;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2494;
  uint64_t llvm_cbe_tmp__2495;
  uint8_t* llvm_cbe_tmp__2496;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2497;
  uint64_t llvm_cbe_tmp__2498;

  llvm_cbe_tmp__2486 = llvm_cbe_tmp__2483;
  llvm_cbe_tmp__2487 = llvm_cbe_tmp__2484;
  llvm_cbe_tmp__2488 = llvm_cbe_tmp__2485;
  llvm_cbe_tmp__2490 = llvm_cbe_tmp__2487;
  llvm_cbe_tmp__2491 = llvm_cbe_tmp__2486;
  llvm_cbe_tmp__2489 = (llvm_sdiv_u64((llvm_sub_u64((((uint64_t)(uintptr_t)llvm_cbe_tmp__2490)), (((uint64_t)(uintptr_t)llvm_cbe_tmp__2491)))), UINT64_C(8)));
  llvm_cbe_tmp__2492 = llvm_cbe_tmp__2489;
  if ((((llvm_cbe_tmp__2492 != UINT64_C(0))&1))) {
    goto llvm_cbe_tmp__2499;
  } else {
    goto llvm_cbe_tmp__2500;
  }

llvm_cbe_tmp__2499:
  llvm_cbe_tmp__2493 = llvm_cbe_tmp__2488;
  llvm_cbe_tmp__2494 = llvm_cbe_tmp__2486;
  llvm_cbe_tmp__2495 = llvm_cbe_tmp__2489;
  llvm_cbe_tmp__2496 = memmove((((uint8_t*)llvm_cbe_tmp__2493)), (((uint8_t*)llvm_cbe_tmp__2494)), (llvm_mul_u64(UINT64_C(8), llvm_cbe_tmp__2495)));
  goto llvm_cbe_tmp__2500;

llvm_cbe_tmp__2500:
  llvm_cbe_tmp__2497 = llvm_cbe_tmp__2488;
  llvm_cbe_tmp__2498 = llvm_cbe_tmp__2489;
  return ((&llvm_cbe_tmp__2497[((int64_t)llvm_cbe_tmp__2498)]));
}


struct l_struct_class_OC_NExpression** _ZSt12__miter_baseIPP11NExpressionET_S3_(struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2501) {
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2502;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2503;

  llvm_cbe_tmp__2502 = llvm_cbe_tmp__2501;
  llvm_cbe_tmp__2503 = llvm_cbe_tmp__2502;
  return llvm_cbe_tmp__2503;
}


struct l_struct_class_OC_NExpression** _ZNKSt13move_iteratorIPP11NExpressionE4baseEv(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18* llvm_cbe_tmp__2504) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18* llvm_cbe_tmp__2505;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18* llvm_cbe_tmp__2506;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2507;

  llvm_cbe_tmp__2505 = llvm_cbe_tmp__2504;
  llvm_cbe_tmp__2506 = llvm_cbe_tmp__2505;
  llvm_cbe_tmp__2507 = *((&llvm_cbe_tmp__2506->field0));
  return llvm_cbe_tmp__2507;
}


void _ZNSt13move_iteratorIPP11NExpressionEC2ES2_(struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18* llvm_cbe_tmp__2508, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2509) {
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18* llvm_cbe_tmp__2510;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2511;    /* Address-exposed local */
  struct l_struct_class_OC_std_KD__KD_move_iterator_OC_18* llvm_cbe_tmp__2512;
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2513;

  llvm_cbe_tmp__2510 = llvm_cbe_tmp__2508;
  llvm_cbe_tmp__2511 = llvm_cbe_tmp__2509;
  llvm_cbe_tmp__2512 = llvm_cbe_tmp__2510;
  llvm_cbe_tmp__2513 = llvm_cbe_tmp__2511;
  *((&llvm_cbe_tmp__2512->field0)) = llvm_cbe_tmp__2513;
}


void _ZN9__gnu_cxx13new_allocatorIP11NExpressionE7destroyIS2_EEvPT_(struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__2514, struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2515) {
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__2516;    /* Address-exposed local */
  struct l_struct_class_OC_NExpression** llvm_cbe_tmp__2517;    /* Address-exposed local */
  struct l_struct_class_OC___gnu_cxx_KD__KD_new_allocator_OC_11* llvm_cbe_tmp__2518;

  llvm_cbe_tmp__2516 = llvm_cbe_tmp__2514;
  llvm_cbe_tmp__2517 = llvm_cbe_tmp__2515;
  llvm_cbe_tmp__2518 = llvm_cbe_tmp__2516;
}


static void _GLOBAL__sub_I_parser_OC_cpp(void) {
  __cxx_global_var_init();
}

