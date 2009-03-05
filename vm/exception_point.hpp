#ifndef RBX_EXCEPTION_POINT

#include <setjmp.h>

namespace rubinius {
  class NativeMethodEnvironment;

  class ExceptionPoint {
    bool jumped_to_;
    ExceptionPoint* previous_;

  public:
    jmp_buf __jump_buffer;

  public:
    ExceptionPoint(NativeMethodEnvironment* env);

    bool jumped_to() {
      return jumped_to_;
    }

    void reset() {
      jumped_to_ = false;
    }

    void return_to(NativeMethodEnvironment* env);

    void unwind_to_previous(NativeMethodEnvironment* env) {
      previous_->return_to(env);
    }

    void pop(NativeMethodEnvironment* env);
  };
}

#define PLACE_EXCEPTION_POINT(ep) _setjmp(ep.__jump_buffer)

#endif
