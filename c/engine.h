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
	vector<int> process(string query, int qtd_result);
	bool insert(int id, string element);
	bool update(int id, string element);
	bool remove(int id);
private:
	Trie *t;
};

#endif