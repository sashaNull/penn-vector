#include "./Vec.h"
#include <stdlib.h>
#include "./panic.h"

Vec vec_new(size_t initial_capacity, ptr_dtor_fn ele_dtor_fn) {
  // TODO: implement me
  Vec vec;
  vec.data = (ptr_t*)malloc(initial_capacity * sizeof(ptr_t));
  if (vec.data == NULL && initial_capacity > 0) {
    panic("Memory allocation failed in vec_new");
  }

  vec.length = 0;
  vec.capacity = initial_capacity;
  vec.ele_dtor_fn = ele_dtor_fn;
  return vec;
}

// TODO: the rest of the vector functions

void vec_destroy(Vec* self) {
  if (self == NULL) {
    return;
  }

  if (self->ele_dtor_fn != NULL) {
    for (size_t i = 0; i < self->length; i++) {
      self->ele_dtor_fn(self->data[i]);
    }
  }

  free(self->data);
  self->data = NULL;
  self->length = 0;
  self->capacity = 0;
  self->ele_dtor_fn = NULL;
  printf("CAC\n");
}

ptr_t vec_get (Vec *self, size_t index) {
  return NULL;
}

void vec_set (Vec* self, size_t index, ptr_t new_ele) {
  return ;
}

void vec_push_back(Vec* self, ptr_t new_ele) {
  if (self->length == self->capacity) {
    size_t new_capacity = self->capacity == 0 ? 1 : self->capacity*2;
    vec_resize(self, new_capacity);
  }
  
  self->data[self->length++] = new_ele;
}

bool vec_pop_back(Vec* self) {
  return false;
}

void vec_insert(Vec* self, size_t index, ptr_t new_ele) {
  return ;
}

void vec_erase(Vec* self, size_t index){
  return ;
}

void vec_resize(Vec* self, size_t new_capacity) {
  return ;
}

void vec_clear(Vec* self) {
  return ;
}
