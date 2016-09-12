import processing.sound.*;
SoundFile sound1, sound2, sound3, sound4, sound5;
boolean isDragging;

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
  if (isDragging) {
    fill(107, 27, 157, 100);
    ellipse(mouseX, mouseY, 16, 16);
  }
}

void mouseDragged() {
  isDragging = true;
  if (mouseX > 100 && mouseX < 105) {
    sound1.play();
  }
  if (mouseX > 200 && mouseX < 205) {
    sound2.play();
  }
  if (mouseX > 300 && mouseX < 305) {
    sound3.play();
  }
  if (mouseX > 400 && mouseX < 405) {
    sound4.play();
  }
  if (mouseX > 500 && mouseX < 505) {
    sound5.play();
  }
}

void mouseReleased() {
  isDragging = false;
}