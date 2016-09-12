import processing.sound.*;
SoundFile sound1, sound2, sound3, sound4, sound5;
boolean play1, play2, play3, play4, play5;
boolean isDragging;
float lastMouseX, lastMouseY;


void setup() {
  size(640, 360);
  background(255, 214, 79);
  noStroke();
  sound1 = new SoundFile(this, "do.wav");
  sound2 = new SoundFile(this, "re.wav");
  sound3 = new SoundFile(this, "mi.wav");
  sound4 = new SoundFile(this, "fa.wav");
  sound5 = new SoundFile(this, "so.wav");
}      

void draw() {
  if (play1) {
    sound1.play();
    play1 = false;
  }
  if (play2) {
    sound2.play();
    play2 = false;
  }
  if (play3) {
    sound3.play();
    play3 = false;
  }
  if (play4) {
    play4 = false;
    sound4.play();
  }
  if (play5) {
    play5 = false;
    sound5.play();
  }
  if (isDragging) {
    stroke(107, 27, 157, 100);
    strokeWeight(10);
    line(mouseX, mouseY, lastMouseX, lastMouseY);
  }

  lastMouseX = mouseX;
  lastMouseY = mouseY;
}

void mouseDragged() {
  isDragging = true;
  if ((mouseX - 100) * (lastMouseX - 100) < 0) {
    play1 = true;
  }
  if ((mouseX - 200) * (lastMouseX - 200) < 0) {
    play2 = true;
  }
  if ((mouseX - 300) * (lastMouseX - 300) < 0) {
    play3 = true;
  }
  if ((mouseX - 400) * (lastMouseX - 400) < 0) {
    play4 = true;
  }
  if ((mouseX - 500) * (lastMouseX - 500) < 0) {
    play5 = true;
  }
}

void mouseReleased() {
  isDragging = false;
}