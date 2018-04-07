//
// Created by okasz on 23.03.2018.
//

#include "SimpleJson.h"


namespace nets{
    JsonValue::JsonValue(){

    }

    JsonValue::JsonValue(int val_integer) {
        json_int_ = val_integer;
    }
    JsonValue::JsonValue(double val_float) {
        json_float_ = val_float;
    }
    JsonValue::JsonValue(bool val_bool) {
        json_bool_ = val_bool;
    }
    JsonValue::JsonValue(string val_string) {
        json_string_ = val_string;
    }

    JsonValue::JsonValue(std::vector<JsonValue> val_vector) {
        json_vector_ = val_vector;
    }

    JsonValue::JsonValue(std::map<string, JsonValue> val_object) {
        json_object_ = val_object;
    }

    JsonValue::~JsonValue() {

    }

    std::string JsonValue::ToString() const{
        if (json_int_){
            return std::to_string(*json_int_);
        }
        else if (json_float_){
            std::stringstream stringstream;
            stringstream << std::defaultfloat << *json_float_;
            return stringstream.str();
        }
        else if (json_string_){
            string current = *json_string_;
            for (int i=0; i<current.length(); ++i){
                if (current[i] == '\"' || current[i] == '\\'){
                    current.insert(i, 1, '\\');
                    ++i;
                }
            }
            return "\""+current+"\"";
        }
        else if(json_vector_){
            if (*json_bool_){
                return "true";
            }
            else{
                return "false";
            }
        }
        else if (json_vector_){
            string output = "[";
            bool first = true;
            for (auto const& value : *json_vector_){
                if (!first){
                    output+=", ";
                }
                else{
                    first = false;
                }
                output+=value.ToString();
            }
            output+="]";
            return output;
        }
        else if(json_object_){
            string output ="{";

            for (auto const& value : *json_object_){
                string current = value.first;

                for (int i=0; i<current.length(); i++){
                    if (current[i] == '\"' || current[i] == '\\'){
                        current.insert(i,1,'\\');
                        ++i;
                    }
                }

                output+="\""+current+"\":"+value.second.ToString()+", ";
            }
            output = output.substr(0,output.length()-2)+'}';
            return output;
        }
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        for (auto const& value: *json_object_){
            if (value.first == name){
                return value.second;
            }
        }
        return optional<JsonValue>();
    }
}