#include "node.h"
#include "codegen.h"
#include "parser.hpp"

using namespace std;

void CodeGenContext::generateCode(NBlock& root) {
  std::cout << "Generating code...\n";
  ArrayRef<Type*> argTypes;
  FunctionType *ftype = FunctionType::get(Type::getVoidTy(globalContext), argTypes, false);
  mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
  BasicBlock *bblock = BasicBlock::Create(globalContext, "entry", mainFunction, 0);

  pushBlock(bblock);
  root.codeGen(*this);
  ReturnInst::Create(globalContext, bblock);
  popBlock();

  std::cout << "Code is generated.\n";
  llvm::legacy::PassManager pm;
  pm.add(createPrintModulePass(outs()));
  pm.run(*module);
}

//GenericValue CodeGenContext::runCode() {
//  std::cout << "Running code...n";
//  ExistingModuleProvider *mp = new ExistingModuleProvider(module);
//  ExecutionEngine *ee = ExecutionEngine::create(mp, false);
//  vector<GenericValue> noargs;
//  GenericValue v = ee->runFunction(mainFunction, noargs);
//  std::cout << "Code was run.n";
//  return v;
//}

static const Type *typeOf(const NIdentifier& type) {
  if (type.name.compare("int") == 0) {
    return Type::getInt64Ty(globalContext);
  }
  else if (type.name.compare("double") == 0) {
    return Type::getDoubleTy(globalContext);
  }
  return Type::getVoidTy(globalContext);
}

Value *NInteger::codeGen(CodeGenContext& context) {
  std::cout << "Createing integer: " << value << std::endl;
  return ConstantInt::get(Type::getInt64Ty(globalContext), value, true);
}

Value *NDouble::codeGen(CodeGenContext& context) {
  std::cout << "Creating double: " << value << std::endl;
  return ConstantFP::get(Type::getDoubleTy(globalContext), value);
}

Value *NIdentifier::codeGen(CodeGenContext& context) {
  std::cout << "Creating identifier reference: " << name << std::endl;
  if (context.locals().find(name) == context.locals().end()) {
    std::cerr << "undeclared variable " << name << std::endl;
    return NULL;
  }
  return new LoadInst(context.locals()[name], "", false, context.currentBlock());
}

Value *NMethodCall::codeGen(CodeGenContext& context) {
  Function *function  = context.module->getFunction(id.name.c_str());
  FunctionType *function_type = function->getFunctionType();
  if (function == NULL) {
    std::cerr << "no such function "  << id.name << std::endl;
  }
  std::vector<Value *> args;
  ExpressionList::const_iterator it;
  for (it = arguments.begin(); it != arguments.end(); ++it) {
    args.push_back((**it).codeGen(context));
  }
  //CallInst *call = CallInst::Create(function, args.begin(), args.end(), "", context.currentBlock());
  CallInst *call = CallInst::Create(function_type, (Value *)args.data(), nullptr, "", nullptr);
  std::cout << "Creating method call: " << id.name << std::endl;
  return call;
}

Value *NBinaryOperator::codeGen(CodeGenContext& context) {
  std::cout << "Creating binary operation " << op << std::endl;
  Instruction::BinaryOps instr;
  switch (op) {
  case TPLUS:       { instr = Instruction::Add; goto math; }
  case TMINUS:      { instr = Instruction::Sub; goto math; }                    
  case TMUL:        { instr = Instruction::Mul; goto math; }                    
  case TDIV:        { instr = Instruction::SDiv; goto math; }                           
  }
  return NULL;
math:
  return BinaryOperator::Create(instr, lhs.codeGen(context),
                                rhs.codeGen(context), "", context.currentBlock());
}

Value *NAssignment::codeGen(CodeGenContext& context) {
  std::cout << "Creating assignment for " << lhs.name << std::endl;
  if (context.locals().find(lhs.name) == context.locals().end()) {
    std::cerr << "undeclared variable " << lhs.name << std::endl;
    return NULL;    
  }
  return new StoreInst(rhs.codeGen(context), context.locals()[lhs.name], false, context.currentBlock());
}

Value *NBlock::codeGen(CodeGenContext& context) {
  StatementList::const_iterator it;
  Value *last = NULL;
  for (it = statements.begin(); it != statements.end(); ++it) {
    std::cout << "Generating code for " << typeid(**it).name() << std::endl;
    last = (**it).codeGen(context);
  }
  std::cout << "Creating block" << std::endl;
  return last;
}

Value *NVariableDeclaration::codeGen(CodeGenContext& context) {
  std::cout << "Creating variable declaration " << type.name << " " << id.name << std::endl;
 // AllocaInst *alloc = new AllocaInst(const_cast<Type *>(typeOf(type)), 0, nullptr, id.name.c_str(), nullptr);//context.currentBlock()->getTerminator());
  //context.locals()[id.name] = alloc;
  //if (assignmentExpr != NULL) {
  //  NAssignment assn(id, *assignmentExpr);
  //  assn.codeGen(context);
  //}
  return nullptr;
}

Value *NFunctionDeclaration::codeGen(CodeGenContext& context) {
  vector<const Type*> argTypes;
  VariableList::const_iterator it;
  for (it = arguments.begin(); it != arguments.end(); ++it) {
    argTypes.push_back(typeOf((**it).type));
  }
  //FunctionType *ftype = FunctionType::get(typeOf(type), argTypes, false);
  //Function *function = Function::Create(ftype, GlobalValue::InternalLinkage, id.name.c_str(), context.module);
  //BasicBlock *bblock = BasicBlock::Create(globalContext, "entry", function, 0);
  //
  //context.pushBlock(bblock);
  //for (it = arguments.begin(); it != arguments.end(); ++it) {
  //  (**it).codeGen(context);
  //}
  //
  //block.codeGen(context);
  //ReturnInst::Create(globalContext, bblock);

  //context.popBlock();
  //std::cout << "Creating function: " << id.name << std::endl;
  return nullptr;
}
