#ifndef CHAT_USER_HPP
#define CHAT_USER_HPP

#include <string>

namespace Internal {

    struct User final {
        // Lifetime management

        User();

        User(std::size_t id);

        // Methods

        std::string AsJSON() const;

        static User FromJSON(const std::string& json);

    public:
        // Properties

        const std::size_t m_id;
        std::size_t m_chatroom;
        std::string m_username;

    private:
        inline static std::size_t m_instance { 0 }; 
    };
}

#endif // CHAT_USER_HPP