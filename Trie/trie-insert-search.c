/*

Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct TrieNode
{
    struct TrieNode* child[26];
    bool endofword;
};

struct TrieNode* getNode()
{
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if(newNode)
    {
        newNode->endofword = false;
        int i;
        for(i=0;i<26;i++)
            newNode->child[i] = NULL;
        
    }
    return newNode;
}

void insert(struct TrieNode* root,char* key)
{
    int index;
    struct TrieNode* temp = root;
    for(int i=0;i<strlen(key);i++)
    {
        index = key[i]-'a';
        if(temp->child[index]==NULL)
            temp->child[index] = getNode();
        temp = temp->child[index];
    }
    temp->endofword = true;
}

int search(struct TrieNode* root, char* key)
{
    int index;
    struct TrieNode* temp = root;
    for(int i=0;i<strlen(key);i++)
    {
        index = key[i]-'a';
        if(temp->child[index]==NULL)
            return 0;
        temp = temp->child[index];
    }
    if(temp->endofword==false) return 0;
    return 1;
}

int main() {
	//code
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    char st[20][50];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%s",st[i]);
	        //printf("%s",st[i]);
	    }
	    
	    char find[50];
	    scanf("%s",find);
	    
	    struct TrieNode* root = getNode();
	    for(int i=0;i<n;i++)
	    {
	        insert(root,st[i]);
	    }
	    
	    int res = search(root,find);
	    printf("%d\n",res);
	}
	return 0;
}

