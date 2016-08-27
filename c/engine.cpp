#include "engine.h"

Engine::Engine()
{
	cout << "Starting engine.." << endl;
}

Engine::~Engine()
{
	cout << "Ending engine.." << endl;
}

void Engine::init()
{
	cout << "Initializing engine.." << endl;
}

vector<int> Engine::process(string query)
{
	cout << "processing..." << endl;
  	cout << "query: " << query << endl;

	std::vector<int> vec;
 	vec.push_back(12);
  	vec.push_back(20);

	return vec;
}