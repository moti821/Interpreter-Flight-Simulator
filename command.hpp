#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#include "server.hpp"
#include "lexer.hpp"
#include "data_base.hpp"





class Command
{
public:
    virtual int do_command(int) = 0;
};


class OpenServerCommand : public Command
{
public:
    virtual int do_command(int);
};


class ConnectCommand : public Command
{
public:
    virtual int do_command(int);
};


class VarCommand : public Command
{
public:
    VarCommand(){}
    virtual int do_command(int);
    static std::unordered_map <std::string, std::string> variable;
private:
};


class EqualCommand : public Command
{
public:
    virtual int do_command(int);
};


class WhileCommand : public Command
{
public:
    virtual int do_command(int);
    void create_vec_line(int);
    int next_line();
private:
    std::vector<int> vec_lines_to_while;
};


class PrintCommand : public Command
{
public:
    virtual int do_command(int);
};


class SleepCommand : public Command
{
public:
    virtual int do_command(int);
};