import processing.sound.*;
SoundFile sound1, sound2, sound3, sound4, sound5;
boolean key1, key2, key3, key4, key5;

void setup() {
  size(640, 360);
  background(255);
  noStroke();
  sound1 = new SoundFile(this, "do.wav");
  sound2 = new SoundFile(this, "re.wav");
  sound3 = new SoundFile(this, "mi.wav");
  sound4 = new SoundFile(this, "fa.wav");
  sound5 = new SoundFile(this, "so.wav");
}      

void draw() {
  background(255, 214, 79);
  rectMode(CENTER);
  float w = width * 0.1;
  float h = height * 0.8;

  if (key1) {
    fill(255);
  } else {
    fill(238, 145, 117);
  }
  rect(width/6, height/2, w, h);

  if (key2) {
    fill(255);
  } else {
    fill(246, 96, 100);
  }
  rect(width/6 * 2, height/2, w, h);

  if (key3) {
    fill(255);
  } else {
    fill(214, 86, 113);
  }
  rect(width/6 * 3, height/2, w, h);

  if (key4) {
    fill(255);
  } else {
    fill(124, 60, 131);
  }
  rect(width/6 * 4, height/2, w, h);

  if (key5) {
    fill(255);
  } else {
    fill(107, 27, 157);
  }
  rect(width/6 * 5, height/2, w, h);
}
void keyPressed() {
  if (key == 'a') {
    sound1.play();
    key1 = true;
  }
  if (key == 's') {
    sound2.play();
    key2 = true;
  }
  if (key == 'd') {
    sound3.play();
    key3 = true;
  }
  if (key == 'f') {
    sound4.play();
    key4 = true;
  }
  if (key == 'g') {
    sound5.play();
    key5 = true;
  }
}

void keyReleased() {
  if (key == 'a') {
    key1 = false;
  }
  if (key == 's') {
    key2 = false;
  }
  if (key == 'd') {
    key3 = false;
  }
  if (key == 'f') {
    key4 = false;
  }
  if (key == 'g') {
    key5 = false;
  }
}