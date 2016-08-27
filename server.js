"use strict";

var currentPath = process.cwd();
var restify = require('restify');
var addon = require(currentPath + '/build/Release/addon');

var options = {
	name: "Binder C++ as a Service"
};

var server = restify.createServer(options);

server.use(restify.acceptParser(server.acceptable));
server.use(restify.authorizationParser());
server.use(restify.queryParser({ mapParams: false }));

//max body size 10kb
server.use(restify.bodyParser({
    maxBodySize: 10 * 1024,
    mapParams: false
}));

//initialize addon
addon.create();

module.exports = server;
require('./routes');