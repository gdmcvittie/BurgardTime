const uint16_t gameOver[] PROGMEM = {
  500,100, 300,100, 100,100, 300,100, 500,100, 50,160,
  TONES_END };

const uint16_t levelDone[] PROGMEM = {
  900,100, 1000,300, 1200,100, 600,250, 700,100, 800,250, 900,100, 1000,300, 1200,250, 600,100, 700,250, 800,500,
  TONES_END };

const uint16_t bossDone[] PROGMEM = {
  1000,500, 500,100, 600,250, 700,250, 800,100, 900,500,
  TONES_END };

 /*
 * misc boop
 */
void soundMisc(){
  sound.tone(500, 100);
}

 /*
 * jump
 */
void soundJump(){
  sound.tone(1000, 100);
}

 /*
 * throw hammer
 */
void soundThrow(){
  sound.tone(800, 100);
}

/*
 * hit something with hammer
 */
void soundHit(){
  sound.tone(1600, 100);
}

/*
 * egg
 */
void soundEgg(){
  sound.tone(1200, 100);
}

 /*
 * lose health
 */
void soundBad(){
  sound.tone(100, 100);
}

 /*
 * gain health
 */
void soundGood(){
  sound.tone(900, 100);
}


/*
 * level end
 */
void soundLevelDone(){
  sound.tones(levelDone);
  while (sound.playing()) { }
}


/*
 * boss killed
 */
void soundBossDone(){
  sound.tones(bossDone);
  while (sound.playing()) { }
}


/*
 * game over
 */
void soundGameOver(){
  sound.tones(gameOver);
  while (sound.playing()) { }
  sound.tones(gameOver);
  while (sound.playing()) { }
  delay(1000);
}
