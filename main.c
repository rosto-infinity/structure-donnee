#include <stdio.h>
#include <stdlib.h>

// D�finition de la structure du n�ud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// D�finition de la structure de la liste cha�n�e
typedef struct LinkedList {
    Node *head;
    Node *tail; // Pointeur vers le dernier n�ud
} LinkedList;

// Fonction de cr�ation d'un nouveau n�ud
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erreur d'allocation m�moire");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour ins�rer un n�ud � la fin de la liste
void insertAtEnd(LinkedList *list, int newData) {
    Node *newNode = createNode(newData); // Utilisation de createNode

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode; // Le premier n�ud est aussi le dernier
    } else {
        list->tail->next = newNode; // Lier le dernier n�ud au nouveau n�ud
        list->tail = newNode; // Mettre � jour le pointeur vers le dernier n�ud
    }
}

// Fonction pour afficher la liste cha�n�e
void printList(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Fonction principale
int main() {
    LinkedList list; // Cr�ation d'une liste cha�n�e
    list.head = NULL; // Initialisation de la t�te de la liste
    list.tail = NULL; // Initialisation du dernier n�ud

    // Insertion de quelques �l�ments � la fin
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);

    // Affichage de la liste
    printf("Liste cha�n�e : ");
    printList(list.head);

    // Lib�ration de la m�moire
    Node *temp;
    while (list.head != NULL) {
        temp = list.head;
        list.head = list.head->next;
        free(temp);
    }

    return 0;
}
