#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Définition de la structure de la liste chaînée
typedef struct LinkedList {
    Node *head;
    Node *tail; // Pointeur vers le dernier nœud
} LinkedList;

// Fonction de création d'un nouveau nœud
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un nœud à la fin de la liste
void insertAtEnd(LinkedList *list, int newData) {
    Node *newNode = createNode(newData); // Utilisation de createNode

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode; // Le premier nœud est aussi le dernier
    } else {
        list->tail->next = newNode; // Lier le dernier nœud au nouveau nœud
        list->tail = newNode; // Mettre à jour le pointeur vers le dernier nœud
    }
}

// Fonction pour afficher la liste chaînée
void printList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Fonction principale
int main() {
    LinkedList list; // Création d'une liste chaînée
    list.head = NULL; // Initialisation de la tête de la liste
    list.tail = NULL; // Initialisation du dernier nœud

    // Insertion de quelques éléments à la fin
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);

    // Affichage de la liste
    printf("Liste chaînée : ");
    printList(list.head);

    // Libération de la mémoire
    Node *temp;
    while (list.head != NULL) {
        temp = list.head;
        list.head = list.head->next;
        free(temp);
    }

    return 0;
}
