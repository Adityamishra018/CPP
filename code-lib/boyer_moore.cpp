#include <string_view>  
#include <optional>  
#include <array> 
#include <iostream>  


struct SearchPattern {
    constexpr static std::size_t num_chars{ 256 };
    const std::string_view needle;
    std::array<char, num_chars> bad_char_table{};

    constexpr SearchPattern(const std::string_view needle) noexcept
        : needle(needle) {
       
        for (std::size_t i = 0; i < num_chars; i++) {
            bad_char_table[i] = needle.length();
        }
        for (std::size_t i = 0; i < needle.length(); i++) {
            bad_char_table[needle[i]] = needle.length() - i - 1;
        }
    }
};

[[nodiscard]] constexpr std::optional<std::size_t> boyer_moore_horspool (
    const SearchPattern& pattern,
    const std::string_view haystack) noexcept {
    for (std::size_t h = 0; h < haystack.length() - pattern.needle.length() + 1;) {
        
        bool found = true;
        for (std::size_t n = pattern.needle.length() - 1; ; n--) {
            
            if (haystack[h + n] != pattern.needle[n]) {
                
                found = false;
               
                h += pattern.bad_char_table[haystack[h + n]];
                break;
            }
            if (n == 0) {
                break;
            }
        }
        if (found) {
            return h;
        }
    }

    return std::nullopt;
}

int main() {
    constexpr SearchPattern needle{ "abc" };
    constexpr auto haystack = "aa abc ddef";
    constexpr auto index = boyer_moore_horspool(needle, haystack);
    static_assert(index == 3, "index is supposed to be 3!");

    if (index) {
        std::cout << "found at index " << index.value() << '\n';
    } else {
        std::cout << "not found" << '\n';
    }
}