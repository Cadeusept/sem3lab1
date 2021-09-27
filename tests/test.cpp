// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <student.hpp>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Exceptions, Unable_to_open_1){
    EXPECT_THROW(parse_json(TEST_FILE1_DIR),std::runtime_error);
}

TEST(Exceptions, Unexpected_group_type){
    EXPECT_THROW(get_str_from_group(3.14),std::invalid_argument);
}

TEST(Exceptions, Unexpected_avg_type){
    EXPECT_THROW(get_str_from_avg("ABOBA"),std::invalid_argument);
}

TEST(Exceptions, Unexpected_debt_type){
    EXPECT_THROW(get_str_from_debt(3.14),std::invalid_argument);
}

TEST(Equality, EqualityTest1){
    std::vector<Student> students;
    for (auto const& item : data.at("items")) {
        Student student;
        from_json(item, student);
        students.push_back(student);
    }
    std::stringstream parsed;

    EXPECT_EQ();
}