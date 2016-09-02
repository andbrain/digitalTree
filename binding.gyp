{
  "targets": [
    {
    	"target_name": "addon",
      "cflags": ["-std=gnu++11"],
    	"sources": [ 
    		"binder.cc",
        "c/engine.cpp",
        "c/trie.cpp",
        "c/util.cpp"
    	],
  		"include_dirs" : [
        "c"
      ]
    }
  ]
}