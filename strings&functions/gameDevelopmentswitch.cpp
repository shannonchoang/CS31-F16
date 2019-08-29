
int main() {
  int HP = 100;
  int input[3] = {1, 3, 4};
  for (int i = 0; i < 3; i++) {
    switch (input[i]) {
      case 1:
      case 2:
        printf("Welcome!\n");
        HP *= 2;
        break;
      case 3:
        printf("Obtained a poisonous mushroom\n");
        HP /= 2;
        break;
      case 4:
        printf("Encountered a troll! HP -5\n");
        HP -= 5;
      case 5:
        printf("Got a potion! HP +5\n");
        HP += 5;
        break;
      default:
        printf("Invalid move\n");
    }
  }
}

//assume all appropiate headers are included 
//assume array input is correct

//What is the output? 
/*
HP = 100
case 1 
"Welcome!\n"
HP = 200 
case 3 
"Obstained a poisonouns mushroom\n"
HP = 100 
case 4 
"Encountered a troll! HP-5 \n"
HP = 95 
//WRONG IT WILL ALSO GO INTO CASE 5 
the -5 will be canceled out by the +5


*/