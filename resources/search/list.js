"use strict";

var currentPath = process.cwd();
var addon = require(currentPath + '/build/Release/addon');

module.exports = function listCategories(req, res, next) {
	console.log("\n");
	// global.addon.start(); // will print 'world
	// var result = global.addon.process("Anderson"); // will print 'world
	var result = addon.process("Anderson"); // will print 'world
	console.log("\n");
	console.log("response: ",result);

	res.send({code:"success", message: result});
	return next();
};