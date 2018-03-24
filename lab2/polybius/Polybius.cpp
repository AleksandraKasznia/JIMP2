//
// Created by okasz on 09.03.18.
//

#include "Polybius.h"

std::map<char, std::string> crypt = {{' ',""},{'a',"11"},{'b',"12"},{'c',"13"},{'d',"14"},{'e',"15"},{'f',"21"},{'g',"22"},
                                     {'h',"23"},{'i',"24"},{'j',"24"},{'k',"25"},{'l',"31"},{'m',"32"},{'n',"33"},{'o',"34"},
                                     {'p',"35"},{'q',"41"},{'r',"42"},{'s',"43"},{'t',"44"},{'u',"45"},{'v',"51"},{'w',"52"},
                                     {'x',"53"},{'y',"54"},{'z',"55"}};
std::map<std::string, char> decrypt = {{"",' '},{"11",'a'},{"12",'b'},{"13",'c'},{"14",'d'},{"15",'e'},{"21",'f'},{"22",'g'},
                                       {"23",'h'},{"24",'i'},{"24",'j'},{"25",'k'},{"31",'l'},{"32",'m'},{"33",'n'},{"34",'o'},
                                       {"35",'p'},{"41",'q'},{"42",'r'},{"43",'s'},{"44",'t'},{"45",'u'},{"51",'v'},{"52",'w'},
                                       {"53",'x'},{"54",'y'},{"55",'z'}};

std::string PolybiusCrypt(std::string message){
    std::string crypted_message;
    int iterator = 0;

    while (message[iterator] != '\0'){
        if (message[iterator] == ' ' or (toascii('a') <= toascii(message[iterator]) and toascii(message[iterator])<= toascii('z'))){
            crypted_message += crypt[message[iterator]];
        }
        else{
            if (toascii('A') <= toascii(message[iterator]) and toascii(message[iterator]) <= toascii('Z')){
                crypted_message += crypt[tolower(message[iterator])];
            }
            else{
                crypted_message += message[iterator];
            }
        }
        iterator++;
    }

    return crypted_message;
}

std::string PolybiusDecrypt(std::string crypted){
    std::string decrypted_message, key;
    int iterator = 0;

    if (crypted.length() <= 1){
        return "";
    }

    while (crypted[iterator] != '\0'){
        key += crypted[iterator];
        key += crypted[iterator + 1];
        decrypted_message += decrypt[key];

        iterator += 2;
    }
    return decrypted_message;
}