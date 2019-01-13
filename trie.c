#include <stdio.h>
#include<stdlib.h>
// define character size
#define CHAR_SIZE 26
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// A Trie node
struct Trie
{
	int isEnd;	// 1 when node is a leaf node
	struct Trie* character[CHAR_SIZE];
};
// Function that returns a new Trie node
struct Trie* NewTrieNode()
{
	struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
	node->isEnd = 0;

	for (int i = 0; i < CHAR_SIZE; i++)
		node->character[i] = NULL;

	return node;
}
// Iterative function to insert a string in Trie.
void insert(struct Trie* *head, char* str)
{
	// start from root node
	struct Trie* curr_node = *head;
	while (*str)
	{
		// create a new node if path doesn't exists
		if (curr_node->character[*str - 'a'] == NULL)
			curr_node->character[*str - 'a'] = NewTrieNode();
		// go to next node
		curr_node = curr_node->character[*str - 'a'];
		// move to next character
		str++;
	}
	// mark current node as leaf
	curr_node->isEnd = 1;
}
// Iterative function to search a string in Trie. It returns 1
// if the string is found in the Trie, else it returns 0
int search(struct Trie* head, char* str)
{
	// return 0 if Trie is empty
	if (head == NULL)
		return 0;

	struct Trie* curr_node = head;
	while (*str)
	{
		// go to next node
		curr_node = curr_node->character[*str - 'a'];
		// if string is invalid (reached end of path in Trie)
		if (curr_node == NULL)
			return 0;
		// move to next character
		str++;
	}
	// if current node is a leaf and we have reached the
	// end of the string, return 1
	return curr_node->isEnd;
}
// returns 1 if given node has any children
int haveChildren(struct Trie* curr_node)
{
	for (int i = 0; i < CHAR_SIZE; i++)
		if (curr_node->character[i])
			return 1;	// child found
	return 0;
}
int deletion(struct Trie* *curr_node, char* str)
{
	// return if Trie is empty
	if (*curr_node == NULL)
		return 0;
	// if we have not reached the end of the string
	if (*str)
	{
		// recurse for the node corresponding to next character in
		// the string and if it returns 1, delete current node
		// (if it is non-leaf)
		if (*curr_node != NULL && (*curr_node)->character[*str - 'a'] != NULL &&
			deletion(&((*curr_node)->character[*str - 'a']), str + 1) &&
			(*curr_node)->isEnd == 0)
		{
			if (!haveChildren(*curr_node))
			{
				free(*curr_node);
				(*curr_node) = NULL;
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	// if we have reached the end of the string
	if (*str == '\0' && (*curr_node)->isEnd)
	{
		// if current node is a leaf node and don't have any children
		if (!haveChildren(*curr_node))
		{
			free(*curr_node); // delete current node
			(*curr_node) = NULL;
			return 1; // delete non-leaf parent nodes
		}
		// if current node is a leaf node and have children
		else
		{
			// mark current node as not an End leaf node (DON'T DELETE IT)
			(*curr_node)->isEnd = 0;
			return 0;	   // don't delete its parent nodes
		}
	}
	return 0;
}
int main()
{
	struct Trie* head = NewTrieNode();
	char words[][20]={"manikanteswari","an","is","was","were","you","me","yourself","he","his","himself","them","themselves","the","a","she","her","my","bye","hello"};
    int i;
    for(i=0;i<ARRAY_SIZE(words);i++)
        insert(&head,words[i]);
    printf("%d",search(head,"himself"));
    deletion(&head,"himself");
    printf("\n%d",search(head,"himself"));

		return 0;
}
