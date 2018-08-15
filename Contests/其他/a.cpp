#include<stdio.h>
void do_twice(void(*f)()){
    f();
    f();
}
void do_four(void(*f)()){
    do_twice(f);
    do_twice(f);
}

void print_plus(){
    printf("+");
}

void print_dash(){
    printf("-");
}
void print_bar(){
    printf("|");
}

void print_space(){
    printf(" ");
}

void print_end(){
    printf("\n");
}

void nothing(){
}
void one_four_one(void (*f)(),void(*g)(), void(*h)()){
    f();
    do_four(g);
    h();
}
void print1beam(){
    one_four_one(nothing, print_dash, print_plus);
}

void print1post(){
    one_four_one(nothing, print_space, print_bar);
}
void print4beams(){
    one_four_one(print_plus, print1beam, print_end);
}
void print4posts(){
    one_four_one(print_bar, print1post, print_end);
}
void print_row(){
    one_four_one(nothing, print4posts, print4beams);
}
void print_grid(){
    one_four_one(print4beams, print_row, nothing);
}

int main(){
  print_grid();

}

