#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <vector>
#include "trie.h"

using namespace std;

class Engine
{
public:
	Engine();
	~Engine();
	void init(string filepath);
	vector<int> process(string query);

private:
	Trie *t;
};

#endif