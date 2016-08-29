#include "engine.h"

Engine::Engine()
{
	cout << "Starting engine.." << endl;
	t = new Trie();
}

Engine::~Engine()
{
	cout << "Ending engine.." << endl;
	delete t;
}

void Engine::init(string filepath)
{
	cout << "Initializing engine.." << endl;
	t->Init(filepath);
}

vector<int> Engine::process(string query,  int qtd_result)
{
	std::vector<int> vec;
	vec = t->Search(query, qtd_result);

	return vec;
}