#include <assert.h>
#include <stdint.h>

#include <Common.h>
#include <Time.h>
#include <StringBuilder.h>
#include <LinkedStack.h>
#include <LinkedList.h>

void dummy_start() {}

void dummy_tail() {}

LinkedList *ALL_TESTS;

typedef void(*TestFunction)();

#define BEGIN_DECLARE_TEST() \
void declare_test() {

#define END_DECLARE_TEST() \
}

#define DECLARE_TEST(name) \
$(ALL_TESTS, insertBefore, ALL_TESTS->fields->tail, &test_##name); \

#define DEFINE_TEST(name) \
void test_##name() { \

#define END_TEST() \
}

typedef struct {
  double height;
  int8_t age;
  bool gender;
} Person;

DEFINE_TEST(linked_list)
  LinkedList *list;
  list = LinkedList_new();
//  LinkedList_initialize(list, "haha");
  assert(list->fields->size == 0);
  Person a = {171.1, 16, true};
  Person b = {188.8, 18, false};
  Person c = {88.8, 8, false};
  Person d = {53.8, 8, false};
  Person e = {58.8, 8, true};
  Person f = {68.8, 8, true};
  Person g = {78.8, 8, false};
  Person h = {98.8, 8, true};
  $(list, addStart, &a);
  assert(_(list, size) == 1);
  $(list, addEnd, &b);
  assert(_(list, size) == 2);
  $(list, insertBefore, list->fields->tail, &c);
  $(list, insertAfter, list->fields->tail, &d);
  $(list, insertBefore, list->fields->head, &e);
  $(list, insertAfter, list->fields->head, &f);
  assert(_(list, size) == 6);
END_TEST()

DEFINE_TEST(stack)
  LinkedStack *stack;
  Time_start();
  stack = LinkedStack_new();
  $(stack, delete);
END_TEST()

BEGIN_DECLARE_TEST()
  DECLARE_TEST(linked_list)
  DECLARE_TEST(stack)
END_DECLARE_TEST()

int main() {

  ALL_TESTS = LinkedList_new();
  $(ALL_TESTS, addStart, &dummy_start);
  $(ALL_TESTS, addStart, &dummy_tail);
  declare_test();

  printf("%zu\n", ALL_TESTS->fields->size);
  LinkedListNode *p = ALL_TESTS->fields->head;
  while(p) {
    ((TestFunction)(p->data))();
    p = p->next;
  }
//  $(list, removeNode, list->fields->tail); // TODO: allocate the data dynamically.
//  assert(_(list, size) == 5);
  return 0;
}
