

https://www.geeksforgeeks.org/lru-cache-implementation/

class LRUCache
{
	list<int>dq;
	unordered_map<int, list<int> >m;
	int csize;

public:
	LRUCache(int);
	void insert(int);
	void display();
};

LRUCache::LRUCache(int n)
{
	csize = n;
}

void LRUCache::insert(int x)
{
	// If element found in cache
	if (m.find(x) != m.end())
	{
		dq.erase(x);
		dp.push_front(x);
		m[x] = dq.begin();
	}
	else
	{
		if (dq.size() == c.size())
		{
			auto last = dq.back();
			dq.pop_back();
			m.erase(last);
		}
		dq.push_front(x);
		m[x] = dq.begin();
	}
}

void LRUCache::display()
{
	for (auto x : dq)
		cout << x << " ";
	cout << endl;
}