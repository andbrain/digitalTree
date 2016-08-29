"use strict";

var currentPath = process.cwd();
var addon = require(currentPath + '/build/Release/addon');

function checkParams (query) {
	// qtd default = 5 results
	if(query){
		if(!query.q)
			return ({code: 0, message: "no query to search!"});
		query.qtd = (query.qtd)? query.qtd:5;
	}
	else
		return ({code: 0, message: "no query to search!"});

	query.code = 1;
	return query;
}

module.exports = function list(req, res, next) {
	var query = checkParams(req.query);

	if(!query.code){
		res.send({code: "fail", message: query.message});
		return next();
	}

	var result = addon.process(query.q, query.qtd);

	res.send({result: result});
	return next();
};