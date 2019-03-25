; ModuleID = 'parser.cpp'
source_filename = "parser.cpp"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%class.NBlock = type { %class.NExpression, %"class.std::vector" }
%class.NExpression = type { %class.Node }
%class.Node = type { i32 (...)** }
%"class.std::vector" = type { %"struct.std::_Vector_base" }
%"struct.std::_Vector_base" = type { %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl" }
%"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl" = type { %class.NStatement**, %class.NStatement**, %class.NStatement** }
%class.NStatement = type { %class.Node }
%union.YYSTYPE = type { %class.Node* }
%union.yyalloc = type { %union.YYSTYPE }
%"class.std::__cxx11::basic_string" = type { %"struct.std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider", i64, %union.anon }
%"struct.std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" = type { i8* }
%union.anon = type { i64, [8 x i8] }
%"class.std::allocator.0" = type { i8 }
%class.NExpressionStatement = type { %class.NStatement, %class.NExpression* }
%class.NVariableDeclaration = type { %class.NStatement, %class.NIdentifier*, %class.NIdentifier*, %class.NExpression* }
%class.NIdentifier = type { %class.NExpression, %"class.std::__cxx11::basic_string" }
%class.NFunctionDeclaration = type { %class.NStatement, %class.NIdentifier*, %class.NIdentifier*, %"class.std::vector.3", %class.NBlock* }
%"class.std::vector.3" = type { %"struct.std::_Vector_base.4" }
%"struct.std::_Vector_base.4" = type { %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl" }
%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl" = type { %class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration** }
%class.NDouble = type { %class.NExpression, double }
%class.NAssignment = type { %class.NExpression, %class.NIdentifier*, %class.NExpression* }
%class.NMethodCall = type { %class.NExpression, %class.NIdentifier*, %"class.std::vector.8" }
%"class.std::vector.8" = type { %"struct.std::_Vector_base.9" }
%"struct.std::_Vector_base.9" = type { %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl" }
%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl" = type { %class.NExpression**, %class.NExpression**, %class.NExpression** }
%class.NBinaryOperator = type { %class.NExpression, i32, %class.NExpression*, %class.NExpression* }
%"class.__gnu_cxx::__normal_iterator.14" = type { %class.NStatement** }
%"class.std::allocator" = type { i8 }
%"class.std::allocator.5" = type { i8 }
%"class.__gnu_cxx::__normal_iterator.15" = type { %class.NVariableDeclaration** }
%"class.std::allocator.10" = type { i8 }
%"class.__gnu_cxx::__normal_iterator.17" = type { %class.NExpression** }
%"class.llvm::Value" = type { %"class.llvm::Type"*, %"class.llvm::Use"*, i8, i8, i16, i32 }
%"class.llvm::Type" = type opaque
%"class.llvm::Use" = type { %"class.llvm::Value"*, %"class.llvm::Use"*, %"class.llvm::PointerIntPair" }
%"class.llvm::PointerIntPair" = type { i64 }
%class.CodeGenContext = type opaque
%"class.__gnu_cxx::new_allocator" = type { i8 }
%"class.__gnu_cxx::__normal_iterator" = type { %class.NVariableDeclaration** }
%"class.__gnu_cxx::new_allocator.6" = type { i8 }
%"class.__gnu_cxx::__normal_iterator.13" = type { %class.NExpression** }
%"class.__gnu_cxx::new_allocator.11" = type { i8 }
%"class.std::move_iterator" = type { %class.NStatement** }
%"class.std::move_iterator.16" = type { %class.NVariableDeclaration** }
%"class.std::move_iterator.18" = type { %class.NExpression** }

$_ZN6NBlockC2Ev = comdat any

$_ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_ = comdat any

$_ZN20NExpressionStatementC2ER11NExpression = comdat any

$_ZN20NVariableDeclarationC2ERK11NIdentifierRS0_ = comdat any

$_ZN20NVariableDeclarationC2ERK11NIdentifierRS0_P11NExpression = comdat any

$_ZN20NFunctionDeclarationC2ERK11NIdentifierS2_RKSt6vectorIP20NVariableDeclarationSaIS5_EER6NBlock = comdat any

$_ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev = comdat any

$_ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev = comdat any

$_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_ = comdat any

$_ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE = comdat any

$_ZN7NDoubleC2Ed = comdat any

$_ZN11NAssignmentC2ER11NIdentifierR11NExpression = comdat any

$_ZN11NMethodCallC2ERK11NIdentifierRSt6vectorIP11NExpressionSaIS5_EE = comdat any

$_ZNSt6vectorIP11NExpressionSaIS1_EED2Ev = comdat any

$_ZN15NBinaryOperatorC2ER11NExpressioniS1_ = comdat any

$_ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev = comdat any

$_ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_ = comdat any

$_ZN11NExpressionC2Ev = comdat any

$_ZNSt6vectorIP10NStatementSaIS1_EEC2Ev = comdat any

$_ZN6NBlockD2Ev = comdat any

$_ZN6NBlockD0Ev = comdat any

$_ZN6NBlock7codeGenER14CodeGenContext = comdat any

$_ZN4NodeC2Ev = comdat any

$_ZN11NExpressionD2Ev = comdat any

$_ZN11NExpressionD0Ev = comdat any

$_ZN4Node7codeGenER14CodeGenContext = comdat any

$_ZN4NodeD2Ev = comdat any

$_ZN4NodeD0Ev = comdat any

$_ZNSt12_Vector_baseIP10NStatementSaIS1_EEC2Ev = comdat any

$__clang_call_terminate = comdat any

$_ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implC2Ev = comdat any

$_ZNSaIP10NStatementEC2Ev = comdat any

$_ZN9__gnu_cxx13new_allocatorIP10NStatementEC2Ev = comdat any

$_ZNSt6vectorIP10NStatementSaIS1_EED2Ev = comdat any

$_ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E = comdat any

$_ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv = comdat any

$_ZNSt12_Vector_baseIP10NStatementSaIS1_EED2Ev = comdat any

$_ZSt8_DestroyIPP10NStatementEvT_S3_ = comdat any

$_ZNSt12_Destroy_auxILb1EE9__destroyIPP10NStatementEEvT_S5_ = comdat any

$_ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m = comdat any

$_ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implD2Ev = comdat any

$_ZNSt16allocator_traitsISaIP10NStatementEE10deallocateERS2_PS1_m = comdat any

$_ZN9__gnu_cxx13new_allocatorIP10NStatementE10deallocateEPS2_m = comdat any

$_ZNSaIP10NStatementED2Ev = comdat any

$_ZN9__gnu_cxx13new_allocatorIP10NStatementED2Ev = comdat any

$_ZN10NStatementC2Ev = comdat any

$_ZN20NExpressionStatementD2Ev = comdat any

$_ZN20NExpressionStatementD0Ev = comdat any

$_ZN20NExpressionStatement7codeGenER14CodeGenContext = comdat any

$_ZN10NStatementD2Ev = comdat any

$_ZN10NStatementD0Ev = comdat any

$_ZN20NVariableDeclarationD2Ev = comdat any

$_ZN20NVariableDeclarationD0Ev = comdat any

$_ZN20NVariableDeclaration7codeGenER14CodeGenContext = comdat any

$_ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2ERKS3_ = comdat any

$_ZN20NFunctionDeclarationD2Ev = comdat any

$_ZN20NFunctionDeclarationD0Ev = comdat any

$_ZN20NFunctionDeclaration7codeGenER14CodeGenContext = comdat any

$_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv = comdat any

$_ZN9__gnu_cxx14__alloc_traitsISaIP20NVariableDeclarationES2_E17_S_select_on_copyERKS3_ = comdat any

$_ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2EmRKS2_ = comdat any

$_ZNSaIP20NVariableDeclarationED2Ev = comdat any

$_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E = comdat any

$_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv = comdat any

$_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev = comdat any

$_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE37select_on_container_copy_constructionERKS2_ = comdat any

$_ZNSaIP20NVariableDeclarationEC2ERKS1_ = comdat any

$_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2ERKS3_ = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2ERKS2_ = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE17_M_create_storageEm = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm = comdat any

$_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8allocateERS2_m = comdat any

$_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8allocateEmPKv = comdat any

$_ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv = comdat any

$_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationED2Ev = comdat any

$_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_ = comdat any

$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_ = comdat any

$_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_ = comdat any

$_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_ = comdat any

$_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_ = comdat any

$_ZSt13__copy_move_aILb0EPKP20NVariableDeclarationPS1_ET1_T0_S6_S5_ = comdat any

$_ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE = comdat any

$_ZSt12__niter_baseIPP20NVariableDeclarationET_S3_ = comdat any

$_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_ = comdat any

$_ZNK9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv = comdat any

$_ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_ = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m = comdat any

$_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE10deallocateERS2_PS1_m = comdat any

$_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE10deallocateEPS2_m = comdat any

$_ZN11NIdentifierD2Ev = comdat any

$_ZN11NIdentifierD0Ev = comdat any

$_ZN11NIdentifier7codeGenER14CodeGenContext = comdat any

$_ZN7NDoubleD2Ev = comdat any

$_ZN7NDoubleD0Ev = comdat any

$_ZN7NDouble7codeGenER14CodeGenContext = comdat any

$_ZN11NAssignmentD2Ev = comdat any

$_ZN11NAssignmentD0Ev = comdat any

$_ZN11NAssignment7codeGenER14CodeGenContext = comdat any

$_ZNSt6vectorIP11NExpressionSaIS1_EEC2ERKS3_ = comdat any

$_ZN11NMethodCallD2Ev = comdat any

$_ZN11NMethodCallD0Ev = comdat any

$_ZN11NMethodCall7codeGenER14CodeGenContext = comdat any

$_ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv = comdat any

$_ZN9__gnu_cxx14__alloc_traitsISaIP11NExpressionES2_E17_S_select_on_copyERKS3_ = comdat any

$_ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2EmRKS2_ = comdat any

$_ZNSaIP11NExpressionED2Ev = comdat any

$_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E = comdat any

$_ZNKSt6vectorIP11NExpressionSaIS1_EE5beginEv = comdat any

$_ZNKSt6vectorIP11NExpressionSaIS1_EE3endEv = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev = comdat any

$_ZNSt16allocator_traitsISaIP11NExpressionEE37select_on_container_copy_constructionERKS2_ = comdat any

$_ZNSaIP11NExpressionEC2ERKS1_ = comdat any

$_ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2ERKS3_ = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2ERKS2_ = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE17_M_create_storageEm = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm = comdat any

$_ZNSt16allocator_traitsISaIP11NExpressionEE8allocateERS2_m = comdat any

$_ZN9__gnu_cxx13new_allocatorIP11NExpressionE8allocateEmPKv = comdat any

$_ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv = comdat any

$_ZN9__gnu_cxx13new_allocatorIP11NExpressionED2Ev = comdat any

$_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_ = comdat any

$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_ = comdat any

$_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_ = comdat any

$_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_ = comdat any

$_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_ = comdat any

$_ZSt13__copy_move_aILb0EPKP11NExpressionPS1_ET1_T0_S6_S5_ = comdat any

$_ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE = comdat any

$_ZSt12__niter_baseIPP11NExpressionET_S3_ = comdat any

$_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_ = comdat any

$_ZNK9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv = comdat any

$_ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_ = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m = comdat any

$_ZNSt16allocator_traitsISaIP11NExpressionEE10deallocateERS2_PS1_m = comdat any

$_ZN9__gnu_cxx13new_allocatorIP11NExpressionE10deallocateEPS2_m = comdat any

$_ZN15NBinaryOperatorD2Ev = comdat any

$_ZN15NBinaryOperatorD0Ev = comdat any

$_ZN15NBinaryOperator7codeGenER14CodeGenContext = comdat any

$_ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E = comdat any

$_ZSt8_DestroyIPP11NExpressionEvT_S3_ = comdat any

$_ZNSt12_Destroy_auxILb1EE9__destroyIPP11NExpressionEEvT_S5_ = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2Ev = comdat any

$_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2Ev = comdat any

$_ZNSaIP11NExpressionEC2Ev = comdat any

$_ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2Ev = comdat any

$_ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E = comdat any

$_ZSt8_DestroyIPP20NVariableDeclarationEvT_S3_ = comdat any

$_ZNSt12_Destroy_auxILb1EE9__destroyIPP20NVariableDeclarationEEvT_S5_ = comdat any

$_ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_ = comdat any

$_ZNSt6vectorIP10NStatementSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_ = comdat any

$_ZNSt6vectorIP10NStatementSaIS1_EE3endEv = comdat any

$_ZN9__gnu_cxx13new_allocatorIP10NStatementE9constructIS2_JRKS2_EEEvPT_DpOT0_ = comdat any

$_ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE = comdat any

$_ZNKSt6vectorIP10NStatementSaIS1_EE12_M_check_lenEmPKc = comdat any

$_ZN9__gnu_cxxmiIPP10NStatementSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_ = comdat any

$_ZNSt6vectorIP10NStatementSaIS1_EE5beginEv = comdat any

$_ZNSt12_Vector_baseIP10NStatementSaIS1_EE11_M_allocateEm = comdat any

$_ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_ = comdat any

$_ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv = comdat any

$_ZNSt16allocator_traitsISaIP10NStatementEE7destroyIS1_EEvRS2_PT_ = comdat any

$_ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv = comdat any

$_ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv = comdat any

$_ZSt3maxImERKT_S2_S2_ = comdat any

$_ZNSt16allocator_traitsISaIP10NStatementEE8max_sizeERKS2_ = comdat any

$_ZNKSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv = comdat any

$_ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv = comdat any

$_ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_ = comdat any

$_ZNSt16allocator_traitsISaIP10NStatementEE8allocateERS2_m = comdat any

$_ZN9__gnu_cxx13new_allocatorIP10NStatementE8allocateEmPKv = comdat any

$_ZSt22__uninitialized_copy_aISt13move_iteratorIPP10NStatementES3_S2_ET0_T_S6_S5_RSaIT1_E = comdat any

$_ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_ = comdat any

$_ZSt18uninitialized_copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_ = comdat any

$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP10NStatementES5_EET0_T_S8_S7_ = comdat any

$_ZSt4copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_ = comdat any

$_ZSt14__copy_move_a2ILb1EPP10NStatementS2_ET1_T0_S4_S3_ = comdat any

$_ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E = comdat any

$_ZSt13__copy_move_aILb1EPP10NStatementS2_ET1_T0_S4_S3_ = comdat any

$_ZSt12__niter_baseIPP10NStatementET_S3_ = comdat any

$_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP10NStatementEEPT_PKS5_S8_S6_ = comdat any

$_ZSt12__miter_baseIPP10NStatementET_S3_ = comdat any

$_ZNKSt13move_iteratorIPP10NStatementE4baseEv = comdat any

$_ZNSt13move_iteratorIPP10NStatementEC2ES2_ = comdat any

$_ZN9__gnu_cxx13new_allocatorIP10NStatementE7destroyIS2_EEvPT_ = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2Ev = comdat any

$_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2Ev = comdat any

$_ZNSaIP20NVariableDeclarationEC2Ev = comdat any

$_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2Ev = comdat any

$_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_ = comdat any

$_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_ = comdat any

$_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv = comdat any

$_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE9constructIS2_JRKS2_EEEvPT_DpOT0_ = comdat any

$_ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE = comdat any

$_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE12_M_check_lenEmPKc = comdat any

$_ZN9__gnu_cxxmiIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_ = comdat any

$_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv = comdat any

$_ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_ = comdat any

$_ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv = comdat any

$_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE7destroyIS1_EEvRS2_PT_ = comdat any

$_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv = comdat any

$_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8max_sizeERKS2_ = comdat any

$_ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_ = comdat any

$_ZSt22__uninitialized_copy_aISt13move_iteratorIPP20NVariableDeclarationES3_S2_ET0_T_S6_S5_RSaIT1_E = comdat any

$_ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_ = comdat any

$_ZSt18uninitialized_copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_ = comdat any

$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP20NVariableDeclarationES5_EET0_T_S8_S7_ = comdat any

$_ZSt4copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_ = comdat any

$_ZSt14__copy_move_a2ILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_ = comdat any

$_ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E = comdat any

$_ZSt13__copy_move_aILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_ = comdat any

$_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_ = comdat any

$_ZSt12__miter_baseIPP20NVariableDeclarationET_S3_ = comdat any

$_ZNKSt13move_iteratorIPP20NVariableDeclarationE4baseEv = comdat any

$_ZNSt13move_iteratorIPP20NVariableDeclarationEC2ES2_ = comdat any

$_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE7destroyIS2_EEvPT_ = comdat any

$_ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_ = comdat any

$_ZNSt6vectorIP11NExpressionSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_ = comdat any

$_ZNSt6vectorIP11NExpressionSaIS1_EE3endEv = comdat any

$_ZN9__gnu_cxx13new_allocatorIP11NExpressionE9constructIS2_JRKS2_EEEvPT_DpOT0_ = comdat any

$_ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE = comdat any

$_ZNKSt6vectorIP11NExpressionSaIS1_EE12_M_check_lenEmPKc = comdat any

$_ZN9__gnu_cxxmiIPP11NExpressionSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_ = comdat any

$_ZNSt6vectorIP11NExpressionSaIS1_EE5beginEv = comdat any

$_ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_ = comdat any

$_ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv = comdat any

$_ZNSt16allocator_traitsISaIP11NExpressionEE7destroyIS1_EEvRS2_PT_ = comdat any

$_ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv = comdat any

$_ZNSt16allocator_traitsISaIP11NExpressionEE8max_sizeERKS2_ = comdat any

$_ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_ = comdat any

$_ZSt22__uninitialized_copy_aISt13move_iteratorIPP11NExpressionES3_S2_ET0_T_S6_S5_RSaIT1_E = comdat any

$_ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_ = comdat any

$_ZSt18uninitialized_copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_ = comdat any

$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP11NExpressionES5_EET0_T_S8_S7_ = comdat any

$_ZSt4copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_ = comdat any

$_ZSt14__copy_move_a2ILb1EPP11NExpressionS2_ET1_T0_S4_S3_ = comdat any

$_ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E = comdat any

$_ZSt13__copy_move_aILb1EPP11NExpressionS2_ET1_T0_S4_S3_ = comdat any

$_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_ = comdat any

$_ZSt12__miter_baseIPP11NExpressionET_S3_ = comdat any

$_ZNKSt13move_iteratorIPP11NExpressionE4baseEv = comdat any

$_ZNSt13move_iteratorIPP11NExpressionEC2ES2_ = comdat any

$_ZN9__gnu_cxx13new_allocatorIP11NExpressionE7destroyIS2_EEvPT_ = comdat any

$_ZTV6NBlock = comdat any

$_ZTS6NBlock = comdat any

$_ZTS11NExpression = comdat any

$_ZTS4Node = comdat any

$_ZTI4Node = comdat any

$_ZTI11NExpression = comdat any

$_ZTI6NBlock = comdat any

$_ZTV11NExpression = comdat any

$_ZTV4Node = comdat any

$_ZTV20NExpressionStatement = comdat any

$_ZTS20NExpressionStatement = comdat any

$_ZTS10NStatement = comdat any

$_ZTI10NStatement = comdat any

$_ZTI20NExpressionStatement = comdat any

$_ZTV10NStatement = comdat any

$_ZTV20NVariableDeclaration = comdat any

$_ZTS20NVariableDeclaration = comdat any

$_ZTI20NVariableDeclaration = comdat any

$_ZTV20NFunctionDeclaration = comdat any

$_ZTS20NFunctionDeclaration = comdat any

$_ZTI20NFunctionDeclaration = comdat any

$_ZTV11NIdentifier = comdat any

$_ZTS11NIdentifier = comdat any

$_ZTI11NIdentifier = comdat any

$_ZTV7NDouble = comdat any

$_ZTS7NDouble = comdat any

$_ZTI7NDouble = comdat any

$_ZTV11NAssignment = comdat any

$_ZTS11NAssignment = comdat any

$_ZTI11NAssignment = comdat any

$_ZTV11NMethodCall = comdat any

$_ZTS11NMethodCall = comdat any

$_ZTI11NMethodCall = comdat any

$_ZTV15NBinaryOperator = comdat any

$_ZTS15NBinaryOperator = comdat any

$_ZTI15NBinaryOperator = comdat any

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external hidden global i8
@programBlock = dso_local global %class.NBlock* null, align 8
@.str = private unnamed_addr constant [11 x i8] c"ERROR: %sn\00", align 1
@yychar = dso_local global i32 0, align 4
@yylval = dso_local global %union.YYSTYPE zeroinitializer, align 8
@yynerrs = dso_local global i32 0, align 4
@_ZL6yypact = internal constant [54 x i8] c"\16\DF\DF\DF\16\03\16\DF\DF\DF\13\DF@\06/\DF\DF\16\16\11\DF\DF\DF\DF\DF\DF\DF\DF\DF\DF\16\DF@@\18\16\02@\DF\16@\DF\19\02@\1D\02\0B\04\DF\DF\DF\08\DF", align 16
@_ZL11yytranslate = internal constant [278 x i8] c"\00\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\02\01\02\03\04\05\06\07\08\09\0A\0B\0C\0D\0E\0F\10\11\12\13\14\15\16", align 16
@_ZL7yycheck = internal constant [87 x i8] c"\00\06\04\00$\03\06\03\04\05\0A\03\04\05.\11\12\0D\0C\0D\10\0D\03\0C\10\03\04\05\1E\0C\0D\0C\0D#0\0D$'\0E\0E\FF\11\11+\0F\FF.40\FF\FF\FF4\06\07\08\09\0A\0B\FF\FF\0E\FF\FF\FF\FF\13\14\15\16\06\07\08\09\0A\0B\FF\FF\FF\FF\FF\FF\FF\13\14\15\16", align 16
@_ZL7yytable = internal constant [87 x i8] c"\0A\10\0E\0F)\01\0A\01\02\03\13\01\02\032 !\04\11\123\04\01#5\01\02\03%#$\11\12(4\04+,&-\00'./0\00+\10\0A\00\00\00\0A\14\15\16\17\18\19\00\00\1F\00\00\00\00\1A\1B\1C\1D\14\15\16\17\18\19\00\00\00\00\00\00\00\1A\1B\1C\1D", align 16
@_ZL8yydefact = internal constant [54 x i8] c"\00\10\11\12\00\00\02\03\05\06\15\16\07\15\00\01\04\00\19\0A\1C\1D\1E\1F !\22#$%\00\18\13\1A\00\00\0D\17\14\00\0B\0E\00\00\1B\00\00\0A\00\0C\0F\09\00\08", align 16
@_ZL4yyr2 = internal constant [38 x i8] c"\00\02\01\01\02\01\01\01\03\02\02\04\06\00\01\03\01\01\01\03\04\01\01\03\03\00\01\03\01\01\01\01\01\01\01\01\01\01", align 16
@_ZL4yyr1 = internal constant [38 x i8] c"\00\17\18\19\19\1A\1A\1A\1B\1B\1C\1C\1D\1E\1E\1E\1F  !!!!!!\22\22\22##########", align 16
@_ZL7yypgoto = internal constant [13 x i8] c"\DF\DF\F2\FB\DF\E0\DF\DF\00\DF\FE\DF\DF", align 1
@_ZL9yydefgoto = internal constant [13 x i8] c"\FF\05\06\071\08\09*\0D\0B\0C\22\1E", align 1
@.str.1 = private unnamed_addr constant [13 x i8] c"syntax error\00", align 1
@.str.2 = private unnamed_addr constant [18 x i8] c"Error: discarding\00", align 1
@.str.3 = private unnamed_addr constant [15 x i8] c"Error: popping\00", align 1
@_ZL6yystos = internal constant [54 x i8] c"\00\03\04\05\0D\18\19\1A\1C\1D\1F !\1F!\00\1A\0C\0D\1F\06\07\08\09\0A\0B\13\14\15\16#\0E!!\22\0C\0D!\0E\11!\1C\1E\1F!\0E\11\1F\0F\1B\1C\10\19\10", align 16
@.str.4 = private unnamed_addr constant [17 x i8] c"memory exhausted\00", align 1
@.str.5 = private unnamed_addr constant [30 x i8] c"Cleanup: discarding lookahead\00", align 1
@.str.6 = private unnamed_addr constant [17 x i8] c"Cleanup: popping\00", align 1
@_ZTV6NBlock = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI6NBlock to i8*), i8* bitcast (void (%class.NBlock*)* @_ZN6NBlockD2Ev to i8*), i8* bitcast (void (%class.NBlock*)* @_ZN6NBlockD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NBlock*, %class.CodeGenContext*)* @_ZN6NBlock7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTVN10__cxxabiv120__si_class_type_infoE = external dso_local global i8*
@_ZTS6NBlock = linkonce_odr dso_local constant [8 x i8] c"6NBlock\00", comdat
@_ZTS11NExpression = linkonce_odr dso_local constant [14 x i8] c"11NExpression\00", comdat
@_ZTVN10__cxxabiv117__class_type_infoE = external dso_local global i8*
@_ZTS4Node = linkonce_odr dso_local constant [6 x i8] c"4Node\00", comdat
@_ZTI4Node = linkonce_odr dso_local constant { i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv117__class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_ZTS4Node, i32 0, i32 0) }, comdat
@_ZTI11NExpression = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_ZTS11NExpression, i32 0, i32 0), i8* bitcast ({ i8*, i8* }* @_ZTI4Node to i8*) }, comdat
@_ZTI6NBlock = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([8 x i8], [8 x i8]* @_ZTS6NBlock, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NExpression to i8*) }, comdat
@_ZTV11NExpression = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NExpression to i8*), i8* bitcast (void (%class.NExpression*)* @_ZN11NExpressionD2Ev to i8*), i8* bitcast (void (%class.NExpression*)* @_ZN11NExpressionD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.Node*, %class.CodeGenContext*)* @_ZN4Node7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTV4Node = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8* }* @_ZTI4Node to i8*), i8* bitcast (void (%class.Node*)* @_ZN4NodeD2Ev to i8*), i8* bitcast (void (%class.Node*)* @_ZN4NodeD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.Node*, %class.CodeGenContext*)* @_ZN4Node7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTV20NExpressionStatement = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI20NExpressionStatement to i8*), i8* bitcast (void (%class.NExpressionStatement*)* @_ZN20NExpressionStatementD2Ev to i8*), i8* bitcast (void (%class.NExpressionStatement*)* @_ZN20NExpressionStatementD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NExpressionStatement*, %class.CodeGenContext*)* @_ZN20NExpressionStatement7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS20NExpressionStatement = linkonce_odr dso_local constant [23 x i8] c"20NExpressionStatement\00", comdat
@_ZTS10NStatement = linkonce_odr dso_local constant [13 x i8] c"10NStatement\00", comdat
@_ZTI10NStatement = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([13 x i8], [13 x i8]* @_ZTS10NStatement, i32 0, i32 0), i8* bitcast ({ i8*, i8* }* @_ZTI4Node to i8*) }, comdat
@_ZTI20NExpressionStatement = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([23 x i8], [23 x i8]* @_ZTS20NExpressionStatement, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI10NStatement to i8*) }, comdat
@_ZTV10NStatement = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI10NStatement to i8*), i8* bitcast (void (%class.NStatement*)* @_ZN10NStatementD2Ev to i8*), i8* bitcast (void (%class.NStatement*)* @_ZN10NStatementD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.Node*, %class.CodeGenContext*)* @_ZN4Node7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTV20NVariableDeclaration = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI20NVariableDeclaration to i8*), i8* bitcast (void (%class.NVariableDeclaration*)* @_ZN20NVariableDeclarationD2Ev to i8*), i8* bitcast (void (%class.NVariableDeclaration*)* @_ZN20NVariableDeclarationD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NVariableDeclaration*, %class.CodeGenContext*)* @_ZN20NVariableDeclaration7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS20NVariableDeclaration = linkonce_odr dso_local constant [23 x i8] c"20NVariableDeclaration\00", comdat
@_ZTI20NVariableDeclaration = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([23 x i8], [23 x i8]* @_ZTS20NVariableDeclaration, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI10NStatement to i8*) }, comdat
@_ZTV20NFunctionDeclaration = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI20NFunctionDeclaration to i8*), i8* bitcast (void (%class.NFunctionDeclaration*)* @_ZN20NFunctionDeclarationD2Ev to i8*), i8* bitcast (void (%class.NFunctionDeclaration*)* @_ZN20NFunctionDeclarationD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NFunctionDeclaration*, %class.CodeGenContext*)* @_ZN20NFunctionDeclaration7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS20NFunctionDeclaration = linkonce_odr dso_local constant [23 x i8] c"20NFunctionDeclaration\00", comdat
@_ZTI20NFunctionDeclaration = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([23 x i8], [23 x i8]* @_ZTS20NFunctionDeclaration, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI10NStatement to i8*) }, comdat
@_ZTV11NIdentifier = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NIdentifier to i8*), i8* bitcast (void (%class.NIdentifier*)* @_ZN11NIdentifierD2Ev to i8*), i8* bitcast (void (%class.NIdentifier*)* @_ZN11NIdentifierD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NIdentifier*, %class.CodeGenContext*)* @_ZN11NIdentifier7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS11NIdentifier = linkonce_odr dso_local constant [14 x i8] c"11NIdentifier\00", comdat
@_ZTI11NIdentifier = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_ZTS11NIdentifier, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NExpression to i8*) }, comdat
@_ZTV7NDouble = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI7NDouble to i8*), i8* bitcast (void (%class.NDouble*)* @_ZN7NDoubleD2Ev to i8*), i8* bitcast (void (%class.NDouble*)* @_ZN7NDoubleD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NDouble*, %class.CodeGenContext*)* @_ZN7NDouble7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS7NDouble = linkonce_odr dso_local constant [9 x i8] c"7NDouble\00", comdat
@_ZTI7NDouble = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @_ZTS7NDouble, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NExpression to i8*) }, comdat
@_ZTV11NAssignment = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NAssignment to i8*), i8* bitcast (void (%class.NAssignment*)* @_ZN11NAssignmentD2Ev to i8*), i8* bitcast (void (%class.NAssignment*)* @_ZN11NAssignmentD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NAssignment*, %class.CodeGenContext*)* @_ZN11NAssignment7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS11NAssignment = linkonce_odr dso_local constant [14 x i8] c"11NAssignment\00", comdat
@_ZTI11NAssignment = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_ZTS11NAssignment, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NExpression to i8*) }, comdat
@_ZTV11NMethodCall = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NMethodCall to i8*), i8* bitcast (void (%class.NMethodCall*)* @_ZN11NMethodCallD2Ev to i8*), i8* bitcast (void (%class.NMethodCall*)* @_ZN11NMethodCallD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NMethodCall*, %class.CodeGenContext*)* @_ZN11NMethodCall7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS11NMethodCall = linkonce_odr dso_local constant [14 x i8] c"11NMethodCall\00", comdat
@_ZTI11NMethodCall = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_ZTS11NMethodCall, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NExpression to i8*) }, comdat
@_ZTV15NBinaryOperator = linkonce_odr dso_local unnamed_addr constant { [5 x i8*] } { [5 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTI15NBinaryOperator to i8*), i8* bitcast (void (%class.NBinaryOperator*)* @_ZN15NBinaryOperatorD2Ev to i8*), i8* bitcast (void (%class.NBinaryOperator*)* @_ZN15NBinaryOperatorD0Ev to i8*), i8* bitcast (%"class.llvm::Value"* (%class.NBinaryOperator*, %class.CodeGenContext*)* @_ZN15NBinaryOperator7codeGenER14CodeGenContext to i8*)] }, comdat, align 8
@_ZTS15NBinaryOperator = linkonce_odr dso_local constant [18 x i8] c"15NBinaryOperator\00", comdat
@_ZTI15NBinaryOperator = linkonce_odr dso_local constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i64 2) to i8*), i8* getelementptr inbounds ([18 x i8], [18 x i8]* @_ZTS15NBinaryOperator, i32 0, i32 0), i8* bitcast ({ i8*, i8*, i8* }* @_ZTI11NExpression to i8*) }, comdat
@.str.7 = private unnamed_addr constant [9 x i8] c"Deleting\00", align 1
@.str.8 = private unnamed_addr constant [26 x i8] c"vector::_M_realloc_insert\00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_parser.cpp, i8* null }]

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

; Function Attrs: noinline optnone uwtable
define dso_local void @_Z7yyerrorPKc(i8*) #4 {
  %2 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %3 = load i8*, i8** %2, align 8
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str, i32 0, i32 0), i8* %3)
  ret void
}

declare dso_local i32 @printf(i8*, ...) #1

; Function Attrs: noinline optnone uwtable
define dso_local i32 @_Z7yyparsev() #4 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca [200 x i16], align 16
  %4 = alloca i16*, align 8
  %5 = alloca i16*, align 8
  %6 = alloca [200 x %union.YYSTYPE], align 16
  %7 = alloca %union.YYSTYPE*, align 8
  %8 = alloca %union.YYSTYPE*, align 8
  %9 = alloca i64, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca %union.YYSTYPE, align 8
  %14 = alloca i32, align 4
  %15 = alloca i64, align 8
  %16 = alloca i16*, align 8
  %17 = alloca %union.yyalloc*, align 8
  %18 = alloca i64, align 8
  %19 = alloca i64, align 8
  %20 = alloca i8*
  %21 = alloca i32
  %22 = alloca %"class.std::__cxx11::basic_string", align 8
  %23 = alloca %"class.std::allocator.0", align 1
  %24 = alloca i1, align 1
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  store i32 0, i32* %12, align 4
  store i32 0, i32* %14, align 4
  %27 = getelementptr inbounds [200 x i16], [200 x i16]* %3, i32 0, i32 0
  store i16* %27, i16** %4, align 8
  store i16* %27, i16** %5, align 8
  %28 = getelementptr inbounds [200 x %union.YYSTYPE], [200 x %union.YYSTYPE]* %6, i32 0, i32 0
  store %union.YYSTYPE* %28, %union.YYSTYPE** %7, align 8
  store %union.YYSTYPE* %28, %union.YYSTYPE** %8, align 8
  store i64 200, i64* %9, align 8
  store i32 0, i32* %1, align 4
  store i32 0, i32* %2, align 4
  store i32 0, i32* @yynerrs, align 4
  store i32 -2, i32* @yychar, align 4
  br label %32

; <label>:29:                                     ; preds = %723, %615, %199
  %30 = load i16*, i16** %5, align 8
  %31 = getelementptr inbounds i16, i16* %30, i32 1
  store i16* %31, i16** %5, align 8
  br label %32

; <label>:32:                                     ; preds = %29, %0
  %33 = load i32, i32* %1, align 4
  %34 = trunc i32 %33 to i16
  %35 = load i16*, i16** %5, align 8
  store i16 %34, i16* %35, align 2
  %36 = load i16*, i16** %4, align 8
  %37 = load i64, i64* %9, align 8
  %38 = getelementptr inbounds i16, i16* %36, i64 %37
  %39 = getelementptr inbounds i16, i16* %38, i64 -1
  %40 = load i16*, i16** %5, align 8
  %41 = icmp ule i16* %39, %40
  br i1 %41, label %42, label %129

; <label>:42:                                     ; preds = %32
  %43 = load i16*, i16** %5, align 8
  %44 = load i16*, i16** %4, align 8
  %45 = ptrtoint i16* %43 to i64
  %46 = ptrtoint i16* %44 to i64
  %47 = sub i64 %45, %46
  %48 = sdiv exact i64 %47, 2
  %49 = add nsw i64 %48, 1
  store i64 %49, i64* %15, align 8
  %50 = load i64, i64* %9, align 8
  %51 = icmp ule i64 10000, %50
  br i1 %51, label %52, label %53

; <label>:52:                                     ; preds = %42
  br label %730

; <label>:53:                                     ; preds = %42
  %54 = load i64, i64* %9, align 8
  %55 = mul i64 %54, 2
  store i64 %55, i64* %9, align 8
  %56 = load i64, i64* %9, align 8
  %57 = icmp ult i64 10000, %56
  br i1 %57, label %58, label %59

; <label>:58:                                     ; preds = %53
  store i64 10000, i64* %9, align 8
  br label %59

; <label>:59:                                     ; preds = %58, %53
  %60 = load i16*, i16** %4, align 8
  store i16* %60, i16** %16, align 8
  %61 = load i64, i64* %9, align 8
  %62 = mul i64 %61, 10
  %63 = add i64 %62, 7
  %64 = call noalias i8* @malloc(i64 %63) #3
  %65 = bitcast i8* %64 to %union.yyalloc*
  store %union.yyalloc* %65, %union.yyalloc** %17, align 8
  %66 = load %union.yyalloc*, %union.yyalloc** %17, align 8
  %67 = icmp ne %union.yyalloc* %66, null
  br i1 %67, label %69, label %68

; <label>:68:                                     ; preds = %59
  br label %730

; <label>:69:                                     ; preds = %59
  br label %70

; <label>:70:                                     ; preds = %69
  %71 = load %union.yyalloc*, %union.yyalloc** %17, align 8
  %72 = bitcast %union.yyalloc* %71 to i16*
  %73 = bitcast i16* %72 to i8*
  %74 = load i16*, i16** %4, align 8
  %75 = bitcast i16* %74 to i8*
  %76 = load i64, i64* %15, align 8
  %77 = mul i64 %76, 2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %73, i8* align 2 %75, i64 %77, i1 false)
  %78 = load %union.yyalloc*, %union.yyalloc** %17, align 8
  %79 = bitcast %union.yyalloc* %78 to i16*
  store i16* %79, i16** %4, align 8
  %80 = load i64, i64* %9, align 8
  %81 = mul i64 %80, 2
  %82 = add i64 %81, 7
  store i64 %82, i64* %18, align 8
  %83 = load i64, i64* %18, align 8
  %84 = udiv i64 %83, 8
  %85 = load %union.yyalloc*, %union.yyalloc** %17, align 8
  %86 = getelementptr inbounds %union.yyalloc, %union.yyalloc* %85, i64 %84
  store %union.yyalloc* %86, %union.yyalloc** %17, align 8
  br label %87

; <label>:87:                                     ; preds = %70
  br label %88

; <label>:88:                                     ; preds = %87
  %89 = load %union.yyalloc*, %union.yyalloc** %17, align 8
  %90 = bitcast %union.yyalloc* %89 to %union.YYSTYPE*
  %91 = bitcast %union.YYSTYPE* %90 to i8*
  %92 = load %union.YYSTYPE*, %union.YYSTYPE** %7, align 8
  %93 = bitcast %union.YYSTYPE* %92 to i8*
  %94 = load i64, i64* %15, align 8
  %95 = mul i64 %94, 8
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %91, i8* align 8 %93, i64 %95, i1 false)
  %96 = load %union.yyalloc*, %union.yyalloc** %17, align 8
  %97 = bitcast %union.yyalloc* %96 to %union.YYSTYPE*
  store %union.YYSTYPE* %97, %union.YYSTYPE** %7, align 8
  %98 = load i64, i64* %9, align 8
  %99 = mul i64 %98, 8
  %100 = add i64 %99, 7
  store i64 %100, i64* %19, align 8
  %101 = load i64, i64* %19, align 8
  %102 = udiv i64 %101, 8
  %103 = load %union.yyalloc*, %union.yyalloc** %17, align 8
  %104 = getelementptr inbounds %union.yyalloc, %union.yyalloc* %103, i64 %102
  store %union.yyalloc* %104, %union.yyalloc** %17, align 8
  br label %105

; <label>:105:                                    ; preds = %88
  %106 = load i16*, i16** %16, align 8
  %107 = getelementptr inbounds [200 x i16], [200 x i16]* %3, i32 0, i32 0
  %108 = icmp ne i16* %106, %107
  br i1 %108, label %109, label %112

; <label>:109:                                    ; preds = %105
  %110 = load i16*, i16** %16, align 8
  %111 = bitcast i16* %110 to i8*
  call void @free(i8* %111) #3
  br label %112

; <label>:112:                                    ; preds = %109, %105
  %113 = load i16*, i16** %4, align 8
  %114 = load i64, i64* %15, align 8
  %115 = getelementptr inbounds i16, i16* %113, i64 %114
  %116 = getelementptr inbounds i16, i16* %115, i64 -1
  store i16* %116, i16** %5, align 8
  %117 = load %union.YYSTYPE*, %union.YYSTYPE** %7, align 8
  %118 = load i64, i64* %15, align 8
  %119 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %117, i64 %118
  %120 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %119, i64 -1
  store %union.YYSTYPE* %120, %union.YYSTYPE** %8, align 8
  %121 = load i16*, i16** %4, align 8
  %122 = load i64, i64* %9, align 8
  %123 = getelementptr inbounds i16, i16* %121, i64 %122
  %124 = getelementptr inbounds i16, i16* %123, i64 -1
  %125 = load i16*, i16** %5, align 8
  %126 = icmp ule i16* %124, %125
  br i1 %126, label %127, label %128

; <label>:127:                                    ; preds = %112
  br label %729

; <label>:128:                                    ; preds = %112
  br label %129

; <label>:129:                                    ; preds = %128, %32
  %130 = load i32, i32* %1, align 4
  %131 = icmp eq i32 %130, 15
  br i1 %131, label %132, label %133

; <label>:132:                                    ; preds = %129
  br label %728

; <label>:133:                                    ; preds = %129
  br label %134

; <label>:134:                                    ; preds = %133
  %135 = load i32, i32* %1, align 4
  %136 = sext i32 %135 to i64
  %137 = getelementptr inbounds [54 x i8], [54 x i8]* @_ZL6yypact, i64 0, i64 %136
  %138 = load i8, i8* %137, align 1
  %139 = sext i8 %138 to i32
  store i32 %139, i32* %10, align 4
  %140 = load i32, i32* %10, align 4
  %141 = icmp eq i32 %140, -33
  br i1 %141, label %142, label %143

; <label>:142:                                    ; preds = %134
  br label %204

; <label>:143:                                    ; preds = %134
  %144 = load i32, i32* @yychar, align 4
  %145 = icmp eq i32 %144, -2
  br i1 %145, label %146, label %148

; <label>:146:                                    ; preds = %143
  %147 = call i32 @_Z5yylexv()
  store i32 %147, i32* @yychar, align 4
  br label %148

; <label>:148:                                    ; preds = %146, %143
  %149 = load i32, i32* @yychar, align 4
  %150 = icmp sle i32 %149, 0
  br i1 %150, label %151, label %152

; <label>:151:                                    ; preds = %148
  store i32 0, i32* %12, align 4
  store i32 0, i32* @yychar, align 4
  br label %164

; <label>:152:                                    ; preds = %148
  %153 = load i32, i32* @yychar, align 4
  %154 = icmp ule i32 %153, 277
  br i1 %154, label %155, label %161

; <label>:155:                                    ; preds = %152
  %156 = load i32, i32* @yychar, align 4
  %157 = sext i32 %156 to i64
  %158 = getelementptr inbounds [278 x i8], [278 x i8]* @_ZL11yytranslate, i64 0, i64 %157
  %159 = load i8, i8* %158, align 1
  %160 = zext i8 %159 to i32
  br label %162

; <label>:161:                                    ; preds = %152
  br label %162

; <label>:162:                                    ; preds = %161, %155
  %163 = phi i32 [ %160, %155 ], [ 2, %161 ]
  store i32 %163, i32* %12, align 4
  br label %164

; <label>:164:                                    ; preds = %162, %151
  %165 = load i32, i32* %12, align 4
  %166 = load i32, i32* %10, align 4
  %167 = add nsw i32 %166, %165
  store i32 %167, i32* %10, align 4
  %168 = load i32, i32* %10, align 4
  %169 = icmp slt i32 %168, 0
  br i1 %169, label %181, label %170

; <label>:170:                                    ; preds = %164
  %171 = load i32, i32* %10, align 4
  %172 = icmp slt i32 86, %171
  br i1 %172, label %181, label %173

; <label>:173:                                    ; preds = %170
  %174 = load i32, i32* %10, align 4
  %175 = sext i32 %174 to i64
  %176 = getelementptr inbounds [87 x i8], [87 x i8]* @_ZL7yycheck, i64 0, i64 %175
  %177 = load i8, i8* %176, align 1
  %178 = sext i8 %177 to i32
  %179 = load i32, i32* %12, align 4
  %180 = icmp ne i32 %178, %179
  br i1 %180, label %181, label %182

; <label>:181:                                    ; preds = %173, %170, %164
  br label %204

; <label>:182:                                    ; preds = %173
  %183 = load i32, i32* %10, align 4
  %184 = sext i32 %183 to i64
  %185 = getelementptr inbounds [87 x i8], [87 x i8]* @_ZL7yytable, i64 0, i64 %184
  %186 = load i8, i8* %185, align 1
  %187 = zext i8 %186 to i32
  store i32 %187, i32* %10, align 4
  %188 = load i32, i32* %10, align 4
  %189 = icmp sle i32 %188, 0
  br i1 %189, label %190, label %193

; <label>:190:                                    ; preds = %182
  %191 = load i32, i32* %10, align 4
  %192 = sub nsw i32 0, %191
  store i32 %192, i32* %10, align 4
  br label %214

; <label>:193:                                    ; preds = %182
  %194 = load i32, i32* %2, align 4
  %195 = icmp ne i32 %194, 0
  br i1 %195, label %196, label %199

; <label>:196:                                    ; preds = %193
  %197 = load i32, i32* %2, align 4
  %198 = add nsw i32 %197, -1
  store i32 %198, i32* %2, align 4
  br label %199

; <label>:199:                                    ; preds = %196, %193
  store i32 -2, i32* @yychar, align 4
  %200 = load i32, i32* %10, align 4
  store i32 %200, i32* %1, align 4
  %201 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %202 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %201, i32 1
  store %union.YYSTYPE* %202, %union.YYSTYPE** %8, align 8
  %203 = bitcast %union.YYSTYPE* %202 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %203, i8* align 8 bitcast (%union.YYSTYPE* @yylval to i8*), i64 8, i1 false)
  br label %29

; <label>:204:                                    ; preds = %181, %142
  %205 = load i32, i32* %1, align 4
  %206 = sext i32 %205 to i64
  %207 = getelementptr inbounds [54 x i8], [54 x i8]* @_ZL8yydefact, i64 0, i64 %206
  %208 = load i8, i8* %207, align 1
  %209 = zext i8 %208 to i32
  store i32 %209, i32* %10, align 4
  %210 = load i32, i32* %10, align 4
  %211 = icmp eq i32 %210, 0
  br i1 %211, label %212, label %213

; <label>:212:                                    ; preds = %204
  br label %617

; <label>:213:                                    ; preds = %204
  br label %214

; <label>:214:                                    ; preds = %213, %190
  %215 = load i32, i32* %10, align 4
  %216 = sext i32 %215 to i64
  %217 = getelementptr inbounds [38 x i8], [38 x i8]* @_ZL4yyr2, i64 0, i64 %216
  %218 = load i8, i8* %217, align 1
  %219 = zext i8 %218 to i32
  store i32 %219, i32* %14, align 4
  %220 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %221 = load i32, i32* %14, align 4
  %222 = sub nsw i32 1, %221
  %223 = sext i32 %222 to i64
  %224 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %220, i64 %223
  %225 = bitcast %union.YYSTYPE* %13 to i8*
  %226 = bitcast %union.YYSTYPE* %224 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %225, i8* align 8 %226, i64 8, i1 false)
  %227 = load i32, i32* %10, align 4
  switch i32 %227, label %557 [
    i32 2, label %228
    i32 3, label %233
    i32 4, label %248
    i32 7, label %257
    i32 8, label %271
    i32 9, label %277
    i32 10, label %286
    i32 11, label %304
    i32 12, label %326
    i32 13, label %360
    i32 14, label %364
    i32 15, label %373
    i32 16, label %381
    i32 17, label %402
    i32 18, label %434
    i32 19, label %458
    i32 20, label %476
    i32 21, label %502
    i32 23, label %508
    i32 24, label %530
    i32 25, label %536
    i32 26, label %540
    i32 27, label %549
  ]

; <label>:228:                                    ; preds = %214
  %229 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %230 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %229, i64 0
  %231 = bitcast %union.YYSTYPE* %230 to %class.NBlock**
  %232 = load %class.NBlock*, %class.NBlock** %231, align 8
  store %class.NBlock* %232, %class.NBlock** @programBlock, align 8
  br label %558

; <label>:233:                                    ; preds = %214
  %234 = call i8* @_Znwm(i64 32) #13
  %235 = bitcast i8* %234 to %class.NBlock*
  invoke void @_ZN6NBlockC2Ev(%class.NBlock* %235)
          to label %236 unwind label %244

; <label>:236:                                    ; preds = %233
  %237 = bitcast %union.YYSTYPE* %13 to %class.NBlock**
  store %class.NBlock* %235, %class.NBlock** %237, align 8
  %238 = bitcast %union.YYSTYPE* %13 to %class.NBlock**
  %239 = load %class.NBlock*, %class.NBlock** %238, align 8
  %240 = getelementptr inbounds %class.NBlock, %class.NBlock* %239, i32 0, i32 1
  %241 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %242 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %241, i64 0
  %243 = bitcast %union.YYSTYPE* %242 to %class.NStatement**
  call void @_ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_(%"class.std::vector"* %240, %class.NStatement** dereferenceable(8) %243)
  br label %558

; <label>:244:                                    ; preds = %233
  %245 = landingpad { i8*, i32 }
          cleanup
  %246 = extractvalue { i8*, i32 } %245, 0
  store i8* %246, i8** %20, align 8
  %247 = extractvalue { i8*, i32 } %245, 1
  store i32 %247, i32* %21, align 4
  call void @_ZdlPv(i8* %234) #14
  br label %783

; <label>:248:                                    ; preds = %214
  %249 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %250 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %249, i64 -1
  %251 = bitcast %union.YYSTYPE* %250 to %class.NBlock**
  %252 = load %class.NBlock*, %class.NBlock** %251, align 8
  %253 = getelementptr inbounds %class.NBlock, %class.NBlock* %252, i32 0, i32 1
  %254 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %255 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %254, i64 0
  %256 = bitcast %union.YYSTYPE* %255 to %class.NStatement**
  call void @_ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_(%"class.std::vector"* %253, %class.NStatement** dereferenceable(8) %256)
  br label %558

; <label>:257:                                    ; preds = %214
  %258 = call i8* @_Znwm(i64 16) #13
  %259 = bitcast i8* %258 to %class.NExpressionStatement*
  %260 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %261 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %260, i64 0
  %262 = bitcast %union.YYSTYPE* %261 to %class.NExpression**
  %263 = load %class.NExpression*, %class.NExpression** %262, align 8
  invoke void @_ZN20NExpressionStatementC2ER11NExpression(%class.NExpressionStatement* %259, %class.NExpression* dereferenceable(8) %263)
          to label %264 unwind label %267

; <label>:264:                                    ; preds = %257
  %265 = bitcast %class.NExpressionStatement* %259 to %class.NStatement*
  %266 = bitcast %union.YYSTYPE* %13 to %class.NStatement**
  store %class.NStatement* %265, %class.NStatement** %266, align 8
  br label %558

; <label>:267:                                    ; preds = %257
  %268 = landingpad { i8*, i32 }
          cleanup
  %269 = extractvalue { i8*, i32 } %268, 0
  store i8* %269, i8** %20, align 8
  %270 = extractvalue { i8*, i32 } %268, 1
  store i32 %270, i32* %21, align 4
  call void @_ZdlPv(i8* %258) #14
  br label %783

; <label>:271:                                    ; preds = %214
  %272 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %273 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %272, i64 -1
  %274 = bitcast %union.YYSTYPE* %273 to %class.NBlock**
  %275 = load %class.NBlock*, %class.NBlock** %274, align 8
  %276 = bitcast %union.YYSTYPE* %13 to %class.NBlock**
  store %class.NBlock* %275, %class.NBlock** %276, align 8
  br label %558

; <label>:277:                                    ; preds = %214
  %278 = call i8* @_Znwm(i64 32) #13
  %279 = bitcast i8* %278 to %class.NBlock*
  invoke void @_ZN6NBlockC2Ev(%class.NBlock* %279)
          to label %280 unwind label %282

; <label>:280:                                    ; preds = %277
  %281 = bitcast %union.YYSTYPE* %13 to %class.NBlock**
  store %class.NBlock* %279, %class.NBlock** %281, align 8
  br label %558

; <label>:282:                                    ; preds = %277
  %283 = landingpad { i8*, i32 }
          cleanup
  %284 = extractvalue { i8*, i32 } %283, 0
  store i8* %284, i8** %20, align 8
  %285 = extractvalue { i8*, i32 } %283, 1
  store i32 %285, i32* %21, align 4
  call void @_ZdlPv(i8* %278) #14
  br label %783

; <label>:286:                                    ; preds = %214
  %287 = call i8* @_Znwm(i64 32) #13
  %288 = bitcast i8* %287 to %class.NVariableDeclaration*
  %289 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %290 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %289, i64 -1
  %291 = bitcast %union.YYSTYPE* %290 to %class.NIdentifier**
  %292 = load %class.NIdentifier*, %class.NIdentifier** %291, align 8
  %293 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %294 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %293, i64 0
  %295 = bitcast %union.YYSTYPE* %294 to %class.NIdentifier**
  %296 = load %class.NIdentifier*, %class.NIdentifier** %295, align 8
  invoke void @_ZN20NVariableDeclarationC2ERK11NIdentifierRS0_(%class.NVariableDeclaration* %288, %class.NIdentifier* dereferenceable(40) %292, %class.NIdentifier* dereferenceable(40) %296)
          to label %297 unwind label %300

; <label>:297:                                    ; preds = %286
  %298 = bitcast %class.NVariableDeclaration* %288 to %class.NStatement*
  %299 = bitcast %union.YYSTYPE* %13 to %class.NStatement**
  store %class.NStatement* %298, %class.NStatement** %299, align 8
  br label %558

; <label>:300:                                    ; preds = %286
  %301 = landingpad { i8*, i32 }
          cleanup
  %302 = extractvalue { i8*, i32 } %301, 0
  store i8* %302, i8** %20, align 8
  %303 = extractvalue { i8*, i32 } %301, 1
  store i32 %303, i32* %21, align 4
  call void @_ZdlPv(i8* %287) #14
  br label %783

; <label>:304:                                    ; preds = %214
  %305 = call i8* @_Znwm(i64 32) #13
  %306 = bitcast i8* %305 to %class.NVariableDeclaration*
  %307 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %308 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %307, i64 -3
  %309 = bitcast %union.YYSTYPE* %308 to %class.NIdentifier**
  %310 = load %class.NIdentifier*, %class.NIdentifier** %309, align 8
  %311 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %312 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %311, i64 -2
  %313 = bitcast %union.YYSTYPE* %312 to %class.NIdentifier**
  %314 = load %class.NIdentifier*, %class.NIdentifier** %313, align 8
  %315 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %316 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %315, i64 0
  %317 = bitcast %union.YYSTYPE* %316 to %class.NExpression**
  %318 = load %class.NExpression*, %class.NExpression** %317, align 8
  invoke void @_ZN20NVariableDeclarationC2ERK11NIdentifierRS0_P11NExpression(%class.NVariableDeclaration* %306, %class.NIdentifier* dereferenceable(40) %310, %class.NIdentifier* dereferenceable(40) %314, %class.NExpression* %318)
          to label %319 unwind label %322

; <label>:319:                                    ; preds = %304
  %320 = bitcast %class.NVariableDeclaration* %306 to %class.NStatement*
  %321 = bitcast %union.YYSTYPE* %13 to %class.NStatement**
  store %class.NStatement* %320, %class.NStatement** %321, align 8
  br label %558

; <label>:322:                                    ; preds = %304
  %323 = landingpad { i8*, i32 }
          cleanup
  %324 = extractvalue { i8*, i32 } %323, 0
  store i8* %324, i8** %20, align 8
  %325 = extractvalue { i8*, i32 } %323, 1
  store i32 %325, i32* %21, align 4
  call void @_ZdlPv(i8* %305) #14
  br label %783

; <label>:326:                                    ; preds = %214
  %327 = call i8* @_Znwm(i64 56) #13
  %328 = bitcast i8* %327 to %class.NFunctionDeclaration*
  %329 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %330 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %329, i64 -5
  %331 = bitcast %union.YYSTYPE* %330 to %class.NIdentifier**
  %332 = load %class.NIdentifier*, %class.NIdentifier** %331, align 8
  %333 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %334 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %333, i64 -4
  %335 = bitcast %union.YYSTYPE* %334 to %class.NIdentifier**
  %336 = load %class.NIdentifier*, %class.NIdentifier** %335, align 8
  %337 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %338 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %337, i64 -2
  %339 = bitcast %union.YYSTYPE* %338 to %"class.std::vector.3"**
  %340 = load %"class.std::vector.3"*, %"class.std::vector.3"** %339, align 8
  %341 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %342 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %341, i64 0
  %343 = bitcast %union.YYSTYPE* %342 to %class.NBlock**
  %344 = load %class.NBlock*, %class.NBlock** %343, align 8
  invoke void @_ZN20NFunctionDeclarationC2ERK11NIdentifierS2_RKSt6vectorIP20NVariableDeclarationSaIS5_EER6NBlock(%class.NFunctionDeclaration* %328, %class.NIdentifier* dereferenceable(40) %332, %class.NIdentifier* dereferenceable(40) %336, %"class.std::vector.3"* dereferenceable(24) %340, %class.NBlock* dereferenceable(32) %344)
          to label %345 unwind label %356

; <label>:345:                                    ; preds = %326
  %346 = bitcast %class.NFunctionDeclaration* %328 to %class.NStatement*
  %347 = bitcast %union.YYSTYPE* %13 to %class.NStatement**
  store %class.NStatement* %346, %class.NStatement** %347, align 8
  %348 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %349 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %348, i64 -2
  %350 = bitcast %union.YYSTYPE* %349 to %"class.std::vector.3"**
  %351 = load %"class.std::vector.3"*, %"class.std::vector.3"** %350, align 8
  %352 = icmp eq %"class.std::vector.3"* %351, null
  br i1 %352, label %355, label %353

; <label>:353:                                    ; preds = %345
  call void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev(%"class.std::vector.3"* %351) #3
  %354 = bitcast %"class.std::vector.3"* %351 to i8*
  call void @_ZdlPv(i8* %354) #14
  br label %355

; <label>:355:                                    ; preds = %353, %345
  br label %558

; <label>:356:                                    ; preds = %326
  %357 = landingpad { i8*, i32 }
          cleanup
  %358 = extractvalue { i8*, i32 } %357, 0
  store i8* %358, i8** %20, align 8
  %359 = extractvalue { i8*, i32 } %357, 1
  store i32 %359, i32* %21, align 4
  call void @_ZdlPv(i8* %327) #14
  br label %783

; <label>:360:                                    ; preds = %214
  %361 = call i8* @_Znwm(i64 24) #13
  %362 = bitcast i8* %361 to %"class.std::vector.3"*
  call void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev(%"class.std::vector.3"* %362) #3
  %363 = bitcast %union.YYSTYPE* %13 to %"class.std::vector.3"**
  store %"class.std::vector.3"* %362, %"class.std::vector.3"** %363, align 8
  br label %558

; <label>:364:                                    ; preds = %214
  %365 = call i8* @_Znwm(i64 24) #13
  %366 = bitcast i8* %365 to %"class.std::vector.3"*
  call void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev(%"class.std::vector.3"* %366) #3
  %367 = bitcast %union.YYSTYPE* %13 to %"class.std::vector.3"**
  store %"class.std::vector.3"* %366, %"class.std::vector.3"** %367, align 8
  %368 = bitcast %union.YYSTYPE* %13 to %"class.std::vector.3"**
  %369 = load %"class.std::vector.3"*, %"class.std::vector.3"** %368, align 8
  %370 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %371 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %370, i64 0
  %372 = bitcast %union.YYSTYPE* %371 to %class.NVariableDeclaration**
  call void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_(%"class.std::vector.3"* %369, %class.NVariableDeclaration** dereferenceable(8) %372)
  br label %558

; <label>:373:                                    ; preds = %214
  %374 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %375 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %374, i64 -2
  %376 = bitcast %union.YYSTYPE* %375 to %"class.std::vector.3"**
  %377 = load %"class.std::vector.3"*, %"class.std::vector.3"** %376, align 8
  %378 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %379 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %378, i64 0
  %380 = bitcast %union.YYSTYPE* %379 to %class.NVariableDeclaration**
  call void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_(%"class.std::vector.3"* %377, %class.NVariableDeclaration** dereferenceable(8) %380)
  br label %558

; <label>:381:                                    ; preds = %214
  %382 = call i8* @_Znwm(i64 40) #13
  %383 = bitcast i8* %382 to %class.NIdentifier*
  %384 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %385 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %384, i64 0
  %386 = bitcast %union.YYSTYPE* %385 to %"class.std::__cxx11::basic_string"**
  %387 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %386, align 8
  invoke void @_ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(%class.NIdentifier* %383, %"class.std::__cxx11::basic_string"* dereferenceable(32) %387)
          to label %388 unwind label %398

; <label>:388:                                    ; preds = %381
  %389 = bitcast %union.YYSTYPE* %13 to %class.NIdentifier**
  store %class.NIdentifier* %383, %class.NIdentifier** %389, align 8
  %390 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %391 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %390, i64 0
  %392 = bitcast %union.YYSTYPE* %391 to %"class.std::__cxx11::basic_string"**
  %393 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %392, align 8
  %394 = icmp eq %"class.std::__cxx11::basic_string"* %393, null
  br i1 %394, label %397, label %395

; <label>:395:                                    ; preds = %388
  call void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(%"class.std::__cxx11::basic_string"* %393) #3
  %396 = bitcast %"class.std::__cxx11::basic_string"* %393 to i8*
  call void @_ZdlPv(i8* %396) #14
  br label %397

; <label>:397:                                    ; preds = %395, %388
  br label %558

; <label>:398:                                    ; preds = %381
  %399 = landingpad { i8*, i32 }
          cleanup
  %400 = extractvalue { i8*, i32 } %399, 0
  store i8* %400, i8** %20, align 8
  %401 = extractvalue { i8*, i32 } %399, 1
  store i32 %401, i32* %21, align 4
  call void @_ZdlPv(i8* %382) #14
  br label %783

; <label>:402:                                    ; preds = %214
  %403 = call i8* @_Znwm(i64 40) #13
  store i1 true, i1* %24, align 1
  %404 = bitcast i8* %403 to %class.NIdentifier*
  %405 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %406 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %405, i64 0
  %407 = bitcast %union.YYSTYPE* %406 to %"class.std::__cxx11::basic_string"**
  %408 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %407, align 8
  %409 = call i8* @_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv(%"class.std::__cxx11::basic_string"* %408) #3
  call void @_ZNSaIcEC1Ev(%"class.std::allocator.0"* %23) #3
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_(%"class.std::__cxx11::basic_string"* %22, i8* %409, %"class.std::allocator.0"* dereferenceable(1) %23)
          to label %410 unwind label %422

; <label>:410:                                    ; preds = %402
  invoke void @_ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(%class.NIdentifier* %404, %"class.std::__cxx11::basic_string"* dereferenceable(32) %22)
          to label %411 unwind label %426

; <label>:411:                                    ; preds = %410
  store i1 false, i1* %24, align 1
  %412 = bitcast %class.NIdentifier* %404 to %class.NExpression*
  %413 = bitcast %union.YYSTYPE* %13 to %class.NExpression**
  store %class.NExpression* %412, %class.NExpression** %413, align 8
  call void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(%"class.std::__cxx11::basic_string"* %22) #3
  call void @_ZNSaIcED1Ev(%"class.std::allocator.0"* %23) #3
  %414 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %415 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %414, i64 0
  %416 = bitcast %union.YYSTYPE* %415 to %"class.std::__cxx11::basic_string"**
  %417 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %416, align 8
  %418 = icmp eq %"class.std::__cxx11::basic_string"* %417, null
  br i1 %418, label %421, label %419

; <label>:419:                                    ; preds = %411
  call void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(%"class.std::__cxx11::basic_string"* %417) #3
  %420 = bitcast %"class.std::__cxx11::basic_string"* %417 to i8*
  call void @_ZdlPv(i8* %420) #14
  br label %421

; <label>:421:                                    ; preds = %419, %411
  br label %558

; <label>:422:                                    ; preds = %402
  %423 = landingpad { i8*, i32 }
          cleanup
  %424 = extractvalue { i8*, i32 } %423, 0
  store i8* %424, i8** %20, align 8
  %425 = extractvalue { i8*, i32 } %423, 1
  store i32 %425, i32* %21, align 4
  br label %430

; <label>:426:                                    ; preds = %410
  %427 = landingpad { i8*, i32 }
          cleanup
  %428 = extractvalue { i8*, i32 } %427, 0
  store i8* %428, i8** %20, align 8
  %429 = extractvalue { i8*, i32 } %427, 1
  store i32 %429, i32* %21, align 4
  call void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(%"class.std::__cxx11::basic_string"* %22) #3
  br label %430

; <label>:430:                                    ; preds = %426, %422
  call void @_ZNSaIcED1Ev(%"class.std::allocator.0"* %23) #3
  %431 = load i1, i1* %24, align 1
  br i1 %431, label %432, label %433

; <label>:432:                                    ; preds = %430
  call void @_ZdlPv(i8* %403) #14
  br label %433

; <label>:433:                                    ; preds = %432, %430
  br label %783

; <label>:434:                                    ; preds = %214
  %435 = call i8* @_Znwm(i64 16) #13
  %436 = bitcast i8* %435 to %class.NDouble*
  %437 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %438 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %437, i64 0
  %439 = bitcast %union.YYSTYPE* %438 to %"class.std::__cxx11::basic_string"**
  %440 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %439, align 8
  %441 = call i8* @_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv(%"class.std::__cxx11::basic_string"* %440) #3
  %442 = call double @atof(i8* %441) #15
  invoke void @_ZN7NDoubleC2Ed(%class.NDouble* %436, double %442)
          to label %443 unwind label %454

; <label>:443:                                    ; preds = %434
  %444 = bitcast %class.NDouble* %436 to %class.NExpression*
  %445 = bitcast %union.YYSTYPE* %13 to %class.NExpression**
  store %class.NExpression* %444, %class.NExpression** %445, align 8
  %446 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %447 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %446, i64 0
  %448 = bitcast %union.YYSTYPE* %447 to %"class.std::__cxx11::basic_string"**
  %449 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %448, align 8
  %450 = icmp eq %"class.std::__cxx11::basic_string"* %449, null
  br i1 %450, label %453, label %451

; <label>:451:                                    ; preds = %443
  call void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(%"class.std::__cxx11::basic_string"* %449) #3
  %452 = bitcast %"class.std::__cxx11::basic_string"* %449 to i8*
  call void @_ZdlPv(i8* %452) #14
  br label %453

; <label>:453:                                    ; preds = %451, %443
  br label %558

; <label>:454:                                    ; preds = %434
  %455 = landingpad { i8*, i32 }
          cleanup
  %456 = extractvalue { i8*, i32 } %455, 0
  store i8* %456, i8** %20, align 8
  %457 = extractvalue { i8*, i32 } %455, 1
  store i32 %457, i32* %21, align 4
  call void @_ZdlPv(i8* %435) #14
  br label %783

; <label>:458:                                    ; preds = %214
  %459 = call i8* @_Znwm(i64 24) #13
  %460 = bitcast i8* %459 to %class.NAssignment*
  %461 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %462 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %461, i64 -2
  %463 = bitcast %union.YYSTYPE* %462 to %class.NIdentifier**
  %464 = load %class.NIdentifier*, %class.NIdentifier** %463, align 8
  %465 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %466 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %465, i64 0
  %467 = bitcast %union.YYSTYPE* %466 to %class.NExpression**
  %468 = load %class.NExpression*, %class.NExpression** %467, align 8
  invoke void @_ZN11NAssignmentC2ER11NIdentifierR11NExpression(%class.NAssignment* %460, %class.NIdentifier* dereferenceable(40) %464, %class.NExpression* dereferenceable(8) %468)
          to label %469 unwind label %472

; <label>:469:                                    ; preds = %458
  %470 = bitcast %class.NAssignment* %460 to %class.NExpression*
  %471 = bitcast %union.YYSTYPE* %13 to %class.NExpression**
  store %class.NExpression* %470, %class.NExpression** %471, align 8
  br label %558

; <label>:472:                                    ; preds = %458
  %473 = landingpad { i8*, i32 }
          cleanup
  %474 = extractvalue { i8*, i32 } %473, 0
  store i8* %474, i8** %20, align 8
  %475 = extractvalue { i8*, i32 } %473, 1
  store i32 %475, i32* %21, align 4
  call void @_ZdlPv(i8* %459) #14
  br label %783

; <label>:476:                                    ; preds = %214
  %477 = call i8* @_Znwm(i64 40) #13
  %478 = bitcast i8* %477 to %class.NMethodCall*
  %479 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %480 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %479, i64 -3
  %481 = bitcast %union.YYSTYPE* %480 to %class.NIdentifier**
  %482 = load %class.NIdentifier*, %class.NIdentifier** %481, align 8
  %483 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %484 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %483, i64 -1
  %485 = bitcast %union.YYSTYPE* %484 to %"class.std::vector.8"**
  %486 = load %"class.std::vector.8"*, %"class.std::vector.8"** %485, align 8
  invoke void @_ZN11NMethodCallC2ERK11NIdentifierRSt6vectorIP11NExpressionSaIS5_EE(%class.NMethodCall* %478, %class.NIdentifier* dereferenceable(40) %482, %"class.std::vector.8"* dereferenceable(24) %486)
          to label %487 unwind label %498

; <label>:487:                                    ; preds = %476
  %488 = bitcast %class.NMethodCall* %478 to %class.NExpression*
  %489 = bitcast %union.YYSTYPE* %13 to %class.NExpression**
  store %class.NExpression* %488, %class.NExpression** %489, align 8
  %490 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %491 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %490, i64 -1
  %492 = bitcast %union.YYSTYPE* %491 to %"class.std::vector.8"**
  %493 = load %"class.std::vector.8"*, %"class.std::vector.8"** %492, align 8
  %494 = icmp eq %"class.std::vector.8"* %493, null
  br i1 %494, label %497, label %495

; <label>:495:                                    ; preds = %487
  call void @_ZNSt6vectorIP11NExpressionSaIS1_EED2Ev(%"class.std::vector.8"* %493) #3
  %496 = bitcast %"class.std::vector.8"* %493 to i8*
  call void @_ZdlPv(i8* %496) #14
  br label %497

; <label>:497:                                    ; preds = %495, %487
  br label %558

; <label>:498:                                    ; preds = %476
  %499 = landingpad { i8*, i32 }
          cleanup
  %500 = extractvalue { i8*, i32 } %499, 0
  store i8* %500, i8** %20, align 8
  %501 = extractvalue { i8*, i32 } %499, 1
  store i32 %501, i32* %21, align 4
  call void @_ZdlPv(i8* %477) #14
  br label %783

; <label>:502:                                    ; preds = %214
  %503 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %504 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %503, i64 0
  %505 = bitcast %union.YYSTYPE* %504 to %class.NIdentifier**
  %506 = load %class.NIdentifier*, %class.NIdentifier** %505, align 8
  %507 = bitcast %union.YYSTYPE* %13 to %class.NIdentifier**
  store %class.NIdentifier* %506, %class.NIdentifier** %507, align 8
  br label %558

; <label>:508:                                    ; preds = %214
  %509 = call i8* @_Znwm(i64 32) #13
  %510 = bitcast i8* %509 to %class.NBinaryOperator*
  %511 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %512 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %511, i64 -2
  %513 = bitcast %union.YYSTYPE* %512 to %class.NExpression**
  %514 = load %class.NExpression*, %class.NExpression** %513, align 8
  %515 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %516 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %515, i64 -1
  %517 = bitcast %union.YYSTYPE* %516 to i32*
  %518 = load i32, i32* %517, align 8
  %519 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %520 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %519, i64 0
  %521 = bitcast %union.YYSTYPE* %520 to %class.NExpression**
  %522 = load %class.NExpression*, %class.NExpression** %521, align 8
  invoke void @_ZN15NBinaryOperatorC2ER11NExpressioniS1_(%class.NBinaryOperator* %510, %class.NExpression* dereferenceable(8) %514, i32 %518, %class.NExpression* dereferenceable(8) %522)
          to label %523 unwind label %526

; <label>:523:                                    ; preds = %508
  %524 = bitcast %class.NBinaryOperator* %510 to %class.NExpression*
  %525 = bitcast %union.YYSTYPE* %13 to %class.NExpression**
  store %class.NExpression* %524, %class.NExpression** %525, align 8
  br label %558

; <label>:526:                                    ; preds = %508
  %527 = landingpad { i8*, i32 }
          cleanup
  %528 = extractvalue { i8*, i32 } %527, 0
  store i8* %528, i8** %20, align 8
  %529 = extractvalue { i8*, i32 } %527, 1
  store i32 %529, i32* %21, align 4
  call void @_ZdlPv(i8* %509) #14
  br label %783

; <label>:530:                                    ; preds = %214
  %531 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %532 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %531, i64 -1
  %533 = bitcast %union.YYSTYPE* %532 to %class.NExpression**
  %534 = load %class.NExpression*, %class.NExpression** %533, align 8
  %535 = bitcast %union.YYSTYPE* %13 to %class.NExpression**
  store %class.NExpression* %534, %class.NExpression** %535, align 8
  br label %558

; <label>:536:                                    ; preds = %214
  %537 = call i8* @_Znwm(i64 24) #13
  %538 = bitcast i8* %537 to %"class.std::vector.8"*
  call void @_ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev(%"class.std::vector.8"* %538) #3
  %539 = bitcast %union.YYSTYPE* %13 to %"class.std::vector.8"**
  store %"class.std::vector.8"* %538, %"class.std::vector.8"** %539, align 8
  br label %558

; <label>:540:                                    ; preds = %214
  %541 = call i8* @_Znwm(i64 24) #13
  %542 = bitcast i8* %541 to %"class.std::vector.8"*
  call void @_ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev(%"class.std::vector.8"* %542) #3
  %543 = bitcast %union.YYSTYPE* %13 to %"class.std::vector.8"**
  store %"class.std::vector.8"* %542, %"class.std::vector.8"** %543, align 8
  %544 = bitcast %union.YYSTYPE* %13 to %"class.std::vector.8"**
  %545 = load %"class.std::vector.8"*, %"class.std::vector.8"** %544, align 8
  %546 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %547 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %546, i64 0
  %548 = bitcast %union.YYSTYPE* %547 to %class.NExpression**
  call void @_ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_(%"class.std::vector.8"* %545, %class.NExpression** dereferenceable(8) %548)
  br label %558

; <label>:549:                                    ; preds = %214
  %550 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %551 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %550, i64 -2
  %552 = bitcast %union.YYSTYPE* %551 to %"class.std::vector.8"**
  %553 = load %"class.std::vector.8"*, %"class.std::vector.8"** %552, align 8
  %554 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %555 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %554, i64 0
  %556 = bitcast %union.YYSTYPE* %555 to %class.NExpression**
  call void @_ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_(%"class.std::vector.8"* %553, %class.NExpression** dereferenceable(8) %556)
  br label %558

; <label>:557:                                    ; preds = %214
  br label %558

; <label>:558:                                    ; preds = %557, %549, %540, %536, %530, %523, %502, %497, %469, %453, %421, %397, %373, %364, %360, %355, %319, %297, %280, %271, %264, %248, %236, %228
  %559 = load i32, i32* %14, align 4
  %560 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %561 = sext i32 %559 to i64
  %562 = sub i64 0, %561
  %563 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %560, i64 %562
  store %union.YYSTYPE* %563, %union.YYSTYPE** %8, align 8
  %564 = load i32, i32* %14, align 4
  %565 = load i16*, i16** %5, align 8
  %566 = sext i32 %564 to i64
  %567 = sub i64 0, %566
  %568 = getelementptr inbounds i16, i16* %565, i64 %567
  store i16* %568, i16** %5, align 8
  store i32 0, i32* %14, align 4
  %569 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %570 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %569, i32 1
  store %union.YYSTYPE* %570, %union.YYSTYPE** %8, align 8
  %571 = bitcast %union.YYSTYPE* %570 to i8*
  %572 = bitcast %union.YYSTYPE* %13 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %571, i8* align 8 %572, i64 8, i1 false)
  %573 = load i32, i32* %10, align 4
  %574 = sext i32 %573 to i64
  %575 = getelementptr inbounds [38 x i8], [38 x i8]* @_ZL4yyr1, i64 0, i64 %574
  %576 = load i8, i8* %575, align 1
  %577 = zext i8 %576 to i32
  %578 = sub nsw i32 %577, 23
  store i32 %578, i32* %25, align 4
  %579 = load i32, i32* %25, align 4
  %580 = sext i32 %579 to i64
  %581 = getelementptr inbounds [13 x i8], [13 x i8]* @_ZL7yypgoto, i64 0, i64 %580
  %582 = load i8, i8* %581, align 1
  %583 = sext i8 %582 to i32
  %584 = load i16*, i16** %5, align 8
  %585 = load i16, i16* %584, align 2
  %586 = sext i16 %585 to i32
  %587 = add nsw i32 %583, %586
  store i32 %587, i32* %26, align 4
  %588 = load i32, i32* %26, align 4
  %589 = icmp sle i32 0, %588
  br i1 %589, label %590, label %609

; <label>:590:                                    ; preds = %558
  %591 = load i32, i32* %26, align 4
  %592 = icmp sle i32 %591, 86
  br i1 %592, label %593, label %609

; <label>:593:                                    ; preds = %590
  %594 = load i32, i32* %26, align 4
  %595 = sext i32 %594 to i64
  %596 = getelementptr inbounds [87 x i8], [87 x i8]* @_ZL7yycheck, i64 0, i64 %595
  %597 = load i8, i8* %596, align 1
  %598 = sext i8 %597 to i32
  %599 = load i16*, i16** %5, align 8
  %600 = load i16, i16* %599, align 2
  %601 = sext i16 %600 to i32
  %602 = icmp eq i32 %598, %601
  br i1 %602, label %603, label %609

; <label>:603:                                    ; preds = %593
  %604 = load i32, i32* %26, align 4
  %605 = sext i32 %604 to i64
  %606 = getelementptr inbounds [87 x i8], [87 x i8]* @_ZL7yytable, i64 0, i64 %605
  %607 = load i8, i8* %606, align 1
  %608 = zext i8 %607 to i32
  br label %615

; <label>:609:                                    ; preds = %593, %590, %558
  %610 = load i32, i32* %25, align 4
  %611 = sext i32 %610 to i64
  %612 = getelementptr inbounds [13 x i8], [13 x i8]* @_ZL9yydefgoto, i64 0, i64 %611
  %613 = load i8, i8* %612, align 1
  %614 = sext i8 %613 to i32
  br label %615

; <label>:615:                                    ; preds = %609, %603
  %616 = phi i32 [ %608, %603 ], [ %614, %609 ]
  store i32 %616, i32* %1, align 4
  br label %29

; <label>:617:                                    ; preds = %212
  %618 = load i32, i32* @yychar, align 4
  %619 = icmp eq i32 %618, -2
  br i1 %619, label %620, label %621

; <label>:620:                                    ; preds = %617
  br label %633

; <label>:621:                                    ; preds = %617
  %622 = load i32, i32* @yychar, align 4
  %623 = icmp ule i32 %622, 277
  br i1 %623, label %624, label %630

; <label>:624:                                    ; preds = %621
  %625 = load i32, i32* @yychar, align 4
  %626 = sext i32 %625 to i64
  %627 = getelementptr inbounds [278 x i8], [278 x i8]* @_ZL11yytranslate, i64 0, i64 %626
  %628 = load i8, i8* %627, align 1
  %629 = zext i8 %628 to i32
  br label %631

; <label>:630:                                    ; preds = %621
  br label %631

; <label>:631:                                    ; preds = %630, %624
  %632 = phi i32 [ %629, %624 ], [ 2, %630 ]
  br label %633

; <label>:633:                                    ; preds = %631, %620
  %634 = phi i32 [ -2, %620 ], [ %632, %631 ]
  store i32 %634, i32* %12, align 4
  %635 = load i32, i32* %2, align 4
  %636 = icmp ne i32 %635, 0
  br i1 %636, label %640, label %637

; <label>:637:                                    ; preds = %633
  %638 = load i32, i32* @yynerrs, align 4
  %639 = add nsw i32 %638, 1
  store i32 %639, i32* @yynerrs, align 4
  call void @_Z7yyerrorPKc(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.1, i32 0, i32 0))
  br label %640

; <label>:640:                                    ; preds = %637, %633
  %641 = load i32, i32* %2, align 4
  %642 = icmp eq i32 %641, 3
  br i1 %642, label %643, label %654

; <label>:643:                                    ; preds = %640
  %644 = load i32, i32* @yychar, align 4
  %645 = icmp sle i32 %644, 0
  br i1 %645, label %646, label %651

; <label>:646:                                    ; preds = %643
  %647 = load i32, i32* @yychar, align 4
  %648 = icmp eq i32 %647, 0
  br i1 %648, label %649, label %650

; <label>:649:                                    ; preds = %646
  br label %729

; <label>:650:                                    ; preds = %646
  br label %653

; <label>:651:                                    ; preds = %643
  %652 = load i32, i32* %12, align 4
  call void @_ZL10yydestructPKciP7YYSTYPE(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i32 0, i32 0), i32 %652, %union.YYSTYPE* @yylval)
  store i32 -2, i32* @yychar, align 4
  br label %653

; <label>:653:                                    ; preds = %651, %650
  br label %654

; <label>:654:                                    ; preds = %653, %640
  br label %669
                                                  ; No predecessors!
  %656 = load i32, i32* %14, align 4
  %657 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %658 = sext i32 %656 to i64
  %659 = sub i64 0, %658
  %660 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %657, i64 %659
  store %union.YYSTYPE* %660, %union.YYSTYPE** %8, align 8
  %661 = load i32, i32* %14, align 4
  %662 = load i16*, i16** %5, align 8
  %663 = sext i32 %661 to i64
  %664 = sub i64 0, %663
  %665 = getelementptr inbounds i16, i16* %662, i64 %664
  store i16* %665, i16** %5, align 8
  store i32 0, i32* %14, align 4
  %666 = load i16*, i16** %5, align 8
  %667 = load i16, i16* %666, align 2
  %668 = sext i16 %667 to i32
  store i32 %668, i32* %1, align 4
  br label %669

; <label>:669:                                    ; preds = %655, %654
  store i32 3, i32* %2, align 4
  br label %670

; <label>:670:                                    ; preds = %709, %669
  %671 = load i32, i32* %1, align 4
  %672 = sext i32 %671 to i64
  %673 = getelementptr inbounds [54 x i8], [54 x i8]* @_ZL6yypact, i64 0, i64 %672
  %674 = load i8, i8* %673, align 1
  %675 = sext i8 %674 to i32
  store i32 %675, i32* %10, align 4
  %676 = load i32, i32* %10, align 4
  %677 = icmp eq i32 %676, -33
  br i1 %677, label %704, label %678

; <label>:678:                                    ; preds = %670
  %679 = load i32, i32* %10, align 4
  %680 = add nsw i32 %679, 1
  store i32 %680, i32* %10, align 4
  %681 = load i32, i32* %10, align 4
  %682 = icmp sle i32 0, %681
  br i1 %682, label %683, label %703

; <label>:683:                                    ; preds = %678
  %684 = load i32, i32* %10, align 4
  %685 = icmp sle i32 %684, 86
  br i1 %685, label %686, label %703

; <label>:686:                                    ; preds = %683
  %687 = load i32, i32* %10, align 4
  %688 = sext i32 %687 to i64
  %689 = getelementptr inbounds [87 x i8], [87 x i8]* @_ZL7yycheck, i64 0, i64 %688
  %690 = load i8, i8* %689, align 1
  %691 = sext i8 %690 to i32
  %692 = icmp eq i32 %691, 1
  br i1 %692, label %693, label %703

; <label>:693:                                    ; preds = %686
  %694 = load i32, i32* %10, align 4
  %695 = sext i32 %694 to i64
  %696 = getelementptr inbounds [87 x i8], [87 x i8]* @_ZL7yytable, i64 0, i64 %695
  %697 = load i8, i8* %696, align 1
  %698 = zext i8 %697 to i32
  store i32 %698, i32* %10, align 4
  %699 = load i32, i32* %10, align 4
  %700 = icmp slt i32 0, %699
  br i1 %700, label %701, label %702

; <label>:701:                                    ; preds = %693
  br label %723

; <label>:702:                                    ; preds = %693
  br label %703

; <label>:703:                                    ; preds = %702, %686, %683, %678
  br label %704

; <label>:704:                                    ; preds = %703, %670
  %705 = load i16*, i16** %5, align 8
  %706 = load i16*, i16** %4, align 8
  %707 = icmp eq i16* %705, %706
  br i1 %707, label %708, label %709

; <label>:708:                                    ; preds = %704
  br label %729

; <label>:709:                                    ; preds = %704
  %710 = load i32, i32* %1, align 4
  %711 = sext i32 %710 to i64
  %712 = getelementptr inbounds [54 x i8], [54 x i8]* @_ZL6yystos, i64 0, i64 %711
  %713 = load i8, i8* %712, align 1
  %714 = zext i8 %713 to i32
  %715 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  call void @_ZL10yydestructPKciP7YYSTYPE(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @.str.3, i32 0, i32 0), i32 %714, %union.YYSTYPE* %715)
  %716 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %717 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %716, i64 -1
  store %union.YYSTYPE* %717, %union.YYSTYPE** %8, align 8
  %718 = load i16*, i16** %5, align 8
  %719 = getelementptr inbounds i16, i16* %718, i64 -1
  store i16* %719, i16** %5, align 8
  %720 = load i16*, i16** %5, align 8
  %721 = load i16, i16* %720, align 2
  %722 = sext i16 %721 to i32
  store i32 %722, i32* %1, align 4
  br label %670

; <label>:723:                                    ; preds = %701
  %724 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %725 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %724, i32 1
  store %union.YYSTYPE* %725, %union.YYSTYPE** %8, align 8
  %726 = bitcast %union.YYSTYPE* %725 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %726, i8* align 8 bitcast (%union.YYSTYPE* @yylval to i8*), i64 8, i1 false)
  %727 = load i32, i32* %10, align 4
  store i32 %727, i32* %1, align 4
  br label %29

; <label>:728:                                    ; preds = %132
  store i32 0, i32* %11, align 4
  br label %731

; <label>:729:                                    ; preds = %708, %649, %127
  store i32 1, i32* %11, align 4
  br label %731

; <label>:730:                                    ; preds = %68, %52
  call void @_Z7yyerrorPKc(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @.str.4, i32 0, i32 0))
  store i32 2, i32* %11, align 4
  br label %731

; <label>:731:                                    ; preds = %730, %729, %728
  %732 = load i32, i32* @yychar, align 4
  %733 = icmp ne i32 %732, -2
  br i1 %733, label %734, label %747

; <label>:734:                                    ; preds = %731
  %735 = load i32, i32* @yychar, align 4
  %736 = icmp ule i32 %735, 277
  br i1 %736, label %737, label %743

; <label>:737:                                    ; preds = %734
  %738 = load i32, i32* @yychar, align 4
  %739 = sext i32 %738 to i64
  %740 = getelementptr inbounds [278 x i8], [278 x i8]* @_ZL11yytranslate, i64 0, i64 %739
  %741 = load i8, i8* %740, align 1
  %742 = zext i8 %741 to i32
  br label %744

; <label>:743:                                    ; preds = %734
  br label %744

; <label>:744:                                    ; preds = %743, %737
  %745 = phi i32 [ %742, %737 ], [ 2, %743 ]
  store i32 %745, i32* %12, align 4
  %746 = load i32, i32* %12, align 4
  call void @_ZL10yydestructPKciP7YYSTYPE(i8* getelementptr inbounds ([30 x i8], [30 x i8]* @.str.5, i32 0, i32 0), i32 %746, %union.YYSTYPE* @yylval)
  br label %747

; <label>:747:                                    ; preds = %744, %731
  %748 = load i32, i32* %14, align 4
  %749 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %750 = sext i32 %748 to i64
  %751 = sub i64 0, %750
  %752 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %749, i64 %751
  store %union.YYSTYPE* %752, %union.YYSTYPE** %8, align 8
  %753 = load i32, i32* %14, align 4
  %754 = load i16*, i16** %5, align 8
  %755 = sext i32 %753 to i64
  %756 = sub i64 0, %755
  %757 = getelementptr inbounds i16, i16* %754, i64 %756
  store i16* %757, i16** %5, align 8
  br label %758

; <label>:758:                                    ; preds = %762, %747
  %759 = load i16*, i16** %5, align 8
  %760 = load i16*, i16** %4, align 8
  %761 = icmp ne i16* %759, %760
  br i1 %761, label %762, label %774

; <label>:762:                                    ; preds = %758
  %763 = load i16*, i16** %5, align 8
  %764 = load i16, i16* %763, align 2
  %765 = sext i16 %764 to i64
  %766 = getelementptr inbounds [54 x i8], [54 x i8]* @_ZL6yystos, i64 0, i64 %765
  %767 = load i8, i8* %766, align 1
  %768 = zext i8 %767 to i32
  %769 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  call void @_ZL10yydestructPKciP7YYSTYPE(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @.str.6, i32 0, i32 0), i32 %768, %union.YYSTYPE* %769)
  %770 = load %union.YYSTYPE*, %union.YYSTYPE** %8, align 8
  %771 = getelementptr inbounds %union.YYSTYPE, %union.YYSTYPE* %770, i64 -1
  store %union.YYSTYPE* %771, %union.YYSTYPE** %8, align 8
  %772 = load i16*, i16** %5, align 8
  %773 = getelementptr inbounds i16, i16* %772, i64 -1
  store i16* %773, i16** %5, align 8
  br label %758

; <label>:774:                                    ; preds = %758
  %775 = load i16*, i16** %4, align 8
  %776 = getelementptr inbounds [200 x i16], [200 x i16]* %3, i32 0, i32 0
  %777 = icmp ne i16* %775, %776
  br i1 %777, label %778, label %781

; <label>:778:                                    ; preds = %774
  %779 = load i16*, i16** %4, align 8
  %780 = bitcast i16* %779 to i8*
  call void @free(i8* %780) #3
  br label %781

; <label>:781:                                    ; preds = %778, %774
  %782 = load i32, i32* %11, align 4
  ret i32 %782

; <label>:783:                                    ; preds = %526, %498, %472, %454, %433, %398, %356, %322, %300, %282, %267, %244
  %784 = load i8*, i8** %20, align 8
  %785 = load i32, i32* %21, align 4
  %786 = insertvalue { i8*, i32 } undef, i8* %784, 0
  %787 = insertvalue { i8*, i32 } %786, i32 %785, 1
  resume { i8*, i32 } %787
}

; Function Attrs: nounwind
declare dso_local noalias i8* @malloc(i64) #2

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #5

; Function Attrs: nounwind
declare dso_local void @free(i8*) #2

declare dso_local i32 @_Z5yylexv() #1

; Function Attrs: nobuiltin
declare dso_local noalias i8* @_Znwm(i64) #6

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN6NBlockC2Ev(%class.NBlock*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NBlock*, align 8
  store %class.NBlock* %0, %class.NBlock** %2, align 8
  %3 = load %class.NBlock*, %class.NBlock** %2, align 8
  %4 = bitcast %class.NBlock* %3 to %class.NExpression*
  call void @_ZN11NExpressionC2Ev(%class.NExpression* %4) #3
  %5 = bitcast %class.NBlock* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV6NBlock, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %5, align 8
  %6 = getelementptr inbounds %class.NBlock, %class.NBlock* %3, i32 0, i32 1
  call void @_ZNSt6vectorIP10NStatementSaIS1_EEC2Ev(%"class.std::vector"* %6) #3
  ret void
}

declare dso_local i32 @__gxx_personality_v0(...)

; Function Attrs: nobuiltin nounwind
declare dso_local void @_ZdlPv(i8*) #8

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP10NStatementSaIS1_EE9push_backERKS1_(%"class.std::vector"*, %class.NStatement** dereferenceable(8)) #4 comdat align 2 {
  %3 = alloca %"class.std::vector"*, align 8
  %4 = alloca %class.NStatement**, align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.14", align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %3, align 8
  store %class.NStatement** %1, %class.NStatement*** %4, align 8
  %6 = load %"class.std::vector"*, %"class.std::vector"** %3, align 8
  %7 = bitcast %"class.std::vector"* %6 to %"struct.std::_Vector_base"*
  %8 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %7, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %8, i32 0, i32 1
  %10 = load %class.NStatement**, %class.NStatement*** %9, align 8
  %11 = bitcast %"class.std::vector"* %6 to %"struct.std::_Vector_base"*
  %12 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %11, i32 0, i32 0
  %13 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %12, i32 0, i32 2
  %14 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %15 = icmp ne %class.NStatement** %10, %14
  br i1 %15, label %16, label %30

; <label>:16:                                     ; preds = %2
  %17 = bitcast %"class.std::vector"* %6 to %"struct.std::_Vector_base"*
  %18 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %17, i32 0, i32 0
  %19 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %18 to %"class.std::allocator"*
  %20 = bitcast %"class.std::vector"* %6 to %"struct.std::_Vector_base"*
  %21 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %20, i32 0, i32 0
  %22 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %21, i32 0, i32 1
  %23 = load %class.NStatement**, %class.NStatement*** %22, align 8
  %24 = load %class.NStatement**, %class.NStatement*** %4, align 8
  call void @_ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator"* dereferenceable(1) %19, %class.NStatement** %23, %class.NStatement** dereferenceable(8) %24)
  %25 = bitcast %"class.std::vector"* %6 to %"struct.std::_Vector_base"*
  %26 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %25, i32 0, i32 0
  %27 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %26, i32 0, i32 1
  %28 = load %class.NStatement**, %class.NStatement*** %27, align 8
  %29 = getelementptr inbounds %class.NStatement*, %class.NStatement** %28, i32 1
  store %class.NStatement** %29, %class.NStatement*** %27, align 8
  br label %36

; <label>:30:                                     ; preds = %2
  %31 = call %class.NStatement** @_ZNSt6vectorIP10NStatementSaIS1_EE3endEv(%"class.std::vector"* %6) #3
  %32 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %5, i32 0, i32 0
  store %class.NStatement** %31, %class.NStatement*** %32, align 8
  %33 = load %class.NStatement**, %class.NStatement*** %4, align 8
  %34 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %5, i32 0, i32 0
  %35 = load %class.NStatement**, %class.NStatement*** %34, align 8
  call void @_ZNSt6vectorIP10NStatementSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(%"class.std::vector"* %6, %class.NStatement** %35, %class.NStatement** dereferenceable(8) %33)
  br label %36

; <label>:36:                                     ; preds = %30, %16
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NExpressionStatementC2ER11NExpression(%class.NExpressionStatement*, %class.NExpression* dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %class.NExpressionStatement*, align 8
  %4 = alloca %class.NExpression*, align 8
  store %class.NExpressionStatement* %0, %class.NExpressionStatement** %3, align 8
  store %class.NExpression* %1, %class.NExpression** %4, align 8
  %5 = load %class.NExpressionStatement*, %class.NExpressionStatement** %3, align 8
  %6 = bitcast %class.NExpressionStatement* %5 to %class.NStatement*
  call void @_ZN10NStatementC2Ev(%class.NStatement* %6) #3
  %7 = bitcast %class.NExpressionStatement* %5 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV20NExpressionStatement, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %7, align 8
  %8 = getelementptr inbounds %class.NExpressionStatement, %class.NExpressionStatement* %5, i32 0, i32 1
  %9 = load %class.NExpression*, %class.NExpression** %4, align 8
  store %class.NExpression* %9, %class.NExpression** %8, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NVariableDeclarationC2ERK11NIdentifierRS0_(%class.NVariableDeclaration*, %class.NIdentifier* dereferenceable(40), %class.NIdentifier* dereferenceable(40)) unnamed_addr #7 comdat align 2 {
  %4 = alloca %class.NVariableDeclaration*, align 8
  %5 = alloca %class.NIdentifier*, align 8
  %6 = alloca %class.NIdentifier*, align 8
  store %class.NVariableDeclaration* %0, %class.NVariableDeclaration** %4, align 8
  store %class.NIdentifier* %1, %class.NIdentifier** %5, align 8
  store %class.NIdentifier* %2, %class.NIdentifier** %6, align 8
  %7 = load %class.NVariableDeclaration*, %class.NVariableDeclaration** %4, align 8
  %8 = bitcast %class.NVariableDeclaration* %7 to %class.NStatement*
  call void @_ZN10NStatementC2Ev(%class.NStatement* %8) #3
  %9 = bitcast %class.NVariableDeclaration* %7 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV20NVariableDeclaration, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %9, align 8
  %10 = getelementptr inbounds %class.NVariableDeclaration, %class.NVariableDeclaration* %7, i32 0, i32 1
  %11 = load %class.NIdentifier*, %class.NIdentifier** %5, align 8
  store %class.NIdentifier* %11, %class.NIdentifier** %10, align 8
  %12 = getelementptr inbounds %class.NVariableDeclaration, %class.NVariableDeclaration* %7, i32 0, i32 2
  %13 = load %class.NIdentifier*, %class.NIdentifier** %6, align 8
  store %class.NIdentifier* %13, %class.NIdentifier** %12, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NVariableDeclarationC2ERK11NIdentifierRS0_P11NExpression(%class.NVariableDeclaration*, %class.NIdentifier* dereferenceable(40), %class.NIdentifier* dereferenceable(40), %class.NExpression*) unnamed_addr #7 comdat align 2 {
  %5 = alloca %class.NVariableDeclaration*, align 8
  %6 = alloca %class.NIdentifier*, align 8
  %7 = alloca %class.NIdentifier*, align 8
  %8 = alloca %class.NExpression*, align 8
  store %class.NVariableDeclaration* %0, %class.NVariableDeclaration** %5, align 8
  store %class.NIdentifier* %1, %class.NIdentifier** %6, align 8
  store %class.NIdentifier* %2, %class.NIdentifier** %7, align 8
  store %class.NExpression* %3, %class.NExpression** %8, align 8
  %9 = load %class.NVariableDeclaration*, %class.NVariableDeclaration** %5, align 8
  %10 = bitcast %class.NVariableDeclaration* %9 to %class.NStatement*
  call void @_ZN10NStatementC2Ev(%class.NStatement* %10) #3
  %11 = bitcast %class.NVariableDeclaration* %9 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV20NVariableDeclaration, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %11, align 8
  %12 = getelementptr inbounds %class.NVariableDeclaration, %class.NVariableDeclaration* %9, i32 0, i32 1
  %13 = load %class.NIdentifier*, %class.NIdentifier** %6, align 8
  store %class.NIdentifier* %13, %class.NIdentifier** %12, align 8
  %14 = getelementptr inbounds %class.NVariableDeclaration, %class.NVariableDeclaration* %9, i32 0, i32 2
  %15 = load %class.NIdentifier*, %class.NIdentifier** %7, align 8
  store %class.NIdentifier* %15, %class.NIdentifier** %14, align 8
  %16 = getelementptr inbounds %class.NVariableDeclaration, %class.NVariableDeclaration* %9, i32 0, i32 3
  %17 = load %class.NExpression*, %class.NExpression** %8, align 8
  store %class.NExpression* %17, %class.NExpression** %16, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZN20NFunctionDeclarationC2ERK11NIdentifierS2_RKSt6vectorIP20NVariableDeclarationSaIS5_EER6NBlock(%class.NFunctionDeclaration*, %class.NIdentifier* dereferenceable(40), %class.NIdentifier* dereferenceable(40), %"class.std::vector.3"* dereferenceable(24), %class.NBlock* dereferenceable(32)) unnamed_addr #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %6 = alloca %class.NFunctionDeclaration*, align 8
  %7 = alloca %class.NIdentifier*, align 8
  %8 = alloca %class.NIdentifier*, align 8
  %9 = alloca %"class.std::vector.3"*, align 8
  %10 = alloca %class.NBlock*, align 8
  %11 = alloca i8*
  %12 = alloca i32
  store %class.NFunctionDeclaration* %0, %class.NFunctionDeclaration** %6, align 8
  store %class.NIdentifier* %1, %class.NIdentifier** %7, align 8
  store %class.NIdentifier* %2, %class.NIdentifier** %8, align 8
  store %"class.std::vector.3"* %3, %"class.std::vector.3"** %9, align 8
  store %class.NBlock* %4, %class.NBlock** %10, align 8
  %13 = load %class.NFunctionDeclaration*, %class.NFunctionDeclaration** %6, align 8
  %14 = bitcast %class.NFunctionDeclaration* %13 to %class.NStatement*
  call void @_ZN10NStatementC2Ev(%class.NStatement* %14) #3
  %15 = bitcast %class.NFunctionDeclaration* %13 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV20NFunctionDeclaration, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %15, align 8
  %16 = getelementptr inbounds %class.NFunctionDeclaration, %class.NFunctionDeclaration* %13, i32 0, i32 1
  %17 = load %class.NIdentifier*, %class.NIdentifier** %7, align 8
  store %class.NIdentifier* %17, %class.NIdentifier** %16, align 8
  %18 = getelementptr inbounds %class.NFunctionDeclaration, %class.NFunctionDeclaration* %13, i32 0, i32 2
  %19 = load %class.NIdentifier*, %class.NIdentifier** %8, align 8
  store %class.NIdentifier* %19, %class.NIdentifier** %18, align 8
  %20 = getelementptr inbounds %class.NFunctionDeclaration, %class.NFunctionDeclaration* %13, i32 0, i32 3
  %21 = load %"class.std::vector.3"*, %"class.std::vector.3"** %9, align 8
  invoke void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2ERKS3_(%"class.std::vector.3"* %20, %"class.std::vector.3"* dereferenceable(24) %21)
          to label %22 unwind label %25

; <label>:22:                                     ; preds = %5
  %23 = getelementptr inbounds %class.NFunctionDeclaration, %class.NFunctionDeclaration* %13, i32 0, i32 4
  %24 = load %class.NBlock*, %class.NBlock** %10, align 8
  store %class.NBlock* %24, %class.NBlock** %23, align 8
  ret void

; <label>:25:                                     ; preds = %5
  %26 = landingpad { i8*, i32 }
          cleanup
  %27 = extractvalue { i8*, i32 } %26, 0
  store i8* %27, i8** %11, align 8
  %28 = extractvalue { i8*, i32 } %26, 1
  store i32 %28, i32* %12, align 4
  %29 = bitcast %class.NFunctionDeclaration* %13 to %class.NStatement*
  call void @_ZN10NStatementD2Ev(%class.NStatement* %29) #3
  br label %30

; <label>:30:                                     ; preds = %25
  %31 = load i8*, i8** %11, align 8
  %32 = load i32, i32* %12, align 4
  %33 = insertvalue { i8*, i32 } undef, i8* %31, 0
  %34 = insertvalue { i8*, i32 } %33, i32 %32, 1
  resume { i8*, i32 } %34
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev(%"class.std::vector.3"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"class.std::vector.3"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %2, align 8
  %5 = load %"class.std::vector.3"*, %"class.std::vector.3"** %2, align 8
  %6 = bitcast %"class.std::vector.3"* %5 to %"struct.std::_Vector_base.4"*
  %7 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %6, i32 0, i32 0
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %7, i32 0, i32 0
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  %10 = bitcast %"class.std::vector.3"* %5 to %"struct.std::_Vector_base.4"*
  %11 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %10, i32 0, i32 0
  %12 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %11, i32 0, i32 1
  %13 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %14 = bitcast %"class.std::vector.3"* %5 to %"struct.std::_Vector_base.4"*
  %15 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %14) #3
  invoke void @_ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(%class.NVariableDeclaration** %9, %class.NVariableDeclaration** %13, %"class.std::allocator.5"* dereferenceable(1) %15)
          to label %16 unwind label %18

; <label>:16:                                     ; preds = %1
  %17 = bitcast %"class.std::vector.3"* %5 to %"struct.std::_Vector_base.4"*
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev(%"struct.std::_Vector_base.4"* %17) #3
  ret void

; <label>:18:                                     ; preds = %1
  %19 = landingpad { i8*, i32 }
          catch i8* null
  %20 = extractvalue { i8*, i32 } %19, 0
  store i8* %20, i8** %3, align 8
  %21 = extractvalue { i8*, i32 } %19, 1
  store i32 %21, i32* %4, align 4
  %22 = bitcast %"class.std::vector.3"* %5 to %"struct.std::_Vector_base.4"*
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev(%"struct.std::_Vector_base.4"* %22) #3
  br label %23

; <label>:23:                                     ; preds = %18
  %24 = load i8*, i8** %3, align 8
  call void @__clang_call_terminate(i8* %24) #10
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2Ev(%"class.std::vector.3"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"class.std::vector.3"*, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %2, align 8
  %3 = load %"class.std::vector.3"*, %"class.std::vector.3"** %2, align 8
  %4 = bitcast %"class.std::vector.3"* %3 to %"struct.std::_Vector_base.4"*
  invoke void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2Ev(%"struct.std::_Vector_base.4"* %4)
          to label %5 unwind label %6

; <label>:5:                                      ; preds = %1
  ret void

; <label>:6:                                      ; preds = %1
  %7 = landingpad { i8*, i32 }
          catch i8* null
  %8 = extractvalue { i8*, i32 } %7, 0
  call void @__clang_call_terminate(i8* %8) #10
  unreachable
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE9push_backERKS1_(%"class.std::vector.3"*, %class.NVariableDeclaration** dereferenceable(8)) #4 comdat align 2 {
  %3 = alloca %"class.std::vector.3"*, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.15", align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %3, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %4, align 8
  %6 = load %"class.std::vector.3"*, %"class.std::vector.3"** %3, align 8
  %7 = bitcast %"class.std::vector.3"* %6 to %"struct.std::_Vector_base.4"*
  %8 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %7, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %8, i32 0, i32 1
  %10 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %9, align 8
  %11 = bitcast %"class.std::vector.3"* %6 to %"struct.std::_Vector_base.4"*
  %12 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %11, i32 0, i32 0
  %13 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %12, i32 0, i32 2
  %14 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %15 = icmp ne %class.NVariableDeclaration** %10, %14
  br i1 %15, label %16, label %30

; <label>:16:                                     ; preds = %2
  %17 = bitcast %"class.std::vector.3"* %6 to %"struct.std::_Vector_base.4"*
  %18 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %17, i32 0, i32 0
  %19 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %18 to %"class.std::allocator.5"*
  %20 = bitcast %"class.std::vector.3"* %6 to %"struct.std::_Vector_base.4"*
  %21 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %20, i32 0, i32 0
  %22 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %21, i32 0, i32 1
  %23 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %22, align 8
  %24 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  call void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator.5"* dereferenceable(1) %19, %class.NVariableDeclaration** %23, %class.NVariableDeclaration** dereferenceable(8) %24)
  %25 = bitcast %"class.std::vector.3"* %6 to %"struct.std::_Vector_base.4"*
  %26 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %25, i32 0, i32 0
  %27 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %26, i32 0, i32 1
  %28 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %27, align 8
  %29 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %28, i32 1
  store %class.NVariableDeclaration** %29, %class.NVariableDeclaration*** %27, align 8
  br label %36

; <label>:30:                                     ; preds = %2
  %31 = call %class.NVariableDeclaration** @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(%"class.std::vector.3"* %6) #3
  %32 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %31, %class.NVariableDeclaration*** %32, align 8
  %33 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %34 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %5, i32 0, i32 0
  %35 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %34, align 8
  call void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(%"class.std::vector.3"* %6, %class.NVariableDeclaration** %35, %class.NVariableDeclaration** dereferenceable(8) %33)
  br label %36

; <label>:36:                                     ; preds = %30, %16
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZN11NIdentifierC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(%class.NIdentifier*, %"class.std::__cxx11::basic_string"* dereferenceable(32)) unnamed_addr #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %3 = alloca %class.NIdentifier*, align 8
  %4 = alloca %"class.std::__cxx11::basic_string"*, align 8
  %5 = alloca i8*
  %6 = alloca i32
  store %class.NIdentifier* %0, %class.NIdentifier** %3, align 8
  store %"class.std::__cxx11::basic_string"* %1, %"class.std::__cxx11::basic_string"** %4, align 8
  %7 = load %class.NIdentifier*, %class.NIdentifier** %3, align 8
  %8 = bitcast %class.NIdentifier* %7 to %class.NExpression*
  call void @_ZN11NExpressionC2Ev(%class.NExpression* %8) #3
  %9 = bitcast %class.NIdentifier* %7 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV11NIdentifier, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %9, align 8
  %10 = getelementptr inbounds %class.NIdentifier, %class.NIdentifier* %7, i32 0, i32 1
  %11 = load %"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"** %4, align 8
  invoke void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_(%"class.std::__cxx11::basic_string"* %10, %"class.std::__cxx11::basic_string"* dereferenceable(32) %11)
          to label %12 unwind label %13

; <label>:12:                                     ; preds = %2
  ret void

; <label>:13:                                     ; preds = %2
  %14 = landingpad { i8*, i32 }
          cleanup
  %15 = extractvalue { i8*, i32 } %14, 0
  store i8* %15, i8** %5, align 8
  %16 = extractvalue { i8*, i32 } %14, 1
  store i32 %16, i32* %6, align 4
  %17 = bitcast %class.NIdentifier* %7 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %17) #3
  br label %18

; <label>:18:                                     ; preds = %13
  %19 = load i8*, i8** %5, align 8
  %20 = load i32, i32* %6, align 4
  %21 = insertvalue { i8*, i32 } undef, i8* %19, 0
  %22 = insertvalue { i8*, i32 } %21, i32 %20, 1
  resume { i8*, i32 } %22
}

; Function Attrs: nounwind
declare dso_local void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(%"class.std::__cxx11::basic_string"*) unnamed_addr #2

; Function Attrs: nounwind
declare dso_local i8* @_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv(%"class.std::__cxx11::basic_string"*) #2

; Function Attrs: nounwind
declare dso_local void @_ZNSaIcEC1Ev(%"class.std::allocator.0"*) unnamed_addr #2

declare dso_local void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_(%"class.std::__cxx11::basic_string"*, i8*, %"class.std::allocator.0"* dereferenceable(1)) unnamed_addr #1

; Function Attrs: nounwind
declare dso_local void @_ZNSaIcED1Ev(%"class.std::allocator.0"*) unnamed_addr #2

; Function Attrs: nounwind readonly
declare dso_local double @atof(i8*) #9

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN7NDoubleC2Ed(%class.NDouble*, double) unnamed_addr #7 comdat align 2 {
  %3 = alloca %class.NDouble*, align 8
  %4 = alloca double, align 8
  store %class.NDouble* %0, %class.NDouble** %3, align 8
  store double %1, double* %4, align 8
  %5 = load %class.NDouble*, %class.NDouble** %3, align 8
  %6 = bitcast %class.NDouble* %5 to %class.NExpression*
  call void @_ZN11NExpressionC2Ev(%class.NExpression* %6) #3
  %7 = bitcast %class.NDouble* %5 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV7NDouble, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %7, align 8
  %8 = getelementptr inbounds %class.NDouble, %class.NDouble* %5, i32 0, i32 1
  %9 = load double, double* %4, align 8
  store double %9, double* %8, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NAssignmentC2ER11NIdentifierR11NExpression(%class.NAssignment*, %class.NIdentifier* dereferenceable(40), %class.NExpression* dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %4 = alloca %class.NAssignment*, align 8
  %5 = alloca %class.NIdentifier*, align 8
  %6 = alloca %class.NExpression*, align 8
  store %class.NAssignment* %0, %class.NAssignment** %4, align 8
  store %class.NIdentifier* %1, %class.NIdentifier** %5, align 8
  store %class.NExpression* %2, %class.NExpression** %6, align 8
  %7 = load %class.NAssignment*, %class.NAssignment** %4, align 8
  %8 = bitcast %class.NAssignment* %7 to %class.NExpression*
  call void @_ZN11NExpressionC2Ev(%class.NExpression* %8) #3
  %9 = bitcast %class.NAssignment* %7 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV11NAssignment, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %9, align 8
  %10 = getelementptr inbounds %class.NAssignment, %class.NAssignment* %7, i32 0, i32 1
  %11 = load %class.NIdentifier*, %class.NIdentifier** %5, align 8
  store %class.NIdentifier* %11, %class.NIdentifier** %10, align 8
  %12 = getelementptr inbounds %class.NAssignment, %class.NAssignment* %7, i32 0, i32 2
  %13 = load %class.NExpression*, %class.NExpression** %6, align 8
  store %class.NExpression* %13, %class.NExpression** %12, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZN11NMethodCallC2ERK11NIdentifierRSt6vectorIP11NExpressionSaIS5_EE(%class.NMethodCall*, %class.NIdentifier* dereferenceable(40), %"class.std::vector.8"* dereferenceable(24)) unnamed_addr #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %4 = alloca %class.NMethodCall*, align 8
  %5 = alloca %class.NIdentifier*, align 8
  %6 = alloca %"class.std::vector.8"*, align 8
  %7 = alloca i8*
  %8 = alloca i32
  store %class.NMethodCall* %0, %class.NMethodCall** %4, align 8
  store %class.NIdentifier* %1, %class.NIdentifier** %5, align 8
  store %"class.std::vector.8"* %2, %"class.std::vector.8"** %6, align 8
  %9 = load %class.NMethodCall*, %class.NMethodCall** %4, align 8
  %10 = bitcast %class.NMethodCall* %9 to %class.NExpression*
  call void @_ZN11NExpressionC2Ev(%class.NExpression* %10) #3
  %11 = bitcast %class.NMethodCall* %9 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV11NMethodCall, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %11, align 8
  %12 = getelementptr inbounds %class.NMethodCall, %class.NMethodCall* %9, i32 0, i32 1
  %13 = load %class.NIdentifier*, %class.NIdentifier** %5, align 8
  store %class.NIdentifier* %13, %class.NIdentifier** %12, align 8
  %14 = getelementptr inbounds %class.NMethodCall, %class.NMethodCall* %9, i32 0, i32 2
  %15 = load %"class.std::vector.8"*, %"class.std::vector.8"** %6, align 8
  invoke void @_ZNSt6vectorIP11NExpressionSaIS1_EEC2ERKS3_(%"class.std::vector.8"* %14, %"class.std::vector.8"* dereferenceable(24) %15)
          to label %16 unwind label %17

; <label>:16:                                     ; preds = %3
  ret void

; <label>:17:                                     ; preds = %3
  %18 = landingpad { i8*, i32 }
          cleanup
  %19 = extractvalue { i8*, i32 } %18, 0
  store i8* %19, i8** %7, align 8
  %20 = extractvalue { i8*, i32 } %18, 1
  store i32 %20, i32* %8, align 4
  %21 = bitcast %class.NMethodCall* %9 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %21) #3
  br label %22

; <label>:22:                                     ; preds = %17
  %23 = load i8*, i8** %7, align 8
  %24 = load i32, i32* %8, align 4
  %25 = insertvalue { i8*, i32 } undef, i8* %23, 0
  %26 = insertvalue { i8*, i32 } %25, i32 %24, 1
  resume { i8*, i32 } %26
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP11NExpressionSaIS1_EED2Ev(%"class.std::vector.8"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"class.std::vector.8"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %2, align 8
  %5 = load %"class.std::vector.8"*, %"class.std::vector.8"** %2, align 8
  %6 = bitcast %"class.std::vector.8"* %5 to %"struct.std::_Vector_base.9"*
  %7 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %6, i32 0, i32 0
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %7, i32 0, i32 0
  %9 = load %class.NExpression**, %class.NExpression*** %8, align 8
  %10 = bitcast %"class.std::vector.8"* %5 to %"struct.std::_Vector_base.9"*
  %11 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %10, i32 0, i32 0
  %12 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %11, i32 0, i32 1
  %13 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %14 = bitcast %"class.std::vector.8"* %5 to %"struct.std::_Vector_base.9"*
  %15 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %14) #3
  invoke void @_ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(%class.NExpression** %9, %class.NExpression** %13, %"class.std::allocator.10"* dereferenceable(1) %15)
          to label %16 unwind label %18

; <label>:16:                                     ; preds = %1
  %17 = bitcast %"class.std::vector.8"* %5 to %"struct.std::_Vector_base.9"*
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev(%"struct.std::_Vector_base.9"* %17) #3
  ret void

; <label>:18:                                     ; preds = %1
  %19 = landingpad { i8*, i32 }
          catch i8* null
  %20 = extractvalue { i8*, i32 } %19, 0
  store i8* %20, i8** %3, align 8
  %21 = extractvalue { i8*, i32 } %19, 1
  store i32 %21, i32* %4, align 4
  %22 = bitcast %"class.std::vector.8"* %5 to %"struct.std::_Vector_base.9"*
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev(%"struct.std::_Vector_base.9"* %22) #3
  br label %23

; <label>:23:                                     ; preds = %18
  %24 = load i8*, i8** %3, align 8
  call void @__clang_call_terminate(i8* %24) #10
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN15NBinaryOperatorC2ER11NExpressioniS1_(%class.NBinaryOperator*, %class.NExpression* dereferenceable(8), i32, %class.NExpression* dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %5 = alloca %class.NBinaryOperator*, align 8
  %6 = alloca %class.NExpression*, align 8
  %7 = alloca i32, align 4
  %8 = alloca %class.NExpression*, align 8
  store %class.NBinaryOperator* %0, %class.NBinaryOperator** %5, align 8
  store %class.NExpression* %1, %class.NExpression** %6, align 8
  store i32 %2, i32* %7, align 4
  store %class.NExpression* %3, %class.NExpression** %8, align 8
  %9 = load %class.NBinaryOperator*, %class.NBinaryOperator** %5, align 8
  %10 = bitcast %class.NBinaryOperator* %9 to %class.NExpression*
  call void @_ZN11NExpressionC2Ev(%class.NExpression* %10) #3
  %11 = bitcast %class.NBinaryOperator* %9 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV15NBinaryOperator, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %11, align 8
  %12 = getelementptr inbounds %class.NBinaryOperator, %class.NBinaryOperator* %9, i32 0, i32 1
  %13 = load i32, i32* %7, align 4
  store i32 %13, i32* %12, align 8
  %14 = getelementptr inbounds %class.NBinaryOperator, %class.NBinaryOperator* %9, i32 0, i32 2
  %15 = load %class.NExpression*, %class.NExpression** %6, align 8
  store %class.NExpression* %15, %class.NExpression** %14, align 8
  %16 = getelementptr inbounds %class.NBinaryOperator, %class.NBinaryOperator* %9, i32 0, i32 3
  %17 = load %class.NExpression*, %class.NExpression** %8, align 8
  store %class.NExpression* %17, %class.NExpression** %16, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP11NExpressionSaIS1_EEC2Ev(%"class.std::vector.8"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"class.std::vector.8"*, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %2, align 8
  %3 = load %"class.std::vector.8"*, %"class.std::vector.8"** %2, align 8
  %4 = bitcast %"class.std::vector.8"* %3 to %"struct.std::_Vector_base.9"*
  invoke void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2Ev(%"struct.std::_Vector_base.9"* %4)
          to label %5 unwind label %6

; <label>:5:                                      ; preds = %1
  ret void

; <label>:6:                                      ; preds = %1
  %7 = landingpad { i8*, i32 }
          catch i8* null
  %8 = extractvalue { i8*, i32 } %7, 0
  call void @__clang_call_terminate(i8* %8) #10
  unreachable
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP11NExpressionSaIS1_EE9push_backERKS1_(%"class.std::vector.8"*, %class.NExpression** dereferenceable(8)) #4 comdat align 2 {
  %3 = alloca %"class.std::vector.8"*, align 8
  %4 = alloca %class.NExpression**, align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.17", align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %3, align 8
  store %class.NExpression** %1, %class.NExpression*** %4, align 8
  %6 = load %"class.std::vector.8"*, %"class.std::vector.8"** %3, align 8
  %7 = bitcast %"class.std::vector.8"* %6 to %"struct.std::_Vector_base.9"*
  %8 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %7, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %8, i32 0, i32 1
  %10 = load %class.NExpression**, %class.NExpression*** %9, align 8
  %11 = bitcast %"class.std::vector.8"* %6 to %"struct.std::_Vector_base.9"*
  %12 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %11, i32 0, i32 0
  %13 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %12, i32 0, i32 2
  %14 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %15 = icmp ne %class.NExpression** %10, %14
  br i1 %15, label %16, label %30

; <label>:16:                                     ; preds = %2
  %17 = bitcast %"class.std::vector.8"* %6 to %"struct.std::_Vector_base.9"*
  %18 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %17, i32 0, i32 0
  %19 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %18 to %"class.std::allocator.10"*
  %20 = bitcast %"class.std::vector.8"* %6 to %"struct.std::_Vector_base.9"*
  %21 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %20, i32 0, i32 0
  %22 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %21, i32 0, i32 1
  %23 = load %class.NExpression**, %class.NExpression*** %22, align 8
  %24 = load %class.NExpression**, %class.NExpression*** %4, align 8
  call void @_ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator.10"* dereferenceable(1) %19, %class.NExpression** %23, %class.NExpression** dereferenceable(8) %24)
  %25 = bitcast %"class.std::vector.8"* %6 to %"struct.std::_Vector_base.9"*
  %26 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %25, i32 0, i32 0
  %27 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %26, i32 0, i32 1
  %28 = load %class.NExpression**, %class.NExpression*** %27, align 8
  %29 = getelementptr inbounds %class.NExpression*, %class.NExpression** %28, i32 1
  store %class.NExpression** %29, %class.NExpression*** %27, align 8
  br label %36

; <label>:30:                                     ; preds = %2
  %31 = call %class.NExpression** @_ZNSt6vectorIP11NExpressionSaIS1_EE3endEv(%"class.std::vector.8"* %6) #3
  %32 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %5, i32 0, i32 0
  store %class.NExpression** %31, %class.NExpression*** %32, align 8
  %33 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %34 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %5, i32 0, i32 0
  %35 = load %class.NExpression**, %class.NExpression*** %34, align 8
  call void @_ZNSt6vectorIP11NExpressionSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(%"class.std::vector.8"* %6, %class.NExpression** %35, %class.NExpression** dereferenceable(8) %33)
  br label %36

; <label>:36:                                     ; preds = %30, %16
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define internal void @_ZL10yydestructPKciP7YYSTYPE(i8*, i32, %union.YYSTYPE*) #7 {
  %4 = alloca i8*, align 8
  %5 = alloca i32, align 4
  %6 = alloca %union.YYSTYPE*, align 8
  store i8* %0, i8** %4, align 8
  store i32 %1, i32* %5, align 4
  store %union.YYSTYPE* %2, %union.YYSTYPE** %6, align 8
  %7 = load i8*, i8** %4, align 8
  %8 = icmp ne i8* %7, null
  br i1 %8, label %10, label %9

; <label>:9:                                      ; preds = %3
  store i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str.7, i32 0, i32 0), i8** %4, align 8
  br label %10

; <label>:10:                                     ; preds = %9, %3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NExpressionC2Ev(%class.NExpression*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NExpression*, align 8
  store %class.NExpression* %0, %class.NExpression** %2, align 8
  %3 = load %class.NExpression*, %class.NExpression** %2, align 8
  %4 = bitcast %class.NExpression* %3 to %class.Node*
  call void @_ZN4NodeC2Ev(%class.Node* %4) #3
  %5 = bitcast %class.NExpression* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV11NExpression, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %5, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP10NStatementSaIS1_EEC2Ev(%"class.std::vector"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %2, align 8
  %3 = load %"class.std::vector"*, %"class.std::vector"** %2, align 8
  %4 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  invoke void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EEC2Ev(%"struct.std::_Vector_base"* %4)
          to label %5 unwind label %6

; <label>:5:                                      ; preds = %1
  ret void

; <label>:6:                                      ; preds = %1
  %7 = landingpad { i8*, i32 }
          catch i8* null
  %8 = extractvalue { i8*, i32 } %7, 0
  call void @__clang_call_terminate(i8* %8) #10
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN6NBlockD2Ev(%class.NBlock*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NBlock*, align 8
  store %class.NBlock* %0, %class.NBlock** %2, align 8
  %3 = load %class.NBlock*, %class.NBlock** %2, align 8
  %4 = bitcast %class.NBlock* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV6NBlock, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %4, align 8
  %5 = getelementptr inbounds %class.NBlock, %class.NBlock* %3, i32 0, i32 1
  call void @_ZNSt6vectorIP10NStatementSaIS1_EED2Ev(%"class.std::vector"* %5) #3
  %6 = bitcast %class.NBlock* %3 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %6) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN6NBlockD0Ev(%class.NBlock*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NBlock*, align 8
  store %class.NBlock* %0, %class.NBlock** %2, align 8
  %3 = load %class.NBlock*, %class.NBlock** %2, align 8
  call void @_ZN6NBlockD2Ev(%class.NBlock* %3) #3
  %4 = bitcast %class.NBlock* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN6NBlock7codeGenER14CodeGenContext(%class.NBlock*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NBlock*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NBlock* %0, %class.NBlock** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NBlock*, %class.NBlock** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN4NodeC2Ev(%class.Node*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.Node*, align 8
  store %class.Node* %0, %class.Node** %2, align 8
  %3 = load %class.Node*, %class.Node** %2, align 8
  %4 = bitcast %class.Node* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV4Node, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %4, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NExpressionD2Ev(%class.NExpression*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NExpression*, align 8
  store %class.NExpression* %0, %class.NExpression** %2, align 8
  %3 = load %class.NExpression*, %class.NExpression** %2, align 8
  %4 = bitcast %class.NExpression* %3 to %class.Node*
  call void @_ZN4NodeD2Ev(%class.Node* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NExpressionD0Ev(%class.NExpression*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NExpression*, align 8
  store %class.NExpression* %0, %class.NExpression** %2, align 8
  %3 = load %class.NExpression*, %class.NExpression** %2, align 8
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %3) #3
  %4 = bitcast %class.NExpression* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN4Node7codeGenER14CodeGenContext(%class.Node*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.Node*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.Node* %0, %class.Node** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.Node*, %class.Node** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN4NodeD2Ev(%class.Node*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.Node*, align 8
  store %class.Node* %0, %class.Node** %2, align 8
  %3 = load %class.Node*, %class.Node** %2, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN4NodeD0Ev(%class.Node*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.Node*, align 8
  store %class.Node* %0, %class.Node** %2, align 8
  %3 = load %class.Node*, %class.Node** %2, align 8
  call void @_ZN4NodeD2Ev(%class.Node* %3) #3
  %4 = bitcast %class.Node* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #10

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EEC2Ev(%"struct.std::_Vector_base"*) unnamed_addr #4 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %0, %"struct.std::_Vector_base"** %2, align 8
  %3 = load %"struct.std::_Vector_base"*, %"struct.std::_Vector_base"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %3, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %4)
  ret void
}

; Function Attrs: noinline noreturn nounwind
define linkonce_odr hidden void @__clang_call_terminate(i8*) #11 comdat {
  %2 = call i8* @__cxa_begin_catch(i8* %0) #3
  call void @_ZSt9terminatev() #10
  unreachable
}

declare dso_local i8* @__cxa_begin_catch(i8*)

declare dso_local void @_ZSt9terminatev()

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"** %2, align 8
  %3 = load %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"*, %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"** %2, align 8
  %4 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %3 to %"class.std::allocator"*
  call void @_ZNSaIP10NStatementEC2Ev(%"class.std::allocator"* %4) #3
  %5 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %3, i32 0, i32 0
  store %class.NStatement** null, %class.NStatement*** %5, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %3, i32 0, i32 1
  store %class.NStatement** null, %class.NStatement*** %6, align 8
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %3, i32 0, i32 2
  store %class.NStatement** null, %class.NStatement*** %7, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP10NStatementEC2Ev(%"class.std::allocator"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.std::allocator"*, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %2, align 8
  %3 = load %"class.std::allocator"*, %"class.std::allocator"** %2, align 8
  %4 = bitcast %"class.std::allocator"* %3 to %"class.__gnu_cxx::new_allocator"*
  call void @_ZN9__gnu_cxx13new_allocatorIP10NStatementEC2Ev(%"class.__gnu_cxx::new_allocator"* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP10NStatementEC2Ev(%"class.__gnu_cxx::new_allocator"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  store %"class.__gnu_cxx::new_allocator"* %0, %"class.__gnu_cxx::new_allocator"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator"*, %"class.__gnu_cxx::new_allocator"** %2, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP10NStatementSaIS1_EED2Ev(%"class.std::vector"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"class.std::vector"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"class.std::vector"* %0, %"class.std::vector"** %2, align 8
  %5 = load %"class.std::vector"*, %"class.std::vector"** %2, align 8
  %6 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %7 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %6, i32 0, i32 0
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %7, i32 0, i32 0
  %9 = load %class.NStatement**, %class.NStatement*** %8, align 8
  %10 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %11 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %10, i32 0, i32 0
  %12 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %11, i32 0, i32 1
  %13 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %14 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %15 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %14) #3
  invoke void @_ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(%class.NStatement** %9, %class.NStatement** %13, %"class.std::allocator"* dereferenceable(1) %15)
          to label %16 unwind label %18

; <label>:16:                                     ; preds = %1
  %17 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  call void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EED2Ev(%"struct.std::_Vector_base"* %17) #3
  ret void

; <label>:18:                                     ; preds = %1
  %19 = landingpad { i8*, i32 }
          catch i8* null
  %20 = extractvalue { i8*, i32 } %19, 0
  store i8* %20, i8** %3, align 8
  %21 = extractvalue { i8*, i32 } %19, 1
  store i32 %21, i32* %4, align 4
  %22 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  call void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EED2Ev(%"struct.std::_Vector_base"* %22) #3
  br label %23

; <label>:23:                                     ; preds = %18
  %24 = load i8*, i8** %3, align 8
  call void @__clang_call_terminate(i8* %24) #10
  unreachable
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(%class.NStatement**, %class.NStatement**, %"class.std::allocator"* dereferenceable(1)) #4 comdat {
  %4 = alloca %class.NStatement**, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca %"class.std::allocator"*, align 8
  store %class.NStatement** %0, %class.NStatement*** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store %"class.std::allocator"* %2, %"class.std::allocator"** %6, align 8
  %7 = load %class.NStatement**, %class.NStatement*** %4, align 8
  %8 = load %class.NStatement**, %class.NStatement*** %5, align 8
  call void @_ZSt8_DestroyIPP10NStatementEvT_S3_(%class.NStatement** %7, %class.NStatement** %8)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"*) #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %0, %"struct.std::_Vector_base"** %2, align 8
  %3 = load %"struct.std::_Vector_base"*, %"struct.std::_Vector_base"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %3, i32 0, i32 0
  %5 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %4 to %"class.std::allocator"*
  ret %"class.std::allocator"* %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EED2Ev(%"struct.std::_Vector_base"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"struct.std::_Vector_base"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"struct.std::_Vector_base"* %0, %"struct.std::_Vector_base"** %2, align 8
  %5 = load %"struct.std::_Vector_base"*, %"struct.std::_Vector_base"** %2, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %6, i32 0, i32 0
  %8 = load %class.NStatement**, %class.NStatement*** %7, align 8
  %9 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %9, i32 0, i32 2
  %11 = load %class.NStatement**, %class.NStatement*** %10, align 8
  %12 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %13 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %12, i32 0, i32 0
  %14 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %15 = ptrtoint %class.NStatement** %11 to i64
  %16 = ptrtoint %class.NStatement** %14 to i64
  %17 = sub i64 %15, %16
  %18 = sdiv exact i64 %17, 8
  invoke void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"* %5, %class.NStatement** %8, i64 %18)
          to label %19 unwind label %21

; <label>:19:                                     ; preds = %1
  %20 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %20) #3
  ret void

; <label>:21:                                     ; preds = %1
  %22 = landingpad { i8*, i32 }
          catch i8* null
  %23 = extractvalue { i8*, i32 } %22, 0
  store i8* %23, i8** %3, align 8
  %24 = extractvalue { i8*, i32 } %22, 1
  store i32 %24, i32* %4, align 4
  %25 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %25) #3
  br label %26

; <label>:26:                                     ; preds = %21
  %27 = load i8*, i8** %3, align 8
  call void @__clang_call_terminate(i8* %27) #10
  unreachable
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZSt8_DestroyIPP10NStatementEvT_S3_(%class.NStatement**, %class.NStatement**) #4 comdat {
  %3 = alloca %class.NStatement**, align 8
  %4 = alloca %class.NStatement**, align 8
  store %class.NStatement** %0, %class.NStatement*** %3, align 8
  store %class.NStatement** %1, %class.NStatement*** %4, align 8
  %5 = load %class.NStatement**, %class.NStatement*** %3, align 8
  %6 = load %class.NStatement**, %class.NStatement*** %4, align 8
  call void @_ZNSt12_Destroy_auxILb1EE9__destroyIPP10NStatementEEvT_S5_(%class.NStatement** %5, %class.NStatement** %6)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Destroy_auxILb1EE9__destroyIPP10NStatementEEvT_S5_(%class.NStatement**, %class.NStatement**) #7 comdat align 2 {
  %3 = alloca %class.NStatement**, align 8
  %4 = alloca %class.NStatement**, align 8
  store %class.NStatement** %0, %class.NStatement*** %3, align 8
  store %class.NStatement** %1, %class.NStatement*** %4, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"*, %class.NStatement**, i64) #4 comdat align 2 {
  %4 = alloca %"struct.std::_Vector_base"*, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca i64, align 8
  store %"struct.std::_Vector_base"* %0, %"struct.std::_Vector_base"** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"struct.std::_Vector_base"*, %"struct.std::_Vector_base"** %4, align 8
  %8 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %9 = icmp ne %class.NStatement** %8, null
  br i1 %9, label %10, label %15

; <label>:10:                                     ; preds = %3
  %11 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %7, i32 0, i32 0
  %12 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %11 to %"class.std::allocator"*
  %13 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %14 = load i64, i64* %6, align 8
  call void @_ZNSt16allocator_traitsISaIP10NStatementEE10deallocateERS2_PS1_m(%"class.std::allocator"* dereferenceable(1) %12, %class.NStatement** %13, i64 %14)
  br label %15

; <label>:15:                                     ; preds = %10, %3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"** %2, align 8
  %3 = load %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"*, %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"** %2, align 8
  %4 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %3 to %"class.std::allocator"*
  call void @_ZNSaIP10NStatementED2Ev(%"class.std::allocator"* %4) #3
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP10NStatementEE10deallocateERS2_PS1_m(%"class.std::allocator"* dereferenceable(1), %class.NStatement**, i64) #4 comdat align 2 {
  %4 = alloca %"class.std::allocator"*, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca i64, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"class.std::allocator"*, %"class.std::allocator"** %4, align 8
  %8 = bitcast %"class.std::allocator"* %7 to %"class.__gnu_cxx::new_allocator"*
  %9 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %10 = load i64, i64* %6, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIP10NStatementE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator"* %8, %class.NStatement** %9, i64 %10)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP10NStatementE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator"*, %class.NStatement**, i64) #7 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca i64, align 8
  store %"class.__gnu_cxx::new_allocator"* %0, %"class.__gnu_cxx::new_allocator"** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator"*, %"class.__gnu_cxx::new_allocator"** %4, align 8
  %8 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %9 = bitcast %class.NStatement** %8 to i8*
  call void @_ZdlPv(i8* %9) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP10NStatementED2Ev(%"class.std::allocator"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.std::allocator"*, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %2, align 8
  %3 = load %"class.std::allocator"*, %"class.std::allocator"** %2, align 8
  %4 = bitcast %"class.std::allocator"* %3 to %"class.__gnu_cxx::new_allocator"*
  call void @_ZN9__gnu_cxx13new_allocatorIP10NStatementED2Ev(%"class.__gnu_cxx::new_allocator"* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP10NStatementED2Ev(%"class.__gnu_cxx::new_allocator"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  store %"class.__gnu_cxx::new_allocator"* %0, %"class.__gnu_cxx::new_allocator"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator"*, %"class.__gnu_cxx::new_allocator"** %2, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN10NStatementC2Ev(%class.NStatement*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NStatement*, align 8
  store %class.NStatement* %0, %class.NStatement** %2, align 8
  %3 = load %class.NStatement*, %class.NStatement** %2, align 8
  %4 = bitcast %class.NStatement* %3 to %class.Node*
  call void @_ZN4NodeC2Ev(%class.Node* %4) #3
  %5 = bitcast %class.NStatement* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV10NStatement, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %5, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NExpressionStatementD2Ev(%class.NExpressionStatement*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NExpressionStatement*, align 8
  store %class.NExpressionStatement* %0, %class.NExpressionStatement** %2, align 8
  %3 = load %class.NExpressionStatement*, %class.NExpressionStatement** %2, align 8
  %4 = bitcast %class.NExpressionStatement* %3 to %class.NStatement*
  call void @_ZN10NStatementD2Ev(%class.NStatement* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NExpressionStatementD0Ev(%class.NExpressionStatement*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NExpressionStatement*, align 8
  store %class.NExpressionStatement* %0, %class.NExpressionStatement** %2, align 8
  %3 = load %class.NExpressionStatement*, %class.NExpressionStatement** %2, align 8
  call void @_ZN20NExpressionStatementD2Ev(%class.NExpressionStatement* %3) #3
  %4 = bitcast %class.NExpressionStatement* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN20NExpressionStatement7codeGenER14CodeGenContext(%class.NExpressionStatement*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NExpressionStatement*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NExpressionStatement* %0, %class.NExpressionStatement** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NExpressionStatement*, %class.NExpressionStatement** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN10NStatementD2Ev(%class.NStatement*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NStatement*, align 8
  store %class.NStatement* %0, %class.NStatement** %2, align 8
  %3 = load %class.NStatement*, %class.NStatement** %2, align 8
  %4 = bitcast %class.NStatement* %3 to %class.Node*
  call void @_ZN4NodeD2Ev(%class.Node* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN10NStatementD0Ev(%class.NStatement*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NStatement*, align 8
  store %class.NStatement* %0, %class.NStatement** %2, align 8
  %3 = load %class.NStatement*, %class.NStatement** %2, align 8
  call void @_ZN10NStatementD2Ev(%class.NStatement* %3) #3
  %4 = bitcast %class.NStatement* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NVariableDeclarationD2Ev(%class.NVariableDeclaration*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NVariableDeclaration*, align 8
  store %class.NVariableDeclaration* %0, %class.NVariableDeclaration** %2, align 8
  %3 = load %class.NVariableDeclaration*, %class.NVariableDeclaration** %2, align 8
  %4 = bitcast %class.NVariableDeclaration* %3 to %class.NStatement*
  call void @_ZN10NStatementD2Ev(%class.NStatement* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NVariableDeclarationD0Ev(%class.NVariableDeclaration*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NVariableDeclaration*, align 8
  store %class.NVariableDeclaration* %0, %class.NVariableDeclaration** %2, align 8
  %3 = load %class.NVariableDeclaration*, %class.NVariableDeclaration** %2, align 8
  call void @_ZN20NVariableDeclarationD2Ev(%class.NVariableDeclaration* %3) #3
  %4 = bitcast %class.NVariableDeclaration* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN20NVariableDeclaration7codeGenER14CodeGenContext(%class.NVariableDeclaration*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NVariableDeclaration*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NVariableDeclaration* %0, %class.NVariableDeclaration** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NVariableDeclaration*, %class.NVariableDeclaration** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EEC2ERKS3_(%"class.std::vector.3"*, %"class.std::vector.3"* dereferenceable(24)) unnamed_addr #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %3 = alloca %"class.std::vector.3"*, align 8
  %4 = alloca %"class.std::vector.3"*, align 8
  %5 = alloca %"class.std::allocator.5", align 1
  %6 = alloca i8*
  %7 = alloca i32
  %8 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %3, align 8
  store %"class.std::vector.3"* %1, %"class.std::vector.3"** %4, align 8
  %10 = load %"class.std::vector.3"*, %"class.std::vector.3"** %3, align 8
  %11 = bitcast %"class.std::vector.3"* %10 to %"struct.std::_Vector_base.4"*
  %12 = load %"class.std::vector.3"*, %"class.std::vector.3"** %4, align 8
  %13 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(%"class.std::vector.3"* %12) #3
  %14 = load %"class.std::vector.3"*, %"class.std::vector.3"** %4, align 8
  %15 = bitcast %"class.std::vector.3"* %14 to %"struct.std::_Vector_base.4"*
  %16 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %15) #3
  call void @_ZN9__gnu_cxx14__alloc_traitsISaIP20NVariableDeclarationES2_E17_S_select_on_copyERKS3_(%"class.std::allocator.5"* sret %5, %"class.std::allocator.5"* dereferenceable(1) %16)
  invoke void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2EmRKS2_(%"struct.std::_Vector_base.4"* %11, i64 %13, %"class.std::allocator.5"* dereferenceable(1) %5)
          to label %17 unwind label %39

; <label>:17:                                     ; preds = %2
  call void @_ZNSaIP20NVariableDeclarationED2Ev(%"class.std::allocator.5"* %5) #3
  %18 = load %"class.std::vector.3"*, %"class.std::vector.3"** %4, align 8
  %19 = call %class.NVariableDeclaration** @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(%"class.std::vector.3"* %18) #3
  %20 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %8, i32 0, i32 0
  store %class.NVariableDeclaration** %19, %class.NVariableDeclaration*** %20, align 8
  %21 = load %"class.std::vector.3"*, %"class.std::vector.3"** %4, align 8
  %22 = call %class.NVariableDeclaration** @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(%"class.std::vector.3"* %21) #3
  %23 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %9, i32 0, i32 0
  store %class.NVariableDeclaration** %22, %class.NVariableDeclaration*** %23, align 8
  %24 = bitcast %"class.std::vector.3"* %10 to %"struct.std::_Vector_base.4"*
  %25 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %24, i32 0, i32 0
  %26 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %25, i32 0, i32 0
  %27 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %26, align 8
  %28 = bitcast %"class.std::vector.3"* %10 to %"struct.std::_Vector_base.4"*
  %29 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %28) #3
  %30 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %8, i32 0, i32 0
  %31 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %30, align 8
  %32 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %9, i32 0, i32 0
  %33 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %32, align 8
  %34 = invoke %class.NVariableDeclaration** @_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(%class.NVariableDeclaration** %31, %class.NVariableDeclaration** %33, %class.NVariableDeclaration** %27, %"class.std::allocator.5"* dereferenceable(1) %29)
          to label %35 unwind label %43

; <label>:35:                                     ; preds = %17
  %36 = bitcast %"class.std::vector.3"* %10 to %"struct.std::_Vector_base.4"*
  %37 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %36, i32 0, i32 0
  %38 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %37, i32 0, i32 1
  store %class.NVariableDeclaration** %34, %class.NVariableDeclaration*** %38, align 8
  ret void

; <label>:39:                                     ; preds = %2
  %40 = landingpad { i8*, i32 }
          cleanup
  %41 = extractvalue { i8*, i32 } %40, 0
  store i8* %41, i8** %6, align 8
  %42 = extractvalue { i8*, i32 } %40, 1
  store i32 %42, i32* %7, align 4
  call void @_ZNSaIP20NVariableDeclarationED2Ev(%"class.std::allocator.5"* %5) #3
  br label %48

; <label>:43:                                     ; preds = %17
  %44 = landingpad { i8*, i32 }
          cleanup
  %45 = extractvalue { i8*, i32 } %44, 0
  store i8* %45, i8** %6, align 8
  %46 = extractvalue { i8*, i32 } %44, 1
  store i32 %46, i32* %7, align 4
  %47 = bitcast %"class.std::vector.3"* %10 to %"struct.std::_Vector_base.4"*
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev(%"struct.std::_Vector_base.4"* %47) #3
  br label %48

; <label>:48:                                     ; preds = %43, %39
  %49 = load i8*, i8** %6, align 8
  %50 = load i32, i32* %7, align 4
  %51 = insertvalue { i8*, i32 } undef, i8* %49, 0
  %52 = insertvalue { i8*, i32 } %51, i32 %50, 1
  resume { i8*, i32 } %52
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NFunctionDeclarationD2Ev(%class.NFunctionDeclaration*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NFunctionDeclaration*, align 8
  store %class.NFunctionDeclaration* %0, %class.NFunctionDeclaration** %2, align 8
  %3 = load %class.NFunctionDeclaration*, %class.NFunctionDeclaration** %2, align 8
  %4 = bitcast %class.NFunctionDeclaration* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV20NFunctionDeclaration, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %4, align 8
  %5 = getelementptr inbounds %class.NFunctionDeclaration, %class.NFunctionDeclaration* %3, i32 0, i32 3
  call void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EED2Ev(%"class.std::vector.3"* %5) #3
  %6 = bitcast %class.NFunctionDeclaration* %3 to %class.NStatement*
  call void @_ZN10NStatementD2Ev(%class.NStatement* %6) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN20NFunctionDeclarationD0Ev(%class.NFunctionDeclaration*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NFunctionDeclaration*, align 8
  store %class.NFunctionDeclaration* %0, %class.NFunctionDeclaration** %2, align 8
  %3 = load %class.NFunctionDeclaration*, %class.NFunctionDeclaration** %2, align 8
  call void @_ZN20NFunctionDeclarationD2Ev(%class.NFunctionDeclaration* %3) #3
  %4 = bitcast %class.NFunctionDeclaration* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN20NFunctionDeclaration7codeGenER14CodeGenContext(%class.NFunctionDeclaration*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NFunctionDeclaration*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NFunctionDeclaration* %0, %class.NFunctionDeclaration** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NFunctionDeclaration*, %class.NFunctionDeclaration** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(%"class.std::vector.3"*) #7 comdat align 2 {
  %2 = alloca %"class.std::vector.3"*, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %2, align 8
  %3 = load %"class.std::vector.3"*, %"class.std::vector.3"** %2, align 8
  %4 = bitcast %"class.std::vector.3"* %3 to %"struct.std::_Vector_base.4"*
  %5 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %5, i32 0, i32 1
  %7 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %8 = bitcast %"class.std::vector.3"* %3 to %"struct.std::_Vector_base.4"*
  %9 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %8, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %9, i32 0, i32 0
  %11 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %10, align 8
  %12 = ptrtoint %class.NVariableDeclaration** %7 to i64
  %13 = ptrtoint %class.NVariableDeclaration** %11 to i64
  %14 = sub i64 %12, %13
  %15 = sdiv exact i64 %14, 8
  ret i64 %15
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx14__alloc_traitsISaIP20NVariableDeclarationES2_E17_S_select_on_copyERKS3_(%"class.std::allocator.5"* noalias sret, %"class.std::allocator.5"* dereferenceable(1)) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator.5"*, align 8
  store %"class.std::allocator.5"* %1, %"class.std::allocator.5"** %3, align 8
  %4 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %3, align 8
  call void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE37select_on_container_copy_constructionERKS2_(%"class.std::allocator.5"* sret %0, %"class.std::allocator.5"* dereferenceable(1) %4)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(1) %"class.std::allocator.5"* @_ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"*) #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base.4"*, align 8
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %2, align 8
  %3 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %3, i32 0, i32 0
  %5 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %4 to %"class.std::allocator.5"*
  ret %"class.std::allocator.5"* %5
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2EmRKS2_(%"struct.std::_Vector_base.4"*, i64, %"class.std::allocator.5"* dereferenceable(1)) unnamed_addr #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %4 = alloca %"struct.std::_Vector_base.4"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca %"class.std::allocator.5"*, align 8
  %7 = alloca i8*
  %8 = alloca i32
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %4, align 8
  store i64 %1, i64* %5, align 8
  store %"class.std::allocator.5"* %2, %"class.std::allocator.5"** %6, align 8
  %9 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %4, align 8
  %10 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %9, i32 0, i32 0
  %11 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %6, align 8
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2ERKS2_(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %10, %"class.std::allocator.5"* dereferenceable(1) %11) #3
  %12 = load i64, i64* %5, align 8
  invoke void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE17_M_create_storageEm(%"struct.std::_Vector_base.4"* %9, i64 %12)
          to label %13 unwind label %14

; <label>:13:                                     ; preds = %3
  ret void

; <label>:14:                                     ; preds = %3
  %15 = landingpad { i8*, i32 }
          cleanup
  %16 = extractvalue { i8*, i32 } %15, 0
  store i8* %16, i8** %7, align 8
  %17 = extractvalue { i8*, i32 } %15, 1
  store i32 %17, i32* %8, align 4
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %10) #3
  br label %18

; <label>:18:                                     ; preds = %14
  %19 = load i8*, i8** %7, align 8
  %20 = load i32, i32* %8, align 4
  %21 = insertvalue { i8*, i32 } undef, i8* %19, 0
  %22 = insertvalue { i8*, i32 } %21, i32 %20, 1
  resume { i8*, i32 } %22
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP20NVariableDeclarationED2Ev(%"class.std::allocator.5"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.std::allocator.5"*, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %2, align 8
  %3 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %2, align 8
  %4 = bitcast %"class.std::allocator.5"* %3 to %"class.__gnu_cxx::new_allocator.6"*
  call void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationED2Ev(%"class.__gnu_cxx::new_allocator.6"* %4) #3
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**, %"class.std::allocator.5"* dereferenceable(1)) #4 comdat {
  %5 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %6 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %7 = alloca %class.NVariableDeclaration**, align 8
  %8 = alloca %"class.std::allocator.5"*, align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %10 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %11 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %11, align 8
  %12 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %6, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %12, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %7, align 8
  store %"class.std::allocator.5"* %3, %"class.std::allocator.5"** %8, align 8
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator"* %9 to i8*
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = bitcast %"class.__gnu_cxx::__normal_iterator"* %10 to i8*
  %16 = bitcast %"class.__gnu_cxx::__normal_iterator"* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %15, i8* align 8 %16, i64 8, i1 false)
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %7, align 8
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %9, i32 0, i32 0
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %18, align 8
  %20 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %10, i32 0, i32 0
  %21 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %20, align 8
  %22 = call %class.NVariableDeclaration** @_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NVariableDeclaration** %19, %class.NVariableDeclaration** %21, %class.NVariableDeclaration** %17)
  ret %class.NVariableDeclaration** %22
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(%"class.std::vector.3"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %3 = alloca %"class.std::vector.3"*, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %3, align 8
  %5 = load %"class.std::vector.3"*, %"class.std::vector.3"** %3, align 8
  %6 = bitcast %"class.std::vector.3"* %5 to %"struct.std::_Vector_base.4"*
  %7 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %6, i32 0, i32 0
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %7, i32 0, i32 0
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  store %class.NVariableDeclaration** %9, %class.NVariableDeclaration*** %4, align 8
  call void @_ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_(%"class.__gnu_cxx::__normal_iterator"* %2, %class.NVariableDeclaration*** dereferenceable(8) %4) #3
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %2, i32 0, i32 0
  %11 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %10, align 8
  ret %class.NVariableDeclaration** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(%"class.std::vector.3"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %3 = alloca %"class.std::vector.3"*, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %3, align 8
  %5 = load %"class.std::vector.3"*, %"class.std::vector.3"** %3, align 8
  %6 = bitcast %"class.std::vector.3"* %5 to %"struct.std::_Vector_base.4"*
  %7 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %6, i32 0, i32 0
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %7, i32 0, i32 1
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  store %class.NVariableDeclaration** %9, %class.NVariableDeclaration*** %4, align 8
  call void @_ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_(%"class.__gnu_cxx::__normal_iterator"* %2, %class.NVariableDeclaration*** dereferenceable(8) %4) #3
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %2, i32 0, i32 0
  %11 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %10, align 8
  ret %class.NVariableDeclaration** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(1) %"class.std::allocator.5"* @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"*) #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base.4"*, align 8
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %2, align 8
  %3 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %3, i32 0, i32 0
  %5 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %4 to %"class.std::allocator.5"*
  ret %"class.std::allocator.5"* %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EED2Ev(%"struct.std::_Vector_base.4"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"struct.std::_Vector_base.4"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %2, align 8
  %5 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %2, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %6, i32 0, i32 0
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %7, align 8
  %9 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %9, i32 0, i32 2
  %11 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %10, align 8
  %12 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %13 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %12, i32 0, i32 0
  %14 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %15 = ptrtoint %class.NVariableDeclaration** %11 to i64
  %16 = ptrtoint %class.NVariableDeclaration** %14 to i64
  %17 = sub i64 %15, %16
  %18 = sdiv exact i64 %17, 8
  invoke void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.4"* %5, %class.NVariableDeclaration** %8, i64 %18)
          to label %19 unwind label %21

; <label>:19:                                     ; preds = %1
  %20 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %20) #3
  ret void

; <label>:21:                                     ; preds = %1
  %22 = landingpad { i8*, i32 }
          catch i8* null
  %23 = extractvalue { i8*, i32 } %22, 0
  store i8* %23, i8** %3, align 8
  %24 = extractvalue { i8*, i32 } %22, 1
  store i32 %24, i32* %4, align 4
  %25 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %25) #3
  br label %26

; <label>:26:                                     ; preds = %21
  %27 = load i8*, i8** %3, align 8
  call void @__clang_call_terminate(i8* %27) #10
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE37select_on_container_copy_constructionERKS2_(%"class.std::allocator.5"* noalias sret, %"class.std::allocator.5"* dereferenceable(1)) #7 comdat align 2 {
  %3 = alloca %"class.std::allocator.5"*, align 8
  store %"class.std::allocator.5"* %1, %"class.std::allocator.5"** %3, align 8
  %4 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %3, align 8
  call void @_ZNSaIP20NVariableDeclarationEC2ERKS1_(%"class.std::allocator.5"* %0, %"class.std::allocator.5"* dereferenceable(1) %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP20NVariableDeclarationEC2ERKS1_(%"class.std::allocator.5"*, %"class.std::allocator.5"* dereferenceable(1)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.std::allocator.5"*, align 8
  %4 = alloca %"class.std::allocator.5"*, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %3, align 8
  store %"class.std::allocator.5"* %1, %"class.std::allocator.5"** %4, align 8
  %5 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %3, align 8
  %6 = bitcast %"class.std::allocator.5"* %5 to %"class.__gnu_cxx::new_allocator.6"*
  %7 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %4, align 8
  %8 = bitcast %"class.std::allocator.5"* %7 to %"class.__gnu_cxx::new_allocator.6"*
  call void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2ERKS3_(%"class.__gnu_cxx::new_allocator.6"* %6, %"class.__gnu_cxx::new_allocator.6"* dereferenceable(1) %8) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2ERKS3_(%"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"* dereferenceable(1)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  %4 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %3, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %1, %"class.__gnu_cxx::new_allocator.6"** %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %3, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2ERKS2_(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*, %"class.std::allocator.5"* dereferenceable(1)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*, align 8
  %4 = alloca %"class.std::allocator.5"*, align 8
  store %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"** %3, align 8
  store %"class.std::allocator.5"* %1, %"class.std::allocator.5"** %4, align 8
  %5 = load %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*, %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"** %3, align 8
  %6 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %5 to %"class.std::allocator.5"*
  %7 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %4, align 8
  call void @_ZNSaIP20NVariableDeclarationEC2ERKS1_(%"class.std::allocator.5"* %6, %"class.std::allocator.5"* dereferenceable(1) %7) #3
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** null, %class.NVariableDeclaration*** %8, align 8
  %9 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %5, i32 0, i32 1
  store %class.NVariableDeclaration** null, %class.NVariableDeclaration*** %9, align 8
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %5, i32 0, i32 2
  store %class.NVariableDeclaration** null, %class.NVariableDeclaration*** %10, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE17_M_create_storageEm(%"struct.std::_Vector_base.4"*, i64) #4 comdat align 2 {
  %3 = alloca %"struct.std::_Vector_base.4"*, align 8
  %4 = alloca i64, align 8
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %3, align 8
  %6 = load i64, i64* %4, align 8
  %7 = call %class.NVariableDeclaration** @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base.4"* %5, i64 %6)
  %8 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %8, i32 0, i32 0
  store %class.NVariableDeclaration** %7, %class.NVariableDeclaration*** %9, align 8
  %10 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %11 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %10, i32 0, i32 0
  %12 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %11, align 8
  %13 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %14 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %13, i32 0, i32 1
  store %class.NVariableDeclaration** %12, %class.NVariableDeclaration*** %14, align 8
  %15 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %16 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %15, i32 0, i32 0
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %16, align 8
  %18 = load i64, i64* %4, align 8
  %19 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %17, i64 %18
  %20 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %21 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %20, i32 0, i32 2
  store %class.NVariableDeclaration** %19, %class.NVariableDeclaration*** %21, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"** %2, align 8
  %3 = load %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*, %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"** %2, align 8
  %4 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %3 to %"class.std::allocator.5"*
  call void @_ZNSaIP20NVariableDeclarationED2Ev(%"class.std::allocator.5"* %4) #3
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base.4"*, i64) #4 comdat align 2 {
  %3 = alloca %"struct.std::_Vector_base.4"*, align 8
  %4 = alloca i64, align 8
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %3, align 8
  %6 = load i64, i64* %4, align 8
  %7 = icmp ne i64 %6, 0
  br i1 %7, label %8, label %13

; <label>:8:                                      ; preds = %2
  %9 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %10 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %9 to %"class.std::allocator.5"*
  %11 = load i64, i64* %4, align 8
  %12 = call %class.NVariableDeclaration** @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8allocateERS2_m(%"class.std::allocator.5"* dereferenceable(1) %10, i64 %11)
  br label %14

; <label>:13:                                     ; preds = %2
  br label %14

; <label>:14:                                     ; preds = %13, %8
  %15 = phi %class.NVariableDeclaration** [ %12, %8 ], [ null, %13 ]
  ret %class.NVariableDeclaration** %15
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8allocateERS2_m(%"class.std::allocator.5"* dereferenceable(1), i64) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator.5"*, align 8
  %4 = alloca i64, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %3, align 8
  %6 = bitcast %"class.std::allocator.5"* %5 to %"class.__gnu_cxx::new_allocator.6"*
  %7 = load i64, i64* %4, align 8
  %8 = call %class.NVariableDeclaration** @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8allocateEmPKv(%"class.__gnu_cxx::new_allocator.6"* %6, i64 %7, i8* null)
  ret %class.NVariableDeclaration** %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8allocateEmPKv(%"class.__gnu_cxx::new_allocator.6"*, i64, i8*) #4 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i8*, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %4, align 8
  store i64 %1, i64* %5, align 8
  store i8* %2, i8** %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %4, align 8
  %8 = load i64, i64* %5, align 8
  %9 = call i64 @_ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv(%"class.__gnu_cxx::new_allocator.6"* %7) #3
  %10 = icmp ugt i64 %8, %9
  br i1 %10, label %11, label %12

; <label>:11:                                     ; preds = %3
  call void @_ZSt17__throw_bad_allocv() #16
  unreachable

; <label>:12:                                     ; preds = %3
  %13 = load i64, i64* %5, align 8
  %14 = mul i64 %13, 8
  %15 = call i8* @_Znwm(i64 %14)
  %16 = bitcast i8* %15 to %class.NVariableDeclaration**
  ret %class.NVariableDeclaration** %16
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv(%"class.__gnu_cxx::new_allocator.6"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %2, align 8
  ret i64 2305843009213693951
}

; Function Attrs: noreturn
declare dso_local void @_ZSt17__throw_bad_allocv() #12

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationED2Ev(%"class.__gnu_cxx::new_allocator.6"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %2, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca i8, align 1
  %8 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %10, align 8
  %11 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %11, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  store i8 1, i8* %7, align 1
  %12 = bitcast %"class.__gnu_cxx::__normal_iterator"* %8 to i8*
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %12, i8* align 8 %13, i64 8, i1 false)
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator"* %9 to i8*
  %15 = bitcast %"class.__gnu_cxx::__normal_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %14, i8* align 8 %15, i64 8, i1 false)
  %16 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %17 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %8, i32 0, i32 0
  %18 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %17, align 8
  %19 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %9, i32 0, i32 0
  %20 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %19, align 8
  %21 = call %class.NVariableDeclaration** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(%class.NVariableDeclaration** %18, %class.NVariableDeclaration** %20, %class.NVariableDeclaration** %16)
  ret %class.NVariableDeclaration** %21
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %8 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %9 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %9, align 8
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %10, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %11 = bitcast %"class.__gnu_cxx::__normal_iterator"* %7 to i8*
  %12 = bitcast %"class.__gnu_cxx::__normal_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator"* %8 to i8*
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %16 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %7, i32 0, i32 0
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %16, align 8
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %8, i32 0, i32 0
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %18, align 8
  %20 = call %class.NVariableDeclaration** @_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NVariableDeclaration** %17, %class.NVariableDeclaration** %19, %class.NVariableDeclaration** %15)
  ret %class.NVariableDeclaration** %20
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %8 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %10 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %11 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %11, align 8
  %12 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %12, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator"* %8 to i8*
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %8, i32 0, i32 0
  %16 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %15, align 8
  %17 = call %class.NVariableDeclaration** @_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_(%class.NVariableDeclaration** %16)
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %7, i32 0, i32 0
  store %class.NVariableDeclaration** %17, %class.NVariableDeclaration*** %18, align 8
  %19 = bitcast %"class.__gnu_cxx::__normal_iterator"* %10 to i8*
  %20 = bitcast %"class.__gnu_cxx::__normal_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %19, i8* align 8 %20, i64 8, i1 false)
  %21 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %10, i32 0, i32 0
  %22 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %21, align 8
  %23 = call %class.NVariableDeclaration** @_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_(%class.NVariableDeclaration** %22)
  %24 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %9, i32 0, i32 0
  store %class.NVariableDeclaration** %23, %class.NVariableDeclaration*** %24, align 8
  %25 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %26 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %7, i32 0, i32 0
  %27 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %26, align 8
  %28 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %9, i32 0, i32 0
  %29 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %28, align 8
  %30 = call %class.NVariableDeclaration** @_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(%class.NVariableDeclaration** %27, %class.NVariableDeclaration** %29, %class.NVariableDeclaration** %25)
  ret %class.NVariableDeclaration** %30
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %8 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %9 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %9, align 8
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %10, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %11 = bitcast %"class.__gnu_cxx::__normal_iterator"* %7 to i8*
  %12 = bitcast %"class.__gnu_cxx::__normal_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %7, i32 0, i32 0
  %14 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %15 = call %class.NVariableDeclaration** @_ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(%class.NVariableDeclaration** %14)
  %16 = bitcast %"class.__gnu_cxx::__normal_iterator"* %8 to i8*
  %17 = bitcast %"class.__gnu_cxx::__normal_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %16, i8* align 8 %17, i64 8, i1 false)
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %8, i32 0, i32 0
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %18, align 8
  %20 = call %class.NVariableDeclaration** @_ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(%class.NVariableDeclaration** %19)
  %21 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %22 = call %class.NVariableDeclaration** @_ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(%class.NVariableDeclaration** %21)
  %23 = call %class.NVariableDeclaration** @_ZSt13__copy_move_aILb0EPKP20NVariableDeclarationPS1_ET1_T0_S6_S5_(%class.NVariableDeclaration** %15, %class.NVariableDeclaration** %20, %class.NVariableDeclaration** %22)
  ret %class.NVariableDeclaration** %23
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS3_SaIS3_EEEEET_SA_(%class.NVariableDeclaration**) #7 comdat {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %3 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %3, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %4, align 8
  %5 = bitcast %"class.__gnu_cxx::__normal_iterator"* %2 to i8*
  %6 = bitcast %"class.__gnu_cxx::__normal_iterator"* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %5, i8* align 8 %6, i64 8, i1 false)
  %7 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %2, i32 0, i32 0
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %7, align 8
  ret %class.NVariableDeclaration** %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt13__copy_move_aILb0EPKP20NVariableDeclarationPS1_ET1_T0_S6_S5_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %class.NVariableDeclaration**, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca i8, align 1
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  store i8 1, i8* %7, align 1
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %10 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %11 = call %class.NVariableDeclaration** @_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(%class.NVariableDeclaration** %8, %class.NVariableDeclaration** %9, %class.NVariableDeclaration** %10)
  ret %class.NVariableDeclaration** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt12__niter_baseIPKP20NVariableDeclarationSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(%class.NVariableDeclaration**) #7 comdat {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator", align 8
  %3 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %2, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %3, align 8
  %4 = call dereferenceable(8) %class.NVariableDeclaration*** @_ZNK9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator"* %2) #3
  %5 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  ret %class.NVariableDeclaration** %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(%class.NVariableDeclaration**) #7 comdat {
  %2 = alloca %class.NVariableDeclaration**, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %2, align 8
  %3 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %2, align 8
  ret %class.NVariableDeclaration** %3
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #7 comdat align 2 {
  %4 = alloca %class.NVariableDeclaration**, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca i64, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %10 = ptrtoint %class.NVariableDeclaration** %8 to i64
  %11 = ptrtoint %class.NVariableDeclaration** %9 to i64
  %12 = sub i64 %10, %11
  %13 = sdiv exact i64 %12, 8
  store i64 %13, i64* %7, align 8
  %14 = load i64, i64* %7, align 8
  %15 = icmp ne i64 %14, 0
  br i1 %15, label %16, label %23

; <label>:16:                                     ; preds = %3
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %18 = bitcast %class.NVariableDeclaration** %17 to i8*
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %20 = bitcast %class.NVariableDeclaration** %19 to i8*
  %21 = load i64, i64* %7, align 8
  %22 = mul i64 8, %21
  call void @llvm.memmove.p0i8.p0i8.i64(i8* align 8 %18, i8* align 8 %20, i64 %22, i1 false)
  br label %23

; <label>:23:                                     ; preds = %16, %3
  %24 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %25 = load i64, i64* %7, align 8
  %26 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %24, i64 %25
  ret %class.NVariableDeclaration** %26
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memmove.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i1) #5

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NVariableDeclaration*** @_ZNK9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %0, %"class.__gnu_cxx::__normal_iterator"** %2, align 8
  %3 = load %"class.__gnu_cxx::__normal_iterator"*, %"class.__gnu_cxx::__normal_iterator"** %2, align 8
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %3, i32 0, i32 0
  ret %class.NVariableDeclaration*** %4
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx17__normal_iteratorIPKP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS4_(%"class.__gnu_cxx::__normal_iterator"*, %class.NVariableDeclaration*** dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator"*, align 8
  %4 = alloca %class.NVariableDeclaration***, align 8
  store %"class.__gnu_cxx::__normal_iterator"* %0, %"class.__gnu_cxx::__normal_iterator"** %3, align 8
  store %class.NVariableDeclaration*** %1, %class.NVariableDeclaration**** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator"*, %"class.__gnu_cxx::__normal_iterator"** %3, align 8
  %6 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator", %"class.__gnu_cxx::__normal_iterator"* %5, i32 0, i32 0
  %7 = load %class.NVariableDeclaration***, %class.NVariableDeclaration**** %4, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %7, align 8
  store %class.NVariableDeclaration** %8, %class.NVariableDeclaration*** %6, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.4"*, %class.NVariableDeclaration**, i64) #4 comdat align 2 {
  %4 = alloca %"struct.std::_Vector_base.4"*, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca i64, align 8
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %4, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %9 = icmp ne %class.NVariableDeclaration** %8, null
  br i1 %9, label %10, label %15

; <label>:10:                                     ; preds = %3
  %11 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %7, i32 0, i32 0
  %12 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %11 to %"class.std::allocator.5"*
  %13 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %14 = load i64, i64* %6, align 8
  call void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE10deallocateERS2_PS1_m(%"class.std::allocator.5"* dereferenceable(1) %12, %class.NVariableDeclaration** %13, i64 %14)
  br label %15

; <label>:15:                                     ; preds = %10, %3
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE10deallocateERS2_PS1_m(%"class.std::allocator.5"* dereferenceable(1), %class.NVariableDeclaration**, i64) #4 comdat align 2 {
  %4 = alloca %"class.std::allocator.5"*, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca i64, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %4, align 8
  %8 = bitcast %"class.std::allocator.5"* %7 to %"class.__gnu_cxx::new_allocator.6"*
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %10 = load i64, i64* %6, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator.6"* %8, %class.NVariableDeclaration** %9, i64 %10)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator.6"*, %class.NVariableDeclaration**, i64) #7 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca i64, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %4, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %9 = bitcast %class.NVariableDeclaration** %8 to i8*
  call void @_ZdlPv(i8* %9) #3
  ret void
}

declare dso_local void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_(%"class.std::__cxx11::basic_string"*, %"class.std::__cxx11::basic_string"* dereferenceable(32)) unnamed_addr #1

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NIdentifierD2Ev(%class.NIdentifier*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NIdentifier*, align 8
  store %class.NIdentifier* %0, %class.NIdentifier** %2, align 8
  %3 = load %class.NIdentifier*, %class.NIdentifier** %2, align 8
  %4 = bitcast %class.NIdentifier* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV11NIdentifier, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %4, align 8
  %5 = getelementptr inbounds %class.NIdentifier, %class.NIdentifier* %3, i32 0, i32 1
  call void @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev(%"class.std::__cxx11::basic_string"* %5) #3
  %6 = bitcast %class.NIdentifier* %3 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %6) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NIdentifierD0Ev(%class.NIdentifier*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NIdentifier*, align 8
  store %class.NIdentifier* %0, %class.NIdentifier** %2, align 8
  %3 = load %class.NIdentifier*, %class.NIdentifier** %2, align 8
  call void @_ZN11NIdentifierD2Ev(%class.NIdentifier* %3) #3
  %4 = bitcast %class.NIdentifier* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN11NIdentifier7codeGenER14CodeGenContext(%class.NIdentifier*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NIdentifier*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NIdentifier* %0, %class.NIdentifier** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NIdentifier*, %class.NIdentifier** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN7NDoubleD2Ev(%class.NDouble*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NDouble*, align 8
  store %class.NDouble* %0, %class.NDouble** %2, align 8
  %3 = load %class.NDouble*, %class.NDouble** %2, align 8
  %4 = bitcast %class.NDouble* %3 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN7NDoubleD0Ev(%class.NDouble*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NDouble*, align 8
  store %class.NDouble* %0, %class.NDouble** %2, align 8
  %3 = load %class.NDouble*, %class.NDouble** %2, align 8
  call void @_ZN7NDoubleD2Ev(%class.NDouble* %3) #3
  %4 = bitcast %class.NDouble* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN7NDouble7codeGenER14CodeGenContext(%class.NDouble*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NDouble*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NDouble* %0, %class.NDouble** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NDouble*, %class.NDouble** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NAssignmentD2Ev(%class.NAssignment*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NAssignment*, align 8
  store %class.NAssignment* %0, %class.NAssignment** %2, align 8
  %3 = load %class.NAssignment*, %class.NAssignment** %2, align 8
  %4 = bitcast %class.NAssignment* %3 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NAssignmentD0Ev(%class.NAssignment*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NAssignment*, align 8
  store %class.NAssignment* %0, %class.NAssignment** %2, align 8
  %3 = load %class.NAssignment*, %class.NAssignment** %2, align 8
  call void @_ZN11NAssignmentD2Ev(%class.NAssignment* %3) #3
  %4 = bitcast %class.NAssignment* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN11NAssignment7codeGenER14CodeGenContext(%class.NAssignment*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NAssignment*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NAssignment* %0, %class.NAssignment** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NAssignment*, %class.NAssignment** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP11NExpressionSaIS1_EEC2ERKS3_(%"class.std::vector.8"*, %"class.std::vector.8"* dereferenceable(24)) unnamed_addr #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %3 = alloca %"class.std::vector.8"*, align 8
  %4 = alloca %"class.std::vector.8"*, align 8
  %5 = alloca %"class.std::allocator.10", align 1
  %6 = alloca i8*
  %7 = alloca i32
  %8 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %3, align 8
  store %"class.std::vector.8"* %1, %"class.std::vector.8"** %4, align 8
  %10 = load %"class.std::vector.8"*, %"class.std::vector.8"** %3, align 8
  %11 = bitcast %"class.std::vector.8"* %10 to %"struct.std::_Vector_base.9"*
  %12 = load %"class.std::vector.8"*, %"class.std::vector.8"** %4, align 8
  %13 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(%"class.std::vector.8"* %12) #3
  %14 = load %"class.std::vector.8"*, %"class.std::vector.8"** %4, align 8
  %15 = bitcast %"class.std::vector.8"* %14 to %"struct.std::_Vector_base.9"*
  %16 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %15) #3
  call void @_ZN9__gnu_cxx14__alloc_traitsISaIP11NExpressionES2_E17_S_select_on_copyERKS3_(%"class.std::allocator.10"* sret %5, %"class.std::allocator.10"* dereferenceable(1) %16)
  invoke void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2EmRKS2_(%"struct.std::_Vector_base.9"* %11, i64 %13, %"class.std::allocator.10"* dereferenceable(1) %5)
          to label %17 unwind label %39

; <label>:17:                                     ; preds = %2
  call void @_ZNSaIP11NExpressionED2Ev(%"class.std::allocator.10"* %5) #3
  %18 = load %"class.std::vector.8"*, %"class.std::vector.8"** %4, align 8
  %19 = call %class.NExpression** @_ZNKSt6vectorIP11NExpressionSaIS1_EE5beginEv(%"class.std::vector.8"* %18) #3
  %20 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %8, i32 0, i32 0
  store %class.NExpression** %19, %class.NExpression*** %20, align 8
  %21 = load %"class.std::vector.8"*, %"class.std::vector.8"** %4, align 8
  %22 = call %class.NExpression** @_ZNKSt6vectorIP11NExpressionSaIS1_EE3endEv(%"class.std::vector.8"* %21) #3
  %23 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %9, i32 0, i32 0
  store %class.NExpression** %22, %class.NExpression*** %23, align 8
  %24 = bitcast %"class.std::vector.8"* %10 to %"struct.std::_Vector_base.9"*
  %25 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %24, i32 0, i32 0
  %26 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %25, i32 0, i32 0
  %27 = load %class.NExpression**, %class.NExpression*** %26, align 8
  %28 = bitcast %"class.std::vector.8"* %10 to %"struct.std::_Vector_base.9"*
  %29 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %28) #3
  %30 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %8, i32 0, i32 0
  %31 = load %class.NExpression**, %class.NExpression*** %30, align 8
  %32 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %9, i32 0, i32 0
  %33 = load %class.NExpression**, %class.NExpression*** %32, align 8
  %34 = invoke %class.NExpression** @_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(%class.NExpression** %31, %class.NExpression** %33, %class.NExpression** %27, %"class.std::allocator.10"* dereferenceable(1) %29)
          to label %35 unwind label %43

; <label>:35:                                     ; preds = %17
  %36 = bitcast %"class.std::vector.8"* %10 to %"struct.std::_Vector_base.9"*
  %37 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %36, i32 0, i32 0
  %38 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %37, i32 0, i32 1
  store %class.NExpression** %34, %class.NExpression*** %38, align 8
  ret void

; <label>:39:                                     ; preds = %2
  %40 = landingpad { i8*, i32 }
          cleanup
  %41 = extractvalue { i8*, i32 } %40, 0
  store i8* %41, i8** %6, align 8
  %42 = extractvalue { i8*, i32 } %40, 1
  store i32 %42, i32* %7, align 4
  call void @_ZNSaIP11NExpressionED2Ev(%"class.std::allocator.10"* %5) #3
  br label %48

; <label>:43:                                     ; preds = %17
  %44 = landingpad { i8*, i32 }
          cleanup
  %45 = extractvalue { i8*, i32 } %44, 0
  store i8* %45, i8** %6, align 8
  %46 = extractvalue { i8*, i32 } %44, 1
  store i32 %46, i32* %7, align 4
  %47 = bitcast %"class.std::vector.8"* %10 to %"struct.std::_Vector_base.9"*
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev(%"struct.std::_Vector_base.9"* %47) #3
  br label %48

; <label>:48:                                     ; preds = %43, %39
  %49 = load i8*, i8** %6, align 8
  %50 = load i32, i32* %7, align 4
  %51 = insertvalue { i8*, i32 } undef, i8* %49, 0
  %52 = insertvalue { i8*, i32 } %51, i32 %50, 1
  resume { i8*, i32 } %52
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NMethodCallD2Ev(%class.NMethodCall*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NMethodCall*, align 8
  store %class.NMethodCall* %0, %class.NMethodCall** %2, align 8
  %3 = load %class.NMethodCall*, %class.NMethodCall** %2, align 8
  %4 = bitcast %class.NMethodCall* %3 to i32 (...)***
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTV11NMethodCall, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %4, align 8
  %5 = getelementptr inbounds %class.NMethodCall, %class.NMethodCall* %3, i32 0, i32 2
  call void @_ZNSt6vectorIP11NExpressionSaIS1_EED2Ev(%"class.std::vector.8"* %5) #3
  %6 = bitcast %class.NMethodCall* %3 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %6) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN11NMethodCallD0Ev(%class.NMethodCall*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NMethodCall*, align 8
  store %class.NMethodCall* %0, %class.NMethodCall** %2, align 8
  %3 = load %class.NMethodCall*, %class.NMethodCall** %2, align 8
  call void @_ZN11NMethodCallD2Ev(%class.NMethodCall* %3) #3
  %4 = bitcast %class.NMethodCall* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN11NMethodCall7codeGenER14CodeGenContext(%class.NMethodCall*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NMethodCall*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NMethodCall* %0, %class.NMethodCall** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NMethodCall*, %class.NMethodCall** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(%"class.std::vector.8"*) #7 comdat align 2 {
  %2 = alloca %"class.std::vector.8"*, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %2, align 8
  %3 = load %"class.std::vector.8"*, %"class.std::vector.8"** %2, align 8
  %4 = bitcast %"class.std::vector.8"* %3 to %"struct.std::_Vector_base.9"*
  %5 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %5, i32 0, i32 1
  %7 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %8 = bitcast %"class.std::vector.8"* %3 to %"struct.std::_Vector_base.9"*
  %9 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %8, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %9, i32 0, i32 0
  %11 = load %class.NExpression**, %class.NExpression*** %10, align 8
  %12 = ptrtoint %class.NExpression** %7 to i64
  %13 = ptrtoint %class.NExpression** %11 to i64
  %14 = sub i64 %12, %13
  %15 = sdiv exact i64 %14, 8
  ret i64 %15
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx14__alloc_traitsISaIP11NExpressionES2_E17_S_select_on_copyERKS3_(%"class.std::allocator.10"* noalias sret, %"class.std::allocator.10"* dereferenceable(1)) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator.10"*, align 8
  store %"class.std::allocator.10"* %1, %"class.std::allocator.10"** %3, align 8
  %4 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %3, align 8
  call void @_ZNSt16allocator_traitsISaIP11NExpressionEE37select_on_container_copy_constructionERKS2_(%"class.std::allocator.10"* sret %0, %"class.std::allocator.10"* dereferenceable(1) %4)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(1) %"class.std::allocator.10"* @_ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"*) #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base.9"*, align 8
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %2, align 8
  %3 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %3, i32 0, i32 0
  %5 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %4 to %"class.std::allocator.10"*
  ret %"class.std::allocator.10"* %5
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2EmRKS2_(%"struct.std::_Vector_base.9"*, i64, %"class.std::allocator.10"* dereferenceable(1)) unnamed_addr #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %4 = alloca %"struct.std::_Vector_base.9"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca %"class.std::allocator.10"*, align 8
  %7 = alloca i8*
  %8 = alloca i32
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %4, align 8
  store i64 %1, i64* %5, align 8
  store %"class.std::allocator.10"* %2, %"class.std::allocator.10"** %6, align 8
  %9 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %4, align 8
  %10 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %9, i32 0, i32 0
  %11 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %6, align 8
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2ERKS2_(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %10, %"class.std::allocator.10"* dereferenceable(1) %11) #3
  %12 = load i64, i64* %5, align 8
  invoke void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE17_M_create_storageEm(%"struct.std::_Vector_base.9"* %9, i64 %12)
          to label %13 unwind label %14

; <label>:13:                                     ; preds = %3
  ret void

; <label>:14:                                     ; preds = %3
  %15 = landingpad { i8*, i32 }
          cleanup
  %16 = extractvalue { i8*, i32 } %15, 0
  store i8* %16, i8** %7, align 8
  %17 = extractvalue { i8*, i32 } %15, 1
  store i32 %17, i32* %8, align 4
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %10) #3
  br label %18

; <label>:18:                                     ; preds = %14
  %19 = load i8*, i8** %7, align 8
  %20 = load i32, i32* %8, align 4
  %21 = insertvalue { i8*, i32 } undef, i8* %19, 0
  %22 = insertvalue { i8*, i32 } %21, i32 %20, 1
  resume { i8*, i32 } %22
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP11NExpressionED2Ev(%"class.std::allocator.10"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.std::allocator.10"*, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %2, align 8
  %3 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %2, align 8
  %4 = bitcast %"class.std::allocator.10"* %3 to %"class.__gnu_cxx::new_allocator.11"*
  call void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionED2Ev(%"class.__gnu_cxx::new_allocator.11"* %4) #3
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E(%class.NExpression**, %class.NExpression**, %class.NExpression**, %"class.std::allocator.10"* dereferenceable(1)) #4 comdat {
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %6 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %7 = alloca %class.NExpression**, align 8
  %8 = alloca %"class.std::allocator.10"*, align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %10 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %11 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %5, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %11, align 8
  %12 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %6, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %12, align 8
  store %class.NExpression** %2, %class.NExpression*** %7, align 8
  store %"class.std::allocator.10"* %3, %"class.std::allocator.10"** %8, align 8
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %9 to i8*
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %10 to i8*
  %16 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %15, i8* align 8 %16, i64 8, i1 false)
  %17 = load %class.NExpression**, %class.NExpression*** %7, align 8
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %9, i32 0, i32 0
  %19 = load %class.NExpression**, %class.NExpression*** %18, align 8
  %20 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %10, i32 0, i32 0
  %21 = load %class.NExpression**, %class.NExpression*** %20, align 8
  %22 = call %class.NExpression** @_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NExpression** %19, %class.NExpression** %21, %class.NExpression** %17)
  ret %class.NExpression** %22
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNKSt6vectorIP11NExpressionSaIS1_EE5beginEv(%"class.std::vector.8"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %3 = alloca %"class.std::vector.8"*, align 8
  %4 = alloca %class.NExpression**, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %3, align 8
  %5 = load %"class.std::vector.8"*, %"class.std::vector.8"** %3, align 8
  %6 = bitcast %"class.std::vector.8"* %5 to %"struct.std::_Vector_base.9"*
  %7 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %6, i32 0, i32 0
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %7, i32 0, i32 0
  %9 = load %class.NExpression**, %class.NExpression*** %8, align 8
  store %class.NExpression** %9, %class.NExpression*** %4, align 8
  call void @_ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_(%"class.__gnu_cxx::__normal_iterator.13"* %2, %class.NExpression*** dereferenceable(8) %4) #3
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %2, i32 0, i32 0
  %11 = load %class.NExpression**, %class.NExpression*** %10, align 8
  ret %class.NExpression** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNKSt6vectorIP11NExpressionSaIS1_EE3endEv(%"class.std::vector.8"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %3 = alloca %"class.std::vector.8"*, align 8
  %4 = alloca %class.NExpression**, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %3, align 8
  %5 = load %"class.std::vector.8"*, %"class.std::vector.8"** %3, align 8
  %6 = bitcast %"class.std::vector.8"* %5 to %"struct.std::_Vector_base.9"*
  %7 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %6, i32 0, i32 0
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %7, i32 0, i32 1
  %9 = load %class.NExpression**, %class.NExpression*** %8, align 8
  store %class.NExpression** %9, %class.NExpression*** %4, align 8
  call void @_ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_(%"class.__gnu_cxx::__normal_iterator.13"* %2, %class.NExpression*** dereferenceable(8) %4) #3
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %2, i32 0, i32 0
  %11 = load %class.NExpression**, %class.NExpression*** %10, align 8
  ret %class.NExpression** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(1) %"class.std::allocator.10"* @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"*) #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base.9"*, align 8
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %2, align 8
  %3 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %3, i32 0, i32 0
  %5 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %4 to %"class.std::allocator.10"*
  ret %"class.std::allocator.10"* %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EED2Ev(%"struct.std::_Vector_base.9"*) unnamed_addr #7 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %2 = alloca %"struct.std::_Vector_base.9"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %2, align 8
  %5 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %2, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %6, i32 0, i32 0
  %8 = load %class.NExpression**, %class.NExpression*** %7, align 8
  %9 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %9, i32 0, i32 2
  %11 = load %class.NExpression**, %class.NExpression*** %10, align 8
  %12 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %13 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %12, i32 0, i32 0
  %14 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %15 = ptrtoint %class.NExpression** %11 to i64
  %16 = ptrtoint %class.NExpression** %14 to i64
  %17 = sub i64 %15, %16
  %18 = sdiv exact i64 %17, 8
  invoke void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.9"* %5, %class.NExpression** %8, i64 %18)
          to label %19 unwind label %21

; <label>:19:                                     ; preds = %1
  %20 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %20) #3
  ret void

; <label>:21:                                     ; preds = %1
  %22 = landingpad { i8*, i32 }
          catch i8* null
  %23 = extractvalue { i8*, i32 } %22, 0
  store i8* %23, i8** %3, align 8
  %24 = extractvalue { i8*, i32 } %22, 1
  store i32 %24, i32* %4, align 4
  %25 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %25) #3
  br label %26

; <label>:26:                                     ; preds = %21
  %27 = load i8*, i8** %3, align 8
  call void @__clang_call_terminate(i8* %27) #10
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP11NExpressionEE37select_on_container_copy_constructionERKS2_(%"class.std::allocator.10"* noalias sret, %"class.std::allocator.10"* dereferenceable(1)) #7 comdat align 2 {
  %3 = alloca %"class.std::allocator.10"*, align 8
  store %"class.std::allocator.10"* %1, %"class.std::allocator.10"** %3, align 8
  %4 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %3, align 8
  call void @_ZNSaIP11NExpressionEC2ERKS1_(%"class.std::allocator.10"* %0, %"class.std::allocator.10"* dereferenceable(1) %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP11NExpressionEC2ERKS1_(%"class.std::allocator.10"*, %"class.std::allocator.10"* dereferenceable(1)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.std::allocator.10"*, align 8
  %4 = alloca %"class.std::allocator.10"*, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %3, align 8
  store %"class.std::allocator.10"* %1, %"class.std::allocator.10"** %4, align 8
  %5 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %3, align 8
  %6 = bitcast %"class.std::allocator.10"* %5 to %"class.__gnu_cxx::new_allocator.11"*
  %7 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %4, align 8
  %8 = bitcast %"class.std::allocator.10"* %7 to %"class.__gnu_cxx::new_allocator.11"*
  call void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2ERKS3_(%"class.__gnu_cxx::new_allocator.11"* %6, %"class.__gnu_cxx::new_allocator.11"* dereferenceable(1) %8) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2ERKS3_(%"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"* dereferenceable(1)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  %4 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %3, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %1, %"class.__gnu_cxx::new_allocator.11"** %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %3, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2ERKS2_(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*, %"class.std::allocator.10"* dereferenceable(1)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*, align 8
  %4 = alloca %"class.std::allocator.10"*, align 8
  store %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"** %3, align 8
  store %"class.std::allocator.10"* %1, %"class.std::allocator.10"** %4, align 8
  %5 = load %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*, %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"** %3, align 8
  %6 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %5 to %"class.std::allocator.10"*
  %7 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %4, align 8
  call void @_ZNSaIP11NExpressionEC2ERKS1_(%"class.std::allocator.10"* %6, %"class.std::allocator.10"* dereferenceable(1) %7) #3
  %8 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %5, i32 0, i32 0
  store %class.NExpression** null, %class.NExpression*** %8, align 8
  %9 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %5, i32 0, i32 1
  store %class.NExpression** null, %class.NExpression*** %9, align 8
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %5, i32 0, i32 2
  store %class.NExpression** null, %class.NExpression*** %10, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE17_M_create_storageEm(%"struct.std::_Vector_base.9"*, i64) #4 comdat align 2 {
  %3 = alloca %"struct.std::_Vector_base.9"*, align 8
  %4 = alloca i64, align 8
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %3, align 8
  %6 = load i64, i64* %4, align 8
  %7 = call %class.NExpression** @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base.9"* %5, i64 %6)
  %8 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %8, i32 0, i32 0
  store %class.NExpression** %7, %class.NExpression*** %9, align 8
  %10 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %11 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %10, i32 0, i32 0
  %12 = load %class.NExpression**, %class.NExpression*** %11, align 8
  %13 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %14 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %13, i32 0, i32 1
  store %class.NExpression** %12, %class.NExpression*** %14, align 8
  %15 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %16 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %15, i32 0, i32 0
  %17 = load %class.NExpression**, %class.NExpression*** %16, align 8
  %18 = load i64, i64* %4, align 8
  %19 = getelementptr inbounds %class.NExpression*, %class.NExpression** %17, i64 %18
  %20 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %21 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %20, i32 0, i32 2
  store %class.NExpression** %19, %class.NExpression*** %21, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"** %2, align 8
  %3 = load %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*, %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"** %2, align 8
  %4 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %3 to %"class.std::allocator.10"*
  call void @_ZNSaIP11NExpressionED2Ev(%"class.std::allocator.10"* %4) #3
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base.9"*, i64) #4 comdat align 2 {
  %3 = alloca %"struct.std::_Vector_base.9"*, align 8
  %4 = alloca i64, align 8
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %3, align 8
  %6 = load i64, i64* %4, align 8
  %7 = icmp ne i64 %6, 0
  br i1 %7, label %8, label %13

; <label>:8:                                      ; preds = %2
  %9 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %10 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %9 to %"class.std::allocator.10"*
  %11 = load i64, i64* %4, align 8
  %12 = call %class.NExpression** @_ZNSt16allocator_traitsISaIP11NExpressionEE8allocateERS2_m(%"class.std::allocator.10"* dereferenceable(1) %10, i64 %11)
  br label %14

; <label>:13:                                     ; preds = %2
  br label %14

; <label>:14:                                     ; preds = %13, %8
  %15 = phi %class.NExpression** [ %12, %8 ], [ null, %13 ]
  ret %class.NExpression** %15
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt16allocator_traitsISaIP11NExpressionEE8allocateERS2_m(%"class.std::allocator.10"* dereferenceable(1), i64) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator.10"*, align 8
  %4 = alloca i64, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %3, align 8
  %6 = bitcast %"class.std::allocator.10"* %5 to %"class.__gnu_cxx::new_allocator.11"*
  %7 = load i64, i64* %4, align 8
  %8 = call %class.NExpression** @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE8allocateEmPKv(%"class.__gnu_cxx::new_allocator.11"* %6, i64 %7, i8* null)
  ret %class.NExpression** %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE8allocateEmPKv(%"class.__gnu_cxx::new_allocator.11"*, i64, i8*) #4 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i8*, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %4, align 8
  store i64 %1, i64* %5, align 8
  store i8* %2, i8** %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %4, align 8
  %8 = load i64, i64* %5, align 8
  %9 = call i64 @_ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv(%"class.__gnu_cxx::new_allocator.11"* %7) #3
  %10 = icmp ugt i64 %8, %9
  br i1 %10, label %11, label %12

; <label>:11:                                     ; preds = %3
  call void @_ZSt17__throw_bad_allocv() #16
  unreachable

; <label>:12:                                     ; preds = %3
  %13 = load i64, i64* %5, align 8
  %14 = mul i64 %13, 8
  %15 = call i8* @_Znwm(i64 %14)
  %16 = bitcast i8* %15 to %class.NExpression**
  ret %class.NExpression** %16
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv(%"class.__gnu_cxx::new_allocator.11"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %2, align 8
  ret i64 2305843009213693951
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionED2Ev(%"class.__gnu_cxx::new_allocator.11"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %2, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca i8, align 1
  %8 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %4, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %10, align 8
  %11 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %5, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %11, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  store i8 1, i8* %7, align 1
  %12 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %8 to i8*
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %12, i8* align 8 %13, i64 8, i1 false)
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %9 to i8*
  %15 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %14, i8* align 8 %15, i64 8, i1 false)
  %16 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %17 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %8, i32 0, i32 0
  %18 = load %class.NExpression**, %class.NExpression*** %17, align 8
  %19 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %9, i32 0, i32 0
  %20 = load %class.NExpression**, %class.NExpression*** %19, align 8
  %21 = call %class.NExpression** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(%class.NExpression** %18, %class.NExpression** %20, %class.NExpression** %16)
  ret %class.NExpression** %21
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %8 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %9 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %4, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %9, align 8
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %5, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %10, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %11 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %7 to i8*
  %12 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %8 to i8*
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %16 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %7, i32 0, i32 0
  %17 = load %class.NExpression**, %class.NExpression*** %16, align 8
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %8, i32 0, i32 0
  %19 = load %class.NExpression**, %class.NExpression*** %18, align 8
  %20 = call %class.NExpression** @_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NExpression** %17, %class.NExpression** %19, %class.NExpression** %15)
  ret %class.NExpression** %20
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %8 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %9 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %10 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %11 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %4, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %11, align 8
  %12 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %5, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %12, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %13 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %8 to i8*
  %14 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %8, i32 0, i32 0
  %16 = load %class.NExpression**, %class.NExpression*** %15, align 8
  %17 = call %class.NExpression** @_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_(%class.NExpression** %16)
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %7, i32 0, i32 0
  store %class.NExpression** %17, %class.NExpression*** %18, align 8
  %19 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %10 to i8*
  %20 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %19, i8* align 8 %20, i64 8, i1 false)
  %21 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %10, i32 0, i32 0
  %22 = load %class.NExpression**, %class.NExpression*** %21, align 8
  %23 = call %class.NExpression** @_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_(%class.NExpression** %22)
  %24 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %9, i32 0, i32 0
  store %class.NExpression** %23, %class.NExpression*** %24, align 8
  %25 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %26 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %7, i32 0, i32 0
  %27 = load %class.NExpression**, %class.NExpression*** %26, align 8
  %28 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %9, i32 0, i32 0
  %29 = load %class.NExpression**, %class.NExpression*** %28, align 8
  %30 = call %class.NExpression** @_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(%class.NExpression** %27, %class.NExpression** %29, %class.NExpression** %25)
  ret %class.NExpression** %30
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEPS3_ET1_T0_SC_SB_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %5 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %8 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %9 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %4, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %9, align 8
  %10 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %5, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %10, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %11 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %7 to i8*
  %12 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %7, i32 0, i32 0
  %14 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %15 = call %class.NExpression** @_ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(%class.NExpression** %14)
  %16 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %8 to i8*
  %17 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %16, i8* align 8 %17, i64 8, i1 false)
  %18 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %8, i32 0, i32 0
  %19 = load %class.NExpression**, %class.NExpression*** %18, align 8
  %20 = call %class.NExpression** @_ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(%class.NExpression** %19)
  %21 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %22 = call %class.NExpression** @_ZSt12__niter_baseIPP11NExpressionET_S3_(%class.NExpression** %21)
  %23 = call %class.NExpression** @_ZSt13__copy_move_aILb0EPKP11NExpressionPS1_ET1_T0_S6_S5_(%class.NExpression** %15, %class.NExpression** %20, %class.NExpression** %22)
  ret %class.NExpression** %23
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS3_SaIS3_EEEEET_SA_(%class.NExpression**) #7 comdat {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %3, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %4, align 8
  %5 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %2 to i8*
  %6 = bitcast %"class.__gnu_cxx::__normal_iterator.13"* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %5, i8* align 8 %6, i64 8, i1 false)
  %7 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %2, i32 0, i32 0
  %8 = load %class.NExpression**, %class.NExpression*** %7, align 8
  ret %class.NExpression** %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt13__copy_move_aILb0EPKP11NExpressionPS1_ET1_T0_S6_S5_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %class.NExpression**, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca i8, align 1
  store %class.NExpression** %0, %class.NExpression*** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  store i8 1, i8* %7, align 1
  %8 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %9 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %10 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %11 = call %class.NExpression** @_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(%class.NExpression** %8, %class.NExpression** %9, %class.NExpression** %10)
  ret %class.NExpression** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt12__niter_baseIPKP11NExpressionSt6vectorIS1_SaIS1_EEET_N9__gnu_cxx17__normal_iteratorIS7_T0_EE(%class.NExpression**) #7 comdat {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.13", align 8
  %3 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %2, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %3, align 8
  %4 = call dereferenceable(8) %class.NExpression*** @_ZNK9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.13"* %2) #3
  %5 = load %class.NExpression**, %class.NExpression*** %4, align 8
  ret %class.NExpression** %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt12__niter_baseIPP11NExpressionET_S3_(%class.NExpression**) #7 comdat {
  %2 = alloca %class.NExpression**, align 8
  store %class.NExpression** %0, %class.NExpression*** %2, align 8
  %3 = load %class.NExpression**, %class.NExpression*** %2, align 8
  ret %class.NExpression** %3
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #7 comdat align 2 {
  %4 = alloca %class.NExpression**, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca i64, align 8
  store %class.NExpression** %0, %class.NExpression*** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %9 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %10 = ptrtoint %class.NExpression** %8 to i64
  %11 = ptrtoint %class.NExpression** %9 to i64
  %12 = sub i64 %10, %11
  %13 = sdiv exact i64 %12, 8
  store i64 %13, i64* %7, align 8
  %14 = load i64, i64* %7, align 8
  %15 = icmp ne i64 %14, 0
  br i1 %15, label %16, label %23

; <label>:16:                                     ; preds = %3
  %17 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %18 = bitcast %class.NExpression** %17 to i8*
  %19 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %20 = bitcast %class.NExpression** %19 to i8*
  %21 = load i64, i64* %7, align 8
  %22 = mul i64 8, %21
  call void @llvm.memmove.p0i8.p0i8.i64(i8* align 8 %18, i8* align 8 %20, i64 %22, i1 false)
  br label %23

; <label>:23:                                     ; preds = %16, %3
  %24 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %25 = load i64, i64* %7, align 8
  %26 = getelementptr inbounds %class.NExpression*, %class.NExpression** %24, i64 %25
  ret %class.NExpression** %26
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NExpression*** @_ZNK9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.13"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.13"*, align 8
  store %"class.__gnu_cxx::__normal_iterator.13"* %0, %"class.__gnu_cxx::__normal_iterator.13"** %2, align 8
  %3 = load %"class.__gnu_cxx::__normal_iterator.13"*, %"class.__gnu_cxx::__normal_iterator.13"** %2, align 8
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %3, i32 0, i32 0
  ret %class.NExpression*** %4
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx17__normal_iteratorIPKP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS4_(%"class.__gnu_cxx::__normal_iterator.13"*, %class.NExpression*** dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.13"*, align 8
  %4 = alloca %class.NExpression***, align 8
  store %"class.__gnu_cxx::__normal_iterator.13"* %0, %"class.__gnu_cxx::__normal_iterator.13"** %3, align 8
  store %class.NExpression*** %1, %class.NExpression**** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator.13"*, %"class.__gnu_cxx::__normal_iterator.13"** %3, align 8
  %6 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.13", %"class.__gnu_cxx::__normal_iterator.13"* %5, i32 0, i32 0
  %7 = load %class.NExpression***, %class.NExpression**** %4, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %7, align 8
  store %class.NExpression** %8, %class.NExpression*** %6, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.9"*, %class.NExpression**, i64) #4 comdat align 2 {
  %4 = alloca %"struct.std::_Vector_base.9"*, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca i64, align 8
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %4, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %9 = icmp ne %class.NExpression** %8, null
  br i1 %9, label %10, label %15

; <label>:10:                                     ; preds = %3
  %11 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %7, i32 0, i32 0
  %12 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %11 to %"class.std::allocator.10"*
  %13 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %14 = load i64, i64* %6, align 8
  call void @_ZNSt16allocator_traitsISaIP11NExpressionEE10deallocateERS2_PS1_m(%"class.std::allocator.10"* dereferenceable(1) %12, %class.NExpression** %13, i64 %14)
  br label %15

; <label>:15:                                     ; preds = %10, %3
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP11NExpressionEE10deallocateERS2_PS1_m(%"class.std::allocator.10"* dereferenceable(1), %class.NExpression**, i64) #4 comdat align 2 {
  %4 = alloca %"class.std::allocator.10"*, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca i64, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %4, align 8
  %8 = bitcast %"class.std::allocator.10"* %7 to %"class.__gnu_cxx::new_allocator.11"*
  %9 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %10 = load i64, i64* %6, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator.11"* %8, %class.NExpression** %9, i64 %10)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE10deallocateEPS2_m(%"class.__gnu_cxx::new_allocator.11"*, %class.NExpression**, i64) #7 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca i64, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store i64 %2, i64* %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %4, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %9 = bitcast %class.NExpression** %8 to i8*
  call void @_ZdlPv(i8* %9) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN15NBinaryOperatorD2Ev(%class.NBinaryOperator*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NBinaryOperator*, align 8
  store %class.NBinaryOperator* %0, %class.NBinaryOperator** %2, align 8
  %3 = load %class.NBinaryOperator*, %class.NBinaryOperator** %2, align 8
  %4 = bitcast %class.NBinaryOperator* %3 to %class.NExpression*
  call void @_ZN11NExpressionD2Ev(%class.NExpression* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN15NBinaryOperatorD0Ev(%class.NBinaryOperator*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %class.NBinaryOperator*, align 8
  store %class.NBinaryOperator* %0, %class.NBinaryOperator** %2, align 8
  %3 = load %class.NBinaryOperator*, %class.NBinaryOperator** %2, align 8
  call void @_ZN15NBinaryOperatorD2Ev(%class.NBinaryOperator* %3) #3
  %4 = bitcast %class.NBinaryOperator* %3 to i8*
  call void @_ZdlPv(i8* %4) #14
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %"class.llvm::Value"* @_ZN15NBinaryOperator7codeGenER14CodeGenContext(%class.NBinaryOperator*, %class.CodeGenContext* nonnull) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.llvm::Value"*, align 8
  %4 = alloca %class.NBinaryOperator*, align 8
  %5 = alloca %class.CodeGenContext*, align 8
  store %class.NBinaryOperator* %0, %class.NBinaryOperator** %4, align 8
  store %class.CodeGenContext* %1, %class.CodeGenContext** %5, align 8
  %6 = load %class.NBinaryOperator*, %class.NBinaryOperator** %4, align 8
  call void @llvm.trap()
  unreachable
                                                  ; No predecessors!
  %8 = load %"class.llvm::Value"*, %"class.llvm::Value"** %3, align 8
  ret %"class.llvm::Value"* %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(%class.NExpression**, %class.NExpression**, %"class.std::allocator.10"* dereferenceable(1)) #4 comdat {
  %4 = alloca %class.NExpression**, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %"class.std::allocator.10"*, align 8
  store %class.NExpression** %0, %class.NExpression*** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %"class.std::allocator.10"* %2, %"class.std::allocator.10"** %6, align 8
  %7 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %5, align 8
  call void @_ZSt8_DestroyIPP11NExpressionEvT_S3_(%class.NExpression** %7, %class.NExpression** %8)
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZSt8_DestroyIPP11NExpressionEvT_S3_(%class.NExpression**, %class.NExpression**) #4 comdat {
  %3 = alloca %class.NExpression**, align 8
  %4 = alloca %class.NExpression**, align 8
  store %class.NExpression** %0, %class.NExpression*** %3, align 8
  store %class.NExpression** %1, %class.NExpression*** %4, align 8
  %5 = load %class.NExpression**, %class.NExpression*** %3, align 8
  %6 = load %class.NExpression**, %class.NExpression*** %4, align 8
  call void @_ZNSt12_Destroy_auxILb1EE9__destroyIPP11NExpressionEEvT_S5_(%class.NExpression** %5, %class.NExpression** %6)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Destroy_auxILb1EE9__destroyIPP11NExpressionEEvT_S5_(%class.NExpression**, %class.NExpression**) #7 comdat align 2 {
  %3 = alloca %class.NExpression**, align 8
  %4 = alloca %class.NExpression**, align 8
  store %class.NExpression** %0, %class.NExpression*** %3, align 8
  store %class.NExpression** %1, %class.NExpression*** %4, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EEC2Ev(%"struct.std::_Vector_base.9"*) unnamed_addr #4 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base.9"*, align 8
  store %"struct.std::_Vector_base.9"* %0, %"struct.std::_Vector_base.9"** %2, align 8
  %3 = load %"struct.std::_Vector_base.9"*, %"struct.std::_Vector_base.9"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %3, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %4)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"** %2, align 8
  %3 = load %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"*, %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"** %2, align 8
  %4 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %3 to %"class.std::allocator.10"*
  call void @_ZNSaIP11NExpressionEC2Ev(%"class.std::allocator.10"* %4) #3
  %5 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %3, i32 0, i32 0
  store %class.NExpression** null, %class.NExpression*** %5, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %3, i32 0, i32 1
  store %class.NExpression** null, %class.NExpression*** %6, align 8
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %3, i32 0, i32 2
  store %class.NExpression** null, %class.NExpression*** %7, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP11NExpressionEC2Ev(%"class.std::allocator.10"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.std::allocator.10"*, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %2, align 8
  %3 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %2, align 8
  %4 = bitcast %"class.std::allocator.10"* %3 to %"class.__gnu_cxx::new_allocator.11"*
  call void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2Ev(%"class.__gnu_cxx::new_allocator.11"* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionEC2Ev(%"class.__gnu_cxx::new_allocator.11"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %2, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %"class.std::allocator.5"* dereferenceable(1)) #4 comdat {
  %4 = alloca %class.NVariableDeclaration**, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %"class.std::allocator.5"*, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %"class.std::allocator.5"* %2, %"class.std::allocator.5"** %6, align 8
  %7 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  call void @_ZSt8_DestroyIPP20NVariableDeclarationEvT_S3_(%class.NVariableDeclaration** %7, %class.NVariableDeclaration** %8)
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZSt8_DestroyIPP20NVariableDeclarationEvT_S3_(%class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %3 = alloca %class.NVariableDeclaration**, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %3, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %4, align 8
  %5 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %3, align 8
  %6 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  call void @_ZNSt12_Destroy_auxILb1EE9__destroyIPP20NVariableDeclarationEEvT_S5_(%class.NVariableDeclaration** %5, %class.NVariableDeclaration** %6)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Destroy_auxILb1EE9__destroyIPP20NVariableDeclarationEEvT_S5_(%class.NVariableDeclaration**, %class.NVariableDeclaration**) #7 comdat align 2 {
  %3 = alloca %class.NVariableDeclaration**, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %3, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %4, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator"* dereferenceable(1), %class.NStatement**, %class.NStatement** dereferenceable(8)) #4 comdat align 2 {
  %4 = alloca %"class.std::allocator"*, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca %class.NStatement**, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  %7 = load %"class.std::allocator"*, %"class.std::allocator"** %4, align 8
  %8 = bitcast %"class.std::allocator"* %7 to %"class.__gnu_cxx::new_allocator"*
  %9 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %10 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %11 = call dereferenceable(8) %class.NStatement** @_ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(%class.NStatement** dereferenceable(8) %10) #3
  call void @_ZN9__gnu_cxx13new_allocatorIP10NStatementE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator"* %8, %class.NStatement** %9, %class.NStatement** dereferenceable(8) %11)
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP10NStatementSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(%"class.std::vector"*, %class.NStatement**, %class.NStatement** dereferenceable(8)) #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.14", align 8
  %5 = alloca %"class.std::vector"*, align 8
  %6 = alloca %class.NStatement**, align 8
  %7 = alloca i64, align 8
  %8 = alloca %class.NStatement**, align 8
  %9 = alloca %class.NStatement**, align 8
  %10 = alloca i64, align 8
  %11 = alloca %"class.__gnu_cxx::__normal_iterator.14", align 8
  %12 = alloca %class.NStatement**, align 8
  %13 = alloca %class.NStatement**, align 8
  %14 = alloca i8*
  %15 = alloca i32
  %16 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %4, i32 0, i32 0
  store %class.NStatement** %1, %class.NStatement*** %16, align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %5, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  %17 = load %"class.std::vector"*, %"class.std::vector"** %5, align 8
  %18 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE12_M_check_lenEmPKc(%"class.std::vector"* %17, i64 1, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.8, i32 0, i32 0))
  store i64 %18, i64* %7, align 8
  %19 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %20 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %19, i32 0, i32 0
  %21 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %20, i32 0, i32 0
  %22 = load %class.NStatement**, %class.NStatement*** %21, align 8
  store %class.NStatement** %22, %class.NStatement*** %8, align 8
  %23 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %24 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %23, i32 0, i32 0
  %25 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %24, i32 0, i32 1
  %26 = load %class.NStatement**, %class.NStatement*** %25, align 8
  store %class.NStatement** %26, %class.NStatement*** %9, align 8
  %27 = call %class.NStatement** @_ZNSt6vectorIP10NStatementSaIS1_EE5beginEv(%"class.std::vector"* %17) #3
  %28 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %11, i32 0, i32 0
  store %class.NStatement** %27, %class.NStatement*** %28, align 8
  %29 = call i64 @_ZN9__gnu_cxxmiIPP10NStatementSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(%"class.__gnu_cxx::__normal_iterator.14"* dereferenceable(8) %4, %"class.__gnu_cxx::__normal_iterator.14"* dereferenceable(8) %11) #3
  store i64 %29, i64* %10, align 8
  %30 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %31 = load i64, i64* %7, align 8
  %32 = call %class.NStatement** @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base"* %30, i64 %31)
  store %class.NStatement** %32, %class.NStatement*** %12, align 8
  %33 = load %class.NStatement**, %class.NStatement*** %12, align 8
  store %class.NStatement** %33, %class.NStatement*** %13, align 8
  %34 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %35 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %34, i32 0, i32 0
  %36 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %35 to %"class.std::allocator"*
  %37 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %38 = load i64, i64* %10, align 8
  %39 = getelementptr inbounds %class.NStatement*, %class.NStatement** %37, i64 %38
  %40 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %41 = call dereferenceable(8) %class.NStatement** @_ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(%class.NStatement** dereferenceable(8) %40) #3
  invoke void @_ZNSt16allocator_traitsISaIP10NStatementEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator"* dereferenceable(1) %36, %class.NStatement** %39, %class.NStatement** dereferenceable(8) %41)
          to label %42 unwind label %61

; <label>:42:                                     ; preds = %3
  store %class.NStatement** null, %class.NStatement*** %13, align 8
  %43 = load %class.NStatement**, %class.NStatement*** %8, align 8
  %44 = call dereferenceable(8) %class.NStatement*** @_ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.14"* %4) #3
  %45 = load %class.NStatement**, %class.NStatement*** %44, align 8
  %46 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %47 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %48 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %47) #3
  %49 = invoke %class.NStatement** @_ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NStatement** %43, %class.NStatement** %45, %class.NStatement** %46, %"class.std::allocator"* dereferenceable(1) %48)
          to label %50 unwind label %61

; <label>:50:                                     ; preds = %42
  store %class.NStatement** %49, %class.NStatement*** %13, align 8
  %51 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %52 = getelementptr inbounds %class.NStatement*, %class.NStatement** %51, i32 1
  store %class.NStatement** %52, %class.NStatement*** %13, align 8
  %53 = call dereferenceable(8) %class.NStatement*** @_ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.14"* %4) #3
  %54 = load %class.NStatement**, %class.NStatement*** %53, align 8
  %55 = load %class.NStatement**, %class.NStatement*** %9, align 8
  %56 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %57 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %58 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %57) #3
  %59 = invoke %class.NStatement** @_ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NStatement** %54, %class.NStatement** %55, %class.NStatement** %56, %"class.std::allocator"* dereferenceable(1) %58)
          to label %60 unwind label %61

; <label>:60:                                     ; preds = %50
  store %class.NStatement** %59, %class.NStatement*** %13, align 8
  br label %94

; <label>:61:                                     ; preds = %50, %42, %3
  %62 = landingpad { i8*, i32 }
          catch i8* null
  %63 = extractvalue { i8*, i32 } %62, 0
  store i8* %63, i8** %14, align 8
  %64 = extractvalue { i8*, i32 } %62, 1
  store i32 %64, i32* %15, align 4
  br label %65

; <label>:65:                                     ; preds = %61
  %66 = load i8*, i8** %14, align 8
  %67 = call i8* @__cxa_begin_catch(i8* %66) #3
  %68 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %69 = icmp ne %class.NStatement** %68, null
  br i1 %69, label %82, label %70

; <label>:70:                                     ; preds = %65
  %71 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %72 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %71, i32 0, i32 0
  %73 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %72 to %"class.std::allocator"*
  %74 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %75 = load i64, i64* %10, align 8
  %76 = getelementptr inbounds %class.NStatement*, %class.NStatement** %74, i64 %75
  invoke void @_ZNSt16allocator_traitsISaIP10NStatementEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator"* dereferenceable(1) %73, %class.NStatement** %76)
          to label %77 unwind label %78

; <label>:77:                                     ; preds = %70
  br label %88

; <label>:78:                                     ; preds = %92, %88, %82, %70
  %79 = landingpad { i8*, i32 }
          cleanup
  %80 = extractvalue { i8*, i32 } %79, 0
  store i8* %80, i8** %14, align 8
  %81 = extractvalue { i8*, i32 } %79, 1
  store i32 %81, i32* %15, align 4
  invoke void @__cxa_end_catch()
          to label %93 unwind label %129

; <label>:82:                                     ; preds = %65
  %83 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %84 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %85 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %86 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %85) #3
  invoke void @_ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(%class.NStatement** %83, %class.NStatement** %84, %"class.std::allocator"* dereferenceable(1) %86)
          to label %87 unwind label %78

; <label>:87:                                     ; preds = %82
  br label %88

; <label>:88:                                     ; preds = %87, %77
  %89 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %90 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %91 = load i64, i64* %7, align 8
  invoke void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"* %89, %class.NStatement** %90, i64 %91)
          to label %92 unwind label %78

; <label>:92:                                     ; preds = %88
  invoke void @__cxa_rethrow() #16
          to label %132 unwind label %78

; <label>:93:                                     ; preds = %78
  br label %124

; <label>:94:                                     ; preds = %60
  %95 = load %class.NStatement**, %class.NStatement*** %8, align 8
  %96 = load %class.NStatement**, %class.NStatement*** %9, align 8
  %97 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %98 = call dereferenceable(1) %"class.std::allocator"* @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %97) #3
  call void @_ZSt8_DestroyIPP10NStatementS1_EvT_S3_RSaIT0_E(%class.NStatement** %95, %class.NStatement** %96, %"class.std::allocator"* dereferenceable(1) %98)
  %99 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %100 = load %class.NStatement**, %class.NStatement*** %8, align 8
  %101 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %102 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %101, i32 0, i32 0
  %103 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %102, i32 0, i32 2
  %104 = load %class.NStatement**, %class.NStatement*** %103, align 8
  %105 = load %class.NStatement**, %class.NStatement*** %8, align 8
  %106 = ptrtoint %class.NStatement** %104 to i64
  %107 = ptrtoint %class.NStatement** %105 to i64
  %108 = sub i64 %106, %107
  %109 = sdiv exact i64 %108, 8
  call void @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base"* %99, %class.NStatement** %100, i64 %109)
  %110 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %111 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %112 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %111, i32 0, i32 0
  %113 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %112, i32 0, i32 0
  store %class.NStatement** %110, %class.NStatement*** %113, align 8
  %114 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %115 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %116 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %115, i32 0, i32 0
  %117 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %116, i32 0, i32 1
  store %class.NStatement** %114, %class.NStatement*** %117, align 8
  %118 = load %class.NStatement**, %class.NStatement*** %12, align 8
  %119 = load i64, i64* %7, align 8
  %120 = getelementptr inbounds %class.NStatement*, %class.NStatement** %118, i64 %119
  %121 = bitcast %"class.std::vector"* %17 to %"struct.std::_Vector_base"*
  %122 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %121, i32 0, i32 0
  %123 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %122, i32 0, i32 2
  store %class.NStatement** %120, %class.NStatement*** %123, align 8
  ret void

; <label>:124:                                    ; preds = %93
  %125 = load i8*, i8** %14, align 8
  %126 = load i32, i32* %15, align 4
  %127 = insertvalue { i8*, i32 } undef, i8* %125, 0
  %128 = insertvalue { i8*, i32 } %127, i32 %126, 1
  resume { i8*, i32 } %128

; <label>:129:                                    ; preds = %78
  %130 = landingpad { i8*, i32 }
          catch i8* null
  %131 = extractvalue { i8*, i32 } %130, 0
  call void @__clang_call_terminate(i8* %131) #10
  unreachable

; <label>:132:                                    ; preds = %92
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZNSt6vectorIP10NStatementSaIS1_EE3endEv(%"class.std::vector"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.14", align 8
  %3 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %3, align 8
  %4 = load %"class.std::vector"*, %"class.std::vector"** %3, align 8
  %5 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %6, i32 0, i32 1
  call void @_ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.14"* %2, %class.NStatement*** dereferenceable(8) %7) #3
  %8 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %2, i32 0, i32 0
  %9 = load %class.NStatement**, %class.NStatement*** %8, align 8
  ret %class.NStatement** %9
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP10NStatementE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator"*, %class.NStatement**, %class.NStatement** dereferenceable(8)) #7 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca %class.NStatement**, align 8
  store %"class.__gnu_cxx::new_allocator"* %0, %"class.__gnu_cxx::new_allocator"** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator"*, %"class.__gnu_cxx::new_allocator"** %4, align 8
  %8 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %9 = bitcast %class.NStatement** %8 to i8*
  %10 = bitcast i8* %9 to %class.NStatement**
  %11 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %12 = call dereferenceable(8) %class.NStatement** @_ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(%class.NStatement** dereferenceable(8) %11) #3
  %13 = load %class.NStatement*, %class.NStatement** %12, align 8
  store %class.NStatement* %13, %class.NStatement** %10, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NStatement** @_ZSt7forwardIRKP10NStatementEOT_RNSt16remove_referenceIS4_E4typeE(%class.NStatement** dereferenceable(8)) #7 comdat {
  %2 = alloca %class.NStatement**, align 8
  store %class.NStatement** %0, %class.NStatement*** %2, align 8
  %3 = load %class.NStatement**, %class.NStatement*** %2, align 8
  ret %class.NStatement** %3
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE12_M_check_lenEmPKc(%"class.std::vector"*, i64, i8*) #4 comdat align 2 {
  %4 = alloca %"class.std::vector"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i8*, align 8
  %7 = alloca i64, align 8
  %8 = alloca i64, align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %4, align 8
  store i64 %1, i64* %5, align 8
  store i8* %2, i8** %6, align 8
  %9 = load %"class.std::vector"*, %"class.std::vector"** %4, align 8
  %10 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(%"class.std::vector"* %9) #3
  %11 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(%"class.std::vector"* %9) #3
  %12 = sub i64 %10, %11
  %13 = load i64, i64* %5, align 8
  %14 = icmp ult i64 %12, %13
  br i1 %14, label %15, label %17

; <label>:15:                                     ; preds = %3
  %16 = load i8*, i8** %6, align 8
  call void @_ZSt20__throw_length_errorPKc(i8* %16) #16
  unreachable

; <label>:17:                                     ; preds = %3
  %18 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(%"class.std::vector"* %9) #3
  %19 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(%"class.std::vector"* %9) #3
  store i64 %19, i64* %8, align 8
  %20 = call dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8) %8, i64* dereferenceable(8) %5)
  %21 = load i64, i64* %20, align 8
  %22 = add i64 %18, %21
  store i64 %22, i64* %7, align 8
  %23 = load i64, i64* %7, align 8
  %24 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(%"class.std::vector"* %9) #3
  %25 = icmp ult i64 %23, %24
  br i1 %25, label %30, label %26

; <label>:26:                                     ; preds = %17
  %27 = load i64, i64* %7, align 8
  %28 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(%"class.std::vector"* %9) #3
  %29 = icmp ugt i64 %27, %28
  br i1 %29, label %30, label %32

; <label>:30:                                     ; preds = %26, %17
  %31 = call i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(%"class.std::vector"* %9) #3
  br label %34

; <label>:32:                                     ; preds = %26
  %33 = load i64, i64* %7, align 8
  br label %34

; <label>:34:                                     ; preds = %32, %30
  %35 = phi i64 [ %31, %30 ], [ %33, %32 ]
  ret i64 %35
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZN9__gnu_cxxmiIPP10NStatementSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(%"class.__gnu_cxx::__normal_iterator.14"* dereferenceable(8), %"class.__gnu_cxx::__normal_iterator.14"* dereferenceable(8)) #7 comdat {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.14"*, align 8
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.14"*, align 8
  store %"class.__gnu_cxx::__normal_iterator.14"* %0, %"class.__gnu_cxx::__normal_iterator.14"** %3, align 8
  store %"class.__gnu_cxx::__normal_iterator.14"* %1, %"class.__gnu_cxx::__normal_iterator.14"** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator.14"*, %"class.__gnu_cxx::__normal_iterator.14"** %3, align 8
  %6 = call dereferenceable(8) %class.NStatement*** @_ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.14"* %5) #3
  %7 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %8 = load %"class.__gnu_cxx::__normal_iterator.14"*, %"class.__gnu_cxx::__normal_iterator.14"** %4, align 8
  %9 = call dereferenceable(8) %class.NStatement*** @_ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.14"* %8) #3
  %10 = load %class.NStatement**, %class.NStatement*** %9, align 8
  %11 = ptrtoint %class.NStatement** %7 to i64
  %12 = ptrtoint %class.NStatement** %10 to i64
  %13 = sub i64 %11, %12
  %14 = sdiv exact i64 %13, 8
  ret i64 %14
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZNSt6vectorIP10NStatementSaIS1_EE5beginEv(%"class.std::vector"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.14", align 8
  %3 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %3, align 8
  %4 = load %"class.std::vector"*, %"class.std::vector"** %3, align 8
  %5 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %6, i32 0, i32 0
  call void @_ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.14"* %2, %class.NStatement*** dereferenceable(8) %7) #3
  %8 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %2, i32 0, i32 0
  %9 = load %class.NStatement**, %class.NStatement*** %8, align 8
  ret %class.NStatement** %9
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZNSt12_Vector_baseIP10NStatementSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base"*, i64) #4 comdat align 2 {
  %3 = alloca %"struct.std::_Vector_base"*, align 8
  %4 = alloca i64, align 8
  store %"struct.std::_Vector_base"* %0, %"struct.std::_Vector_base"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"struct.std::_Vector_base"*, %"struct.std::_Vector_base"** %3, align 8
  %6 = load i64, i64* %4, align 8
  %7 = icmp ne i64 %6, 0
  br i1 %7, label %8, label %13

; <label>:8:                                      ; preds = %2
  %9 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %10 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %9 to %"class.std::allocator"*
  %11 = load i64, i64* %4, align 8
  %12 = call %class.NStatement** @_ZNSt16allocator_traitsISaIP10NStatementEE8allocateERS2_m(%"class.std::allocator"* dereferenceable(1) %10, i64 %11)
  br label %14

; <label>:13:                                     ; preds = %2
  br label %14

; <label>:14:                                     ; preds = %13, %8
  %15 = phi %class.NStatement** [ %12, %8 ], [ null, %13 ]
  ret %class.NStatement** %15
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt34__uninitialized_move_if_noexcept_aIPP10NStatementS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NStatement**, %class.NStatement**, %class.NStatement**, %"class.std::allocator"* dereferenceable(1)) #4 comdat {
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca %class.NStatement**, align 8
  %7 = alloca %class.NStatement**, align 8
  %8 = alloca %"class.std::allocator"*, align 8
  %9 = alloca %"class.std::move_iterator", align 8
  %10 = alloca %"class.std::move_iterator", align 8
  store %class.NStatement** %0, %class.NStatement*** %5, align 8
  store %class.NStatement** %1, %class.NStatement*** %6, align 8
  store %class.NStatement** %2, %class.NStatement*** %7, align 8
  store %"class.std::allocator"* %3, %"class.std::allocator"** %8, align 8
  %11 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %12 = call %class.NStatement** @_ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_(%class.NStatement** %11)
  %13 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %9, i32 0, i32 0
  store %class.NStatement** %12, %class.NStatement*** %13, align 8
  %14 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %15 = call %class.NStatement** @_ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_(%class.NStatement** %14)
  %16 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %10, i32 0, i32 0
  store %class.NStatement** %15, %class.NStatement*** %16, align 8
  %17 = load %class.NStatement**, %class.NStatement*** %7, align 8
  %18 = load %"class.std::allocator"*, %"class.std::allocator"** %8, align 8
  %19 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %9, i32 0, i32 0
  %20 = load %class.NStatement**, %class.NStatement*** %19, align 8
  %21 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %10, i32 0, i32 0
  %22 = load %class.NStatement**, %class.NStatement*** %21, align 8
  %23 = call %class.NStatement** @_ZSt22__uninitialized_copy_aISt13move_iteratorIPP10NStatementES3_S2_ET0_T_S6_S5_RSaIT1_E(%class.NStatement** %20, %class.NStatement** %22, %class.NStatement** %17, %"class.std::allocator"* dereferenceable(1) %18)
  ret %class.NStatement** %23
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NStatement*** @_ZNK9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.14"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.14"*, align 8
  store %"class.__gnu_cxx::__normal_iterator.14"* %0, %"class.__gnu_cxx::__normal_iterator.14"** %2, align 8
  %3 = load %"class.__gnu_cxx::__normal_iterator.14"*, %"class.__gnu_cxx::__normal_iterator.14"** %2, align 8
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %3, i32 0, i32 0
  ret %class.NStatement*** %4
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP10NStatementEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator"* dereferenceable(1), %class.NStatement**) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator"*, align 8
  %4 = alloca %class.NStatement**, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %3, align 8
  store %class.NStatement** %1, %class.NStatement*** %4, align 8
  %5 = load %"class.std::allocator"*, %"class.std::allocator"** %3, align 8
  %6 = bitcast %"class.std::allocator"* %5 to %"class.__gnu_cxx::new_allocator"*
  %7 = load %class.NStatement**, %class.NStatement*** %4, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIP10NStatementE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator"* %6, %class.NStatement** %7)
  ret void
}

declare dso_local void @__cxa_rethrow()

declare dso_local void @__cxa_end_catch()

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE8max_sizeEv(%"class.std::vector"*) #7 comdat align 2 {
  %2 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %2, align 8
  %3 = load %"class.std::vector"*, %"class.std::vector"** %2, align 8
  %4 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %5 = call dereferenceable(1) %"class.std::allocator"* @_ZNKSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %4) #3
  %6 = call i64 @_ZNSt16allocator_traitsISaIP10NStatementEE8max_sizeERKS2_(%"class.std::allocator"* dereferenceable(1) %5) #3
  ret i64 %6
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP10NStatementSaIS1_EE4sizeEv(%"class.std::vector"*) #7 comdat align 2 {
  %2 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %0, %"class.std::vector"** %2, align 8
  %3 = load %"class.std::vector"*, %"class.std::vector"** %2, align 8
  %4 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %5 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %5, i32 0, i32 1
  %7 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %8 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %9 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %8, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl", %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %9, i32 0, i32 0
  %11 = load %class.NStatement**, %class.NStatement*** %10, align 8
  %12 = ptrtoint %class.NStatement** %7 to i64
  %13 = ptrtoint %class.NStatement** %11 to i64
  %14 = sub i64 %12, %13
  %15 = sdiv exact i64 %14, 8
  ret i64 %15
}

; Function Attrs: noreturn
declare dso_local void @_ZSt20__throw_length_errorPKc(i8*) #12

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8), i64* dereferenceable(8)) #7 comdat {
  %3 = alloca i64*, align 8
  %4 = alloca i64*, align 8
  %5 = alloca i64*, align 8
  store i64* %0, i64** %4, align 8
  store i64* %1, i64** %5, align 8
  %6 = load i64*, i64** %4, align 8
  %7 = load i64, i64* %6, align 8
  %8 = load i64*, i64** %5, align 8
  %9 = load i64, i64* %8, align 8
  %10 = icmp ult i64 %7, %9
  br i1 %10, label %11, label %13

; <label>:11:                                     ; preds = %2
  %12 = load i64*, i64** %5, align 8
  store i64* %12, i64** %3, align 8
  br label %15

; <label>:13:                                     ; preds = %2
  %14 = load i64*, i64** %4, align 8
  store i64* %14, i64** %3, align 8
  br label %15

; <label>:15:                                     ; preds = %13, %11
  %16 = load i64*, i64** %3, align 8
  ret i64* %16
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNSt16allocator_traitsISaIP10NStatementEE8max_sizeERKS2_(%"class.std::allocator"* dereferenceable(1)) #7 comdat align 2 {
  %2 = alloca %"class.std::allocator"*, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %2, align 8
  %3 = load %"class.std::allocator"*, %"class.std::allocator"** %2, align 8
  %4 = bitcast %"class.std::allocator"* %3 to %"class.__gnu_cxx::new_allocator"*
  %5 = call i64 @_ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv(%"class.__gnu_cxx::new_allocator"* %4) #3
  ret i64 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(1) %"class.std::allocator"* @_ZNKSt12_Vector_baseIP10NStatementSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"*) #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %0, %"struct.std::_Vector_base"** %2, align 8
  %3 = load %"struct.std::_Vector_base"*, %"struct.std::_Vector_base"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base", %"struct.std::_Vector_base"* %3, i32 0, i32 0
  %5 = bitcast %"struct.std::_Vector_base<NStatement *, std::allocator<NStatement *> >::_Vector_impl"* %4 to %"class.std::allocator"*
  ret %"class.std::allocator"* %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv(%"class.__gnu_cxx::new_allocator"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  store %"class.__gnu_cxx::new_allocator"* %0, %"class.__gnu_cxx::new_allocator"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator"*, %"class.__gnu_cxx::new_allocator"** %2, align 8
  ret i64 2305843009213693951
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx17__normal_iteratorIPP10NStatementSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.14"*, %class.NStatement*** dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.14"*, align 8
  %4 = alloca %class.NStatement***, align 8
  store %"class.__gnu_cxx::__normal_iterator.14"* %0, %"class.__gnu_cxx::__normal_iterator.14"** %3, align 8
  store %class.NStatement*** %1, %class.NStatement**** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator.14"*, %"class.__gnu_cxx::__normal_iterator.14"** %3, align 8
  %6 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.14", %"class.__gnu_cxx::__normal_iterator.14"* %5, i32 0, i32 0
  %7 = load %class.NStatement***, %class.NStatement**** %4, align 8
  %8 = load %class.NStatement**, %class.NStatement*** %7, align 8
  store %class.NStatement** %8, %class.NStatement*** %6, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZNSt16allocator_traitsISaIP10NStatementEE8allocateERS2_m(%"class.std::allocator"* dereferenceable(1), i64) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator"*, align 8
  %4 = alloca i64, align 8
  store %"class.std::allocator"* %0, %"class.std::allocator"** %3, align 8
  store i64 %1, i64* %4, align 8
  %5 = load %"class.std::allocator"*, %"class.std::allocator"** %3, align 8
  %6 = bitcast %"class.std::allocator"* %5 to %"class.__gnu_cxx::new_allocator"*
  %7 = load i64, i64* %4, align 8
  %8 = call %class.NStatement** @_ZN9__gnu_cxx13new_allocatorIP10NStatementE8allocateEmPKv(%"class.__gnu_cxx::new_allocator"* %6, i64 %7, i8* null)
  ret %class.NStatement** %8
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZN9__gnu_cxx13new_allocatorIP10NStatementE8allocateEmPKv(%"class.__gnu_cxx::new_allocator"*, i64, i8*) #4 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i8*, align 8
  store %"class.__gnu_cxx::new_allocator"* %0, %"class.__gnu_cxx::new_allocator"** %4, align 8
  store i64 %1, i64* %5, align 8
  store i8* %2, i8** %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator"*, %"class.__gnu_cxx::new_allocator"** %4, align 8
  %8 = load i64, i64* %5, align 8
  %9 = call i64 @_ZNK9__gnu_cxx13new_allocatorIP10NStatementE8max_sizeEv(%"class.__gnu_cxx::new_allocator"* %7) #3
  %10 = icmp ugt i64 %8, %9
  br i1 %10, label %11, label %12

; <label>:11:                                     ; preds = %3
  call void @_ZSt17__throw_bad_allocv() #16
  unreachable

; <label>:12:                                     ; preds = %3
  %13 = load i64, i64* %5, align 8
  %14 = mul i64 %13, 8
  %15 = call i8* @_Znwm(i64 %14)
  %16 = bitcast i8* %15 to %class.NStatement**
  ret %class.NStatement** %16
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt22__uninitialized_copy_aISt13move_iteratorIPP10NStatementES3_S2_ET0_T_S6_S5_RSaIT1_E(%class.NStatement**, %class.NStatement**, %class.NStatement**, %"class.std::allocator"* dereferenceable(1)) #4 comdat {
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = alloca %"class.std::move_iterator", align 8
  %7 = alloca %class.NStatement**, align 8
  %8 = alloca %"class.std::allocator"*, align 8
  %9 = alloca %"class.std::move_iterator", align 8
  %10 = alloca %"class.std::move_iterator", align 8
  %11 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %5, i32 0, i32 0
  store %class.NStatement** %0, %class.NStatement*** %11, align 8
  %12 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %6, i32 0, i32 0
  store %class.NStatement** %1, %class.NStatement*** %12, align 8
  store %class.NStatement** %2, %class.NStatement*** %7, align 8
  store %"class.std::allocator"* %3, %"class.std::allocator"** %8, align 8
  %13 = bitcast %"class.std::move_iterator"* %9 to i8*
  %14 = bitcast %"class.std::move_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = bitcast %"class.std::move_iterator"* %10 to i8*
  %16 = bitcast %"class.std::move_iterator"* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %15, i8* align 8 %16, i64 8, i1 false)
  %17 = load %class.NStatement**, %class.NStatement*** %7, align 8
  %18 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %9, i32 0, i32 0
  %19 = load %class.NStatement**, %class.NStatement*** %18, align 8
  %20 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %10, i32 0, i32 0
  %21 = load %class.NStatement**, %class.NStatement*** %20, align 8
  %22 = call %class.NStatement** @_ZSt18uninitialized_copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(%class.NStatement** %19, %class.NStatement** %21, %class.NStatement** %17)
  ret %class.NStatement** %22
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt32__make_move_if_noexcept_iteratorIP10NStatementSt13move_iteratorIPS1_EET0_PT_(%class.NStatement**) #4 comdat {
  %2 = alloca %"class.std::move_iterator", align 8
  %3 = alloca %class.NStatement**, align 8
  store %class.NStatement** %0, %class.NStatement*** %3, align 8
  %4 = load %class.NStatement**, %class.NStatement*** %3, align 8
  call void @_ZNSt13move_iteratorIPP10NStatementEC2ES2_(%"class.std::move_iterator"* %2, %class.NStatement** %4)
  %5 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %2, i32 0, i32 0
  %6 = load %class.NStatement**, %class.NStatement*** %5, align 8
  ret %class.NStatement** %6
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt18uninitialized_copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(%class.NStatement**, %class.NStatement**, %class.NStatement**) #4 comdat {
  %4 = alloca %"class.std::move_iterator", align 8
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = alloca %class.NStatement**, align 8
  %7 = alloca i8, align 1
  %8 = alloca %"class.std::move_iterator", align 8
  %9 = alloca %"class.std::move_iterator", align 8
  %10 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %4, i32 0, i32 0
  store %class.NStatement** %0, %class.NStatement*** %10, align 8
  %11 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %5, i32 0, i32 0
  store %class.NStatement** %1, %class.NStatement*** %11, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  store i8 1, i8* %7, align 1
  %12 = bitcast %"class.std::move_iterator"* %8 to i8*
  %13 = bitcast %"class.std::move_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %12, i8* align 8 %13, i64 8, i1 false)
  %14 = bitcast %"class.std::move_iterator"* %9 to i8*
  %15 = bitcast %"class.std::move_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %14, i8* align 8 %15, i64 8, i1 false)
  %16 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %17 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %8, i32 0, i32 0
  %18 = load %class.NStatement**, %class.NStatement*** %17, align 8
  %19 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %9, i32 0, i32 0
  %20 = load %class.NStatement**, %class.NStatement*** %19, align 8
  %21 = call %class.NStatement** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP10NStatementES5_EET0_T_S8_S7_(%class.NStatement** %18, %class.NStatement** %20, %class.NStatement** %16)
  ret %class.NStatement** %21
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP10NStatementES5_EET0_T_S8_S7_(%class.NStatement**, %class.NStatement**, %class.NStatement**) #4 comdat align 2 {
  %4 = alloca %"class.std::move_iterator", align 8
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = alloca %class.NStatement**, align 8
  %7 = alloca %"class.std::move_iterator", align 8
  %8 = alloca %"class.std::move_iterator", align 8
  %9 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %4, i32 0, i32 0
  store %class.NStatement** %0, %class.NStatement*** %9, align 8
  %10 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %5, i32 0, i32 0
  store %class.NStatement** %1, %class.NStatement*** %10, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  %11 = bitcast %"class.std::move_iterator"* %7 to i8*
  %12 = bitcast %"class.std::move_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = bitcast %"class.std::move_iterator"* %8 to i8*
  %14 = bitcast %"class.std::move_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %16 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %7, i32 0, i32 0
  %17 = load %class.NStatement**, %class.NStatement*** %16, align 8
  %18 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %8, i32 0, i32 0
  %19 = load %class.NStatement**, %class.NStatement*** %18, align 8
  %20 = call %class.NStatement** @_ZSt4copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(%class.NStatement** %17, %class.NStatement** %19, %class.NStatement** %15)
  ret %class.NStatement** %20
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt4copyISt13move_iteratorIPP10NStatementES3_ET0_T_S6_S5_(%class.NStatement**, %class.NStatement**, %class.NStatement**) #4 comdat {
  %4 = alloca %"class.std::move_iterator", align 8
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = alloca %class.NStatement**, align 8
  %7 = alloca %"class.std::move_iterator", align 8
  %8 = alloca %"class.std::move_iterator", align 8
  %9 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %4, i32 0, i32 0
  store %class.NStatement** %0, %class.NStatement*** %9, align 8
  %10 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %5, i32 0, i32 0
  store %class.NStatement** %1, %class.NStatement*** %10, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  %11 = bitcast %"class.std::move_iterator"* %7 to i8*
  %12 = bitcast %"class.std::move_iterator"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %7, i32 0, i32 0
  %14 = load %class.NStatement**, %class.NStatement*** %13, align 8
  %15 = call %class.NStatement** @_ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NStatement** %14)
  %16 = bitcast %"class.std::move_iterator"* %8 to i8*
  %17 = bitcast %"class.std::move_iterator"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %16, i8* align 8 %17, i64 8, i1 false)
  %18 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %8, i32 0, i32 0
  %19 = load %class.NStatement**, %class.NStatement*** %18, align 8
  %20 = call %class.NStatement** @_ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NStatement** %19)
  %21 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %22 = call %class.NStatement** @_ZSt14__copy_move_a2ILb1EPP10NStatementS2_ET1_T0_S4_S3_(%class.NStatement** %15, %class.NStatement** %20, %class.NStatement** %21)
  ret %class.NStatement** %22
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt14__copy_move_a2ILb1EPP10NStatementS2_ET1_T0_S4_S3_(%class.NStatement**, %class.NStatement**, %class.NStatement**) #4 comdat {
  %4 = alloca %class.NStatement**, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca %class.NStatement**, align 8
  store %class.NStatement** %0, %class.NStatement*** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  %7 = load %class.NStatement**, %class.NStatement*** %4, align 8
  %8 = call %class.NStatement** @_ZSt12__niter_baseIPP10NStatementET_S3_(%class.NStatement** %7)
  %9 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %10 = call %class.NStatement** @_ZSt12__niter_baseIPP10NStatementET_S3_(%class.NStatement** %9)
  %11 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %12 = call %class.NStatement** @_ZSt12__niter_baseIPP10NStatementET_S3_(%class.NStatement** %11)
  %13 = call %class.NStatement** @_ZSt13__copy_move_aILb1EPP10NStatementS2_ET1_T0_S4_S3_(%class.NStatement** %8, %class.NStatement** %10, %class.NStatement** %12)
  ret %class.NStatement** %13
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt12__miter_baseIPP10NStatementEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NStatement**) #4 comdat {
  %2 = alloca %"class.std::move_iterator", align 8
  %3 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %2, i32 0, i32 0
  store %class.NStatement** %0, %class.NStatement*** %3, align 8
  %4 = call %class.NStatement** @_ZNKSt13move_iteratorIPP10NStatementE4baseEv(%"class.std::move_iterator"* %2)
  %5 = call %class.NStatement** @_ZSt12__miter_baseIPP10NStatementET_S3_(%class.NStatement** %4)
  ret %class.NStatement** %5
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt13__copy_move_aILb1EPP10NStatementS2_ET1_T0_S4_S3_(%class.NStatement**, %class.NStatement**, %class.NStatement**) #4 comdat {
  %4 = alloca %class.NStatement**, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca %class.NStatement**, align 8
  %7 = alloca i8, align 1
  store %class.NStatement** %0, %class.NStatement*** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  store i8 1, i8* %7, align 1
  %8 = load %class.NStatement**, %class.NStatement*** %4, align 8
  %9 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %10 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %11 = call %class.NStatement** @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP10NStatementEEPT_PKS5_S8_S6_(%class.NStatement** %8, %class.NStatement** %9, %class.NStatement** %10)
  ret %class.NStatement** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt12__niter_baseIPP10NStatementET_S3_(%class.NStatement**) #7 comdat {
  %2 = alloca %class.NStatement**, align 8
  store %class.NStatement** %0, %class.NStatement*** %2, align 8
  %3 = load %class.NStatement**, %class.NStatement*** %2, align 8
  ret %class.NStatement** %3
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP10NStatementEEPT_PKS5_S8_S6_(%class.NStatement**, %class.NStatement**, %class.NStatement**) #7 comdat align 2 {
  %4 = alloca %class.NStatement**, align 8
  %5 = alloca %class.NStatement**, align 8
  %6 = alloca %class.NStatement**, align 8
  %7 = alloca i64, align 8
  store %class.NStatement** %0, %class.NStatement*** %4, align 8
  store %class.NStatement** %1, %class.NStatement*** %5, align 8
  store %class.NStatement** %2, %class.NStatement*** %6, align 8
  %8 = load %class.NStatement**, %class.NStatement*** %5, align 8
  %9 = load %class.NStatement**, %class.NStatement*** %4, align 8
  %10 = ptrtoint %class.NStatement** %8 to i64
  %11 = ptrtoint %class.NStatement** %9 to i64
  %12 = sub i64 %10, %11
  %13 = sdiv exact i64 %12, 8
  store i64 %13, i64* %7, align 8
  %14 = load i64, i64* %7, align 8
  %15 = icmp ne i64 %14, 0
  br i1 %15, label %16, label %23

; <label>:16:                                     ; preds = %3
  %17 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %18 = bitcast %class.NStatement** %17 to i8*
  %19 = load %class.NStatement**, %class.NStatement*** %4, align 8
  %20 = bitcast %class.NStatement** %19 to i8*
  %21 = load i64, i64* %7, align 8
  %22 = mul i64 8, %21
  call void @llvm.memmove.p0i8.p0i8.i64(i8* align 8 %18, i8* align 8 %20, i64 %22, i1 false)
  br label %23

; <label>:23:                                     ; preds = %16, %3
  %24 = load %class.NStatement**, %class.NStatement*** %6, align 8
  %25 = load i64, i64* %7, align 8
  %26 = getelementptr inbounds %class.NStatement*, %class.NStatement** %24, i64 %25
  ret %class.NStatement** %26
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZSt12__miter_baseIPP10NStatementET_S3_(%class.NStatement**) #7 comdat {
  %2 = alloca %class.NStatement**, align 8
  store %class.NStatement** %0, %class.NStatement*** %2, align 8
  %3 = load %class.NStatement**, %class.NStatement*** %2, align 8
  ret %class.NStatement** %3
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NStatement** @_ZNKSt13move_iteratorIPP10NStatementE4baseEv(%"class.std::move_iterator"*) #7 comdat align 2 {
  %2 = alloca %"class.std::move_iterator"*, align 8
  store %"class.std::move_iterator"* %0, %"class.std::move_iterator"** %2, align 8
  %3 = load %"class.std::move_iterator"*, %"class.std::move_iterator"** %2, align 8
  %4 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %3, i32 0, i32 0
  %5 = load %class.NStatement**, %class.NStatement*** %4, align 8
  ret %class.NStatement** %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt13move_iteratorIPP10NStatementEC2ES2_(%"class.std::move_iterator"*, %class.NStatement**) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.std::move_iterator"*, align 8
  %4 = alloca %class.NStatement**, align 8
  store %"class.std::move_iterator"* %0, %"class.std::move_iterator"** %3, align 8
  store %class.NStatement** %1, %class.NStatement*** %4, align 8
  %5 = load %"class.std::move_iterator"*, %"class.std::move_iterator"** %3, align 8
  %6 = getelementptr inbounds %"class.std::move_iterator", %"class.std::move_iterator"* %5, i32 0, i32 0
  %7 = load %class.NStatement**, %class.NStatement*** %4, align 8
  store %class.NStatement** %7, %class.NStatement*** %6, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP10NStatementE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator"*, %class.NStatement**) #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::new_allocator"*, align 8
  %4 = alloca %class.NStatement**, align 8
  store %"class.__gnu_cxx::new_allocator"* %0, %"class.__gnu_cxx::new_allocator"** %3, align 8
  store %class.NStatement** %1, %class.NStatement*** %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator"*, %"class.__gnu_cxx::new_allocator"** %3, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EEC2Ev(%"struct.std::_Vector_base.4"*) unnamed_addr #4 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base.4"*, align 8
  store %"struct.std::_Vector_base.4"* %0, %"struct.std::_Vector_base.4"** %2, align 8
  %3 = load %"struct.std::_Vector_base.4"*, %"struct.std::_Vector_base.4"** %2, align 8
  %4 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %3, i32 0, i32 0
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %4)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %0, %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"** %2, align 8
  %3 = load %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"*, %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"** %2, align 8
  %4 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %3 to %"class.std::allocator.5"*
  call void @_ZNSaIP20NVariableDeclarationEC2Ev(%"class.std::allocator.5"* %4) #3
  %5 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %3, i32 0, i32 0
  store %class.NVariableDeclaration** null, %class.NVariableDeclaration*** %5, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %3, i32 0, i32 1
  store %class.NVariableDeclaration** null, %class.NVariableDeclaration*** %6, align 8
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %3, i32 0, i32 2
  store %class.NVariableDeclaration** null, %class.NVariableDeclaration*** %7, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSaIP20NVariableDeclarationEC2Ev(%"class.std::allocator.5"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.std::allocator.5"*, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %2, align 8
  %3 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %2, align 8
  %4 = bitcast %"class.std::allocator.5"* %3 to %"class.__gnu_cxx::new_allocator.6"*
  call void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2Ev(%"class.__gnu_cxx::new_allocator.6"* %4) #3
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationEC2Ev(%"class.__gnu_cxx::new_allocator.6"*) unnamed_addr #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %2, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator.5"* dereferenceable(1), %class.NVariableDeclaration**, %class.NVariableDeclaration** dereferenceable(8)) #4 comdat align 2 {
  %4 = alloca %"class.std::allocator.5"*, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %7 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %4, align 8
  %8 = bitcast %"class.std::allocator.5"* %7 to %"class.__gnu_cxx::new_allocator.6"*
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %10 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %11 = call dereferenceable(8) %class.NVariableDeclaration** @_ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(%class.NVariableDeclaration** dereferenceable(8) %10) #3
  call void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator.6"* %8, %class.NVariableDeclaration** %9, %class.NVariableDeclaration** dereferenceable(8) %11)
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(%"class.std::vector.3"*, %class.NVariableDeclaration**, %class.NVariableDeclaration** dereferenceable(8)) #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.15", align 8
  %5 = alloca %"class.std::vector.3"*, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca i64, align 8
  %8 = alloca %class.NVariableDeclaration**, align 8
  %9 = alloca %class.NVariableDeclaration**, align 8
  %10 = alloca i64, align 8
  %11 = alloca %"class.__gnu_cxx::__normal_iterator.15", align 8
  %12 = alloca %class.NVariableDeclaration**, align 8
  %13 = alloca %class.NVariableDeclaration**, align 8
  %14 = alloca i8*
  %15 = alloca i32
  %16 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %16, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %17 = load %"class.std::vector.3"*, %"class.std::vector.3"** %5, align 8
  %18 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE12_M_check_lenEmPKc(%"class.std::vector.3"* %17, i64 1, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.8, i32 0, i32 0))
  store i64 %18, i64* %7, align 8
  %19 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %20 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %19, i32 0, i32 0
  %21 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %20, i32 0, i32 0
  %22 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %21, align 8
  store %class.NVariableDeclaration** %22, %class.NVariableDeclaration*** %8, align 8
  %23 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %24 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %23, i32 0, i32 0
  %25 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %24, i32 0, i32 1
  %26 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %25, align 8
  store %class.NVariableDeclaration** %26, %class.NVariableDeclaration*** %9, align 8
  %27 = call %class.NVariableDeclaration** @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(%"class.std::vector.3"* %17) #3
  %28 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %11, i32 0, i32 0
  store %class.NVariableDeclaration** %27, %class.NVariableDeclaration*** %28, align 8
  %29 = call i64 @_ZN9__gnu_cxxmiIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(%"class.__gnu_cxx::__normal_iterator.15"* dereferenceable(8) %4, %"class.__gnu_cxx::__normal_iterator.15"* dereferenceable(8) %11) #3
  store i64 %29, i64* %10, align 8
  %30 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %31 = load i64, i64* %7, align 8
  %32 = call %class.NVariableDeclaration** @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base.4"* %30, i64 %31)
  store %class.NVariableDeclaration** %32, %class.NVariableDeclaration*** %12, align 8
  %33 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  store %class.NVariableDeclaration** %33, %class.NVariableDeclaration*** %13, align 8
  %34 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %35 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %34, i32 0, i32 0
  %36 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %35 to %"class.std::allocator.5"*
  %37 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %38 = load i64, i64* %10, align 8
  %39 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %37, i64 %38
  %40 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %41 = call dereferenceable(8) %class.NVariableDeclaration** @_ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(%class.NVariableDeclaration** dereferenceable(8) %40) #3
  invoke void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator.5"* dereferenceable(1) %36, %class.NVariableDeclaration** %39, %class.NVariableDeclaration** dereferenceable(8) %41)
          to label %42 unwind label %61

; <label>:42:                                     ; preds = %3
  store %class.NVariableDeclaration** null, %class.NVariableDeclaration*** %13, align 8
  %43 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  %44 = call dereferenceable(8) %class.NVariableDeclaration*** @_ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.15"* %4) #3
  %45 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %44, align 8
  %46 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %47 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %48 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %47) #3
  %49 = invoke %class.NVariableDeclaration** @_ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NVariableDeclaration** %43, %class.NVariableDeclaration** %45, %class.NVariableDeclaration** %46, %"class.std::allocator.5"* dereferenceable(1) %48)
          to label %50 unwind label %61

; <label>:50:                                     ; preds = %42
  store %class.NVariableDeclaration** %49, %class.NVariableDeclaration*** %13, align 8
  %51 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %52 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %51, i32 1
  store %class.NVariableDeclaration** %52, %class.NVariableDeclaration*** %13, align 8
  %53 = call dereferenceable(8) %class.NVariableDeclaration*** @_ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.15"* %4) #3
  %54 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %53, align 8
  %55 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %9, align 8
  %56 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %57 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %58 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %57) #3
  %59 = invoke %class.NVariableDeclaration** @_ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NVariableDeclaration** %54, %class.NVariableDeclaration** %55, %class.NVariableDeclaration** %56, %"class.std::allocator.5"* dereferenceable(1) %58)
          to label %60 unwind label %61

; <label>:60:                                     ; preds = %50
  store %class.NVariableDeclaration** %59, %class.NVariableDeclaration*** %13, align 8
  br label %94

; <label>:61:                                     ; preds = %50, %42, %3
  %62 = landingpad { i8*, i32 }
          catch i8* null
  %63 = extractvalue { i8*, i32 } %62, 0
  store i8* %63, i8** %14, align 8
  %64 = extractvalue { i8*, i32 } %62, 1
  store i32 %64, i32* %15, align 4
  br label %65

; <label>:65:                                     ; preds = %61
  %66 = load i8*, i8** %14, align 8
  %67 = call i8* @__cxa_begin_catch(i8* %66) #3
  %68 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %69 = icmp ne %class.NVariableDeclaration** %68, null
  br i1 %69, label %82, label %70

; <label>:70:                                     ; preds = %65
  %71 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %72 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %71, i32 0, i32 0
  %73 = bitcast %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %72 to %"class.std::allocator.5"*
  %74 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %75 = load i64, i64* %10, align 8
  %76 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %74, i64 %75
  invoke void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator.5"* dereferenceable(1) %73, %class.NVariableDeclaration** %76)
          to label %77 unwind label %78

; <label>:77:                                     ; preds = %70
  br label %88

; <label>:78:                                     ; preds = %92, %88, %82, %70
  %79 = landingpad { i8*, i32 }
          cleanup
  %80 = extractvalue { i8*, i32 } %79, 0
  store i8* %80, i8** %14, align 8
  %81 = extractvalue { i8*, i32 } %79, 1
  store i32 %81, i32* %15, align 4
  invoke void @__cxa_end_catch()
          to label %93 unwind label %129

; <label>:82:                                     ; preds = %65
  %83 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %84 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %85 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %86 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %85) #3
  invoke void @_ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(%class.NVariableDeclaration** %83, %class.NVariableDeclaration** %84, %"class.std::allocator.5"* dereferenceable(1) %86)
          to label %87 unwind label %78

; <label>:87:                                     ; preds = %82
  br label %88

; <label>:88:                                     ; preds = %87, %77
  %89 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %90 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %91 = load i64, i64* %7, align 8
  invoke void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.4"* %89, %class.NVariableDeclaration** %90, i64 %91)
          to label %92 unwind label %78

; <label>:92:                                     ; preds = %88
  invoke void @__cxa_rethrow() #16
          to label %132 unwind label %78

; <label>:93:                                     ; preds = %78
  br label %124

; <label>:94:                                     ; preds = %60
  %95 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  %96 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %9, align 8
  %97 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %98 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %97) #3
  call void @_ZSt8_DestroyIPP20NVariableDeclarationS1_EvT_S3_RSaIT0_E(%class.NVariableDeclaration** %95, %class.NVariableDeclaration** %96, %"class.std::allocator.5"* dereferenceable(1) %98)
  %99 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %100 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  %101 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %102 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %101, i32 0, i32 0
  %103 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %102, i32 0, i32 2
  %104 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %103, align 8
  %105 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  %106 = ptrtoint %class.NVariableDeclaration** %104 to i64
  %107 = ptrtoint %class.NVariableDeclaration** %105 to i64
  %108 = sub i64 %106, %107
  %109 = sdiv exact i64 %108, 8
  call void @_ZNSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.4"* %99, %class.NVariableDeclaration** %100, i64 %109)
  %110 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %111 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %112 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %111, i32 0, i32 0
  %113 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %112, i32 0, i32 0
  store %class.NVariableDeclaration** %110, %class.NVariableDeclaration*** %113, align 8
  %114 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %115 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %116 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %115, i32 0, i32 0
  %117 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %116, i32 0, i32 1
  store %class.NVariableDeclaration** %114, %class.NVariableDeclaration*** %117, align 8
  %118 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %12, align 8
  %119 = load i64, i64* %7, align 8
  %120 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %118, i64 %119
  %121 = bitcast %"class.std::vector.3"* %17 to %"struct.std::_Vector_base.4"*
  %122 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %121, i32 0, i32 0
  %123 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %122, i32 0, i32 2
  store %class.NVariableDeclaration** %120, %class.NVariableDeclaration*** %123, align 8
  ret void

; <label>:124:                                    ; preds = %93
  %125 = load i8*, i8** %14, align 8
  %126 = load i32, i32* %15, align 4
  %127 = insertvalue { i8*, i32 } undef, i8* %125, 0
  %128 = insertvalue { i8*, i32 } %127, i32 %126, 1
  resume { i8*, i32 } %128

; <label>:129:                                    ; preds = %78
  %130 = landingpad { i8*, i32 }
          catch i8* null
  %131 = extractvalue { i8*, i32 } %130, 0
  call void @__clang_call_terminate(i8* %131) #10
  unreachable

; <label>:132:                                    ; preds = %92
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE3endEv(%"class.std::vector.3"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.15", align 8
  %3 = alloca %"class.std::vector.3"*, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %3, align 8
  %4 = load %"class.std::vector.3"*, %"class.std::vector.3"** %3, align 8
  %5 = bitcast %"class.std::vector.3"* %4 to %"struct.std::_Vector_base.4"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %6, i32 0, i32 1
  call void @_ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.15"* %2, %class.NVariableDeclaration*** dereferenceable(8) %7) #3
  %8 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %2, i32 0, i32 0
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  ret %class.NVariableDeclaration** %9
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator.6"*, %class.NVariableDeclaration**, %class.NVariableDeclaration** dereferenceable(8)) #7 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %4, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %9 = bitcast %class.NVariableDeclaration** %8 to i8*
  %10 = bitcast i8* %9 to %class.NVariableDeclaration**
  %11 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %12 = call dereferenceable(8) %class.NVariableDeclaration** @_ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(%class.NVariableDeclaration** dereferenceable(8) %11) #3
  %13 = load %class.NVariableDeclaration*, %class.NVariableDeclaration** %12, align 8
  store %class.NVariableDeclaration* %13, %class.NVariableDeclaration** %10, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NVariableDeclaration** @_ZSt7forwardIRKP20NVariableDeclarationEOT_RNSt16remove_referenceIS4_E4typeE(%class.NVariableDeclaration** dereferenceable(8)) #7 comdat {
  %2 = alloca %class.NVariableDeclaration**, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %2, align 8
  %3 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %2, align 8
  ret %class.NVariableDeclaration** %3
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE12_M_check_lenEmPKc(%"class.std::vector.3"*, i64, i8*) #4 comdat align 2 {
  %4 = alloca %"class.std::vector.3"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i8*, align 8
  %7 = alloca i64, align 8
  %8 = alloca i64, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %4, align 8
  store i64 %1, i64* %5, align 8
  store i8* %2, i8** %6, align 8
  %9 = load %"class.std::vector.3"*, %"class.std::vector.3"** %4, align 8
  %10 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(%"class.std::vector.3"* %9) #3
  %11 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(%"class.std::vector.3"* %9) #3
  %12 = sub i64 %10, %11
  %13 = load i64, i64* %5, align 8
  %14 = icmp ult i64 %12, %13
  br i1 %14, label %15, label %17

; <label>:15:                                     ; preds = %3
  %16 = load i8*, i8** %6, align 8
  call void @_ZSt20__throw_length_errorPKc(i8* %16) #16
  unreachable

; <label>:17:                                     ; preds = %3
  %18 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(%"class.std::vector.3"* %9) #3
  %19 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(%"class.std::vector.3"* %9) #3
  store i64 %19, i64* %8, align 8
  %20 = call dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8) %8, i64* dereferenceable(8) %5)
  %21 = load i64, i64* %20, align 8
  %22 = add i64 %18, %21
  store i64 %22, i64* %7, align 8
  %23 = load i64, i64* %7, align 8
  %24 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE4sizeEv(%"class.std::vector.3"* %9) #3
  %25 = icmp ult i64 %23, %24
  br i1 %25, label %30, label %26

; <label>:26:                                     ; preds = %17
  %27 = load i64, i64* %7, align 8
  %28 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(%"class.std::vector.3"* %9) #3
  %29 = icmp ugt i64 %27, %28
  br i1 %29, label %30, label %32

; <label>:30:                                     ; preds = %26, %17
  %31 = call i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(%"class.std::vector.3"* %9) #3
  br label %34

; <label>:32:                                     ; preds = %26
  %33 = load i64, i64* %7, align 8
  br label %34

; <label>:34:                                     ; preds = %32, %30
  %35 = phi i64 [ %31, %30 ], [ %33, %32 ]
  ret i64 %35
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZN9__gnu_cxxmiIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(%"class.__gnu_cxx::__normal_iterator.15"* dereferenceable(8), %"class.__gnu_cxx::__normal_iterator.15"* dereferenceable(8)) #7 comdat {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.15"*, align 8
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.15"*, align 8
  store %"class.__gnu_cxx::__normal_iterator.15"* %0, %"class.__gnu_cxx::__normal_iterator.15"** %3, align 8
  store %"class.__gnu_cxx::__normal_iterator.15"* %1, %"class.__gnu_cxx::__normal_iterator.15"** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator.15"*, %"class.__gnu_cxx::__normal_iterator.15"** %3, align 8
  %6 = call dereferenceable(8) %class.NVariableDeclaration*** @_ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.15"* %5) #3
  %7 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %8 = load %"class.__gnu_cxx::__normal_iterator.15"*, %"class.__gnu_cxx::__normal_iterator.15"** %4, align 8
  %9 = call dereferenceable(8) %class.NVariableDeclaration*** @_ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.15"* %8) #3
  %10 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %9, align 8
  %11 = ptrtoint %class.NVariableDeclaration** %7 to i64
  %12 = ptrtoint %class.NVariableDeclaration** %10 to i64
  %13 = sub i64 %11, %12
  %14 = sdiv exact i64 %13, 8
  ret i64 %14
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt6vectorIP20NVariableDeclarationSaIS1_EE5beginEv(%"class.std::vector.3"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.15", align 8
  %3 = alloca %"class.std::vector.3"*, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %3, align 8
  %4 = load %"class.std::vector.3"*, %"class.std::vector.3"** %3, align 8
  %5 = bitcast %"class.std::vector.3"* %4 to %"struct.std::_Vector_base.4"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base.4", %"struct.std::_Vector_base.4"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl", %"struct.std::_Vector_base<NVariableDeclaration *, std::allocator<NVariableDeclaration *> >::_Vector_impl"* %6, i32 0, i32 0
  call void @_ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.15"* %2, %class.NVariableDeclaration*** dereferenceable(8) %7) #3
  %8 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %2, i32 0, i32 0
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %8, align 8
  ret %class.NVariableDeclaration** %9
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt34__uninitialized_move_if_noexcept_aIPP20NVariableDeclarationS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**, %"class.std::allocator.5"* dereferenceable(1)) #4 comdat {
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca %class.NVariableDeclaration**, align 8
  %8 = alloca %"class.std::allocator.5"*, align 8
  %9 = alloca %"class.std::move_iterator.16", align 8
  %10 = alloca %"class.std::move_iterator.16", align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %6, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %7, align 8
  store %"class.std::allocator.5"* %3, %"class.std::allocator.5"** %8, align 8
  %11 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %12 = call %class.NVariableDeclaration** @_ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_(%class.NVariableDeclaration** %11)
  %13 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %9, i32 0, i32 0
  store %class.NVariableDeclaration** %12, %class.NVariableDeclaration*** %13, align 8
  %14 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %15 = call %class.NVariableDeclaration** @_ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_(%class.NVariableDeclaration** %14)
  %16 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %10, i32 0, i32 0
  store %class.NVariableDeclaration** %15, %class.NVariableDeclaration*** %16, align 8
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %7, align 8
  %18 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %8, align 8
  %19 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %9, i32 0, i32 0
  %20 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %19, align 8
  %21 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %10, i32 0, i32 0
  %22 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %21, align 8
  %23 = call %class.NVariableDeclaration** @_ZSt22__uninitialized_copy_aISt13move_iteratorIPP20NVariableDeclarationES3_S2_ET0_T_S6_S5_RSaIT1_E(%class.NVariableDeclaration** %20, %class.NVariableDeclaration** %22, %class.NVariableDeclaration** %17, %"class.std::allocator.5"* dereferenceable(1) %18)
  ret %class.NVariableDeclaration** %23
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NVariableDeclaration*** @_ZNK9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.15"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.15"*, align 8
  store %"class.__gnu_cxx::__normal_iterator.15"* %0, %"class.__gnu_cxx::__normal_iterator.15"** %2, align 8
  %3 = load %"class.__gnu_cxx::__normal_iterator.15"*, %"class.__gnu_cxx::__normal_iterator.15"** %2, align 8
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %3, i32 0, i32 0
  ret %class.NVariableDeclaration*** %4
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator.5"* dereferenceable(1), %class.NVariableDeclaration**) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator.5"*, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %3, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %4, align 8
  %5 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %3, align 8
  %6 = bitcast %"class.std::allocator.5"* %5 to %"class.__gnu_cxx::new_allocator.6"*
  %7 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator.6"* %6, %class.NVariableDeclaration** %7)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP20NVariableDeclarationSaIS1_EE8max_sizeEv(%"class.std::vector.3"*) #7 comdat align 2 {
  %2 = alloca %"class.std::vector.3"*, align 8
  store %"class.std::vector.3"* %0, %"class.std::vector.3"** %2, align 8
  %3 = load %"class.std::vector.3"*, %"class.std::vector.3"** %2, align 8
  %4 = bitcast %"class.std::vector.3"* %3 to %"struct.std::_Vector_base.4"*
  %5 = call dereferenceable(1) %"class.std::allocator.5"* @_ZNKSt12_Vector_baseIP20NVariableDeclarationSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.4"* %4) #3
  %6 = call i64 @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8max_sizeERKS2_(%"class.std::allocator.5"* dereferenceable(1) %5) #3
  ret i64 %6
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNSt16allocator_traitsISaIP20NVariableDeclarationEE8max_sizeERKS2_(%"class.std::allocator.5"* dereferenceable(1)) #7 comdat align 2 {
  %2 = alloca %"class.std::allocator.5"*, align 8
  store %"class.std::allocator.5"* %0, %"class.std::allocator.5"** %2, align 8
  %3 = load %"class.std::allocator.5"*, %"class.std::allocator.5"** %2, align 8
  %4 = bitcast %"class.std::allocator.5"* %3 to %"class.__gnu_cxx::new_allocator.6"*
  %5 = call i64 @_ZNK9__gnu_cxx13new_allocatorIP20NVariableDeclarationE8max_sizeEv(%"class.__gnu_cxx::new_allocator.6"* %4) #3
  ret i64 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx17__normal_iteratorIPP20NVariableDeclarationSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.15"*, %class.NVariableDeclaration*** dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.15"*, align 8
  %4 = alloca %class.NVariableDeclaration***, align 8
  store %"class.__gnu_cxx::__normal_iterator.15"* %0, %"class.__gnu_cxx::__normal_iterator.15"** %3, align 8
  store %class.NVariableDeclaration*** %1, %class.NVariableDeclaration**** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator.15"*, %"class.__gnu_cxx::__normal_iterator.15"** %3, align 8
  %6 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.15", %"class.__gnu_cxx::__normal_iterator.15"* %5, i32 0, i32 0
  %7 = load %class.NVariableDeclaration***, %class.NVariableDeclaration**** %4, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %7, align 8
  store %class.NVariableDeclaration** %8, %class.NVariableDeclaration*** %6, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt22__uninitialized_copy_aISt13move_iteratorIPP20NVariableDeclarationES3_S2_ET0_T_S6_S5_RSaIT1_E(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**, %"class.std::allocator.5"* dereferenceable(1)) #4 comdat {
  %5 = alloca %"class.std::move_iterator.16", align 8
  %6 = alloca %"class.std::move_iterator.16", align 8
  %7 = alloca %class.NVariableDeclaration**, align 8
  %8 = alloca %"class.std::allocator.5"*, align 8
  %9 = alloca %"class.std::move_iterator.16", align 8
  %10 = alloca %"class.std::move_iterator.16", align 8
  %11 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %11, align 8
  %12 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %6, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %12, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %7, align 8
  store %"class.std::allocator.5"* %3, %"class.std::allocator.5"** %8, align 8
  %13 = bitcast %"class.std::move_iterator.16"* %9 to i8*
  %14 = bitcast %"class.std::move_iterator.16"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = bitcast %"class.std::move_iterator.16"* %10 to i8*
  %16 = bitcast %"class.std::move_iterator.16"* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %15, i8* align 8 %16, i64 8, i1 false)
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %7, align 8
  %18 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %9, i32 0, i32 0
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %18, align 8
  %20 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %10, i32 0, i32 0
  %21 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %20, align 8
  %22 = call %class.NVariableDeclaration** @_ZSt18uninitialized_copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(%class.NVariableDeclaration** %19, %class.NVariableDeclaration** %21, %class.NVariableDeclaration** %17)
  ret %class.NVariableDeclaration** %22
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt32__make_move_if_noexcept_iteratorIP20NVariableDeclarationSt13move_iteratorIPS1_EET0_PT_(%class.NVariableDeclaration**) #4 comdat {
  %2 = alloca %"class.std::move_iterator.16", align 8
  %3 = alloca %class.NVariableDeclaration**, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %3, align 8
  %4 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %3, align 8
  call void @_ZNSt13move_iteratorIPP20NVariableDeclarationEC2ES2_(%"class.std::move_iterator.16"* %2, %class.NVariableDeclaration** %4)
  %5 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %2, i32 0, i32 0
  %6 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  ret %class.NVariableDeclaration** %6
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt18uninitialized_copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %"class.std::move_iterator.16", align 8
  %5 = alloca %"class.std::move_iterator.16", align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca i8, align 1
  %8 = alloca %"class.std::move_iterator.16", align 8
  %9 = alloca %"class.std::move_iterator.16", align 8
  %10 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %10, align 8
  %11 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %11, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  store i8 1, i8* %7, align 1
  %12 = bitcast %"class.std::move_iterator.16"* %8 to i8*
  %13 = bitcast %"class.std::move_iterator.16"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %12, i8* align 8 %13, i64 8, i1 false)
  %14 = bitcast %"class.std::move_iterator.16"* %9 to i8*
  %15 = bitcast %"class.std::move_iterator.16"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %14, i8* align 8 %15, i64 8, i1 false)
  %16 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %17 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %8, i32 0, i32 0
  %18 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %17, align 8
  %19 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %9, i32 0, i32 0
  %20 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %19, align 8
  %21 = call %class.NVariableDeclaration** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP20NVariableDeclarationES5_EET0_T_S8_S7_(%class.NVariableDeclaration** %18, %class.NVariableDeclaration** %20, %class.NVariableDeclaration** %16)
  ret %class.NVariableDeclaration** %21
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP20NVariableDeclarationES5_EET0_T_S8_S7_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat align 2 {
  %4 = alloca %"class.std::move_iterator.16", align 8
  %5 = alloca %"class.std::move_iterator.16", align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca %"class.std::move_iterator.16", align 8
  %8 = alloca %"class.std::move_iterator.16", align 8
  %9 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %9, align 8
  %10 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %10, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %11 = bitcast %"class.std::move_iterator.16"* %7 to i8*
  %12 = bitcast %"class.std::move_iterator.16"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = bitcast %"class.std::move_iterator.16"* %8 to i8*
  %14 = bitcast %"class.std::move_iterator.16"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %16 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %7, i32 0, i32 0
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %16, align 8
  %18 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %8, i32 0, i32 0
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %18, align 8
  %20 = call %class.NVariableDeclaration** @_ZSt4copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(%class.NVariableDeclaration** %17, %class.NVariableDeclaration** %19, %class.NVariableDeclaration** %15)
  ret %class.NVariableDeclaration** %20
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt4copyISt13move_iteratorIPP20NVariableDeclarationES3_ET0_T_S6_S5_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %"class.std::move_iterator.16", align 8
  %5 = alloca %"class.std::move_iterator.16", align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca %"class.std::move_iterator.16", align 8
  %8 = alloca %"class.std::move_iterator.16", align 8
  %9 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %4, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %9, align 8
  %10 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %5, i32 0, i32 0
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %10, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %11 = bitcast %"class.std::move_iterator.16"* %7 to i8*
  %12 = bitcast %"class.std::move_iterator.16"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %7, i32 0, i32 0
  %14 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %13, align 8
  %15 = call %class.NVariableDeclaration** @_ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NVariableDeclaration** %14)
  %16 = bitcast %"class.std::move_iterator.16"* %8 to i8*
  %17 = bitcast %"class.std::move_iterator.16"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %16, i8* align 8 %17, i64 8, i1 false)
  %18 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %8, i32 0, i32 0
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %18, align 8
  %20 = call %class.NVariableDeclaration** @_ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NVariableDeclaration** %19)
  %21 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %22 = call %class.NVariableDeclaration** @_ZSt14__copy_move_a2ILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(%class.NVariableDeclaration** %15, %class.NVariableDeclaration** %20, %class.NVariableDeclaration** %21)
  ret %class.NVariableDeclaration** %22
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt14__copy_move_a2ILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %class.NVariableDeclaration**, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %7 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %8 = call %class.NVariableDeclaration** @_ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(%class.NVariableDeclaration** %7)
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %10 = call %class.NVariableDeclaration** @_ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(%class.NVariableDeclaration** %9)
  %11 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %12 = call %class.NVariableDeclaration** @_ZSt12__niter_baseIPP20NVariableDeclarationET_S3_(%class.NVariableDeclaration** %11)
  %13 = call %class.NVariableDeclaration** @_ZSt13__copy_move_aILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(%class.NVariableDeclaration** %8, %class.NVariableDeclaration** %10, %class.NVariableDeclaration** %12)
  ret %class.NVariableDeclaration** %13
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt12__miter_baseIPP20NVariableDeclarationEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NVariableDeclaration**) #4 comdat {
  %2 = alloca %"class.std::move_iterator.16", align 8
  %3 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %2, i32 0, i32 0
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %3, align 8
  %4 = call %class.NVariableDeclaration** @_ZNKSt13move_iteratorIPP20NVariableDeclarationE4baseEv(%"class.std::move_iterator.16"* %2)
  %5 = call %class.NVariableDeclaration** @_ZSt12__miter_baseIPP20NVariableDeclarationET_S3_(%class.NVariableDeclaration** %4)
  ret %class.NVariableDeclaration** %5
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt13__copy_move_aILb1EPP20NVariableDeclarationS2_ET1_T0_S4_S3_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #4 comdat {
  %4 = alloca %class.NVariableDeclaration**, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca i8, align 1
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  store i8 1, i8* %7, align 1
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %10 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %11 = call %class.NVariableDeclaration** @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(%class.NVariableDeclaration** %8, %class.NVariableDeclaration** %9, %class.NVariableDeclaration** %10)
  ret %class.NVariableDeclaration** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP20NVariableDeclarationEEPT_PKS5_S8_S6_(%class.NVariableDeclaration**, %class.NVariableDeclaration**, %class.NVariableDeclaration**) #7 comdat align 2 {
  %4 = alloca %class.NVariableDeclaration**, align 8
  %5 = alloca %class.NVariableDeclaration**, align 8
  %6 = alloca %class.NVariableDeclaration**, align 8
  %7 = alloca i64, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %4, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %5, align 8
  store %class.NVariableDeclaration** %2, %class.NVariableDeclaration*** %6, align 8
  %8 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %5, align 8
  %9 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %10 = ptrtoint %class.NVariableDeclaration** %8 to i64
  %11 = ptrtoint %class.NVariableDeclaration** %9 to i64
  %12 = sub i64 %10, %11
  %13 = sdiv exact i64 %12, 8
  store i64 %13, i64* %7, align 8
  %14 = load i64, i64* %7, align 8
  %15 = icmp ne i64 %14, 0
  br i1 %15, label %16, label %23

; <label>:16:                                     ; preds = %3
  %17 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %18 = bitcast %class.NVariableDeclaration** %17 to i8*
  %19 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  %20 = bitcast %class.NVariableDeclaration** %19 to i8*
  %21 = load i64, i64* %7, align 8
  %22 = mul i64 8, %21
  call void @llvm.memmove.p0i8.p0i8.i64(i8* align 8 %18, i8* align 8 %20, i64 %22, i1 false)
  br label %23

; <label>:23:                                     ; preds = %16, %3
  %24 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %6, align 8
  %25 = load i64, i64* %7, align 8
  %26 = getelementptr inbounds %class.NVariableDeclaration*, %class.NVariableDeclaration** %24, i64 %25
  ret %class.NVariableDeclaration** %26
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZSt12__miter_baseIPP20NVariableDeclarationET_S3_(%class.NVariableDeclaration**) #7 comdat {
  %2 = alloca %class.NVariableDeclaration**, align 8
  store %class.NVariableDeclaration** %0, %class.NVariableDeclaration*** %2, align 8
  %3 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %2, align 8
  ret %class.NVariableDeclaration** %3
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NVariableDeclaration** @_ZNKSt13move_iteratorIPP20NVariableDeclarationE4baseEv(%"class.std::move_iterator.16"*) #7 comdat align 2 {
  %2 = alloca %"class.std::move_iterator.16"*, align 8
  store %"class.std::move_iterator.16"* %0, %"class.std::move_iterator.16"** %2, align 8
  %3 = load %"class.std::move_iterator.16"*, %"class.std::move_iterator.16"** %2, align 8
  %4 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %3, i32 0, i32 0
  %5 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  ret %class.NVariableDeclaration** %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt13move_iteratorIPP20NVariableDeclarationEC2ES2_(%"class.std::move_iterator.16"*, %class.NVariableDeclaration**) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.std::move_iterator.16"*, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  store %"class.std::move_iterator.16"* %0, %"class.std::move_iterator.16"** %3, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %4, align 8
  %5 = load %"class.std::move_iterator.16"*, %"class.std::move_iterator.16"** %3, align 8
  %6 = getelementptr inbounds %"class.std::move_iterator.16", %"class.std::move_iterator.16"* %5, i32 0, i32 0
  %7 = load %class.NVariableDeclaration**, %class.NVariableDeclaration*** %4, align 8
  store %class.NVariableDeclaration** %7, %class.NVariableDeclaration*** %6, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP20NVariableDeclarationE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator.6"*, %class.NVariableDeclaration**) #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::new_allocator.6"*, align 8
  %4 = alloca %class.NVariableDeclaration**, align 8
  store %"class.__gnu_cxx::new_allocator.6"* %0, %"class.__gnu_cxx::new_allocator.6"** %3, align 8
  store %class.NVariableDeclaration** %1, %class.NVariableDeclaration*** %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator.6"*, %"class.__gnu_cxx::new_allocator.6"** %3, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator.10"* dereferenceable(1), %class.NExpression**, %class.NExpression** dereferenceable(8)) #4 comdat align 2 {
  %4 = alloca %"class.std::allocator.10"*, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %7 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %4, align 8
  %8 = bitcast %"class.std::allocator.10"* %7 to %"class.__gnu_cxx::new_allocator.11"*
  %9 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %10 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %11 = call dereferenceable(8) %class.NExpression** @_ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(%class.NExpression** dereferenceable(8) %10) #3
  call void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator.11"* %8, %class.NExpression** %9, %class.NExpression** dereferenceable(8) %11)
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt6vectorIP11NExpressionSaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_(%"class.std::vector.8"*, %class.NExpression**, %class.NExpression** dereferenceable(8)) #4 comdat align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.17", align 8
  %5 = alloca %"class.std::vector.8"*, align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca i64, align 8
  %8 = alloca %class.NExpression**, align 8
  %9 = alloca %class.NExpression**, align 8
  %10 = alloca i64, align 8
  %11 = alloca %"class.__gnu_cxx::__normal_iterator.17", align 8
  %12 = alloca %class.NExpression**, align 8
  %13 = alloca %class.NExpression**, align 8
  %14 = alloca i8*
  %15 = alloca i32
  %16 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %4, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %16, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %17 = load %"class.std::vector.8"*, %"class.std::vector.8"** %5, align 8
  %18 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE12_M_check_lenEmPKc(%"class.std::vector.8"* %17, i64 1, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.8, i32 0, i32 0))
  store i64 %18, i64* %7, align 8
  %19 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %20 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %19, i32 0, i32 0
  %21 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %20, i32 0, i32 0
  %22 = load %class.NExpression**, %class.NExpression*** %21, align 8
  store %class.NExpression** %22, %class.NExpression*** %8, align 8
  %23 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %24 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %23, i32 0, i32 0
  %25 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %24, i32 0, i32 1
  %26 = load %class.NExpression**, %class.NExpression*** %25, align 8
  store %class.NExpression** %26, %class.NExpression*** %9, align 8
  %27 = call %class.NExpression** @_ZNSt6vectorIP11NExpressionSaIS1_EE5beginEv(%"class.std::vector.8"* %17) #3
  %28 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %11, i32 0, i32 0
  store %class.NExpression** %27, %class.NExpression*** %28, align 8
  %29 = call i64 @_ZN9__gnu_cxxmiIPP11NExpressionSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(%"class.__gnu_cxx::__normal_iterator.17"* dereferenceable(8) %4, %"class.__gnu_cxx::__normal_iterator.17"* dereferenceable(8) %11) #3
  store i64 %29, i64* %10, align 8
  %30 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %31 = load i64, i64* %7, align 8
  %32 = call %class.NExpression** @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE11_M_allocateEm(%"struct.std::_Vector_base.9"* %30, i64 %31)
  store %class.NExpression** %32, %class.NExpression*** %12, align 8
  %33 = load %class.NExpression**, %class.NExpression*** %12, align 8
  store %class.NExpression** %33, %class.NExpression*** %13, align 8
  %34 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %35 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %34, i32 0, i32 0
  %36 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %35 to %"class.std::allocator.10"*
  %37 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %38 = load i64, i64* %10, align 8
  %39 = getelementptr inbounds %class.NExpression*, %class.NExpression** %37, i64 %38
  %40 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %41 = call dereferenceable(8) %class.NExpression** @_ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(%class.NExpression** dereferenceable(8) %40) #3
  invoke void @_ZNSt16allocator_traitsISaIP11NExpressionEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_(%"class.std::allocator.10"* dereferenceable(1) %36, %class.NExpression** %39, %class.NExpression** dereferenceable(8) %41)
          to label %42 unwind label %61

; <label>:42:                                     ; preds = %3
  store %class.NExpression** null, %class.NExpression*** %13, align 8
  %43 = load %class.NExpression**, %class.NExpression*** %8, align 8
  %44 = call dereferenceable(8) %class.NExpression*** @_ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.17"* %4) #3
  %45 = load %class.NExpression**, %class.NExpression*** %44, align 8
  %46 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %47 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %48 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %47) #3
  %49 = invoke %class.NExpression** @_ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NExpression** %43, %class.NExpression** %45, %class.NExpression** %46, %"class.std::allocator.10"* dereferenceable(1) %48)
          to label %50 unwind label %61

; <label>:50:                                     ; preds = %42
  store %class.NExpression** %49, %class.NExpression*** %13, align 8
  %51 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %52 = getelementptr inbounds %class.NExpression*, %class.NExpression** %51, i32 1
  store %class.NExpression** %52, %class.NExpression*** %13, align 8
  %53 = call dereferenceable(8) %class.NExpression*** @_ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.17"* %4) #3
  %54 = load %class.NExpression**, %class.NExpression*** %53, align 8
  %55 = load %class.NExpression**, %class.NExpression*** %9, align 8
  %56 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %57 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %58 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %57) #3
  %59 = invoke %class.NExpression** @_ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NExpression** %54, %class.NExpression** %55, %class.NExpression** %56, %"class.std::allocator.10"* dereferenceable(1) %58)
          to label %60 unwind label %61

; <label>:60:                                     ; preds = %50
  store %class.NExpression** %59, %class.NExpression*** %13, align 8
  br label %94

; <label>:61:                                     ; preds = %50, %42, %3
  %62 = landingpad { i8*, i32 }
          catch i8* null
  %63 = extractvalue { i8*, i32 } %62, 0
  store i8* %63, i8** %14, align 8
  %64 = extractvalue { i8*, i32 } %62, 1
  store i32 %64, i32* %15, align 4
  br label %65

; <label>:65:                                     ; preds = %61
  %66 = load i8*, i8** %14, align 8
  %67 = call i8* @__cxa_begin_catch(i8* %66) #3
  %68 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %69 = icmp ne %class.NExpression** %68, null
  br i1 %69, label %82, label %70

; <label>:70:                                     ; preds = %65
  %71 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %72 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %71, i32 0, i32 0
  %73 = bitcast %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %72 to %"class.std::allocator.10"*
  %74 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %75 = load i64, i64* %10, align 8
  %76 = getelementptr inbounds %class.NExpression*, %class.NExpression** %74, i64 %75
  invoke void @_ZNSt16allocator_traitsISaIP11NExpressionEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator.10"* dereferenceable(1) %73, %class.NExpression** %76)
          to label %77 unwind label %78

; <label>:77:                                     ; preds = %70
  br label %88

; <label>:78:                                     ; preds = %92, %88, %82, %70
  %79 = landingpad { i8*, i32 }
          cleanup
  %80 = extractvalue { i8*, i32 } %79, 0
  store i8* %80, i8** %14, align 8
  %81 = extractvalue { i8*, i32 } %79, 1
  store i32 %81, i32* %15, align 4
  invoke void @__cxa_end_catch()
          to label %93 unwind label %129

; <label>:82:                                     ; preds = %65
  %83 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %84 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %85 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %86 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %85) #3
  invoke void @_ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(%class.NExpression** %83, %class.NExpression** %84, %"class.std::allocator.10"* dereferenceable(1) %86)
          to label %87 unwind label %78

; <label>:87:                                     ; preds = %82
  br label %88

; <label>:88:                                     ; preds = %87, %77
  %89 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %90 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %91 = load i64, i64* %7, align 8
  invoke void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.9"* %89, %class.NExpression** %90, i64 %91)
          to label %92 unwind label %78

; <label>:92:                                     ; preds = %88
  invoke void @__cxa_rethrow() #16
          to label %132 unwind label %78

; <label>:93:                                     ; preds = %78
  br label %124

; <label>:94:                                     ; preds = %60
  %95 = load %class.NExpression**, %class.NExpression*** %8, align 8
  %96 = load %class.NExpression**, %class.NExpression*** %9, align 8
  %97 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %98 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %97) #3
  call void @_ZSt8_DestroyIPP11NExpressionS1_EvT_S3_RSaIT0_E(%class.NExpression** %95, %class.NExpression** %96, %"class.std::allocator.10"* dereferenceable(1) %98)
  %99 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %100 = load %class.NExpression**, %class.NExpression*** %8, align 8
  %101 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %102 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %101, i32 0, i32 0
  %103 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %102, i32 0, i32 2
  %104 = load %class.NExpression**, %class.NExpression*** %103, align 8
  %105 = load %class.NExpression**, %class.NExpression*** %8, align 8
  %106 = ptrtoint %class.NExpression** %104 to i64
  %107 = ptrtoint %class.NExpression** %105 to i64
  %108 = sub i64 %106, %107
  %109 = sdiv exact i64 %108, 8
  call void @_ZNSt12_Vector_baseIP11NExpressionSaIS1_EE13_M_deallocateEPS1_m(%"struct.std::_Vector_base.9"* %99, %class.NExpression** %100, i64 %109)
  %110 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %111 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %112 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %111, i32 0, i32 0
  %113 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %112, i32 0, i32 0
  store %class.NExpression** %110, %class.NExpression*** %113, align 8
  %114 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %115 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %116 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %115, i32 0, i32 0
  %117 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %116, i32 0, i32 1
  store %class.NExpression** %114, %class.NExpression*** %117, align 8
  %118 = load %class.NExpression**, %class.NExpression*** %12, align 8
  %119 = load i64, i64* %7, align 8
  %120 = getelementptr inbounds %class.NExpression*, %class.NExpression** %118, i64 %119
  %121 = bitcast %"class.std::vector.8"* %17 to %"struct.std::_Vector_base.9"*
  %122 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %121, i32 0, i32 0
  %123 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %122, i32 0, i32 2
  store %class.NExpression** %120, %class.NExpression*** %123, align 8
  ret void

; <label>:124:                                    ; preds = %93
  %125 = load i8*, i8** %14, align 8
  %126 = load i32, i32* %15, align 4
  %127 = insertvalue { i8*, i32 } undef, i8* %125, 0
  %128 = insertvalue { i8*, i32 } %127, i32 %126, 1
  resume { i8*, i32 } %128

; <label>:129:                                    ; preds = %78
  %130 = landingpad { i8*, i32 }
          catch i8* null
  %131 = extractvalue { i8*, i32 } %130, 0
  call void @__clang_call_terminate(i8* %131) #10
  unreachable

; <label>:132:                                    ; preds = %92
  unreachable
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt6vectorIP11NExpressionSaIS1_EE3endEv(%"class.std::vector.8"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.17", align 8
  %3 = alloca %"class.std::vector.8"*, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %3, align 8
  %4 = load %"class.std::vector.8"*, %"class.std::vector.8"** %3, align 8
  %5 = bitcast %"class.std::vector.8"* %4 to %"struct.std::_Vector_base.9"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %6, i32 0, i32 1
  call void @_ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.17"* %2, %class.NExpression*** dereferenceable(8) %7) #3
  %8 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %2, i32 0, i32 0
  %9 = load %class.NExpression**, %class.NExpression*** %8, align 8
  ret %class.NExpression** %9
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE9constructIS2_JRKS2_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator.11"*, %class.NExpression**, %class.NExpression** dereferenceable(8)) #7 comdat align 2 {
  %4 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %7 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %4, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %9 = bitcast %class.NExpression** %8 to i8*
  %10 = bitcast i8* %9 to %class.NExpression**
  %11 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %12 = call dereferenceable(8) %class.NExpression** @_ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(%class.NExpression** dereferenceable(8) %11) #3
  %13 = load %class.NExpression*, %class.NExpression** %12, align 8
  store %class.NExpression* %13, %class.NExpression** %10, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NExpression** @_ZSt7forwardIRKP11NExpressionEOT_RNSt16remove_referenceIS4_E4typeE(%class.NExpression** dereferenceable(8)) #7 comdat {
  %2 = alloca %class.NExpression**, align 8
  store %class.NExpression** %0, %class.NExpression*** %2, align 8
  %3 = load %class.NExpression**, %class.NExpression*** %2, align 8
  ret %class.NExpression** %3
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE12_M_check_lenEmPKc(%"class.std::vector.8"*, i64, i8*) #4 comdat align 2 {
  %4 = alloca %"class.std::vector.8"*, align 8
  %5 = alloca i64, align 8
  %6 = alloca i8*, align 8
  %7 = alloca i64, align 8
  %8 = alloca i64, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %4, align 8
  store i64 %1, i64* %5, align 8
  store i8* %2, i8** %6, align 8
  %9 = load %"class.std::vector.8"*, %"class.std::vector.8"** %4, align 8
  %10 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(%"class.std::vector.8"* %9) #3
  %11 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(%"class.std::vector.8"* %9) #3
  %12 = sub i64 %10, %11
  %13 = load i64, i64* %5, align 8
  %14 = icmp ult i64 %12, %13
  br i1 %14, label %15, label %17

; <label>:15:                                     ; preds = %3
  %16 = load i8*, i8** %6, align 8
  call void @_ZSt20__throw_length_errorPKc(i8* %16) #16
  unreachable

; <label>:17:                                     ; preds = %3
  %18 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(%"class.std::vector.8"* %9) #3
  %19 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(%"class.std::vector.8"* %9) #3
  store i64 %19, i64* %8, align 8
  %20 = call dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8) %8, i64* dereferenceable(8) %5)
  %21 = load i64, i64* %20, align 8
  %22 = add i64 %18, %21
  store i64 %22, i64* %7, align 8
  %23 = load i64, i64* %7, align 8
  %24 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE4sizeEv(%"class.std::vector.8"* %9) #3
  %25 = icmp ult i64 %23, %24
  br i1 %25, label %30, label %26

; <label>:26:                                     ; preds = %17
  %27 = load i64, i64* %7, align 8
  %28 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(%"class.std::vector.8"* %9) #3
  %29 = icmp ugt i64 %27, %28
  br i1 %29, label %30, label %32

; <label>:30:                                     ; preds = %26, %17
  %31 = call i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(%"class.std::vector.8"* %9) #3
  br label %34

; <label>:32:                                     ; preds = %26
  %33 = load i64, i64* %7, align 8
  br label %34

; <label>:34:                                     ; preds = %32, %30
  %35 = phi i64 [ %31, %30 ], [ %33, %32 ]
  ret i64 %35
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZN9__gnu_cxxmiIPP11NExpressionSt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_(%"class.__gnu_cxx::__normal_iterator.17"* dereferenceable(8), %"class.__gnu_cxx::__normal_iterator.17"* dereferenceable(8)) #7 comdat {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.17"*, align 8
  %4 = alloca %"class.__gnu_cxx::__normal_iterator.17"*, align 8
  store %"class.__gnu_cxx::__normal_iterator.17"* %0, %"class.__gnu_cxx::__normal_iterator.17"** %3, align 8
  store %"class.__gnu_cxx::__normal_iterator.17"* %1, %"class.__gnu_cxx::__normal_iterator.17"** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator.17"*, %"class.__gnu_cxx::__normal_iterator.17"** %3, align 8
  %6 = call dereferenceable(8) %class.NExpression*** @_ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.17"* %5) #3
  %7 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %8 = load %"class.__gnu_cxx::__normal_iterator.17"*, %"class.__gnu_cxx::__normal_iterator.17"** %4, align 8
  %9 = call dereferenceable(8) %class.NExpression*** @_ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.17"* %8) #3
  %10 = load %class.NExpression**, %class.NExpression*** %9, align 8
  %11 = ptrtoint %class.NExpression** %7 to i64
  %12 = ptrtoint %class.NExpression** %10 to i64
  %13 = sub i64 %11, %12
  %14 = sdiv exact i64 %13, 8
  ret i64 %14
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt6vectorIP11NExpressionSaIS1_EE5beginEv(%"class.std::vector.8"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.17", align 8
  %3 = alloca %"class.std::vector.8"*, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %3, align 8
  %4 = load %"class.std::vector.8"*, %"class.std::vector.8"** %3, align 8
  %5 = bitcast %"class.std::vector.8"* %4 to %"struct.std::_Vector_base.9"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base.9", %"struct.std::_Vector_base.9"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl", %"struct.std::_Vector_base<NExpression *, std::allocator<NExpression *> >::_Vector_impl"* %6, i32 0, i32 0
  call void @_ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.17"* %2, %class.NExpression*** dereferenceable(8) %7) #3
  %8 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %2, i32 0, i32 0
  %9 = load %class.NExpression**, %class.NExpression*** %8, align 8
  ret %class.NExpression** %9
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt34__uninitialized_move_if_noexcept_aIPP11NExpressionS2_SaIS1_EET0_T_S5_S4_RT1_(%class.NExpression**, %class.NExpression**, %class.NExpression**, %"class.std::allocator.10"* dereferenceable(1)) #4 comdat {
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca %class.NExpression**, align 8
  %8 = alloca %"class.std::allocator.10"*, align 8
  %9 = alloca %"class.std::move_iterator.18", align 8
  %10 = alloca %"class.std::move_iterator.18", align 8
  store %class.NExpression** %0, %class.NExpression*** %5, align 8
  store %class.NExpression** %1, %class.NExpression*** %6, align 8
  store %class.NExpression** %2, %class.NExpression*** %7, align 8
  store %"class.std::allocator.10"* %3, %"class.std::allocator.10"** %8, align 8
  %11 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %12 = call %class.NExpression** @_ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_(%class.NExpression** %11)
  %13 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %9, i32 0, i32 0
  store %class.NExpression** %12, %class.NExpression*** %13, align 8
  %14 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %15 = call %class.NExpression** @_ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_(%class.NExpression** %14)
  %16 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %10, i32 0, i32 0
  store %class.NExpression** %15, %class.NExpression*** %16, align 8
  %17 = load %class.NExpression**, %class.NExpression*** %7, align 8
  %18 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %8, align 8
  %19 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %9, i32 0, i32 0
  %20 = load %class.NExpression**, %class.NExpression*** %19, align 8
  %21 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %10, i32 0, i32 0
  %22 = load %class.NExpression**, %class.NExpression*** %21, align 8
  %23 = call %class.NExpression** @_ZSt22__uninitialized_copy_aISt13move_iteratorIPP11NExpressionES3_S2_ET0_T_S6_S5_RSaIT1_E(%class.NExpression** %20, %class.NExpression** %22, %class.NExpression** %17, %"class.std::allocator.10"* dereferenceable(1) %18)
  ret %class.NExpression** %23
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local dereferenceable(8) %class.NExpression*** @_ZNK9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEE4baseEv(%"class.__gnu_cxx::__normal_iterator.17"*) #7 comdat align 2 {
  %2 = alloca %"class.__gnu_cxx::__normal_iterator.17"*, align 8
  store %"class.__gnu_cxx::__normal_iterator.17"* %0, %"class.__gnu_cxx::__normal_iterator.17"** %2, align 8
  %3 = load %"class.__gnu_cxx::__normal_iterator.17"*, %"class.__gnu_cxx::__normal_iterator.17"** %2, align 8
  %4 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %3, i32 0, i32 0
  ret %class.NExpression*** %4
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local void @_ZNSt16allocator_traitsISaIP11NExpressionEE7destroyIS1_EEvRS2_PT_(%"class.std::allocator.10"* dereferenceable(1), %class.NExpression**) #4 comdat align 2 {
  %3 = alloca %"class.std::allocator.10"*, align 8
  %4 = alloca %class.NExpression**, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %3, align 8
  store %class.NExpression** %1, %class.NExpression*** %4, align 8
  %5 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %3, align 8
  %6 = bitcast %"class.std::allocator.10"* %5 to %"class.__gnu_cxx::new_allocator.11"*
  %7 = load %class.NExpression**, %class.NExpression*** %4, align 8
  call void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator.11"* %6, %class.NExpression** %7)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNKSt6vectorIP11NExpressionSaIS1_EE8max_sizeEv(%"class.std::vector.8"*) #7 comdat align 2 {
  %2 = alloca %"class.std::vector.8"*, align 8
  store %"class.std::vector.8"* %0, %"class.std::vector.8"** %2, align 8
  %3 = load %"class.std::vector.8"*, %"class.std::vector.8"** %2, align 8
  %4 = bitcast %"class.std::vector.8"* %3 to %"struct.std::_Vector_base.9"*
  %5 = call dereferenceable(1) %"class.std::allocator.10"* @_ZNKSt12_Vector_baseIP11NExpressionSaIS1_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base.9"* %4) #3
  %6 = call i64 @_ZNSt16allocator_traitsISaIP11NExpressionEE8max_sizeERKS2_(%"class.std::allocator.10"* dereferenceable(1) %5) #3
  ret i64 %6
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local i64 @_ZNSt16allocator_traitsISaIP11NExpressionEE8max_sizeERKS2_(%"class.std::allocator.10"* dereferenceable(1)) #7 comdat align 2 {
  %2 = alloca %"class.std::allocator.10"*, align 8
  store %"class.std::allocator.10"* %0, %"class.std::allocator.10"** %2, align 8
  %3 = load %"class.std::allocator.10"*, %"class.std::allocator.10"** %2, align 8
  %4 = bitcast %"class.std::allocator.10"* %3 to %"class.__gnu_cxx::new_allocator.11"*
  %5 = call i64 @_ZNK9__gnu_cxx13new_allocatorIP11NExpressionE8max_sizeEv(%"class.__gnu_cxx::new_allocator.11"* %4) #3
  ret i64 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx17__normal_iteratorIPP11NExpressionSt6vectorIS2_SaIS2_EEEC2ERKS3_(%"class.__gnu_cxx::__normal_iterator.17"*, %class.NExpression*** dereferenceable(8)) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::__normal_iterator.17"*, align 8
  %4 = alloca %class.NExpression***, align 8
  store %"class.__gnu_cxx::__normal_iterator.17"* %0, %"class.__gnu_cxx::__normal_iterator.17"** %3, align 8
  store %class.NExpression*** %1, %class.NExpression**** %4, align 8
  %5 = load %"class.__gnu_cxx::__normal_iterator.17"*, %"class.__gnu_cxx::__normal_iterator.17"** %3, align 8
  %6 = getelementptr inbounds %"class.__gnu_cxx::__normal_iterator.17", %"class.__gnu_cxx::__normal_iterator.17"* %5, i32 0, i32 0
  %7 = load %class.NExpression***, %class.NExpression**** %4, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %7, align 8
  store %class.NExpression** %8, %class.NExpression*** %6, align 8
  ret void
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt22__uninitialized_copy_aISt13move_iteratorIPP11NExpressionES3_S2_ET0_T_S6_S5_RSaIT1_E(%class.NExpression**, %class.NExpression**, %class.NExpression**, %"class.std::allocator.10"* dereferenceable(1)) #4 comdat {
  %5 = alloca %"class.std::move_iterator.18", align 8
  %6 = alloca %"class.std::move_iterator.18", align 8
  %7 = alloca %class.NExpression**, align 8
  %8 = alloca %"class.std::allocator.10"*, align 8
  %9 = alloca %"class.std::move_iterator.18", align 8
  %10 = alloca %"class.std::move_iterator.18", align 8
  %11 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %5, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %11, align 8
  %12 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %6, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %12, align 8
  store %class.NExpression** %2, %class.NExpression*** %7, align 8
  store %"class.std::allocator.10"* %3, %"class.std::allocator.10"** %8, align 8
  %13 = bitcast %"class.std::move_iterator.18"* %9 to i8*
  %14 = bitcast %"class.std::move_iterator.18"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = bitcast %"class.std::move_iterator.18"* %10 to i8*
  %16 = bitcast %"class.std::move_iterator.18"* %6 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %15, i8* align 8 %16, i64 8, i1 false)
  %17 = load %class.NExpression**, %class.NExpression*** %7, align 8
  %18 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %9, i32 0, i32 0
  %19 = load %class.NExpression**, %class.NExpression*** %18, align 8
  %20 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %10, i32 0, i32 0
  %21 = load %class.NExpression**, %class.NExpression*** %20, align 8
  %22 = call %class.NExpression** @_ZSt18uninitialized_copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(%class.NExpression** %19, %class.NExpression** %21, %class.NExpression** %17)
  ret %class.NExpression** %22
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt32__make_move_if_noexcept_iteratorIP11NExpressionSt13move_iteratorIPS1_EET0_PT_(%class.NExpression**) #4 comdat {
  %2 = alloca %"class.std::move_iterator.18", align 8
  %3 = alloca %class.NExpression**, align 8
  store %class.NExpression** %0, %class.NExpression*** %3, align 8
  %4 = load %class.NExpression**, %class.NExpression*** %3, align 8
  call void @_ZNSt13move_iteratorIPP11NExpressionEC2ES2_(%"class.std::move_iterator.18"* %2, %class.NExpression** %4)
  %5 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %2, i32 0, i32 0
  %6 = load %class.NExpression**, %class.NExpression*** %5, align 8
  ret %class.NExpression** %6
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt18uninitialized_copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %"class.std::move_iterator.18", align 8
  %5 = alloca %"class.std::move_iterator.18", align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca i8, align 1
  %8 = alloca %"class.std::move_iterator.18", align 8
  %9 = alloca %"class.std::move_iterator.18", align 8
  %10 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %4, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %10, align 8
  %11 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %5, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %11, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  store i8 1, i8* %7, align 1
  %12 = bitcast %"class.std::move_iterator.18"* %8 to i8*
  %13 = bitcast %"class.std::move_iterator.18"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %12, i8* align 8 %13, i64 8, i1 false)
  %14 = bitcast %"class.std::move_iterator.18"* %9 to i8*
  %15 = bitcast %"class.std::move_iterator.18"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %14, i8* align 8 %15, i64 8, i1 false)
  %16 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %17 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %8, i32 0, i32 0
  %18 = load %class.NExpression**, %class.NExpression*** %17, align 8
  %19 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %9, i32 0, i32 0
  %20 = load %class.NExpression**, %class.NExpression*** %19, align 8
  %21 = call %class.NExpression** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP11NExpressionES5_EET0_T_S8_S7_(%class.NExpression** %18, %class.NExpression** %20, %class.NExpression** %16)
  ret %class.NExpression** %21
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPP11NExpressionES5_EET0_T_S8_S7_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat align 2 {
  %4 = alloca %"class.std::move_iterator.18", align 8
  %5 = alloca %"class.std::move_iterator.18", align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca %"class.std::move_iterator.18", align 8
  %8 = alloca %"class.std::move_iterator.18", align 8
  %9 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %4, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %9, align 8
  %10 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %5, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %10, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %11 = bitcast %"class.std::move_iterator.18"* %7 to i8*
  %12 = bitcast %"class.std::move_iterator.18"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = bitcast %"class.std::move_iterator.18"* %8 to i8*
  %14 = bitcast %"class.std::move_iterator.18"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %13, i8* align 8 %14, i64 8, i1 false)
  %15 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %16 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %7, i32 0, i32 0
  %17 = load %class.NExpression**, %class.NExpression*** %16, align 8
  %18 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %8, i32 0, i32 0
  %19 = load %class.NExpression**, %class.NExpression*** %18, align 8
  %20 = call %class.NExpression** @_ZSt4copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(%class.NExpression** %17, %class.NExpression** %19, %class.NExpression** %15)
  ret %class.NExpression** %20
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt4copyISt13move_iteratorIPP11NExpressionES3_ET0_T_S6_S5_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %"class.std::move_iterator.18", align 8
  %5 = alloca %"class.std::move_iterator.18", align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca %"class.std::move_iterator.18", align 8
  %8 = alloca %"class.std::move_iterator.18", align 8
  %9 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %4, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %9, align 8
  %10 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %5, i32 0, i32 0
  store %class.NExpression** %1, %class.NExpression*** %10, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %11 = bitcast %"class.std::move_iterator.18"* %7 to i8*
  %12 = bitcast %"class.std::move_iterator.18"* %4 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %11, i8* align 8 %12, i64 8, i1 false)
  %13 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %7, i32 0, i32 0
  %14 = load %class.NExpression**, %class.NExpression*** %13, align 8
  %15 = call %class.NExpression** @_ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NExpression** %14)
  %16 = bitcast %"class.std::move_iterator.18"* %8 to i8*
  %17 = bitcast %"class.std::move_iterator.18"* %5 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 8 %16, i8* align 8 %17, i64 8, i1 false)
  %18 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %8, i32 0, i32 0
  %19 = load %class.NExpression**, %class.NExpression*** %18, align 8
  %20 = call %class.NExpression** @_ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NExpression** %19)
  %21 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %22 = call %class.NExpression** @_ZSt14__copy_move_a2ILb1EPP11NExpressionS2_ET1_T0_S4_S3_(%class.NExpression** %15, %class.NExpression** %20, %class.NExpression** %21)
  ret %class.NExpression** %22
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt14__copy_move_a2ILb1EPP11NExpressionS2_ET1_T0_S4_S3_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %class.NExpression**, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  store %class.NExpression** %0, %class.NExpression*** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %7 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %8 = call %class.NExpression** @_ZSt12__niter_baseIPP11NExpressionET_S3_(%class.NExpression** %7)
  %9 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %10 = call %class.NExpression** @_ZSt12__niter_baseIPP11NExpressionET_S3_(%class.NExpression** %9)
  %11 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %12 = call %class.NExpression** @_ZSt12__niter_baseIPP11NExpressionET_S3_(%class.NExpression** %11)
  %13 = call %class.NExpression** @_ZSt13__copy_move_aILb1EPP11NExpressionS2_ET1_T0_S4_S3_(%class.NExpression** %8, %class.NExpression** %10, %class.NExpression** %12)
  ret %class.NExpression** %13
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt12__miter_baseIPP11NExpressionEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E(%class.NExpression**) #4 comdat {
  %2 = alloca %"class.std::move_iterator.18", align 8
  %3 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %2, i32 0, i32 0
  store %class.NExpression** %0, %class.NExpression*** %3, align 8
  %4 = call %class.NExpression** @_ZNKSt13move_iteratorIPP11NExpressionE4baseEv(%"class.std::move_iterator.18"* %2)
  %5 = call %class.NExpression** @_ZSt12__miter_baseIPP11NExpressionET_S3_(%class.NExpression** %4)
  ret %class.NExpression** %5
}

; Function Attrs: noinline optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt13__copy_move_aILb1EPP11NExpressionS2_ET1_T0_S4_S3_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #4 comdat {
  %4 = alloca %class.NExpression**, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca i8, align 1
  store %class.NExpression** %0, %class.NExpression*** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  store i8 1, i8* %7, align 1
  %8 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %9 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %10 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %11 = call %class.NExpression** @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(%class.NExpression** %8, %class.NExpression** %9, %class.NExpression** %10)
  ret %class.NExpression** %11
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIP11NExpressionEEPT_PKS5_S8_S6_(%class.NExpression**, %class.NExpression**, %class.NExpression**) #7 comdat align 2 {
  %4 = alloca %class.NExpression**, align 8
  %5 = alloca %class.NExpression**, align 8
  %6 = alloca %class.NExpression**, align 8
  %7 = alloca i64, align 8
  store %class.NExpression** %0, %class.NExpression*** %4, align 8
  store %class.NExpression** %1, %class.NExpression*** %5, align 8
  store %class.NExpression** %2, %class.NExpression*** %6, align 8
  %8 = load %class.NExpression**, %class.NExpression*** %5, align 8
  %9 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %10 = ptrtoint %class.NExpression** %8 to i64
  %11 = ptrtoint %class.NExpression** %9 to i64
  %12 = sub i64 %10, %11
  %13 = sdiv exact i64 %12, 8
  store i64 %13, i64* %7, align 8
  %14 = load i64, i64* %7, align 8
  %15 = icmp ne i64 %14, 0
  br i1 %15, label %16, label %23

; <label>:16:                                     ; preds = %3
  %17 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %18 = bitcast %class.NExpression** %17 to i8*
  %19 = load %class.NExpression**, %class.NExpression*** %4, align 8
  %20 = bitcast %class.NExpression** %19 to i8*
  %21 = load i64, i64* %7, align 8
  %22 = mul i64 8, %21
  call void @llvm.memmove.p0i8.p0i8.i64(i8* align 8 %18, i8* align 8 %20, i64 %22, i1 false)
  br label %23

; <label>:23:                                     ; preds = %16, %3
  %24 = load %class.NExpression**, %class.NExpression*** %6, align 8
  %25 = load i64, i64* %7, align 8
  %26 = getelementptr inbounds %class.NExpression*, %class.NExpression** %24, i64 %25
  ret %class.NExpression** %26
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZSt12__miter_baseIPP11NExpressionET_S3_(%class.NExpression**) #7 comdat {
  %2 = alloca %class.NExpression**, align 8
  store %class.NExpression** %0, %class.NExpression*** %2, align 8
  %3 = load %class.NExpression**, %class.NExpression*** %2, align 8
  ret %class.NExpression** %3
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local %class.NExpression** @_ZNKSt13move_iteratorIPP11NExpressionE4baseEv(%"class.std::move_iterator.18"*) #7 comdat align 2 {
  %2 = alloca %"class.std::move_iterator.18"*, align 8
  store %"class.std::move_iterator.18"* %0, %"class.std::move_iterator.18"** %2, align 8
  %3 = load %"class.std::move_iterator.18"*, %"class.std::move_iterator.18"** %2, align 8
  %4 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %3, i32 0, i32 0
  %5 = load %class.NExpression**, %class.NExpression*** %4, align 8
  ret %class.NExpression** %5
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZNSt13move_iteratorIPP11NExpressionEC2ES2_(%"class.std::move_iterator.18"*, %class.NExpression**) unnamed_addr #7 comdat align 2 {
  %3 = alloca %"class.std::move_iterator.18"*, align 8
  %4 = alloca %class.NExpression**, align 8
  store %"class.std::move_iterator.18"* %0, %"class.std::move_iterator.18"** %3, align 8
  store %class.NExpression** %1, %class.NExpression*** %4, align 8
  %5 = load %"class.std::move_iterator.18"*, %"class.std::move_iterator.18"** %3, align 8
  %6 = getelementptr inbounds %"class.std::move_iterator.18", %"class.std::move_iterator.18"* %5, i32 0, i32 0
  %7 = load %class.NExpression**, %class.NExpression*** %4, align 8
  store %class.NExpression** %7, %class.NExpression*** %6, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define linkonce_odr dso_local void @_ZN9__gnu_cxx13new_allocatorIP11NExpressionE7destroyIS2_EEvPT_(%"class.__gnu_cxx::new_allocator.11"*, %class.NExpression**) #7 comdat align 2 {
  %3 = alloca %"class.__gnu_cxx::new_allocator.11"*, align 8
  %4 = alloca %class.NExpression**, align 8
  store %"class.__gnu_cxx::new_allocator.11"* %0, %"class.__gnu_cxx::new_allocator.11"** %3, align 8
  store %class.NExpression** %1, %class.NExpression*** %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator.11"*, %"class.__gnu_cxx::new_allocator.11"** %3, align 8
  ret void
}

; Function Attrs: noinline uwtable
define internal void @_GLOBAL__sub_I_parser.cpp() #0 section ".text.startup" {
  call void @__cxx_global_var_init()
  ret void
}

attributes #0 = { noinline uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
attributes #4 = { noinline optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { argmemonly nounwind }
attributes #6 = { nobuiltin "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { nobuiltin nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #9 = { nounwind readonly "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #10 = { noreturn nounwind }
attributes #11 = { noinline noreturn nounwind }
attributes #12 = { noreturn "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #13 = { builtin }
attributes #14 = { builtin nounwind }
attributes #15 = { nounwind readonly }
attributes #16 = { noreturn }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 7.0.1-8 (tags/RELEASE_701/final)"}
