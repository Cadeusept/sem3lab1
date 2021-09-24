#include "student.hpp"

auto get_name(const json& j) -> std::string {
    if (j.is_null())
        return "";
    else
        return j.get<std::string>();
}

auto get_group(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else
        return j.get<std::size_t>();
}

auto get_avg(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else if (j.is_number_float())
        return j.get<double>();
    else
        return j.get<std::size_t>();
}

auto get_debt(const json& j) -> std::any {
    if (j.is_null())
        return nullptr;
    else if (j.is_string())
        return j.get<std::string>();
    else
        return j.get<std::vector<std::string> >();
}

void from_json(const json& j, Student& s) {
    s.name = get_name(j.at("name"));
    s.group = get_group(j.at("group"));
    s.avg = get_avg(j.at("avg"));
    s.debt = get_debt(j.at("debt"));
}

void print(const Student& student, std::ostream& os) {
    //сделать для остальных атрибутов student проверку
    if (student.name!="")
        os << student.name;
    else
        os << "null";

    if (student.group.type()==typeid(std::nullptr_t)){
        os << "null";
    } else if (student.group.type()==typeid(std::string)) {
        os << std::any_cast<std::string>(student.group);
    } else if (student.group.type()==typeid(std::size_t)){
        os << std::to_string(std::any_cast<std::size_t>(student.group));
    }

    if (student.avg.type()==typeid(std::nullptr_t))
        os << "null";
    else if (student.avg.type()==typeid(std::string))
        os << std::any_cast<std::string>(student.avg);
    else if (student.avg.type()==typeid(std::double_t))
        os << std::to_string(std::any_cast<std::double_t>(student.avg));
    else if (student.avg.type()==typeid(std::size_t))
        os << std::to_string(std::any_cast<std::size_t>(student.avg));

    if (student.debt.type()==typeid(std::nullptr_t)) {
        os << "null";
    } else if (student.debt.type()==typeid(std::string)) {
        os << std::any_cast<std::string>(student.debt);
    } else {
        os
          << std::any_cast< std::vector<std::string> >(student.debt).size()
          << " items";
    }
}

void print(const std::vector<Student>& students, std::ostream& os) {
    unsigned long max_name=0; unsigned long max_group=0; unsigned long max_avg=0; unsigned long max_debt=0;
    for (auto const& student : students){
        if (student.name.length()>max_name) max_name=student.name.length();
        if (std::any_cast<std::string>(student.group).length()>max_group)
            max_group=std::any_cast<std::string>(student.group).length();
        if (std::any_cast<std::string>(student.avg).length()>max_avg)
            max_avg=std::any_cast<std::string>(student.avg).length();
        if ((student.debt.type() == typeid(std::string) && std::any_cast<std::string>(student.debt).length()>max_debt)
        || (student.debt.type() != typeid(std::string) && (student.debt.type() != typeid(std::nullptr_t) &&
        std::to_string(std::any_cast< std::vector<std::string> >(student.debt).size()).length()>max_debt)))
            max_debt=std::to_string(std::any_cast< std::vector<std::string> >(student.debt).size()).length();
    }



    //сделать таблицу вывода
    for (auto const& student : students) {
        print(student, os);
    }
}



