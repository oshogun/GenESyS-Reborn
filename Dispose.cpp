/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dispose.cpp
 * Author: cancian
 * 
 * Created on 21 de Junho de 2018, 20:13
 */

#include "Dispose.h"
#include "Model.h"

Dispose::Dispose(Model* model):SinkModelComponent(model) {
	_name = "Dispose "+Util::_S_generateNewIdOfType("Dispose");
}

Dispose::Dispose(const Dispose& orig):SinkModelComponent(orig) {
}

Dispose::~Dispose() {
}

void Dispose::_execute(Entity* entity) {
	_model->removeEntity(entity, this->isCollectStatistics());
}
