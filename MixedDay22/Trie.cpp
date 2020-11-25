
struct TrieNode
{
	struct TrieNode* children[N];
	bool isEndOfWord;
}

struct TrieNode* newNode()
{
	struct TrieNode* node = new TrieNode;
	node->isEndOfWord = false;

	for (int i = 0; i < N; i++)
		node->children[i] = NULL;
	return node;
}

void insert(struct TrieNode* root, string s)
{
	struct TrieNode* f = root;
	for (int i = 0; i < s.length(); i++)
	{
		int idx = s[i] - 'a';
		if (f->children[idx] == NULL)
			f->children[idx] = newNode();
		f = f->children[idx];
	}
	f->isEndOfWord = true;
}

bool search(struct TrieNode* root, string s)
{
	struct TrieNode* f = root;
	for (int i = 0; i < s.length(); i++)
	{
		int idx = s[i] - 'a';
		if (f->children[idx] == NULL)
			return false;
		f = f->children[idx];
	}
	return (f != NULL && f->isEndOfWord == true);
}