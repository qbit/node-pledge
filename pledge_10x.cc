#include <node.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <string>

using namespace v8;

Handle<Value> Pledge(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsString()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }
 
  std::string str(*v8::String::Utf8Value(args[0]));
  const int num = pledge(str.c_str(), NULL);
  if (num == -1)
    err(1, "pledge");

  return scope.Close(Number::New(num));
}

void Init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("init"),
      FunctionTemplate::New(Pledge)->GetFunction());
}

NODE_MODULE(pledge, Init)
