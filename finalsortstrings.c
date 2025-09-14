#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct link {
    char *strn;
    struct link *next;
};

struct base {
    struct link *head;
};

int findPos(char *str) {
    int pos;
    if (str[0] < 65 || (str[0] > 90 && str[0] < 97) || str[0] > 122) return -1;
    if (str[0] <= 90) pos = str[0] - 65;
    else pos = str[0] - 71;
    return pos;
}

struct base **ssCreate(void) {
    struct base **ss = malloc(52*sizeof(struct base *));
    for (int i = 0; i < 52; i++) ss[i] = NULL;
    return ss;
}

struct base **ssAddinOrder(struct base **ss, char *str) {
    int pos = findPos(str);
    if (pos < 0) return ss;
    if (!ss[pos]) {
        ss[pos] = malloc(sizeof(struct base));
        ss[pos]->head = malloc(sizeof(struct link));
        ss[pos]->head->strn = str;
        ss[pos]->head->next = NULL;
        return ss;
    }
    struct link *node = ss[pos]->head;
    struct link *prev = NULL;
    while (node) {
        if (!strcmp(str, node->strn)) return ss;
        else if (strcmp(str, node->strn) > 0) {
            if (!node->next) {
                struct link *newnode = malloc(sizeof(struct link));
                newnode->next = node->next;
                newnode->strn = str;
                node->next = newnode;
                return ss;
            }
        }
        else if (strcmp(str, node->strn) < 0) {
            struct link *newnode = malloc(sizeof(struct link));
            newnode->next = node;
            newnode->strn = str;
            if (!prev) ss[pos]->head = newnode;
            else prev->next = newnode;
            return ss;
        }
        if (!prev) prev = ss[pos]->head;
        else prev = prev->next;
        node = node->next;
    }
    return ss;
}

struct base **ssRemove(struct base **ss, char *str) {
    if (!str) return ss;
    int pos = findPos(str);
    if (pos < 0) return ss;
    struct link *node = ss[pos]->head;
    while (node) {
        if (!node->next) {
            if (!strcmp(str, node->strn)) {
                free(node);
                free(ss[pos]);
                ss[pos] = NULL;
            }
            return ss;
        }
        if (!strcmp(str, node->next->strn)) {
            struct link *temp = node->next->next;
            free(node->next);
            node->next = temp;
            return ss;
        }
        node = node->next;
    }
    return ss;
}

void ssPrintchar(struct base **ss, char c) {
    int pos;
    if (c < 65 || (c > 90 && c < 97) || c > 122) return;
    else if (c <= 90) pos = c - 65;
    else pos = c - 71;
    if (!ss[pos]) return;
    struct link *node = ss[pos]->head;
    while(node) {
        printf("%s\n", node->strn);
        node = node->next;
    }
    return;
}

void ssPrintall(struct base **ss) {
    for (int pos = 0; pos < 52; pos++) {
        if (ss[pos]) {
            // printf("%d\n", ss[pos]);
            struct link *node = ss[pos]->head;
            while(node) {
                printf("%s\n", node->strn);
                node = node->next;
            }
        }
    }
    return;
}

void ssDelete(struct base **ss) {
    for (int pos = 0; pos < 52; pos++) {
        if(ss[pos]) {
            struct link *node = ss[pos]->head;
            while(node) {
                struct link *temp = node->next;
                free(node);
                node = temp;
            }
            free(ss[pos]);
            ss[pos] = NULL;
        }
    }
    free(ss);
    ss = NULL;
}

int main(void) {
    struct base **ss = ssCreate();
    ssAddinOrder(ss, "ART");
    ssAddinOrder(ss, "Apple");
    ssAddinOrder(ss, "First");
    ssAddinOrder(ss, "Fuzzy");
    ssAddinOrder(ss, "Fun");
    ssPrintchar(ss, 'F');
    ssAddinOrder(ss, "ZOO");
    ssAddinOrder(ss, "art");
    ssAddinOrder(ss, "y1");
    ssAddinOrder(ss, "y2");
    ssAddinOrder(ss, "y4");
    ssRemove(ss, "y4");
    ssAddinOrder(ss, "y3");
    ssAddinOrder(ss, "y4");
    ssAddinOrder(ss, "zoo");
    ssAddinOrder(ss, "zebra");
    ssAddinOrder(ss, "Fun");
    ssRemove(ss, "Fun");

    ssPrintall(ss);
    ssDelete(ss);
    return 0;
}