/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "trees/treeNode.hpp"

#include <iostream>
#include <cstring>
using namespace std;

namespace trees {

TreeNode::TreeNode(): parent(nullptr), data("."), children(new TreeList()) {
}

TreeNode::TreeNode(string val): parent(nullptr), data(val), children(new TreeList()),ubication(val) {
}

void TreeNode::setParent(TreeNode* node){
	parent = node;
	setUbication();
}
void TreeNode::setData(string val){
		data = val;
}
void TreeNode::setChildren(TreeList* list){
	children = list;
}
void TreeNode::setUbication(){
	string prev_path=parent->getUbication();
	if(prev_path=="/"){
		ubication="/"+ parent->getData();
	}
	else{
		ubication=prev_path+"/"+parent->getData();
	}
}

TreeNode* TreeNode::getParent(){
	return parent;
}
string TreeNode::getData(){
	return data;
}
TreeList* TreeNode::getChildren(){
	return children;
}

string TreeNode::getUbication(){
	return ubication;
}

TreeNode::~TreeNode() {
	//action when a treeNode is deleted
	//delete the descendants only
	if (children != nullptr){
		delete children;
	}
}

} /* namespace trees */
