import processing.sound.*;
SoundFile sound;

void setup() {
  size(640, 360);
  background(255);
  sound = new SoundFile(this, "1.mp3");
}      

void draw() {
  
}
void keyPressed() {
  //播放音频
  
 // sound.play();
  if (key == 'p') {
    sound.play();
  }
  ////暂停音频
  if (key == 's') {
    sound.stop();
  }
}