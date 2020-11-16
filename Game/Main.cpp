#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Collider.h"
#include "Player.h"
#include "Map1.h"
#include "Platform.h"
#include "Platform2.h"
#include <conio.h>
#include <vector>
#include "Enemy.h"
#include "Textbox.h"
int GameState = 3,HTP=0;

int key = 0, CheckKey = 0, doll = 0, CheckDoll = 0, Gdoll = 0, keycard = 0, hammer = 0, CheckHammer = 0, CodeKeyCard = 0;
int barricade1 = 0, barricade2 = 0, barricade3 = 0, barricade4 = 0, barricade5 = 0, barricade6 = 0, barricade7 = 0;
int State = 0;
int StateCheck = 0;
int Teleport = 0;
bool StartPlayerPosition = 0;
float MapSizeX = 6960.0f, MapSizeY = 4920.0f;  // BLOCK Size 120*120 : 1 BLOCK // Position จะนับจากตรงกลางแล้วขยายไป
float SizeBlock = 120.0f; // สมการบล็อค =( (n+1)*120 )+ 60
int GhostState = 0, CheckGoshtG = 0, GhostState1 = 0, CheckGoshtG1 = 0, MSCheck = 0;
int GhostState2 = 0, CheckGoshtG2 = 0, GhostState12 = 0, CheckGoshtG12 = 0, MSCheck2 = 0;
int PlayerHP = 3,BottleHP = 0, BottleSP = 0;
float MaxSP = 0,PlayerSP = 0;
bool CheckDamage = 0, NMove = 0;
bool GhostGMes = 0,CodeMes = 0,CheckHintTree=0;
bool PlayerHide = 0, FindBook = 0, CheckFind = 0, CheckBook = 0, BookHP = 0, BookHP1 = 0, BookHP2 = 0, Code = 0, Gbook = 0, CheckBookHP = 0, CheckBookHP1 = 0, CheckBookHP2 = 0;
bool CheckHP1 = 0, CheckHP2 = 0, CheckHP3 = 0, CheckHP4 = 0, CheckHP5 = 0, CheckSP1 = 0, CheckSP2 = 0, CheckSP3 = 0;
bool CheckHP1_2F = 0, CheckHP2_2F = 0, CheckHP3_2F = 0, CheckSP1_2F = 0, CheckSP2_2F = 0, CheckSP3_2F = 0;
bool CorrectCheck = 0,Checkif = 0,work = 0,MenuCheck = 0;
bool MiniMap1 = 0, MiniMap2 = 0 , MiniMap3 = 0, MiniMap1v2 = 0, MiniMap2F1 = 0, MiniMap2F2 = 0, MiniMap2F3 = 0, MiniMap2F4 = 0;
bool Cheatcollision = 0, CheatLight = 0;

static const float VIEW_HEIGHT = 480.0f; //900


void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

	view.setSize(VIEW_HEIGHT * aspectRatio * 2, VIEW_HEIGHT* 1.9);
}

int main()
{

	std::string CheckCode;
	char CodePass[10] = { '6','3','0','1','0','7','9','1' };
	sf::Clock MenuTime;
	sf::Clock MenuTime2;
	sf::Clock clock;
	Clock cl;
	sf::Clock StartTime;
	sf::Clock TimeCheckHeal;
	sf::Clock DamageClock;
	sf::Clock GT;
	float StartGameTime;
	float TimeDamage ;
	float times ;
	float TimeHeal;
	float GhostATK;
	float OpenMenuTime;
	float OpenMenuTime2;
	sf::Clock stop;
	sf::RenderWindow window(sf::VideoMode(700, 700), "Makasan Kawaii !", sf::Style::Close | sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	
	

	//view.setViewport(sf::FloatRect(0.25f, 0.25f, 0.0f, 0.0f));
	//ResizeView(sf::RenderWindow & window, sf::View & VIEW_HEIGHT);

	


	/////////////////////////////////////////  TEXT //////////////////////////////////

	sf::Font MainFont;
	MainFont.loadFromFile("Font/EkkamaiNew-Regular.ttf");
	sf::Text PickedUp("Press the F to pick up ", MainFont, 25);
	sf::Text Destroy("Press the E to destroy ", MainFont, 25);
	sf::Text FindHammer("Find something to destroy ",MainFont, 25);
	sf::Text Talk("Press the F to Talk ", MainFont, 25);
	sf::Text Okay("Um...Of course!", MainFont, 25);
	sf::Text DollG1("I lost something important ",MainFont, 30);
	sf::Text DollG11("Can you help me to find it ? ", MainFont, 27);
	sf::Text DollG2("If you help me find ", MainFont, 27);
	sf::Text DollG22("I will let you through ", MainFont, 27);
	sf::Text PlayerTalkGhostG("Hello .......Can I walk through this way ?", MainFont, 25);
	sf::Text PlayerTalkGhostG2("Okay, wait for me for a moment ", MainFont, 25);
	sf::Text DollG3("Oh ! That's my doll ! ", MainFont, 27);
	sf::Text PlayerTalkGhostG3("Is this your important item ?", MainFont, 25);
	sf::Text Thankyou("Thank you !", MainFont, 27);
	sf::Text Hide("Press the F to Hide ", MainFont, 25);
	sf::Text GetOut("Press the Spacebar to Getout ", MainFont, 25);
	sf::Text Find("Press the F to Find Something ", MainFont, 25);
	sf::Text NotFind("Couldn't find anything ! ", MainFont, 25);
	sf::Text Read("Press the F to Read ", MainFont, 25);
	sf::Text Examine("Press the F to Examine", MainFont, 25);
	sf::Text BookG1("A..re you saw my book ?", MainFont, 30);
	sf::Text BookG11("Can you help me to find it ? ", MainFont, 27);
	sf::Text BookG2("If you have that BOOK ", MainFont, 27);
	sf::Text BookG22("I will let you through... ", MainFont, 27);
	sf::Text PlayerTalkGhostG32F("Is this your book ?", MainFont, 25);
	sf::Text BookG3("Oh ! That's my book ! ", MainFont, 27);
	sf::Text UseKeycard("Key Card is required for activation !", MainFont, 25);
	sf::Text Escape("Press the Spacebar to Escape ", MainFont, 25);
	sf::Text CODE("CODE : ", MainFont, 40);
	sf::Text Confirm("Press the ENTER to Confirm ", MainFont, 25);
	sf::Text Correct("Correct !", MainFont, 40);
	sf::Text NotCorrect("NotCorrect !", MainFont, 40);
	sf::Text Success("Success !", MainFont, 40);



	sf::Text PotionHP0("X 0", MainFont, 35);
	sf::Text PotionHP1("X 1", MainFont, 35);
	sf::Text PotionHP2("X 2", MainFont, 35);
	sf::Text PotionHP3("X 3", MainFont, 35);
	sf::Text PotionHP4("X 4", MainFont, 35);
	sf::Text PotionHP5("X 5", MainFont, 35);
	sf::Text PotionHP6("X 6", MainFont, 35);
	sf::Text PotionHP7("X 7", MainFont, 35);
	sf::Text PotionHP8("X 8", MainFont, 35);
	sf::Text PotionHP9("X 9", MainFont, 35);
	sf::Text PotionHP10("X 10", MainFont, 35);

	sf::Text PotionSP0("X 0", MainFont, 35);
	sf::Text PotionSP1("X 1", MainFont, 35);
	sf::Text PotionSP2("X 2", MainFont, 35);
	sf::Text PotionSP3("X 3", MainFont, 35);
	sf::Text PotionSP4("X 4", MainFont, 35);
	sf::Text PotionSP5("X 5", MainFont, 35);
	sf::Text PotionSP6("X 6", MainFont, 35);
	sf::Text PotionSP7("X 7", MainFont, 35);
	sf::Text PotionSP8("X 8", MainFont, 35);
	sf::Text PotionSP9("X 9", MainFont, 35);
	sf::Text PotionSP10("X 10", MainFont, 35);



	sf::Texture GhostGMessage;
	GhostGMessage.loadFromFile("Object/GhostGMessage.png");
	Platform GhostGMessage1(&GhostGMessage,sf::Vector2f(SizeBlock/2,SizeBlock/2), sf::Vector2f(((51) * 120) + 60, ((25) * 120) + 60));

	sf::Texture Codeborad;
	Codeborad.loadFromFile("Font/Code63010791.png");
	
	Textbox textbox1(40, sf::Color::White, true);
	textbox1.setFont(MainFont);
	


	/////////////////////////////////////////  TEXT //////////////////////////////////

	/////////////////////////////////////////  BOX Message ////////////////////////////////////
	sf::Texture MainMessageBox;
	MainMessageBox.loadFromFile("Object/messageboxmain.png");
	sf::Texture GhostMessageBox;
	GhostMessageBox.loadFromFile("Object/messageboxghost.png");
	sf::Texture GhostMessageBox2;
	GhostMessageBox2.loadFromFile("Object/messageboxghost2.png");
	sf::Texture StaminaBox;
	StaminaBox.loadFromFile("Object/messageboxstamina.png");
	sf::Texture StaminaBox1;
	StaminaBox1.loadFromFile("Object/messageboxstamina0.png");
	sf::Texture Messagebox;
	Messagebox.loadFromFile("Object/messagebox.png");
	
	/////////////////////////////////////////  BOX Message ////////////////////////////////////

	///////////////////////////////////////// Player /////////////////////////////////////////
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Player/SonyeoFull.png");
	Player player(&playerTexture, sf::Vector2u(4, 8), 0.25f, 70.0f,1);
	player.SetPosition(sf::Vector2f(2400.0f, 4440.0f));
	
	sf::Texture PlayerHeart3;
	PlayerHeart3.loadFromFile("Player/HP3.png");
	sf::Texture PlayerHeart2;
	PlayerHeart2.loadFromFile("Player/HP2.png");
	sf::Texture PlayerHeart1;
	PlayerHeart1.loadFromFile("Player/HP1.png");
	sf::Texture PlayerHeart0;
	PlayerHeart0.loadFromFile("Player/HP0.png");




	//////////////////////////////////////////// HP + SP //////////////////////////////
	sf::Texture HPTexture;
	HPTexture.loadFromFile("Item/HP Potion.png");
	sf::Texture SPTexture;
	SPTexture.loadFromFile("Item/SP Potion.png");
	sf::Texture BoxHPTexture;
	BoxHPTexture.loadFromFile("Item/HP PotionBox.png");
	///////////////////////////////////////////// 1 FLOOR ////////////////////////////////////////////
	Platform HP1(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((5) * 120) + 60, ((7) * 120) + 60 + 30));
	Platform HP2(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((49) * 120) + 60, ((20) * 120) + 60 + 30));
	Platform HP3(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((28) * 120) + 60, ((6) * 120) + 60 + 30));
	Platform HP4(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((39) * 120) + 60, ((38) * 120) + 60 + 30)); 
	Platform HP5(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((53) * 120) + 60, ((5) * 120) + 60 + 30));
	Platform SP1(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((55) * 120) + 60, ((32) * 120) + 60));
	Platform SP2(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((26) * 120) + 60, ((19) * 120) + 60));
	Platform SP3(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((1) * 120) + 60, ((21) * 120) + 60));

	///////////////////////////////////////////// 2 FLOOR ////////////////////////////////////////////

	Platform HP1_2F(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((9) * 120) + 60, ((6) * 120) + 60 + 30));
	Platform HP2_2F(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((26) * 120) + 60, ((35) * 120) + 60 + 30));
	Platform HP3_2F(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((50) * 120) + 60, ((27) * 120) + 60 + 30));
	Platform SP1_2F(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((31) * 120) + 60, ((35) * 120) + 60));
	Platform SP2_2F(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((49) * 120) + 60, ((19) * 120) + 60));
	Platform SP3_2F(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((8) * 120) + 60, ((33) * 120) + 60));

	//////////////////////////////////////////// HP + SP //////////////////////////////
	
	///////////////////////////////////////// Player /////////////////////////////////////////

	///////////////////////////////////////// Enemy /////////////////////////////////////////
	sf::Texture WEnemyTexture;
	WEnemyTexture.loadFromFile("Monster/Ghostw.png");
	sf::Texture BEnemyTexture;
	BEnemyTexture.loadFromFile("Monster/GhostB.png");
	sf::Texture GEnemyTexture;
	GEnemyTexture.loadFromFile("Monster/GhostG.png");
	sf::Texture GEnemyTexture2;
	GEnemyTexture2.loadFromFile("Monster/Ghost2G.png");

	std::vector<Enemy> WEnemys1;
	std::vector<Enemy> BEnemys1;
	std::vector<Enemy> GEnemys1;
	std::vector<Enemy> WEnemys2;
	std::vector<Enemy> BEnemys2;
	std::vector<Enemy> GEnemys2;
	sf::Texture GEnemyBlock;
	sf::Texture GEnemy2Block;

	Platform GEnemyBlock1(&GEnemyBlock, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((47) * 120) + 60, ((6) * 120) + 60));
	Platform GEnemyBlock2(&GEnemy2Block, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((35) * 120) + 60, ((26) * 120) + 60));
	///////////////////////////////////////// Enemy /////////////////////////////////////////
	////////////////////////////////////////////////////// MAP + MiniMap ////////////////////////////////////////

	sf::Texture Map01;
	Map01.loadFromFile("Map/Map1Full.png");
	Platform Map01Texture(&Map01, sf::Vector2f(MapSizeX, MapSizeY), sf::Vector2f(3480.0f, 2460.0f));
	sf::Texture Map02;
	Map02.loadFromFile("Map/Map2Full.png");
	Platform Map02Texture(&Map02, sf::Vector2f(MapSizeX, MapSizeY), sf::Vector2f(3480.0f, 2460.0f));
	std::vector<Map1> Block0;
	std::vector<Map1> Block1;

	sf::Texture MiniMap1F1;
	MiniMap1F1.loadFromFile("Map/MiniMap/MiniMap1.png");
	sf::Texture MiniMap1F1v2;
	MiniMap1F1v2.loadFromFile("Map/MiniMap/MiniMap1v2.png");
	sf::Texture MiniMap1F2;
	MiniMap1F2.loadFromFile("Map/MiniMap/MiniMap2.png");
	sf::Texture MiniMap1F3;
	MiniMap1F3.loadFromFile("Map/MiniMap/MiniMap3.png");

	sf::Texture MiniMap2F1;
	MiniMap2F1.loadFromFile("Map/MiniMap/MiniMap2F1.png");
	sf::Texture MiniMap2F2;
	MiniMap2F2.loadFromFile("Map/MiniMap/MiniMap2F2.png");

	
	
	////////////////////////////////////////////////////// MAP + MiniMap ////////////////////////////////////////


	////////////////////////////////// MENU ///////////////////////////////////

	sf::Texture MenuP0;
	MenuP0.loadFromFile("Manu/ManuFull.png");
	sf::Texture MenuP1;
	MenuP1.loadFromFile("Manu/ManuFull2.png");
	sf::Texture testbox;
	testbox.loadFromFile("Manu/testbox.png");
	sf::Texture PlayP0;
	PlayP0.loadFromFile("Manu/Player0.png");
	sf::Texture PlayP1;
	PlayP1.loadFromFile("Manu/Player1.png");
	sf::Texture HIGHSCOREP0;
	HIGHSCOREP0.loadFromFile("Manu/HIGHSCORE0.png");
	sf::Texture HIGHSCOREP1;
	HIGHSCOREP1.loadFromFile("Manu/HIGHSCORE1.png");
	sf::Texture HOWTOPLAYP0;
	HOWTOPLAYP0.loadFromFile("Manu/HOWTOPLAY0.png");
	sf::Texture HOWTOPLAYP1;
	HOWTOPLAYP1.loadFromFile("Manu/HOWTOPLAY1.png");
	sf::Texture EXITP0;
	EXITP0.loadFromFile("Manu/EXIT0.png");
	sf::Texture EXITP1;
	EXITP1.loadFromFile("Manu/EXIT1.png");
	sf::Texture HTP1;
	HTP1.loadFromFile("Manu/HOW TO PLAY 1.png");
	sf::Texture NEXT;
	NEXT.loadFromFile("Manu/NEXT.png");
	sf::Texture NEXT2;
	NEXT2.loadFromFile("Manu/NEXT2.png");
	sf::Texture BACK;
	BACK.loadFromFile("Manu/BACK.png");
	sf::Texture BACK2;
	BACK2.loadFromFile("Manu/BACK2.png");


	Platform Manu0(&MenuP0, sf::Vector2f(1920,1080), sf::Vector2f(1920/2, 1080/2));
	Platform Manu1(&MenuP1, sf::Vector2f(1920, 1080), sf::Vector2f(1920 / 2, 1080 / 2));
	Platform Play0(&PlayP0, sf::Vector2f(340, 130), sf::Vector2f(1170, 500));
	Platform Play1(&PlayP1, sf::Vector2f(340, 130), sf::Vector2f(1170, 500));
	Platform HIGHSCORE0(&HIGHSCOREP0, sf::Vector2f(510, 100), sf::Vector2f(1375, 675));
	Platform HIGHSCORE1(&HIGHSCOREP1, sf::Vector2f(510, 100), sf::Vector2f(1375, 675));
	Platform HOWTOPLAY0(&HOWTOPLAYP0, sf::Vector2f(480, 100), sf::Vector2f(1650, 815));
	Platform HOWTOPLAY1(&HOWTOPLAYP1, sf::Vector2f(480, 100), sf::Vector2f(1650, 815));
	Platform EXIT0(&EXITP0, sf::Vector2f(190, 80), sf::Vector2f(1650, 950));
	Platform EXIT1(&EXITP1, sf::Vector2f(190, 80), sf::Vector2f(1650, 950));
	Platform HTP01(&HTP1, sf::Vector2f(1920, 1080), sf::Vector2f(1920/2, 1080/2));
	Platform MenuNEXT(&NEXT, sf::Vector2f(180, 176), sf::Vector2f(1790, 955)); //1790
	Platform MenuNEXT2(&NEXT2, sf::Vector2f(180, 176), sf::Vector2f(1790 , 955));
	Platform MenuBACK(&BACK, sf::Vector2f(180, 176), sf::Vector2f(160, 955)); //160
	Platform MenuBACK2(&BACK2, sf::Vector2f(180, 176), sf::Vector2f(160, 955));

	////////////////////////////////// MENU ///////////////////////////////////


	sf::Texture HintTree;
	HintTree.loadFromFile("Object/HintTree.png");
	

	sf::Texture Light;
	Light.loadFromFile("Object/light-on.png");
	

	

	sf::Texture Object1;
	Object1.loadFromFile("Object/Box.png");
	Platform Object(&Object1, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((39) * 120) + 60, ((24) * 120) + 85));

	sf::Texture ObjectT1;
	ObjectT1.loadFromFile("Object/T1test.png");
	Platform ObjectTree1(&ObjectT1, sf::Vector2f(SizeBlock, SizeBlock * 3), sf::Vector2f(((9) * 120) + 60, ((25) * 120) + 60));
	sf::Texture ObjectT01;
	ObjectT01.loadFromFile("Object/T001.png");
	Platform ObjectTree01(&ObjectT01, sf::Vector2f(SizeBlock, SizeBlock * 3), sf::Vector2f(((9) * 120) + 60, ((25) * 120) + 60));

	sf::Texture Key;
	Key.loadFromFile("Item/key.png");
	Platform Key1(&Key, sf::Vector2f(SizeBlock / 1.7, SizeBlock / 1.7), sf::Vector2f(((25) * 120) + 60, ((6) * 120) + 60));

	sf::Texture Doll;
	Doll.loadFromFile("Item/Doll.png");
	Platform Doll1(&Doll, sf::Vector2f(SizeBlock / 1.7, SizeBlock / 1.7), sf::Vector2f(((14.2) * 120) + 60, ((37.8) * 120) + 60));
	Platform Doll2(&Doll, sf::Vector2f(SizeBlock / 1.7, SizeBlock / 1.7), sf::Vector2f(((5) * 120) + 60, ((4.1) * 120) + 60));
	Platform Doll3(&Doll, sf::Vector2f(SizeBlock / 1.7, SizeBlock / 1.7), sf::Vector2f(((47) * 120) + 60, ((18) * 120) + 60));
	Platform Doll4(&Doll, sf::Vector2f(SizeBlock / 1.7, SizeBlock / 1.7), sf::Vector2f(((43) * 120) + 60, ((27) * 120) + 60));

	sf::Texture Book;
	Book.loadFromFile("Item/Book.png");
	

	sf::Texture Hammer;
	Hammer.loadFromFile("Item/Hammer1.png");
	Platform Hammer1(&Hammer, sf::Vector2f(SizeBlock / 1.5, SizeBlock / 1.5), sf::Vector2f(((6) * 120) + 60, ((27) * 120) + 60));

	sf::Texture Keycard;
	Keycard.loadFromFile("Item/keycard.png");
	Platform Keycard1(&Keycard, sf::Vector2f(SizeBlock / 2.5, SizeBlock / 2.5), sf::Vector2f(((16) * 120) + 60, ((4.1) * 120) + 60));

	sf::Texture Barricade;
	sf::Texture BarricadeR;
	sf::Texture BarricadeBroken;
	Barricade.loadFromFile("Object/barricade.png");
	BarricadeR.loadFromFile("Object/barricadeR.png");
	BarricadeBroken.loadFromFile("Object/barricadeBroken.png");
	Platform Barricade1(&Barricade, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((9) * 120) + 60, ((22) * 120) + 60));
	Platform Barricade2(&Barricade, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((43) * 120) + 60, ((14) * 120) + 60));
	Platform Barricade3(&Barricade, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((44) * 120) + 60, ((14) * 120) + 60));
	Platform Barricade4(&BarricadeR, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((36) * 120) + 60, ((4) * 120) + 60));
	Platform Barricade5(&BarricadeR, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((36) * 120) + 60, ((5) * 120) + 60));
	Platform Barricade6(&Barricade, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((20.1) * 120) + 60, ((15) * 120) + 60)); //ขวางบันได
	Platform Barricade7(&Barricade, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((21) * 120) + 60, ((15) * 120) + 60));//ขวางบันได
	Platform BarricadeBroken1(&BarricadeBroken, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((9) * 120) + 60, ((22) * 120) + 60));
	Platform BarricadeBroken2(&BarricadeBroken, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((43) * 120) + 60, ((14) * 120) + 60));
	Platform BarricadeBroken3(&BarricadeBroken, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((44) * 120) + 60, ((14) * 120) + 60));
	Platform BarricadeBroken4(&BarricadeBroken, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((36) * 120) + 60, ((4) * 120) + 60));
	Platform BarricadeBroken5(&BarricadeBroken, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((36) * 120) + 60, ((5) * 120) + 60));
	Platform BarricadeBroken6(&BarricadeBroken, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((20.1) * 120) + 60, ((15) * 120) + 60));
	Platform BarricadeBroken7(&BarricadeBroken, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(((21) * 120) + 60, ((15) * 120) + 60));
	//Platform platform2(nullptr, sf::Vector2f(SizeBlock, SizeBlock), sf::Vector2f(60.0f, 180.0f));



	int map1[41][58] = {
	//////0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},//0
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//1
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//2
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 2, 2, 2, 2, 2, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//3
		{ 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2},//4
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 2, 2, 2, 2, 2, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 2},//5
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 2, 2, 2, 2, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 2},//6
		{ 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 2},//7
		{ 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 2},//8
		{ 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 2},//9
		{ 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2},//10
		{ 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//11
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//12
		{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2},//13
		{ 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 2},//14
		{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 2},//15
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2},//16
		{ 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 2},//17
		{ 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 2},//18
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 2, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 2},//19
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 2},//20
		{ 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 2},//21
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2},//22
		{ 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},//23
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},//24
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2},//25
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 2},//26
		{ 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2},//27
		{ 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 2, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2},//28
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2},//29
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2},//30
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 2},//31
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 2},//32
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 2},//33
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 2},//34
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2},//35
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2},//36
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2},//37
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2},//38
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//39
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2} //40
	};


	int map2[41][58] = {
		//////0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},//0
			{ 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//1
			{ 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//2
			{ 2, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//3
			{ 2, 2, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2},//4
			{ 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 2},//5
			{ 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},//6
			{ 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2},//7
			{ 2, 2, 2, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2},//8
			{ 2, 2, 2, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 2},//9
			{ 2, 2, 2, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 2},//10
			{ 2, 2, 2, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2},//11
			{ 0, 2, 2, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2},//12
			{ 2, 2, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 2},//13
			{ 2, 2, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 2},//14
			{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 2},//15
			{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2},//16
			{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 2},//17
			{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2},//18
			{ 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2},//19
			{ 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//20
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//21
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2},//22
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2},//23
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2},//24
			{ 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 2},//25
			{ 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 2},//26
			{ 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 2},//27
			{ 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//28
			{ 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//29
			{ 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//30
			{ 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//31
			{ 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//32
			{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//33
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2},//34
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//35
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//36
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//37
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//38
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//39
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2} //40
	};
	
	////////////////////////////   Ghost White1  && Ghost Black1 //////////////////////////////////

	int WEnemyY[8] = { -60,-60,-60, -40,-60,-4600,-60,-60 };			
	int WEnemyY1[8] = { 3600,3960,4200,4500,5100,5500,5000,5000 };
	int WpositionX[8] = {180,900,420,660,4500,4500,5220,5340 };

	int WEnemyX[8] = { -120,-120,-120,-100,3000,3600,3780,3780 };		
	int WEnemyX1[8] = { 1320,1440,2400,1500,6960,8000,7200,7200 };		
	int WpositionY[8] = {1860,2760,420,1140,1680,1680,3300,4500};	

	

	
	for (int i = 0; i < 8; i++)
	{

			WEnemys1.push_back(Enemy(&WEnemyTexture, sf::Vector2u(4, 4), 0.5, 230.0f, WEnemyY[i], WEnemyY1[i], 0, 0, 0, WpositionX[i], 0));
			WEnemys1.push_back(Enemy(&WEnemyTexture, sf::Vector2u(4, 4), 0.5, 230.0f, 0, 0, WEnemyX[i], WEnemyX1[i], 1, 0, WpositionY[i]));
		
			BEnemys1.push_back(Enemy(&BEnemyTexture, sf::Vector2u(4, 4), 0.3, 300.0f, WEnemyY[i], WEnemyY1[i], 0, 0, 0, WpositionX[i], 0));
			BEnemys1.push_back(Enemy(&BEnemyTexture, sf::Vector2u(4, 4), 0.3, 300.0f, 0, 0, WEnemyX[i], WEnemyX1[i], 1, 0, WpositionY[i]));
		
	}

	////////////////////////////   Ghost White1  && Ghost Black1//////////////////////////////////

	////////////////////////////   Ghost Green1  //////////////////////////////////

	int GEnemyY[1] = { 0 };
	int GEnemyY1[1] = { 0 };
	int GpositionX[1] = { 5700 };

	int GEnemyX[1] = { 0 };
	int GEnemyX1[1] = { 0 };
	int GpositionY[1] = { 780 };

	for (int i = 0; i < 1; i++)
	{
		GEnemys1.push_back(Enemy(&GEnemyTexture, sf::Vector2u(3, 4), 0.5, 250.0f, GEnemyY[i], GEnemyY1[i], 0, 0, 2, GpositionX[i], GpositionY[i]));
	}
	
	////////////////////////////   Ghost Green1 //////////////////////////////////

	///////////////////////////////////////////////////////// 2 Floor  ////////////////////////////////////////////////

	////////////////////////////   Ghost White2  && Ghost Black2//////////////////////////////////

	int WEnemyY2F[8] = { -60,-60,-60,-60,-60,-1200};
	int WEnemyY12F[8] = { 4900,4900,4900,4800,4800,4800};
	int WpositionX2F[8] = { 780,4860,4980,6180,4260,4260};

	int WEnemyX2F[8] = { -60,-120,-60,-60,-90,-3000 };
	int WEnemyX12F[8] = { 7550,1320,7550,7000,6900,6900 };
	int WpositionY2F[8] = { 2120,1860,4500,3420,4080,4080 };




	for (int i = 0; i < 6; i++)
	{

		WEnemys2.push_back(Enemy(&WEnemyTexture, sf::Vector2u(4, 4), 0.5, 230.0f, WEnemyY2F[i], WEnemyY12F[i], 0, 0, 0, WpositionX2F[i], 0));
		WEnemys2.push_back(Enemy(&WEnemyTexture, sf::Vector2u(4, 4), 0.5, 230.0f, 0, 0, WEnemyX2F[i], WEnemyX12F[i], 1, 0, WpositionY2F[i]));

		BEnemys2.push_back(Enemy(&BEnemyTexture, sf::Vector2u(4, 4), 0.75, 300.0f, WEnemyY2F[i], WEnemyY12F[i], 0, 0, 0, WpositionX2F[i], 0));
		BEnemys2.push_back(Enemy(&BEnemyTexture, sf::Vector2u(4, 4), 0.75, 300.0f, 0, 0, WEnemyX2F[i], WEnemyX12F[i], 1, 0, WpositionY2F[i]));

	}

	////////////////////////////   Ghost White2  && Ghost Black2//////////////////////////////////

	int GEnemyY2F[1] = { 0 };
	int GEnemyY12F[1] = { 0 };
	int GpositionX2F[1] = { 4260 };

	int GEnemyX2F[1] = { 0 };
	int GEnemyX12F[1] = { 0 };
	int GpositionY2F[1] = { 3120 };

	for (int i = 0; i < 1; i++)
	{
		GEnemys2.push_back(Enemy(&GEnemyTexture2, sf::Vector2u(3, 4), 0.5, 250.0f, GEnemyY2F[i], GEnemyY12F[i], 0, 0, 2, GpositionX2F[i], GpositionY2F[i]));
	}

	///////////////////////////////////////////////////////// 2 Floor  ////////////////////////////////////////////////

	////////////////////////////  Random Doll  ////////////////////////////
	int random[4];
	int DollRandom;
	srand(time(NULL));
	for (int a = 0; a < 4; a++)
	{
		int ch = -1;
		while (1)
		{
			int re = 0;
			ch = rand() % 4 + 1;
			for (int j = 0; j < 4; j++) {
				if (ch == random[j]) {
					re = 1;
				}
			}
			if (re == 0) {
				random[a] = ch;
				break;
			}
		}
	}
	//printf("%d\n", random[1]);
	if (random[1] == 1) {
		DollRandom = 1;
	}
	else if (random[1] == 2) {
		DollRandom = 2;
	}
	else if (random[1] == 3) {
		DollRandom = 3;
	}
	else if (random[1] == 4) {
		DollRandom = 4;
	}
	////////////////////////////  Random Doll  ////////////////////////////


	float deltaTime = 0.0f;
	float counting_stop = 0;
	bool isShift = false;
	


	while (window.isOpen())
	{
		OpenMenuTime = MenuTime.getElapsedTime().asMilliseconds();
		OpenMenuTime2 = MenuTime2.getElapsedTime().asMilliseconds();
		TimeDamage = DamageClock.getElapsedTime().asMilliseconds();
		times = cl.getElapsedTime().asSeconds();
		GhostATK = GT.getElapsedTime().asMilliseconds();
		TimeHeal = TimeCheckHeal.getElapsedTime().asMilliseconds();
		StartGameTime = StartTime.getElapsedTime().asMilliseconds();

		float PositionPlayerX = float((player.GetCollider().GetPosition().x) / (MapSizeX / 58.0));
		float PositionPlayerY = float((player.GetCollider().GetPosition().y) / (MapSizeY / 41.0));
		deltaTime = clock.restart().asSeconds();
		counting_stop = stop.getElapsedTime().asMilliseconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			//case sf::Event::Resized:
				//ResizeView(window, view);
				//break;
			case sf::Event::TextEntered:
				if (CodeMes == 1) {
					textbox1.typedOn(evnt);
				}
			}
		}
		window.setFramerateLimit(90);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		ResizeView(window, view);
		 /////////////////////////////////// MENU /////////////////////////////////
			
		if (GameState == 3) {	
			if (HTP == 0) {

				if (MenuCheck == 0) {
					Manu0.Draw(window);
					Play0.Draw(window);
					HIGHSCORE0.Draw(window);
					HOWTOPLAY0.Draw(window);
					EXIT0.Draw(window);
				}
				if (OpenMenuTime > 5000) {
					MenuCheck = 1;
					//if (OpenMenuTime2 > 1000) {
						//if (TimeDamage > 3000)
						//{
					Manu1.Draw(window);
					Play0.Draw(window);
					HIGHSCORE0.Draw(window);
					HOWTOPLAY0.Draw(window);
					EXIT0.Draw(window);
					//}
					//if (TimeDamage > 3020)DamageClock.restart();
				//}
				//if (OpenMenuTime2 > 2000)MenuTime2.restart();
					if (OpenMenuTime > 5500) {
						MenuTime.restart();
					}
				}
				else {
					MenuCheck = 0;
				}

				if (Play0.body.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
					Play1.Draw(window);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						GameState = 0;
						StartTime.restart();
						window.clear();
					}
				}
				if (HIGHSCORE0.body.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
					HIGHSCORE1.Draw(window);
				}
				if (HOWTOPLAY0.body.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
					HOWTOPLAY1.Draw(window);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and times > 1) {
						HTP++;
						cl.restart();
						
					}

				}
				if (EXIT0.body.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
					EXIT1.Draw(window);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
						window.close();
					}
				}
			}
			if (HTP >= 1) {
			
				if (HTP == 1) {
					HTP01.Draw(window);
					if (MenuNEXT.body.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
						MenuNEXT2.Draw(window);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
							HTP++;
						}
						
					}
					else {
						MenuNEXT.Draw(window);
					}
					if (MenuBACK.body.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
						MenuBACK2.Draw(window);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
							HTP--;
						}
					}
					else {
						MenuBACK.Draw(window);
					}
				}
				else if (HTP == 2) {

				}
				
			}



		}

		/////////////////////////////////// MENU /////////////////////////////////

		



		if (GameState == 0) {

		Platform Light1(&Light, sf::Vector2f(SizeBlock * 30, SizeBlock * 25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));


		/////////////////////////////////// USE HP + SP /////////////////////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) and TimeHeal >= 500) {
			if (BottleHP >= 1 and PlayerHP < 3) {
				BottleHP--;
				PlayerHP++;
				TimeCheckHeal.restart();
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) and TimeHeal >= 500) {
			if (BottleSP >= 1) {
				BottleSP--;
				PlayerSP = 0;
				TimeCheckHeal.restart();
			}

		}
		

		//////////////////////// คีย์ลัดโกง ////////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
			Cheatcollision = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
			Cheatcollision = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
			CheatLight = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {
			CheatLight = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			PlayerSP = 0;
		}

		//////////////////////// คีย์ลัดโกง ////////////

		/////////////////////////////////// USE HP + SP /////////////////////////

		if ((int(PositionPlayerX) == 20 or int(PositionPlayerX) == 21) and int(PositionPlayerY) == 13 and Teleport == 0)
		{
			State = 1;
			StateCheck = 1;
		}
		if ((int(PositionPlayerX) == 18 or int(PositionPlayerX) == 19 or int(PositionPlayerX) == 20) and int(PositionPlayerY) == 13 and Teleport == 1)
		{
			State = 0;
			StateCheck = 1;
		}
		//////////// Ghost Green ///////////////////////
		Platform MessageBoxEmpty(&Messagebox, sf::Vector2f(SizeBlock * 6, SizeBlock * 1.5), sf::Vector2f((PositionPlayerX - 4) * 120, (PositionPlayerY) * 120));
		Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 6, SizeBlock * 1.5), sf::Vector2f((PositionPlayerX - 4) * 120, (PositionPlayerY - 2.9) * 120));
		Platform MessageBoxGhost(&GhostMessageBox, sf::Vector2f(SizeBlock * 6, SizeBlock * 1.5), sf::Vector2f((PositionPlayerX + 4) * 120, (PositionPlayerY + 2.9) * 120));
		Platform MessageBoxGhost2(&GhostMessageBox2, sf::Vector2f(SizeBlock * 6, SizeBlock * 1.5), sf::Vector2f((PositionPlayerX + 3.7) * 120, (PositionPlayerY + 2.9) * 120));

		PlayerTalkGhostG.setPosition((PositionPlayerX - 5.5) * 120, (PositionPlayerY - 3.5) * 120);
		PlayerTalkGhostG2.setPosition((PositionPlayerX - 5.5) * 120, (PositionPlayerY - 3.5) * 120);
		PlayerTalkGhostG3.setPosition((PositionPlayerX - 5.5) * 120, (PositionPlayerY - 3.5) * 120);
		DollG1.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.3) * 120);
		DollG11.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.7) * 120);
		DollG2.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.3) * 120);
		DollG22.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.7) * 120);
		DollG3.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.3) * 120);
		Okay.setPosition((PositionPlayerX - 5.5) * 120, (PositionPlayerY - 3.5) * 120);
		Thankyou.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.3) * 120);

		BookG1.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.3) * 120);
		BookG11.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.7) * 120);
		BookG2.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.3) * 120);
		BookG22.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.7) * 120);
		BookG3.setPosition((PositionPlayerX + 2.3) * 120, (PositionPlayerY + 2.3) * 120);
		PlayerTalkGhostG32F.setPosition((PositionPlayerX - 5.5) * 120, (PositionPlayerY - 3.5) * 120);
		//////////// Ghost Green ///////////////////////
		

		


		player.Update(deltaTime, PlayerHide, PlayerSP, NMove);
		//Enemy1.Update(deltaTime);

		Platform PlayerHeart31(&PlayerHeart3, sf::Vector2f(SizeBlock / 1.5, SizeBlock / 1.5), sf::Vector2f((player.GetPosition().x - 780), (player.GetPosition().y - 380)));
		Platform PlayerHeart21(&PlayerHeart2, sf::Vector2f(SizeBlock / 1.5, SizeBlock / 1.5), sf::Vector2f((player.GetPosition().x - 780), (player.GetPosition().y - 380)));
		Platform PlayerHeart11(&PlayerHeart1, sf::Vector2f(SizeBlock / 1.5, SizeBlock / 1.5), sf::Vector2f((player.GetPosition().x - 780), (player.GetPosition().y - 380)));
		Platform PlayerHeart01(&PlayerHeart0, sf::Vector2f(SizeBlock / 1.5, SizeBlock / 1.5), sf::Vector2f((player.GetPosition().x - 780), (player.GetPosition().y - 380)));

		Platform PotionHP(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f((player.GetPosition().x + 700), (player.GetPosition().y + 400)));
		PotionHP0.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP1.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP2.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP3.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP4.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP5.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP6.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP7.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP8.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP9.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		PotionHP10.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 380));
		Platform PotionSP(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f((player.GetPosition().x + 700), (player.GetPosition().y + 325)));
		PotionSP0.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP1.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP2.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP3.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP4.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP5.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP6.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP7.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP8.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP9.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));
		PotionSP10.setPosition((player.GetPosition().x + 750), (player.GetPosition().y + 305));

		Platform2 Stamina_Texture(&StaminaBox1, sf::Vector2f(SizeBlock * (2 - (PlayerSP) / 100), SizeBlock / 4), sf::Vector2f((player.GetPosition().x - 838), (player.GetPosition().y + 387)));
		Platform2 Stamina_Texture1(&StaminaBox, sf::Vector2f(SizeBlock * 2.08, SizeBlock / 3.3), sf::Vector2f((player.GetPosition().x - 840), (player.GetPosition().y + 384)));
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) and ( (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) or (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ) )
		{
			if (PlayerSP <= 200)
			{
				PlayerSP += 1.5;
			}

		}
		else {
			if (PlayerSP >= 0) {
				PlayerSP -= 0.25;
			}

		}

		Collider Test = player.GetCollider();


		view.setCenter(player.GetPosition());

		window.clear(sf::Color(100, 100, 100));
		window.setView(view);

		if (StateCheck == 1) {
			window.clear();
			StateCheck = 0;
		}
		
	
	//////////////////////////////////////////////////////////// Game Game Game Game Game Game Game Game Game ////////////////////////////////////////////////////
		if (State == 0) {
			for (int mapX = 0; mapX < 58; mapX++)
			{
				for (int mapY = 0; mapY < 41; mapY++)
				{
					if (map1[mapY][mapX] == 0)
					{
						Map1 temp(nullptr, Vector2f(((mapX) * 120) + 60, ((mapY) * 120) + 60), Vector2f(SizeBlock, SizeBlock));
						Block0.push_back(temp);
					}
				}
			}
			if (StartPlayerPosition == 1) {
				player.SetPosition(sf::Vector2f(2520.0f, 1860.0f));
			}

			StartPlayerPosition = 1;
			State = -1;
			Teleport = 0;
		}


		if (Teleport == 0) {
			
			for (Map1& m : Block0) m.draw(window);
			for (int i = 0; i < Block0.size(); i++)
			{
				if (Cheatcollision == 0) {
					Block0[i].GetCollider().CheckCollision(Test, 1.0f);
				}
			}
			
			Map01Texture.Draw(window);

			if ((int(PositionPlayerX) == 6 or int(PositionPlayerX) == 5) and int(PositionPlayerY) == 7) {
				if (CheckHP1 == 0) {
					HP1.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP1 = 1;
						BottleHP++;
					}
				}	
			}
			else 
			{
				if (CheckHP1 == 0) 
				{
					HP1.Draw(window);
				}
				
			}
			
			if ((int(PositionPlayerX) == 50 or int(PositionPlayerX) == 49) and (int(PositionPlayerY) == 20 or int(PositionPlayerY) == 21))  {
				if (CheckHP2 == 0) {
					HP2.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP2 = 1;
						BottleHP++;
					}
				}
			}
			else
			{
				if (CheckHP2 == 0)
				{
					HP2.Draw(window);
				}

			}
			
			if ((int(PositionPlayerX) == 28 or int(PositionPlayerX) == 27) and (int(PositionPlayerY) == 6 or int(PositionPlayerY) == 5)) {
				if (CheckHP3 == 0) {
					HP3.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP3 = 1;
						BottleHP++;
					}
				}
			}
			else
			{
				if (CheckHP3 == 0)
				{
					HP3.Draw(window);
				}

			}

			if ((int(PositionPlayerX) == 39 or int(PositionPlayerX) == 40) and (int(PositionPlayerY) == 38 or int(PositionPlayerY) == 37)) {
				if (CheckHP4 == 0) {
					HP4.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP4 = 1;
						BottleHP++;
					}
				}
			}
			else
			{
				if (CheckHP4 == 0)
				{
					HP4.Draw(window);
				}

			}

			if ((int(PositionPlayerX) == 53 or int(PositionPlayerX) == 54) and (int(PositionPlayerY) == 5 or int(PositionPlayerY) == 6)) {
				if (CheckHP5 == 0) {
					HP5.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP5 = 1;
						BottleHP++;
					}
				}
			}
			else
			{
				if (CheckHP5 == 0)
				{
					HP5.Draw(window);
				}

			}
			
			if ((int(PositionPlayerX) == 55 or int(PositionPlayerX) == 54) and (int(PositionPlayerY) == 32 or int(PositionPlayerY) == 33)) {
				if (CheckSP1 == 0) {
					SP1.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckSP1 = 1;
						BottleSP++;
					}
				}
			}
			else
			{
				if (CheckSP1 == 0)
				{
					SP1.Draw(window);
				}
			}
			if ((int(PositionPlayerX) == 26 or int(PositionPlayerX) == 27) and (int(PositionPlayerY) == 18 or int(PositionPlayerY) == 19)) {
				if (CheckSP2 == 0) {
					SP2.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckSP2 = 1;
						BottleSP++;
					}
				}
			}
			else
			{
				if (CheckSP2 == 0)
				{
					SP2.Draw(window);
				}
			}
			if (int(PositionPlayerX) == 1 and (int(PositionPlayerY) == 20 or int(PositionPlayerY) == 21 or int(PositionPlayerY) == 22)) {
				if (CheckSP3 == 0) {
					SP3.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckSP3 = 1;
						BottleSP++;
					}
				}
			}
			else
			{
				if (CheckSP3 == 0)
				{
					SP3.Draw(window);
				}
			}

			/*
			Platform HP4(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((33) * 120) + 60, ((21) * 120) + 60 + 30)); //2 Floor
			Platform HP5(&HPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((8) * 120) + 60, ((3) * 120) + 60 + 30));

			
			Platform SP2(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((31) * 120) + 60, ((35) * 120) + 60));//2 Floor
			Platform SP3(&SPTexture, sf::Vector2f(SizeBlock / 2, SizeBlock / 2), sf::Vector2f(((26) * 120) + 60, ((35) * 120) + 60));

			*/
			
			

			//for (Platform& H : HP) H.Update(deltaTime);
			//for (Platform& H : HP) H.Draw(window);
			//for (Platform& S : SP) S.Update(deltaTime);
			//for (Platform& S : SP) S.Draw(window);
			
			//////////////////////////// SEE MAP ////////////////////////////////
			if (int(PositionPlayerX) == 24 and int(PositionPlayerY) == 16) {
				Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
				MessageBox0.Draw(window);
				Examine.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
				window.draw(Examine);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					MiniMap1 = 1;
				}

			}
			if ((int(PositionPlayerX) == 47 or int(PositionPlayerX) == 46) and int(PositionPlayerY) == 26) {
				Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
				MessageBox0.Draw(window);
				Examine.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
				window.draw(Examine);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					MiniMap2 = 1;
				}
				
			}
			if (int(PositionPlayerX) == 45 and int(PositionPlayerY) == 12) {
				Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
				MessageBox0.Draw(window);
				Examine.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
				window.draw(Examine);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					MiniMap3 = 1;
				}
				
			}


			//////////////////////////////////////////// Hide1F /////////////////////////////////////////
			if (((int(PositionPlayerX) == 3 and int(PositionPlayerY) == 7)) or (int(PositionPlayerX) == 5 and int(PositionPlayerY) == 27) or (int(PositionPlayerX) == 48 and int(PositionPlayerY) == 27)){
				if (PlayerHide == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Hide.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Hide);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						PlayerHide = 1;
					}
				}
				if (PlayerHide == 1) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.0, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					GetOut.setPosition((PositionPlayerX - 1.0) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(GetOut);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						
						PlayerHide = 0;
					}
				}
			}
			//////////////////////////////////////////// Hide1F /////////////////////////////////////////
			Platform HintTree1(&HintTree, sf::Vector2f(60, 60), sf::Vector2f(420, 3400));
			HintTree1.Draw(window);
			if (int(PositionPlayerX) == 3 and (int(PositionPlayerY) == 28 or int(PositionPlayerY) == 27)) {
				if (CheckHintTree == 0) {	
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY - 1.3) * 120);
					window.draw(PickedUp);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					CheckHintTree = 1;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					CheckHintTree = 0;
				}
			}
			else {
				CheckHintTree = 0;
			}
			


			CheckCode = textbox1.getText();
			if ((int(PositionPlayerX) == 36 or int(PositionPlayerX) == 37) and int(PositionPlayerY) == 10) {
				
				if(CodeKeyCard == 0){
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Examine.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Examine);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					CodeKeyCard = 1;
				}
				else if (CodeKeyCard == 1) {
					if (work == 0) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						CodeKeyCard = 0;
					}
					if (keycard == 0) {
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.7, SizeBlock), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
						MessageBox0.Draw(window);
						UseKeycard.setPosition((PositionPlayerX - 1.2) * 120, (PositionPlayerY + 1.1) * 120);
						window.draw(UseKeycard);
					}
					else if (keycard == 1) {
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.7, SizeBlock), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
						MessageBox0.Draw(window);
						Escape.setPosition((PositionPlayerX - 1.2) * 120, (PositionPlayerY + 0.85) * 120);
						window.draw(Escape);
						Confirm.setPosition((PositionPlayerX - 1.2) * 120, (PositionPlayerY + 1.25) * 120);
						window.draw(Confirm);
						NMove = 1;
						Platform MessageBoxEmpty(&Messagebox, sf::Vector2f(SizeBlock * 3.2, SizeBlock / 1.5), sf::Vector2f(4500, 1060));
						MessageBoxEmpty.Draw(window);

						CODE.setPosition(4320, 1040);
						window.draw(CODE);
						textbox1.setPosition({ 4460 ,1040 });
						CodeMes = 1;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
							NMove = 0;
							CodeMes = 0;
							CodeKeyCard = 0;
							Checkif = 0;
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
						{
							Checkif = 1;
							if (CheckCode == CodePass) {
								CorrectCheck = 1;

							}
						}
						if (Checkif == 1)
						{
							if (CorrectCheck == 1)
							{
								Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.7, SizeBlock), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
								MessageBox0.Draw(window);
								Correct.setPosition((PositionPlayerX - 0.5) * 120, (PositionPlayerY + 1) * 120);
								window.draw(Correct);
								if (times > 2) {
									cl.restart();
								}
								else if (times > 1) {
									NMove = 0;
									CodeMes = 0;
									CodeKeyCard = 0;
									Checkif = 0;
									work = 1;
								}

							}
							else
							{
								if (CorrectCheck == 0) {
									Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.7, SizeBlock), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
									MessageBox0.Draw(window);
									NotCorrect.setPosition((PositionPlayerX - 0.5) * 120, (PositionPlayerY + 1) * 120);
									window.draw(NotCorrect);
								}
							}
						}


					}

				}
				else {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.7, SizeBlock), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Success.setPosition((PositionPlayerX - 0.5) * 120, (PositionPlayerY + 1) * 120);
					window.draw(Success);
				}
					//////////////////// input Code //////////////
				}
				
			}
			else {
				CodeKeyCard = 0;
				CodeMes = 0;
			}


			if (GhostGMes == 0) {
				if (int(PositionPlayerX) == 51 and (int(PositionPlayerY) == 26))
				{
					GhostGMessage1.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						GhostGMes = 1;
					}
				}
				GhostGMessage1.Draw(window);
			}
			
			////////////////////////////// WGhost Atk ///////////////////////
			if (key == 0) {
				for (int i = 0; i < WEnemys1.size(); i++)
				{
					if (CheckDamage == 0)
					{
						if (WEnemys1[i].GetCollider().CheckCollision2(Test))
						{
							if (PlayerHide == 0) {
								CheckDamage = 1;
							}	
						}
					}
					if (CheckDamage == 1) {
						if (GhostATK > 1000)
						{
							PlayerHP -= 1;
							GT.restart();
							break;
						}

					}

				}
			}
			
			////////////////////////////// WGhost Atk ///////////////////////
			////////////////////////////// BGhost Atk ///////////////////////
			if (key == 1) {
				for (int i = 0; i < BEnemys1.size(); i++)
				{
					if (CheckDamage == 0)
					{
						if (BEnemys1[i].GetCollider().CheckCollision2(Test))
						{
							if (PlayerHide == 0) {
								CheckDamage = 1;
							}
						}


					}
					if (CheckDamage == 1) {
						if (GhostATK > 1000)
						{
							PlayerHP -= 3;
							GT.restart();
							break;
						}
					}

				}
			}
			
			////////////////////////////// BGhost Atk ///////////////////////

			
			Object.GetCollider().CheckCollision(Test, 0.8f);
			Object.Draw(window);


			if (int(PositionPlayerX) == 9 and (int(PositionPlayerY) == 24 or int(PositionPlayerY) == 25)) {
				ObjectTree01.Draw(window);
			}
			else {
				ObjectTree1.Draw(window);
			}

			if ((PositionPlayerX >= 25 and PositionPlayerX <= 26) and (PositionPlayerY >= 5.5 and PositionPlayerY <= 6.7))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					key = 1;
					CheckKey = 1;
				}	
				if (CheckKey == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Key1.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1 )*120);
					window.draw(PickedUp);
				}
				
			}
			else {
				if (key == 0) {
					Key1.Draw(window);
				}
				
			}
			if ((PositionPlayerX >= 5.5 and PositionPlayerX <= 7.5) and (PositionPlayerY >= 26.5 and PositionPlayerY <= 28.5))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					hammer = 1;
					CheckHammer = 1;
				}
				if (CheckHammer == 0) {
					Hammer1.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock/1.25 ), sf::Vector2f((PositionPlayerX ) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
				}

			}
			else {
				if (hammer == 0) {
					Hammer1.Draw(window);
				}

			}
			if (barricade1 == 0) {
				if ((int(PositionPlayerX) == 9 or int(PositionPlayerX) == 10) and (PositionPlayerY >= 21 and PositionPlayerY <= 24) and hammer == 1 )
				{
					if ((int(PositionPlayerX) == 9 or int(PositionPlayerX) == 10) and int(PositionPlayerY) == 21)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY -1) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY - 1.1) * 120);
						window.draw(Destroy);
					}
					else if ((int(PositionPlayerX) == 9 or int(PositionPlayerX) == 10) and int(PositionPlayerY) == 23)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
						window.draw(Destroy);
					}
					
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						barricade1 = 1;
					}
					
				}
				else if ((int(PositionPlayerX) == 9 or int(PositionPlayerX) == 10) and int(PositionPlayerY) == 23) 
				{
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(FindHammer);
				}
				else if ((int(PositionPlayerX) == 9 or int(PositionPlayerX) == 10) and int(PositionPlayerY) == 21)
				{
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY -1.1) * 120);
					window.draw(FindHammer);
				}


				Barricade1.Draw(window);
				Barricade1.GetCollider().CheckCollision(Test, 1.0f);
			}
			else {
				BarricadeBroken1.Draw(window);
			}
			if (barricade2 == 0) {
				if (int(PositionPlayerX) == 43 and (PositionPlayerY >= 13 and PositionPlayerY <= 16) and hammer == 1)
				{
					if (int(PositionPlayerX) == 43  and int(PositionPlayerY) == 13)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY - 1.1) * 120);
						window.draw(Destroy);
					}
					else if (int(PositionPlayerX) == 43  and int(PositionPlayerY) == 15)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
						window.draw(Destroy);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						barricade2 = 1;
					}
				}
				else if (int(PositionPlayerX) == 43 and int(PositionPlayerY) == 13) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY - 1.1) * 120);
					window.draw(FindHammer);
				}
				else if (int(PositionPlayerX) == 43 and int(PositionPlayerY) == 15) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(FindHammer);
				}
				Barricade2.Draw(window);
				Barricade2.GetCollider().CheckCollision(Test, 1.0f);
			}
			else {
				BarricadeBroken2.Draw(window);
			}
			if (barricade3 == 0) {
				if (int(PositionPlayerX) == 44 and (PositionPlayerY >= 13 and PositionPlayerY <= 16) and hammer == 1)
				{
					if (int(PositionPlayerX) == 44 and int(PositionPlayerY) == 13)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY - 1.1) * 120);
						window.draw(Destroy);
					}
					else if (int(PositionPlayerX) == 44 and int(PositionPlayerY) == 15)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
						window.draw(Destroy);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						barricade3 = 1;
					}

				}
				else if (int(PositionPlayerX) == 44 and int(PositionPlayerY) == 13) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY - 1.1) * 120);
					window.draw(FindHammer);
				}
				else if (int(PositionPlayerX) == 44 and int(PositionPlayerY) == 15) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(FindHammer);
				}
				
				Barricade3.Draw(window);
				Barricade3.GetCollider().CheckCollision(Test, 1.0f);
			}
			else {
				BarricadeBroken3.Draw(window);
			}

			if (barricade4 == 0) {
				if (int(PositionPlayerX) == 37 and int(PositionPlayerY) == 4 and hammer == 1)
				{
					if (int(PositionPlayerX) == 37 and int(PositionPlayerY) == 4)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1.5) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY - 1.6) * 120);
						window.draw(Destroy);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						barricade4 = 1;
					}

				}
				else if (int(PositionPlayerX) == 37 and int(PositionPlayerY) == 4) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1.5) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY - 1.6) * 120);
					window.draw(FindHammer);
				}
				Barricade4.Draw(window);
				Barricade4.GetCollider().CheckCollision(Test, 1.0f);
			}
			else {
				BarricadeBroken4.Draw(window);
				
			}
			if (barricade5 == 0) {
				if (int(PositionPlayerX) == 37 and int(PositionPlayerY) == 5 and hammer == 1)
				{
					
					if (int(PositionPlayerX) == 37 and int(PositionPlayerY) == 5)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.5) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.35) * 120);
						window.draw(Destroy);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						barricade5 = 1;
					}

				}
				else if (int(PositionPlayerX) == 37 and int(PositionPlayerY) == 5) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.5) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.35) * 120);
					window.draw(FindHammer);
				}

				Barricade5.Draw(window);
				Barricade5.GetCollider().CheckCollision(Test, 1.0f);
			}
			else {	
				BarricadeBroken5.Draw(window);
			}
			if (barricade6 == 0) {
				if (int(PositionPlayerX) == 20 and int(PositionPlayerY) == 16 and hammer == 1)
				{

					if (int(PositionPlayerX) == 20 and int(PositionPlayerY) == 16)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.5) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.35) * 120);
						window.draw(Destroy);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						barricade6 = 1;
					}

				}
				else if (int(PositionPlayerX) == 20 and int(PositionPlayerY) == 16) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.5) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.35) * 120);
					window.draw(FindHammer);
				}

				Barricade6.Draw(window);
				Barricade6.GetCollider().CheckCollision(Test, 1.0f);
			}
			else {
				BarricadeBroken6.Draw(window);
			}
			if (barricade7 == 0) {
				if (int(PositionPlayerX) == 21 and int(PositionPlayerY) == 16 and hammer == 1)
				{

					if (int(PositionPlayerX) == 21 and int(PositionPlayerY) == 16)
					{
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.5) * 120));
						MessageBox0.Draw(window);
						Destroy.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.35) * 120);
						window.draw(Destroy);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						barricade7 = 1;
					}

				}
				else if (int(PositionPlayerX) == 21 and int(PositionPlayerY) == 16) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.5) * 120));
					MessageBox0.Draw(window);
					FindHammer.setPosition((PositionPlayerX - 0.9) * 120, (PositionPlayerY + 1.35) * 120);
					window.draw(FindHammer);
				}

				Barricade7.Draw(window);
				Barricade7.GetCollider().CheckCollision(Test, 1.0f);
			}
			else {
				BarricadeBroken7.Draw(window);
			}

			/////////////////////////// Ghost Grren /////////////////////////////////////////

			if (int(PositionPlayerX) == 47 and (PositionPlayerY >= 7 and PositionPlayerY <= 8) and doll == 1 )
			{
				if (CheckGoshtG1 == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Talk.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Talk);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) and (times >= 0.5)) {
					if (CheckGoshtG1 == 0)
					{
						CheckGoshtG1++;
						cl.restart();
					}
				}
				if (CheckGoshtG1 == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and (times >= 0.5)) {
						GhostState1++;
						cl.restart();
					}
				}
				MSCheck = 1;
				
			}
			else if (int(PositionPlayerX) == 47 and (PositionPlayerY >= 7 and PositionPlayerY <= 8)) {
			
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) and (times >= 0.5))
				{
					if (CheckGoshtG == 0) {
						CheckGoshtG++;
						cl.restart();
					}
					
				}
				if (CheckGoshtG == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Talk.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Talk);
				}
				if (CheckGoshtG) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and (times >= 0.5)) {
						GhostState++;
						cl.restart();
					}
				}
				MSCheck = 1;
				
			}
			else if (CheckGoshtG1 != 2){
				MSCheck = 0;
				CheckGoshtG = 0;
				GhostState = 0;
				CheckGoshtG1 = 0;
				GhostState1 = 0;			
			}

			if (Gdoll == 0) {
				for (Enemy& E : GEnemys1) E.Update(deltaTime);
				for (Enemy& E : GEnemys1) E.Draw(window);
				GEnemyBlock1.GetCollider().CheckCollision(Test, 1.0f);
			}

			/////////////////////////// Ghost Grren /////////////////////////////////////////

			if (int((PositionPlayerX) == 16 or (PositionPlayerX >= 15.5 and PositionPlayerX <= 17.0 )) and ((PositionPlayerY >= 3.5 and PositionPlayerY <= 6.2) or (PositionPlayerY == 4 )) and keycard == 0)
			{
				Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
				MessageBox0.Draw(window);
				PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
				window.draw(PickedUp);
				Keycard1.Draw(window);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					keycard = 1;
				}
			}
			else if (keycard == 0) {
				Keycard1.Draw(window);
			}	
			if (key == 0) {
				for (Enemy& E : WEnemys1) E.Update(deltaTime);
				for (Enemy& E : WEnemys1) E.Draw(window);
			}

			if (key == 1) {
				for (Enemy& B : BEnemys1) B.Update(deltaTime);
				for (Enemy& B : BEnemys1) B.Draw(window);
			}

		}

		////////////////////////////////////////////////////// MAP 2 /////////////////////////////////////////////////////////////////////////////////

		if (State == 1) {
			for (int mapX = 0; mapX < 58; mapX++)
			{
				for (int mapY = 0; mapY < 41; mapY++)
				{
					if (map2[mapY][mapX] == 0)
					{
						Map1 temp(nullptr, Vector2f(((mapX) * 120) + 60, ((mapY) * 120) + 60), Vector2f(SizeBlock, SizeBlock));
						Block1.push_back(temp);
					}
				}
			}
			player.SetPosition(sf::Vector2f(2340.0f, 1500.0f));
			State = -1;
			Teleport = 1;
		}
		
		if (Teleport == 1) 
		{

			for (Map1& m : Block1) m.draw(window);
			for (int i = 0; i < Block1.size(); i++)
			{
				if (Cheatcollision == 0) {
					Block1[i].GetCollider().CheckCollision(Test, 1.0f);
				}
			}
			Map02Texture.Draw(window);
			///////////////////////////////////// HP + SP Spawn /////////////////////////////////////////
			if ((int(PositionPlayerX) == 9 or int(PositionPlayerX) == 8) and (int(PositionPlayerY) == 5 or int(PositionPlayerY) == 6)) {
				if (CheckHP1_2F == 0) {
					HP1_2F.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP1_2F = 1;
						BottleHP++;
					}
				}
			}
			else
			{
				if (CheckHP1_2F == 0)
				{
					HP1_2F.Draw(window);
				}

			}
			if ((int(PositionPlayerX) == 25 or int(PositionPlayerX) == 26) and (int(PositionPlayerY) == 35 or int(PositionPlayerY) == 36)) {
				if (CheckHP2_2F == 0) {
					HP2_2F.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP2_2F = 1;
						BottleHP++;
					}
				}
			}
			else
			{
				if (CheckHP2_2F == 0)
				{
					HP2_2F.Draw(window);
				}

			}
			if ((int(PositionPlayerX) == 50 or int(PositionPlayerX) == 49) and (int(PositionPlayerY) == 27 or int(PositionPlayerY) == 26)) {
				if (CheckHP3_2F == 0) {
					HP3_2F.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckHP3_2F = 1;
						BottleHP++;
					}
				}
			}
			else
			{
				if (CheckHP3_2F == 0)
				{
					HP3_2F.Draw(window);
				}

			}

			if ((int(PositionPlayerX) == 31 or int(PositionPlayerX) == 32) and (int(PositionPlayerY) == 35 or int(PositionPlayerY) == 34)) {
				if (CheckSP1_2F == 0) {
					SP1_2F.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckSP1_2F = 1;
						BottleSP++;
					}
				}
			}
			else
			{
				if (CheckSP1_2F == 0)
				{
					SP1_2F.Draw(window);
				}
			}
			if (int(PositionPlayerX) == 49  and (int(PositionPlayerY) == 19 or int(PositionPlayerY) == 18)) {
				if (CheckSP2_2F == 0) {
					SP2_2F.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckSP2_2F = 1;
						BottleSP++;
					}
				}
			}
			else
			{
				if (CheckSP2_2F == 0)
				{
					SP2_2F.Draw(window);
				}
			}
			if ((int(PositionPlayerX) == 8 or int(PositionPlayerX) == 7) and (int(PositionPlayerY) == 32 or int(PositionPlayerY) == 33)) {
				if (CheckSP3_2F == 0) {
					SP3_2F.Draw(window);
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(PickedUp);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						CheckSP3_2F = 1;
						BottleSP++;
					}
				}
			}
			else
			{
				if (CheckSP3_2F == 0)
				{
					SP3_2F.Draw(window);
				}
			}


			//////////////////////////////////////////// Hide2F /////////////////////////////////////////
			if (((int(PositionPlayerX) == 3 and int(PositionPlayerY) == 4)) or (int(PositionPlayerX) == 5 and int(PositionPlayerY) == 25) or (int(PositionPlayerX) == 9 and int(PositionPlayerY) == 26) or (int(PositionPlayerX) == 22 and int(PositionPlayerY) == 17) or (int(PositionPlayerX) == 33 and int(PositionPlayerY) == 17) or (int(PositionPlayerX) == 31 and int(PositionPlayerY) == 33) or (int(PositionPlayerX) == 51 and int(PositionPlayerY) == 5) or (int(PositionPlayerX) == 49 and int(PositionPlayerY) == 24) or (int(PositionPlayerX) == 40 and int(PositionPlayerY) == 5))
			{
				if (PlayerHide == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Hide.setPosition((PositionPlayerX - 0.7) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Hide);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						PlayerHide = 1;
					}
				}
				if (PlayerHide == 1) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.0, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					GetOut.setPosition((PositionPlayerX - 1.0) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(GetOut);
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

						PlayerHide = 0;
					}
				}
			}
			//////////////////////////////////////////// Hide2F /////////////////////////////////////////
			
			//////////////////////////////////////////// Find Book2F //////////////////////////////////////


			if (((int(PositionPlayerX) == 4 and int(PositionPlayerY) == 25)) or (int(PositionPlayerX) == 11 and int(PositionPlayerY) == 26) or (int(PositionPlayerX) == 30 and int(PositionPlayerY) == 26) or (int(PositionPlayerX) == 34 and int(PositionPlayerY) == 11) or (int(PositionPlayerX) == 36 and int(PositionPlayerY) == 17) or (int(PositionPlayerX) == 41 and int(PositionPlayerY) == 5) or (int(PositionPlayerX) == 50 and int(PositionPlayerY) == 24)) 
			{
				if (CheckFind == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 4.0, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Find.setPosition((PositionPlayerX - 1.0) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Find);
				}
				
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
					CheckFind = 1;
					
				}
				if (CheckFind == 1) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120 -20 , (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					NotFind.setPosition((PositionPlayerX - 1.0) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(NotFind);
					if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
						CheckFind = 0;
						
					}
				}
				if (BookHP == 0)
				{
					if ((int(PositionPlayerX) == 11 and int(PositionPlayerY) == 26)) {
						if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
							BookHP = 1;
							BottleHP++;
							NMove = 1;
						}
					}
				}
				if (BookHP1 == 0)
				{
					if ((int(PositionPlayerX) == 34 and int(PositionPlayerY) == 11)) {
						if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
							BookHP1 = 1;
							BottleHP++;
							NMove = 1;
						}
					}
				}
				if (BookHP2 == 0)
				{
					if ((int(PositionPlayerX) == 41 and int(PositionPlayerY) == 5)) {
						if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
							BookHP2 = 1;
							BottleHP++;
							NMove = 1;
						}
					}
				}
				if (FindBook == 0) 
				{
					if ((int(PositionPlayerX) == 50 and int(PositionPlayerY) == 24)) {
						if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
							FindBook = 1;
							NMove = 1;
						}
					}
				}		
			}
			else 
			{
				CheckFind = 0;
			}
			


			//////////////////////////////////////////// Find Book //////////////////////////////////////

			////////////////////////////// WGhost Atk ///////////////////////
			if (key == 0) 
			{
				for (int i = 0; i < WEnemys2.size(); i++)
				{
					if (CheckDamage == 0)
					{
						if (WEnemys2[i].GetCollider().CheckCollision2(Test))
						{
							if (PlayerHide == 0) {
								CheckDamage = 1;
							}
						}
					}
					if (CheckDamage == 1) {
						if (GhostATK > 1000)
						{
							PlayerHP -= 1;
							GT.restart();
							break;
						}

					}

				}
			}

			////////////////////////////// WGhost Atk ///////////////////////
			////////////////////////////// BGhost Atk ///////////////////////
			if (key == 1) {
				for (int i = 0; i < BEnemys2.size(); i++)
				{
					if (CheckDamage == 0)
					{
						if (BEnemys2[i].GetCollider().CheckCollision2(Test))
						{

							CheckDamage = 1;

						}
					}
					if (CheckDamage == 1) {
						if (GhostATK > 1000)
						{
							PlayerHP -= 3;
							GT.restart();
							break;
						}
					}

				}
			}

			////////////////////////////// BGhost Atk ///////////////////////

			if (DollRandom == 1) 
			{
				if ((PositionPlayerX >= 14.1 and PositionPlayerX <= 15.5) and (PositionPlayerY >= 37.5 and PositionPlayerY <= 39.5))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
					{
						doll = 1;
						CheckDoll = 1;
					}
					if (CheckDoll == 0) {
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
						MessageBox0.Draw(window);
						Doll1.Draw(window);
						PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
						window.draw(PickedUp);
					}

				}
				else if (doll == 0)
				{
					Doll1.Draw(window);
				}
			}
			else if (DollRandom == 2) 
			{
				if ((PositionPlayerX >= 4.5 and PositionPlayerX <= 5.7) and (PositionPlayerY >= 4.3 and PositionPlayerY <= 5.5))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
					{
						doll = 1;
						CheckDoll = 1;
					}
					if (CheckDoll == 0) {
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
						MessageBox0.Draw(window);
						Doll2.Draw(window);
						PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
						window.draw(PickedUp);
					}

				}
				else if (doll == 0)
				{
					Doll2.Draw(window);
				}
			}
			else if (DollRandom == 3)
			{
				if ((PositionPlayerX >= 46.5 and PositionPlayerX <= 48) and (PositionPlayerY >= 17.5 and PositionPlayerY <= 19.0))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
					{
						doll = 1;
						CheckDoll = 1;
					}
					if (CheckDoll == 0) {
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY -1.3) * 120));
						MessageBox0.Draw(window);
						Doll3.Draw(window);
						PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY -1.4) * 120);
						window.draw(PickedUp);
					}

				}
				else if (doll == 0)
				{
					Doll3.Draw(window);
				}
			}
			else if (DollRandom == 4)
			{
				if ((PositionPlayerX >= 43.0 and PositionPlayerX <= 44.5) and (PositionPlayerY >= 26.5 and PositionPlayerY <= 28.0))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
					{
						doll = 1;
						CheckDoll = 1;
					}
					if (CheckDoll == 0) {
						Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY - 1.3) * 120));
						MessageBox0.Draw(window);
						Doll4.Draw(window);
						PickedUp.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY - 1.4) * 120);
						window.draw(PickedUp);
					}

				}
				else if (doll == 0)
				{
					Doll4.Draw(window);
				}
			}

			///////////////////////////////// Ghost Green 2 Floor /////////////////////////////////////////////

			if (int(PositionPlayerX) == 35 and int(PositionPlayerY) == 27 and FindBook == 1)
			{
				if (CheckGoshtG12 == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Talk.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Talk);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) and (times >= 0.5)) {
					if (CheckGoshtG12 == 0)
					{
						CheckGoshtG12++;
						cl.restart();
					}
				}
				if (CheckGoshtG12 == 1) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and (times >= 0.5)) {
						GhostState12++;
						cl.restart();
					}
				}
				MSCheck2 = 1;

			}
			else if (int(PositionPlayerX) == 35 and int(PositionPlayerY) == 27) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) and (times >= 0.5))
				{
					if (CheckGoshtG2 == 0) {
						CheckGoshtG2++;
						cl.restart();
					}

				}
				if (CheckGoshtG2 == 0) {
					Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
					MessageBox0.Draw(window);
					Talk.setPosition((PositionPlayerX - 0.8) * 120, (PositionPlayerY + 1.1) * 120);
					window.draw(Talk);
				}
				if (CheckGoshtG2) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and (times >= 0.5)) {
						GhostState2++;
						cl.restart();
					}
				}
				MSCheck2 = 1;

			}
			else if (CheckGoshtG12 != 2) {
				MSCheck2 = 0;
				CheckGoshtG2 = 0;
				GhostState2 = 0;
				CheckGoshtG12 = 0;
				GhostState12 = 0;

			
			}

			if (Gbook == 0) {
				for (Enemy& E2F : GEnemys2) E2F.Update(deltaTime);
				for (Enemy& E2F : GEnemys2) E2F.Draw(window);
				GEnemyBlock2.GetCollider().CheckCollision(Test, 1.0f);
			}
			///////////////////////////////// Ghost Green 2 Floor /////////////////////////////////////////////

			if (key == 0) {
				for (Enemy& E2 : WEnemys2) E2.Update(deltaTime);
				for (Enemy& E2 : WEnemys2) E2.Draw(window);
			}

			if (key == 1) {
				for (Enemy& B2 : BEnemys2) B2.Update(deltaTime);
				for (Enemy& B2 : BEnemys2) B2.Draw(window);
			}
		}

		/*if (PlayerHP <= 0) {
			State = 2;
		}
		if (State == 0) {

		}*/

		if (CheatLight == 0) {
			Light1.Draw(window);
		}
		


		PotionHP.Draw(window);
		PotionSP.Draw(window);

		Stamina_Texture.Draw(window);
		Stamina_Texture1.Draw(window);
		if (BottleHP == 10) {
			window.draw(PotionHP10);
		}
		else if (BottleHP == 9) {
			window.draw(PotionHP9);
		}
		else if (BottleHP == 8) {
			window.draw(PotionHP8);
		}
		else if (BottleHP == 7) {
			window.draw(PotionHP7);
		}
		else if (BottleHP == 6) {
			window.draw(PotionHP6);
		}
		else if (BottleHP == 5) {
			window.draw(PotionHP5);
		}
		else if (BottleHP == 4) {
			window.draw(PotionHP4);
		}
		else if (BottleHP == 3) {
			window.draw(PotionHP3);
		}
		else if (BottleHP == 2) {
			window.draw(PotionHP2);
		}
		else if (BottleHP == 1) {
			window.draw(PotionHP1);
		}
		else if (BottleHP == 0) {
			window.draw(PotionHP0);
		}

		if (BottleSP == 10) {
			window.draw(PotionSP10);
		}
		else if (BottleSP == 9) {
			window.draw(PotionSP9);
		}
		else if (BottleSP == 8) {
			window.draw(PotionSP8);
		}
		else if (BottleSP == 7) {
			window.draw(PotionSP7);
		}
		else if (BottleSP == 6) {
			window.draw(PotionSP6);
		}
		else if (BottleSP == 5) {
			window.draw(PotionSP5);
		}
		else if (BottleSP == 4) {
			window.draw(PotionSP4);
		}
		else if (BottleSP == 3) {
			window.draw(PotionSP3);
		}
		else if (BottleSP == 2) {
			window.draw(PotionSP2);
		}
		else if (BottleSP == 1) {
			window.draw(PotionSP1);
		}
		else if (BottleSP == 0) {
			window.draw(PotionSP0);
		}



		if (PlayerHP == 3) {
			PlayerHeart31.Draw(window);
		}
		else if (PlayerHP == 2) {
			PlayerHeart21.Draw(window);
		}
		else if (PlayerHP == 1) {
			PlayerHeart11.Draw(window);
		}
		else if (PlayerHP <= 0) {
			PlayerHeart01.Draw(window);
		}
		////////////////////////////////////// Ghost Green 1 Floor ////////////////////////////
		if (MSCheck == 1)
		{
			if (CheckGoshtG == 1) {
				MessageBox0.Draw(window);
				MessageBoxGhost.Draw(window);
			}
			if (GhostState == 1) {
				window.draw(PlayerTalkGhostG);
			}
			else if (GhostState == 2) {
				window.draw(DollG1);
				window.draw(DollG11);
			}
			else if (GhostState == 3) {
				window.draw(Okay);
			}
			else if (GhostState == 4) {
				window.draw(DollG2);
				window.draw(DollG22);
			}
			else if (GhostState == 5) {
				window.draw(PlayerTalkGhostG2);
			}
			else if (GhostState == 6) {
				CheckGoshtG = 0;
				GhostState = 0;
				MSCheck = 0;
			}
			//////////////////////////// Have Doll //////////////////
			if (CheckGoshtG1 == 1) {
				MessageBox0.Draw(window);
				MessageBoxGhost.Draw(window);
			}
			if (GhostState1 == 1) {
				window.draw(PlayerTalkGhostG3);
			}
			else if (GhostState1 == 2) {
				window.draw(DollG3);
			}
			else if (GhostState1 == 3) {
				window.draw(Thankyou);
			}
			else if (GhostState1 == 4) {
				
				Gbook = 1;
				MSCheck = 2;
				CheckGoshtG1++;
				GhostState1++;
				Gdoll = 1;
			}
		}
		////////////////////////////////////// Ghost Green 1 Floor ////////////////////////////
		////////////////////////////////////// Ghost Green 2 Floor ////////////////////////////
		if (MSCheck2 == 1)
		{
			if (CheckGoshtG2 == 1) {
				MessageBox0.Draw(window);
				MessageBoxGhost2.Draw(window);
			}
			if (GhostState2 == 1) {
				window.draw(PlayerTalkGhostG);
			}
			else if (GhostState2 == 2) {
				window.draw(BookG1);
				window.draw(BookG11);
			}
			else if (GhostState2 == 3) {
				window.draw(Okay);
			}
			else if (GhostState2 == 4) {
				window.draw(BookG2);
				window.draw(BookG22);
			}
			else if (GhostState2 == 5) {
				window.draw(PlayerTalkGhostG2);
			}
			else if (GhostState2 == 6) {
				CheckGoshtG2 = 0;
				GhostState2 = 0;
				MSCheck2 = 0;
			}
			/////////////////////////// Have Book ///////////////////////////////
			if (CheckGoshtG12 == 1) {
				MessageBox0.Draw(window);
				MessageBoxGhost2.Draw(window);
			}
			if (GhostState12 == 1) {
				window.draw(PlayerTalkGhostG32F);
			}
			else if (GhostState12 == 2) {
				window.draw(BookG3);
			}
			else if (GhostState12 == 3) {
				window.draw(Thankyou);
			}
			else if (GhostState12 == 4) {

				FindBook = 1;
				MSCheck2 = 2;
				CheckGoshtG12++;
				GhostState12++;
				Gbook = 1;
			}
		}
		////////////////////////////////////// Ghost Green 2 Floor ////////////////////////////
		/////////////////////////// Player CheckDamage ////////////////////////////////////////
		if (CheckDamage == 0)
		{
			if (PlayerHide == 0) {
				player.Draw(window);
			}
			
		}
		else if (CheckDamage == 1)
		{
			if (GhostATK < 950) {
				if (TimeDamage > 100)
				{
					player.Draw(window);

				}
				if (TimeDamage > 200)DamageClock.restart();
			}
			else if (GhostATK >= 950) {
				CheckDamage = 0;
			}
		}
		/////////////////////////// Player CheckDamage ////////////////////////////////////////

		///////////////////////////////////// แสดงกระดาษข้อความ GhostGreen 2 Floor /////////////////////////////////////
		if (GhostGMes == 1) {
			Platform GhostGMessage2(&GhostGMessage, sf::Vector2f(SizeBlock * 8.2, SizeBlock * 7.7), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			GhostGMessage2.Draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				GhostGMes = 0;
			}
		}
		///////////////////////////////////// แสดงกระดาษข้อความ GhostGreen 2 Floor /////////////////////////////////////

		if (FindBook == 1 and CheckBook == 0) {
			Platform Book1(&Book, sf::Vector2f(SizeBlock * 6.5, SizeBlock * 6.5), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			Book1.Draw(window);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
				CheckBook = 1;
				NMove = 0;
			}
		}
		if (BookHP == 1 and CheckBookHP == 0) {
			Platform BookHP1(&BoxHPTexture, sf::Vector2f(SizeBlock * 4, SizeBlock * 4), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			BookHP1.Draw(window);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
				CheckBookHP = 1;
				NMove = 0;
			}
		}
		if (BookHP1 == 1 and CheckBookHP1 == 0) {
			Platform BookHP2(&BoxHPTexture, sf::Vector2f(SizeBlock * 4, SizeBlock * 4), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			BookHP2.Draw(window);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
				CheckBookHP1 = 1;
				NMove = 0;
			}
		}
		if (BookHP2 == 1 and CheckBookHP2 == 0) {
			Platform BookHP3(&BoxHPTexture, sf::Vector2f(SizeBlock * 4, SizeBlock * 4), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			BookHP3.Draw(window);
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
				CheckBookHP2 = 1;
				NMove = 0;
			}
		}
		if ((int(PositionPlayerX) == 36 or int(PositionPlayerX) == 37 or int(PositionPlayerX) == 38) and int(PositionPlayerY) == 22) {
			if (Code == 0) {
				Platform MessageBox0(&MainMessageBox, sf::Vector2f(SizeBlock * 3.5, SizeBlock / 1.25), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY + 1.2) * 120));
				MessageBox0.Draw(window);
				Read.setPosition((PositionPlayerX - 0.5) * 120, (PositionPlayerY + 1.1) * 120);
				window.draw(Read);
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))) {
					Code = 1;
				}
			}
			
			if (Code == 1) {
				Platform Codeborad1(&Codeborad, sf::Vector2f(SizeBlock * 6.5, SizeBlock * 6.5), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
				Codeborad1.Draw(window);
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
					Code = 0;
				}
			}
		}
		else {
			Code = 0;
		}
		
		if (CodeKeyCard == 1 and work == 0) {
			textbox1.drawTo(window);
		}
		if (MiniMap1 == 1) {
			Platform MiniMap01(&MiniMap1F1, sf::Vector2f(SizeBlock * 9, SizeBlock * 7), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			MiniMap01.Draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				MiniMap1 = 0;
			}
		}
		if (MiniMap2 == 1) {
			Platform MiniMap02(&MiniMap1F2, sf::Vector2f(SizeBlock * 9, SizeBlock * 7), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			MiniMap02.Draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				MiniMap2 = 0;
			}
		}
		if (MiniMap3 == 1) {
			Platform MiniMap03(&MiniMap1F3, sf::Vector2f(SizeBlock * 9, SizeBlock * 7), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			MiniMap03.Draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				MiniMap3 = 0;
			}
		}
		if (CheckHintTree == 1) {
			Platform HintTree1(&HintTree, sf::Vector2f(SizeBlock * 7, SizeBlock * 5), sf::Vector2f((PositionPlayerX) * 120, (PositionPlayerY) * 120));
			HintTree1.Draw(window);
		}


	}
		//////////////////////////////////////////////////////////// Game Game Game Game Game Game Game Game Game ////////////////////////////////////////////////////
		//printf("%.1f   %.1f\n", PositionPlayerX, PositionPlayerY);
		//printf("%d %d \n",CheckDamage,PlayerHP);
		//printf("%d  %d\n",BottleHP, BottleSP);
		//printf("%d\n",CodeMes);
		
		//printf("%d", CodeKeyCard);
		//std::cout << Checkif <<std::endl;

		////////////////////////////////////////////// Manu ////////////////////////////////////////////////
		
		printf("%d", State);
		printf("%d", HTP);
		window.display();
	}
	return 0;
	
}