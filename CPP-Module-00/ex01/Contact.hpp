#include "header.h"

class Contact
{
    private:
        std::string _FirstName;
        std::string _LastName;
        std::string _Nickname;
        int         _PhoneNumber;
        std::string _DarkestSecret;

    public:
        // Setters
        void SetFirstName(std::string FirstName);
        void SetLastName(std::string LastName);
        void SetNickname(std::string Nickname);
        void SetPhoneNumber(int PhoneNumber);
        void SetDarkestSecret(std::string DarkestSecret);

        // Getters
        std::string FirstName();
        std::string LastName();
        std::string Nickname();
        int PhoneNumber();
        std::string DarkestSecret();
};
