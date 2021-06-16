#include"WarSystem.h"
#include"MyDraw.h"

int main() {
	system("mode con cols=120 lines=50  ");
	WarSystem game1;
	system("cls");
	MyDraw::drawMain(game1._PGroupA, game1._pGroupB);
	game1.startWar(game1._PGroupA, game1._pGroupB);
	system("pause");

	return 0;
}