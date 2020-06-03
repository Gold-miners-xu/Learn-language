#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node node_t;
struct node {
	char* name;
	node_t* next;
};
void insert_list(node_t** head, char dname) {
	if (head == NULL) return;
	node_t* new_node = create_node(dname);
	if (*head == NULL) {
		*head = new_node;
	}
	else {
		if (strcasecmp((*head)->name, new_node->name) >= 0) {
			new_node->next = *head;
			*head = new_node;
			return;
		}
		node_t* cur = *head;
		node_t* next = cur->next;
		while( next != NULL ){
			if (strcasecmp(next->name, new_node->name) >= 0) {
				break;
			}
			cur = next;
			next = cur->next;
		}
		
		new_node->next = next;
		cur->next = new_node;
	}

}
node_t* create_node(char* dname) {
	node_t* pnode = (node_t*)malloc(sizeof(node_t));
	pnode->name = malloc(strlen(dname) + 1);
	memset(pnode->name, 0x00, strlen(dname) + 1);
	strcpy(pnode->name, dname);
	pnode->next = NULL;
	return pnode;
}
int main() {
	node_t* head = NULL;
	struct dirent* pdirent = NULL;
	DIR pdir = opendir(".");
	while ((pdirent = readdir(pdir)) != NULL) {
		if (pdirent->d_name[0] == '.')
			continue;
		insert_list(&head, pdirent->d_name);
		//printf("&s ", pdirent->d_name);
	}
	node_t* cur = head;
	while (cur != NULL) {
		printf("%s ", cur->name);
		cur = cur->next;
	}
	printf("\n");

	closedir(pdir);
}