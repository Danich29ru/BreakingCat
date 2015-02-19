#include"ui.h"
#include"common.h"

#define UI_BUTTON_WIDTH 100
#define UI_BUTTON_HEIGHT 30

Texture g_ButtonNormal;
Texture g_ButtonMouseOver;

unsigned char g_HelpMsg_OKButton_State = 0;

unsigned char g_ButtonTexture[] = { 0xFF, };

void bcInitializeGameUI()
{
	g_ButtonNormal = bcCreateTexture();
	bcTCBMConvertToTexture(g_ButtonTexture, g_ButtonNormal, 1, 1, 0x00550000, 0x000000FF);
	g_ButtonMouseOver = bcCreateTexture();
	bcTCBMConvertToTexture(g_ButtonTexture, g_ButtonMouseOver, 1, 1, 0x00AA0000, 0x000000FF);
}


void bcShutdownGameUI()
{
	bcDeleteTexture(&g_ButtonNormal);
	bcDeleteTexture(&g_ButtonMouseOver);
}


void bcDrawParameters()
{
	bcRect textRect;
	wchar_t temp[20];
	unsigned int money = g_Game_Money > 10000 ? g_Game_Money / 1000 : g_Game_Money;

	textRect._left = WINDOW_WIDTH - 195;
	textRect._top = 5;
	textRect._right = WINDOW_WIDTH;
	textRect._bottom = WINDOW_HEIGHT;

	bcSetAdditionalPixels(1);

	bcDrawText(g_WhiteFont, L"Купилки      -", 1, textRect);
	if (money == g_Game_Money)
		wsprintf(temp, L"%d р", g_Game_Money);
	else
		wsprintf(temp, L"%dК р", money);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Опыт         -", 1, textRect);
	wsprintf(temp, L"%d ХП", g_Game_Experience);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Валериана    -", 1, textRect);
	wsprintf(temp, L"%d КГ", g_Game_RawMaterials_V);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Кошачья Мята -", 1, textRect);
	wsprintf(temp, L"%d КГ", g_Game_RawMaterials_N);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Настойка     -", 1, textRect);
	wsprintf(temp, L"%d Л", g_Game_Product_1);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Химка        -", 1, textRect);
	wsprintf(temp, L"%d КГ", g_Game_Product_2);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Химики       -", 1, textRect);
	wsprintf(temp, L"%d Чел.", g_Game_Chemists);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Фермеры      -", 1, textRect);
	wsprintf(temp, L"%d Чел.", g_Game_Farmers);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Торчки       -", 1, textRect);
	wsprintf(temp, L"%d Чел.", g_Game_Addicts);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	textRect._top += 17;
	bcDrawText(g_WhiteFont, L"Барыги       -", 1, textRect);
	wsprintf(temp, L"%d Чел.", g_Game_Hucksters);
	textRect._left += 130;
	bcDrawText(g_WhiteFont, temp, 1, textRect);
	textRect._left -= 130;

	bcSetAdditionalPixels(0);
}


void bcDrawButtons()
{
	bcRect textRect;

	//New laboratory
	bcDrawTexture(g_MapTextures[BC_MAP_LAB], WINDOW_WIDTH - 185, 200, 64, 64);

	textRect._left = WINDOW_WIDTH - 140;
	textRect._top = 235;
	textRect._right = WINDOW_WIDTH;
	textRect._bottom = WINDOW_HEIGHT;
	bcDrawText(g_YellowFont, L"+", 4, textRect);

	//new farm
	bcDrawTexture(g_MapTextures[BC_MAP_LAB], WINDOW_WIDTH - 95, 200, 64, 64);

	textRect._left = WINDOW_WIDTH - 50;
	textRect._top = 235;
	textRect._right = WINDOW_WIDTH;
	textRect._bottom = WINDOW_HEIGHT;
	bcDrawText(g_YellowFont, L"+", 4, textRect);

	//new chemist
	bcDrawTexture(g_MapTextures[BC_MAP_LAB], WINDOW_WIDTH - 185, 285, 64, 64);

	textRect._left = WINDOW_WIDTH - 140;
	textRect._top = 320;
	textRect._right = WINDOW_WIDTH;
	textRect._bottom = WINDOW_HEIGHT;
	bcDrawText(g_YellowFont, L"+", 4, textRect);

	//new farmer
	bcDrawTexture(g_MapTextures[BC_MAP_LAB], WINDOW_WIDTH - 95, 285, 64, 64);

	textRect._left = WINDOW_WIDTH - 50;
	textRect._top = 320;
	textRect._right = WINDOW_WIDTH;
	textRect._bottom = WINDOW_HEIGHT;
	bcDrawText(g_YellowFont, L"+", 4, textRect);
}


void bcDrawGameUI()
{
	bcDrawParameters();
	bcDrawButtons();
}


void bcDrawHelpMessage()
{
	wchar_t message1[] = L"Ф1 в режиме игры - открыть данную справку";
	wchar_t message2[] = L"Ф2 - Включить отображение кадров в секунду";
	wchar_t message3[] = L"1. Стройте фермы растительного сырья - ";
	wchar_t message4[] = L"2. Стройте химические лаборатории - ";
	wchar_t message5[] = L"3. Нанимайте дополнительных работников(химики, фермеры) - ";
	wchar_t message6[] = L"4. Продавайте настойку валерианы и химку из котовника - ";
	wchar_t message7[] = L"5. Расширяйте производство, станьте кошачьим Хайзенбергом";
	wchar_t message8[] = L"6. ???";
	wchar_t message9[] = L"7. ПРОФИТ!!!";

	bcRect buttonRect;
	buttonRect._top = WINDOW_HEIGHT / 2 - UI_BUTTON_HEIGHT / 2 + 150;
	buttonRect._left = WINDOW_WIDTH / 2 - UI_BUTTON_WIDTH / 2;
	buttonRect._bottom = WINDOW_HEIGHT / 2 + UI_BUTTON_HEIGHT / 2 + 150;
	buttonRect._right = WINDOW_WIDTH / 2 + UI_BUTTON_WIDTH / 2;

	bcRect textRect;
	textRect._left = 105;
	textRect._right = 600;
	textRect._top = 110;
	textRect._bottom = 400;

	bcDrawTexture(g_MapTextures[BC_MAP_BACKGROUND], 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	bcDrawTexture(g_MapTextures[BC_MAP_CELL_BACKGROUND], 100, 100, 600, 400);

	bcDrawText(g_WhiteFont, message1, 1, textRect);
	textRect._top += 10;
	bcDrawText(g_WhiteFont, message2, 1, textRect);
	textRect._top += 30;
	bcDrawText(g_WhiteFont, message3, 1, textRect);
	textRect._top += 30;
	bcDrawText(g_WhiteFont, message4, 1, textRect);
	textRect._top += 30;
	bcDrawText(g_WhiteFont, message5, 1, textRect);
	textRect._top += 30;
	bcDrawText(g_WhiteFont, message6, 1, textRect);
	textRect._top += 30;
	bcDrawText(g_WhiteFont, message7, 1, textRect);
	textRect._top += 12;
	bcDrawText(g_WhiteFont, message8, 1, textRect);
	textRect._top += 12;
	bcDrawText(g_WhiteFont, message9, 1, textRect);

	bcDrawTexture(g_MapTextures[BC_MAP_LAB], 415, 135, 30, 30);

	bcDrawTexture(g_MapTextures[BC_MAP_LAB], 390, 167, 30, 30);

	bcDrawTexture(g_MapTextures[BC_MAP_LAB], 575, 195, 30, 30);
	bcDrawTexture(g_MapTextures[BC_MAP_LAB], 610, 195, 30, 30);

	bcDrawTexture(g_MapTextures[BC_MAP_LAB], 560, 227, 30, 30);

	if (g_HelpMsg_OKButton_State == 0)
	{
		bcDrawTexture(g_ButtonNormal, buttonRect._left, buttonRect._top, buttonRect._right - buttonRect._left, buttonRect._bottom - buttonRect._top);
	}
	else
	{
		bcDrawTexture(g_ButtonMouseOver, buttonRect._left, buttonRect._top, buttonRect._right - buttonRect._left, buttonRect._bottom - buttonRect._top);
	}

	textRect._left = WINDOW_WIDTH / 2 - UI_BUTTON_WIDTH / 2 + 46;
	textRect._top = WINDOW_HEIGHT / 2 - UI_BUTTON_HEIGHT / 2 + 161;
	bcDrawText(g_WhiteFont, L"ок", 1, textRect);
}


void bcDrawLogo()
{
	bcRect textRect;
	textRect._left = 20;
	textRect._right = 10000;
	textRect._top = 20;
	textRect._bottom = 400;
	bcDrawTexture(g_MapTextures[BC_MAP_BACKGROUND], 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	textRect._left = 200;
	textRect._right = 10000;
	textRect._top = 20;
	textRect._bottom = 400;
	bcDrawText(g_YellowFont, L"Для конкурса 96к игр", 2, textRect);
	textRect._left = 20;
	textRect._right = 10000;
	textRect._top = 50;
	textRect._bottom = 400;
	bcDrawText(g_WhiteFont, L"К О Т И К И - Н А Р К О Т И К И", 3, textRect);
	textRect._left = 20;
	textRect._right = 10000;
	textRect._top = 100;
	textRect._bottom = 400;
	bcDrawText(g_YellowFont, L"Наркотики - зло! Лучше купи вискаса коту из подвала, вместо травушки, порошка или колес!", 1, textRect);
	textRect._left = 200;
	textRect._right = 10000;
	textRect._top = 115;
	textRect._bottom = 400;
	bcDrawText(g_WhiteFont, L"И кот скажет тебе спасибо.", 2, textRect);

	bcDrawTexture(g_MapTextures[BC_MAP_LAB], 220, 200, 350, 350);
}


void bcGameUIUpdate()
{

}


void bcHelpMsgUpdate()
{
	long mouseX = 0, mouseY = 0;

	bcRect buttonRect;
	buttonRect._top = WINDOW_HEIGHT / 2 - UI_BUTTON_HEIGHT / 2 + 150;
	buttonRect._left = WINDOW_WIDTH / 2 - UI_BUTTON_WIDTH / 2;
	buttonRect._bottom = buttonRect._top - UI_BUTTON_HEIGHT;
	buttonRect._right = buttonRect._left + UI_BUTTON_WIDTH;

	bcGetMousePos(&mouseX, &mouseY);

	if (buttonRect._top >= mouseY && buttonRect._bottom <= mouseY && buttonRect._left <= mouseX && buttonRect._right >= mouseX)
	{
			g_HelpMsg_OKButton_State = 1;

			if (GetAsyncKeyState(VK_LBUTTON) < 0)
			{
				g_GameState = BC_GAME;
			}
	}
	else
	{
		g_HelpMsg_OKButton_State = 0;
	}
}