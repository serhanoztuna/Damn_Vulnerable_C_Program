#include <stdio.h>
#include <string.h>

void process_user() {
    char username[16];
    char role[8] = "user";

    printf("Enter your username: ");
    gets(username);   // ⚠️ Zafiyet: gets() sınır kontrolü yapmaz (CWE-242)

    if (strcmp(username, "admin") == 0) {
        strcpy(role, "admin");  // ⚠️ Zafiyet: role buffer'ı 8 byte, "admin" taşabilir
    }

    printf("Welcome %s, your role is: %s\n", username, role);
}

int main() {
    process_user();
    return 0;
}
