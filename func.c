#include "func.h"

static NODE *head = NULL;

NODE *CreateNode() {
    NODE *p_node;
    if ((p_node = (NODE *)malloc(sizeof(NODE))) == NULL) {
        printf("Memory allocation error\n");
        exit(0);
    }
    p_node->next = NULL;
    printf("Enter the data: ");
    scanf("%d", &p_node->data);
    return p_node;
}

void CreateList() {
    int no;
    NODE *p_node, *p_temp;
    printf("Enter the no of nodes: ");
    scanf("%d", &no);
    for (int i = 0; i < no; i++) {
        p_node = CreateNode();
        if (head == NULL) {
            head = p_node;
        } else {
            p_temp = head;
            while (p_temp->next != NULL)
                p_temp = p_temp->next;
            p_temp->next = p_node;
        }
    }
}

void InsertAtBeginning() {
    NODE *p_node = CreateNode();
    p_node->next = head;
    head = p_node;
}

void InsertAtEnd() {
    NODE *p_node = CreateNode();
    if (head == NULL) {
        head = p_node;
    } else {
        NODE *p_temp = head;
        while (p_temp->next != NULL)
            p_temp = p_temp->next;
        p_temp->next = p_node;
    }
}

int listSize() {
    int size = 0;
    NODE *current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void PrintList() {
    NODE *p_node = head;
    if (p_node == NULL) {
        printf("List is empty\n");
        return;
    }
    while (p_node != NULL) {
        printf("%d ", p_node->data);
        p_node = p_node->next;
    }
    printf("\n");
}

void InsertAnywhere() {
    int pos, listlen;
    printf("Enter the position: ");
    scanf("%d", &pos);
    listlen = listSize();

    if (pos < 1 || pos > listlen + 1) {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1) {
        InsertAtBeginning();
        return;
    }
    if (pos == listlen + 1) {
        InsertAtEnd();
        return;
    }
    NODE *p_temp = head;
    for (int i = 1; i < pos - 1; i++)
        p_temp = p_temp->next;
    NODE *p_node = CreateNode();
    p_node->next = p_temp->next;
    p_temp->next = p_node;
}

void DeleteFirstNode() {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    NODE *p_node = head;
    head = head->next;
    free(p_node);
}

void DeleteLastNode() {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    NODE *p_temp = head;
    while (p_temp->next->next != NULL)
        p_temp = p_temp->next;
    free(p_temp->next);
    p_temp->next = NULL;
}

void DeleteAnyNode() {
    int pos, listlen;
    printf("Enter the position: ");
    scanf("%d", &pos);
    listlen = listSize();

    if (pos < 1 || pos > listlen) {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1) {
        DeleteFirstNode();
        return;
    }
    NODE *p_temp = head;
    for (int i = 1; i < pos - 1; i++)
        p_temp = p_temp->next;
    NODE *p_node = p_temp->next;
    p_temp->next = p_node->next;
    free(p_node);
}

bool SearchList() {
    NODE *p_node = head;
    int value;
    printf("Enter the element you are looking for: ");
    scanf("%d", &value);
    while (p_node != NULL) {
        if (p_node->data == value)
            return true;
        p_node = p_node->next;
    }
    return false;
}

void ReverseList() {
    NODE *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void FreeList() {
    NODE *p_node;
    while (head != NULL) {
        p_node = head;
        head = head->next;
        free(p_node);
    }
}

void ModifyList() {
    int pos, new_data, i = 1;
    NODE *p_node = head;

    printf("Enter the position to modify: ");
    scanf("%d", &pos);

    printf("Enter the new data: ");
    scanf("%d", &new_data);

    while (p_node != NULL && i < pos) {
        p_node = p_node->next;
        i++;
    }

    if (p_node == NULL) {
        printf("Invalid position\n");
    } else {
        p_node->data = new_data;
        printf("Node at position %d modified\n", pos);
    }
}

bool Palindrome() {
    int arr[1000], i = 0, j;
    NODE *p_node = head;

    while (p_node != NULL) {
        arr[i++] = p_node->data;
        p_node = p_node->next;
    }

    for (j = 0; j < i / 2; j++) {
        if (arr[j] != arr[i - j - 1])
            return false;
    }
    return true;
}

bool IsListEmpty() {
    return head == NULL;
}