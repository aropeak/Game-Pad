// Check to See if Hero & Enemies Collide
boolean checkCollide(int hX, int hY, int hW, int hH, int eX, int eY, int eW, int eH){
  boolean canMove = false;           // Assume a move can be made
  boolean xMin = false; if(hX < eX + eW){xMin = true;}               // Does the xMin collide?
  boolean xMax = false; if(hX + hW > eX){xMax = true;}               // Does the xMax collide?
  boolean yMin = false; if(hY < eY + eH){yMin = true;}               // Does the yMin collide?
  boolean yMax = false; if(hY + hH > eY){yMax = true;}               // Does the yMin collide?
  if (xMin && xMax && yMin && yMax) {canMove = true;}
  return canMove;
}

void fight() {
  boolean canFight=checkCollide(heroX, heroY, heroW, heroH, enemyX, enemyY, enemyW, enemyH);
  boolean canFight2=checkCollide(heroX, heroY, heroW, heroH, norbX, norbY, norbW, norbH);

  if(canFight==true && buttonBuffer[1] == 1 && shieldBool==true) {
     if(enemyX>heroX) {enemyX = enemyX + 10;}
     if(enemyX<heroX) {enemyX = enemyX - 10;}
     if(enemyY>heroY) {enemyY = enemyY + 10;}
     if(enemyY<heroY) {enemyY = enemyY - 10;}
     tft.setClipRect(0, 0, screenW, screenH-40);
     drawLevel(curMode);
     tft.updateScreen();
  }
  
  if(canFight==true && buttonBuffer[1] == 0 && shieldBool==false) {
     if(enemyX>heroX) {heroX = heroX - 10;}
     if(enemyX<heroX) {heroX = heroX + 10;}
     if(enemyY>heroY) {heroY = heroY - 10;}
     if(enemyY<heroY) {heroY = heroY + 10;}
     if(random(5) ==  0){heroHealth = heroHealth - 1;}
     tft.setClipRect(0, 0, screenW, screenH-40);
     drawLevel(curMode);
     tft.updateScreen();
     updateHealth();
  }

    if(canFight==true && buttonBuffer[0] == 1) {
     if(enemyX>swordX) {enemyX = enemyX + 10;}
     if(enemyX<swordX) {enemyX = enemyX - 10;}
     if(enemyY>swordY) {enemyY = enemyY + 10;}
     if(enemyY<swordY) {enemyY = enemyY - 10;}
     enemyHealth = 0;
     tft.setClipRect(0, 0, screenW, screenH-40);
     drawLevel(curMode);
     tft.updateScreen();
  }
 Serial.println(canFight2);

   if(canFight2==true && curMode ==7) {
      if(buttonBuffer[0]==1){
        norbHealth=0;
      } else {
        if(random(3) ==  0){heroHealth = heroHealth - 1;}
        heroY = heroY - 20;
        }
   }
}
