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
        return j.get<std::double_t>();
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



void print(const Student& student, std::ostream& os, unsigned max_name, unsigned max_group, unsigned max_avg, unsigned max_debt) {
    //сделать для остальных атрибутов student проверку
    os << "|" << std::left <<std::setw(max_name);
    if (student.name!="")
        os << student.name;
    else
        os << "null";

    os << "|" <<std::setw(max_group);
    if (student.group.type()==typeid(std::nullptr_t)){
        os << "null";
    } else if (student.group.type()==typeid(std::string)) {
        os << std::any_cast<std::string>(student.group);
    } else if (student.group.type()==typeid(std::size_t)){
        os << std::to_string(std::any_cast<std::size_t>(student.group));
    }

    os << "|" <<std::setw(max_avg);
    if (student.avg.type()==typeid(std::nullptr_t))
        os << "null";
    else if (student.avg.type()==typeid(std::string))
        os << std::any_cast<std::string>(student.avg);
    else if (student.avg.type()==typeid(std::double_t))
        os << std::to_string(std::any_cast<std::double_t>(student.avg));
    else if (student.avg.type()==typeid(std::size_t))
        os << std::to_string(std::any_cast<std::size_t>(student.avg));

    os << "|" <<std::setw(max_debt);
    if (student.debt.type()==typeid(std::nullptr_t)) {
        os << "null";
    } else if (student.debt.type()==typeid(std::string)) {
        os << std::any_cast<std::string>(student.debt);
    } else {
        os
          << std::any_cast< std::vector<std::string> >(student.debt).size()
          << " items";
    }
    os << "|";
}



void print(const std::vector<Student>& students, std::ostream& os) {
    unsigned max_name=0; unsigned max_group=0; unsigned max_avg=0; unsigned max_debt=0;
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

    std::string table_string;
    table_string+="|";
    table_string+=std::string(max_name,'-');
    table_string+="|";
    table_string+=std::string(max_group,'-');
    table_string+="|";
    table_string+=std::string(max_avg,'-');
    table_string+="|";
    table_string+=std::string(max_debt,'-');
    table_string+="|";

    os << table_string;
    os << "|" << std::left << std::setw(max_name) << "Name" << "|" << std::setw(max_group) << "Group" << "|"
       << std::setw(max_avg) << "Avg" << "|" << std::setw(max_debt) << "Debt" << "|";

    //сделать таблицу вывода
    for (auto const& student : students) {
        print(student, os, max_name, max_group, max_avg, max_debt);
    }
}



