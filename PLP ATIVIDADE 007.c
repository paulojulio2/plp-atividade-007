#include <stdio.h>
#include <string.h>

#define MAX_NODES 100

struct Node {
    char name[50];
    char type[50];
    int value;
};

struct HashTable {
    struct Node nodes[MAX_NODES];
    int size;
};

void print_str(char *str) {
    printf("%s", str);
}

int hash_function(char *str) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum % MAX_NODES;
}

void add_node(struct HashTable *table, char *name, char *type, int value) {
    int index = hash_function(name);
    strcpy(table->nodes[index].name, name);
    strcpy(table->nodes[index].type, type);
    table->nodes[index].value = value;
    table->size++;
}

int find_node(struct HashTable *table, char *name) {
    int index = hash_function(name);
    if (strcmp(table->nodes[index].name, name) == 0) {
        return index;
    }
    return -1;
}

int main() {
    int b = 2, c = 3;
    int a = b + c;

    print_str("Valor de a: ");
    printf("%d\n", a);

    struct HashTable table = {{{0}}, 0};

    add_node(&table, "var1", "int", 10);
    add_node(&table, "var2", "float", 20);

    int index = find_node(&table, "var1");
    if (index >= 0) {
        printf("Valor de var1: %d\n", table.nodes[index].value);
    } else {
        print_str("Não foi possível encontrar var1\n");
    }

    return 0;
}
