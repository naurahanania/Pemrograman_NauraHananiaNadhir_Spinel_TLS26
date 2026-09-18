#include <iostream>

int get_length(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int get_mod(int a, int b) {
    return a % b;
}

void encrypt_message(char msg[]) {
    int len = get_length(msg);
    if (len <= 1) return;

    for (int i = len - 1; i >= 1; i--) {
        char prev_char = msg[i - 1];
        char curr_char = msg[i];

        if (curr_char >= 'a' && curr_char <= 'z') {
            curr_char = curr_char - 'a' + 'A';
        }
        if (prev_char >= 'a' && prev_char <= 'z') {
            prev_char = prev_char - 'a' + 'A';
        }

        if (curr_char >= 'A' && curr_char <= 'Z' && prev_char >= 'A' && prev_char <= 'Z') {
            int curr_val = curr_char - 'A' + 1;
            int prev_val = prev_char - 'A' + 1;

            int new_val = get_mod(curr_val + prev_val - 1, 26);
            if (new_val == 0) new_val = 26;

            msg[i] = (char)(new_val - 1 + 'A');
        }
    }
}

int main() {
    char message[1000];
    std::cout << "Masukkan pesan: ";
    std::cin >> message;

    encrypt_message(message);

    std::cout << "Pesan terenkripsi: " << message << std::endl;

    return 0;
}