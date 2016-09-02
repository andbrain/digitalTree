#include <node.h>
#include <iostream>
#include <vector>
#include <engine.h>

static Engine eng;

bool removeElement(int id)
{
  return eng.remove(id);
}

bool updateElement(int id, std::string element)
{
  return eng.update(id, element);
}

bool insertElement(int id, std::string element)
{
  return eng.insert(id, element);
}

std::vector<int> ProcessQuery(std::string query, int qtd)
{
  std::vector<int> vec;

  vec = eng.process(query, qtd);

  return vec;
}

void Initializer(string filepath)
{
  eng.init(filepath);
}

namespace nodeNM {
  using namespace v8;
  
  void Remove(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Make sure there is an argument
    if(args.Length() != 1){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    }

    if( args[0]->IsUndefined()){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    } 

    int id = args[0]->NumberValue();
    bool result = removeElement(id);

    Local<Boolean> res = Boolean::New(isolate, result);
    args.GetReturnValue().Set(res);
  }

  void Update(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Make sure there is an argument
    if(args.Length() != 2){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    }

    if( args[0]->IsUndefined()){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    } 

    int id = args[0]->NumberValue();
    v8::String::Utf8Value nameFromArgs(args[1]->ToString());
    std::string element = std::string(*nameFromArgs);
    bool result = updateElement(id, element);

    Local<Boolean> res = Boolean::New(isolate, result);
    args.GetReturnValue().Set(res);
  }

  void Insert(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Make sure there is an argument
    if(args.Length() != 2){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    }

    if( args[0]->IsUndefined()){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    } 

    int id = args[0]->NumberValue();
    v8::String::Utf8Value nameFromArgs(args[1]->ToString());
    std::string element = std::string(*nameFromArgs);
    bool result = insertElement(id, element);

    Local<Boolean> res = Boolean::New(isolate, result);
    args.GetReturnValue().Set(res);
  }


  void Create(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Make sure there is an argument
    if(args.Length() != 1){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    }
    v8::String::Utf8Value nameFromArgs(args[0]->ToString());
    std::string basefile = std::string(*nameFromArgs);
    Initializer(basefile);

    args.GetReturnValue();
  }

  void Process(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    
    // Make sure there is an argument
    if(args.Length() != 2){
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Need an argument!")));
      return;
    }

    // convert first arg to std::string and call c++ function
    v8::String::Utf8Value nameFromArgs(args[0]->ToString());
    std::string query = std::string(*nameFromArgs);

    int qtd = args[1]->IsUndefined() ? 0 : args[1]->Int32Value();

    std::vector<int> vec = ProcessQuery(query, qtd);

    // Pack std::vector into a JS array
    Local<Array> result = Array::New(isolate);
    for (unsigned int i = 0; i < vec.size(); ++i)
    {
      result->Set(i, Number::New(isolate, vec[i]));
    }

    args.GetReturnValue().Set(result);
  }

  void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "create", Create);
    NODE_SET_METHOD(exports, "process", Process);
    NODE_SET_METHOD(exports, "insert", Insert);
    NODE_SET_METHOD(exports, "update", Update);
    NODE_SET_METHOD(exports, "remove", Remove);
  }

  NODE_MODULE(addon, init)
}