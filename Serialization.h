//
// Created by kaszalek on 09.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H
#include<iostream>
#include <string>
#include<functional>
#include<vector>


namespace academia{
    class Serializable;

    class Serializer{
    public:
        Serializer(std::ostream *out);
        
        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

    private:
        std::ostream *out_;
    };
    
    class Serializable{
    public:
        virtual void Serialize(Serializer *serializer)const =0;
    private:
        
    };

    class Room:public Serializable{
    public:
        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM,
        };
        Room(int id, const std::string &name, Type room_type);

        void Serialize(Serializer *serializer) const override;

        std::string TypeToString(Room::Type type)const;
    private:
        int id_;
        std::string name_;
        Type type_;
    };


}


#endif //JIMP_EXERCISES_SERIALIZATION_H
