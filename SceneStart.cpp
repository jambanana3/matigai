#include "SceneStart.h"
#include "Mouse.h"


SceneStart::SceneStart(){
	setNext( nullptr );
}

SceneStart::~SceneStart( ) {

}

//\------ ������̂������牺 (   void Scene,,,::run( ) �̂Ȃ�  ) ---------//

void SceneStart::run( ) {

	TouchPoint* Buttan_End(new TouchPoint( 90, 90 ) );
	Buttan_End->setPos(10, 10);
	Mouse* mousePtr( new Mouse() );

	while ( true ) {//  ---------�@���ꃁ�C�����[�v�@�|�|�|�|�E�E
		mousePtr->update( );



		Buttan_End->draw( );
		if (Buttan_End->touch( mousePtr, mousePtr->left_in( ) )) {
			break;
		}

		if ( FrameEnd( ) ) {//�@����͒�^���@�݂����Ȃ̋C�ɂ��Ȃ��ł����B
			break;
		}
	}

	delete Buttan_End;
	delete mousePtr;

}
