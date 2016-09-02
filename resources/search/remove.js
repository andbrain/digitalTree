"use strict";

var currentPath = process.cwd();
var addon = require(currentPath + '/build/Release/addon');

function checkParams (query) {
	// qtd default = 5 results
	if(query){
		if(!query.id)
			return ({code: 0, message: "no element id to insert!"});	
	}
	else
		return ({code: 0, message: "no element to insert!"});

	query.code = 1;
	return query;
}

module.exports = function del(req, res, next) {
	var query = checkParams(req.body);

	if(!query.code){
		res.send({code: "error", message: query.message});
		return next();
	}
	//TODO see how to sync response of insert with response of request
	var result = addon.remove(query.id);

	res.send({status: "success", result: result});
	return next();
};