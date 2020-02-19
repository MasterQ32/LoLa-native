#include "compiler.hpp"
#include <cassert>
#include <cstring>
#include <iostream>
#include <iomanip>

std::shared_ptr<LoLa::Compiler::CompilationUnit> LoLa::Compiler::Compiler::compile(const LoLa::AST::Program &program) const
{
    auto cu = std::make_shared<CompilationUnit>();

    CodeWriter writer(cu.get());

    Scope global_scope;
    global_scope.is_global = true;
    for(auto const & stmt : program.statements)
        stmt->emit(writer, global_scope);
    writer.emit(IL::Instruction::ret); // implicit return at the end of the block

    cu->global_count = global_scope.max_variables;

    for(auto const & fn : program.functions)
    {
        auto const ep = cu->code.size();

        auto [ fun, created ] = cu->functions.emplace(fn.name, std::make_unique<ScriptFunction>(cu));
        fun->second->entry_point = ep;

        Scope scope;
        scope.is_global = false;
        scope.global_scope = &global_scope;

        for(auto const & param : fn.params)
            scope.declare(param);

        fn.body->emit(writer, scope);
        writer.emit(IL::Instruction::ret); // implicit return at the end of the function

        fun->second->local_count = scope.max_variables;
    }

    return cu;
}

LoLa::Compiler::CodeWriter::CodeWriter(LoLa::Compiler::CompilationUnit *target) :
    next_label { 1 },
    labels(),
    target(target),
    patches()
{

}

LoLa::Compiler::Label LoLa::Compiler::CodeWriter::createLabel()
{
    auto const lbl = next_label;
    next_label.value += 1;
    return lbl;
}

LoLa::Compiler::Label LoLa::Compiler::CodeWriter::createAndDefineLabel()
{
    auto lbl = createLabel();
    defineLabel(lbl);
    return lbl;
}

void LoLa::Compiler::CodeWriter::defineLabel(LoLa::Compiler::Label lbl)
{
    if(auto it = labels.find(lbl); it != labels.end())
        throw "label was already defined!";

    uint32_t const position = target->code.size();

    labels.emplace(lbl, position);

    // resolve all forward references to this label
    for(auto it = patches.begin(); it != patches.end();)
    {
        if(it->first == lbl)
        {
            assert(position >= it->second + sizeof(position));
            memcpy(&target->code[it->second], &position, sizeof(position));
            it = patches.erase(it);
        }
        else
        {
            it++;
        }
    }

}

void LoLa::Compiler::CodeWriter::emit(LoLa::Compiler::Label label)
{
    if(auto it = labels.find(label); it != labels.end())
    {
        emit(it->second);
    }
    else
    {
        patches.emplace_back(label, target->code.size());
        emit(~0U);
    }
}

void LoLa::Compiler::CodeWriter::emit(const void *data, size_t len)
{
    size_t offset = target->code.size();
    target->code.resize(offset + len);
    memcpy(&target->code[offset], data, len);
}

void LoLa::Compiler::CodeWriter::emit(IL::Instruction val) {
    emit(&val, sizeof val);
}
void LoLa::Compiler::CodeWriter::emit(double val) {
    emit(&val, sizeof val);
}
void LoLa::Compiler::CodeWriter::emit(std::string val) {
    assert(val.size() < 65536);
    emit(uint16_t(val.size()));
    emit(val.data(), val.size());
}
void LoLa::Compiler::CodeWriter::emit(uint8_t val) {
    emit(&val, sizeof val);
}
void LoLa::Compiler::CodeWriter::emit(uint16_t val) {
    emit(&val, sizeof val);
}
void LoLa::Compiler::CodeWriter::emit(uint32_t val) {
    emit(&val, sizeof val);
}

LoLa::Compiler::Scope::Scope()
{
    enter();
}

LoLa::Compiler::Scope::~Scope()
{
    leave();
    assert(return_point.size() == 0);
    assert(local_variables.size() == 0);
}

void LoLa::Compiler::Scope::enter()
{
    return_point.emplace_back(local_variables.size());
}

void LoLa::Compiler::Scope::leave()
{
    assert(not return_point.empty());
    local_variables.resize(return_point.back());
    return_point.pop_back();
}

void LoLa::Compiler::Scope::declare(const std::string &name)
{
    // TODO: Test here for shadowing
    local_variables.emplace_back(name);
    assert(local_variables.size() < 65536);
    max_variables = std::max<uint16_t>(max_variables, local_variables.size());
}

std::optional<std::pair<uint16_t, LoLa::Compiler::Scope::Type>>  LoLa::Compiler::Scope::get(std::string const & name) const
{
    if(local_variables.empty())
        return std::nullopt;
    size_t i = local_variables.size();
    while(i > 0)
    {
        i -= 1;
        if(local_variables[i] == name)
        {
            // only top-level variables in the global scope are really global ones
            if(is_global and ((return_point.size() <= 1) or (i < return_point.at(1))))
                return std::make_pair(uint16_t(i), Global);
            else
                return std::make_pair(uint16_t(i), Local);
        }
    }
    return std::nullopt;
}

void LoLa::Compiler::Disassembler::disassemble(const LoLa::Compiler::CompilationUnit &cu, std::ostream &stream) const
{
    CodeReader reader;
    reader.code = &cu;
    reader.offset = 0;

    auto const putprefix = [&]() {
        stream << std::setw(6) << std::setfill('0') << std::uppercase << std::hex << reader.offset << "\t";
    };

    putprefix();
    stream << "<main>:" << std::endl;
    while(reader.offset < cu.code.size())
    {
        for(auto const & ep : cu.functions)
        {
            if(ep.second->entry_point != reader.offset)
                continue;
            putprefix();
            stream << ep.first << ":" << std::endl;
            break;
        }

        putprefix();
        stream << "\t";

        disassemble_instruction(reader, stream);

        stream << std::endl;
    }
}

void LoLa::Compiler::Disassembler::disassemble_instruction(LoLa::Compiler::CodeReader &reader, std::ostream &stream) const
{
    using IL::Instruction;

    auto const instr = reader.fetch_instruction();
    switch(instr)
    {
    case Instruction::nop:          stream << "nop" ; return;
    case Instruction::pop:          stream << "pop" ; return;
    case Instruction::eq:           stream << "eq" ; return;
    case Instruction::neq:          stream << "neq" ; return;
    case Instruction::less:         stream << "less" ; return;
    case Instruction::less_eq:      stream << "less_eq" ; return;
    case Instruction::greater:      stream << "greater" ; return;
    case Instruction::greater_eq:   stream << "greater_eq" ; return;
    case Instruction::add:          stream << "add" ; return;
    case Instruction::sub:          stream << "sub" ; return;
    case Instruction::mul:          stream << "mul" ; return;
    case Instruction::div:          stream << "div" ; return;
    case Instruction::mod:          stream << "mod" ; return;
    case Instruction::bool_or:      stream << "or" ; return;
    case Instruction::bool_and:     stream << "and" ; return;
    case Instruction::bool_not:     stream << "not" ; return;
    case Instruction::negate:       stream << "negate" ; return;
    case Instruction::iter_make:    stream << "iter_make" ; return;
    case Instruction::iter_next:    stream << "iter_next" ; return;
    case Instruction::ret:          stream << "ret" ; return;
    case Instruction::retval:       stream << "retval" ; return;
    case Instruction::array_store:  stream << "array_store" ; return;
    case Instruction::array_load:   stream << "array_load" ; return;

    case Instruction::store_global_name: // [ var:str ]
        stream << "store_global " << reader.fetch_string() ;
        return;
    case Instruction::load_global_name: // [ var:str ]
        stream << "load_global " << reader.fetch_string() ;
        return;
    case Instruction::store_global_idx: // [ idx:u16 ]
        stream << "store_global " << reader.fetch_u16() ;
        return;
    case Instruction::load_global_idx: // [ idx:u16 ]
        stream << "load_global " << reader.fetch_u16() ;
        return;
    case Instruction::push_str: // [ val:str ]
        stream << "push_str '" << reader.fetch_string() << "'" ;
        return;
    case Instruction::push_num: // [ val:f64 ]
        stream << "push_num " << reader.fetch_number() ;
        return;
    case Instruction::array_pack: // [ num:u16 ]
        stream << "array_pack " << reader.fetch_u16() ;
        return;
    case Instruction::call_fn: // calls a function [ fun:str ] [argc:u8 ]
        stream << "call_fn " << reader.fetch_string() << ", " << int(reader.fetch_u8()) ;
        return;
    case Instruction::call_obj: // [ fun:str ] [argc:u8 ]
        stream << "call_obj " << reader.fetch_string() << ", " << int(reader.fetch_u8()) ;
        return;
    case Instruction::jmp: // [ target:u32 ]
        stream << "jmp " << reader.fetch_u32() ;
        return;
    case Instruction::jnf : // [ target:u32 ]
        stream << "jnf " << reader.fetch_u32() ;
        return;
    case Instruction::jif: // [ target:u32 ]
        stream << "jif " << reader.fetch_u32() ;
        return;
    case Instruction::store_local: // [ index : u16 ]
        stream << "store_local " << int(reader.fetch_u16()) ;
        return;
    case Instruction::load_local: // [ index : u16 ]
        stream << "load_local " << int(reader.fetch_u16()) ;
        return;
    }
    assert(false and "unhandled instruction");
}





void LoLa::Compiler::CodeReader::fetch_buffer(void *target, size_t len)
{
    if(offset + len > code->code.size())
        throw Error::InvalidPointer;
    memcpy(target, &code->code[offset], len);
    offset += len;
}

LoLa::IL::Instruction LoLa::Compiler::CodeReader::fetch_instruction()
{
    LoLa::IL::Instruction i;
    fetch_buffer(&i, sizeof i);
    return i;
}

std::string LoLa::Compiler::CodeReader::fetch_string()
{
    auto const len = fetch_u16();

    std::string value(len, '?');
    fetch_buffer(value.data(), len);
    return value;
}

double LoLa::Compiler::CodeReader::fetch_number()
{
    double i;
    fetch_buffer(&i, sizeof i);
    return i;
}

uint8_t LoLa::Compiler::CodeReader::fetch_u8()
{
    uint8_t i;
    fetch_buffer(&i, sizeof i);
    return i;
}

uint16_t LoLa::Compiler::CodeReader::fetch_u16()
{
    uint16_t i;
    fetch_buffer(&i, sizeof i);
    return i;
}

uint32_t LoLa::Compiler::CodeReader::fetch_u32()
{
    uint32_t i;
    fetch_buffer(&i, sizeof i);
    return i;
}

#include "runtime.hpp"

LoLa::Compiler::ScriptFunction::ScriptFunction(std::weak_ptr<const CompilationUnit> code) :
    code(code)
{

}

LoLa::Runtime::Function::CallOrImmediate LoLa::Compiler::ScriptFunction::call(LoLa::Runtime::Value const * args, size_t argc) const
{
    auto ptr = std::make_unique<LoLa::Runtime::VirtualMachine::ExecutionContext>();

    ptr->code = code.lock().get();
    ptr->offset = entry_point;
    ptr->locals.resize(local_count);
    assert(argc <= local_count);
    for(size_t i = 0; i < argc; i++)
        ptr->locals[i] = args[i];

    return ptr;
}

void LoLa::Compiler::CompilationUnit::save(std::ostream &stream)
{
    uint32_t version = 1;
    std::array<char, 256> comment { "Created with NativeLola.cpp" };

    stream.write("LoLa\xB9\x40\x80\x5A", 8);
    stream.write(reinterpret_cast<char const *>(&version), 4);
    stream.write(comment.data(), comment.size());

    uint16_t globalCount = this->global_count;
    stream.write(reinterpret_cast<char const *>(&globalCount), 2);

    uint16_t functionCount = static_cast<uint16_t>(this->functions.size());
    stream.write(reinterpret_cast<char const *>(&functionCount), 2);

    uint32_t codeSize = static_cast<uint32_t>( this->code.size() );
    stream.write(reinterpret_cast<char const *>(&codeSize), 4);

    uint32_t numDebugSymbols = static_cast<uint32_t>( 0 );
    stream.write(reinterpret_cast<char const *>(&numDebugSymbols), 4);

    for(auto const & fnpair : this->functions)
    {
        std::array<char, 256> name;
        strncpy(name.data(), fnpair.first.c_str(), name.size());
        stream.write(name.data(), name.size());

        uint32_t ep = fnpair.second->entry_point;
        stream.write(reinterpret_cast<char const *>(&ep), 4);

        uint16_t localCount = fnpair.second->local_count;
        stream.write(reinterpret_cast<char const *>(&localCount), 2);
    }

    stream.write(reinterpret_cast<char const *>(this->code.data()), this->code.size());
}
