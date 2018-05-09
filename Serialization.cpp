//
// Created by kaszalek on 09.05.18.
//

#include "Serialization.h"

namespace academia{
    Serializer::Serializer(std::ostream *out){
        out_ = out;
    }

    std::string Room::TypeToString(Room::Type type) const{
        switch(type) {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::LECTURE_HALL:
                return "LECTURE_HALL";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }
    }

    Room::Room(int id, const std::string &name, Type room_type){
        id_=id;
        name_=name;
        type_=room_type;
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->Footer("/room");
        serializer->IntegerField("id",id_);
        serializer->StringField("name",name_);
        serializer->StringField("type",TypeToString(type_));
    }
}