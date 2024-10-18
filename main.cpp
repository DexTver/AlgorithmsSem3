#include "sets/set_array.h"
#include "sets/set_list.h"
#include "sets/set_bool_array.h"
#include "sets/set_machine_word.h"

int main() {
    char a[] = "124", b[] = "267", c[] = "399", d[] = "35";

    set_array A(a), B(b), C(c), D(d);
//    set_list A(a), B(b), C(c), D(d);
//    set_bool_array A(a), B(b), C(c), D(d);
//    set_machine_word A(a), B(b), C(c), D(d);

    (A & B | C | D).show();
}
