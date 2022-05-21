#include <string>
#include <iostream>
std::string run_length_encode(const std::string& uncompressed) {
    // TODO: Rewrite the body of this function so that it actually works. That
    // includes rewriting the return statement. After you do that, delete this
    // comment.
    int dup = 0;
    std::string compressed = "";

    for (int idx = 1; idx < uncompressed.length(); idx++) {
        if (uncompressed.at(idx - 1) == uncompressed.at(idx)) {
            ++dup;
        }
        else {
            if (dup > 0) {
                compressed += std::to_string(dup + 1);
                compressed += uncompressed.at(idx - 1);
                dup = 0;
            }
            else {
                compressed += uncompressed.at(idx - 1);
            }
        }
        if (idx == uncompressed.length() - 1) {
            if (uncompressed.at(idx - 1) == uncompressed.at(idx)) {
                compressed += std::to_string(dup + 1);
                compressed += uncompressed.at(idx - 1);
                dup = 0;
            }
        }
    }
    return compressed;
}

int main() {
    std::string uncomp = "aabbbcd";
    std::cout << run_length_encode(uncomp);
}