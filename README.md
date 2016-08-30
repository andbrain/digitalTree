# digitalTree
Digital Tree as service of autocomplete, reading sample base of countries

#Installation

* Install node-gyp
```
npm install -g node-gyp
```
* Install node packages
```
npm install
```
# How to use

* Run service
> node .
* Call routes
	- Example with query = **a** and quantity result number = **5**
	```
	curl localhost:3000/api/search?q=a\&qtd=5
	```

# Recommended version

1. npm version = 3.8.6
2. node version = 5.11.0
3. node-gyp version = 3.4.0
4. g++ version = 5.4.0