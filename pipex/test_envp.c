#include <stdio.h>
#include <string.h>

void print_env_var(char **envp, const char *var_name) {
    int len = strlen(var_name);

    for (int i = 0; envp[i]; i++) {
        if (strncmp(envp[i], var_name, len) == 0 && envp[i][len] == '=') {
            printf("%s\n", envp[i]);
            break;
        }
    }
}

int main(int argc, char **argv, char **envp) {
    printf("PATH: ");
    print_env_var(envp, "PATH");

    printf("HOME: ");
    print_env_var(envp, "HOME");

    printf("USER: ");
    print_env_var(envp, "USER");

    printf("PWD: ");
    print_env_var(envp, "PWD");

    printf("LANG: ");
    print_env_var(envp, "LANG");

    printf("SHELL: ");
    print_env_var(envp, "SHELL");

    return 0;
}

