#include "Scene.h"
#include "SceneStart.h"


Scene::Scene( ) {
	_next = nullptr;
}


Scene::~Scene( ) {
}

void Scene::setNext(Scene* scenePtr) { 
	_next = scenePtr;
};
Scene* Scene::getNext( ) {
	return _next;
}
void Scene::setScore( ) {
	
}

void Scene::run( ) {

	_next = ( new SceneStart( ) );

}

void Scene::initThis( ){
	setNext( nullptr );
}
