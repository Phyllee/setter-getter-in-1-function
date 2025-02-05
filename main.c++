#include <iostream>
#include <variant>
#include <string_view>
#include <cstring>

static std::ostream& operator<<(std::ostream& out, const std::variant<char*, std::monostate>& var) {
        if (std::holds_alternative<char*>(var))
                out << std::get<char*>(var);
        else
                out << "No value set";
        return out;
}

class string_manipulation {
public:
        string_manipulation() {
                str = new char[100];
                str_size = 100;
                str[0] = '\0';
        }

        ~string_manipulation() {
                delete[] str;
        }

        std::variant<char*, std::monostate> set_get_str(const char* str_param = nullptr) {
                if (str_param != nullptr) {
                        size_t new_size = strlen(str_param) + 1;

                        if (new_size >= str_size) {
                                str_size = new_size;
                                delete[] str;
                                str = new char[str_size];

                        }

                        strcpy(this->str, str_param);
                        return std::monostate{};
                }
                else
                        return this->str;
        }

private:
        char* str;
        size_t str_size;
};

int main() {
        string_manipulation p{};
        p.set_get_str("Hello! this is PhyllMpse");
        std::cout << p.set_get_str() << '\n';
}
