//
// Created by okasz on 23.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
using ::std::experimental::optional;
using ::std::experimental::make_optional;
using ::std::string;
using ::std::cout;
using ::std::endl;
using namespace std::string_literals;

namespace nets {
    class JsonValue {
    public:
        JsonValue();
        JsonValue(int val_integer);
        JsonValue(double val_float);
        JsonValue(bool val_bool);
        JsonValue(string val_string);
        JsonValue(std::vector<JsonValue> val_vector);
        JsonValue(std::map<string, JsonValue> val_object);
        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        optional<int> json_int_;
        optional<double> json_float_;
        optional<string> json_string_;
        optional<bool> json_bool_;
        optional<std::vector<JsonValue>> json_vector_;
        optional<std::map<string, JsonValue>> json_object_;

    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
