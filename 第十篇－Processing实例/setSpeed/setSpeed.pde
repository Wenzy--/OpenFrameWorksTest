import processing.sound.*;
SoundFile sound;

void setup() {
  size(640, 360);
  background(255);
  sound = new SoundFile(this, "2.mp3");
}      

void draw() {
   float speed = mouseX/(float)width * 3;
   sound.rate(speed);
      
   //上下移动控制播放音量
   float vol = mouseY/(float)height * 4;
   sound.amp(vol);
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