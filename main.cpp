#include "DxLib.h"
#include "Scene.h"
#include "SceneStart.h"
#include "SceneTest.h"


int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int ) {
	ChangeWindowMode( true );
	SetGraphMode(800, 800, 32);
	DxLib_Init();
	SetDrawScreen( DX_SCREEN_BACK );

	Scene* scene( new SceneTest() );
	do {

		scene->run( );
		Scene* next = scene->getNext( );
		delete scene;
		scene = next;

	} while (scene != nullptr );

	delete scene;



	DxLib_End();

}

/*  デバック便利

_RPT0(int rptno, char const* msg)
_RPTN(int rptno, char const* msg, ...)

_RPTN(_CRT_WARN, "deleting %Xh\n", org.m_Data[i]);;

*/