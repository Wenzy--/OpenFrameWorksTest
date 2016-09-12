

import processing.video.*;

Movie mov;

void setup() {
  size(640, 360);
  background(0);
  mov = new Movie(this, "transit.mov");
}

void movieEvent(Movie movie) {
  mov.read();
}

void draw() {    
  image(mov, 0, 0);
  float newSpeed = map(mouseX, 0, width, 0.1, 4);
  mov.speed(newSpeed);
}  

void keyPressed() {
  if (key == 'p') {
    mov.play();
  }
  if (key == 's') {
    mov.stop();
  }
  if (key == 'd') {
    mov.pause();
  }
}