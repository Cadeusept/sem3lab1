//Copyright 2021 Matthew abobus1488822@yandex,ru

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_
#include <string>
#include <any>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iostream>

using json = nlohmann::json;

struct Student{
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

auto get_name(const json& j) -> std::string;

auto get_group(const json& j) -> std::any;

auto get_avg(const json& j) -> std::any;

auto get_debt(const json& j) -> std::any;

void from_json(const json& j, Student& s);

std::string get_str_from_name(std::string name);

std::string get_str_from_group(std::any group);

std::string get_str_from_avg(std::any avg);

std::string get_str_from_debt(std::any debt);

std::vector<Student> get_vector_from_json(json data);

void print(const Student& student, std::ostream& os,
           unsigned max_name, unsigned max_group,
           unsigned max_avg, unsigned max_debt);

void print(const std::vector<Student>& students, std::ostream& os);

void parse_json(std::string jsonPath);

#endif // INCLUDE_STUDENT_HPP_
