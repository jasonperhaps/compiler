; ModuleID = 'tokens.cpp'
source_filename = "tokens.cpp"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type opaque
%struct._IO_codecvt = type opaque
%struct._IO_wide_data = type opaque
%"class.std::ios_base::Init" = type { i8 }
%struct.yy_buffer_state = type { %struct._IO_FILE*, i8*, i8*, i32, i32, i32, i32, i32, i32, i32, i32, i32 }
%union.YYSTYPE = type { %class.Node* }
%class.Node = type { i32 (...)** }
%"class.std::allocator" = type { i8 }
%"class.std::__cxx11::basic_string" = type { %"struct.std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider", i64, %union.anon }
%"struct.std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" = type { i8* }
%union.anon = type { i64, [8 x i8] }

@yyleng = dso_local global i32 0, align 4
@yyin = dso_local global %struct._IO_FILE* null, align 8
@yyout = dso_local global %struct._IO_FILE* null, align 8
@yylineno = dso_local global i32 1, align 4
@yy_flex_debug = dso_local global i32 0, align 4
@yytext = dso_local global i8* null, align 8
@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external hidden global i8
@_ZL7yy_init = internal global i32 0, align 4
@_ZL8yy_start = internal global i32 0, align 4
@stdin = external dso_local global %struct._IO_FILE*, align 8
@stdout = external dso_local global %struct._IO_FILE*, align 8
@_ZL15yy_buffer_stack = internal global %struct.yy_buffer_state** null, align 8
@_ZL19yy_buffer_stack_top = internal global i64 0, align 8
@_ZL10yy_c_buf_p = internal global i8* null, align 8
@_ZL12yy_hold_char = internal global i8 0, align 1
@_ZL5yy_ec = internal constant [256 x i8] c"\00\01\01\01\01\01\01\01\01\02\03\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\02\04\01\01\01\01\01\01\05\06\07\08\09\0A\0B\0C\0D\0D\0D\0D\0D\0D\0D\0D\0D\0D\01\01\0E\0F\10\01\01\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\01\01\01\01\11\01\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\11\12\01\13\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01", align 16
@_ZL9yy_accept = internal constant [33 x i16] [i16 0, i16 0, i16 0, i16 24, i16 22, i16 1, i16 1, i16 22, i16 12, i16 13, i16 20, i16 18, i16 17, i16 19, i16 16, i16 21, i16 4, i16 8, i16 5, i16 10, i16 2, i16 14, i16 15, i16 7, i16 3, i16 3, i16 9, i16 6, i16 11, i16 2, i16 3, i16 3, i16 0], align 16
@_ZL23yy_last_accepting_state = internal global i32 0, align 4
@_ZL22yy_last_accepting_cpos = internal global i8* null, align 8
@_ZL6yy_chk = internal constant [55 x i16] [i16 0, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 20, i16 29, i16 33, i16 31, i16 20, i16 29, i16 30, i16 25, i16 24, i16 19, i16 18, i16 17, i16 16, i16 7, i16 3, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32], align 16
@_ZL7yy_base = internal constant [34 x i16] [i16 0, i16 0, i16 0, i16 34, i16 35, i16 35, i16 35, i16 18, i16 35, i16 35, i16 35, i16 35, i16 35, i16 35, i16 35, i16 35, i16 19, i16 16, i16 15, i16 14, i16 7, i16 35, i16 35, i16 35, i16 15, i16 14, i16 35, i16 35, i16 35, i16 8, i16 13, i16 10, i16 35, i16 21], align 16
@_ZL6yy_def = internal constant [34 x i16] [i16 0, i16 32, i16 1, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 33, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 33, i16 32, i16 32, i16 32, i16 32, i16 32, i16 33, i16 0, i16 32], align 16
@_ZL7yy_meta = internal constant [20 x i8] c"\00\01\01\02\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01\01", align 16
@_ZL6yy_nxt = internal constant [55 x i16] [i16 0, i16 4, i16 5, i16 6, i16 7, i16 8, i16 9, i16 10, i16 11, i16 12, i16 13, i16 14, i16 15, i16 16, i16 17, i16 18, i16 19, i16 20, i16 21, i16 22, i16 29, i16 29, i16 24, i16 31, i16 29, i16 29, i16 30, i16 31, i16 30, i16 28, i16 27, i16 26, i16 25, i16 23, i16 32, i16 3, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32, i16 32], align 16
@.str = private unnamed_addr constant [36 x i8] c"%s\09 -- TIDENTIFIER\09 TOKEN_ID is %d\0A\00", align 1
@yylval = external dso_local global %union.YYSTYPE, align 8
@.str.1 = private unnamed_addr constant [32 x i8] c"%s\09 -- TDOUBLE\09 TOKEN_ID is %d\0A\00", align 1
@.str.2 = private unnamed_addr constant [31 x i8] c"%s\09 -- TEQUAL\09 TOKEN_ID is %d\0A\00", align 1
@.str.3 = private unnamed_addr constant [29 x i8] c"%s\09 -- TCEQ\09 TOKEN_ID is %d\0A\00", align 1
@.str.4 = private unnamed_addr constant [29 x i8] c"%s\09 -- TCNE\09 TOKEN_ID is %d\0A\00", align 1
@.str.5 = private unnamed_addr constant [29 x i8] c"%s\09 -- TCLT\09 TOKEN_ID is %d\0A\00", align 1
@.str.6 = private unnamed_addr constant [29 x i8] c"%s\09 -- TCLE\09 TOKEN_ID is %d\0A\00", align 1
@.str.7 = private unnamed_addr constant [29 x i8] c"%s\09 -- TCGT\09 TOKEN_ID is %d\0A\00", align 1
@.str.8 = private unnamed_addr constant [29 x i8] c"%s\09 -- TCGE\09 TOKEN_ID is %d\0A\00", align 1
@.str.9 = private unnamed_addr constant [32 x i8] c"%s\09 -- TLPAREN\09 TOKEN_ID is %d\0A\00", align 1
@.str.10 = private unnamed_addr constant [32 x i8] c"%s\09 -- TRPAREN\09 TOKEN_ID is %d\0A\00", align 1
@.str.11 = private unnamed_addr constant [32 x i8] c"%s\09 -- TLBRACE\09 TOKEN_ID is %d\0A\00", align 1
@.str.12 = private unnamed_addr constant [32 x i8] c"%s\09 -- TRBRACE\09 TOKEN_ID is %d\0A\00", align 1
@.str.13 = private unnamed_addr constant [29 x i8] c"%s\09 -- TDOT\09 TOKEN_ID is %d\0A\00", align 1
@.str.14 = private unnamed_addr constant [31 x i8] c"%s\09 -- TCOMMA\09 TOKEN_ID is %d\0A\00", align 1
@.str.15 = private unnamed_addr constant [30 x i8] c"%s\09 -- TPLUS\09 TOKEN_ID is %d\0A\00", align 1
@.str.16 = private unnamed_addr constant [31 x i8] c"%s\09 -- TMINUS\09 TOKEN_ID is %d\0A\00", align 1
@.str.17 = private unnamed_addr constant [29 x i8] c"%s\09 -- TMUL\09 TOKEN_ID is %d\0A\00", align 1
@.str.18 = private unnamed_addr constant [29 x i8] c"%s\09 -- TDIV\09 TOKEN_ID is %d\0A\00", align 1
@.str.19 = private unnamed_addr constant [16 x i8] c"Unknown token!\0A\00", align 1
@_ZL10yy_n_chars = internal global i32 0, align 4
@_ZL27yy_did_buffer_switch_on_eof = internal global i32 0, align 4
@.str.20 = private unnamed_addr constant [51 x i8] c"fatal flex scanner internal error--no action found\00", align 1
@.str.21 = private unnamed_addr constant [44 x i8] c"out of dynamic memory in yy_create_buffer()\00", align 1
@.str.22 = private unnamed_addr constant [42 x i8] c"out of dynamic memory in yy_scan_buffer()\00", align 1
@.str.23 = private unnamed_addr constant [41 x i8] c"out of dynamic memory in yy_scan_bytes()\00", align 1
@.str.24 = private unnamed_addr constant [30 x i8] c"bad buffer in yy_scan_bytes()\00", align 1
@.str.25 = private unnamed_addr constant [56 x i8] c"fatal flex scanner internal error--end of buffer missed\00", align 1
@.str.26 = private unnamed_addr constant [44 x i8] c"fatal error - scanner input buffer overflow\00", align 1
@.str.27 = private unnamed_addr constant [29 x i8] c"input in flex scanner failed\00", align 1
@.str.28 = private unnamed_addr constant [46 x i8] c"out of dynamic memory in yy_get_next_buffer()\00", align 1
@.str.29 = private unnamed_addr constant [49 x i8] c"out of dynamic memory in yyensure_buffer_stack()\00", align 1
@_ZL19yy_buffer_stack_max = internal global i64 0, align 8
@stderr = external dso_local global %struct._IO_FILE*, align 8
@.str.30 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_tokens.cpp, i8* null }]

; Function Attrs: noinline uwtable
define internal void @__cxx_global_var_init() #0 section ".text.startup" {
  call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  %1 = call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init", %"class.std::ios_base::Init"* @_ZStL8__ioinit, i32 0, i32 0), i8* @__dso_handle) #3
  ret void
}

declare dso_local void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*) unnamed_addr #1

; Function Attrs: nounwind
declare dso_local void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*) unnamed_addr #2

; Function Attrs: nounwind
declare dso_local i32 @__cxa_atexit(void (i8*)*, i8*, i8*) #3

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @yywrap() #4 {
  %1 = alloca i32, align 4
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %3 = load i32, i32* %1, align 4
  ret i32 %3
}

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #5

; Function Attrs: noinline optnone uwtable
define dso_local i32 @_Z5yylexv() #6 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  %5 = alloca i32, align 4
  %6 = alloca i8, align 1
  %7 = alloca %"class.std::allocator", align 1
  %8 = alloca i8*
  %9 = alloca i32
  %10 = alloca i1, align 1
  %11 = alloca %"class.std::allocator", align 1
  %12 = alloca i1, align 1
  %13 = alloca %"class.std::allocator", align 1
  %14 = alloca i1, align 1
  %15 = alloca %"class.std::allocator", align 1
  %16 = alloca i1, align 1
  %17 = alloca %"class.std::allocator", align 1
  %18 = alloca i1, align 1
  %19 = alloca %"class.std::allocator", align 1
  %20 = alloca i1, align 1
  %21 = alloca %"class.std::allocator", align 1
  %22 = alloca i1, align 1
  %23 = alloca %"class.std::allocator", align 1
  %24 = alloca i1, align 1
  %25 = alloca %"class.std::allocator", align 1
  %26 = alloca i1, align 1
  %27 = alloca %"class.std::allocator", align 1
  %28 = alloca i1, align 1
  %29 = alloca %"class.std::allocator", align 1
  %30 = alloca i1, align 1
  %31 = alloca %"class.std::allocator", align 1
  %32 = alloca i1, align 1
  %33 = alloca %"class.std::allocator", align 1
  %34 = alloca i1, align 1
  %35 = alloca %"class.std::allocator", align 1
  %36 = alloca i1, align 1
  %37 = alloca %"class.std::allocator", align 1
  %38 = alloca i1, align 1
  %39 = alloca %"class.std::allocator", align 1
  %40 = alloca i1, align 1
  %41 = alloca %"class.std::allocator", align 1
  %42 = alloca i1, align 1
  %43 = alloca %"class.std::allocator", align 1
  %44 = alloca i1, align 1
  %45 = alloca %"class.std::allocator", align 1
  %46 = alloca i1, align 1
  %47 = alloca %"class.std::allocator", align 1
  %48 = alloca i1, align 1
  %49 = alloca i32, align 4
  %50 = alloca i32, align 4
  %51 = load i32, i32* @_ZL7yy_init, align 4
  %52 = icmp ne i32 %51, 0
  br i1 %52, label %86, label %53

; <label>:53:                                     ; preds = %0
  store i32 1, i32* @_ZL7yy_init, align 4
  %54 = load i32, i32* @_ZL8yy_start, align 4
  %55 = icmp ne i32 %54, 0
  br i1 %55, label %57, label %56

; <label>:56:                                     ; preds = %53
  store i32 1, i32* @_ZL8yy_start, align 4
  br label %57

; <label>:57:                                     ; preds = %56, %53
  %58 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %59 = icmp ne %struct._IO_FILE* %58, null
  br i1 %59, label %62, label %60

; <label>:60:                                     ; preds = %57
  %61 = load %struct._IO_FILE*, %struct._IO_FILE** @stdin, align 8
  store %struct._IO_FILE* %61, %struct._IO_FILE** @yyin, align 8
  br label %62

; <label>:62:                                     ; preds = %60, %57
  %63 = load %struct._IO_FILE*, %struct._IO_FILE** @yyout, align 8
  %64 = icmp ne %struct._IO_FILE* %63, null
  br i1 %64, label %67, label %65

; <label>:65:                                     ; preds = %62
  %66 = load %struct._IO_FILE*, %struct._IO_FILE** @stdout, align 8
  store %struct._IO_FILE* %66, %struct._IO_FILE** @yyout, align 8
  br label %67

; <label>:67:                                     ; preds = %65, %62
  %68 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %69 = icmp ne %struct.yy_buffer_state** %68, null
  br i1 %69, label %70, label %75

; <label>:70:                                     ; preds = %67
  %71 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %72 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %73 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %71, i64 %72
  %74 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %73, align 8
  br label %76

; <label>:75:                                     ; preds = %67
  br label %76

; <label>:76:                                     ; preds = %75, %70
  %77 = phi %struct.yy_buffer_state* [ %74, %70 ], [ null, %75 ]
  %78 = icmp ne %struct.yy_buffer_state* %77, null
  br i1 %78, label %85, label %79

; <label>:79:                                     ; preds = %76
  call void @_ZL21yyensure_buffer_stackv()
  %80 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %81 = call %struct.yy_buffer_state* @_Z16yy_create_bufferP8_IO_FILEi(%struct._IO_FILE* %80, i32 16384)
  %82 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %83 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %84 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %82, i64 %83
  store %struct.yy_buffer_state* %81, %struct.yy_buffer_state** %84, align 8
  br label %85

; <label>:85:                                     ; preds = %79, %76
  call void @_ZL20yy_load_buffer_statev()
  br label %86

; <label>:86:                                     ; preds = %85, %0
  br label %87

; <label>:87:                                     ; preds = %86, %642
  %88 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  store i8* %88, i8** %3, align 8
  %89 = load i8, i8* @_ZL12yy_hold_char, align 1
  %90 = load i8*, i8** %3, align 8
  store i8 %89, i8* %90, align 1
  %91 = load i8*, i8** %3, align 8
  store i8* %91, i8** %4, align 8
  %92 = load i32, i32* @_ZL8yy_start, align 4
  store i32 %92, i32* %2, align 4
  br label %93

; <label>:93:                                     ; preds = %616, %590, %87
  br label %94

; <label>:94:                                     ; preds = %153, %93
  %95 = load i8*, i8** %3, align 8
  %96 = load i8, i8* %95, align 1
  %97 = zext i8 %96 to i64
  %98 = getelementptr inbounds [256 x i8], [256 x i8]* @_ZL5yy_ec, i64 0, i64 %97
  %99 = load i8, i8* %98, align 1
  store i8 %99, i8* %6, align 1
  %100 = load i32, i32* %2, align 4
  %101 = sext i32 %100 to i64
  %102 = getelementptr inbounds [33 x i16], [33 x i16]* @_ZL9yy_accept, i64 0, i64 %101
  %103 = load i16, i16* %102, align 2
  %104 = icmp ne i16 %103, 0
  br i1 %104, label %105, label %108

; <label>:105:                                    ; preds = %94
  %106 = load i32, i32* %2, align 4
  store i32 %106, i32* @_ZL23yy_last_accepting_state, align 4
  %107 = load i8*, i8** %3, align 8
  store i8* %107, i8** @_ZL22yy_last_accepting_cpos, align 8
  br label %108

; <label>:108:                                    ; preds = %105, %94
  br label %109

; <label>:109:                                    ; preds = %137, %108
  %110 = load i32, i32* %2, align 4
  %111 = sext i32 %110 to i64
  %112 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL7yy_base, i64 0, i64 %111
  %113 = load i16, i16* %112, align 2
  %114 = sext i16 %113 to i32
  %115 = load i8, i8* %6, align 1
  %116 = zext i8 %115 to i32
  %117 = add nsw i32 %114, %116
  %118 = sext i32 %117 to i64
  %119 = getelementptr inbounds [55 x i16], [55 x i16]* @_ZL6yy_chk, i64 0, i64 %118
  %120 = load i16, i16* %119, align 2
  %121 = sext i16 %120 to i32
  %122 = load i32, i32* %2, align 4
  %123 = icmp ne i32 %121, %122
  br i1 %123, label %124, label %138

; <label>:124:                                    ; preds = %109
  %125 = load i32, i32* %2, align 4
  %126 = sext i32 %125 to i64
  %127 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL6yy_def, i64 0, i64 %126
  %128 = load i16, i16* %127, align 2
  %129 = sext i16 %128 to i32
  store i32 %129, i32* %2, align 4
  %130 = load i32, i32* %2, align 4
  %131 = icmp sge i32 %130, 33
  br i1 %131, label %132, label %137

; <label>:132:                                    ; preds = %124
  %133 = load i8, i8* %6, align 1
  %134 = zext i8 %133 to i64
  %135 = getelementptr inbounds [20 x i8], [20 x i8]* @_ZL7yy_meta, i64 0, i64 %134
  %136 = load i8, i8* %135, align 1
  store i8 %136, i8* %6, align 1
  br label %137

; <label>:137:                                    ; preds = %132, %124
  br label %109

; <label>:138:                                    ; preds = %109
  %139 = load i32, i32* %2, align 4
  %140 = sext i32 %139 to i64
  %141 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL7yy_base, i64 0, i64 %140
  %142 = load i16, i16* %141, align 2
  %143 = sext i16 %142 to i32
  %144 = load i8, i8* %6, align 1
  %145 = zext i8 %144 to i32
  %146 = add nsw i32 %143, %145
  %147 = sext i32 %146 to i64
  %148 = getelementptr inbounds [55 x i16], [55 x i16]* @_ZL6yy_nxt, i64 0, i64 %147
  %149 = load i16, i16* %148, align 2
  %150 = sext i16 %149 to i32
  store i32 %150, i32* %2, align 4
  %151 = load i8*, i8** %3, align 8
  %152 = getelementptr inbounds i8, i8* %151, i32 1
  store i8* %152, i8** %3, align 8
  br label %153

; <label>:153:                                    ; preds = %138
  %154 = load i32, i32* %2, align 4
  %155 = sext i32 %154 to i64
  %156 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL7yy_base, i64 0, i64 %155
  %157 = load i16, i16* %156, align 2
  %158 = sext i16 %157 to i32
  %159 = icmp ne i32 %158, 35
  br i1 %159, label %94, label %160

; <label>:160:                                    ; preds = %153
  br label %161

; <label>:161:                                    ; preds = %625, %594, %191, %160
  %162 = load i32, i32* %2, align 4
  %163 = sext i32 %162 to i64
  %164 = getelementptr inbounds [33 x i16], [33 x i16]* @_ZL9yy_accept, i64 0, i64 %163
  %165 = load i16, i16* %164, align 2
  %166 = sext i16 %165 to i32
  store i32 %166, i32* %5, align 4
  %167 = load i32, i32* %5, align 4
  %168 = icmp eq i32 %167, 0
  br i1 %168, label %169, label %177

; <label>:169:                                    ; preds = %161
  %170 = load i8*, i8** @_ZL22yy_last_accepting_cpos, align 8
  store i8* %170, i8** %3, align 8
  %171 = load i32, i32* @_ZL23yy_last_accepting_state, align 4
  store i32 %171, i32* %2, align 4
  %172 = load i32, i32* %2, align 4
  %173 = sext i32 %172 to i64
  %174 = getelementptr inbounds [33 x i16], [33 x i16]* @_ZL9yy_accept, i64 0, i64 %173
  %175 = load i16, i16* %174, align 2
  %176 = sext i16 %175 to i32
  store i32 %176, i32* %5, align 4
  br label %177

; <label>:177:                                    ; preds = %169, %161
  %178 = load i8*, i8** %4, align 8
  store i8* %178, i8** @yytext, align 8
  %179 = load i8*, i8** %3, align 8
  %180 = load i8*, i8** %4, align 8
  %181 = ptrtoint i8* %179 to i64
  %182 = ptrtoint i8* %180 to i64
  %183 = sub i64 %181, %182
  %184 = trunc i64 %183 to i32
  store i32 %184, i32* @yyleng, align 4
  %185 = load i8*, i8** %3, align 8
  %186 = load i8, i8* %185, align 1
  store i8 %186, i8* @_ZL12yy_hold_char, align 1
  %187 = load i8*, i8** %3, align 8
  store i8 0, i8* %187, align 1
  %188 = load i8*, i8** %3, align 8
  store i8* %188, i8** @_ZL10yy_c_buf_p, align 8
  br label %189

; <label>:189:                                    ; preds = %601, %177
  %190 = load i32, i32* %5, align 4
  switch i32 %190, label %641 [
    i32 0, label %191
    i32 1, label %196
    i32 2, label %197
    i32 3, label %213
    i32 4, label %229
    i32 5, label %245
    i32 6, label %261
    i32 7, label %277
    i32 8, label %293
    i32 9, label %309
    i32 10, label %325
    i32 11, label %341
    i32 12, label %357
    i32 13, label %373
    i32 14, label %389
    i32 15, label %405
    i32 16, label %421
    i32 17, label %437
    i32 18, label %453
    i32 19, label %469
    i32 20, label %485
    i32 21, label %501
    i32 22, label %517
    i32 23, label %519
    i32 25, label %530
    i32 24, label %531
  ]

; <label>:191:                                    ; preds = %189
  %192 = load i8, i8* @_ZL12yy_hold_char, align 1
  %193 = load i8*, i8** %3, align 8
  store i8 %192, i8* %193, align 1
  %194 = load i8*, i8** @_ZL22yy_last_accepting_cpos, align 8
  store i8* %194, i8** %3, align 8
  %195 = load i32, i32* @_ZL23yy_last_accepting_state, align 4
  store i32 %195, i32* %2, align 4
  br label %161

; <label>:196:                                    ; preds = %189
  br label %642

; <label>:197:                                    ; preds = %189
  %198 = load i8*, i8** @yytext, align 8
  %199 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([36 x i8], [36 x i8]* @.str, i32 0, i32 0), i8* %198, i32 258)
  %200 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %10, align 1
  %201 = bitcast i8* %200 to %"class.std::__cxx11::basic_string"*
  %202 = load i8*, i8** @yytext, align 8
  %203 = load i32, i32* @yyleng, align 4
  %204 = sext i32 %203 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %7) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %201, i8* %202, i64 %204, %"class.std::allocator"* dereferenceable(1) %7)
          to label %205 unwind label %206

; <label>:205:                                    ; preds = %197
  store i1 false, i1* %10, align 1
  store %"class.std::__cxx11::basic_string"* %201, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %7) #3
  store i32 258, i32* %1, align 4
  br label %643

; <label>:206:                                    ; preds = %197
  %207 = landingpad { i8*, i32 }
          cleanup
  %208 = extractvalue { i8*, i32 } %207, 0
  store i8* %208, i8** %8, align 8
  %209 = extractvalue { i8*, i32 } %207, 1
  store i32 %209, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %7) #3
  %210 = load i1, i1* %10, align 1
  br i1 %210, label %211, label %212

; <label>:211:                                    ; preds = %206
  call void @_ZdlPv(i8* %200) #15
  br label %212

; <label>:212:                                    ; preds = %211, %206
  br label %645

; <label>:213:                                    ; preds = %189
  %214 = load i8*, i8** @yytext, align 8
  %215 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.1, i32 0, i32 0), i8* %214, i32 260)
  %216 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %12, align 1
  %217 = bitcast i8* %216 to %"class.std::__cxx11::basic_string"*
  %218 = load i8*, i8** @yytext, align 8
  %219 = load i32, i32* @yyleng, align 4
  %220 = sext i32 %219 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %11) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %217, i8* %218, i64 %220, %"class.std::allocator"* dereferenceable(1) %11)
          to label %221 unwind label %222

; <label>:221:                                    ; preds = %213
  store i1 false, i1* %12, align 1
  store %"class.std::__cxx11::basic_string"* %217, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %11) #3
  store i32 260, i32* %1, align 4
  br label %643

; <label>:222:                                    ; preds = %213
  %223 = landingpad { i8*, i32 }
          cleanup
  %224 = extractvalue { i8*, i32 } %223, 0
  store i8* %224, i8** %8, align 8
  %225 = extractvalue { i8*, i32 } %223, 1
  store i32 %225, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %11) #3
  %226 = load i1, i1* %12, align 1
  br i1 %226, label %227, label %228

; <label>:227:                                    ; preds = %222
  call void @_ZdlPv(i8* %216) #15
  br label %228

; <label>:228:                                    ; preds = %227, %222
  br label %645

; <label>:229:                                    ; preds = %189
  %230 = load i8*, i8** @yytext, align 8
  %231 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.1, i32 0, i32 0), i8* %230, i32 259)
  %232 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %14, align 1
  %233 = bitcast i8* %232 to %"class.std::__cxx11::basic_string"*
  %234 = load i8*, i8** @yytext, align 8
  %235 = load i32, i32* @yyleng, align 4
  %236 = sext i32 %235 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %13) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %233, i8* %234, i64 %236, %"class.std::allocator"* dereferenceable(1) %13)
          to label %237 unwind label %238

; <label>:237:                                    ; preds = %229
  store i1 false, i1* %14, align 1
  store %"class.std::__cxx11::basic_string"* %233, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %13) #3
  store i32 259, i32* %1, align 4
  br label %643

; <label>:238:                                    ; preds = %229
  %239 = landingpad { i8*, i32 }
          cleanup
  %240 = extractvalue { i8*, i32 } %239, 0
  store i8* %240, i8** %8, align 8
  %241 = extractvalue { i8*, i32 } %239, 1
  store i32 %241, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %13) #3
  %242 = load i1, i1* %14, align 1
  br i1 %242, label %243, label %244

; <label>:243:                                    ; preds = %238
  call void @_ZdlPv(i8* %232) #15
  br label %244

; <label>:244:                                    ; preds = %243, %238
  br label %645

; <label>:245:                                    ; preds = %189
  %246 = load i8*, i8** @yytext, align 8
  store i32 267, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %247 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.2, i32 0, i32 0), i8* %246, i32 267)
  %248 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %16, align 1
  %249 = bitcast i8* %248 to %"class.std::__cxx11::basic_string"*
  %250 = load i8*, i8** @yytext, align 8
  %251 = load i32, i32* @yyleng, align 4
  %252 = sext i32 %251 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %15) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %249, i8* %250, i64 %252, %"class.std::allocator"* dereferenceable(1) %15)
          to label %253 unwind label %254

; <label>:253:                                    ; preds = %245
  store i1 false, i1* %16, align 1
  store %"class.std::__cxx11::basic_string"* %249, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %15) #3
  store i32 267, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 267, i32* %1, align 4
  br label %643

; <label>:254:                                    ; preds = %245
  %255 = landingpad { i8*, i32 }
          cleanup
  %256 = extractvalue { i8*, i32 } %255, 0
  store i8* %256, i8** %8, align 8
  %257 = extractvalue { i8*, i32 } %255, 1
  store i32 %257, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %15) #3
  %258 = load i1, i1* %16, align 1
  br i1 %258, label %259, label %260

; <label>:259:                                    ; preds = %254
  call void @_ZdlPv(i8* %248) #15
  br label %260

; <label>:260:                                    ; preds = %259, %254
  br label %645

; <label>:261:                                    ; preds = %189
  %262 = load i8*, i8** @yytext, align 8
  store i32 261, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %263 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.3, i32 0, i32 0), i8* %262, i32 261)
  %264 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %18, align 1
  %265 = bitcast i8* %264 to %"class.std::__cxx11::basic_string"*
  %266 = load i8*, i8** @yytext, align 8
  %267 = load i32, i32* @yyleng, align 4
  %268 = sext i32 %267 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %17) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %265, i8* %266, i64 %268, %"class.std::allocator"* dereferenceable(1) %17)
          to label %269 unwind label %270

; <label>:269:                                    ; preds = %261
  store i1 false, i1* %18, align 1
  store %"class.std::__cxx11::basic_string"* %265, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %17) #3
  store i32 261, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 261, i32* %1, align 4
  br label %643

; <label>:270:                                    ; preds = %261
  %271 = landingpad { i8*, i32 }
          cleanup
  %272 = extractvalue { i8*, i32 } %271, 0
  store i8* %272, i8** %8, align 8
  %273 = extractvalue { i8*, i32 } %271, 1
  store i32 %273, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %17) #3
  %274 = load i1, i1* %18, align 1
  br i1 %274, label %275, label %276

; <label>:275:                                    ; preds = %270
  call void @_ZdlPv(i8* %264) #15
  br label %276

; <label>:276:                                    ; preds = %275, %270
  br label %645

; <label>:277:                                    ; preds = %189
  %278 = load i8*, i8** @yytext, align 8
  store i32 262, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %279 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.4, i32 0, i32 0), i8* %278, i32 262)
  %280 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %20, align 1
  %281 = bitcast i8* %280 to %"class.std::__cxx11::basic_string"*
  %282 = load i8*, i8** @yytext, align 8
  %283 = load i32, i32* @yyleng, align 4
  %284 = sext i32 %283 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %19) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %281, i8* %282, i64 %284, %"class.std::allocator"* dereferenceable(1) %19)
          to label %285 unwind label %286

; <label>:285:                                    ; preds = %277
  store i1 false, i1* %20, align 1
  store %"class.std::__cxx11::basic_string"* %281, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %19) #3
  store i32 262, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 262, i32* %1, align 4
  br label %643

; <label>:286:                                    ; preds = %277
  %287 = landingpad { i8*, i32 }
          cleanup
  %288 = extractvalue { i8*, i32 } %287, 0
  store i8* %288, i8** %8, align 8
  %289 = extractvalue { i8*, i32 } %287, 1
  store i32 %289, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %19) #3
  %290 = load i1, i1* %20, align 1
  br i1 %290, label %291, label %292

; <label>:291:                                    ; preds = %286
  call void @_ZdlPv(i8* %280) #15
  br label %292

; <label>:292:                                    ; preds = %291, %286
  br label %645

; <label>:293:                                    ; preds = %189
  %294 = load i8*, i8** @yytext, align 8
  store i32 263, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %295 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.5, i32 0, i32 0), i8* %294, i32 263)
  %296 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %22, align 1
  %297 = bitcast i8* %296 to %"class.std::__cxx11::basic_string"*
  %298 = load i8*, i8** @yytext, align 8
  %299 = load i32, i32* @yyleng, align 4
  %300 = sext i32 %299 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %21) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %297, i8* %298, i64 %300, %"class.std::allocator"* dereferenceable(1) %21)
          to label %301 unwind label %302

; <label>:301:                                    ; preds = %293
  store i1 false, i1* %22, align 1
  store %"class.std::__cxx11::basic_string"* %297, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %21) #3
  store i32 263, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 263, i32* %1, align 4
  br label %643

; <label>:302:                                    ; preds = %293
  %303 = landingpad { i8*, i32 }
          cleanup
  %304 = extractvalue { i8*, i32 } %303, 0
  store i8* %304, i8** %8, align 8
  %305 = extractvalue { i8*, i32 } %303, 1
  store i32 %305, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %21) #3
  %306 = load i1, i1* %22, align 1
  br i1 %306, label %307, label %308

; <label>:307:                                    ; preds = %302
  call void @_ZdlPv(i8* %296) #15
  br label %308

; <label>:308:                                    ; preds = %307, %302
  br label %645

; <label>:309:                                    ; preds = %189
  %310 = load i8*, i8** @yytext, align 8
  store i32 264, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %311 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.6, i32 0, i32 0), i8* %310, i32 264)
  %312 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %24, align 1
  %313 = bitcast i8* %312 to %"class.std::__cxx11::basic_string"*
  %314 = load i8*, i8** @yytext, align 8
  %315 = load i32, i32* @yyleng, align 4
  %316 = sext i32 %315 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %23) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %313, i8* %314, i64 %316, %"class.std::allocator"* dereferenceable(1) %23)
          to label %317 unwind label %318

; <label>:317:                                    ; preds = %309
  store i1 false, i1* %24, align 1
  store %"class.std::__cxx11::basic_string"* %313, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %23) #3
  store i32 264, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 264, i32* %1, align 4
  br label %643

; <label>:318:                                    ; preds = %309
  %319 = landingpad { i8*, i32 }
          cleanup
  %320 = extractvalue { i8*, i32 } %319, 0
  store i8* %320, i8** %8, align 8
  %321 = extractvalue { i8*, i32 } %319, 1
  store i32 %321, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %23) #3
  %322 = load i1, i1* %24, align 1
  br i1 %322, label %323, label %324

; <label>:323:                                    ; preds = %318
  call void @_ZdlPv(i8* %312) #15
  br label %324

; <label>:324:                                    ; preds = %323, %318
  br label %645

; <label>:325:                                    ; preds = %189
  %326 = load i8*, i8** @yytext, align 8
  store i32 265, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %327 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.7, i32 0, i32 0), i8* %326, i32 265)
  %328 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %26, align 1
  %329 = bitcast i8* %328 to %"class.std::__cxx11::basic_string"*
  %330 = load i8*, i8** @yytext, align 8
  %331 = load i32, i32* @yyleng, align 4
  %332 = sext i32 %331 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %25) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %329, i8* %330, i64 %332, %"class.std::allocator"* dereferenceable(1) %25)
          to label %333 unwind label %334

; <label>:333:                                    ; preds = %325
  store i1 false, i1* %26, align 1
  store %"class.std::__cxx11::basic_string"* %329, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %25) #3
  store i32 265, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 265, i32* %1, align 4
  br label %643

; <label>:334:                                    ; preds = %325
  %335 = landingpad { i8*, i32 }
          cleanup
  %336 = extractvalue { i8*, i32 } %335, 0
  store i8* %336, i8** %8, align 8
  %337 = extractvalue { i8*, i32 } %335, 1
  store i32 %337, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %25) #3
  %338 = load i1, i1* %26, align 1
  br i1 %338, label %339, label %340

; <label>:339:                                    ; preds = %334
  call void @_ZdlPv(i8* %328) #15
  br label %340

; <label>:340:                                    ; preds = %339, %334
  br label %645

; <label>:341:                                    ; preds = %189
  %342 = load i8*, i8** @yytext, align 8
  store i32 266, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %343 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.8, i32 0, i32 0), i8* %342, i32 266)
  %344 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %28, align 1
  %345 = bitcast i8* %344 to %"class.std::__cxx11::basic_string"*
  %346 = load i8*, i8** @yytext, align 8
  %347 = load i32, i32* @yyleng, align 4
  %348 = sext i32 %347 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %27) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %345, i8* %346, i64 %348, %"class.std::allocator"* dereferenceable(1) %27)
          to label %349 unwind label %350

; <label>:349:                                    ; preds = %341
  store i1 false, i1* %28, align 1
  store %"class.std::__cxx11::basic_string"* %345, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %27) #3
  store i32 266, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 266, i32* %1, align 4
  br label %643

; <label>:350:                                    ; preds = %341
  %351 = landingpad { i8*, i32 }
          cleanup
  %352 = extractvalue { i8*, i32 } %351, 0
  store i8* %352, i8** %8, align 8
  %353 = extractvalue { i8*, i32 } %351, 1
  store i32 %353, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %27) #3
  %354 = load i1, i1* %28, align 1
  br i1 %354, label %355, label %356

; <label>:355:                                    ; preds = %350
  call void @_ZdlPv(i8* %344) #15
  br label %356

; <label>:356:                                    ; preds = %355, %350
  br label %645

; <label>:357:                                    ; preds = %189
  %358 = load i8*, i8** @yytext, align 8
  store i32 268, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %359 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.9, i32 0, i32 0), i8* %358, i32 268)
  %360 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %30, align 1
  %361 = bitcast i8* %360 to %"class.std::__cxx11::basic_string"*
  %362 = load i8*, i8** @yytext, align 8
  %363 = load i32, i32* @yyleng, align 4
  %364 = sext i32 %363 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %29) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %361, i8* %362, i64 %364, %"class.std::allocator"* dereferenceable(1) %29)
          to label %365 unwind label %366

; <label>:365:                                    ; preds = %357
  store i1 false, i1* %30, align 1
  store %"class.std::__cxx11::basic_string"* %361, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %29) #3
  store i32 268, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 268, i32* %1, align 4
  br label %643

; <label>:366:                                    ; preds = %357
  %367 = landingpad { i8*, i32 }
          cleanup
  %368 = extractvalue { i8*, i32 } %367, 0
  store i8* %368, i8** %8, align 8
  %369 = extractvalue { i8*, i32 } %367, 1
  store i32 %369, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %29) #3
  %370 = load i1, i1* %30, align 1
  br i1 %370, label %371, label %372

; <label>:371:                                    ; preds = %366
  call void @_ZdlPv(i8* %360) #15
  br label %372

; <label>:372:                                    ; preds = %371, %366
  br label %645

; <label>:373:                                    ; preds = %189
  %374 = load i8*, i8** @yytext, align 8
  store i32 269, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %375 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.10, i32 0, i32 0), i8* %374, i32 269)
  %376 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %32, align 1
  %377 = bitcast i8* %376 to %"class.std::__cxx11::basic_string"*
  %378 = load i8*, i8** @yytext, align 8
  %379 = load i32, i32* @yyleng, align 4
  %380 = sext i32 %379 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %31) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %377, i8* %378, i64 %380, %"class.std::allocator"* dereferenceable(1) %31)
          to label %381 unwind label %382

; <label>:381:                                    ; preds = %373
  store i1 false, i1* %32, align 1
  store %"class.std::__cxx11::basic_string"* %377, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %31) #3
  store i32 269, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 269, i32* %1, align 4
  br label %643

; <label>:382:                                    ; preds = %373
  %383 = landingpad { i8*, i32 }
          cleanup
  %384 = extractvalue { i8*, i32 } %383, 0
  store i8* %384, i8** %8, align 8
  %385 = extractvalue { i8*, i32 } %383, 1
  store i32 %385, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %31) #3
  %386 = load i1, i1* %32, align 1
  br i1 %386, label %387, label %388

; <label>:387:                                    ; preds = %382
  call void @_ZdlPv(i8* %376) #15
  br label %388

; <label>:388:                                    ; preds = %387, %382
  br label %645

; <label>:389:                                    ; preds = %189
  %390 = load i8*, i8** @yytext, align 8
  store i32 270, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %391 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.11, i32 0, i32 0), i8* %390, i32 270)
  %392 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %34, align 1
  %393 = bitcast i8* %392 to %"class.std::__cxx11::basic_string"*
  %394 = load i8*, i8** @yytext, align 8
  %395 = load i32, i32* @yyleng, align 4
  %396 = sext i32 %395 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %33) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %393, i8* %394, i64 %396, %"class.std::allocator"* dereferenceable(1) %33)
          to label %397 unwind label %398

; <label>:397:                                    ; preds = %389
  store i1 false, i1* %34, align 1
  store %"class.std::__cxx11::basic_string"* %393, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %33) #3
  store i32 270, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 270, i32* %1, align 4
  br label %643

; <label>:398:                                    ; preds = %389
  %399 = landingpad { i8*, i32 }
          cleanup
  %400 = extractvalue { i8*, i32 } %399, 0
  store i8* %400, i8** %8, align 8
  %401 = extractvalue { i8*, i32 } %399, 1
  store i32 %401, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %33) #3
  %402 = load i1, i1* %34, align 1
  br i1 %402, label %403, label %404

; <label>:403:                                    ; preds = %398
  call void @_ZdlPv(i8* %392) #15
  br label %404

; <label>:404:                                    ; preds = %403, %398
  br label %645

; <label>:405:                                    ; preds = %189
  %406 = load i8*, i8** @yytext, align 8
  store i32 271, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %407 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.12, i32 0, i32 0), i8* %406, i32 271)
  %408 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %36, align 1
  %409 = bitcast i8* %408 to %"class.std::__cxx11::basic_string"*
  %410 = load i8*, i8** @yytext, align 8
  %411 = load i32, i32* @yyleng, align 4
  %412 = sext i32 %411 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %35) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %409, i8* %410, i64 %412, %"class.std::allocator"* dereferenceable(1) %35)
          to label %413 unwind label %414

; <label>:413:                                    ; preds = %405
  store i1 false, i1* %36, align 1
  store %"class.std::__cxx11::basic_string"* %409, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %35) #3
  store i32 271, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 271, i32* %1, align 4
  br label %643

; <label>:414:                                    ; preds = %405
  %415 = landingpad { i8*, i32 }
          cleanup
  %416 = extractvalue { i8*, i32 } %415, 0
  store i8* %416, i8** %8, align 8
  %417 = extractvalue { i8*, i32 } %415, 1
  store i32 %417, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %35) #3
  %418 = load i1, i1* %36, align 1
  br i1 %418, label %419, label %420

; <label>:419:                                    ; preds = %414
  call void @_ZdlPv(i8* %408) #15
  br label %420

; <label>:420:                                    ; preds = %419, %414
  br label %645

; <label>:421:                                    ; preds = %189
  %422 = load i8*, i8** @yytext, align 8
  store i32 273, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %423 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.13, i32 0, i32 0), i8* %422, i32 273)
  %424 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %38, align 1
  %425 = bitcast i8* %424 to %"class.std::__cxx11::basic_string"*
  %426 = load i8*, i8** @yytext, align 8
  %427 = load i32, i32* @yyleng, align 4
  %428 = sext i32 %427 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %37) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %425, i8* %426, i64 %428, %"class.std::allocator"* dereferenceable(1) %37)
          to label %429 unwind label %430

; <label>:429:                                    ; preds = %421
  store i1 false, i1* %38, align 1
  store %"class.std::__cxx11::basic_string"* %425, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %37) #3
  store i32 273, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 273, i32* %1, align 4
  br label %643

; <label>:430:                                    ; preds = %421
  %431 = landingpad { i8*, i32 }
          cleanup
  %432 = extractvalue { i8*, i32 } %431, 0
  store i8* %432, i8** %8, align 8
  %433 = extractvalue { i8*, i32 } %431, 1
  store i32 %433, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %37) #3
  %434 = load i1, i1* %38, align 1
  br i1 %434, label %435, label %436

; <label>:435:                                    ; preds = %430
  call void @_ZdlPv(i8* %424) #15
  br label %436

; <label>:436:                                    ; preds = %435, %430
  br label %645

; <label>:437:                                    ; preds = %189
  %438 = load i8*, i8** @yytext, align 8
  store i32 272, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %439 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.14, i32 0, i32 0), i8* %438, i32 272)
  %440 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %40, align 1
  %441 = bitcast i8* %440 to %"class.std::__cxx11::basic_string"*
  %442 = load i8*, i8** @yytext, align 8
  %443 = load i32, i32* @yyleng, align 4
  %444 = sext i32 %443 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %39) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %441, i8* %442, i64 %444, %"class.std::allocator"* dereferenceable(1) %39)
          to label %445 unwind label %446

; <label>:445:                                    ; preds = %437
  store i1 false, i1* %40, align 1
  store %"class.std::__cxx11::basic_string"* %441, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %39) #3
  store i32 272, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 272, i32* %1, align 4
  br label %643

; <label>:446:                                    ; preds = %437
  %447 = landingpad { i8*, i32 }
          cleanup
  %448 = extractvalue { i8*, i32 } %447, 0
  store i8* %448, i8** %8, align 8
  %449 = extractvalue { i8*, i32 } %447, 1
  store i32 %449, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %39) #3
  %450 = load i1, i1* %40, align 1
  br i1 %450, label %451, label %452

; <label>:451:                                    ; preds = %446
  call void @_ZdlPv(i8* %440) #15
  br label %452

; <label>:452:                                    ; preds = %451, %446
  br label %645

; <label>:453:                                    ; preds = %189
  %454 = load i8*, i8** @yytext, align 8
  store i32 274, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %455 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([30 x i8], [30 x i8]* @.str.15, i32 0, i32 0), i8* %454, i32 274)
  %456 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %42, align 1
  %457 = bitcast i8* %456 to %"class.std::__cxx11::basic_string"*
  %458 = load i8*, i8** @yytext, align 8
  %459 = load i32, i32* @yyleng, align 4
  %460 = sext i32 %459 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %41) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %457, i8* %458, i64 %460, %"class.std::allocator"* dereferenceable(1) %41)
          to label %461 unwind label %462

; <label>:461:                                    ; preds = %453
  store i1 false, i1* %42, align 1
  store %"class.std::__cxx11::basic_string"* %457, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %41) #3
  store i32 274, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 274, i32* %1, align 4
  br label %643

; <label>:462:                                    ; preds = %453
  %463 = landingpad { i8*, i32 }
          cleanup
  %464 = extractvalue { i8*, i32 } %463, 0
  store i8* %464, i8** %8, align 8
  %465 = extractvalue { i8*, i32 } %463, 1
  store i32 %465, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %41) #3
  %466 = load i1, i1* %42, align 1
  br i1 %466, label %467, label %468

; <label>:467:                                    ; preds = %462
  call void @_ZdlPv(i8* %456) #15
  br label %468

; <label>:468:                                    ; preds = %467, %462
  br label %645

; <label>:469:                                    ; preds = %189
  %470 = load i8*, i8** @yytext, align 8
  store i32 275, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %471 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.16, i32 0, i32 0), i8* %470, i32 275)
  %472 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %44, align 1
  %473 = bitcast i8* %472 to %"class.std::__cxx11::basic_string"*
  %474 = load i8*, i8** @yytext, align 8
  %475 = load i32, i32* @yyleng, align 4
  %476 = sext i32 %475 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %43) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %473, i8* %474, i64 %476, %"class.std::allocator"* dereferenceable(1) %43)
          to label %477 unwind label %478

; <label>:477:                                    ; preds = %469
  store i1 false, i1* %44, align 1
  store %"class.std::__cxx11::basic_string"* %473, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %43) #3
  store i32 275, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 275, i32* %1, align 4
  br label %643

; <label>:478:                                    ; preds = %469
  %479 = landingpad { i8*, i32 }
          cleanup
  %480 = extractvalue { i8*, i32 } %479, 0
  store i8* %480, i8** %8, align 8
  %481 = extractvalue { i8*, i32 } %479, 1
  store i32 %481, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %43) #3
  %482 = load i1, i1* %44, align 1
  br i1 %482, label %483, label %484

; <label>:483:                                    ; preds = %478
  call void @_ZdlPv(i8* %472) #15
  br label %484

; <label>:484:                                    ; preds = %483, %478
  br label %645

; <label>:485:                                    ; preds = %189
  %486 = load i8*, i8** @yytext, align 8
  store i32 276, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %487 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.17, i32 0, i32 0), i8* %486, i32 276)
  %488 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %46, align 1
  %489 = bitcast i8* %488 to %"class.std::__cxx11::basic_string"*
  %490 = load i8*, i8** @yytext, align 8
  %491 = load i32, i32* @yyleng, align 4
  %492 = sext i32 %491 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %45) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %489, i8* %490, i64 %492, %"class.std::allocator"* dereferenceable(1) %45)
          to label %493 unwind label %494

; <label>:493:                                    ; preds = %485
  store i1 false, i1* %46, align 1
  store %"class.std::__cxx11::basic_string"* %489, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %45) #3
  store i32 276, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 276, i32* %1, align 4
  br label %643

; <label>:494:                                    ; preds = %485
  %495 = landingpad { i8*, i32 }
          cleanup
  %496 = extractvalue { i8*, i32 } %495, 0
  store i8* %496, i8** %8, align 8
  %497 = extractvalue { i8*, i32 } %495, 1
  store i32 %497, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %45) #3
  %498 = load i1, i1* %46, align 1
  br i1 %498, label %499, label %500

; <label>:499:                                    ; preds = %494
  call void @_ZdlPv(i8* %488) #15
  br label %500

; <label>:500:                                    ; preds = %499, %494
  br label %645

; <label>:501:                                    ; preds = %189
  %502 = load i8*, i8** @yytext, align 8
  store i32 277, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  %503 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.18, i32 0, i32 0), i8* %502, i32 277)
  %504 = call i8* @_Znwm(i64 32) #14
  store i1 true, i1* %48, align 1
  %505 = bitcast i8* %504 to %"class.std::__cxx11::basic_string"*
  %506 = load i8*, i8** @yytext, align 8
  %507 = load i32, i32* @yyleng, align 4
  %508 = sext i32 %507 to i64
  call void @_ZNSaIcEC1Ev(%"class.std::allocator"* %47) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"* %505, i8* %506, i64 %508, %"class.std::allocator"* dereferenceable(1) %47)
          to label %509 unwind label %510

; <label>:509:                                    ; preds = %501
  store i1 false, i1* %48, align 1
  store %"class.std::__cxx11::basic_string"* %505, %"class.std::__cxx11::basic_string"** bitcast (%union.YYSTYPE* @yylval to %"class.std::__cxx11::basic_string"**), align 8
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %47) #3
  store i32 277, i32* bitcast (%union.YYSTYPE* @yylval to i32*), align 8
  store i32 277, i32* %1, align 4
  br label %643

; <label>:510:                                    ; preds = %501
  %511 = landingpad { i8*, i32 }
          cleanup
  %512 = extractvalue { i8*, i32 } %511, 0
  store i8* %512, i8** %8, align 8
  %513 = extractvalue { i8*, i32 } %511, 1
  store i32 %513, i32* %9, align 4
  call void @_ZNSaIcED1Ev(%"class.std::allocator"* %47) #3
  %514 = load i1, i1* %48, align 1
  br i1 %514, label %515, label %516

; <label>:515:                                    ; preds = %510
  call void @_ZdlPv(i8* %504) #15
  br label %516

; <label>:516:                                    ; preds = %515, %510
  br label %645

; <label>:517:                                    ; preds = %189
  %518 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.19, i32 0, i32 0))
  store i32 0, i32* %1, align 4
  br label %643

; <label>:519:                                    ; preds = %189
  br label %520

; <label>:520:                                    ; preds = %519
  %521 = load i8*, i8** @yytext, align 8
  %522 = load i32, i32* @yyleng, align 4
  %523 = sext i32 %522 to i64
  %524 = load %struct._IO_FILE*, %struct._IO_FILE** @yyout, align 8
  %525 = call i64 @fwrite(i8* %521, i64 %523, i64 1, %struct._IO_FILE* %524)
  %526 = icmp ne i64 %525, 0
  br i1 %526, label %527, label %528

; <label>:527:                                    ; preds = %520
  br label %528

; <label>:528:                                    ; preds = %527, %520
  br label %529

; <label>:529:                                    ; preds = %528
  br label %642

; <label>:530:                                    ; preds = %189
  store i32 0, i32* %1, align 4
  br label %643

; <label>:531:                                    ; preds = %189
  %532 = load i8*, i8** %3, align 8
  %533 = load i8*, i8** @yytext, align 8
  %534 = ptrtoint i8* %532 to i64
  %535 = ptrtoint i8* %533 to i64
  %536 = sub i64 %534, %535
  %537 = trunc i64 %536 to i32
  %538 = sub nsw i32 %537, 1
  store i32 %538, i32* %49, align 4
  %539 = load i8, i8* @_ZL12yy_hold_char, align 1
  %540 = load i8*, i8** %3, align 8
  store i8 %539, i8* %540, align 1
  %541 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %542 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %543 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %541, i64 %542
  %544 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %543, align 8
  %545 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %544, i32 0, i32 11
  %546 = load i32, i32* %545, align 8
  %547 = icmp eq i32 %546, 0
  br i1 %547, label %548, label %566

; <label>:548:                                    ; preds = %531
  %549 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %550 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %551 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %549, i64 %550
  %552 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %551, align 8
  %553 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %552, i32 0, i32 4
  %554 = load i32, i32* %553, align 4
  store i32 %554, i32* @_ZL10yy_n_chars, align 4
  %555 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %556 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %557 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %558 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %556, i64 %557
  %559 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %558, align 8
  %560 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %559, i32 0, i32 0
  store %struct._IO_FILE* %555, %struct._IO_FILE** %560, align 8
  %561 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %562 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %563 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %561, i64 %562
  %564 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %563, align 8
  %565 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %564, i32 0, i32 11
  store i32 1, i32* %565, align 8
  br label %566

; <label>:566:                                    ; preds = %548, %531
  %567 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %568 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %569 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %570 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %568, i64 %569
  %571 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %570, align 8
  %572 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %571, i32 0, i32 1
  %573 = load i8*, i8** %572, align 8
  %574 = load i32, i32* @_ZL10yy_n_chars, align 4
  %575 = sext i32 %574 to i64
  %576 = getelementptr inbounds i8, i8* %573, i64 %575
  %577 = icmp ule i8* %567, %576
  br i1 %577, label %578, label %596

; <label>:578:                                    ; preds = %566
  %579 = load i8*, i8** @yytext, align 8
  %580 = load i32, i32* %49, align 4
  %581 = sext i32 %580 to i64
  %582 = getelementptr inbounds i8, i8* %579, i64 %581
  store i8* %582, i8** @_ZL10yy_c_buf_p, align 8
  %583 = call i32 @_ZL21yy_get_previous_statev()
  store i32 %583, i32* %2, align 4
  %584 = load i32, i32* %2, align 4
  %585 = call i32 @_ZL16yy_try_NUL_transi(i32 %584)
  store i32 %585, i32* %50, align 4
  %586 = load i8*, i8** @yytext, align 8
  %587 = getelementptr inbounds i8, i8* %586, i64 0
  store i8* %587, i8** %4, align 8
  %588 = load i32, i32* %50, align 4
  %589 = icmp ne i32 %588, 0
  br i1 %589, label %590, label %594

; <label>:590:                                    ; preds = %578
  %591 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %592 = getelementptr inbounds i8, i8* %591, i32 1
  store i8* %592, i8** @_ZL10yy_c_buf_p, align 8
  store i8* %592, i8** %3, align 8
  %593 = load i32, i32* %50, align 4
  store i32 %593, i32* %2, align 4
  br label %93

; <label>:594:                                    ; preds = %578
  %595 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  store i8* %595, i8** %3, align 8
  br label %161

; <label>:596:                                    ; preds = %566
  %597 = call i32 @_ZL18yy_get_next_bufferv()
  switch i32 %597, label %639 [
    i32 1, label %598
    i32 0, label %616
    i32 2, label %625
  ]

; <label>:598:                                    ; preds = %596
  store i32 0, i32* @_ZL27yy_did_buffer_switch_on_eof, align 4
  %599 = call i32 @yywrap()
  %600 = icmp ne i32 %599, 0
  br i1 %600, label %601, label %609

; <label>:601:                                    ; preds = %598
  %602 = load i8*, i8** @yytext, align 8
  %603 = getelementptr inbounds i8, i8* %602, i64 0
  store i8* %603, i8** @_ZL10yy_c_buf_p, align 8
  %604 = load i32, i32* @_ZL8yy_start, align 4
  %605 = sub nsw i32 %604, 1
  %606 = sdiv i32 %605, 2
  %607 = add nsw i32 24, %606
  %608 = add nsw i32 %607, 1
  store i32 %608, i32* %5, align 4
  br label %189

; <label>:609:                                    ; preds = %598
  %610 = load i32, i32* @_ZL27yy_did_buffer_switch_on_eof, align 4
  %611 = icmp ne i32 %610, 0
  br i1 %611, label %614, label %612

; <label>:612:                                    ; preds = %609
  %613 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  call void @_Z9yyrestartP8_IO_FILE(%struct._IO_FILE* %613)
  br label %614

; <label>:614:                                    ; preds = %612, %609
  br label %615

; <label>:615:                                    ; preds = %614
  br label %639

; <label>:616:                                    ; preds = %596
  %617 = load i8*, i8** @yytext, align 8
  %618 = load i32, i32* %49, align 4
  %619 = sext i32 %618 to i64
  %620 = getelementptr inbounds i8, i8* %617, i64 %619
  store i8* %620, i8** @_ZL10yy_c_buf_p, align 8
  %621 = call i32 @_ZL21yy_get_previous_statev()
  store i32 %621, i32* %2, align 4
  %622 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  store i8* %622, i8** %3, align 8
  %623 = load i8*, i8** @yytext, align 8
  %624 = getelementptr inbounds i8, i8* %623, i64 0
  store i8* %624, i8** %4, align 8
  br label %93

; <label>:625:                                    ; preds = %596
  %626 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %627 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %628 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %626, i64 %627
  %629 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %628, align 8
  %630 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %629, i32 0, i32 1
  %631 = load i8*, i8** %630, align 8
  %632 = load i32, i32* @_ZL10yy_n_chars, align 4
  %633 = sext i32 %632 to i64
  %634 = getelementptr inbounds i8, i8* %631, i64 %633
  store i8* %634, i8** @_ZL10yy_c_buf_p, align 8
  %635 = call i32 @_ZL21yy_get_previous_statev()
  store i32 %635, i32* %2, align 4
  %636 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  store i8* %636, i8** %3, align 8
  %637 = load i8*, i8** @yytext, align 8
  %638 = getelementptr inbounds i8, i8* %637, i64 0
  store i8* %638, i8** %4, align 8
  br label %161

; <label>:639:                                    ; preds = %596, %615
  br label %640

; <label>:640:                                    ; preds = %639
  br label %642

; <label>:641:                                    ; preds = %189
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.20, i32 0, i32 0)) #16
  unreachable

; <label>:642:                                    ; preds = %640, %529, %196
  br label %87

; <label>:643:                                    ; preds = %530, %517, %509, %493, %477, %461, %445, %429, %413, %397, %381, %365, %349, %333, %317, %301, %285, %269, %253, %237, %221, %205
  %644 = load i32, i32* %1, align 4
  ret i32 %644

; <label>:645:                                    ; preds = %516, %500, %484, %468, %452, %436, %420, %404, %388, %372, %356, %340, %324, %308, %292, %276, %260, %244, %228, %212
  %646 = load i8*, i8** %8, align 8
  %647 = load i32, i32* %9, align 4
  %648 = insertvalue { i8*, i32 } undef, i8* %646, 0
  %649 = insertvalue { i8*, i32 } %648, i32 %647, 1
  resume { i8*, i32 } %649
}

; Function Attrs: noinline optnone uwtable
define internal void @_ZL21yyensure_buffer_stackv() #6 {
  %1 = alloca i64, align 8
  %2 = alloca i64, align 8
  %3 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %4 = icmp ne %struct.yy_buffer_state** %3, null
  br i1 %4, label %19, label %5

; <label>:5:                                      ; preds = %0
  store i64 1, i64* %1, align 8
  %6 = load i64, i64* %1, align 8
  %7 = mul i64 %6, 8
  %8 = call i8* @_Z7yyallocm(i64 %7)
  %9 = bitcast i8* %8 to %struct.yy_buffer_state**
  store %struct.yy_buffer_state** %9, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %10 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %11 = icmp ne %struct.yy_buffer_state** %10, null
  br i1 %11, label %13, label %12

; <label>:12:                                     ; preds = %5
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([49 x i8], [49 x i8]* @.str.29, i32 0, i32 0)) #16
  unreachable

; <label>:13:                                     ; preds = %5
  %14 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %15 = bitcast %struct.yy_buffer_state** %14 to i8*
  %16 = load i64, i64* %1, align 8
  %17 = mul i64 %16, 8
  call void @llvm.memset.p0i8.i64(i8* align 8 %15, i8 0, i64 %17, i1 false)
  %18 = load i64, i64* %1, align 8
  store i64 %18, i64* @_ZL19yy_buffer_stack_max, align 8
  store i64 0, i64* @_ZL19yy_buffer_stack_top, align 8
  br label %45

; <label>:19:                                     ; preds = %0
  %20 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %21 = load i64, i64* @_ZL19yy_buffer_stack_max, align 8
  %22 = sub i64 %21, 1
  %23 = icmp uge i64 %20, %22
  br i1 %23, label %24, label %45

; <label>:24:                                     ; preds = %19
  store i64 8, i64* %2, align 8
  %25 = load i64, i64* @_ZL19yy_buffer_stack_max, align 8
  %26 = load i64, i64* %2, align 8
  %27 = add i64 %25, %26
  store i64 %27, i64* %1, align 8
  %28 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %29 = bitcast %struct.yy_buffer_state** %28 to i8*
  %30 = load i64, i64* %1, align 8
  %31 = mul i64 %30, 8
  %32 = call i8* @_Z9yyreallocPvm(i8* %29, i64 %31)
  %33 = bitcast i8* %32 to %struct.yy_buffer_state**
  store %struct.yy_buffer_state** %33, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %34 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %35 = icmp ne %struct.yy_buffer_state** %34, null
  br i1 %35, label %37, label %36

; <label>:36:                                     ; preds = %24
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([49 x i8], [49 x i8]* @.str.29, i32 0, i32 0)) #16
  unreachable

; <label>:37:                                     ; preds = %24
  %38 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %39 = load i64, i64* @_ZL19yy_buffer_stack_max, align 8
  %40 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %38, i64 %39
  %41 = bitcast %struct.yy_buffer_state** %40 to i8*
  %42 = load i64, i64* %2, align 8
  %43 = mul i64 %42, 8
  call void @llvm.memset.p0i8.i64(i8* align 8 %41, i8 0, i64 %43, i1 false)
  %44 = load i64, i64* %1, align 8
  store i64 %44, i64* @_ZL19yy_buffer_stack_max, align 8
  br label %45

; <label>:45:                                     ; preds = %13, %37, %19
  ret void
}

; Function Attrs: noinline optnone uwtable
define dso_local %struct.yy_buffer_state* @_Z16yy_create_bufferP8_IO_FILEi(%struct._IO_FILE*, i32) #6 {
  %3 = alloca %struct._IO_FILE*, align 8
  %4 = alloca i32, align 4
  %5 = alloca %struct.yy_buffer_state*, align 8
  store %struct._IO_FILE* %0, %struct._IO_FILE** %3, align 8
  store i32 %1, i32* %4, align 4
  %6 = call i8* @_Z7yyallocm(i64 64)
  %7 = bitcast i8* %6 to %struct.yy_buffer_state*
  store %struct.yy_buffer_state* %7, %struct.yy_buffer_state** %5, align 8
  %8 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %9 = icmp ne %struct.yy_buffer_state* %8, null
  br i1 %9, label %11, label %10

; <label>:10:                                     ; preds = %2
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([44 x i8], [44 x i8]* @.str.21, i32 0, i32 0)) #16
  unreachable

; <label>:11:                                     ; preds = %2
  %12 = load i32, i32* %4, align 4
  %13 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %14 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %13, i32 0, i32 3
  store i32 %12, i32* %14, align 8
  %15 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %16 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %15, i32 0, i32 3
  %17 = load i32, i32* %16, align 8
  %18 = add nsw i32 %17, 2
  %19 = sext i32 %18 to i64
  %20 = call i8* @_Z7yyallocm(i64 %19)
  %21 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %22 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %21, i32 0, i32 1
  store i8* %20, i8** %22, align 8
  %23 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %24 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %23, i32 0, i32 1
  %25 = load i8*, i8** %24, align 8
  %26 = icmp ne i8* %25, null
  br i1 %26, label %28, label %27

; <label>:27:                                     ; preds = %11
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([44 x i8], [44 x i8]* @.str.21, i32 0, i32 0)) #16
  unreachable

; <label>:28:                                     ; preds = %11
  %29 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %30 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %29, i32 0, i32 5
  store i32 1, i32* %30, align 8
  %31 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %32 = load %struct._IO_FILE*, %struct._IO_FILE** %3, align 8
  call void @_ZL14yy_init_bufferP15yy_buffer_stateP8_IO_FILE(%struct.yy_buffer_state* %31, %struct._IO_FILE* %32)
  %33 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  ret %struct.yy_buffer_state* %33
}

; Function Attrs: noinline nounwind optnone uwtable
define internal void @_ZL20yy_load_buffer_statev() #4 {
  %1 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %2 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %3 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %1, i64 %2
  %4 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  %5 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %4, i32 0, i32 4
  %6 = load i32, i32* %5, align 4
  store i32 %6, i32* @_ZL10yy_n_chars, align 4
  %7 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %8 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %9 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %7, i64 %8
  %10 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %9, align 8
  %11 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %10, i32 0, i32 2
  %12 = load i8*, i8** %11, align 8
  store i8* %12, i8** @_ZL10yy_c_buf_p, align 8
  store i8* %12, i8** @yytext, align 8
  %13 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %14 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %15 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %13, i64 %14
  %16 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %15, align 8
  %17 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %16, i32 0, i32 0
  %18 = load %struct._IO_FILE*, %struct._IO_FILE** %17, align 8
  store %struct._IO_FILE* %18, %struct._IO_FILE** @yyin, align 8
  %19 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %20 = load i8, i8* %19, align 1
  store i8 %20, i8* @_ZL12yy_hold_char, align 1
  ret void
}

declare dso_local i32 @printf(i8*, ...) #1

; Function Attrs: nobuiltin
declare dso_local noalias i8* @_Znwm(i64) #7

; Function Attrs: nounwind
declare dso_local void @_ZNSaIcEC1Ev(%"class.std::allocator"*) unnamed_addr #2

declare dso_local void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcmRKS3_(%"class.std::__cxx11::basic_string"*, i8*, i64, %"class.std::allocator"* dereferenceable(1)) unnamed_addr #1

declare dso_local i32 @__gxx_personality_v0(...)

; Function Attrs: nounwind
declare dso_local void @_ZNSaIcED1Ev(%"class.std::allocator"*) unnamed_addr #2

; Function Attrs: nobuiltin nounwind
declare dso_local void @_ZdlPv(i8*) #8

declare dso_local i64 @fwrite(i8*, i64, i64, %struct._IO_FILE*) #1

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @_ZL21yy_get_previous_statev() #4 {
  %1 = alloca i32, align 4
  %2 = alloca i8*, align 8
  %3 = alloca i8, align 1
  %4 = load i32, i32* @_ZL8yy_start, align 4
  store i32 %4, i32* %1, align 4
  %5 = load i8*, i8** @yytext, align 8
  %6 = getelementptr inbounds i8, i8* %5, i64 0
  store i8* %6, i8** %2, align 8
  br label %7

; <label>:7:                                      ; preds = %77, %0
  %8 = load i8*, i8** %2, align 8
  %9 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %10 = icmp ult i8* %8, %9
  br i1 %10, label %11, label %80

; <label>:11:                                     ; preds = %7
  %12 = load i8*, i8** %2, align 8
  %13 = load i8, i8* %12, align 1
  %14 = icmp ne i8 %13, 0
  br i1 %14, label %15, label %22

; <label>:15:                                     ; preds = %11
  %16 = load i8*, i8** %2, align 8
  %17 = load i8, i8* %16, align 1
  %18 = zext i8 %17 to i64
  %19 = getelementptr inbounds [256 x i8], [256 x i8]* @_ZL5yy_ec, i64 0, i64 %18
  %20 = load i8, i8* %19, align 1
  %21 = zext i8 %20 to i32
  br label %23

; <label>:22:                                     ; preds = %11
  br label %23

; <label>:23:                                     ; preds = %22, %15
  %24 = phi i32 [ %21, %15 ], [ 1, %22 ]
  %25 = trunc i32 %24 to i8
  store i8 %25, i8* %3, align 1
  %26 = load i32, i32* %1, align 4
  %27 = sext i32 %26 to i64
  %28 = getelementptr inbounds [33 x i16], [33 x i16]* @_ZL9yy_accept, i64 0, i64 %27
  %29 = load i16, i16* %28, align 2
  %30 = icmp ne i16 %29, 0
  br i1 %30, label %31, label %34

; <label>:31:                                     ; preds = %23
  %32 = load i32, i32* %1, align 4
  store i32 %32, i32* @_ZL23yy_last_accepting_state, align 4
  %33 = load i8*, i8** %2, align 8
  store i8* %33, i8** @_ZL22yy_last_accepting_cpos, align 8
  br label %34

; <label>:34:                                     ; preds = %31, %23
  br label %35

; <label>:35:                                     ; preds = %63, %34
  %36 = load i32, i32* %1, align 4
  %37 = sext i32 %36 to i64
  %38 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL7yy_base, i64 0, i64 %37
  %39 = load i16, i16* %38, align 2
  %40 = sext i16 %39 to i32
  %41 = load i8, i8* %3, align 1
  %42 = zext i8 %41 to i32
  %43 = add nsw i32 %40, %42
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds [55 x i16], [55 x i16]* @_ZL6yy_chk, i64 0, i64 %44
  %46 = load i16, i16* %45, align 2
  %47 = sext i16 %46 to i32
  %48 = load i32, i32* %1, align 4
  %49 = icmp ne i32 %47, %48
  br i1 %49, label %50, label %64

; <label>:50:                                     ; preds = %35
  %51 = load i32, i32* %1, align 4
  %52 = sext i32 %51 to i64
  %53 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL6yy_def, i64 0, i64 %52
  %54 = load i16, i16* %53, align 2
  %55 = sext i16 %54 to i32
  store i32 %55, i32* %1, align 4
  %56 = load i32, i32* %1, align 4
  %57 = icmp sge i32 %56, 33
  br i1 %57, label %58, label %63

; <label>:58:                                     ; preds = %50
  %59 = load i8, i8* %3, align 1
  %60 = zext i8 %59 to i64
  %61 = getelementptr inbounds [20 x i8], [20 x i8]* @_ZL7yy_meta, i64 0, i64 %60
  %62 = load i8, i8* %61, align 1
  store i8 %62, i8* %3, align 1
  br label %63

; <label>:63:                                     ; preds = %58, %50
  br label %35

; <label>:64:                                     ; preds = %35
  %65 = load i32, i32* %1, align 4
  %66 = sext i32 %65 to i64
  %67 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL7yy_base, i64 0, i64 %66
  %68 = load i16, i16* %67, align 2
  %69 = sext i16 %68 to i32
  %70 = load i8, i8* %3, align 1
  %71 = zext i8 %70 to i32
  %72 = add nsw i32 %69, %71
  %73 = sext i32 %72 to i64
  %74 = getelementptr inbounds [55 x i16], [55 x i16]* @_ZL6yy_nxt, i64 0, i64 %73
  %75 = load i16, i16* %74, align 2
  %76 = sext i16 %75 to i32
  store i32 %76, i32* %1, align 4
  br label %77

; <label>:77:                                     ; preds = %64
  %78 = load i8*, i8** %2, align 8
  %79 = getelementptr inbounds i8, i8* %78, i32 1
  store i8* %79, i8** %2, align 8
  br label %7

; <label>:80:                                     ; preds = %7
  %81 = load i32, i32* %1, align 4
  ret i32 %81
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @_ZL16yy_try_NUL_transi(i32) #4 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i8*, align 8
  %5 = alloca i8, align 1
  store i32 %0, i32* %2, align 4
  %6 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  store i8* %6, i8** %4, align 8
  store i8 1, i8* %5, align 1
  %7 = load i32, i32* %2, align 4
  %8 = sext i32 %7 to i64
  %9 = getelementptr inbounds [33 x i16], [33 x i16]* @_ZL9yy_accept, i64 0, i64 %8
  %10 = load i16, i16* %9, align 2
  %11 = icmp ne i16 %10, 0
  br i1 %11, label %12, label %15

; <label>:12:                                     ; preds = %1
  %13 = load i32, i32* %2, align 4
  store i32 %13, i32* @_ZL23yy_last_accepting_state, align 4
  %14 = load i8*, i8** %4, align 8
  store i8* %14, i8** @_ZL22yy_last_accepting_cpos, align 8
  br label %15

; <label>:15:                                     ; preds = %12, %1
  br label %16

; <label>:16:                                     ; preds = %44, %15
  %17 = load i32, i32* %2, align 4
  %18 = sext i32 %17 to i64
  %19 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL7yy_base, i64 0, i64 %18
  %20 = load i16, i16* %19, align 2
  %21 = sext i16 %20 to i32
  %22 = load i8, i8* %5, align 1
  %23 = zext i8 %22 to i32
  %24 = add nsw i32 %21, %23
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [55 x i16], [55 x i16]* @_ZL6yy_chk, i64 0, i64 %25
  %27 = load i16, i16* %26, align 2
  %28 = sext i16 %27 to i32
  %29 = load i32, i32* %2, align 4
  %30 = icmp ne i32 %28, %29
  br i1 %30, label %31, label %45

; <label>:31:                                     ; preds = %16
  %32 = load i32, i32* %2, align 4
  %33 = sext i32 %32 to i64
  %34 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL6yy_def, i64 0, i64 %33
  %35 = load i16, i16* %34, align 2
  %36 = sext i16 %35 to i32
  store i32 %36, i32* %2, align 4
  %37 = load i32, i32* %2, align 4
  %38 = icmp sge i32 %37, 33
  br i1 %38, label %39, label %44

; <label>:39:                                     ; preds = %31
  %40 = load i8, i8* %5, align 1
  %41 = zext i8 %40 to i64
  %42 = getelementptr inbounds [20 x i8], [20 x i8]* @_ZL7yy_meta, i64 0, i64 %41
  %43 = load i8, i8* %42, align 1
  store i8 %43, i8* %5, align 1
  br label %44

; <label>:44:                                     ; preds = %39, %31
  br label %16

; <label>:45:                                     ; preds = %16
  %46 = load i32, i32* %2, align 4
  %47 = sext i32 %46 to i64
  %48 = getelementptr inbounds [34 x i16], [34 x i16]* @_ZL7yy_base, i64 0, i64 %47
  %49 = load i16, i16* %48, align 2
  %50 = sext i16 %49 to i32
  %51 = load i8, i8* %5, align 1
  %52 = zext i8 %51 to i32
  %53 = add nsw i32 %50, %52
  %54 = sext i32 %53 to i64
  %55 = getelementptr inbounds [55 x i16], [55 x i16]* @_ZL6yy_nxt, i64 0, i64 %54
  %56 = load i16, i16* %55, align 2
  %57 = sext i16 %56 to i32
  store i32 %57, i32* %2, align 4
  %58 = load i32, i32* %2, align 4
  %59 = icmp eq i32 %58, 32
  %60 = zext i1 %59 to i32
  store i32 %60, i32* %3, align 4
  %61 = load i32, i32* %3, align 4
  %62 = icmp ne i32 %61, 0
  br i1 %62, label %63, label %64

; <label>:63:                                     ; preds = %45
  br label %66

; <label>:64:                                     ; preds = %45
  %65 = load i32, i32* %2, align 4
  br label %66

; <label>:66:                                     ; preds = %64, %63
  %67 = phi i32 [ 0, %63 ], [ %65, %64 ]
  ret i32 %67
}

; Function Attrs: noinline optnone uwtable
define internal i32 @_ZL18yy_get_next_bufferv() #6 {
  %1 = alloca i32, align 4
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca %struct.yy_buffer_state*, align 8
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %15 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %16 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %14, i64 %15
  %17 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %16, align 8
  %18 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %17, i32 0, i32 1
  %19 = load i8*, i8** %18, align 8
  store i8* %19, i8** %2, align 8
  %20 = load i8*, i8** @yytext, align 8
  store i8* %20, i8** %3, align 8
  %21 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %22 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %23 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %24 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %22, i64 %23
  %25 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %24, align 8
  %26 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %25, i32 0, i32 1
  %27 = load i8*, i8** %26, align 8
  %28 = load i32, i32* @_ZL10yy_n_chars, align 4
  %29 = add nsw i32 %28, 1
  %30 = sext i32 %29 to i64
  %31 = getelementptr inbounds i8, i8* %27, i64 %30
  %32 = icmp ugt i8* %21, %31
  br i1 %32, label %33, label %34

; <label>:33:                                     ; preds = %0
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([56 x i8], [56 x i8]* @.str.25, i32 0, i32 0)) #16
  unreachable

; <label>:34:                                     ; preds = %0
  %35 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %36 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %37 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %35, i64 %36
  %38 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %37, align 8
  %39 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %38, i32 0, i32 10
  %40 = load i32, i32* %39, align 4
  %41 = icmp eq i32 %40, 0
  br i1 %41, label %42, label %52

; <label>:42:                                     ; preds = %34
  %43 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %44 = load i8*, i8** @yytext, align 8
  %45 = ptrtoint i8* %43 to i64
  %46 = ptrtoint i8* %44 to i64
  %47 = sub i64 %45, %46
  %48 = sub nsw i64 %47, 0
  %49 = icmp eq i64 %48, 1
  br i1 %49, label %50, label %51

; <label>:50:                                     ; preds = %42
  store i32 1, i32* %1, align 4
  br label %383

; <label>:51:                                     ; preds = %42
  store i32 2, i32* %1, align 4
  br label %383

; <label>:52:                                     ; preds = %34
  %53 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %54 = load i8*, i8** @yytext, align 8
  %55 = ptrtoint i8* %53 to i64
  %56 = ptrtoint i8* %54 to i64
  %57 = sub i64 %55, %56
  %58 = sub nsw i64 %57, 1
  %59 = trunc i64 %58 to i32
  store i32 %59, i32* %4, align 4
  store i32 0, i32* %5, align 4
  br label %60

; <label>:60:                                     ; preds = %70, %52
  %61 = load i32, i32* %5, align 4
  %62 = load i32, i32* %4, align 4
  %63 = icmp slt i32 %61, %62
  br i1 %63, label %64, label %73

; <label>:64:                                     ; preds = %60
  %65 = load i8*, i8** %3, align 8
  %66 = getelementptr inbounds i8, i8* %65, i32 1
  store i8* %66, i8** %3, align 8
  %67 = load i8, i8* %65, align 1
  %68 = load i8*, i8** %2, align 8
  %69 = getelementptr inbounds i8, i8* %68, i32 1
  store i8* %69, i8** %2, align 8
  store i8 %67, i8* %68, align 1
  br label %70

; <label>:70:                                     ; preds = %64
  %71 = load i32, i32* %5, align 4
  %72 = add nsw i32 %71, 1
  store i32 %72, i32* %5, align 4
  br label %60

; <label>:73:                                     ; preds = %60
  %74 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %75 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %76 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %74, i64 %75
  %77 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %76, align 8
  %78 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %77, i32 0, i32 11
  %79 = load i32, i32* %78, align 8
  %80 = icmp eq i32 %79, 2
  br i1 %80, label %81, label %87

; <label>:81:                                     ; preds = %73
  store i32 0, i32* @_ZL10yy_n_chars, align 4
  %82 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %83 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %84 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %82, i64 %83
  %85 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %84, align 8
  %86 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %85, i32 0, i32 4
  store i32 0, i32* %86, align 4
  br label %288

; <label>:87:                                     ; preds = %73
  %88 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %89 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %90 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %88, i64 %89
  %91 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %90, align 8
  %92 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %91, i32 0, i32 3
  %93 = load i32, i32* %92, align 8
  %94 = load i32, i32* %4, align 4
  %95 = sub nsw i32 %93, %94
  %96 = sub nsw i32 %95, 1
  store i32 %96, i32* %7, align 4
  br label %97

; <label>:97:                                     ; preds = %159, %87
  %98 = load i32, i32* %7, align 4
  %99 = icmp sle i32 %98, 0
  br i1 %99, label %100, label %175

; <label>:100:                                    ; preds = %97
  %101 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %102 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %103 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %101, i64 %102
  %104 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %103, align 8
  store %struct.yy_buffer_state* %104, %struct.yy_buffer_state** %8, align 8
  %105 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %106 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %107 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %106, i32 0, i32 1
  %108 = load i8*, i8** %107, align 8
  %109 = ptrtoint i8* %105 to i64
  %110 = ptrtoint i8* %108 to i64
  %111 = sub i64 %109, %110
  %112 = trunc i64 %111 to i32
  store i32 %112, i32* %9, align 4
  %113 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %114 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %113, i32 0, i32 5
  %115 = load i32, i32* %114, align 8
  %116 = icmp ne i32 %115, 0
  br i1 %116, label %117, label %150

; <label>:117:                                    ; preds = %100
  %118 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %119 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %118, i32 0, i32 3
  %120 = load i32, i32* %119, align 8
  %121 = mul nsw i32 %120, 2
  store i32 %121, i32* %10, align 4
  %122 = load i32, i32* %10, align 4
  %123 = icmp sle i32 %122, 0
  br i1 %123, label %124, label %133

; <label>:124:                                    ; preds = %117
  %125 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %126 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %125, i32 0, i32 3
  %127 = load i32, i32* %126, align 8
  %128 = sdiv i32 %127, 8
  %129 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %130 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %129, i32 0, i32 3
  %131 = load i32, i32* %130, align 8
  %132 = add nsw i32 %131, %128
  store i32 %132, i32* %130, align 8
  br label %138

; <label>:133:                                    ; preds = %117
  %134 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %135 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %134, i32 0, i32 3
  %136 = load i32, i32* %135, align 8
  %137 = mul nsw i32 %136, 2
  store i32 %137, i32* %135, align 8
  br label %138

; <label>:138:                                    ; preds = %133, %124
  %139 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %140 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %139, i32 0, i32 1
  %141 = load i8*, i8** %140, align 8
  %142 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %143 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %142, i32 0, i32 3
  %144 = load i32, i32* %143, align 8
  %145 = add nsw i32 %144, 2
  %146 = sext i32 %145 to i64
  %147 = call i8* @_Z9yyreallocPvm(i8* %141, i64 %146)
  %148 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %149 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %148, i32 0, i32 1
  store i8* %147, i8** %149, align 8
  br label %153

; <label>:150:                                    ; preds = %100
  %151 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %152 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %151, i32 0, i32 1
  store i8* null, i8** %152, align 8
  br label %153

; <label>:153:                                    ; preds = %150, %138
  %154 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %155 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %154, i32 0, i32 1
  %156 = load i8*, i8** %155, align 8
  %157 = icmp ne i8* %156, null
  br i1 %157, label %159, label %158

; <label>:158:                                    ; preds = %153
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([44 x i8], [44 x i8]* @.str.26, i32 0, i32 0)) #16
  unreachable

; <label>:159:                                    ; preds = %153
  %160 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  %161 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %160, i32 0, i32 1
  %162 = load i8*, i8** %161, align 8
  %163 = load i32, i32* %9, align 4
  %164 = sext i32 %163 to i64
  %165 = getelementptr inbounds i8, i8* %162, i64 %164
  store i8* %165, i8** @_ZL10yy_c_buf_p, align 8
  %166 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %167 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %168 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %166, i64 %167
  %169 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %168, align 8
  %170 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %169, i32 0, i32 3
  %171 = load i32, i32* %170, align 8
  %172 = load i32, i32* %4, align 4
  %173 = sub nsw i32 %171, %172
  %174 = sub nsw i32 %173, 1
  store i32 %174, i32* %7, align 4
  br label %97

; <label>:175:                                    ; preds = %97
  %176 = load i32, i32* %7, align 4
  %177 = icmp sgt i32 %176, 8192
  br i1 %177, label %178, label %179

; <label>:178:                                    ; preds = %175
  store i32 8192, i32* %7, align 4
  br label %179

; <label>:179:                                    ; preds = %178, %175
  %180 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %181 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %182 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %180, i64 %181
  %183 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %182, align 8
  %184 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %183, i32 0, i32 6
  %185 = load i32, i32* %184, align 4
  %186 = icmp ne i32 %185, 0
  br i1 %186, label %187, label %248

; <label>:187:                                    ; preds = %179
  store i32 42, i32* %11, align 4
  store i32 0, i32* %12, align 4
  br label %188

; <label>:188:                                    ; preds = %216, %187
  %189 = load i32, i32* %12, align 4
  %190 = load i32, i32* %7, align 4
  %191 = icmp slt i32 %189, %190
  br i1 %191, label %192, label %199

; <label>:192:                                    ; preds = %188
  %193 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %194 = call i32 @getc(%struct._IO_FILE* %193)
  store i32 %194, i32* %11, align 4
  %195 = icmp ne i32 %194, -1
  br i1 %195, label %196, label %199

; <label>:196:                                    ; preds = %192
  %197 = load i32, i32* %11, align 4
  %198 = icmp ne i32 %197, 10
  br label %199

; <label>:199:                                    ; preds = %196, %192, %188
  %200 = phi i1 [ false, %192 ], [ false, %188 ], [ %198, %196 ]
  br i1 %200, label %201, label %219

; <label>:201:                                    ; preds = %199
  %202 = load i32, i32* %11, align 4
  %203 = trunc i32 %202 to i8
  %204 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %205 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %206 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %204, i64 %205
  %207 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %206, align 8
  %208 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %207, i32 0, i32 1
  %209 = load i8*, i8** %208, align 8
  %210 = load i32, i32* %4, align 4
  %211 = sext i32 %210 to i64
  %212 = getelementptr inbounds i8, i8* %209, i64 %211
  %213 = load i32, i32* %12, align 4
  %214 = sext i32 %213 to i64
  %215 = getelementptr inbounds i8, i8* %212, i64 %214
  store i8 %203, i8* %215, align 1
  br label %216

; <label>:216:                                    ; preds = %201
  %217 = load i32, i32* %12, align 4
  %218 = add nsw i32 %217, 1
  store i32 %218, i32* %12, align 4
  br label %188

; <label>:219:                                    ; preds = %199
  %220 = load i32, i32* %11, align 4
  %221 = icmp eq i32 %220, 10
  br i1 %221, label %222, label %238

; <label>:222:                                    ; preds = %219
  %223 = load i32, i32* %11, align 4
  %224 = trunc i32 %223 to i8
  %225 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %226 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %227 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %225, i64 %226
  %228 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %227, align 8
  %229 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %228, i32 0, i32 1
  %230 = load i8*, i8** %229, align 8
  %231 = load i32, i32* %4, align 4
  %232 = sext i32 %231 to i64
  %233 = getelementptr inbounds i8, i8* %230, i64 %232
  %234 = load i32, i32* %12, align 4
  %235 = add nsw i32 %234, 1
  store i32 %235, i32* %12, align 4
  %236 = sext i32 %234 to i64
  %237 = getelementptr inbounds i8, i8* %233, i64 %236
  store i8 %224, i8* %237, align 1
  br label %238

; <label>:238:                                    ; preds = %222, %219
  %239 = load i32, i32* %11, align 4
  %240 = icmp eq i32 %239, -1
  br i1 %240, label %241, label %246

; <label>:241:                                    ; preds = %238
  %242 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %243 = call i32 @ferror(%struct._IO_FILE* %242) #3
  %244 = icmp ne i32 %243, 0
  br i1 %244, label %245, label %246

; <label>:245:                                    ; preds = %241
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.27, i32 0, i32 0)) #16
  unreachable

; <label>:246:                                    ; preds = %241, %238
  %247 = load i32, i32* %12, align 4
  store i32 %247, i32* @_ZL10yy_n_chars, align 4
  br label %281

; <label>:248:                                    ; preds = %179
  %249 = call i32* @__errno_location() #17
  store i32 0, i32* %249, align 4
  br label %250

; <label>:250:                                    ; preds = %277, %248
  %251 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %252 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %253 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %251, i64 %252
  %254 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %253, align 8
  %255 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %254, i32 0, i32 1
  %256 = load i8*, i8** %255, align 8
  %257 = load i32, i32* %4, align 4
  %258 = sext i32 %257 to i64
  %259 = getelementptr inbounds i8, i8* %256, i64 %258
  %260 = load i32, i32* %7, align 4
  %261 = sext i32 %260 to i64
  %262 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %263 = call i64 @fread(i8* %259, i64 1, i64 %261, %struct._IO_FILE* %262)
  %264 = trunc i64 %263 to i32
  store i32 %264, i32* @_ZL10yy_n_chars, align 4
  %265 = icmp eq i32 %264, 0
  br i1 %265, label %266, label %270

; <label>:266:                                    ; preds = %250
  %267 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %268 = call i32 @ferror(%struct._IO_FILE* %267) #3
  %269 = icmp ne i32 %268, 0
  br label %270

; <label>:270:                                    ; preds = %266, %250
  %271 = phi i1 [ false, %250 ], [ %269, %266 ]
  br i1 %271, label %272, label %280

; <label>:272:                                    ; preds = %270
  %273 = call i32* @__errno_location() #17
  %274 = load i32, i32* %273, align 4
  %275 = icmp ne i32 %274, 4
  br i1 %275, label %276, label %277

; <label>:276:                                    ; preds = %272
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str.27, i32 0, i32 0)) #16
  unreachable

; <label>:277:                                    ; preds = %272
  %278 = call i32* @__errno_location() #17
  store i32 0, i32* %278, align 4
  %279 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  call void @clearerr(%struct._IO_FILE* %279) #3
  br label %250

; <label>:280:                                    ; preds = %270
  br label %281

; <label>:281:                                    ; preds = %280, %246
  %282 = load i32, i32* @_ZL10yy_n_chars, align 4
  %283 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %284 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %285 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %283, i64 %284
  %286 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %285, align 8
  %287 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %286, i32 0, i32 4
  store i32 %282, i32* %287, align 4
  br label %288

; <label>:288:                                    ; preds = %281, %81
  %289 = load i32, i32* @_ZL10yy_n_chars, align 4
  %290 = icmp eq i32 %289, 0
  br i1 %290, label %291, label %303

; <label>:291:                                    ; preds = %288
  %292 = load i32, i32* %4, align 4
  %293 = icmp eq i32 %292, 0
  br i1 %293, label %294, label %296

; <label>:294:                                    ; preds = %291
  store i32 1, i32* %6, align 4
  %295 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  call void @_Z9yyrestartP8_IO_FILE(%struct._IO_FILE* %295)
  br label %302

; <label>:296:                                    ; preds = %291
  store i32 2, i32* %6, align 4
  %297 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %298 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %299 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %297, i64 %298
  %300 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %299, align 8
  %301 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %300, i32 0, i32 11
  store i32 2, i32* %301, align 8
  br label %302

; <label>:302:                                    ; preds = %296, %294
  br label %304

; <label>:303:                                    ; preds = %288
  store i32 0, i32* %6, align 4
  br label %304

; <label>:304:                                    ; preds = %303, %302
  %305 = load i32, i32* @_ZL10yy_n_chars, align 4
  %306 = load i32, i32* %4, align 4
  %307 = add nsw i32 %305, %306
  %308 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %309 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %310 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %308, i64 %309
  %311 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %310, align 8
  %312 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %311, i32 0, i32 3
  %313 = load i32, i32* %312, align 8
  %314 = icmp sgt i32 %307, %313
  br i1 %314, label %315, label %352

; <label>:315:                                    ; preds = %304
  %316 = load i32, i32* @_ZL10yy_n_chars, align 4
  %317 = load i32, i32* %4, align 4
  %318 = add nsw i32 %316, %317
  %319 = load i32, i32* @_ZL10yy_n_chars, align 4
  %320 = ashr i32 %319, 1
  %321 = add nsw i32 %318, %320
  store i32 %321, i32* %13, align 4
  %322 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %323 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %324 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %322, i64 %323
  %325 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %324, align 8
  %326 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %325, i32 0, i32 1
  %327 = load i8*, i8** %326, align 8
  %328 = load i32, i32* %13, align 4
  %329 = sext i32 %328 to i64
  %330 = call i8* @_Z9yyreallocPvm(i8* %327, i64 %329)
  %331 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %332 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %333 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %331, i64 %332
  %334 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %333, align 8
  %335 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %334, i32 0, i32 1
  store i8* %330, i8** %335, align 8
  %336 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %337 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %338 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %336, i64 %337
  %339 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %338, align 8
  %340 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %339, i32 0, i32 1
  %341 = load i8*, i8** %340, align 8
  %342 = icmp ne i8* %341, null
  br i1 %342, label %344, label %343

; <label>:343:                                    ; preds = %315
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([46 x i8], [46 x i8]* @.str.28, i32 0, i32 0)) #16
  unreachable

; <label>:344:                                    ; preds = %315
  %345 = load i32, i32* %13, align 4
  %346 = sub nsw i32 %345, 2
  %347 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %348 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %349 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %347, i64 %348
  %350 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %349, align 8
  %351 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %350, i32 0, i32 3
  store i32 %346, i32* %351, align 8
  br label %352

; <label>:352:                                    ; preds = %344, %304
  %353 = load i32, i32* %4, align 4
  %354 = load i32, i32* @_ZL10yy_n_chars, align 4
  %355 = add nsw i32 %354, %353
  store i32 %355, i32* @_ZL10yy_n_chars, align 4
  %356 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %357 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %358 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %356, i64 %357
  %359 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %358, align 8
  %360 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %359, i32 0, i32 1
  %361 = load i8*, i8** %360, align 8
  %362 = load i32, i32* @_ZL10yy_n_chars, align 4
  %363 = sext i32 %362 to i64
  %364 = getelementptr inbounds i8, i8* %361, i64 %363
  store i8 0, i8* %364, align 1
  %365 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %366 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %367 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %365, i64 %366
  %368 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %367, align 8
  %369 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %368, i32 0, i32 1
  %370 = load i8*, i8** %369, align 8
  %371 = load i32, i32* @_ZL10yy_n_chars, align 4
  %372 = add nsw i32 %371, 1
  %373 = sext i32 %372 to i64
  %374 = getelementptr inbounds i8, i8* %370, i64 %373
  store i8 0, i8* %374, align 1
  %375 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %376 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %377 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %375, i64 %376
  %378 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %377, align 8
  %379 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %378, i32 0, i32 1
  %380 = load i8*, i8** %379, align 8
  %381 = getelementptr inbounds i8, i8* %380, i64 0
  store i8* %381, i8** @yytext, align 8
  %382 = load i32, i32* %6, align 4
  store i32 %382, i32* %1, align 4
  br label %383

; <label>:383:                                    ; preds = %352, %51, %50
  %384 = load i32, i32* %1, align 4
  ret i32 %384
}

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z9yyrestartP8_IO_FILE(%struct._IO_FILE*) #6 {
  %2 = alloca %struct._IO_FILE*, align 8
  store %struct._IO_FILE* %0, %struct._IO_FILE** %2, align 8
  %3 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %4 = icmp ne %struct.yy_buffer_state** %3, null
  br i1 %4, label %5, label %10

; <label>:5:                                      ; preds = %1
  %6 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %7 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %8 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, i64 %7
  %9 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  br label %11

; <label>:10:                                     ; preds = %1
  br label %11

; <label>:11:                                     ; preds = %10, %5
  %12 = phi %struct.yy_buffer_state* [ %9, %5 ], [ null, %10 ]
  %13 = icmp ne %struct.yy_buffer_state* %12, null
  br i1 %13, label %20, label %14

; <label>:14:                                     ; preds = %11
  call void @_ZL21yyensure_buffer_stackv()
  %15 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  %16 = call %struct.yy_buffer_state* @_Z16yy_create_bufferP8_IO_FILEi(%struct._IO_FILE* %15, i32 16384)
  %17 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %18 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %19 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %17, i64 %18
  store %struct.yy_buffer_state* %16, %struct.yy_buffer_state** %19, align 8
  br label %20

; <label>:20:                                     ; preds = %14, %11
  %21 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %22 = icmp ne %struct.yy_buffer_state** %21, null
  br i1 %22, label %23, label %28

; <label>:23:                                     ; preds = %20
  %24 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %25 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %26 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %24, i64 %25
  %27 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %26, align 8
  br label %29

; <label>:28:                                     ; preds = %20
  br label %29

; <label>:29:                                     ; preds = %28, %23
  %30 = phi %struct.yy_buffer_state* [ %27, %23 ], [ null, %28 ]
  %31 = load %struct._IO_FILE*, %struct._IO_FILE** %2, align 8
  call void @_ZL14yy_init_bufferP15yy_buffer_stateP8_IO_FILE(%struct.yy_buffer_state* %30, %struct._IO_FILE* %31)
  call void @_ZL20yy_load_buffer_statev()
  ret void
}

; Function Attrs: noinline noreturn optnone uwtable
define internal void @_ZL14yy_fatal_errorPKc(i8*) #9 {
  %2 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  %4 = load i8*, i8** %2, align 8
  %5 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.30, i32 0, i32 0), i8* %4)
  call void @exit(i32 2) #5
  unreachable
                                                  ; No predecessors!
  unreachable
}

; Function Attrs: noinline optnone uwtable
define internal void @_ZL14yy_init_bufferP15yy_buffer_stateP8_IO_FILE(%struct.yy_buffer_state*, %struct._IO_FILE*) #6 {
  %3 = alloca %struct.yy_buffer_state*, align 8
  %4 = alloca %struct._IO_FILE*, align 8
  %5 = alloca i32, align 4
  store %struct.yy_buffer_state* %0, %struct.yy_buffer_state** %3, align 8
  store %struct._IO_FILE* %1, %struct._IO_FILE** %4, align 8
  %6 = call i32* @__errno_location() #17
  %7 = load i32, i32* %6, align 4
  store i32 %7, i32* %5, align 4
  %8 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  call void @_Z15yy_flush_bufferP15yy_buffer_state(%struct.yy_buffer_state* %8)
  %9 = load %struct._IO_FILE*, %struct._IO_FILE** %4, align 8
  %10 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  %11 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %10, i32 0, i32 0
  store %struct._IO_FILE* %9, %struct._IO_FILE** %11, align 8
  %12 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  %13 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %12, i32 0, i32 10
  store i32 1, i32* %13, align 4
  %14 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  %15 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %16 = icmp ne %struct.yy_buffer_state** %15, null
  br i1 %16, label %17, label %22

; <label>:17:                                     ; preds = %2
  %18 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %19 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %20 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %18, i64 %19
  %21 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %20, align 8
  br label %23

; <label>:22:                                     ; preds = %2
  br label %23

; <label>:23:                                     ; preds = %22, %17
  %24 = phi %struct.yy_buffer_state* [ %21, %17 ], [ null, %22 ]
  %25 = icmp ne %struct.yy_buffer_state* %14, %24
  br i1 %25, label %26, label %31

; <label>:26:                                     ; preds = %23
  %27 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  %28 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %27, i32 0, i32 8
  store i32 1, i32* %28, align 4
  %29 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  %30 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %29, i32 0, i32 9
  store i32 0, i32* %30, align 8
  br label %31

; <label>:31:                                     ; preds = %26, %23
  %32 = load %struct._IO_FILE*, %struct._IO_FILE** %4, align 8
  %33 = icmp ne %struct._IO_FILE* %32, null
  br i1 %33, label %34, label %40

; <label>:34:                                     ; preds = %31
  %35 = load %struct._IO_FILE*, %struct._IO_FILE** %4, align 8
  %36 = call i32 @fileno(%struct._IO_FILE* %35) #3
  %37 = call i32 @isatty(i32 %36) #3
  %38 = icmp sgt i32 %37, 0
  %39 = zext i1 %38 to i32
  br label %41

; <label>:40:                                     ; preds = %31
  br label %41

; <label>:41:                                     ; preds = %40, %34
  %42 = phi i32 [ %39, %34 ], [ 0, %40 ]
  %43 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  %44 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %43, i32 0, i32 6
  store i32 %42, i32* %44, align 4
  %45 = load i32, i32* %5, align 4
  %46 = call i32* @__errno_location() #17
  store i32 %45, i32* %46, align 4
  ret void
}

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z19yy_switch_to_bufferP15yy_buffer_state(%struct.yy_buffer_state*) #6 {
  %2 = alloca %struct.yy_buffer_state*, align 8
  store %struct.yy_buffer_state* %0, %struct.yy_buffer_state** %2, align 8
  call void @_ZL21yyensure_buffer_stackv()
  %3 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %4 = icmp ne %struct.yy_buffer_state** %3, null
  br i1 %4, label %5, label %10

; <label>:5:                                      ; preds = %1
  %6 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %7 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %8 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, i64 %7
  %9 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %8, align 8
  br label %11

; <label>:10:                                     ; preds = %1
  br label %11

; <label>:11:                                     ; preds = %10, %5
  %12 = phi %struct.yy_buffer_state* [ %9, %5 ], [ null, %10 ]
  %13 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %14 = icmp eq %struct.yy_buffer_state* %12, %13
  br i1 %14, label %15, label %16

; <label>:15:                                     ; preds = %11
  br label %48

; <label>:16:                                     ; preds = %11
  %17 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %18 = icmp ne %struct.yy_buffer_state** %17, null
  br i1 %18, label %19, label %24

; <label>:19:                                     ; preds = %16
  %20 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %21 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %22 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %20, i64 %21
  %23 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %22, align 8
  br label %25

; <label>:24:                                     ; preds = %16
  br label %25

; <label>:25:                                     ; preds = %24, %19
  %26 = phi %struct.yy_buffer_state* [ %23, %19 ], [ null, %24 ]
  %27 = icmp ne %struct.yy_buffer_state* %26, null
  br i1 %27, label %28, label %43

; <label>:28:                                     ; preds = %25
  %29 = load i8, i8* @_ZL12yy_hold_char, align 1
  %30 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  store i8 %29, i8* %30, align 1
  %31 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %32 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %33 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %34 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %32, i64 %33
  %35 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %34, align 8
  %36 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %35, i32 0, i32 2
  store i8* %31, i8** %36, align 8
  %37 = load i32, i32* @_ZL10yy_n_chars, align 4
  %38 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %39 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %40 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %38, i64 %39
  %41 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %40, align 8
  %42 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %41, i32 0, i32 4
  store i32 %37, i32* %42, align 4
  br label %43

; <label>:43:                                     ; preds = %28, %25
  %44 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %45 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %46 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %47 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %45, i64 %46
  store %struct.yy_buffer_state* %44, %struct.yy_buffer_state** %47, align 8
  call void @_ZL20yy_load_buffer_statev()
  store i32 1, i32* @_ZL27yy_did_buffer_switch_on_eof, align 4
  br label %48

; <label>:48:                                     ; preds = %43, %15
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @_Z7yyallocm(i64) #4 {
  %2 = alloca i64, align 8
  store i64 %0, i64* %2, align 8
  %3 = load i64, i64* %2, align 8
  %4 = call noalias i8* @malloc(i64 %3) #3
  ret i8* %4
}

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z16yy_delete_bufferP15yy_buffer_state(%struct.yy_buffer_state*) #6 {
  %2 = alloca %struct.yy_buffer_state*, align 8
  store %struct.yy_buffer_state* %0, %struct.yy_buffer_state** %2, align 8
  %3 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %4 = icmp ne %struct.yy_buffer_state* %3, null
  br i1 %4, label %6, label %5

; <label>:5:                                      ; preds = %1
  br label %35

; <label>:6:                                      ; preds = %1
  %7 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %8 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %9 = icmp ne %struct.yy_buffer_state** %8, null
  br i1 %9, label %10, label %15

; <label>:10:                                     ; preds = %6
  %11 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %12 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %13 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %11, i64 %12
  %14 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %13, align 8
  br label %16

; <label>:15:                                     ; preds = %6
  br label %16

; <label>:16:                                     ; preds = %15, %10
  %17 = phi %struct.yy_buffer_state* [ %14, %10 ], [ null, %15 ]
  %18 = icmp eq %struct.yy_buffer_state* %7, %17
  br i1 %18, label %19, label %23

; <label>:19:                                     ; preds = %16
  %20 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %21 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %22 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %20, i64 %21
  store %struct.yy_buffer_state* null, %struct.yy_buffer_state** %22, align 8
  br label %23

; <label>:23:                                     ; preds = %19, %16
  %24 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %25 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %24, i32 0, i32 5
  %26 = load i32, i32* %25, align 8
  %27 = icmp ne i32 %26, 0
  br i1 %27, label %28, label %32

; <label>:28:                                     ; preds = %23
  %29 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %30 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %29, i32 0, i32 1
  %31 = load i8*, i8** %30, align 8
  call void @_Z6yyfreePv(i8* %31)
  br label %32

; <label>:32:                                     ; preds = %28, %23
  %33 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %34 = bitcast %struct.yy_buffer_state* %33 to i8*
  call void @_Z6yyfreePv(i8* %34)
  br label %35

; <label>:35:                                     ; preds = %32, %5
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z6yyfreePv(i8*) #4 {
  %2 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %3 = load i8*, i8** %2, align 8
  call void @free(i8* %3) #3
  ret void
}

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z15yy_flush_bufferP15yy_buffer_state(%struct.yy_buffer_state*) #6 {
  %2 = alloca %struct.yy_buffer_state*, align 8
  store %struct.yy_buffer_state* %0, %struct.yy_buffer_state** %2, align 8
  %3 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %4 = icmp ne %struct.yy_buffer_state* %3, null
  br i1 %4, label %6, label %5

; <label>:5:                                      ; preds = %1
  br label %40

; <label>:6:                                      ; preds = %1
  %7 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %8 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %7, i32 0, i32 4
  store i32 0, i32* %8, align 4
  %9 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %10 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %9, i32 0, i32 1
  %11 = load i8*, i8** %10, align 8
  %12 = getelementptr inbounds i8, i8* %11, i64 0
  store i8 0, i8* %12, align 1
  %13 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %14 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %13, i32 0, i32 1
  %15 = load i8*, i8** %14, align 8
  %16 = getelementptr inbounds i8, i8* %15, i64 1
  store i8 0, i8* %16, align 1
  %17 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %18 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %17, i32 0, i32 1
  %19 = load i8*, i8** %18, align 8
  %20 = getelementptr inbounds i8, i8* %19, i64 0
  %21 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %22 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %21, i32 0, i32 2
  store i8* %20, i8** %22, align 8
  %23 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %24 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %23, i32 0, i32 7
  store i32 1, i32* %24, align 8
  %25 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %26 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %25, i32 0, i32 11
  store i32 0, i32* %26, align 8
  %27 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %28 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %29 = icmp ne %struct.yy_buffer_state** %28, null
  br i1 %29, label %30, label %35

; <label>:30:                                     ; preds = %6
  %31 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %32 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %33 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %31, i64 %32
  %34 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %33, align 8
  br label %36

; <label>:35:                                     ; preds = %6
  br label %36

; <label>:36:                                     ; preds = %35, %30
  %37 = phi %struct.yy_buffer_state* [ %34, %30 ], [ null, %35 ]
  %38 = icmp eq %struct.yy_buffer_state* %27, %37
  br i1 %38, label %39, label %40

; <label>:39:                                     ; preds = %36
  call void @_ZL20yy_load_buffer_statev()
  br label %40

; <label>:40:                                     ; preds = %5, %39, %36
  ret void
}

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z19yypush_buffer_stateP15yy_buffer_state(%struct.yy_buffer_state*) #6 {
  %2 = alloca %struct.yy_buffer_state*, align 8
  store %struct.yy_buffer_state* %0, %struct.yy_buffer_state** %2, align 8
  %3 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %4 = icmp eq %struct.yy_buffer_state* %3, null
  br i1 %4, label %5, label %6

; <label>:5:                                      ; preds = %1
  br label %53

; <label>:6:                                      ; preds = %1
  call void @_ZL21yyensure_buffer_stackv()
  %7 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %8 = icmp ne %struct.yy_buffer_state** %7, null
  br i1 %8, label %9, label %14

; <label>:9:                                      ; preds = %6
  %10 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %11 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %12 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %10, i64 %11
  %13 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %12, align 8
  br label %15

; <label>:14:                                     ; preds = %6
  br label %15

; <label>:15:                                     ; preds = %14, %9
  %16 = phi %struct.yy_buffer_state* [ %13, %9 ], [ null, %14 ]
  %17 = icmp ne %struct.yy_buffer_state* %16, null
  br i1 %17, label %18, label %33

; <label>:18:                                     ; preds = %15
  %19 = load i8, i8* @_ZL12yy_hold_char, align 1
  %20 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  store i8 %19, i8* %20, align 1
  %21 = load i8*, i8** @_ZL10yy_c_buf_p, align 8
  %22 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %23 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %24 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %22, i64 %23
  %25 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %24, align 8
  %26 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %25, i32 0, i32 2
  store i8* %21, i8** %26, align 8
  %27 = load i32, i32* @_ZL10yy_n_chars, align 4
  %28 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %29 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %30 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %28, i64 %29
  %31 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %30, align 8
  %32 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %31, i32 0, i32 4
  store i32 %27, i32* %32, align 4
  br label %33

; <label>:33:                                     ; preds = %18, %15
  %34 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %35 = icmp ne %struct.yy_buffer_state** %34, null
  br i1 %35, label %36, label %41

; <label>:36:                                     ; preds = %33
  %37 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %38 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %39 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %37, i64 %38
  %40 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %39, align 8
  br label %42

; <label>:41:                                     ; preds = %33
  br label %42

; <label>:42:                                     ; preds = %41, %36
  %43 = phi %struct.yy_buffer_state* [ %40, %36 ], [ null, %41 ]
  %44 = icmp ne %struct.yy_buffer_state* %43, null
  br i1 %44, label %45, label %48

; <label>:45:                                     ; preds = %42
  %46 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %47 = add i64 %46, 1
  store i64 %47, i64* @_ZL19yy_buffer_stack_top, align 8
  br label %48

; <label>:48:                                     ; preds = %45, %42
  %49 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %2, align 8
  %50 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %51 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %52 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %50, i64 %51
  store %struct.yy_buffer_state* %49, %struct.yy_buffer_state** %52, align 8
  call void @_ZL20yy_load_buffer_statev()
  store i32 1, i32* @_ZL27yy_did_buffer_switch_on_eof, align 4
  br label %53

; <label>:53:                                     ; preds = %48, %5
  ret void
}

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z18yypop_buffer_statev() #6 {
  %1 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %2 = icmp ne %struct.yy_buffer_state** %1, null
  br i1 %2, label %3, label %8

; <label>:3:                                      ; preds = %0
  %4 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %5 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %6 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %4, i64 %5
  %7 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  br label %9

; <label>:8:                                      ; preds = %0
  br label %9

; <label>:9:                                      ; preds = %8, %3
  %10 = phi %struct.yy_buffer_state* [ %7, %3 ], [ null, %8 ]
  %11 = icmp ne %struct.yy_buffer_state* %10, null
  br i1 %11, label %13, label %12

; <label>:12:                                     ; preds = %9
  br label %45

; <label>:13:                                     ; preds = %9
  %14 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %15 = icmp ne %struct.yy_buffer_state** %14, null
  br i1 %15, label %16, label %21

; <label>:16:                                     ; preds = %13
  %17 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %18 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %19 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %17, i64 %18
  %20 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %19, align 8
  br label %22

; <label>:21:                                     ; preds = %13
  br label %22

; <label>:22:                                     ; preds = %21, %16
  %23 = phi %struct.yy_buffer_state* [ %20, %16 ], [ null, %21 ]
  call void @_Z16yy_delete_bufferP15yy_buffer_state(%struct.yy_buffer_state* %23)
  %24 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %25 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %26 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %24, i64 %25
  store %struct.yy_buffer_state* null, %struct.yy_buffer_state** %26, align 8
  %27 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %28 = icmp ugt i64 %27, 0
  br i1 %28, label %29, label %32

; <label>:29:                                     ; preds = %22
  %30 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %31 = add i64 %30, -1
  store i64 %31, i64* @_ZL19yy_buffer_stack_top, align 8
  br label %32

; <label>:32:                                     ; preds = %29, %22
  %33 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %34 = icmp ne %struct.yy_buffer_state** %33, null
  br i1 %34, label %35, label %40

; <label>:35:                                     ; preds = %32
  %36 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %37 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %38 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %36, i64 %37
  %39 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %38, align 8
  br label %41

; <label>:40:                                     ; preds = %32
  br label %41

; <label>:41:                                     ; preds = %40, %35
  %42 = phi %struct.yy_buffer_state* [ %39, %35 ], [ null, %40 ]
  %43 = icmp ne %struct.yy_buffer_state* %42, null
  br i1 %43, label %44, label %45

; <label>:44:                                     ; preds = %41
  call void @_ZL20yy_load_buffer_statev()
  store i32 1, i32* @_ZL27yy_did_buffer_switch_on_eof, align 4
  br label %45

; <label>:45:                                     ; preds = %12, %44, %41
  ret void
}

; Function Attrs: noinline optnone uwtable
define dso_local %struct.yy_buffer_state* @_Z14yy_scan_bufferPcm(i8*, i64) #6 {
  %3 = alloca %struct.yy_buffer_state*, align 8
  %4 = alloca i8*, align 8
  %5 = alloca i64, align 8
  %6 = alloca %struct.yy_buffer_state*, align 8
  store i8* %0, i8** %4, align 8
  store i64 %1, i64* %5, align 8
  %7 = load i64, i64* %5, align 8
  %8 = icmp ult i64 %7, 2
  br i1 %8, label %25, label %9

; <label>:9:                                      ; preds = %2
  %10 = load i8*, i8** %4, align 8
  %11 = load i64, i64* %5, align 8
  %12 = sub i64 %11, 2
  %13 = getelementptr inbounds i8, i8* %10, i64 %12
  %14 = load i8, i8* %13, align 1
  %15 = sext i8 %14 to i32
  %16 = icmp ne i32 %15, 0
  br i1 %16, label %25, label %17

; <label>:17:                                     ; preds = %9
  %18 = load i8*, i8** %4, align 8
  %19 = load i64, i64* %5, align 8
  %20 = sub i64 %19, 1
  %21 = getelementptr inbounds i8, i8* %18, i64 %20
  %22 = load i8, i8* %21, align 1
  %23 = sext i8 %22 to i32
  %24 = icmp ne i32 %23, 0
  br i1 %24, label %25, label %26

; <label>:25:                                     ; preds = %17, %9, %2
  store %struct.yy_buffer_state* null, %struct.yy_buffer_state** %3, align 8
  br label %62

; <label>:26:                                     ; preds = %17
  %27 = call i8* @_Z7yyallocm(i64 64)
  %28 = bitcast i8* %27 to %struct.yy_buffer_state*
  store %struct.yy_buffer_state* %28, %struct.yy_buffer_state** %6, align 8
  %29 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %30 = icmp ne %struct.yy_buffer_state* %29, null
  br i1 %30, label %32, label %31

; <label>:31:                                     ; preds = %26
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([42 x i8], [42 x i8]* @.str.22, i32 0, i32 0)) #16
  unreachable

; <label>:32:                                     ; preds = %26
  %33 = load i64, i64* %5, align 8
  %34 = sub i64 %33, 2
  %35 = trunc i64 %34 to i32
  %36 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %37 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %36, i32 0, i32 3
  store i32 %35, i32* %37, align 8
  %38 = load i8*, i8** %4, align 8
  %39 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %40 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %39, i32 0, i32 1
  store i8* %38, i8** %40, align 8
  %41 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %42 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %41, i32 0, i32 2
  store i8* %38, i8** %42, align 8
  %43 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %44 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %43, i32 0, i32 5
  store i32 0, i32* %44, align 8
  %45 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %46 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %45, i32 0, i32 0
  store %struct._IO_FILE* null, %struct._IO_FILE** %46, align 8
  %47 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %48 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %47, i32 0, i32 3
  %49 = load i32, i32* %48, align 8
  %50 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %51 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %50, i32 0, i32 4
  store i32 %49, i32* %51, align 4
  %52 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %53 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %52, i32 0, i32 6
  store i32 0, i32* %53, align 4
  %54 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %55 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %54, i32 0, i32 7
  store i32 1, i32* %55, align 8
  %56 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %57 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %56, i32 0, i32 10
  store i32 0, i32* %57, align 4
  %58 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  %59 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %58, i32 0, i32 11
  store i32 0, i32* %59, align 8
  %60 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  call void @_Z19yy_switch_to_bufferP15yy_buffer_state(%struct.yy_buffer_state* %60)
  %61 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %6, align 8
  store %struct.yy_buffer_state* %61, %struct.yy_buffer_state** %3, align 8
  br label %62

; <label>:62:                                     ; preds = %32, %25
  %63 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %3, align 8
  ret %struct.yy_buffer_state* %63
}

; Function Attrs: noinline optnone uwtable
define dso_local %struct.yy_buffer_state* @_Z14yy_scan_stringPKc(i8*) #6 {
  %2 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %3 = load i8*, i8** %2, align 8
  %4 = load i8*, i8** %2, align 8
  %5 = call i64 @strlen(i8* %4) #18
  %6 = trunc i64 %5 to i32
  %7 = call %struct.yy_buffer_state* @_Z13yy_scan_bytesPKci(i8* %3, i32 %6)
  ret %struct.yy_buffer_state* %7
}

; Function Attrs: noinline optnone uwtable
define dso_local %struct.yy_buffer_state* @_Z13yy_scan_bytesPKci(i8*, i32) #6 {
  %3 = alloca i8*, align 8
  %4 = alloca i32, align 4
  %5 = alloca %struct.yy_buffer_state*, align 8
  %6 = alloca i8*, align 8
  %7 = alloca i64, align 8
  %8 = alloca i32, align 4
  store i8* %0, i8** %3, align 8
  store i32 %1, i32* %4, align 4
  %9 = load i32, i32* %4, align 4
  %10 = add nsw i32 %9, 2
  %11 = sext i32 %10 to i64
  store i64 %11, i64* %7, align 8
  %12 = load i64, i64* %7, align 8
  %13 = call i8* @_Z7yyallocm(i64 %12)
  store i8* %13, i8** %6, align 8
  %14 = load i8*, i8** %6, align 8
  %15 = icmp ne i8* %14, null
  br i1 %15, label %17, label %16

; <label>:16:                                     ; preds = %2
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([41 x i8], [41 x i8]* @.str.23, i32 0, i32 0)) #16
  unreachable

; <label>:17:                                     ; preds = %2
  store i32 0, i32* %8, align 4
  br label %18

; <label>:18:                                     ; preds = %32, %17
  %19 = load i32, i32* %8, align 4
  %20 = load i32, i32* %4, align 4
  %21 = icmp slt i32 %19, %20
  br i1 %21, label %22, label %35

; <label>:22:                                     ; preds = %18
  %23 = load i8*, i8** %3, align 8
  %24 = load i32, i32* %8, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds i8, i8* %23, i64 %25
  %27 = load i8, i8* %26, align 1
  %28 = load i8*, i8** %6, align 8
  %29 = load i32, i32* %8, align 4
  %30 = sext i32 %29 to i64
  %31 = getelementptr inbounds i8, i8* %28, i64 %30
  store i8 %27, i8* %31, align 1
  br label %32

; <label>:32:                                     ; preds = %22
  %33 = load i32, i32* %8, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %8, align 4
  br label %18

; <label>:35:                                     ; preds = %18
  %36 = load i8*, i8** %6, align 8
  %37 = load i32, i32* %4, align 4
  %38 = add nsw i32 %37, 1
  %39 = sext i32 %38 to i64
  %40 = getelementptr inbounds i8, i8* %36, i64 %39
  store i8 0, i8* %40, align 1
  %41 = load i8*, i8** %6, align 8
  %42 = load i32, i32* %4, align 4
  %43 = sext i32 %42 to i64
  %44 = getelementptr inbounds i8, i8* %41, i64 %43
  store i8 0, i8* %44, align 1
  %45 = load i8*, i8** %6, align 8
  %46 = load i64, i64* %7, align 8
  %47 = call %struct.yy_buffer_state* @_Z14yy_scan_bufferPcm(i8* %45, i64 %46)
  store %struct.yy_buffer_state* %47, %struct.yy_buffer_state** %5, align 8
  %48 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %49 = icmp ne %struct.yy_buffer_state* %48, null
  br i1 %49, label %51, label %50

; <label>:50:                                     ; preds = %35
  call void @_ZL14yy_fatal_errorPKc(i8* getelementptr inbounds ([30 x i8], [30 x i8]* @.str.24, i32 0, i32 0)) #16
  unreachable

; <label>:51:                                     ; preds = %35
  %52 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  %53 = getelementptr inbounds %struct.yy_buffer_state, %struct.yy_buffer_state* %52, i32 0, i32 5
  store i32 1, i32* %53, align 8
  %54 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, align 8
  ret %struct.yy_buffer_state* %54
}

; Function Attrs: nounwind readonly
declare dso_local i64 @strlen(i8*) #10

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z12yyget_linenov() #4 {
  %1 = load i32, i32* @yylineno, align 4
  ret i32 %1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local %struct._IO_FILE* @_Z8yyget_inv() #4 {
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @yyin, align 8
  ret %struct._IO_FILE* %1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local %struct._IO_FILE* @_Z9yyget_outv() #4 {
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @yyout, align 8
  ret %struct._IO_FILE* %1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z10yyget_lengv() #4 {
  %1 = load i32, i32* @yyleng, align 4
  ret i32 %1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @_Z10yyget_textv() #4 {
  %1 = load i8*, i8** @yytext, align 8
  ret i8* %1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z12yyset_linenoi(i32) #4 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  store i32 %3, i32* @yylineno, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z8yyset_inP8_IO_FILE(%struct._IO_FILE*) #4 {
  %2 = alloca %struct._IO_FILE*, align 8
  store %struct._IO_FILE* %0, %struct._IO_FILE** %2, align 8
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** %2, align 8
  store %struct._IO_FILE* %3, %struct._IO_FILE** @yyin, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z9yyset_outP8_IO_FILE(%struct._IO_FILE*) #4 {
  %2 = alloca %struct._IO_FILE*, align 8
  store %struct._IO_FILE* %0, %struct._IO_FILE** %2, align 8
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** %2, align 8
  store %struct._IO_FILE* %3, %struct._IO_FILE** @yyout, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z11yyget_debugv() #4 {
  %1 = load i32, i32* @yy_flex_debug, align 4
  ret i32 %1
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_Z11yyset_debugi(i32) #4 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  store i32 %3, i32* @yy_flex_debug, align 4
  ret void
}

; Function Attrs: noinline optnone uwtable
define dso_local i32 @_Z13yylex_destroyv() #6 {
  br label %1

; <label>:1:                                      ; preds = %22, %0
  %2 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %3 = icmp ne %struct.yy_buffer_state** %2, null
  br i1 %3, label %4, label %9

; <label>:4:                                      ; preds = %1
  %5 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %6 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %7 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %5, i64 %6
  %8 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %7, align 8
  br label %10

; <label>:9:                                      ; preds = %1
  br label %10

; <label>:10:                                     ; preds = %9, %4
  %11 = phi %struct.yy_buffer_state* [ %8, %4 ], [ null, %9 ]
  %12 = icmp ne %struct.yy_buffer_state* %11, null
  br i1 %12, label %13, label %27

; <label>:13:                                     ; preds = %10
  %14 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %15 = icmp ne %struct.yy_buffer_state** %14, null
  br i1 %15, label %16, label %21

; <label>:16:                                     ; preds = %13
  %17 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %18 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %19 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %17, i64 %18
  %20 = load %struct.yy_buffer_state*, %struct.yy_buffer_state** %19, align 8
  br label %22

; <label>:21:                                     ; preds = %13
  br label %22

; <label>:22:                                     ; preds = %21, %16
  %23 = phi %struct.yy_buffer_state* [ %20, %16 ], [ null, %21 ]
  call void @_Z16yy_delete_bufferP15yy_buffer_state(%struct.yy_buffer_state* %23)
  %24 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %25 = load i64, i64* @_ZL19yy_buffer_stack_top, align 8
  %26 = getelementptr inbounds %struct.yy_buffer_state*, %struct.yy_buffer_state** %24, i64 %25
  store %struct.yy_buffer_state* null, %struct.yy_buffer_state** %26, align 8
  call void @_Z18yypop_buffer_statev()
  br label %1

; <label>:27:                                     ; preds = %10
  %28 = load %struct.yy_buffer_state**, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %29 = bitcast %struct.yy_buffer_state** %28 to i8*
  call void @_Z6yyfreePv(i8* %29)
  store %struct.yy_buffer_state** null, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  %30 = call i32 @_ZL15yy_init_globalsv()
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @_ZL15yy_init_globalsv() #4 {
  store %struct.yy_buffer_state** null, %struct.yy_buffer_state*** @_ZL15yy_buffer_stack, align 8
  store i64 0, i64* @_ZL19yy_buffer_stack_top, align 8
  store i64 0, i64* @_ZL19yy_buffer_stack_max, align 8
  store i8* null, i8** @_ZL10yy_c_buf_p, align 8
  store i32 0, i32* @_ZL7yy_init, align 4
  store i32 0, i32* @_ZL8yy_start, align 4
  store %struct._IO_FILE* null, %struct._IO_FILE** @yyin, align 8
  store %struct._IO_FILE* null, %struct._IO_FILE** @yyout, align 8
  ret i32 0
}

; Function Attrs: nounwind
declare dso_local noalias i8* @malloc(i64) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @_Z9yyreallocPvm(i8*, i64) #4 {
  %3 = alloca i8*, align 8
  %4 = alloca i64, align 8
  store i8* %0, i8** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load i8*, i8** %3, align 8
  %6 = load i64, i64* %4, align 8
  %7 = call i8* @realloc(i8* %5, i64 %6) #3
  ret i8* %7
}

; Function Attrs: nounwind
declare dso_local i8* @realloc(i8*, i64) #2

; Function Attrs: nounwind
declare dso_local void @free(i8*) #2

declare dso_local i32 @getc(%struct._IO_FILE*) #1

; Function Attrs: nounwind
declare dso_local i32 @ferror(%struct._IO_FILE*) #2

; Function Attrs: nounwind readnone
declare dso_local i32* @__errno_location() #11

declare dso_local i64 @fread(i8*, i64, i64, %struct._IO_FILE*) #1

; Function Attrs: nounwind
declare dso_local void @clearerr(%struct._IO_FILE*) #2

; Function Attrs: nounwind
declare dso_local i32 @isatty(i32) #2

; Function Attrs: nounwind
declare dso_local i32 @fileno(%struct._IO_FILE*) #2

; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1) #12

declare dso_local i32 @fprintf(%struct._IO_FILE*, i8*, ...) #1

; Function Attrs: noreturn nounwind
declare dso_local void @exit(i32) #13

; Function Attrs: noinline uwtable
define internal void @_GLOBAL__sub_I_tokens.cpp() #0 section ".text.startup" {
  call void @__cxx_global_var_init()
  ret void
}

attributes #0 = { noinline uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
attributes #4 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { noreturn nounwind }
attributes #6 = { noinline optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { nobuiltin "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { nobuiltin nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #9 = { noinline noreturn optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #10 = { nounwind readonly "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #11 = { nounwind readnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #12 = { argmemonly nounwind }
attributes #13 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #14 = { builtin }
attributes #15 = { builtin nounwind }
attributes #16 = { noreturn }
attributes #17 = { nounwind readnone }
attributes #18 = { nounwind readonly }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 7.0.1-8 (tags/RELEASE_701/final)"}
