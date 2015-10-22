#include <unistd.h>
#include <node.h>
#include <string.h>
#include <err.h>
#include <errno.h>

namespace openbsdPledge {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Pledge(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() < 1) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsString()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  } 

  const int num = pledge(*String::Utf8Value(args[0]), NULL);
  if (num == -1)
    err(1, "pledge");
 
  args.GetReturnValue().Set(num);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "init", Pledge);
}

NODE_MODULE(addon, Init)

}  // namespace openbsdPledge
