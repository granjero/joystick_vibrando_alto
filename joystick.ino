#include <Button.h>
#include <Keyboard.h>

#define RIGHT 8
#define LEFT 9
#define UP 10
#define DOWN 11

#define BOTON 12

Button up(UP, 100);
Button down(DOWN, 100);
Button right(RIGHT, 100);
Button left(LEFT, 100);
Button boton(BOTON, 100);

int cont_up = 0;
int cont_down = 0;
int cont_right = 0;
int cont_left = 0;

int modo = 0;

void setup() {
  up.begin();
  down.begin();
  right.begin();
  left.begin();
  boton.begin();
  Keyboard.begin();
  Serial.begin(115200);
}

void loop() {
  botones(modo);
}

void botones(int modo) {
  if (up.pressed()) {
    switch (modo) {
      case 0:
        return Keyboard.write('C');
        break;
      case 1:
        return Keyboard.write('X');
        break;
      case 2:
        return Keyboard.write('R');
        break;
      case 3:
        return Keyboard.write('I');
        break;
    }
    // contadores();
  }

  if (down.pressed()) {
    switch (modo) {
      case 0:
        return Keyboard.write('c');
        break;
      case 1:
        return Keyboard.write('x');
        break;
      case 2:
        return Keyboard.write('e');
        break;
      case 3:
        return Keyboard.write('i');
        break;
    }
    // contadores();
  }

  if (right.pressed()) {
    switch (modo) {
      case 0:
        return Keyboard.write('B');
        break;
      case 1:
        return Keyboard.write('V');
        break;
      case 2:
        return Keyboard.write('E');
        break;
      case 3:
        return Keyboard.write('P');
        break;
    }
    contadores();
  }
  if (left.pressed()) {
    switch (modo) {
      case 0:
        return Keyboard.write('b');
        break;
      case 1:
        return Keyboard.write('v');
        break;
      case 2:
        return Keyboard.write('e');
        break;
      case 3:
        return Keyboard.write('p');
        break;
    }
    // contadores();
  }
  if (boton.pressed()) {
    modo++;
    modo = modo > 3 ? 0 : modo;
  }
}

void contadores() {
  Serial.print("up ");
  Serial.println(cont_up);
  Serial.print("down ");
  Serial.println(cont_down);
  Serial.print("right ");
  Serial.println(cont_right);
  Serial.print("left ");
  Serial.println(cont_left);
  Serial.println("********");
  delay(250);
}


// devuelve el caracter que corresponde segun el modo y la direccion
char devuelveCaracter(int modo) {
  switch (modo) {
    case 0:
      return 'Cc';  //
      break;
    case 1:
      return 'Bb';  //
      break;
    case 2:
      return 'Xx';  //
      break;
    case 3:
      return 'Vv';  //
      break;
    case 4:
      return 'Rr';  //
      break;
    case 5:
      return 'Ee';  //
      break;
    case 6:
      return 'Ii';
      break;
    case 7:
      return 'Pp';
      break;
  }
}