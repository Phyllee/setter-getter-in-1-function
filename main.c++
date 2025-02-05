#include <iostream>
#include <variant>

struct NoValue{};

static std::ostream& operator<<(std::ostream& out, const std::variant<std::string, std::monostate>& var) {
        if (std::holds_alternative<std::string>(var))
                out << std::get<std::string>(var);
        else
                out << "No value set";
        return out;
}

class string_manipulation {
public:
        std::variant<std::string, std::monostate> set_get_str(const char* str = nullptr) {
                if (str != nullptr) {
                        this->str = str;
                        return {};
                }
                else
                        return this->str;
        }
private:
        std::string str;
};

int main() {
        string_manipulation p;
        p.set_get_str("Hello!");
        std::cout << p.set_get_str() << '\n';
}
