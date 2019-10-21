// C++ program to print all words in the CamelCase 
// dictionary that matches with a given pattern 
#include <bits/stdc++.h> 
using namespace std; 

// Alphabet size (# of upper-Case characters) 
#define ALPHABET_SIZE 26 

// A Trie node 
struct TrieNode 
{ 
	TrieNode* children[ALPHABET_SIZE]; 

	// isLeaf is true if the node represents 
	// end of a word 
	bool isLeaf; 

	// vector to store list of complete words 
	// in leaf node 
	list<string> word; 
}; 

// Returns new Trie node (initialized to NULLs) 
TrieNode* getNewTrieNode(void) 
{ 
	TrieNode* pNode = new TrieNode; 

	if (pNode) 
	{ 
		pNode->isLeaf = false; 

		for (int i = 0; i < ALPHABET_SIZE; i++) 
			pNode->children[i] = NULL; 
	} 

	return pNode; 
} 

// Function to insert word into the Trie 
void insert(TrieNode* root, string word) 
{ 
	int index; 
	TrieNode* pCrawl = root; 

	for (int level = 0; level < word.length(); level++) 
	{ 
		// consider only uppercase characters 
		if (islower(word[level])) 
			continue; 

		// get current character position 
		index = int(word[level]) - 'A'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNewTrieNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isLeaf = true; 

	// push word into vector associated with leaf node 
	(pCrawl->word).push_back(word); 
} 

// Function to print all children of Trie node root 
void printAllWords(TrieNode* root) 
{ 
	// if current node is leaf 
	if (root->isLeaf) 
	{ 
		for(string str : root->word) 
			cout << str << endl; 
	} 

	// recurse for all children of root node 
	for (int i = 0; i < ALPHABET_SIZE; i++) 
	{ 
		TrieNode* child = root->children[i]; 
		if (child) 
			printAllWords(child); 
	} 
} 

// search for pattern in Trie and print all words 
// matching that pattern 
bool search(TrieNode* root, string pattern) 
{ 
	int index; 
	TrieNode* pCrawl = root; 

	for (int level = 0; level < pattern.length(); level++) 
	{ 
		index = int(pattern[level]) - 'A'; 
		// Invalid pattern 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	// print all words matching that pattern 
	printAllWords(pCrawl); 

	return true; 
} 

// Main function to print all words in the CamelCase 
// dictionary that matches with a given pattern 
void findAllWords(vector<string> dict, string pattern) 
{ 
	// construct Trie root node 
	TrieNode* root = getNewTrieNode(); 

	// Construct Trie from given dict 
	for (string word : dict) 
		insert(root, word); 

	// search for pattern in Trie 
	if (!search(root, pattern)) 
		cout << "No match found"; 
} 

// Driver function 
int main() 
{ 
	// dictionary of words where each word follows 
	// CamelCase notation 
	vector<string> dict = { 
		"Hi", "Hello", "HelloWorld", "HiTech", "HiGeek", 
		"HiTechWorld", "HiTechCity", "HiTechLab"
	}; 

	// pattern consisting of uppercase characters only 
	string pattern = "HT"; 

	findAllWords(dict, pattern); 

	return 0; 
} 
